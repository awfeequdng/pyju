#include "support/platform.h"

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>

#include "pyju.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#include "support/ios.h"
#include "uv.h"

#ifdef __cplusplus
#include <cstring>
extern "C" {
#endif

static uv_async_t signal_async;

static void pyju_signal_async_cb(uv_async_t *hdl)
{
    // This should abort the current loop and the julia code it returns to
    // or the safepoint in the callers of `uv_run` should throw the exception.
    (void)hdl;
    uv_stop(pyju_io_loop);
}

void pyju_wake_libuv(void)
{
    uv_async_send(&signal_async);
}

PyjuMutex_t pyju_uv_mutex;
void pyju_init_uv(void)
{
    uv_async_init(pyju_io_loop, &signal_async, pyju_signal_async_cb);
    PYJU_MUTEX_INIT(&pyju_uv_mutex); // a file-scope initializer can be used instead
}

_Atomic(int) pyju_uv_n_waiters = 0;

void PYJU_UV_LOCK(void)
{
    if (pyju_mutex_trylock(&pyju_uv_mutex)) {
    }
    else {
        pyju_atomic_fetch_add_relaxed(&pyju_uv_n_waiters, 1);
        pyju_fence(); // [^store_buffering_2]
        pyju_wake_libuv();
        PYJU_LOCK(&pyju_uv_mutex);
        pyju_atomic_fetch_add_relaxed(&pyju_uv_n_waiters, -1);
    }
}

PYJU_DLLEXPORT void pyju_iolock_begin(void)
{
    PYJU_UV_LOCK();
}

PYJU_DLLEXPORT void pyju_iolock_end(void)
{
    PYJU_UV_UNLOCK();
}


PYJU_DLLEXPORT uv_loop_t *pyju_global_event_loop(void)
{
    return pyju_io_loop;
}

PYJU_DLLEXPORT int pyju_fs_unlink(char *path)
{
    uv_fs_t req;
    PYJU_SIGATOMIC_BEGIN();
    int ret = uv_fs_unlink(unused_uv_loop_arg, &req, path, NULL);
    uv_fs_req_cleanup(&req);
    PYJU_SIGATOMIC_END();
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_rename(const char *src_path, const char *dst_path)
{
    uv_fs_t req;
    PYJU_SIGATOMIC_BEGIN();
    int ret = uv_fs_rename(unused_uv_loop_arg, &req, src_path, dst_path, NULL);
    uv_fs_req_cleanup(&req);
    PYJU_SIGATOMIC_END();
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_sendfile(uv_os_fd_t src_fd, uv_os_fd_t dst_fd,
                                int64_t in_offset, size_t len)
{
    uv_fs_t req;
    PYJU_SIGATOMIC_BEGIN();
    int ret = uv_fs_sendfile(unused_uv_loop_arg, &req, dst_fd, src_fd,
                             in_offset, len, NULL);
    uv_fs_req_cleanup(&req);
    PYJU_SIGATOMIC_END();
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_hardlink(char *path, char *new_path)
{
    uv_fs_t req;
    int ret = uv_fs_link(unused_uv_loop_arg, &req, path, new_path, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_symlink(char *path, char *new_path, int flags)
{
    uv_fs_t req;
    int ret = uv_fs_symlink(unused_uv_loop_arg, &req, path, new_path, flags, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_chmod(char *path, int mode)
{
    uv_fs_t req;
    int ret = uv_fs_chmod(unused_uv_loop_arg, &req, path, mode, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_chown(char *path, int uid, int gid)
{
    uv_fs_t req;
    int ret = uv_fs_chown(unused_uv_loop_arg, &req, path, uid, gid, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_access(char *path, int mode)
{
    uv_fs_t req;
    int ret = uv_fs_access(unused_uv_loop_arg, &req, path, mode, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_write(uv_os_fd_t handle, const char *data, size_t len,
                             int64_t offset) PYJU_NOTSAFEPOINT
{
    PyjuTask_t *ct = pyju_get_current_task();
    // TODO: fix this cheating
    if (pyju_get_safe_restore() || ct == NULL || pyju_atomic_load_relaxed(&ct->tid) != 0)
        return write(handle, data, len);

    uv_fs_t req;
    uv_buf_t buf[1];
    buf[0].base = (char*)data;
    buf[0].len = len;
    if (!pyju_io_loop)
        pyju_io_loop = uv_default_loop();
    int ret = uv_fs_write(unused_uv_loop_arg, &req, handle, buf, 1, offset, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}

PYJU_DLLEXPORT int pyju_fs_read(uv_os_fd_t handle, char *data, size_t len)
{
    uv_fs_t req;
    uv_buf_t buf[1];
    buf[0].base = data;
    buf[0].len = len;
    int ret = uv_fs_read(unused_uv_loop_arg, &req, handle, buf, 1, -1, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}


PYJU_DLLEXPORT int pyju_fs_read_byte(uv_os_fd_t handle)
{
    uv_fs_t req;
    unsigned char c;
    uv_buf_t buf[1];
    buf[0].base = (char*)&c;
    buf[0].len = 1;
    int ret = uv_fs_read(unused_uv_loop_arg, &req, handle, buf, 1, -1, NULL);
    uv_fs_req_cleanup(&req);
    switch (ret) {
    case -1: return ret;
    case  0: pyju_eof_error();
    case  1: return (int)c;
    default:
        assert(0 && "pyju_fs_read_byte: Invalid return value from uv_fs_read");
        return -1;
    }
}


PYJU_DLLEXPORT int pyju_fs_close(uv_os_fd_t handle)
{
    uv_fs_t req;
    int ret = uv_fs_close(unused_uv_loop_arg, &req, handle, NULL);
    uv_fs_req_cleanup(&req);
    return ret;
}


PYJU_DLLEXPORT int pyju_uv_write(uv_stream_t *stream, const char *data, size_t n,
                             uv_write_t *uvw, uv_write_cb writecb)
{
    uv_buf_t buf[1];
    buf[0].base = (char*)data;
    buf[0].len = n;
    PYJU_UV_LOCK();
    PYJU_SIGATOMIC_BEGIN();
    int err = uv_write(uvw, stream, buf, 1, writecb);
    PYJU_UV_UNLOCK();
    PYJU_SIGATOMIC_END();
    return err;
}

PYJU_DLLEXPORT void pyju_uv_writecb(uv_write_t *req, int status)
{
    free(req);
    if (status < 0) {
        pyju_safe_printf("pyju_uv_writecb() ERROR: %s %s\n",
                       uv_strerror(status), uv_err_name(status));
    }
}

PYJU_DLLEXPORT void pyju_uv_puts(uv_stream_t *stream, const char *str, size_t n)
{
    assert(stream);
    static_assert(offsetof(uv_stream_t,type) == offsetof(ios_t,bm) &&
        sizeof(((uv_stream_t*)0)->type) == sizeof(((ios_t*)0)->bm),
            "UV and ios layout mismatch");

    uv_os_fd_t fd = (uv_os_fd_t)(ssize_t)-1;

    // Fallback for output during early initialisation...
    if (stream == (void*)STDOUT_FILENO) {
        fd = UV_STDOUT_FD;
    }
    else if (stream == (void*)STDERR_FILENO) {
        fd = UV_STDERR_FD;
    }
    else if (stream->type == UV_FILE) {
        fd = ((pyju_uv_file_t*)stream)->file;
    }

    // TODO: Hack to make CoreIO thread-safer
    PyjuTask_t *ct = pyju_get_current_task();
    if (ct == NULL || pyju_atomic_load_relaxed(&ct->tid) != 0) {
        if (stream == PYJU_STDOUT) {
            fd = UV_STDOUT_FD;
        }
        else if (stream == PYJU_STDERR) {
            fd = UV_STDERR_FD;
        }
    }

    if ((ssize_t)fd != -1) {
        // Write to file descriptor...
        pyju_fs_write(fd, str, n, -1);
    }
    else if (stream->type > UV_HANDLE_TYPE_MAX) {
        // Write to ios.c stream...
        // This is needed because caller pyju_static_show() in builtins.c can be
        // called from fl_print in flisp/print.c (via cvalue_printdata()),
        // and cvalue_printdata() passes ios_t* to pyju_static_show().
        ios_write((ios_t*)stream, str, n);
    }
    else {
        // Write to libuv stream...
        uv_write_t *req = (uv_write_t*)malloc_s(sizeof(uv_write_t) + n);
        char *data = (char*)(req + 1);
        memcpy(data, str, n);
        uv_buf_t buf[1];
        buf[0].base = data;
        buf[0].len = n;
        req->data = NULL;
        PYJU_UV_LOCK();
        PYJU_SIGATOMIC_BEGIN();
        int status = uv_write(req, stream, buf, 1, (uv_write_cb)pyju_uv_writecb);
        PYJU_UV_UNLOCK();
        PYJU_SIGATOMIC_END();
        if (status < 0) {
            pyju_uv_writecb(req, status);
        }
    }
}

PYJU_DLLEXPORT void pyju_uv_putb(uv_stream_t *stream, uint8_t b)
{
    pyju_uv_puts(stream, (char*)&b, 1);
}

PYJU_DLLEXPORT void pyju_uv_putc(uv_stream_t *stream, uint32_t c)
{
    char s[4];
    int n = 1;
    s[0] = c >> 24;
    if ((s[1] = c >> 16)) {
        n++;
        if ((s[2] = c >> 8)) {
            n++;
            if ((s[3] = c)) {
                n++;
            }
        }
    }
    pyju_uv_puts(stream, s, n);
}

extern int vasprintf(char **str, const char *fmt, va_list ap);

PYJU_DLLEXPORT int pyju_vprintf(uv_stream_t *s, const char *format, va_list args)
{
    char *str = NULL;
    int c;
    va_list al;
#if defined(_OS_WINDOWS_) && !defined(_COMPILER_GCC_)
    al = args;
#else
    va_copy(al, args);
#endif

    c = vasprintf(&str, format, al);

    if (c >= 0) {
        pyju_uv_puts(s, str, c);
        free(str);
    }
    va_end(al);
    return c;
}

PYJU_DLLEXPORT int pyju_printf(uv_stream_t *s, const char *format, ...)
{
    va_list args;
    int c;

    va_start(args, format);
    c = pyju_vprintf(s, format, args);
    va_end(args);
    return c;
}

PYJU_DLLEXPORT void pyju_safe_printf(const char *fmt, ...) PYJU_NOTSAFEPOINT
{
    static char buf[1000];
    buf[0] = '\0';
    int last_errno = errno;

    va_list args;
    va_start(args, fmt);
    // Not async signal safe on some platforms?
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    buf[999] = '\0';
    if (write(STDERR_FILENO, buf, strlen(buf)) < 0) {
        // nothing we can do; ignore the failure
    }

    errno = last_errno;
}

#ifdef __cplusplus
}
#endif

