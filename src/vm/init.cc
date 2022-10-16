#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#include "support/libsupport.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h> // defines dirname

#if !defined(_OS_WINDOWS_) || defined(_COMPILER_GCC_)
#include <getopt.h>
#endif

#include <uv.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/resource.h>
#include <unistd.h>

// list of modules being deserialized with __init__ methods
PyjuArray_t *pyju_module_init_order;

PYJU_DLLEXPORT size_t pyju_page_size;


void pyju_init_stack_limits(int ismaster, void **stack_lo, void **stack_hi)
{
    // Only use pthread_*_np functions to get stack address for non-master
    // threads since it seems to return bogus values for master thread on Linux
    // and possibly OSX.
    if (!ismaster) {
#  if defined(_OS_LINUX_)
        pthread_attr_t attr;
        pthread_getattr_np(pthread_self(), &attr);
        void *stackaddr;
        size_t stacksize;
        pthread_attr_getstack(&attr, &stackaddr, &stacksize);
        pthread_attr_destroy(&attr);
        *stack_lo = (void*)stackaddr;
#pragma GCC diagnostic push
#if defined(_COMPILER_GCC_) && __GNUC__ >= 12
#pragma GCC diagnostic ignored "-Wdangling-pointer"
#endif
        *stack_hi = (void*)&stacksize;
#pragma GCC diagnostic pop
        return;
#  elif defined(_OS_DARWIN_)
        extern void *pthread_get_stackaddr_np(pthread_t thread);
        extern size_t pthread_get_stacksize_np(pthread_t thread);
        pthread_t thread = pthread_self();
        void *stackaddr = pthread_get_stackaddr_np(thread);
        size_t stacksize = pthread_get_stacksize_np(thread);
        *stack_lo = (void*)stackaddr;
        *stack_hi = (void*)&stacksize;
        return;
#  elif defined(_OS_FREEBSD_)
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_get_np(pthread_self(), &attr);
        void *stackaddr;
        size_t stacksize;
        pthread_attr_getstack(&attr, &stackaddr, &stacksize);
        pthread_attr_destroy(&attr);
        *stack_lo = (void*)stackaddr;
        *stack_hi = (void*)&stacksize;
        return;
#  else
#      warning "Getting precise stack size for thread is not supported."
#  endif
    }
    struct rlimit rl;
    getrlimit(RLIMIT_STACK, &rl);
    size_t stacksize = rl.rlim_cur;
// We intentionally leak a stack address here core.StackAddressEscape
#  ifndef __clang_analyzer__
    *stack_hi = (void*)&stacksize;
#pragma GCC diagnostic push
#if defined(_COMPILER_GCC_) && __GNUC__ >= 12
#pragma GCC diagnostic ignored "-Wdangling-pointer"
#endif
    *stack_lo = (void*)((char*)*stack_hi - stacksize);
#pragma GCC diagnostic pop
#  else
    *stack_hi = 0;
    *stack_lo = 0;
#  endif

}

uv_loop_t *pyju_io_loop;


PYJU_DLLEXPORT void pyju_init() {
    // Make sure we finalize the tls callback before starting any threads.
    (void)pyju_get_pgcstack();

    pyju_io_loop = uv_default_loop(); // this loop will internal events (spawning process etc.),
                                        // best to call this first, since it also initializes libuv
}

#ifdef __cplusplus
} // extern "C"
#endif