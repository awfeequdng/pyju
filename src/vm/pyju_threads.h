// This file is a part of Julia. License is MIT: https://julialang.org/license

// Meant to be included in <julia.h>
#ifndef PYJU_THREADS_H
#define PYJU_THREADS_H

#include <bits/types/sig_atomic_t.h>
#include <cstddef>
#include <cstdint>
#include <pthread.h>
#include <setjmp.h>

#include "pyju_atomics.h"
#include "support/dtypes.h"
#include "support/arraylist.h"

// threading ------------------------------------------------------------------

#  define pyju_jmp_buf sigjmp_buf
#  if defined(_CPU_ARM_) || defined(_CPU_PPC_) || defined(_CPU_WASM_)
#    define MAX_ALIGN 8
#  elif defined(_CPU_AARCH64_)
// int128 is 16 bytes aligned on aarch64
#    define MAX_ALIGN 16
#  elif defined(_P64)
// Generically we assume MAX_ALIGN is sizeof(void*)
#    define MAX_ALIGN 8
#  else
#    define MAX_ALIGN 4
#  endif

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT int16_t pyju_threadid(void);
PYJU_DLLEXPORT int8_t pyju_threadpoolid(int16_t tid) PYJU_NOTSAFEPOINT;

// PYJU_ENABLE_THREADING may be controlled by altering PYJU_THREADS in Make.user

// When running into scheduler issues, this may help provide information on the
// sequence of events that led to the issue. Normally, it is empty.
//#define PYJU_DEBUG_SLEEPWAKE(x) x
#define PYJU_DEBUG_SLEEPWAKE(x)

struct PyjuStackContext_t {
    pyju_jmp_buf uc_mcontext;
};

#if !defined(PYJU_HAVE_UCONTEXT) && \
    !defined(PYJU_HAVE_ASM) && \
    !defined(PYJU_HAVE_UNW_CONTEXT) && \
    !defined(PYJU_HAVE_SIGALTSTACK) && \
    !defined(PYJU_HAVE_ASYNCIFY)
#if (defined(_CPU_X86_64_) || defined(_CPU_X86_) || defined(_CPU_AARCH64_) ||  \
     defined(_CPU_ARM_) || defined(_CPU_PPC64_))
#define PYJU_HAVE_ASM
#endif

#endif

#if (!defined(PYJU_HAVE_UNW_CONTEXT) && defined(PYJU_HAVE_ASM)) || defined(PYJU_HAVE_SIGALTSTACK)
typedef PyjuStackContext_t _PyjuUContext_t;
#endif
#if defined(PYJU_HAVE_ASYNCIFY)
#if defined(_COMPILER_TSAN_ENABLED_)
#error TSAN not currently supported with asyncify
#endif
typedef struct {
    // This is the extent of the asyncify stack, but because the top of the
    // asyncify stack (stacktop) is also the bottom of the C stack, we can
    // reuse stacktop for both. N.B.: This matches the layout of the
    // __asyncify_data struct.
    void *stackbottom;
    void *stacktop;
} _PyjuUContext_t;
#endif
#if defined(PYJU_HAVE_UNW_CONTEXT)
#define UNW_LOCAL_ONLY
#include <libunwind.h>
typedef unw_context_t _PyjuUContext_t;
#endif
#if defined(PYJU_HAVE_UCONTEXT)
#include <ucontext.h>
typedef ucontext_t _PyjuUContext_t;
#endif

typedef struct {
    union {
        _PyjuUContext_t ctx;
        PyjuStackContext_t copy_ctx;
    };
} PyjuUContext_t;

// handle to reference an OS thread
typedef pthread_t PyjuThread_t;

struct PyjuTast_t;

// Recursive spin lock
struct PyjuMutex_t {
    _Atomic(PyjuTast_t *) owner;
    uint32_t count;
};

struct PyjuTaggedValue_t;
struct PyjuValue_t;

