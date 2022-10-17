// This file is a part of Julia. License is MIT: https://julialang.org/license

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

// Ref https://www.uclibc.org/docs/tls.pdf
// For variant 1 PYJU_ELF_TLS_INIT_SIZE is the size of the thread control block (TCB)
// For variant 2 PYJU_ELF_TLS_INIT_SIZE is 0
#ifdef _OS_LINUX_
#  if defined(_CPU_X86_64_) || defined(_CPU_X86_)
#    define PYJU_ELF_TLS_VARIANT 2
#    define PYJU_ELF_TLS_INIT_SIZE 0
#  elif defined(_CPU_AARCH64_)
#    define PYJU_ELF_TLS_VARIANT 1
#    define PYJU_ELF_TLS_INIT_SIZE 16
#  elif defined(__ARM_ARCH) && __ARM_ARCH >= 7
#    define PYJU_ELF_TLS_VARIANT 1
#    define PYJU_ELF_TLS_INIT_SIZE 8
#  endif
#endif

#ifdef PYJU_ELF_TLS_VARIANT
#  include <link.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "threading.h"

PYJU_DLLEXPORT void *pyju_get_ptls_states(void)
{
    // mostly deprecated: use current_task instead
    return pyju_current_task->ptls;
}

static pthread_key_t pyju_safe_restore_key;

__attribute__((constructor)) void _pyju_init_safe_restore(void)
{
    pthread_key_create(&pyju_safe_restore_key, NULL);
}

PYJU_DLLEXPORT pyju_jmp_buf *pyju_get_safe_restore(void)
{
    return (pyju_jmp_buf*)pthread_getspecific(pyju_safe_restore_key);
}

PYJU_DLLEXPORT void pyju_set_safe_restore(pyju_jmp_buf *sr)
{
    pthread_setspecific(pyju_safe_restore_key, (void*)sr);
}

// The tls_states buffer:
//
// On platforms that do not use ELF (i.e. where `__thread` is emulated with
// lower level API) (Mac, Windows), we use the platform runtime API to create
// TLS variable directly.
// This is functionally equivalent to using `__thread` but can be
// more efficient since we can have better control over the creation and
// initialization of the TLS buffer.
//
// On platforms that use ELF (Linux, FreeBSD), we use a `__thread` variable
// as the fallback in the shared object. For better efficiency, we also
// create a `__thread` variable in the main executable using a static TLS
// model.

// We use the faster static version in the main executable to replace
// the slower version in the shared object. The code in different libraries
// or executables, however, have to agree on which version to use.
// The general solution is to add one more indirection in the C entry point.
//
// When `ifunc` is available, we can use it to trick the linker to use the
// real address (`pyju_get_pgcstack_static`) directly as the symbol address.
//
// However, since the detection of the static version in `ifunc`
// is not guaranteed to be reliable, we still need to fallback to the wrapper
// version as the symbol address if we didn't find the static version in `ifunc`.

// fallback provided for embedding
static pyju_pgcstack_key_t pyju_pgcstack_key;
static __thread PyjuGcFrame_t **pgcstack_;
static PyjuGcFrame_t **pyju_get_pgcstack_fallback(void) PYJU_NOTSAFEPOINT
{
    return pgcstack_;
}
static PyjuGcFrame_t ***pyju_pgcstack_addr_fallback(void) PYJU_NOTSAFEPOINT
{
    return &pgcstack_;
}
void pyju_set_pgcstack(PyjuGcFrame_t **pgcstack) PYJU_NOTSAFEPOINT
{
    *pyju_pgcstack_key() = pgcstack;
}
#  if PYJU_USE_IFUNC
PYJU_DLLEXPORT __attribute__((weak))
void pyju_register_pgcstack_getter(void);
#  endif
static PyjuGcFrame_t **pyju_get_pgcstack_init(void);
static pyju_get_pgcstack_func *pyju_get_pgcstack_cb = pyju_get_pgcstack_init;
static PyjuGcFrame_t **pyju_get_pgcstack_init(void)
{
    // This 2-step initialization is used to detect calling
    // `pyju_pgcstack_getkey` after the address of the TLS variables
    // are used. Since the address of TLS variables should be constant,
    // changing the getter address can result in weird crashes.

    // This is clearly not thread safe but should be fine since we
    // make sure the tls states callback is finalized before adding
    // multiple threads
#  if PYJU_USE_IFUNC
    if (pyju_register_pgcstack_getter)
        pyju_register_pgcstack_getter();
    else
#  endif
    {
        pyju_get_pgcstack_cb = pyju_get_pgcstack_fallback;
        pyju_pgcstack_key = &pyju_pgcstack_addr_fallback;
    }
    return pyju_get_pgcstack_cb();
}

