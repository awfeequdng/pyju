#include "support/platform.h"
#include "support/hashing.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#if defined(_OS_WINDOWS_)
#include <malloc.h>
#else
#include <unistd.h>
#endif
#include <ctype.h>
#include "pyju_object.h"
#include "pyju_internal.h"
// #include "builtin_proto.h"
// #include "intrinsics.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// egal and object_id ---------------------------------------------------------

static int bits_equal(const void *a, const void *b, int sz) PYJU_NOTSAFEPOINT
{
    switch (sz) {
    case 1:  return *(int8_t*)a == *(int8_t*)b;
        // Let compiler constant folds the following.
    case 2:  return memcmp(a, b, 2) == 0;
    case 4:  return memcmp(a, b, 4) == 0;
    case 8:  return memcmp(a, b, 8) == 0;
    default: return memcmp(a, b, sz) == 0;
    }
}



static uintptr_t bits_hash(const void *b, size_t sz) PYJU_NOTSAFEPOINT
{
    switch (sz) {
    case 1:  return int32hash(*(const int8_t*)b);
    case 2:  return int32hash(pyju_load_unaligned_i16(b));
    case 4:  return int32hash(pyju_load_unaligned_i32(b));
#ifdef _P64
    case 8:  return int64hash(pyju_load_unaligned_i64(b));
#else
    case 8:  return int64to32hash(jl_load_unaligned_i64(b));
#endif
    default:
#ifdef _P64
        return memhash((const char*)b, sz);
#else
        return memhash32((const char*)b, sz);
#endif
    }
}

static uintptr_t NOINLINE hash_svec(PyjuSvec_t *v) PYJU_NOTSAFEPOINT
{
    uintptr_t h = 0;
    size_t i, l = pyju_svec_len(v);
    for (i = 0; i < l; i++) {
        PyjuValue_t *x = pyju_svecref(v, i);
        uintptr_t u = (x == NULL) ? 0 : pyju_object_id(x);
        h = bitmix(h, u);
    }
    return h;
}

static uintptr_t immut_id_(PyjuDataType_t *dt, PyjuValue_t *v, uintptr_t h) PYJU_NOTSAFEPOINT;

typedef struct _varidx {
    PyjuTVar_t *var;
    struct _varidx *prev;
} pyju_varidx_t;

static uintptr_t type_object_id_(PyjuValue_t *v, pyju_varidx_t *env) PYJU_NOTSAFEPOINT
{
    if (v == NULL)
        return 0;
    PyjuDataType_t *tv = (PyjuDataType_t*)pyju_typeof(v);
    if (tv == pyju_tvar_type) {
        pyju_varidx_t *pe = env;
        int i = 0;
        while (pe != NULL) {
            if (pe->var == (PyjuTVar_t*)v)
                return (i<<8) + 42;
            i++;
            pe = pe->prev;
        }
        return inthash((uintptr_t)v);
    }
    if (tv == pyju_uniontype_type) {
        return bitmix(bitmix(pyju_object_id((PyjuValue_t*)tv),
                             type_object_id_(((PyjuUnionType_t*)v)->a, env)),
                      type_object_id_(((PyjuUnionType_t*)v)->b, env));
    }
    if (tv == pyju_unionall_type) {
        PyjuUnionAll_t *u = (PyjuUnionAll_t*)v;
        uintptr_t h = u->var->name->hash;
        h = bitmix(h, type_object_id_(u->var->lb, env));
        h = bitmix(h, type_object_id_(u->var->ub, env));
        pyju_varidx_t e = { u->var, env };
        return bitmix(h, type_object_id_(u->body, &e));
    }
    if (tv == pyju_datatype_type) {
        PyjuDataType_t *dtv = (PyjuDataType_t*)v;
        if (dtv->isconcretetype)
            return dtv->hash;
        uintptr_t h = ~dtv->name->hash;
        size_t i, l = pyju_nparams(v);
        for (i = 0; i < l; i++) {
            h = bitmix(h, type_object_id_(pyju_tparam(v, i), env));
        }
        return h;
    }
    if (tv == pyju_vararg_type) {
        PyjuVararg_t *vm = (PyjuVararg_t*)v;
        PyjuValue_t *t = vm->T ? vm->T : (PyjuValue_t*)pyju_any_type;
        PyjuValue_t *n = vm->N ? vm->N : pyju_nothing;
        return bitmix(type_object_id_(t, env),
            type_object_id_(n, env));
    }
    if (tv == pyju_symbol_type)
        return ((PyjuSym_t*)v)->hash;
    assert(!tv->name->mutabl);
    return immut_id_(tv, v, tv->hash);
}