struct PyjuGcPool_t {
    PyjuTaggedValue_t *freelist;    // root of list of free objects
    PyjuTaggedValue_t *newpages;    // root of list of chunks of free objects
    uint16_t osize;                 // size of objects in this pool
};

struct PyjuThreadGcNum_t {
    _Atomic(int64_t) allocd;
    _Atomic(int64_t) freed;
    _Atomic(uint64_t) malloc;
    _Atomic(uint64_t) realloc;
    _Atomic(uint64_t) poolalloc;
    _Atomic(uint64_t) bigalloc;
    _Atomic(uint64_t) freecall;
};

struct _mallocarray_t;
struct _bigval_t;

struct PyjuThreadHeap_t {
    // variable for tracking weak references
    arraylist_t weak_refs;
    // live tasks started on this thread
    // that are holding onto a stack from the pool
    arraylist_t live_tasks;

    // variables for tracking malloc'd arrays
    struct _mallocarray_t *mallocarrays;
    struct _mallocarray_t *mafreelist;

    // variables for tracking big objects
    struct _bigval_t *big_objects;

    // variables for tracking "remembered set"
    arraylist_t rem_bindings;
    arraylist_t _remset[2]; // contains pyju_value_t*
    // lower bound of the number of pointers inside remembered values
    int remset_nptr;
    arraylist_t *remset;
    arraylist_t *last_remset;

    // variables for allocating objects from pools
#ifdef _P64
#  define JL_GC_N_POOLS 49
#elif MAX_ALIGN == 8
#  define JL_GC_N_POOLS 50
#else
#  define JL_GC_N_POOLS 51
#endif
    PyjuGcPool_t norm_pools[JL_GC_N_POOLS];

#define JL_N_STACK_POOLS 16
    arraylist_t free_stacks[JL_N_STACK_POOLS];
};

// Cache of thread local change to global metadata during GC
// This is sync'd after marking.
union PyjuGcMarkData_t;

struct PyjuGcMarkSp_t {
    void **pc;  // Current pc
    PyjuGcMarkData_t *data; // Current stack address for the data (up growing)
    void **pc_start;        // Cached value of `gc_cache->pc_stack`
    void **pc_end;          // Cached value of `gc_cache->pc_stack_end`
};

struct PyjuTask_t;

struct PyjuGcMarkCache_t {
    // thread local increment of `perm_scanned_bytes`
    size_t perm_scanned_bytes;
    // thread local increment of `scanned_bytes`
    size_t scanned_bytes;
    // Number of queued big objects (<= 1024)
    size_t nbig_obj;
    // Array of queued big objects to be moved between the young list
    // and the old list.
    // A set low bit means that the object should be moved from the old list
    // to the young list (`mark_reset_age`).
    // Objects can only be put into this list when the mark bit is flipped to
    // `1` (atomically). Combining with the sync after marking,
    // this makes sure that a single objects can only appear once in
    // the lists (the mark bit cannot be flipped to `0` without sweeping)
    void *big_obj[1024];
    void **pc_stack;
    void **pc_stack_end;
    PyjuGcMarkData_t *data_stack;
};

struct PyjuBtElement_t;
struct PyjuTimingBlock_t;