PYJU_DLLEXPORT void pyju_pgcstack_setkey(pyju_get_pgcstack_func *f, pyju_pgcstack_key_t k)
{
    if (f == pyju_get_pgcstack_cb || !f)
        return;
    // only allow setting this once
    if (pyju_get_pgcstack_cb != pyju_get_pgcstack_init) {
        printf("not implemented pyju_safe_printf yet:");
        // pyju_safe_printf("ERROR: Attempt to change TLS address.\n");
        exit(1);
    }
    pyju_get_pgcstack_cb = f;
    pyju_pgcstack_key = k;
}

PYJU_DLLEXPORT PyjuGcFrame_t **pyju_get_pgcstack(void) PYJU_GLOBALLY_ROOTED
{
    return pyju_get_pgcstack_cb();
}

void pyju_pgcstack_getkey(pyju_get_pgcstack_func **f, pyju_pgcstack_key_t *k)
{
    if (pyju_get_pgcstack_cb == pyju_get_pgcstack_init)
        pyju_get_pgcstack_init();
    // for codegen
    *f = pyju_get_pgcstack_cb;
    *k = pyju_pgcstack_key;
}

PyjuPtls_t *pyju_all_tls_states PYJU_GLOBALLY_ROOTED;
PYJU_DLLEXPORT _Atomic(uint8_t) pyju_measure_compile_time_enabled = 0;
PYJU_DLLEXPORT _Atomic(uint64_t) pyju_cumulative_compile_time = 0;
PYJU_DLLEXPORT _Atomic(uint64_t) pyju_cumulative_recompile_time = 0;

// return calling thread's ID
// Also update the suspended_threads list in signals-mach when changing the
// type of the thread id.
PYJU_DLLEXPORT int16_t pyju_threadid(void)
{
    return pyju_atomic_load_relaxed(&pyju_current_task->tid);
}

PyjuPtls_t pyju_init_threadtls(int16_t tid)
{
    PyjuPtls_t ptls = (PyjuPtls_t)calloc(1, sizeof(PyjuTlsStates_t));
    ptls->system_id = (PyjuThread_t)(uintptr_t)uv_thread_self();
    ptls->rngseed = pyju_rand();

    ptls->tid = tid;
    pyju_atomic_store_relaxed(&ptls->gc_state, 0); // GC unsafe
    // Conditionally initialize the safepoint address. See comment in
    // `safepoint.cc`
    if (tid == 0) {
        ptls->safepoint = (size_t*)(pyju_safepoint_pages + pyju_page_size);
    }
    else {
        ptls->safepoint = (size_t*)(pyju_safepoint_pages + pyju_page_size * 2 +
                                    sizeof(size_t));
    }
    PyjuBtElement_t *bt_data = (PyjuBtElement_t*)
        malloc_s(sizeof(PyjuBtElement_t) * (PYJU_MAX_BT_SIZE + 1));
    memset(bt_data, 0, sizeof(PyjuBtElement_t) * (PYJU_MAX_BT_SIZE + 1));
    ptls->bt_data = bt_data;
    small_arraylist_new(&ptls->locks, 0);
    pyju_init_thread_heap(ptls);

    pyju_all_tls_states[tid] = ptls;

    return ptls;
}

PYJU_DLLEXPORT PyjuMutex_t pyju_codegen_lock;
PyjuMutex_t typecache_lock;

PYJU_DLLEXPORT ssize_t pyju_tls_offset = -1;

