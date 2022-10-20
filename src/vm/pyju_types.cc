#include <cstddef>
#include <stdlib.h>
#include <string.h>

#include "pyju_object.h"
#include "pyju_internal.h"
#include "support/hashing.h"

#ifdef __cplusplus
extern "C" {
#endif

_Atomic(PyjuValue_t*) cmpswap_names PYJU_GLOBALLY_ROOTED;

// compute empirical max-probe for a given size
#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)
#define h2index(hv, sz) (size_t)((hv) & ((sz)-1))

// --- type properties and predicates ---

static int typeenv_has(PyjuTypeEnv_t *env, PyjuTVar_t *v) PYJU_NOTSAFEPOINT
{
    while (env != NULL) {
        if (env->var == v)
            return 1;
        env = env->prev;
    }
    return 0;
}


static int layout_uses_free_typevars(PyjuValue_t *v, PyjuTypeEnv_t *env)
{
    if (pyju_typeis(v, pyju_tvar_type))
        return !typeenv_has(env, (PyjuTVar_t*)v);
    if (pyju_is_uniontype(v))
        return layout_uses_free_typevars(((PyjuUnionType_t*)v)->a, env) ||
               layout_uses_free_typevars(((PyjuUnionType_t*)v)->b, env);
    if (pyju_is_vararg(v)) {
        PyjuVararg_t *vm = (PyjuVararg_t*)v;
        if (vm->T && layout_uses_free_typevars(vm->T, env))
            return 1;
        if (vm->N && layout_uses_free_typevars(vm->N, env))
            return 1;
        return 0;
    }
    if (pyju_is_unionall(v)) {
        PyjuUnionAll_t *ua = (PyjuUnionAll_t*)v;
        PyjuTypeEnv_t newenv = { ua->var, NULL, env };
        return layout_uses_free_typevars(ua->body, &newenv);
    }
    if (pyju_is_datatype(v)) {
        PyjuDataType_t *dt = (PyjuDataType_t*)v;
        if (dt->layout || dt->isconcretetype || !dt->name->mayinlinealloc)
            return 0;
        if (dt->name == pyju_namedtuple_typename)
            return layout_uses_free_typevars(pyju_tparam0(dt), env) || layout_uses_free_typevars(pyju_tparam1(dt), env);
        if (dt->name == pyju_tuple_typename)
            // conservative, since we don't want to inline an abstract tuple,
            // and we currently declare !has_fixed_layout for these, but that
            // means we also won't be able to inline a tuple which is concrete
            // except for the use of free type-vars
            return 1;
        PyjuSvec_t *types = pyju_get_fieldtypes(dt);
        size_t i, l = pyju_svec_len(types);
        for (i = 0; i < l; i++) {
            PyjuValue_t *ft = pyju_svecref(types, i);
            if (layout_uses_free_typevars(ft, env)) {
                // This might be inline-alloc, but we don't know the layout
                return 1;
            }
        }
    }
    return 0;
}

int pyju_has_fixed_layout(PyjuDataType_t *dt)
{
    if (dt->layout || dt->isconcretetype)
        return 1;
    if (dt->name->abstract)
        return 0;
    if (dt->name == pyju_namedtuple_typename)
        return !layout_uses_free_typevars(pyju_tparam0(dt), NULL) && !layout_uses_free_typevars(pyju_tparam1(dt), NULL);
    if (dt->name == pyju_tuple_typename)
        return 0;
    PyjuSvec_t *types = pyju_get_fieldtypes(dt);
    size_t i, l = pyju_svec_len(types);
    for (i = 0; i < l; i++) {
        PyjuValue_t *ft = pyju_svecref(types, i);
        if (layout_uses_free_typevars(ft, NULL)) {
            return 0;
        }
    }
    return 1;
}

// --- type union ---
static int count_union_components(PyjuValue_t **types, size_t n)
{
    size_t i, c=0;
    for(i=0; i < n; i++) {
        PyjuValue_t *e = types[i];
        if (pyju_is_uniontype(e)) {
            PyjuUnionType_t *u = (PyjuUnionType_t*)e;
            c += count_union_components(&u->a, 1);
            c += count_union_components(&u->b, 1);
        }
        else {
            c++;
        }
    }
    return c;
}

int pyju_count_union_components(PyjuValue_t *v)
{
    if (!pyju_is_uniontype(v)) return 1;
    PyjuUnionType_t *u = (PyjuUnionType_t*)v;
    return pyju_count_union_components(u->a) + pyju_count_union_components(u->b);
}

// Return the `*pi`th element of a nested type union, according to a
// standard traversal order. Anything that is not itself a `Union` is
// considered an "element". `*pi` is destroyed in the process.
static PyjuValue_t *nth_union_component(PyjuValue_t *v, int *pi) PYJU_NOTSAFEPOINT
{
    if (!pyju_is_uniontype(v)) {
        if (*pi == 0)
            return v;
        (*pi)--;
        return NULL;
    }
    PyjuUnionType_t *u = (PyjuUnionType_t*)v;
    PyjuValue_t *a = nth_union_component(u->a, pi);
    if (a) return a;
    return nth_union_component(u->b, pi);
}

PyjuValue_t *pyju_nth_union_component(PyjuValue_t *v, int i) PYJU_NOTSAFEPOINT
{
    return nth_union_component(v, &i);
}

// inverse of jl_nth_union_component
int pyju_find_union_component(PyjuValue_t *haystack, PyjuValue_t *needle, unsigned *nth) PYJU_NOTSAFEPOINT
{
    if (pyju_is_uniontype(haystack)) {
        if (pyju_find_union_component(((PyjuUnionType_t*)haystack)->a, needle, nth))
            return 1;
        if (pyju_find_union_component(((PyjuUnionType_t*)haystack)->b, needle, nth))
            return 1;
        return 0;
    }
    if (needle == haystack)
        return 1;
    (*nth)++;
    return 0;
}

static int has_free_typevars(PyjuValue_t *v, PyjuTypeEnv_t *env) PYJU_NOTSAFEPOINT
{
    if (pyju_typeis(v, pyju_tvar_type)) {
        return !typeenv_has(env, (PyjuTVar_t*)v);
    }
    if (pyju_is_uniontype(v))
        return has_free_typevars(((PyjuUnionType_t*)v)->a, env) ||
            has_free_typevars(((PyjuUnionType_t*)v)->b, env);
    if (pyju_is_vararg(v)) {
        PyjuVararg_t *vm = (PyjuVararg_t *)v;
        if (vm->T) {
            if (has_free_typevars(vm->T, env))
                return 1;
            return vm->N && has_free_typevars(vm->N, env);
        }
    }
    if (pyju_is_unionall(v)) {
        PyjuUnionAll_t *ua = (PyjuUnionAll_t*)v;
        PyjuTypeEnv_t newenv = {ua->var, NULL, env};
        return has_free_typevars(ua->var->lb, env) || has_free_typevars(ua->var->ub, env) ||
            has_free_typevars(ua->body, &newenv);
    }
    if (pyju_is_datatype(v)) {
        int expect = ((PyjuDataType_t*)v)->hasfreetypevars;
        if (expect == 0 || env == NULL)
            return expect;
        size_t i;
        for (i = 0; i < pyju_nparams(v); i++) {
            if (has_free_typevars(pyju_tparam(v, i), env)) {
                return 1;
            }
        }
    }
    return 0;
}

PYJU_DLLEXPORT int pyju_has_free_typevars(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return has_free_typevars(v, NULL);
}

PyjuValue_t *pyju_unwrap_unionall(PyjuValue_t *v)
{
    while (pyju_is_unionall(v))
        v = ((PyjuUnionAll_t*)v)->body;
    return v;
}
static unsigned typekey_hash(PyjuTypeName_t *tn, PyjuValue_t **key, size_t n, int nofail) PYJU_NOTSAFEPOINT;
static unsigned typekeyvalue_hash(PyjuTypeName_t *tn, PyjuValue_t *key1, PyjuValue_t **key, size_t n, int leaf) PYJU_NOTSAFEPOINT;

static unsigned type_hash(PyjuValue_t *kj, int *failed) PYJU_NOTSAFEPOINT
{
    PyjuValue_t *uw = pyju_is_unionall(kj) ? pyju_unwrap_unionall(kj) : kj;
    if (pyju_is_datatype(uw)) {
        PyjuDataType_t *dt = (PyjuDataType_t*)uw;
        unsigned hash = dt->hash;
        if (!hash) {
            if (!*failed) {
                *failed = 1;
                return 0;
            }
            hash = typekey_hash(dt->name, pyju_svec_data(dt->parameters), pyju_svec_len(dt->parameters), *failed);
        }
        return hash;
    } else if (pyju_is_typevar(uw)) {
        if (!*failed) {
            *failed = 1;
            return 0;
        }
        // ignore var and lb, since those might get normalized out in equality testing
        return type_hash(((PyjuTVar_t*)uw)->ub, failed);
    } else if (pyju_is_vararg(uw)) {
        if (!*failed) {
            *failed = 1;
            return 0;
        }
        PyjuVararg_t *vm = (PyjuVararg_t *)uw;
        // 0x064eeaab is just a randomly chosen constant
        return bitmix(type_hash(vm->T ? vm->T : (PyjuValue_t*)pyju_any_type, failed), vm->N ? type_hash(vm->N, failed) : 0x064eeaab);
    } else if (pyju_is_uniontype(uw)) {
        if (!*failed) {
            *failed = 1;
            return 0;
        }
        unsigned hasha = type_hash(((PyjuUnionType_t*)uw)->a, failed);
        unsigned hashb = type_hash(((PyjuUnionType_t*)uw)->b, failed);
        // use a associative mixing function, with well-defined overflow
        // since Union is associative
        return hasha + hashb;
    }
    else {
        return pyju_object_id(uw);
    }
}

static unsigned typekey_hash(PyjuTypeName_t *tn, PyjuValue_t **key, size_t n, int nofail) PYJU_NOTSAFEPOINT
{
    if (tn == pyju_type_typename && key[0] == pyju_bottom_type)
        return pyju_typeofbottom_type->hash;
    size_t j;
    unsigned hash = 3;
    int failed = nofail;
    for (j = 0; j < n; j++) {
        hash = bitmix(type_hash(key[j], &failed), hash);
        if (failed && !nofail)
            return 0;
    }
    hash = bitmix(~tn->hash, hash);
    return hash ? hash : 1;
}

void pyju_precompute_memoized_dt(PyjuDataType_t *dt, int cacheable)
{
    int istuple = (dt->name == pyju_tuple_typename);
    dt->hasfreetypevars = 0;
    dt->isconcretetype = !dt->name->abstract;
    dt->isdispatchtuple = istuple;
    size_t i, l = pyju_nparams(dt);
    for (i = 0; i < l; i++) {
        PyjuValue_t *p = pyju_tparam(dt, i);
        if (!dt->hasfreetypevars) {
            dt->hasfreetypevars = pyju_has_free_typevars(p);
            if (dt->hasfreetypevars)
                dt->isconcretetype = 0;
        }
        if (istuple && dt->isconcretetype)
            dt->isconcretetype = (pyju_is_datatype(p) && ((PyjuDataType_t*)p)->isconcretetype) || p == pyju_bottom_type;
        if (dt->isdispatchtuple) {
            dt->isdispatchtuple = pyju_is_datatype(p) &&
                ((!pyju_is_kind(p) && ((PyjuDataType_t*)p)->isconcretetype) ||
                 (p == (PyjuValue_t*)pyju_typeofbottom_type) || // == Type{Union{}}, so needs to be consistent
                 (((PyjuDataType_t*)p)->name == pyju_type_typename && !((PyjuDataType_t*)p)->hasfreetypevars));
        }
        if (istuple && dt->has_concrete_subtype) {
            if (pyju_is_vararg(p))
                p = ((PyjuVararg_t*)p)->T;
            // tuple types like Tuple{:x} cannot have instances
            if (p && !pyju_is_type(p) && !pyju_is_typevar(p))
                dt->has_concrete_subtype = 0;
        }
    }
    if (dt->name == pyju_type_typename) {
        cacheable = 0; // the cache for Type ignores parameter normalization, so it can't be used as a regular hash
        PyjuValue_t *p = pyju_tparam(dt, 0);
        if (!pyju_is_type(p) && !pyju_is_typevar(p)) // Type{v} has no subtypes, if v is not a Type
            dt->has_concrete_subtype = 0;
    }
    dt->hash = typekey_hash(dt->name, pyju_svec_data(dt->parameters), l, cacheable);
    dt->cached_by_hash = cacheable ? (typekey_hash(dt->name, pyju_svec_data(dt->parameters), l, 0) != 0) : (dt->hash != 0);
}

void pyju_init_types(void) PYJU_GC_DISABLED {
    PyjuModule_t *core = nullptr;

    // create base objects
    pyju_datatype_type = pyju_new_uninitialized_datatype();
}

#ifdef __cplusplus
}   // extern "C"
#endif