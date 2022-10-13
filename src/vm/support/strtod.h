// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_STRTOD_H
#define PYJU_STRTOD_H

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT double pyju_strtod_c(const char *nptr, char **endptr);
PYJU_DLLEXPORT float pyju_strtof_c(const char *nptr, char **endptr);

#ifdef __cplusplus
}
#endif

#endif
