// This file is a part of Julia. License is MIT: https://julialang.org/license

#include "pyju.h"
#include "pyju_internal.h"
#include "threading.h"
#include <sys/mman.h>
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// 0: no sigint is pending
// 1: at least one sigint is pending, only the sigint page is enabled.
// 2: at least one sigint is pending, both safepoint pages are enabled.
PYJU_DLLEXPORT sig_atomic_t pyju_signal_pending = 0;
_Atomic(uint32_t) pyju_gc_running = 0;
char *pyju_safepoint_pages = NULL;
// The number of safepoints enabled on the three pages.
// The first page, is the SIGINT page, only used by the master thread.
// The second page, is the GC page for the master thread, this is where
// the `safepoint` tls pointer points to for the master thread.
// The third page is the GC page for the other threads. The thread's
// `safepoint` tls pointer points the beginning of this page + `sizeof(size_t)`
// so that both safepoint load and pending signal load falls in this page.
// The initialization of the `safepoint` pointer is done `ti_initthread`
// in `threading.c`.
uint8_t pyju_safepoint_enable_cnt[3] = {0, 0, 0};

// This lock should be acquired before enabling/disabling the safepoint
// or accessing one of the following variables:
//
// * pyju_gc_running
// * pyju_signal_pending
// * pyju_safepoint_enable_cnt
//
// Additionally accessing `pyju_gc_running` should use acquire/release
// load/store so that threads waiting for the GC doesn't have to also
// fight on the safepoint lock...
uv_mutex_t safepoint_lock;

static void pyju_safepoint_enable(int idx) PYJU_NOTSAFEPOINT
{
    // safepoint_lock should be held
    assert(0 <= idx && idx < 3);
    if (pyju_safepoint_enable_cnt[idx]++ != 0) {
        // We expect this to be enabled at most twice
        // one for the GC, one for SIGINT.
        // Update this if this is not the case anymore in the future.
        assert(pyju_safepoint_enable_cnt[idx] <= 2);
        return;
    }
    // Now that we are requested to mprotect the page and it wasn't already.
    char *pageaddr = pyju_safepoint_pages + pyju_page_size * idx;

    mprotect(pageaddr, pyju_page_size, PROT_NONE);
}

static void pyju_safepoint_disable(int idx) PYJU_NOTSAFEPOINT
{
    // safepoint_lock should be held
    assert(0 <= idx && idx < 3);
    if (--pyju_safepoint_enable_cnt[idx] != 0) {
        assert(pyju_safepoint_enable_cnt[idx] > 0);
        return;
    }
    // Now that we are requested to un-mprotect the page and no one else
    // want it to be kept protected.
    char *pageaddr = pyju_safepoint_pages + pyju_page_size * idx;

    mprotect(pageaddr, pyju_page_size, PROT_READ);
}

void pyju_safepoint_init(void)
{
    uv_mutex_init(&safepoint_lock);
    // pyju_page_size isn't available yet.
    size_t pgsz = pyju_getpagesize();
#ifdef _OS_WINDOWS_
    char *addr = (char*)VirtualAlloc(NULL, pgsz * 3, MEM_COMMIT, PAGE_READONLY);
#else
    char *addr = (char*)mmap(0, pgsz * 3, PROT_READ,
                             MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED)
        addr = NULL;
#endif
    if (addr == NULL) {
        printf("pyju_printf(PYJU_STDERR not implemented");
        // pyju_printf(PYJU_STDERR, "could not allocate GC synchronization page\n");
        // pyju_gc_debug_critical_error();
        abort();
    }
    // The signal page is for the gc safepoint.
    // The page before it is the sigint pending flag.
    pyju_safepoint_pages = addr;
}

int pyju_safepoint_start_gc(void)
{
    if (pyju_n_threads == 1) {
        pyju_atomic_store_relaxed(&pyju_gc_running, 1);
        return 1;
    }
    // The thread should have set this already
    assert(pyju_atomic_load_relaxed(&pyju_current_task->ptls->gc_state) == PYJU_GC_STATE_WAITING);
    uv_mutex_lock(&safepoint_lock);
    // In case multiple threads enter the GC at the same time, only allow
    // one of them to actually run the collection. We can't just let the
    // master thread do the GC since it might be running unmanaged code
    // and can take arbitrarily long time before hitting a safe point.
    uint32_t running = 0;
    if (!pyju_atomic_cmpswap(&pyju_gc_running, &running, 1)) {
        uv_mutex_unlock(&safepoint_lock);
        pyju_safepoint_wait_gc();
        return 0;
    }
    pyju_safepoint_enable(1);
    pyju_safepoint_enable(2);
    uv_mutex_unlock(&safepoint_lock);
    return 1;
}

void pyju_safepoint_end_gc(void)
{
    assert(pyju_atomic_load_relaxed(&pyju_gc_running));
    if (pyju_n_threads == 1) {
        pyju_atomic_store_relaxed(&pyju_gc_running, 0);
        return;
    }
    uv_mutex_lock(&safepoint_lock);
    // Need to reset the page protection before resetting the flag since
    // the thread will trigger a segfault immediately after returning from
    // the signal handler.
    pyju_safepoint_disable(2);
    pyju_safepoint_disable(1);
    pyju_atomic_store_release(&pyju_gc_running, 0);
#  ifdef __APPLE__
    // This wakes up other threads on mac.
    pyju_mach_gc_end();
#  endif
    uv_mutex_unlock(&safepoint_lock);
}

void pyju_safepoint_wait_gc(void)
{
    // The thread should have set this is already
    assert(pyju_atomic_load_relaxed(&pyju_current_task->ptls->gc_state) != 0);
    // Use normal volatile load in the loop for speed until GC finishes.
    // Then use an acquire load to make sure the GC result is visible on this thread.
    while (pyju_atomic_load_relaxed(&pyju_gc_running) || pyju_atomic_load_acquire(&pyju_gc_running)) {
        pyju_cpu_pause(); // yield?
    }
}

void pyju_safepoint_enable_sigint(void)
{
    uv_mutex_lock(&safepoint_lock);
    // Make sure both safepoints are enabled exactly once for SIGINT.
    switch (pyju_signal_pending) {
    default:
        assert(0 && "Shouldn't happen.");
    case 0:
        // Enable SIGINT page
        pyju_safepoint_enable(0);
        // fall through
    case 1:
        // SIGINT page is enabled, enable GC page
        pyju_safepoint_enable(1);
        // fall through
    case 2:
        pyju_signal_pending = 2;
    }
    uv_mutex_unlock(&safepoint_lock);
}

void pyju_safepoint_defer_sigint(void)
{
    uv_mutex_lock(&safepoint_lock);
    // Make sure the GC safepoint is disabled for SIGINT.
    if (pyju_signal_pending == 2) {
        pyju_safepoint_disable(1);
        pyju_signal_pending = 1;
    }
    uv_mutex_unlock(&safepoint_lock);
}

int pyju_safepoint_consume_sigint(void)
{
    int has_signal = 0;
    uv_mutex_lock(&safepoint_lock);
    // Make sure both safepoints are disabled for SIGINT.
    switch (pyju_signal_pending) {
    default:
        assert(0 && "Shouldn't happen.");
    case 2:
        // Disable gc page
        pyju_safepoint_disable(1);
        // fall through
    case 1:
        // GC page is disabled, disable SIGINT page
        pyju_safepoint_disable(0);
        has_signal = 1;
        // fall through
    case 0:
        pyju_signal_pending = 0;
    }
    uv_mutex_unlock(&safepoint_lock);
    return has_signal;
}

#ifdef __cplusplus
}
#endif
