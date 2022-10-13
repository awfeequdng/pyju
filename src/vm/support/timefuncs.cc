// This file is a part of Julia. License is MIT: https://julialang.org/license

#include <assert.h>

#include "dtypes.h"

#include <sys/time.h>
#include <sys/select.h>

#include "timefuncs.h"

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT int pyju_gettimeofday(struct pyju_timeval *jtv)
{
#if defined(_OS_WINDOWS_)
    struct __timeb64 tb;
    errno_t code = _ftime64_s(&tb);
    jtv->sec = tb.time;
    jtv->usec = tb.millitm * 1000;
#else
    struct timeval tv;
    int code = gettimeofday(&tv, NULL);
    jtv->sec = tv.tv_sec;
    jtv->usec = tv.tv_usec;
#endif
    return code;
}

PYJU_DLLEXPORT double pyju_clock_now(void)
{
    struct pyju_timeval now;
    pyju_gettimeofday(&now);
    return now.sec + now.usec * 1e-6;
}

void sleep_ms(int ms)
{
    if (ms == 0)
        return;

    struct timeval timeout;

    timeout.tv_sec = ms / 1000;
    timeout.tv_usec = (ms % 1000) * 1000;

    select(0, NULL, NULL, NULL, &timeout);
}

#ifdef __cplusplus
}
#endif