#ifdef PYJU_ELF_TLS_VARIANT
PYJU_DLLEXPORT const int pyju_tls_elf_support = 1;
// Optimize TLS access in codegen if the TLS buffer is using a IE or LE model.
// To detect such case, we find the size of the TLS segment in the main
// executable and the thread pointer (TP) and then see if the TLS pointer on the
// current thread is in the right range.
// This can in principle be extended to the case where the TLS buffer is
// in the shared library but is part of the static buffer but that seems harder
// to detect.
#  if PYJU_ELF_TLS_VARIANT == 1
// In Variant 1, the static TLS buffer comes after a fixed size TCB.
// The alignment needs to be applied to the original size.
static inline size_t pyju_add_tls_size(size_t orig_size, size_t size, size_t align)
{
    return LLT_ALIGN(orig_size, align) + size;
}
static inline ssize_t pyju_check_tls_bound(void *tp, PyjuGcFrame_t ***k0, size_t tls_size)
{
    ssize_t offset = (char*)k0 - (char*)tp;
    if (offset < PYJU_ELF_TLS_INIT_SIZE ||
        (size_t)offset + sizeof(*k0) > tls_size)
        return -1;
    return offset;
}
#  elif PYJU_ELF_TLS_VARIANT == 2
// In Variant 2, the static TLS buffer comes before a unknown size TCB.
// The alignment needs to be applied to the new size.
static inline size_t pyju_add_tls_size(size_t orig_size, size_t size, size_t align)
{
    return LLT_ALIGN(orig_size + size, align);
}
static inline ssize_t pyju_check_tls_bound(void *tp, PyjuGcFrame_t ***k0, size_t tls_size)
{
    ssize_t offset = (char*)tp - (char*)k0;
    if (offset < sizeof(*k0) || offset > tls_size)
        return -1;
    return -offset;
}
#  else
#    error "Unknown static TLS variant"
#  endif

// Find the size of the TLS segment in the main executable
typedef struct {
    size_t total_size;
} check_tls_cb_t;

static int check_tls_cb(struct dl_phdr_info *info, size_t size, void *_data)
{
    check_tls_cb_t *data = (check_tls_cb_t*)_data;
    const ElfW(Phdr) *phdr = info->dlpi_phdr;
    unsigned phnum = info->dlpi_phnum;
    size_t total_size = PYJU_ELF_TLS_INIT_SIZE;

    for (unsigned i = 0; i < phnum; i++) {
        const ElfW(Phdr) *seg = &phdr[i];
        if (seg->p_type != PT_TLS)
            continue;
        // There should be only one TLS segment
        // Variant II
        total_size = pyju_add_tls_size(total_size, seg->p_memsz, seg->p_align);
    }
    data->total_size = total_size;
    // only run once (on the main executable)
    return 1;
}

static void pyju_check_tls(void)
{
    pyju_get_pgcstack_func *f;
    PyjuGcFrame_t ***(*k)(void);
    pyju_pgcstack_getkey(&f, &k);
    PyjuGcFrame_t ***k0 = k();
    if (k0 == NULL)
        return;
    check_tls_cb_t data = {0};
    dl_iterate_phdr(check_tls_cb, &data);
    if (data.total_size == 0)
        return;
    void *tp; // Thread pointer
#if defined(_CPU_X86_64_)
    asm("movq %%fs:0, %0" : "=r"(tp));
#elif defined(_CPU_X86_)
    asm("movl %%gs:0, %0" : "=r"(tp));
#elif defined(_CPU_AARCH64_)
    asm("mrs %0, tpidr_el0" : "=r"(tp));
#elif defined(__ARM_ARCH) && __ARM_ARCH >= 7
    asm("mrc p15, 0, %0, c13, c0, 3" : "=r"(tp));
#else
#  error "Cannot emit thread pointer for this architecture."
#endif
    ssize_t offset = pyju_check_tls_bound(tp, k0, data.total_size);
    if (offset == -1)
        return;
    pyju_tls_offset = offset;
}
#else
// !PYJU_ELF_TLS_VARIANT
PYJU_DLLEXPORT const int pyju_tls_elf_support = 0;
#endif