struct PyjuTlsStates_t {
    int16_t tid;
    int8_t threadpoolid;
    uint64_t rngseed;
    volatile size_t *safepoint;
    _Atomic(int8_t) sleep_check_state; // read/write from foreign threads
    // Whether it is safe to execute GC at the same time
#define PYJU_GC_STATE_WAITING 1
    // gc_state = 1 means the thread is doing GC or is waiting for the GC to finish.
#define PYJU_GC_STATE_SAFE 2
    // gc_state = 2 means the thread is running unmanaged code that can be
    //              execute at the same time with the GC
    _Atomic(int8_t) gc_state;   // read from foreign threads
    // execution of certain certain impure
    // statements is prohibited from certain
    // callbacks (such as generated functions)
    // as it may make compilation undecidable
    int8_t in_pure_callback;
    int8_t in_finalizer;
    int8_t disable_gc;
    // Counter to disable finalizer **on the current thread**
    int finalizers_inhibited;
    PyjuThreadHeap_t heap; // this is very large, and the offset is baked into codegen
    PyjuThreadGcNum_t gc_num;
    volatile sig_atomic_t defer_signal;
    _Atomic(PyjuTask_t*) current_task;
    PyjuTask_t *next_task;
    PyjuTask_t *previous_task;
    PyjuTask_t *root_task;
    PyjuTimingBlock_t *timing_stack;
    void *stackbase;
    size_t stacksize;
    union {
        PyjuUContext_t base_ctx;    // base context of stack
        // This hack is needed to support always_copy_stacks:
        PyjuStackContext_t copy_stack_ctx;
    };
    // Temp storage for exception thrown in signal handler. Not rooted.
    PyjuValue_t *sig_exception;
    // Temporary backtrace buffer. Scanned for gc roots when bt_size > 0.
    PyjuBtElement_t *bt_data; // JL_MAX_BT_SIZE + 1 elements long
    size_t bt_size;    // Size for backtrace in transit in bt_data
    // Temporary backtrace buffer used only for allocations profiler.
    PyjuBtElement_t *profiling_bt_buffer;
    // Atomically set by the sender, reset by the handler.
    volatile _Atomic(sig_atomic_t) signal_request; // TODO: no actual reason for this to be _Atomic
    // Allow the sigint to be raised asynchronously
    // this is limited to the few places we do synchronous IO
    // we can make this more general (similar to defer_signal) if necessary
    volatile sig_atomic_t io_wait;

    void *signal_stack;

    PyjuThread_t system_id;
    arraylist_t finalizers;
    PyjuGcMarkCache_t gc_cache;
    arraylist_t sweep_objs;
    PyjuGcMarkSp_t gc_mark_sp;
    // Saved exception for previous *external* API call or NULL if cleared.
    // Access via pyju_exception_occurred().
    PyjuValue_t *previous_exception;

    // currently-held locks, to be released when an exception is thrown
    small_arraylist_t locks;

    PYJU_DEBUG_SLEEPWAKE(
        uint64_t uv_run_enter;
        uint64_t uv_run_leave;
        uint64_t sleep_enter;
        uint64_t sleep_leave;
    )
    // some hidden state (usually just because we don't have the type's size declaration)
#ifdef LIBRARY_EXPORTS
    uv_mutex_t sleep_lock;
    uv_cond_t wake_signal;
#endif
};

// Update codegen version in `ccall.cpp` after changing either `pause` or `wake`
#ifdef __MIC__
#  define pyju_cpu_pause() _mm_delay_64(100)
#  define pyju_cpu_wake() ((void)0)
#  define JL_CPU_WAKE_NOOP 1
#elif defined(_CPU_X86_64_) || defined(_CPU_X86_)  /* !__MIC__ */
#  define pyju_cpu_pause() _mm_pause()
#  define pyju_cpu_wake() ((void)0)
#  define JL_CPU_WAKE_NOOP 1
#elif defined(_CPU_AARCH64_) || (defined(_CPU_ARM_) && __ARM_ARCH >= 7)
#  define pyju_cpu_pause() __asm__ volatile ("wfe" ::: "memory")
#  define pyju_cpu_wake() __asm__ volatile ("sev" ::: "memory")
#  define JL_CPU_WAKE_NOOP 0
#else
#  define pyju_cpu_pause() ((void)0)
#  define pyju_cpu_wake() ((void)0)
#  define JL_CPU_WAKE_NOOP 1
#endif

PYJU_DLLEXPORT void (pyju_cpu_pause)(void);
PYJU_DLLEXPORT void (pyju_cpu_wake)(void);

#ifdef __cplusplus
}
#endif

#endif
