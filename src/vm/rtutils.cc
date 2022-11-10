// This file is a part of Julia. License is MIT: https://julialang.org/license

/*
  utility functions used by the runtime system, generated code, and Base library
*/
#include "support/platform.h"

#include <cstdlib>
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
#include "pyju.h"
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


PyjuValue_t *pyju_vexceptionf(PyjuDataType_t *exception_type,
                           const char *fmt, va_list args)
{
    if (exception_type == NULL) {
        pyju_printf(PYJU_STDERR, "ERROR: ");
        pyju_vprintf(PYJU_STDERR, fmt, args);
        pyju_printf(PYJU_STDERR, "\n");
        // pyju_exit(1);
        exit(1);
    }
    char *str = NULL;
    int ok = vasprintf(&str, fmt, args);
    PyjuValue_t *msg;
    if (ok < 0) {  // vasprintf failed
        msg = pyju_cstr_to_string("internal error: could not display error message");
    }
    else {
        msg = pyju_pchar_to_string(str, strlen(str));
        free(str);
    }
    PYJU_GC_PUSH1(&msg);
    PyjuValue_t *e = pyju_new_struct(exception_type, msg);
    PYJU_GC_POP();
    return e;
}

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


PYJU_DLLEXPORT void PYJU_NORETURN pyju_eof_error(void) {
    printf("not impl pyju_eof_error\n");
    abort();
}

PYJU_DLLEXPORT void PYJU_NORETURN pyju_exceptionf(PyjuDataType_t *exception_type,
                                            const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    PyjuValue_t *e = pyju_vexceptionf(exception_type, fmt, args);
    va_end(args);
    pyju_throw(e);
}

// with function name or description only
PYJU_DLLEXPORT void PYJU_NORETURN pyju_type_error(const char *fname,
                                            PyjuValue_t *expected PYJU_MAYBE_UNROOTED,
                                            PyjuValue_t *got PYJU_MAYBE_UNROOTED)
{
    printf("not impl pyju_type_error\n");
    abort();
}

// showing --------------------------------------------------------------------

PYJU_DLLEXPORT void pyju_flush_cstdio(void) PYJU_NOTSAFEPOINT
{
    fflush(stdout);
    fflush(stderr);
}


// with function name / location description, plus extra context
PYJU_DLLEXPORT void PYJU_NORETURN pyju_type_error_rt(const char *fname, const char *context,
                                               PyjuValue_t *expected PYJU_MAYBE_UNROOTED,
                                               PyjuValue_t *got PYJU_MAYBE_UNROOTED)
{
    printf("pyju_type_error_rt not impl\n");
    abort();
    // PyjuValue_t *ctxt=NULL;
    // PYJU_GC_PUSH3(&ctxt, &expected, &got);
    // ctxt = pyju_pchar_to_string((char*)context, strlen(context));
    // PyjuValue_t *ex = pyju_new_struct(pyju_typeerror_type, pyju_symbol(fname), ctxt, expected, got);
    // pyju_throw(ex);
}

PYJU_DLLEXPORT void PYJU_NORETURN pyju_bounds_error_int(PyjuValue_t *v PYJU_MAYBE_UNROOTED, size_t i)
{
    PyjuValue_t *t = NULL;
    PYJU_GC_PUSH2(&v, &t); // root arguments so the caller doesn't need to
    t = pyju_box_long(i);
    pyju_throw(pyju_new_struct((PyjuDataType_t*)pyju_boundserror_type, v, t));
}

PYJU_DLLEXPORT size_t pyju_static_show(PYJU_STREAM *out, PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    printf("not impl: pyju_static_show\n");
    return 0;
    // return jl_static_show_x(out, v, 0);
}

#ifdef __cplusplus
}
#endif
