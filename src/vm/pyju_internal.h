#pragma once
#include "pyju_object.h"
#include "pyju_threads.h"
#include "pyju_fasttls.h"
#include "pyju_locks.h"
#include <cstdlib>
#include <uv.h>

#ifndef UV_STDIN_FD
#define UV_STDIN_FD    (0)
#endif
#ifndef UV_STDOUT_FD
#define UV_STDOUT_FD   (1)
#endif
#ifndef UV_STDERR_FD
#define UV_STDERR_FD   (2)
#endif


#ifdef __cplusplus
extern "C" {
#endif

struct PyjuTypeEnv_t {
    PyjuTVar_t *var;
    PyjuValue_t *val;
    struct PyjuTypeEnv_t *prev;
};


// Exception stack: a stack of pairs of (exception,raw_backtrace).
// The stack may be traversed and accessed with the functions below.
struct PyjuExcStack_t {
    size_t top;
    size_t reserved_size;
    // Pack all stack entries into a growable buffer to amortize allocation
    // across repeated exception handling.
    // Layout: [bt_data1... bt_size1 exc1  bt_data2... bt_size2 exc2  ..]
    // PyjuBtElement_t data[]; // Access with pyju_excstack_raw
};

typedef PyjuGcFrame_t ***(*pyju_pgcstack_key_t)(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_pgcstack_getkey(pyju_get_pgcstack_func **f, pyju_pgcstack_key_t *k);
void pyju_set_pgcstack(PyjuGcFrame_t **) PYJU_NOTSAFEPOINT;

// number of cycles since power-on
static inline uint64_t cycleclock(void) PYJU_NOTSAFEPOINT
{
#if defined(_CPU_X86_64_)
    uint64_t low, high;
    __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
    return (high << 32) | low;
#elif defined(_CPU_X86_)
    int64_t ret;
    __asm__ volatile("rdtsc" : "=A"(ret));
    return ret;
#elif defined(_CPU_AARCH64_)
    // System timer of ARMv8 runs at a different frequency than the CPU's.
    // The frequency is fixed, typically in the range 1-50MHz.  It can be
    // read at CNTFRQ special register.  We assume the OS has set up
    // the virtual timer properly.
    int64_t virtual_timer_value;
    __asm__ volatile("mrs %0, cntvct_el0" : "=r"(virtual_timer_value));
    return virtual_timer_value;
#elif defined(_CPU_PPC64_)
    // This returns a time-base, which is not always precisely a cycle-count.
    // https://reviews.llvm.org/D78084
    int64_t tb;
    asm volatile("mfspr %0, 268" : "=r" (tb));
    return tb;
#else
    #warning No cycleclock() definition for your platform
    // copy from https://github.com/google/benchmark/blob/v1.5.0/src/cycleclock.h
    return 0;
#endif
}

#include "timing.h"


// If this is detected in a backtrace of segfault, it means the functions
// that use this value must be reworked into their async form with cb arg
// provided and with PYJU_UV_LOCK used around the calls
static uv_loop_t *const unused_uv_loop_arg = (uv_loop_t *)0xBAD10;

extern PyjuMutex_t pyju_uv_mutex;
extern _Atomic(int) pyju_uv_n_waiters;
void PYJU_UV_LOCK(void);
#define PYJU_UV_UNLOCK() PYJU_UNLOCK(&pyju_uv_mutex)


// this is a version of memcpy that preserves atomic memory ordering
// which makes it safe to use for objects that can contain memory references
// without risk of creating pointers out of thin air
// TODO: replace with LLVM's llvm.memmove.element.unordered.atomic.p0i8.p0i8.i32
//       aka `__llvm_memmove_element_unordered_atomic_8` (for 64 bit)
static inline void memmove_refs(void **dstp, void *const *srcp, size_t n) PYJU_NOTSAFEPOINT
{
    size_t i;
    _Atomic(void*) *srcpa = (_Atomic(void*)*)srcp;
    _Atomic(void*) *dstpa = (_Atomic(void*)*)dstp;
    if (dstp < srcp || dstp > srcp + n) {
        for (i = 0; i < n; i++) {
            pyju_atomic_store_relaxed(dstpa + i, pyju_atomic_load_relaxed(srcpa + i));
        }
    }
    else {
        for (i = 0; i < n; i++) {
            pyju_atomic_store_relaxed(dstpa + n - i - 1, pyju_atomic_load_relaxed(srcpa + n - i - 1));
        }
    }
}

// -- gc.c -- //

#define GC_CLEAN  0 // freshly allocated
#define GC_MARKED 1 // reachable and young
#define GC_OLD    2 // if it is reachable it will be marked as old
#define GC_OLD_MARKED (GC_OLD | GC_MARKED) // reachable and old

// useful constants
extern PyjuMethTable_t *pyju_type_type_mt PYJU_GLOBALLY_ROOTED;
extern PyjuMethTable_t *pyju_nonfunction_mt PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLEXPORT _Atomic(size_t) pyju_world_counter;

STATIC_INLINE void *pyju_get_frame_addr(void)
{
#ifdef __GNUC__
    return __builtin_frame_address(0);
#else
    void *dummy = NULL;
    // The mask is to suppress the compiler warning about returning
    // address of local variable
    return (void*)((uintptr_t)&dummy & ~(uintptr_t)15);
#endif
}

PYJU_DLLEXPORT extern int pyju_lineno;
PYJU_DLLEXPORT extern const char *pyju_filename;

PyjuValue_t *pyju_gc_pool_alloc_noinline(PyjuPtls_t ptls, int pool_offset,
                                   int osize);
PyjuValue_t *pyju_gc_big_alloc_noinline(PyjuPtls_t ptls, size_t allocsz);
PYJU_DLLEXPORT int pyju_gc_classify_pools(size_t sz, int *osize);
extern uv_mutex_t gc_perm_lock;
void *pyju_gc_perm_alloc_nolock(size_t sz, int zero,
    unsigned align, unsigned offset) PYJU_NOTSAFEPOINT;
void *pyju_gc_perm_alloc(size_t sz, int zero,
    unsigned align, unsigned offset) PYJU_NOTSAFEPOINT;
void pyju_gc_force_mark_old(PyjuPtls_t ptls, PyjuValue_t *v);
void gc_sweep_sysimg(void);

// pools are 16376 bytes large (GC_POOL_SZ - GC_PAGE_OFFSET)
static const int pyju_gc_sizeclasses[] = {
#ifdef _P64
    8,
#elif MAX_ALIGN > 4
    // ARM and PowerPC have max alignment larger than pointer,
    // make sure allocation of size 8 has that alignment.
    4, 8,
#else
    4, 8, 12,
#endif

    // 16 pools at 8-byte spacing
    // the 8-byte aligned pools are only used for Strings
    16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136,
    // 8 pools at 16-byte spacing
    144, 160, 176, 192, 208, 224, 240, 256,

    // the following tables are computed for maximum packing efficiency via the formula:
    // pg = 2^14
    // sz = (div.(pg-8, rng).÷16)*16; hcat(sz, (pg-8).÷sz, pg .- (pg-8).÷sz.*sz)'

    // rng = 60:-4:32 (8 pools)
    272, 288, 304, 336, 368, 400, 448, 496,
//   60,  56,  53,  48,  44,  40,  36,  33, /pool
//   64, 256, 272, 256, 192, 384, 256,  16, bytes lost

    // rng = 30:-2:16 (8 pools)
    544, 576, 624, 672, 736, 816, 896, 1008,
//   30,  28,  26,  24,  22,  20,  18,  16, /pool
//   64, 256, 160, 256, 192,  64, 256, 256, bytes lost

    // rng = 15:-1:8 (8 pools)
    1088, 1168, 1248, 1360, 1488, 1632, 1808, 2032
//    15,   14,   13,   12,   11,   10,    9,    8, /pool
//    64,   32,  160,   64,   16,   64,  112,  128, bytes lost
};
static_assert(sizeof(pyju_gc_sizeclasses) / sizeof(pyju_gc_sizeclasses[0]) == PYJU_GC_N_POOLS, "");


STATIC_INLINE int pyju_gc_alignment(size_t sz)
{
    if (sz == 0)
        return sizeof(void*);
#ifdef _P64
    (void)sz;
    return 16;
#elif MAX_ALIGN == 8
    return sz <= 4 ? 8 : 16;
#else
    // szclass 8
    if (sz <= 4)
        return 8;
    // szclass 12
    if (sz <= 8)
        return 4;
    // szclass 16+
    return 16;
#endif
}

PYJU_DLLEXPORT int pyju_alignment(size_t sz);

// the following table is computed as:
// [searchsortedfirst(pyju_gc_sizeclasses, i) - 1 for i = 0:16:pyju_gc_sizeclasses[end]]
static const uint8_t szclass_table[] = {0, 1, 3, 5, 7, 9, 11, 13, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 28, 29, 29, 30, 30, 31, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 38, 39, 39, 39, 39, 39, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 41, 41, 42, 42, 42, 42, 42, 43, 43, 43, 43, 43, 44, 44, 44, 44, 44, 44, 44, 45, 45, 45, 45, 45, 45, 45, 45, 46, 46, 46, 46, 46, 46, 46, 46, 46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48};
static_assert(sizeof(szclass_table) == 128, "");


STATIC_INLINE uint8_t PYJU_CONST_FUNC pyju_gc_szclass(unsigned sz)
{
    assert(sz <= 2032);
#ifdef _P64
    if (sz <= 8)
        return 0;
    const int N = 0;
#elif MAX_ALIGN == 8
    if (sz <= 8)
        return (sz >= 4 ? 1 : 0);
    const int N = 1;
#else
    if (sz <= 12)
        return (sz >= 8 ? 2 : (sz >= 4 ? 1 : 0));
    const int N = 2;
#endif
    uint8_t klass = szclass_table[(sz + 15) / 16];
    return klass + N;
}


STATIC_INLINE uint8_t PYJU_CONST_FUNC pyju_gc_szclass_align8(unsigned sz)
{
    if (sz >= 16 && sz <= 152) {
#ifdef _P64
        const int N = 0;
#elif MAX_ALIGN == 8
        const int N = 1;
#else
        const int N = 2;
#endif
        return (sz + 7)/8 - 1 + N;
    }
    return pyju_gc_szclass(sz);
}

#define PYJU_SMALL_BYTE_ALIGNMENT 16
#define PYJU_CACHE_BYTE_ALIGNMENT 64
// PYJU_HEAP_ALIGNMENT is the maximum alignment that the GC can provide
#define PYJU_HEAP_ALIGNMENT PYJU_SMALL_BYTE_ALIGNMENT
#define GC_MAX_SZCLASS (2032-sizeof(void*))
static_assert(ARRAY_CACHE_ALIGN_THRESHOLD > GC_MAX_SZCLASS, "");


STATIC_INLINE PyjuValue_t *pyju_gc_alloc_(PyjuPtls_t ptls, size_t sz, void *ty)
{
    PyjuValue_t *v;
    // const size_t allocsz = sz + sizeof(PyjuTaggedValue_t);
    const size_t allocsz = sz;
    if (sz <= GC_MAX_SZCLASS) {
        int pool_id = pyju_gc_szclass(allocsz);
        PyjuGcPool_t *p = &ptls->heap.norm_pools[pool_id];
        int osize = pyju_gc_sizeclasses[pool_id];
        // We call `pyju_gc_pool_alloc_noinline` instead of `pyju_gc_pool_alloc` to avoid double-counting in
        // the Allocations Profiler. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
        v = pyju_gc_pool_alloc_noinline(ptls, (char*)p - (char*)ptls, osize);
    }
    else {
        if (allocsz < sz) // overflow in adding offs, size was "negative"
        {
            pyju_printf(PYJU_STDOUT, "not impl pyju_throw(pyju_memory_exception)");
            abort();
            // pyju_throw(pyju_memory_exception);
        }
        v = pyju_gc_big_alloc_noinline(ptls, allocsz);
    }
    pyju_set_typeof(v, ty);
    // maybe_record_alloc_to_profile(v, sz, (PyjuDataType_t*)ty);
    return v;
}


/* Programming style note: When using pyju_gc_alloc, do not PYJU_GC_PUSH it into a
 * gc frame, until it has been fully initialized. An uninitialized value in a
 * gc frame can crash upon encountering the first safepoint. By delaying use of
 * the PYJU_GC_PUSH macro until the value has been initialized, any accidental
 * safepoints will be caught by the GC analyzer.
 */
PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc(PyjuPtls_t ptls, size_t sz, void *ty);
// On GCC, only inline when sz is constant
#ifdef __GNUC__
#  define pyju_gc_alloc(ptls, sz, ty)  \
    (__builtin_constant_p(sz) ?      \
     pyju_gc_alloc_(ptls, sz, ty) :    \
     (pyju_gc_alloc)(ptls, sz, ty))
#else
#  define pyju_gc_alloc(ptls, sz, ty) pyju_gc_alloc_(ptls, sz, ty)
#endif

// pyju_buff_tag must be a multiple of GC_PAGE_SZ so that it can't be
// confused for an actual type reference.
#define pyju_buff_tag ((uintptr_t)0x4eadc000)
typedef void pyju_gc_tracked_buffer_t; // For the benefit of the static analyzer
STATIC_INLINE pyju_gc_tracked_buffer_t *pyju_gc_alloc_buf(PyjuPtls_t ptls, size_t sz)
{
    return pyju_gc_alloc(ptls, sz, (void*)pyju_buff_tag);
}

STATIC_INLINE PyjuValue_t *pyju_gc_permobj(size_t sz, void *ty) PYJU_NOTSAFEPOINT
{
    // const size_t allocsz = sz + sizeof(PyjuTaggedValue_t);
    const size_t allocsz = sz;
    unsigned align = (sz == 0 ? sizeof(void*) : (allocsz <= sizeof(void*) * 2 ?
                                                 sizeof(void*) * 2 : 16));
    PyjuTaggedValue_t *o = (PyjuTaggedValue_t*)pyju_gc_perm_alloc(allocsz, 0, align,
                                                              sizeof(void*) % align);
    uintptr_t tag = (uintptr_t)ty;
    o->header = tag | GC_OLD_MARKED;
    return pyju_valueof(o);
}

PyjuValue_t *pyju_permbox8(PyjuDataType_t *t, int8_t x);
PyjuValue_t *pyju_permbox16(PyjuDataType_t *t, int16_t x);
PyjuValue_t *pyju_permbox32(PyjuDataType_t *t, int32_t x);
PyjuValue_t *pyju_permbox64(PyjuDataType_t *t, int64_t x);
PyjuSvec_t *pyju_perm_symsvec(size_t n, ...);


// this sizeof(__VA_ARGS__) trick can't be computed until C11, but that only matters to Clang in some situations
#if !defined(__clang_analyzer__) && !(defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_))
#ifdef _COMPILER_GCC_
#define pyjuperm_symsvec(n, ...) \
    (pyjuperm_symsvec)(__extension__({                                         \
            static_assert(                                                    \
                n == sizeof((char *[]){ __VA_ARGS__ })/sizeof(char *),        \
                "Number of passed arguments does not match expected number"); \
            n;                                                                \
        }), __VA_ARGS__)
#ifdef pyjusvec
#undef pyjusvec
#define pyjusvec(n, ...) \
    (ipyjusvec)(__extension__({                                                \
            static_assert(                                                    \
                n == sizeof((void *[]){ __VA_ARGS__ })/sizeof(void *),        \
                "Number of passed arguments does not match expected number"); \
            n;                                                                \
        }), __VA_ARGS__)
#else
#define pyjusvec(n, ...) \
    (pyjusvec)(__extension__({                                                 \
            static_assert(                                                    \
                n == sizeof((void *[]){ __VA_ARGS__ })/sizeof(void *),        \
                "Number of passed arguments does not match expected number"); \
            n;                                                                \
        }), __VA_ARGS__)
#endif
#endif
#endif

// init.cc
void pyju_init_types(void) PYJU_GC_DISABLED;
void pyju_init_thread_heap(PyjuPtls_t ptls);
extern PYJU_DLLEXPORT size_t pyju_page_size;
void pyju_init_uv(void);
void pyju_gc_init(void);
PyjuTask_t *pyju_init_root_task(PyjuPtls_t ptls, void *stack_lo, void *stack_hi);

//--------------------------------------------------
// congruential random number generator
// for a small amount of thread-local randomness
STATIC_INLINE void unbias_cong(uint64_t max, uint64_t *unbias) PYJU_NOTSAFEPOINT
{
    *unbias = UINT64_MAX - ((UINT64_MAX % max) + 1);
}
STATIC_INLINE uint64_t cong(uint64_t max, uint64_t unbias, uint64_t *seed) PYJU_NOTSAFEPOINT
{
    while ((*seed = 69069 * (*seed) + 362437) > unbias)
        ;
    return *seed % max;
}
PYJU_DLLEXPORT uint64_t pyju_rand(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_srand(uint64_t) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_init_rand(void);



// Whether the GC is running
extern char *pyju_safepoint_pages;
STATIC_INLINE int pyju_addr_is_safepoint(uintptr_t addr)
{
    uintptr_t safepoint_addr = (uintptr_t)pyju_safepoint_pages;
    return addr >= safepoint_addr && addr < safepoint_addr + pyju_page_size * 3;
}
extern _Atomic(uint32_t) pyju_gc_running;
// All the functions are safe to be called from within a signal handler
// provided that the thread will not be interrupted by another asynchronous
// signal.
// Initialize the safepoint
void pyju_safepoint_init(void);
// Start the GC, return `1` if the thread should be running the GC.
// Otherwise, the thread will wait in this function until the GC finishes on
// another thread and return `0`.
// The caller should have saved the `gc_state` and set it to `WAITING`
// before calling this function. If the calling thread is to run the GC,
// it should also wait for the mutator threads to hit a safepoint **AFTER**
// this function returns
int pyju_safepoint_start_gc(void);
// Can only be called by the thread that have got a `1` return value from
// `pyju_safepoint_start_gc()`. This disables the safepoint (for GC,
// the `mprotect` may not be removed if there's pending SIGINT) and wake
// up waiting threads if there's any.
// The caller should restore `gc_state` **AFTER** calling this function.
void pyju_safepoint_end_gc(void);
// Wait for the GC to finish
// This function does **NOT** modify the `gc_state` to inform the GC thread
// The caller should set it **BEFORE** calling this function.
void pyju_safepoint_wait_gc(void);

// Set pending sigint and enable the mechanisms to deliver the sigint.
void pyju_safepoint_enable_sigint(void);
// If the safepoint is enabled to deliver sigint, disable it
// so that the thread won't repeatedly trigger it in a sigatomic region
// while not being able to actually throw the exception.
void pyju_safepoint_defer_sigint(void);
// Clear the sigint pending flag and disable the mechanism to deliver sigint.
// Return `1` if the sigint should be delivered and `0` if there's no sigint
// to be delivered.
int pyju_safepoint_consume_sigint(void);
void pyju_wake_libuv(void);



//--------------------------------------------------
// Backtraces

// Backtrace buffers:
//
// A backtrace buffer conceptually contains a stack of instruction pointers
// ordered from the inner-most frame to the outermost. We store them in a
// special raw format for two reasons:
//
//   * Efficiency: Every `throw()` must populate the trace so it must be as
//     efficient as possible.
//   * Signal safety: For signal-based exceptions such as StackOverflowError
//     the trace buffer needs to be filled from a signal handler where most
//     operations are not allowed (including malloc) so we choose a flat
//     preallocated buffer.
//
// The raw buffer layout contains "frame entries" composed of one or several
// values of type `PyjuBtElement_t`. From the point of view of the GC, an entry
// is either:
//
// 1. A single instruction pointer to native code, not GC-managed.
// 2. An "extended entry": a mixture of raw data and pointers to julia objects
//    which must be treated as GC roots.
//
// A single extended entry is seralized using multiple elements from the raw
// buffer; if `e` is the pointer to the first slot we have:
//
//   e[0]  PYJU_BT_NON_PTR_ENTRY  - Special marker to distinguish extended entries
//   e[1]  descriptor           - A bit packed uintptr_t containing a tag and
//                                the number of GC- managed and non-managed values
//   e[2+j]                     - GC managed data
//   e[2+ngc+i]                 - Non-GC-managed data
//
// The format of `descriptor` is, from LSB to MSB:
//   0:2     ngc     Number of GC-managed pointers for this frame entry
//   3:5     nptr    Number of non-GC-managed buffer elements
//   6:9     tag     Entry type
//   10:...  header  Entry-specific header data
struct PyjuBtElement_t {
    union {
        uintptr_t   uintptr; // Metadata or native instruction ptr
        PyjuValue_t* jlvalue; // Pointer to GC-managed value
    };
} ;

#define PYJU_BT_NON_PTR_ENTRY (((uintptr_t)0)-1)
// // Maximum size for an extended backtrace entry (likely significantly larger
// // than the actual size of 3-4 for an interpreter frame)
#define PYJU_BT_MAX_ENTRY_SIZE 16

STATIC_INLINE int pyju_bt_is_native(PyjuBtElement_t *bt_entry) PYJU_NOTSAFEPOINT
{
    return bt_entry[0].uintptr != PYJU_BT_NON_PTR_ENTRY;
}

// // Extended backtrace entry header packing; the bit packing is done manually
// for precise layout control for interop with julia side.
STATIC_INLINE uintptr_t pyju_bt_entry_descriptor(int ngc, int nptr,
                                               int tag, uintptr_t header) PYJU_NOTSAFEPOINT
{
    assert(((ngc & 0x7) == ngc) && ((nptr & 0x7) == nptr) && ((tag & 0xf) == tag));
    return (ngc & 0x7) | (nptr & 0x7) << 3 | (tag & 0xf) << 6 | header << 10;
}

// Unpacking of extended backtrace entry data
STATIC_INLINE size_t pyju_bt_num_jlvals(PyjuBtElement_t *bt_entry) PYJU_NOTSAFEPOINT
{
    assert(!pyju_bt_is_native(bt_entry));
    return bt_entry[1].uintptr & 0x7;
}
STATIC_INLINE size_t pyju_bt_num_uintvals(PyjuBtElement_t *bt_entry) PYJU_NOTSAFEPOINT
{
    assert(!pyju_bt_is_native(bt_entry));
    return (bt_entry[1].uintptr >> 3) & 0x7;
}
STATIC_INLINE int pyju_bt_entry_tag(PyjuBtElement_t *bt_entry) PYJU_NOTSAFEPOINT
{
    assert(!pyju_bt_is_native(bt_entry));
    return (bt_entry[1].uintptr >> 6) & 0xf;
}
STATIC_INLINE uintptr_t pyju_bt_entry_header(PyjuBtElement_t *bt_entry) PYJU_NOTSAFEPOINT
{
    assert(!pyju_bt_is_native(bt_entry));
    return bt_entry[1].uintptr >> 10;
}

// Return `i`th GC-managed pointer for extended backtrace entry
// The returned value is rooted for the lifetime of the parent exception stack.
STATIC_INLINE PyjuValue_t *pyju_bt_entry_jlvalue(PyjuBtElement_t *bt_entry, size_t i) PYJU_NOTSAFEPOINT
{
    return bt_entry[2 + i].jlvalue;
}

#define PYJU_BT_INTERP_FRAME_TAG    1  // An interpreter frame

// Number of bt elements in frame.
STATIC_INLINE size_t pyju_bt_entry_size(PyjuBtElement_t *bt_entry) PYJU_NOTSAFEPOINT
{
    return pyju_bt_is_native(bt_entry) ?
        1 : 2 + pyju_bt_num_jlvals(bt_entry) + pyju_bt_num_uintvals(bt_entry);
}

void pyju_init_tasks(void) PYJU_GC_DISABLED;

void pyju_init_threading(void);
void pyju_start_threads(void);

extern htable_t pyju_current_modules PYJU_GLOBALLY_ROOTED;


// uv
extern uv_loop_t *pyju_io_loop;

void restore_signals(void);

// functions
PyjuDataType_t *pyju_new_uninitialized_datatype(void);

PyjuSym_t *_pyju_symbol(const char *str, size_t len) PYJU_NOTSAFEPOINT;

extern PYJU_DLLEXPORT PyjuSym_t *pyju_call_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_invoke_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_invoke_modify_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_empty_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_top_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_module_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_slot_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_export_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_import_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_toplevel_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_quote_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_line_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_incomplete_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_goto_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_goto_ifnot_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_return_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_lineinfo_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_lambda_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_assign_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_globalref_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_do_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_method_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_core_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_enter_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_leave_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_pop_exception_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_exc_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_error_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_new_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_using_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_splatnew_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_block_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_new_opaque_closure_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_opaque_closure_method_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_const_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_thunk_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_foreigncall_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_as_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_global_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_list_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_dot_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_newvar_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_boundscheck_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_inbounds_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_copyast_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_cfunction_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_pure_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_loopinfo_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_meta_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_inert_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_polly_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_unused_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_static_parameter_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_inline_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_noinline_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_generated_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_generated_only_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_isdefined_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_propagate_inbounds_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_specialize_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_aggressive_constprop_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_no_constprop_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_purity_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_nospecialize_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_macrocall_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_colon_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_hygienicscope_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_throw_undef_if_not_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_getfield_undefref_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_gc_preserve_begin_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_gc_preserve_end_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_coverageeffect_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_escape_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_aliasscope_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_popaliasscope_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_optlevel_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_thismodule_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_atom_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_statement_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_all_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_compile_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_force_compile_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_infer_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_max_methods_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_atomic_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_not_atomic_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_unordered_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_monotonic_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_acquire_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_release_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_acquire_release_sym;
extern PYJU_DLLEXPORT PyjuSym_t *pyju_sequentially_consistent_sym;

void set_nth_field(PyjuDataType_t *st, PyjuValue_t *v, size_t i, PyjuValue_t *rhs, int isatomic) PYJU_NOTSAFEPOINT;
PyjuValue_t *swap_nth_field(PyjuDataType_t *st, PyjuValue_t *v, size_t i, PyjuValue_t *rhs, int isatomic);
PyjuValue_t *modify_nth_field(PyjuDataType_t *st, PyjuValue_t *v, size_t i, PyjuValue_t *op, PyjuValue_t *rhs, int isatomic);
PyjuValue_t *replace_nth_field(PyjuDataType_t *st, PyjuValue_t *v, size_t i, PyjuValue_t *expected, PyjuValue_t *rhs, int isatomic);
int pyju_find_union_component(PyjuValue_t *haystack, PyjuValue_t *needle, unsigned *nth) PYJU_NOTSAFEPOINT;
void pyju_precompute_memoized_dt(PyjuDataType_t *dt, int cacheable);
STATIC_INLINE int pyju_is_vararg(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return pyju_typeof(v) == (PyjuValue_t*)pyju_vararg_type;
}
void pyju_compute_field_offsets(PyjuDataType_t *st);
PYJU_DLLEXPORT PyjuValue_t *pyju_unwrap_unionall(PyjuValue_t *v PYJU_PROPAGATES_ROOT) PYJU_NOTSAFEPOINT;
int pyju_has_fixed_layout(PyjuDataType_t *t);
PYJU_DLLEXPORT unsigned pyju_special_vector_alignment(size_t nfields, PyjuValue_t *field_type);

int pyju_count_union_components(PyjuValue_t *v);
PYJU_DLLEXPORT PyjuValue_t *pyju_nth_union_component(PyjuValue_t *v PYJU_PROPAGATES_ROOT, int i) PYJU_NOTSAFEPOINT;
int pyju_find_union_component(PyjuValue_t *haystack, PyjuValue_t *needle, unsigned *nth) PYJU_NOTSAFEPOINT;
PyjuDataType_t *pyju_new_abstracttype(PyjuValue_t *name, PyjuModule_t *module,
                                   PyjuDataType_t *super, PyjuSvec_t *parameters);
PYJU_DLLEXPORT PyjuMethTable_t *pyju_new_method_table(PyjuSym_t *name, PyjuModule_t *module);

#ifdef __cplusplus
} // extern "C"
#endif