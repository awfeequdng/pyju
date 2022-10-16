// This file is a part of Julia. License is MIT: https://julialang.org/license

/*
  utility functions used by the runtime system, generated code, and Base library
*/
#include "support/platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>

#include <unistd.h>

#include <ctype.h>
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// exceptions -----------------------------------------------------------------

PYJU_DLLEXPORT void PYJU_NORETURN pyju_error(const char *str)
{
    // if (pyju_errorexception_type == NULL) {
    //     pyju_printf(PYJU_STDERR, "ERROR: %s\n", str);
    //     pyju_exit(1);
    // }
    // pyju_value_t *msg = pyju_pchar_to_string((char*)str, strlen(str));
    // PYJU_GC_PUSH1(&msg);
    // pyju_throw(pyju_new_struct(pyju_errorexception_type, msg));

    printf("not impl pyju_error\n");
    abort();
}

extern int vasprintf(char **str, const char *fmt, va_list ap);


PYJU_DLLEXPORT void PYJU_NORETURN pyju_errorf(const char *fmt, ...)
{
    // va_list args;
    // va_start(args, fmt);
    // pyju_value_t *e = pyju_vexceptionf(jl_errorexception_type, fmt, args);
    // va_end(args);
    // pyju_throw(e);

    printf("not impl pyju_errorf\n");
    abort();
}

// showing --------------------------------------------------------------------

PYJU_DLLEXPORT void pyju_flush_cstdio(void) PYJU_NOTSAFEPOINT
{
    fflush(stdout);
    fflush(stderr);
}

#ifdef __cplusplus
}
#endif
