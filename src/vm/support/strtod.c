#define _GNU_SOURCE
#include "libsupport.h"
#include <stdlib.h>
#include <locale.h>

#if defined(__APPLE__) || defined(__FreeBSD__)
#include <xlocale.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// This code path should be used for systems that support the strtod_l function

// Cache locale object
static int c_locale_initialized = 0;
static locale_t c_locale;

locale_t get_c_locale(void)
{
    if (!c_locale_initialized) {
        c_locale_initialized = 1;
        c_locale = newlocale(LC_ALL_MASK, "C", NULL);
    }
    return c_locale;
}

PYJU_DLLEXPORT double pyju_strtod_c(const char *nptr, char **endptr)
{
    return strtod_l(nptr, endptr, get_c_locale());
}

PYJU_DLLEXPORT float pyju_strtof_c(const char *nptr, char **endptr)
{
    return strtof_l(nptr, endptr, get_c_locale());
}

#ifdef __cplusplus
}
#endif
