// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_FASTTLS_H
#define PYJU_FASTTLS_H

// Thread-local storage access

#ifdef __cplusplus
extern "C" {
#endif

/* Bring in definitions for `_OS_X_`, `PYJU_PATH_MAX` and `PATHSEPSTRING`, `pyju_ptls_t`, etc... */
#include "support/platform.h"
#include "support/dirpath.h"

struct PyjuGcFrame_t;

typedef PyjuGcFrame_t **(pyju_get_pgcstack_func)(void);

#if !defined(_OS_DARWIN_) && !defined(_OS_WINDOWS_)
#define PYJU_DEFINE_FAST_TLS                                                                   \
static __attribute__((tls_model("local-exec"))) __thread PyjuGcFrame_t **pyju_pgcstack_localexec;  \
PYJU_DLLEXPORT PyjuGcFrame_t **pyju_get_pgcstack_static(void)                                        \
{                                                                                               \
    return pyju_pgcstack_localexec;                                                               \
}                                                                                               \
PYJU_DLLEXPORT PyjuGcFrame_t ***pyju_pgcstack_addr_static(void)                                      \
{                                                                                               \
    return &pyju_pgcstack_localexec;                                                              \
}
#else
#define PYJU_DEFINE_FAST_TLS
#endif

#ifdef __cplusplus
}
#endif

#endif
