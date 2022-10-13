// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_TIMEFUNCS_H
#define PYJU_TIMEFUNCS_H

#ifdef __cplusplus
extern "C" {
#endif

struct pyju_timeval {
    int64_t sec;    /* seconds */
    int64_t usec;   /* microseconds */
};

PYJU_DLLEXPORT int pyju_gettimeofday(struct pyju_timeval *jtv);
PYJU_DLLEXPORT double pyju_clock_now(void);
void sleep_ms(int ms);

#ifdef __cplusplus
}
#endif

#endif
