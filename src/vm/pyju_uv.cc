#include "support/platform.h"

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>

#include "pyju_object.h"
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

PYJU_DLLEXPORT int pyju_printf(uv_stream_t *s, const char *format, ...) {
    printf("not impl jl_printf\n");
    return 0;
}

PYJU_DLLEXPORT void pyju_safe_printf(const char *fmt, ...) PYJU_NOTSAFEPOINT {
    printf("not impl jl_safe_printf\n");
}

_Atomic(int) pyju_uv_n_waiters = 0;

#ifdef __cplusplus
}
#endif