// interface to Julia; sets up to make the runtime thread-safe
void pyju_init_threading(void)
{
    char *cp;

#ifdef PYJU_ELF_TLS_VARIANT
    pyju_check_tls();
#endif

    // how many threads available, usable
    pyju_n_threads = JULIA_NUM_THREADS;
    if (pyju_options.nthreads < 0) { // --threads=auto
        pyju_n_threads = pyju_cpu_threads();
    }
    else if (pyju_options.nthreads > 0) { // --threads=N
        pyju_n_threads = pyju_options.nthreads;
    }
    else if ((cp = getenv(NUM_THREADS_NAME))) {
        if (strcmp(cp, "auto"))
            pyju_n_threads = (uint64_t)strtol(cp, NULL, 10); // ENV[NUM_THREADS_NAME] == "N"
        else
            pyju_n_threads = pyju_cpu_threads(); // ENV[NUM_THREADS_NAME] == "auto"
    }
    if (pyju_n_threads <= 0)
        pyju_n_threads = 1;
#ifndef __clang_gcanalyzer__
    pyju_all_tls_states = (PyjuPtls_t*)calloc(pyju_n_threads, sizeof(void*));
#endif
}

static uv_barrier_t thread_init_done;

// void pyju_start_threads(void)
// {
//     int cpumasksize = uv_cpumask_size();
//     char *cp;
//     int i, exclusive;
//     uv_thread_t uvtid;
//     if (cpumasksize < pyju_n_threads) // also handles error case
//         cpumasksize = pyju_n_threads;
//     char *mask = (char*)alloca(cpumasksize);

//     // do we have exclusive use of the machine? default is no
//     exclusive = DEFAULT_MACHINE_EXCLUSIVE;
//     cp = getenv(MACHINE_EXCLUSIVE_NAME);
//     if (cp && strcmp(cp, "0") != 0)
//         exclusive = 1;

//     // exclusive use: affinitize threads, master thread on proc 0, rest
//     // according to a 'compact' policy
//     // non-exclusive: no affinity settings; let the kernel move threads about
//     if (exclusive) {
//         if (pyju_n_threads > pyju_cpu_threads()) {
//             pyju_printf(PYJU_STDERR, "ERROR: Too many threads requested for %s option.\n", MACHINE_EXCLUSIVE_NAME);
//             exit(1);
//         }
//         memset(mask, 0, cpumasksize);
//         mask[0] = 1;
//         uvtid = uv_thread_self();
//         uv_thread_setaffinity(&uvtid, mask, NULL, cpumasksize);
//         mask[0] = 0;
//     }

//     // The analyzer doesn't know pyju_n_threads doesn't change, help it
//     size_t nthreads = pyju_n_threads;

//     // create threads
//     uv_barrier_init(&thread_init_done, nthreads);

//     for (i = 1; i < nthreads; ++i) {
//         PyjugThreadArg_t *t = (PyjugThreadArg_t*)malloc_s(sizeof(PyjugThreadArg_t)); // ownership will be passed to the thread
//         t->tid = i;
//         t->barrier = &thread_init_done;
//         uv_thread_create(&uvtid, pyju_threadfun, t);
//         if (exclusive) {
//             mask[i] = 1;
//             uv_thread_setaffinity(&uvtid, mask, NULL, cpumasksize);
//             mask[i] = 0;
//         }
//         uv_thread_detach(&uvtid);
//     }

//     uv_barrier_wait(&thread_init_done);
// }

_Atomic(unsigned) _threadedregion; // HACK: keep track of whether to prioritize IO or threading

PYJU_DLLEXPORT int pyju_in_threaded_region(void)
{
    return pyju_atomic_load_relaxed(&_threadedregion) != 0;
}

PYJU_DLLEXPORT void pyju_enter_threaded_region(void)
{
    pyju_atomic_fetch_add(&_threadedregion, 1);
}

// PYJU_DLLEXPORT void pyju_exit_threaded_region(void)
// {
//     if (pyju_atomic_fetch_add(&_threadedregion, -1) == 1) {
//         // make sure no more callbacks will run while user code continues
//         // outside thread region and might touch an I/O object.
//         PYJU_UV_LOCK();
//         PYJU_UV_UNLOCK();
//         // make sure thread 0 is not using the sleep_lock
//         // so that it may enter the libuv event loop instead
//         pyju_wakeup_thread(0);
//     }
// }


// Make gc alignment available for threading
// see threads.jl alignment
PYJU_DLLEXPORT int pyju_alignment(size_t sz)
{
    return pyju_gc_alignment(sz);
}

#ifdef __cplusplus
}
#endif
