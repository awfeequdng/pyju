#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "threading.h"

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


static int uv_dup(uv_os_fd_t fd, uv_os_fd_t* dupfd) {
    if ((*dupfd = fcntl(fd, F_DUPFD_CLOEXEC, 3)) == -1)
        return -errno;
    return 0;
}

static void *init_stdio_handle(const char *stdio, uv_os_fd_t fd, int readable)
{
    void *handle;
    int err;
    // Duplicate the file descriptor so we can later dup it over if we want to redirect
    // STDIO without having to worry about closing the associated libuv object.
    // This also helps limit the impact other libraries can cause on our file handle.
    if ((err = uv_dup(fd, &fd)))
        pyju_errorf("error initializing %s in uv_dup: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
    switch(uv_guess_handle(fd)) {
    case UV_TTY:
        handle = malloc_s(sizeof(uv_tty_t));
        if ((err = uv_tty_init(pyju_io_loop, (uv_tty_t*)handle, fd, 0))) {
            pyju_errorf("error initializing %s in uv_tty_init: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        ((uv_tty_t*)handle)->data = NULL;
        uv_tty_set_mode((uv_tty_t*)handle, UV_TTY_MODE_NORMAL); // initialized cooked stdio
        break;
    default:
        assert(0 && "missing case for uv_guess_handle return handling");
        PYJU_FALLTHROUGH;
    case UV_UDP:
        PYJU_FALLTHROUGH;
    case UV_UNKNOWN_HANDLE:
        // dup the descriptor with a new one pointing at the bit bucket ...
#if defined(_OS_WINDOWS_)
        CloseHandle(fd);
        fd = CreateFile("NUL", readable ? FILE_GENERIC_READ : FILE_GENERIC_WRITE | FILE_READ_ATTRIBUTES,
                FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
#else
        {
            int nullfd;
            nullfd = open("/dev/null", O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH /* 0666 */);
            assert(nullfd != -1);
            dup2(nullfd, fd);
            close(nullfd);
        }
#endif
        // ...and continue on as in the UV_FILE case
        PYJU_FALLTHROUGH;
    case UV_FILE:
        handle = malloc_s(sizeof(pyju_uv_file_t));
        {
            pyju_uv_file_t *file = (pyju_uv_file_t*)handle;
            file->loop = pyju_io_loop;
            file->type = UV_FILE;
            file->file = fd;
            file->data = NULL;
        }
        break;
    case UV_NAMED_PIPE:
        handle = malloc_s(sizeof(uv_pipe_t));
        if ((err = uv_pipe_init(pyju_io_loop, (uv_pipe_t*)handle, 0))) {
            pyju_errorf("error initializing %s in uv_pipe_init: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        if ((err = uv_pipe_open((uv_pipe_t*)handle, fd))) {
            pyju_errorf("error initializing %s in uv_pipe_open: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        ((uv_pipe_t*)handle)->data = NULL;
        break;
    case UV_TCP:
        handle = malloc_s(sizeof(uv_tcp_t));
        if ((err = uv_tcp_init(pyju_io_loop, (uv_tcp_t*)handle))) {
            pyju_errorf("error initializing %s in uv_tcp_init: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        if ((err = uv_tcp_open((uv_tcp_t*)handle, (uv_os_sock_t)fd))) {
            pyju_errorf("error initializing %s in uv_tcp_open: %s (%s %d)", stdio, uv_strerror(err), uv_err_name(err), err);
        }
        ((uv_tcp_t*)handle)->data = NULL;
        break;
    }
    return handle;
}

static void init_stdio(void)
{
    PYJU_STDIN  = (uv_stream_t*)init_stdio_handle("stdin", UV_STDIN_FD, 1);
    PYJU_STDOUT = (uv_stream_t*)init_stdio_handle("stdout", UV_STDOUT_FD, 0);
    PYJU_STDERR = (uv_stream_t*)init_stdio_handle("stderr", UV_STDERR_FD, 0);
    pyju_flush_cstdio();
}


static void pyju_set_io_wait(int v)
{
    PyjuTask_t *ct = pyju_current_task;
    ct->ptls->io_wait = v;
}
extern PyjuMutex_t pyju_modules_mutex;


static NOINLINE void _finish_pyju_init(PyjuPtls_t ptls, PyjuTask_t *ct);

PYJU_DLLEXPORT void pyju_init() {
    pyju_init_timing();
    // Make sure we finalize the tls callback before starting any threads.
    (void)pyju_get_pgcstack();
    pyju_safepoint_init();
    libsupport_init();
    htable_new(&pyju_current_modules, 0);
    ios_set_io_wait_func = pyju_set_io_wait;
    pyju_io_loop = uv_default_loop(); // this loop will internal events (spawning process etc.),
                                        // best to call this first, since it also initializes libuv

    pyju_init_uv();
    init_stdio();
    pyju_printf(PYJU_STDOUT, "call pyju_init \n");

    pyju_page_size = pyju_getpagesize();
    void *stack_lo, *stack_hi;
    pyju_init_stack_limits(1, &stack_lo, &stack_hi);

    pyju_init_rand();

    pyju_init_tasks();
    pyju_init_threading();

    pyju_gc_init();
    PyjuPtls_t ptls = pyju_init_threadtls(0);
    // warning: this changes `pyju_current_task`, so be careful not to call that from this function
    PyjuTask_t *ct = pyju_init_root_task(ptls, stack_lo, stack_hi);
    PYJU_GC_PROMISE_ROOTED(ct);
    _finish_pyju_init(ptls, ct);

    pyju_printf(PYJU_STDOUT, "pyju_init finished\n");
}

static NOINLINE void _finish_pyju_init(PyjuPtls_t ptls, PyjuTask_t *ct)
{
    pyju_init_types();
    pyju_global_roots_table = pyju_alloc_vec_any(16);
    pyju_init_common_symbols();

    // pyju_core_module = pyju_new_module(pyju_symbol("Core"));
    // pyju_core_module->parent = pyju_core_module;
}

#ifdef __cplusplus
} // extern "C"
#endif