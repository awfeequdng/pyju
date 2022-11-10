

#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <pthread.h>
#include <time.h>
#include <errno.h>
#if defined(_OS_DARWIN_) && !defined(MAP_ANONYMOUS)
#define MAP_ANONYMOUS MAP_ANON
#endif

#ifdef __APPLE__
#include <AvailabilityMacros.h>
#ifdef MAC_OS_X_VERSION_10_9
#include <sys/_types/_ucontext64.h>
#else
#define __need_ucontext64_t
#include <machine/_structs.h>
#endif
#endif

// Figure out the best signals/timers to use for this platform
#ifdef __APPLE__ // Darwin's mach ports allow signal-free thread management
#define HAVE_MACH
#define HAVE_KEVENT
#elif defined(__FreeBSD__) // generic bsd
#define HAVE_ITIMER
#else // generic linux
#define HAVE_TIMER
#endif

#ifdef HAVE_KEVENT
#include <sys/event.h>
#endif

// 8M signal stack, same as default stack size and enough
// for reasonable finalizers.
// Should also be enough for parallel GC when we have it =)
#define sig_stack_size (8 * 1024 * 1024)

#include "pyju_assert.h"
#include "pyju.h"
#include "pyju_internal.h"

static void *alloc_sigstack(size_t *ssize)
{
    void *stk = pyju_malloc_stack(ssize, NULL);
    if (stk == MAP_FAILED)
        pyju_errorf("fatal error allocating signal stack: mmap: %s", strerror(errno));
    return stk;
}

void pyju_install_thread_signal_handler(PyjuPtls_t ptls)
{
    size_t ssize = sig_stack_size;
    void *signal_stack = alloc_sigstack(&ssize);
    ptls->signal_stack = signal_stack;
    stack_t ss;
    ss.ss_flags = 0;
    ss.ss_size = ssize - 16;
    ss.ss_sp = signal_stack;
    if (sigaltstack(&ss, NULL) < 0) {
        pyju_errorf("fatal error: sigaltstack: %s", strerror(errno));
    }
}