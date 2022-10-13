// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_LIBSUPPORT_H
#define PYJU_LIBSUPPORT_H

#include "platform.h"

#include <stdlib.h>
#include <stdarg.h>
#include "dtypes.h"
#include "utf8.h"
#include "ios.h"

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT void libsupport_init(void);

#ifdef __cplusplus
}
#endif

#endif
