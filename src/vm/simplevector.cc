#include <cstddef>
#include <cstdint>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "support/dtypes.h"

PYJU_DLLEXPORT PyjuSvec_t *(pyju_svec)(size_t n, ...)
{
    va_list args;
    if (n == 0) return pyju_emptysvec;
    va_start(args, n);
    PyjuSvec_t *v = pyju_alloc_svec_uninit(n);
    for (size_t i = 0; i < n; i++)
        pyju_svecset(v, i, va_arg(args, PyjuValue_t*));
    va_end(args);
    return v;
}

PyjuSvec_t *(pyju_perm_symsvec)(size_t n, ...)
{
    if (n == 0) return pyju_emptysvec;
    PyjuSvec_t *v = (PyjuSvec_t*)pyju_gc_permobj((n + 1) * sizeof(void*) + PYJU_TV_SIZE, pyju_simplevector_type);
    assert(pyju_typeis(v, pyju_simplevector_type));
    pyju_svec_set_len_unsafe(v, n);
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; i++)
        pyju_svecset(v, i, pyju_symbol(va_arg(args, const char*)));
    va_end(args);
    return v;
}

PYJU_DLLEXPORT PyjuSvec_t *pyju_svec1(void *a)
{
    PyjuTask_t *ct = pyju_current_task;
    PyjuSvec_t *v = (PyjuSvec_t*)pyju_gc_alloc(ct->ptls, sizeof(void*) * 2 + PYJU_TV_SIZE, pyju_simplevector_type);
    pyju_svec_set_len_unsafe(v, 1);
    pyju_svec_data(v)[0] = (PyjuValue_t*)a;
    return v;
}

PYJU_DLLEXPORT PyjuSvec_t *pyju_svec2(void *a, void *b)
{
    PyjuTask_t *ct = pyju_current_task;
    PyjuSvec_t *v = (PyjuSvec_t*)pyju_gc_alloc(ct->ptls, sizeof(void*) * 3 + PYJU_TV_SIZE, pyju_simplevector_type);
    pyju_svec_set_len_unsafe(v, 2);
    pyju_svec_data(v)[0] = (PyjuValue_t*)a;
    pyju_svec_data(v)[1] = (PyjuValue_t*)b;
    return v;
}

PYJU_DLLEXPORT PyjuSvec_t *pyju_alloc_svec_uninit(size_t n)
{
    PyjuTask_t *ct = pyju_current_task;
    if (n == 0) return pyju_emptysvec;
    PyjuSvec_t *sv = (PyjuSvec_t *)pyju_gc_alloc(ct->ptls, (n + 1) * sizeof(void*) + PYJU_TV_SIZE, pyju_simplevector_type);
    pyju_svec_set_len_unsafe(sv, n);
    return sv;
}

PYJU_DLLEXPORT PyjuSvec_t *pyju_alloc_svec(size_t n)
{
    if (n == 0) return pyju_emptysvec;
    PyjuSvec_t *sv = pyju_alloc_svec_uninit(n);
    memset(pyju_assume_aligned(pyju_svec_data(sv), sizeof(void*)), 0, n * sizeof(void*));
    return sv;
}

PYJU_DLLEXPORT PyjuSvec_t *pyju_svec_copy(PyjuSvec_t *a)
{
    size_t n = pyju_svec_len(a);
    PyjuSvec_t *sv = pyju_alloc_svec_uninit(n);
    memmove_refs((void**)pyju_svec_data(sv), (void**)pyju_svec_data(a), n);
    return sv;
}

PYJU_DLLEXPORT PyjuSvec_t *pyju_svec_fill(size_t n, PyjuValue_t *x)
{
    if (n == 0) return pyju_emptysvec;
    PyjuSvec_t *v = pyju_alloc_svec_uninit(n);
    for (size_t i = 0; i < n; i++)
        pyju_svec_data(v)[i] = x;
    return v;
}

PYJU_DLLEXPORT size_t (pyju_svec_len)(PyjuSvec_t *t) PYJU_NOTSAFEPOINT
{
    return pyju_svec_len(t);
}

PYJU_DLLEXPORT int8_t pyju_svec_isassigned(PyjuSvec_t *t PYJU_PROPAGATES_ROOT, ssize_t i) PYJU_NOTSAFEPOINT
{
    return pyju_svecref(t, (size_t)i) != NULL;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_svec_ref(PyjuSvec_t *t PYJU_PROPAGATES_ROOT, ssize_t i)
{
    PyjuValue_t *v = pyju_svecref(t, i);
    if (__unlikely(v == NULL))
        pyju_throw(pyju_undefref_exception);
    return v;
}