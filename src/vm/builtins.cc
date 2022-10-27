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


// The frequently used jl_egal function deserves special attention when it
// comes to performance which is made challenging by the fact that the
// function has to handle quite a few different cases and because it is
// called recursively.  To optimize performance many special cases are
// handle with separate comparisons which can dramatically reduce the run
// time of the function.  The compiler can translate these simple tests
// with little effort, e.g., few registers are used.
//
// The complex cases require more effort and more registers to be translated
// efficiently.  The effected cases include comparing tuples and fields.  If
// the code to perform these operation would be inlined in the jl_egal
// function then the compiler would generate at the or close to the top of
// the function a prologue which saves all the callee-save registers and at
// the end the respective epilogue.  The result is that even the fast cases
// are slowed down.
//
// The solution is to keep the code in jl_egal simple and split out the
// (more) complex cases into their own functions which are marked with
// NOINLINE.
static int NOINLINE compare_svec(PyjuSvec_t *a, PyjuSvec_t *b) PYJU_NOTSAFEPOINT
{
    size_t i, l = pyju_svec_len(a);
    if (l != pyju_svec_len(b))
        return 0;
    for (i = 0; i < l; i++) {
        if (!pyju_egal(pyju_svecref(a, i), pyju_svecref(b, i)))
            return 0;
    }
    return 1;
}