static uintptr_t immut_id_(PyjuDataType_t *dt, PyjuValue_t *v, uintptr_t h) PYJU_NOTSAFEPOINT
{
    size_t sz = pyju_datatype_size(dt);
    if (sz == 0)
        return ~h;
    size_t f, nf = pyju_datatype_nfields(dt);
    if (nf == 0 || (!dt->layout->haspadding && dt->layout->npointers == 0)) {
        // operate element-wise if there are unused bits inside,
        // otherwise just take the whole data block at once
        // a few select pointers (notably symbol) also have special hash values
        // which may affect the stability of the objectid hash, even though
        // they don't affect egal comparison
        return bits_hash(v, sz) ^ h;
    }
    if (dt == pyju_unionall_type)
        return type_object_id_(v, NULL);
    for (f = 0; f < nf; f++) {
        size_t offs = pyju_field_offset(dt, f);
        char *vo = (char*)v + offs;
        uintptr_t u;
        if (pyju_field_isptr(dt, f)) {
            PyjuValue_t *f = *(PyjuValue_t**)vo;
            u = (f == NULL) ? 0 : pyju_object_id(f);
        }
        else {
            PyjuDataType_t *fieldtype = (PyjuDataType_t*)pyju_field_type_concrete(dt, f);
            if (pyju_is_uniontype(fieldtype)) {
                uint8_t sel = ((uint8_t*)vo)[pyju_field_size(dt, f) - 1];
                fieldtype = (PyjuDataType_t*)pyju_nth_union_component((PyjuValue_t*)fieldtype, sel);
            }
            assert(pyju_is_datatype(fieldtype) && !fieldtype->name->abstract && !fieldtype->name->mutabl);
            int32_t first_ptr = fieldtype->layout->first_ptr;
            if (first_ptr >= 0 && ((PyjuValue_t**)vo)[first_ptr] == NULL) {
                // If the field is a inline immutable that can be can be undef
                // we need to check to check for undef first since undef struct
                // may have fields that are different but should still be treated as equal.
                u = 0;
            }
            else {
                u = immut_id_(fieldtype, (PyjuValue_t*)vo, 0);
            }
        }
        h = bitmix(h, u);
    }
    return h;
}

static uintptr_t NOINLINE pyju_object_id__cold(PyjuDataType_t *dt, PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    if (dt == pyju_simplevector_type)
        return hash_svec((PyjuSvec_t*)v);
    if (dt == pyju_datatype_type) {
        PyjuDataType_t *dtv = (PyjuDataType_t*)v;
        uintptr_t h = ~dtv->name->hash;
        return bitmix(h, hash_svec(dtv->parameters));
    }
    if (dt == pyju_string_type) {
#ifdef _P64
        return memhash_seed(pyju_string_data(v), pyju_string_len(v), 0xedc3b677);
#else
        return memhash32_seed(pyju_string_data(v), pyju_string_len(v), 0xedc3b677);
#endif
    }
    if (dt->name->mutabl)
        return inthash((uintptr_t)v);
    return immut_id_(dt, v, dt->hash);
}

PYJU_DLLEXPORT inline uintptr_t pyju_object_id_(PyjuValue_t *tv, PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    PyjuDataType_t *dt = (PyjuDataType_t*)tv;
    if (dt == pyju_symbol_type)
        return ((PyjuSym_t*)v)->hash;
    if (dt == pyju_typename_type)
        return ((PyjuTypeName_t*)v)->hash;
    if (dt == pyju_datatype_type) {
        PyjuDataType_t *dtv = (PyjuDataType_t*)v;
        if (dtv->isconcretetype)
            return dtv->hash;
    }
    return pyju_object_id__cold(dt, v);
}

PYJU_DLLEXPORT uintptr_t pyju_object_id(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return pyju_object_id_(pyju_typeof(v), v);
}

#ifdef __cplusplus
}
#endif


