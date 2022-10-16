// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef THREADING_H
#define THREADING_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

#include "pyju_object.h"
#include <uv.h>

#define PROFILE_PYJU_THREADING            0

extern PyjuPtls_t *pyju_all_tls_states PYJU_GLOBALLY_ROOTED; /* thread local storage */

struct PyjuThreadArg_t {
    int16_t tid;
    uv_barrier_t *barrier;
    void *arg;
};

// each thread must initialize its TLS
PyjuPtls_t pyju_init_threadtls(int16_t tid);

// provided by a threading infrastructure
void pyju_init_threadinginfra(void);
void pyju_threadfun(void *arg);

#ifdef __cplusplus
}
#endif

#endif  /* THREADING_H */