// See comment above for an explanation of NOINLINE.
static int NOINLINE compare_fields(const PyjuValue_t *a, const PyjuValue_t *b, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT
{
    size_t nf = pyju_datatype_nfields(dt);
    // npointers is used at end, but fetched here for locality with nfields.
    int npointers = ((PyjuDataType_t*)dt)->layout->npointers;
    for (size_t f = 0; f < nf; f++) {
        size_t offs = pyju_field_offset(dt, f);
        char *ao = (char*)a + offs;
        char *bo = (char*)b + offs;
        if (pyju_field_isptr(dt, f)) {
            // Save ptr recursion until the end -- only recurse if otherwise equal
            // Note that we also skip comparing the pointers for null here, because
            // null fields are rare so it can save CPU to delay this read too.
            continue;
        }
        else {
            PyjuDataType_t *ft = (PyjuDataType_t*)pyju_field_type_concrete(dt, f);
            if (pyju_is_uniontype(ft)) {
                size_t idx = pyju_field_size(dt, f) - 1;
                uint8_t asel = ((uint8_t*)ao)[idx];
                uint8_t bsel = ((uint8_t*)bo)[idx];
                if (asel != bsel)
                    return 0;
                ft = (PyjuDataType_t*)pyju_nth_union_component((PyjuValue_t*)ft, asel);
            }
            else if (ft->layout->first_ptr >= 0) {
                // If the field is a inline immutable that can be undef
                // we need to check for undef first since undef struct
                // may have fields that are different but should still be treated as equal.
                int32_t idx = ft->layout->first_ptr;
                PyjuValue_t *ptra = ((PyjuValue_t**)ao)[idx];
                PyjuValue_t *ptrb = ((PyjuValue_t**)bo)[idx];
                if ((ptra == NULL) != (ptrb == NULL)) {
                    return 0;
                }
                else if (ptra == NULL) { // implies ptrb == NULL
                    continue; // skip this field (it is #undef)
                }
            }
            if (!ft->layout->haspadding) {
                if (!bits_equal(ao, bo, ft->size))
                    return 0;
            }
            else {
                assert(pyju_datatype_nfields(ft) > 0);
                if (!compare_fields((PyjuValue_t*)ao, (PyjuValue_t*)bo, ft))
                    return 0;
            }
        }
    }
    // If we've gotten here, the objects are bitwise equal, besides their pointer fields.
    // Now, we will recurse into jl_egal for the pointed-to elements, which might be
    // arbitrarily expensive.
    for (size_t p = 0; p < npointers; p++) {
        size_t offs = pyju_ptr_offset(dt, p);
        PyjuValue_t *af = ((PyjuValue_t**)a)[offs];
        PyjuValue_t *bf = ((PyjuValue_t**)b)[offs];
        if (af != bf) {
            if (af == NULL || bf == NULL)
                return 0;
            if (!pyju_egal(af, bf))
                return 0;
        }
    }
    return 1;
}

static int egal_types(const PyjuValue_t *a, const PyjuValue_t *b, PyjuTypeEnv_t *env, int tvar_names) PYJU_NOTSAFEPOINT
{
    if (a == b)
        return 1;
    PyjuDataType_t *dt = (PyjuDataType_t*)pyju_typeof(a);
    if (dt != (PyjuDataType_t*)pyju_typeof(b))
        return 0;
    if (dt == pyju_datatype_type) {
        PyjuDataType_t *dta = (PyjuDataType_t*)a;
        PyjuDataType_t *dtb = (PyjuDataType_t*)b;
        if (dta->name != dtb->name)
            return 0;
        size_t i, l = pyju_nparams(dta);
        if (pyju_nparams(dtb) != l)
            return 0;
        for (i = 0; i < l; i++) {
            if (!egal_types(pyju_tparam(dta, i), pyju_tparam(dtb, i), env, tvar_names))
                return 0;
        }
        return 1;
    }
    if (dt == pyju_tvar_type) {
        PyjuTypeEnv_t *pe = env;
        while (pe != NULL) {
            if (pe->var == (PyjuTVar_t*)a)
                return pe->val == b;
            pe = pe->prev;
        }
        return 0;
    }
    if (dt == pyju_unionall_type) {
        PyjuUnionAll_t *ua = (PyjuUnionAll_t*)a;
        PyjuUnionAll_t *ub = (PyjuUnionAll_t*)b;
        if (tvar_names && ua->var->name != ub->var->name)
            return 0;
        if (!(egal_types(ua->var->lb, ub->var->lb, env, tvar_names) && egal_types(ua->var->ub, ub->var->ub, env, tvar_names)))
            return 0;
        PyjuTypeEnv_t e = { ua->var, (PyjuValue_t*)ub->var, env };
        return egal_types(ua->body, ub->body, &e, tvar_names);
    }
    if (dt == pyju_uniontype_type) {
        return egal_types(((PyjuUnionType_t*)a)->a, ((PyjuUnionType_t*)b)->a, env, tvar_names) &&
            egal_types(((PyjuUnionType_t*)a)->b, ((PyjuUnionType_t*)b)->b, env, tvar_names);
    }
    if (dt == pyju_vararg_type) {
        PyjuVararg_t *vma = (PyjuVararg_t*)a;
        PyjuVararg_t *vmb = (PyjuVararg_t*)b;
        PyjuValue_t *vmaT = vma->T ? vma->T : (PyjuValue_t*)pyju_any_type;
        PyjuValue_t *vmbT = vmb->T ? vmb->T : (PyjuValue_t*)pyju_any_type;
        if (!egal_types(vmaT, vmbT, env, tvar_names))
            return 0;
        if (vma->N && vmb->N)
            return egal_types(vma->N, vmb->N, env, tvar_names);
        return !vma->N && !vmb->N;
    }
    if (dt == pyju_symbol_type)
        return 0;
    assert(!dt->name->mutabl);
    return pyju_egal__bits(a, b, dt);
}

PYJU_DLLEXPORT int pyju_types_egal(PyjuValue_t *a, PyjuValue_t *b)
{
    return egal_types(a, b, NULL, 0);
}

PYJU_DLLEXPORT int (pyju_egal)(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED) PYJU_NOTSAFEPOINT
{
    // warning: a,b may NOT have been gc-rooted by the caller
    return pyju_egal(a, b);
}

PYJU_DLLEXPORT int pyju_egal__unboxed(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT
{
    return pyju_egal__unboxed(a, b, dt);
}

int pyju_egal__special(const PyjuValue_t *a PYJU_MAYBE_UNROOTED,const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT
{
    if (dt == pyju_simplevector_type)
        return compare_svec((PyjuSvec_t*)a, (PyjuSvec_t*)b);
    if (dt == pyju_datatype_type) {
        PyjuDataType_t *dta = (PyjuDataType_t*)a;
        PyjuDataType_t *dtb = (PyjuDataType_t*)b;
        if (dta->name != dtb->name)
            return 0;
        if (dtb->name != pyju_tuple_typename && (dta->isconcretetype || dtb->isconcretetype))
            return 0;
        return compare_svec(dta->parameters, dtb->parameters);
    }
    if (dt == pyju_string_type) {
        size_t l = pyju_string_len(a);
        if (pyju_string_len(b) != l)
            return 0;
        return !memcmp(pyju_string_data(a), pyju_string_data(b), l);
    }
    assert(0 && "unreachable");
    return 0;
}

int pyju_egal__bits(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT
{
    size_t sz = pyju_datatype_size(dt);
    if (sz == 0)
        return 1;
    size_t nf = pyju_datatype_nfields(dt);
    if (nf == 0 || !dt->layout->haspadding)
        return bits_equal(a, b, sz);
    if (dt == pyju_unionall_type)
        return egal_types(a, b, NULL, 1);
    return compare_fields(a, b, dt);
}

// Typevar constructor for internal use
PYJU_DLLEXPORT PyjuTVar_t *pyju_new_typevar(PyjuSym_t *name, PyjuValue_t *lb, PyjuValue_t *ub)
{
    if (lb != pyju_bottom_type && !pyju_is_type(lb) && !pyju_is_typevar(lb))
        pyju_type_error_rt("TypeVar", "lower bound", (PyjuValue_t *)pyju_type_type, lb);
    if (ub != (PyjuValue_t *)pyju_any_type && !pyju_is_type(ub) && !pyju_is_typevar(ub))
        pyju_type_error_rt("TypeVar", "upper bound", (PyjuValue_t *)pyju_type_type, ub);
    PyjuTask_t *ct = pyju_current_task;
    PyjuTVar_t *tv = (PyjuTVar_t *)pyju_gc_alloc(ct->ptls, sizeof(PyjuTVar_t), pyju_tvar_type);
    tv->name = name;
    tv->lb = lb;
    tv->ub = ub;
    return tv;
}


// apply_type -----------------------------------------------------------------

int pyju_valid_type_param(PyjuValue_t *v)
{
    if (pyju_is_tuple(v)) {
        // NOTE: tuples of symbols are not currently bits types, but have been
        // allowed as type parameters. this is a bit ugly.
        PyjuValue_t *tt = pyju_typeof(v);
        size_t i, l = pyju_nparams(tt);
        for(i=0; i < l; i++) {
            PyjuValue_t *pi = pyju_tparam(tt,i);
            if (!(pi == (PyjuValue_t*)pyju_symbol_type || pyju_isbits(pi)))
                return 0;
        }
        return 1;
    }
    if (pyju_is_vararg(v))
        return 0;
    // TODO: maybe more things
    return pyju_is_type(v) || pyju_is_typevar(v) || pyju_is_symbol(v) || pyju_isbits(pyju_typeof(v));
}

#ifdef __cplusplus
}
#endif


