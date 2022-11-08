#include <cstddef>
#include <cstdint>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "pyju_atomics.h"
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_threads.h"
#include "support/dtypes.h"
#include "support/hashing.h"

#ifdef __cplusplus
extern "C" {
#endif

_Atomic(PyjuValue_t*) cmpswap_names PYJU_GLOBALLY_ROOTED;

// compute empirical max-probe for a given size
#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)
#define h2index(hv, sz) (size_t)((hv) & ((sz)-1))


PYJU_EXTENSION struct _pyju_typestack_t {
    PyjuDataType_t *tt;
    struct _pyju_typestack_t *prev;
};

typedef struct _pyju_typestack_t pyju_typestack_t;

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

// inverse of pyju_nth_union_component
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

static PyjuValue_t *inst_type_w_(PyjuValue_t *t, PyjuTypeEnv_t *env, pyju_typestack_t *stack, int check);
static PyjuSvec_t *inst_ftypes(PyjuSvec_t *p, PyjuTypeEnv_t *env, pyju_typestack_t *stack);

PyjuValue_t *pyju_substitute_var(PyjuValue_t *t, PyjuTVar_t *var, PyjuValue_t *val)
{
    PyjuTypeEnv_t env = { var, val, NULL };
    return inst_type_w_(t, &env, NULL, 1);
}

PyjuValue_t *pyju_unwrap_unionall(PyjuValue_t *v)
{
    while (pyju_is_unionall(v))
        v = ((PyjuUnionAll_t*)v)->body;
    return v;
}


// These `value` functions return the same values as the primary functions,
// but operate on the typeof/Typeof each object in an array
static int typekeyvalue_eq(PyjuDataType_t *tt, PyjuValue_t *key1, PyjuValue_t **key, size_t n, int leaf)
{
    size_t j;
    // TOOD: This shouldn't be necessary
    PYJU_GC_PROMISE_ROOTED(tt);
    size_t tnp = pyju_nparams(tt);
    if (n != tnp)
        return 0;
    if (leaf && tt->name == pyju_type_typename) {
        // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
        // dispatch from changing the type of something.
        // this should work because `Type`s don't have uids, and aren't the
        // direct tags of values so we don't rely on pointer equality.
        PyjuValue_t *kj = key1;
        PyjuValue_t *tj = pyju_tparam0(tt);
        return (kj == tj || (pyju_typeof(tj) == pyju_typeof(kj) && pyju_types_equal(tj, kj)));
    }
    for (j = 0; j < n; j++) {
        PyjuValue_t *kj = j == 0 ? key1 : key[j - 1];
        PyjuValue_t *tj = pyju_svecref(tt->parameters, j);
        if (leaf && pyju_is_type_type(tj)) {
            PyjuValue_t *tp0 = pyju_tparam0(tj);
            if (!(kj == tp0 || (pyju_typeof(tp0) == pyju_typeof(kj) && pyju_types_equal(tp0, kj))))
                return 0;
        }
        else if (pyju_typeof(kj) != tj) {
            return 0;
        }
        else if (leaf && pyju_is_kind(tj)) {
            return 0;
        }
    }
    return 1;
}

static unsigned typekey_hash(PyjuTypeName_t *tn, PyjuValue_t **key, size_t n, int nofail) PYJU_NOTSAFEPOINT;
static unsigned typekeyvalue_hash(PyjuTypeName_t *tn, PyjuValue_t *key1, PyjuValue_t **key, size_t n, int leaf) PYJU_NOTSAFEPOINT;

PYJU_DLLEXPORT int pyju_type_equality_is_identity(PyjuValue_t *t1, PyjuValue_t *t2)
{
    if (t1 == t2)
        return 1;
    if (!pyju_is_datatype(t1) || !pyju_is_datatype(t2))
        return 0;
    PyjuDataType_t *dt1 = (PyjuDataType_t *) t1;
    PyjuDataType_t *dt2 = (PyjuDataType_t *) t2;

    return dt1->cached_by_hash == dt2->cached_by_hash;
}

static int typekey_eq(PyjuDataType_t *tt, PyjuValue_t **key, size_t n)
{
    size_t j;
    // TODO: this shouldn't be necessary
    PYJU_GC_PROMISE_ROOTED(tt);
    size_t tnp = pyju_nparams(tt);
    if (n != tnp)
        return 0;
    if (tt->name == pyju_type_typename) {
        // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
        // dispatch from changing the type of something
        // this should work because `Type`s don't have uids, and aren't the
        // direct tags of values so we don't rely on pointer equality.
        PyjuValue_t *kj = key[0];
        PyjuValue_t *tj = pyju_tparam0(tt);
        return (kj == tj || (pyju_typeof(tj) == pyju_typeof(kj) && pyju_types_equal(tj, kj)));
    }
    for (j = 0; j < n; j++) {
        PyjuValue_t *kj = key[j];
        PyjuValue_t *tj = pyju_svecref(tt->parameters, j);
        if (tj != kj) {
            // require exact same Type{T}. see e.g. issue #22842
            if (pyju_is_type_type(tj) || pyju_is_type_type(kj))
                return 0;
            if ((pyju_is_concrete_type(tj) || pyju_is_concrete_type(kj)) &&
                pyju_type_equality_is_identity(tj, kj))
                return 0;
            if (!pyju_types_equal(tj, kj))
                return 0;
        }
    }
    return 1;
}

static PyjuDataType_t *lookup_type_set(PyjuSvec_t *cache, PyjuValue_t **key, size_t n, uint_t hv)
{
    size_t sz = pyju_svec_len(cache);
    if (sz == 0)
        return NULL;
    size_t maxprobe = max_probe(sz);
    _Atomic(PyjuDataType_t*) *tab = (_Atomic(PyjuDataType_t*)*)pyju_svec_data(cache);
    size_t index = h2index(hv, sz);
    size_t orig = index;
    size_t iter = 0;
    do {
        PyjuDataType_t *val = pyju_atomic_load_relaxed(&tab[index]);
        if (val == NULL)
            return NULL;
        if ((PyjuValue_t*)val != pyju_nothing && val->hash == hv && typekey_eq(val, key, n))
            return val;
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    return NULL;
}

/* returns val if key is in hash, otherwise NULL */
static PyjuDataType_t *lookup_type_setvalue(PyjuSvec_t *cache, PyjuValue_t *key1, PyjuValue_t **key, size_t n, uint_t hv, int leaf)
{
    size_t sz = pyju_svec_len(cache);
    if (sz == 0)
        return NULL;
    size_t maxprobe = max_probe(sz);
    _Atomic(PyjuDataType_t*) *tab = (_Atomic(PyjuDataType_t*)*)pyju_svec_data(cache);
    size_t index = h2index(hv, sz);
    size_t orig = index;
    size_t iter = 0;
    do {
        PyjuDataType_t *val = pyju_atomic_load_relaxed(&tab[index]);
        if (val == NULL)
            return NULL;
        if ((PyjuValue_t*)val != pyju_nothing && val->hash == hv && typekeyvalue_eq(val, key1, key, n, leaf))
            return val;
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    return NULL;
}

// look up a type in a cache by binary or linear search.
// if found, returns the index of the found item. if not found, returns
// ~n, where n is the index where the type should be inserted.
static ssize_t lookup_type_idx_linear(PyjuSvec_t *cache, PyjuValue_t **key, size_t n)
{
    if (n == 0)
        return -1;
    _Atomic(PyjuDataType_t*) *data = (_Atomic(PyjuDataType_t*)*)pyju_svec_data(cache);
    size_t cl = pyju_svec_len(cache);
    ssize_t i;
    for (i = 0; i < cl; i++) {
        PyjuDataType_t *tt = pyju_atomic_load_relaxed(&data[i]);
        if (tt == NULL)
            return ~i;
        if (typekey_eq(tt, key, n))
            return i;
    }
    return ~cl;
}

static ssize_t lookup_type_idx_linearvalue(PyjuSvec_t *cache, PyjuValue_t *key1, PyjuValue_t **key, size_t n)
{
    if (n == 0)
        return -1;
    _Atomic(PyjuDataType_t*) *data = (_Atomic(PyjuDataType_t*)*)pyju_svec_data(cache);
    size_t cl = pyju_svec_len(cache);
    ssize_t i;
    for (i = 0; i < cl; i++) {
        PyjuDataType_t *tt = pyju_atomic_load_relaxed(&data[i]);
        if (tt == NULL)
            return ~i;
        if (typekeyvalue_eq(tt, key1, key, n, 1))
            return i;
    }
    return ~cl;
}

static PyjuValue_t *lookup_type(PyjuTypeName_t *tn PYJU_PROPAGATES_ROOT, PyjuValue_t **key, size_t n)
{
    PYJU_TIMING(TYPE_CACHE_LOOKUP);
    unsigned hv = typekey_hash(tn, key, n, 0);
    if (hv) {
        PyjuSvec_t *cache = pyju_atomic_load_relaxed(&tn->cache);
        return (PyjuValue_t*)lookup_type_set(cache, key, n, hv);
    }
    else {
        PyjuSvec_t *linearcache = pyju_atomic_load_relaxed(&tn->linearcache);
        ssize_t idx = lookup_type_idx_linear(linearcache, key, n);
        return (idx < 0) ? NULL : pyju_svecref(linearcache, idx);
    }
}

static PyjuValue_t *lookup_typevalue(PyjuTypeName_t *tn, PyjuValue_t *key1, PyjuValue_t **key, size_t n, int leaf)
{
    PYJU_TIMING(TYPE_CACHE_LOOKUP);
    unsigned hv = typekeyvalue_hash(tn, key1, key, n, leaf);
    if (hv) {
        PyjuSvec_t *cache = pyju_atomic_load_relaxed(&tn->cache);
        return (PyjuValue_t*)lookup_type_setvalue(cache, key1, key, n, hv, leaf);
    }
    else {
        assert(leaf);
        PyjuSvec_t *linearcache = pyju_atomic_load_relaxed(&tn->linearcache);
        ssize_t idx = lookup_type_idx_linearvalue(linearcache, key1, key, n);
        return (idx < 0) ? NULL : pyju_svecref(linearcache, idx);
    }
}

static PyjuValue_t *lookup_type_stack(pyju_typestack_t *stack, PyjuDataType_t *tt, size_t ntp,
                                     PyjuValue_t **iparams)
{
    // if an identical instantiation is already in process somewhere up the
    // stack, return it. this computes a fixed point for recursive types.
    PyjuTypeName_t *tn = tt->name;
    while (stack != NULL) {
        PYJU_GC_PROMISE_ROOTED(stack->tt);
        if (stack->tt->name == tn &&
            ntp == pyju_svec_len(stack->tt->parameters) &&
            typekey_eq(stack->tt, iparams, ntp)) {
            return (PyjuValue_t*)stack->tt;
        }
        stack = stack->prev;
    }
    return NULL;
}

static int cache_insert_type_set_(PyjuSvec_t *a, PyjuDataType_t *val, uint_t hv, int atomic)
{
    _Atomic(PyjuValue_t*) *tab = (_Atomic(PyjuValue_t*)*)pyju_svec_data(a);
    size_t sz = pyju_svec_len(a);
    if (sz <= 1)
        return 0;
    size_t orig, index, iter;
    iter = 0;
    index = h2index(hv, sz);
    orig = index;
    size_t maxprobe = max_probe(sz);
    do {
        PyjuValue_t *tab_i = pyju_atomic_load_relaxed(&tab[index]);
        if (tab_i == NULL || tab_i == pyju_nothing) {
            if (atomic)
                pyju_atomic_store_release(&tab[index], (PyjuValue_t*)val);
            else
                pyju_atomic_store_relaxed(&tab[index], (PyjuValue_t*)val);
            pyju_gc_wb(a, val);
            return 1;
        }
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);

    return 0;
}

static PyjuSvec_t *cache_rehash_set(PyjuSvec_t *a, size_t newsz);

static void cache_insert_type_set(PyjuDataType_t *val, uint_t hv)
{
    PyjuSvec_t *a = pyju_atomic_load_relaxed(&val->name->cache);
    while (1) {
        PYJU_GC_PROMISE_ROOTED(a);
        if (cache_insert_type_set_(a, val, hv, 1))
            return;

        // table full
        // rehash to grow and retry the sert
        // it's important to grow the table really fast; otherwise we waste
        // lots of time rehashing all the keys over and over
        size_t newsz;
        size_t sz = pyju_svec_len(a);
        if (sz < HT_N_INLINE)
            newsz = HT_N_INLINE;
        else if (sz >= (1 << 19) || (sz <= (1 << 8)))
            newsz = sz << 1;
        else
            newsz = sz << 2;
        a = cache_rehash_set(a, newsz);
        pyju_atomic_store_release(&val->name->cache, a);
        pyju_gc_wb(val->name, a);
    }
}

static PyjuSvec_t *cache_rehash_set(PyjuSvec_t *a, size_t newsz)
{
    PyjuValue_t **ol = pyju_svec_data(a);
    size_t sz = pyju_svec_len(a);
    while (1) {
        size_t i;
        PyjuSvec_t *newa = pyju_alloc_svec(newsz);
        PYJU_GC_PUSH1(&newa);
        for (i = 0; i < sz; i++) {
            PyjuValue_t *val = ol[i];
            if (val != NULL && val != pyju_nothing) {
                uint_t hv = ((PyjuDataType_t*)val)->hash;
                if (!cache_insert_type_set_(newa, (PyjuDataType_t *)val, hv, 0))
                    break;
            }
        }
        PYJU_GC_POP();
        if (i == sz)
            return newa;
        newsz << 1;
    }
}

static void cache_insert_type_linear(PyjuDataType_t *type, ssize_t insert_at)
{
    PyjuSvec_t *cache = pyju_atomic_load_relaxed(&type->name->linearcache);
    assert(pyju_is_svec(cache));
    size_t n = pyju_svec_len(cache);
    if (n == 0 || pyju_svecref(cache, n - 1) != NULL) {
        PyjuSvec_t *nc = pyju_alloc_svec(n < 8 ? 8 : (n*3)>>1);
        memcpy(pyju_svec_data(nc), pyju_svec_data(cache), sizeof(void*) * n);
        pyju_atomic_store_release(&type->name->linearcache, nc);
        pyju_gc_wb(type->name, nc);
        cache = nc;
        n = pyju_svec_len(nc);
    }
    assert(pyju_svecref(cache, insert_at) == NULL);
    pyju_svecset(cache, insert_at, (PyjuValue_t*)type); // todo: make this an atomic-store
}

// #ifndef NDEBUG
static int is_cacheable(PyjuDataType_t *type)
{
    // ensure cache only contains types whose behavior will not depend on the
    // identities of contained TypeVars
    return !pyju_has_free_typevars((PyjuValue_t*)type);
}
// #endif


void pyju_cache_type_(PyjuDataType_t *type)
{
    PYJU_TIMING(TYPE_CACHE_INSERT);
    assert(is_cacheable(type));
    PyjuValue_t **key = pyju_svec_data(type->parameters);
    int n = pyju_svec_len(type->parameters);
    unsigned hv = typekey_hash(type->name, key, n, 0);
    if (hv) {
        assert(hv == type->hash);
        cache_insert_type_set(type, hv);
    }
    else {
        ssize_t idx = lookup_type_idx_linear(pyju_atomic_load_relaxed(&type->name->linearcache), key, n);
        assert(idx < 0);
        cache_insert_type_linear(type, ~idx);
    }
}

PyjuDataType_t *pyju_lookup_cache_type_(PyjuDataType_t *type)
{
    assert(is_cacheable(type));
    PyjuValue_t **key = pyju_svec_data(type->parameters);
    int n = pyju_svec_len(type->parameters);
    return (PyjuDataType_t*)lookup_type(type->name, key, n);
}

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


PyjuVararg_t *pyju_wrap_vararg(PyjuValue_t *t, PyjuValue_t *n)
{
    if (n) {
        if (pyju_is_typevar(n)) {
            // TODO: this is disabled due to #39698; it is also inconsistent
            // with other similar checks, where we usually only check substituted
            // values and not the bounds of variables.
            /*
            pyju_tvar_t *N = (pyju_tvar_t*)n;
            if (!(N->lb == pyju_bottom_type && N->ub == (PyjuValue_t*)pyju_any_type))
                pyju_error("TypeVar in Vararg length must have bounds Union{} and Any");
            */
        }
        else if (!pyju_is_long(n)) {
            pyju_type_error_rt("Vararg", "count", (PyjuValue_t*)pyju_long_type, n);
        }
        else if (pyju_unbox_long(n) < 0) {
            pyju_errorf("Vararg length is negative: %zd", pyju_unbox_long(n));
        }
    }
    if (t) {
        if (!pyju_valid_type_param(t)) {
            pyju_type_error_rt("Vararg", "type", (PyjuValue_t*)pyju_type_type, t);
        }
    }
    PyjuTask_t *ct = pyju_current_task;
    PyjuVararg_t *vm = (PyjuVararg_t *)pyju_gc_alloc(ct->ptls, sizeof(PyjuVararg_t), pyju_vararg_type);
    vm->T = t;
    vm->N = n;
    return vm;
}

static void flatten_type_union(PyjuValue_t **types, size_t n, PyjuValue_t **out, size_t *idx) PYJU_NOTSAFEPOINT
{
    size_t i;
    for(i=0; i < n; i++) {
        PyjuValue_t *e = types[i];
        if (pyju_is_uniontype(e)) {
            PyjuUnionType_t *u = (PyjuUnionType_t*)e;
            flatten_type_union(&u->a, 1, out, idx);
            flatten_type_union(&u->b, 1, out, idx);
        }
        else {
            out[*idx] = e;
            (*idx)++;
        }
    }
}

STATIC_INLINE const char *datatype_module_name(PyjuValue_t *t) PYJU_NOTSAFEPOINT
{
    if (((PyjuDataType_t*)t)->name->module == NULL)
        return NULL;
    return pyju_symbol_name(((PyjuDataType_t*)t)->name->module->name);
}

STATIC_INLINE const char *str_(const char *s) PYJU_NOTSAFEPOINT
{
    return s == NULL ? "" : s;
}

STATIC_INLINE int cmp_(int a, int b) PYJU_NOTSAFEPOINT
{
    return a < b ? -1 : a > b;
}

// a/b are PyjuDataType_t* & not NULL
static int datatype_name_cmp(PyjuValue_t *a, PyjuValue_t *b) PYJU_NOTSAFEPOINT
{
    if (!pyju_is_datatype(a))
        return pyju_is_datatype(b) ? 1 : 0;
    if (!pyju_is_datatype(b))
        return -1;
    int cmp = strcmp(str_(datatype_module_name(a)), str_(datatype_module_name(b)));
    if (cmp != 0)
        return cmp;
    cmp = strcmp(str_(pyju_typename_str(a)), str_(pyju_typename_str(b)));
    if (cmp != 0)
        return cmp;
    cmp = cmp_(pyju_nparams(a), pyju_nparams(b));
    if (cmp != 0)
        return cmp;
    // compare up to 3 type parameters
    for (int i = 0; i < 3 && i < pyju_nparams(a); i++) {
        PyjuValue_t *ap = pyju_tparam(a, i);
        PyjuValue_t *bp = pyju_tparam(b, i);
        if (ap == bp)
            continue;
        else if (pyju_is_datatype(ap) && pyju_is_datatype(bp)) {
            cmp = datatype_name_cmp(ap, bp);
            if (cmp != 0)
                return cmp;
        } else if (pyju_is_unionall(ap) && pyju_is_unionall(bp)) {
            cmp = datatype_name_cmp(pyju_unwrap_unionall(ap), pyju_unwrap_unionall(bp));
            if (cmp != 0)
                return cmp;
        } else {
            // give up
            cmp = 0;
        }
    }
    return cmp;
}

static PyjuTVar_t *tvar(const char *name)
{
    return pyju_new_typevar(pyju_symbol(name), (PyjuValue_t*)pyju_bottom_type,
                          (PyjuValue_t*)pyju_any_type);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_instantiate_unionall(PyjuUnionAll_t *u, PyjuValue_t *p)
{
    PyjuTypeEnv_t env = { u->var, p, NULL };
    return inst_type_w_(u->body, &env, NULL, 1);
}

// sort singletons first, then DataTypes, then UnionAlls,
// ties broken alphabetically including module name & type parameters
static int union_sort_cmp(PyjuValue_t *a, PyjuValue_t *b) PYJU_NOTSAFEPOINT
{
    if (a == NULL)
        return b == NULL ? 0 : 1;
    if (b == NULL)
        return -1;
    if (pyju_is_datatype(a)) {
        if (!pyju_is_datatype(b))
            return -1;
        if (pyju_is_datatype_singleton((PyjuDataType_t*)a)) {
            if (pyju_is_datatype_singleton((PyjuDataType_t*)b))
                return datatype_name_cmp(a, b);
            return -1;
        }
        else if (pyju_is_datatype_singleton((PyjuDataType_t*)b)) {
            return 1;
        }
        else if (pyju_isbits(a)) {
            if (pyju_isbits(b))
                return datatype_name_cmp(a, b);
            return -1;
        }
        else if (pyju_isbits(b)) {
            return 1;
        }
        else {
            return datatype_name_cmp(a, b);
        }
    }
    else {
        if (pyju_is_datatype(b))
            return 1;
        return datatype_name_cmp(pyju_unwrap_unionall(a), pyju_unwrap_unionall(b));
    }
}

static void isort_union(PyjuValue_t **a, size_t len) PYJU_NOTSAFEPOINT
{
    size_t i, j;
    for (i = 1; i < len; i++) {
        PyjuValue_t *x = a[i];
        for (j = i; j > 0; j--) {
            PyjuValue_t *y = a[j - 1];
            if (!(union_sort_cmp(x, y) < 0))
                break;
            a[j] = y;
        }
        a[j] = x;
    }
}

PYJU_DLLEXPORT PyjuValue_t *pyju_type_union(PyjuValue_t **ts, size_t n)
{
    if (n == 0)
        return (PyjuValue_t*)pyju_bottom_type;
    size_t i;
    for (i = 0;  i < n; i++) {
        PyjuValue_t *pi = ts[i];
        if (!(pyju_is_type(pi) || pyju_is_typevar(pi)))
            pyju_type_error("Union", (PyjuValue_t*)pyju_type_type, pi);
    }
    if (n == 1)
        return ts[0];

    size_t nt = count_union_components(ts, n);
    PyjuValue_t **temp;
    PYJU_GC_PUSHARGS(temp, nt + 1);
    size_t count = 0;
    flatten_type_union(ts, n, temp, &count);
    assert(count == nt);
    size_t j;
    for (i = 0; i < nt; i++) {
        int has_free = temp[i] != NULL && pyju_has_free_typevars(temp[i]);
        for (j = 0; j < nt; j++) {
            if (j != i && temp[i] && temp[j]) {
                if (temp[i] == pyju_bottom_type ||
                    temp[j] == (PyjuValue_t*)pyju_any_type ||
                    pyju_egal(temp[i], temp[j]) ||
                    (!has_free && !pyju_has_free_typevars(temp[j]) &&
                    pyju_subtype(temp[i], temp[j]))) {
                    temp[i] = NULL;
                }
            }
        }
    }
    isort_union(temp, nt);
    PyjuValue_t **ptu = &temp[nt];
    *ptu = pyju_bottom_type;
    int k;
    for (k = (int)nt - 1; k >= 0; --k) {
        if (temp[k] != NULL) {
            if (*ptu == pyju_bottom_type)
                *ptu = temp[k];
            else
                *ptu = pyju_new_struct(pyju_uniontype_type, temp[k], *ptu);
        }
    }
    assert(*ptu != NULL);
    PyjuValue_t *tu = *ptu;
    PYJU_GC_POP();
    return tu;
}

static PyjuValue_t *_pyju_instantiate_type_in_env(PyjuValue_t *ty, PyjuUnionAll_t *env, PyjuValue_t **vals, PyjuTypeEnv_t *prev, pyju_typestack_t *stack);


static int within_typevar(PyjuValue_t *t, PyjuValue_t *vlb, PyjuValue_t *vub)
{
    PyjuValue_t *lb = t, *ub = t;
    if (pyju_is_typevar(t) || pyju_has_free_typevars(t)) {
        // TODO: automatically restrict typevars in method definitions based on
        // types they are used in.
        return 1;
        //lb = ((pyju_tvar_t*)t)->lb;
        //ub = ((pyju_tvar_t*)t)->ub;
    }
    else if (!pyju_is_type(t)) {
        return vlb == pyju_bottom_type && vub == (PyjuValue_t*)pyju_any_type;
    }
    return ((pyju_has_free_typevars(vlb) || pyju_subtype(vlb, lb)) &&
            (pyju_has_free_typevars(vub) || pyju_subtype(ub, vub)));
}

static void check_datatype_parameters(PyjuTypeName_t *tn, PyjuValue_t **params, size_t np)
{
    DEBUG_FUNC
    PyjuValue_t *wrapper = tn->wrapper;
    PyjuValue_t **bounds;
    PYJU_GC_PUSHARGS(bounds, np*2);
    int i = 0;
    while (pyju_is_unionall(wrapper)) {
        PyjuTVar_t *tv = ((PyjuUnionAll_t*)wrapper)->var;
        bounds[i++] = tv->lb;
        bounds[i++] = tv->ub;
        wrapper = ((PyjuUnionAll_t*)wrapper)->body;
    }
    assert(i == np*2);
    wrapper = tn->wrapper;
    for (i = 0; i < np; i++) {
        assert(pyju_is_unionall(wrapper));
        PyjuTVar_t *tv = ((PyjuUnionAll_t*)wrapper)->var;
        if (!within_typevar(params[i], bounds[2*i], bounds[2*i+1])) {
            if (tv->lb != bounds[2*i] || tv->ub != bounds[2*i+1])
                // pass a new version of `tv` containing the instantiated bounds
                tv = pyju_new_typevar(tv->name, bounds[2*i], bounds[2*i+1]);
            PYJU_GC_PUSH1(&tv);
            pyju_type_error_rt(pyju_symbol_name(tn->name), pyju_symbol_name(tv->name), (PyjuValue_t*)tv, params[i]);
        }
        int j;
        for (j = 2*i + 2; j < 2*np; j++) {
            PyjuValue_t *bj = bounds[j];
            if (bj != (PyjuValue_t*)pyju_any_type && bj != pyju_bottom_type)
                bounds[j] = pyju_substitute_var(bj, tv, params[i]);
        }
        wrapper = ((PyjuUnionAll_t*)wrapper)->body;
    }
    PYJU_GC_POP();
}

static PyjuValue_t *extract_wrapper(PyjuValue_t *t PYJU_PROPAGATES_ROOT) PYJU_GLOBALLY_ROOTED
{
    t = pyju_unwrap_unionall(t);
    if (pyju_is_datatype(t))
        return ((PyjuDataType_t*)t)->name->wrapper;
    if (pyju_is_uniontype(t)) {
        PyjuValue_t *n1 = extract_wrapper(((PyjuUnionType_t*)t)->a);
        if (n1 != NULL) return n1;
        return extract_wrapper(((PyjuUnionType_t*)t)->b);
    }
    if (pyju_is_typevar(t))
        return extract_wrapper(((PyjuTVar_t*)t)->ub);
    return NULL;
}

int _may_substitute_ub(PyjuValue_t *v, PyjuTVar_t *var, int inside_inv, int *cov_count) PYJU_NOTSAFEPOINT
{
    if (v == (PyjuValue_t*)var) {
        if (inside_inv) {
            return 0;
        }
        else {
            (*cov_count)++;
            return *cov_count <= 1 || pyju_is_concrete_type(var->ub);
        }
    }
    else if (pyju_is_uniontype(v)) {
        return _may_substitute_ub(((PyjuUnionType_t*)v)->a, var, inside_inv, cov_count) &&
            _may_substitute_ub(((PyjuUnionType_t*)v)->b, var, inside_inv, cov_count);
    }
    else if (pyju_is_unionall(v)) {
        PyjuUnionAll_t *ua = (PyjuUnionAll_t*)v;
        if (ua->var == var)
            return 1;
        return _may_substitute_ub(ua->var->lb, var, inside_inv, cov_count) &&
            _may_substitute_ub(ua->var->ub, var, inside_inv, cov_count) &&
            _may_substitute_ub(ua->body, var, inside_inv, cov_count);
    }
    else if (pyju_is_datatype(v)) {
        int invar = inside_inv || !pyju_is_tuple_type(v);
        for (size_t i = 0; i < pyju_nparams(v); i++) {
            if (!_may_substitute_ub(pyju_tparam(v,i), var, invar, cov_count))
                return 0;
        }
    }
    else if (pyju_is_vararg(v)) {
        PyjuVararg_t *va = (PyjuVararg_t*)v;
        int old_count = *cov_count;
        if (va->T && !_may_substitute_ub(va->T, var, inside_inv, cov_count))
            return 0;
        if (*cov_count > old_count && !pyju_is_concrete_type(var->ub))
            return 0;
        if (va->N && !_may_substitute_ub(va->N, var, 1, cov_count))
            return 0;
    }
    return 1;
}

// Check whether `var` may be replaced with its upper bound `ub` in `v where var<:ub`
// Conditions:
//  * `var` does not appear in invariant position
//  * `var` appears at most once (in covariant position) and not in a `Vararg`
//    unless the upper bound is concrete (diagonal rule)
int may_substitute_ub(PyjuValue_t *v, PyjuTVar_t *var) PYJU_NOTSAFEPOINT
{
    int cov_count = 0;
    return _may_substitute_ub(v, var, 0, &cov_count);
}

PyjuValue_t *normalize_unionalls(PyjuValue_t *t)
{
    PYJU_GC_PUSH1(&t);
    if (pyju_is_uniontype(t)) {
        PyjuUnionType_t *u = (PyjuUnionType_t*)t;
        PyjuValue_t *a = NULL;
        PyjuValue_t *b = NULL;
        PYJU_GC_PUSH2(&a, &b);
        a = normalize_unionalls(u->a);
        b = normalize_unionalls(u->b);
        if (a != u->a || b != u->b) {
            t = pyju_new_struct(pyju_uniontype_type, a, b);
        }
        PYJU_GC_POP();
    }
    else if (pyju_is_unionall(t)) {
        PyjuUnionAll_t *u = (PyjuUnionAll_t*)t;
        PyjuValue_t *body = normalize_unionalls(u->body);
        if (body != u->body) {
            PYJU_GC_PUSH1(&body);
            t = pyju_new_struct(pyju_unionall_type, u->var, body);
            PYJU_GC_POP();
            u = (PyjuUnionAll_t*)t;
        }

        if (u->var->lb == u->var->ub || may_substitute_ub(body, u->var)) {
            PYJU_TRY {
                t = pyju_instantiate_unionall(u, u->var->ub);
            }
            PYJU_CATCH {
                // just skip normalization
                // (may happen for bounds inconsistent with the wrapper's bounds)
            }
        }
    }
    PYJU_GC_POP();
    return t;
}

static PyjuValue_t *inst_datatype_inner(PyjuDataType_t *dt, PyjuSvec_t *p, PyjuValue_t **iparams, size_t ntp,
                                       pyju_typestack_t *stack, PyjuTypeEnv_t *env)
{
    DEBUG_FUNC
    pyju_typestack_t top;
    PyjuTypeName_t *tn = dt->name;
    int istuple = (tn == pyju_tuple_typename);
    int isnamedtuple = (tn == pyju_namedtuple_typename);
    if (dt->name != pyju_type_typename) {
        size_t i;
        for (i = 0; i < ntp; i++)
            iparams[i] = normalize_unionalls(iparams[i]);
    }
    DEBUG_FUNC

    // check type cache, if applicable
    int cacheable = 1;
    if (istuple) {
        size_t i;
        for (i = 0; cacheable && i < ntp; i++)
            if (!pyju_is_concrete_type(iparams[i]) && iparams[i] != pyju_bottom_type)
                cacheable = 0;
    }
    else {
        size_t i;
        for (i = 0; cacheable && i < ntp; i++)
            if (pyju_has_free_typevars(iparams[i]))
                cacheable = 0;
    }
    DEBUG_FUNC
    if (cacheable) {
        DEBUG_FUNC
        size_t i;
        for (i = 0; i < ntp; i++) {
        DEBUG_FUNC
            PyjuValue_t *pi = iparams[i];
            if (pi == pyju_bottom_type)
                continue;
            if (pyju_is_datatype(pi))
                continue;
        DEBUG_FUNC
            if (pyju_is_vararg(pi)) {
        DEBUG_FUNC
                pi = pyju_unwrap_vararg(pi);
                if (pyju_has_free_typevars(pi))
                    continue;
            }
        DEBUG_FUNC
            // normalize types equal to wrappers (prepare for wrapper_id)
            PyjuValue_t *tw = extract_wrapper(pi);
        DEBUG_FUNC
            if (tw && tw != pi && (tn != pyju_type_typename || pyju_typeof(pi) == pyju_typeof(tw)) &&
                    pyju_types_equal(pi, tw)) {
        DEBUG_FUNC
                // This would require some special handling, but is never used at
                // the moment.
                assert(!pyju_is_vararg(iparams[i]));
                iparams[i] = tw;
        DEBUG_FUNC
                if (p) pyju_gc_wb(p, tw);
            }
        }
        DEBUG_FUNC
        PyjuValue_t *lkup = (PyjuValue_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL)
            return lkup;
    }
        DEBUG_FUNC
    PyjuValue_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
    if (stack_lkup)
        return stack_lkup;

        DEBUG_FUNC
    if (!istuple) {
        DEBUG_FUNC
        // check parameters against bounds in type definition
        check_datatype_parameters(tn, iparams, ntp);
    }
    else if (ntp == 0 && pyju_emptytuple_type != NULL) {
        // empty tuple type case
        return (PyjuValue_t*)pyju_emptytuple_type;
    }

    PyjuDataType_t *ndt = NULL;
    PyjuValue_t *last = iparams[ntp - 1];
    PYJU_GC_PUSH3(&p, &ndt, &last);

    if (istuple && ntp > 0 && pyju_is_vararg(last)) {
        // normalize Tuple{..., Vararg{Int, 3}} to Tuple{..., Int, Int, Int}
        PyjuValue_t *va = pyju_unwrap_unionall(last);
        PyjuValue_t *va0 = pyju_unwrap_vararg(va), *va1 = pyju_unwrap_vararg_num(va);
        // return same `Tuple` object for types equal to it
        if (ntp == 1 && va0 == (PyjuValue_t*)pyju_any_type && !va1) {
            PYJU_GC_POP();
            return (PyjuValue_t*)pyju_anytuple_type;
        }
        if (va1 && pyju_is_long(va1)) {
            ssize_t nt = pyju_unbox_long(va1);
            assert(nt >= 0);
            if (nt == 0 || !pyju_has_free_typevars(va0)) {
                if (ntp == 1) {
                    PYJU_GC_POP();
                    return pyju_tupletype_fill(nt, va0);
                }
                size_t i, l;
                p = pyju_alloc_svec(ntp - 1 + nt);
                for (i = 0, l = ntp - 1; i < l; i++)
                    pyju_svecset(p, i, iparams[i]);
                l = ntp - 1 + nt;
                for (; i < l; i++)
                    pyju_svecset(p, i, va0);
                PyjuValue_t *ndt = (PyjuValue_t*)pyju_apply_tuple_type(p);
                PYJU_GC_POP();
                return ndt;
            }
        }
    }

    // move array of instantiated parameters to heap; we need to keep it
    if (p == NULL) {
        p = pyju_alloc_svec_uninit(ntp);
        for (size_t i = 0; i < ntp; i++)
            pyju_svecset(p, i, iparams[i]);
    }

    // acquire the write lock now that we know we need a new object
    // since we're going to immediately leak it globally via the instantiation stack
    if (cacheable) {
        PYJU_LOCK(&typecache_lock); // Might GC
        PyjuValue_t *lkup = (PyjuValue_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL) {
            PYJU_UNLOCK(&typecache_lock); // Might GC
            PYJU_GC_POP();
            return lkup;
        }
    }

    // create and initialize new type
    ndt = pyju_new_uninitialized_datatype();
    // associate these parameters with the new type on
    // the stack, in case one of its field types references it.
    top.tt = (PyjuDataType_t*)ndt;
    top.prev = stack;
    stack = &top;
    ndt->name = tn;
    pyju_gc_wb(ndt, ndt->name);
    ndt->super = NULL;
    ndt->parameters = p;
    pyju_gc_wb(ndt, ndt->parameters);
    ndt->types = NULL; // to be filled in below
    if (istuple) {
        ndt->types = p; // TODO: this may need to filter out certain types
    }
    else if (isnamedtuple) {
        PyjuValue_t *names_tup = pyju_svecref(p, 0);
        PyjuValue_t *values_tt = pyju_svecref(p, 1);
        if (!pyju_has_free_typevars(names_tup) && !pyju_has_free_typevars(values_tt)) {
            if (!pyju_is_tuple(names_tup))
                pyju_type_error_rt("NamedTuple", "names", (PyjuValue_t*)pyju_anytuple_type, names_tup);
            size_t nf = pyju_nfields(names_tup);
            for (size_t i = 0; i < nf; i++) {
                PyjuValue_t *ni = pyju_fieldref(names_tup, i);
                if (!pyju_is_symbol(ni))
                    pyju_type_error_rt("NamedTuple", "name", (PyjuValue_t*)pyju_symbol_type, ni);
                for (size_t j = 0; j < i; j++) {
                    if (ni == pyju_fieldref_noalloc(names_tup, j))
                        pyju_errorf("duplicate field name in NamedTuple: \"%s\" is not unique", pyju_symbol_name((PyjuSym_t*)ni));
                }
            }
            if (!pyju_is_datatype(values_tt))
                pyju_error("NamedTuple field type must be a tuple type");
            if (pyju_is_va_tuple((PyjuDataType_t*)values_tt) || pyju_nparams(values_tt) != nf)
                pyju_error("NamedTuple names and field types must have matching lengths");
            ndt->types = ((PyjuDataType_t*)values_tt)->parameters;
            pyju_gc_wb(ndt, ndt->types);
        }
        else {
            ndt->types = pyju_emptysvec; // XXX: this is essentially always false
        }
    }

    PyjuDataType_t *primarydt = ((PyjuDataType_t*)pyju_unwrap_unionall(tn->wrapper));
    pyju_precompute_memoized_dt(ndt, cacheable);
    ndt->size = 0;
    if (primarydt->layout)
        pyju_compute_field_offsets(ndt);

    if (istuple || isnamedtuple) {
        ndt->super = pyju_any_type;
    }
    else if (dt->super) {
        ndt->super = (PyjuDataType_t*)inst_type_w_((PyjuValue_t*)dt->super, env, stack, 1);
        pyju_gc_wb(ndt, ndt->super);
    }
    PyjuSvec_t *ftypes = dt->types;
    if (ftypes == NULL)
        ftypes = primarydt->types;
    if (ftypes == NULL || dt->super == NULL) {
        // in the process of creating this type definition:
        // need to instantiate the super and types fields later
        if (tn->partial == NULL) {
            tn->partial = pyju_alloc_vec_any(0);
            pyju_gc_wb(tn, tn->partial);
        }
        pyju_array_ptr_1d_push(tn->partial, (PyjuValue_t*)ndt);
    }
    else if (!isnamedtuple && !istuple) {
        assert(ftypes != pyju_emptysvec || pyju_field_names(ndt) == pyju_emptysvec);
        assert(ftypes == pyju_emptysvec || !ndt->name->abstract);
        if (ftypes == pyju_emptysvec) {
            ndt->types = ftypes;
        }
        else if (cacheable) {
            // recursively instantiate the types of the fields
            if (dt->types == NULL)
                ndt->types = pyju_compute_fieldtypes(ndt, stack);
            else
                ndt->types = inst_ftypes(ftypes, env, stack);
            pyju_gc_wb(ndt, ndt->types);
        }
    }

    // now publish the finished result
    // XXX: if the stack was used, this will publish in the wrong order,
    // leading to incorrect layouts and data races (#40050: the A{T} should be
    // an isbitstype singleton of size 0)
    if (cacheable) {
        if (ndt->layout == NULL && ndt->types != NULL && ndt->isconcretetype)
            pyju_compute_field_offsets(ndt);
        pyju_cache_type_(ndt);
        PYJU_UNLOCK(&typecache_lock); // Might GC
    }

    PYJU_GC_POP();
    return (PyjuValue_t*)ndt;
}


PYJU_DLLEXPORT PyjuValue_t *pyju_tupletype_fill(size_t n, PyjuValue_t *v)
{
    // TODO: replace with just using NTuple
    PyjuValue_t *p = NULL;
    PYJU_GC_PUSH1(&p);
    p = (PyjuValue_t*)pyju_svec_fill(n, v);
    p = (PyjuValue_t*)pyju_apply_tuple_type((PyjuSvec_t*)p);
    PYJU_GC_POP();
    return p;
}

static PyjuSvec_t *inst_ftypes(PyjuSvec_t *p, PyjuTypeEnv_t *env, pyju_typestack_t *stack)
{
    size_t i;
    size_t lp = pyju_svec_len(p);
    PyjuSvec_t *np = pyju_alloc_svec(lp);
    PYJU_GC_PUSH1(&np);
    for (i = 0; i < lp; i++) {
        PyjuValue_t *pi = pyju_svecref(p, i);
        PYJU_TRY {
            pi = inst_type_w_(pi, env, stack, 1);
            if (!pyju_is_type(pi) && pyju_is_typevar(pi)) {
                pi = pyju_bottom_type;
            }
        }
        PYJU_CATCH {
            pi = pyju_bottom_type;
        }
        pyju_svecset(np, i, pi);
    }
    PYJU_GC_POP();
    return np;
}

static PyjuValue_t *inst_tuple_w_(PyjuValue_t *t, PyjuTypeEnv_t *env, pyju_typestack_t *stack, int check)
{
    PyjuDataType_t *tt = (PyjuDataType_t*)t;
    PyjuSvec_t *tp = tt->parameters;
    size_t ntp = pyju_svec_len(tp);
    // Instantiate NTuple{3,Int}
    // Note this does not instantiate Tuple{Vararg{Int,3}}; that's done in inst_datatype_inner
    if (pyju_is_va_tuple(tt) && ntp == 1) {
        // If this is a Tuple{Vararg{T,N}} with known N, expand it to
        // a fixed-length tuple
        PyjuValue_t *T=NULL, *N=NULL;
        PyjuValue_t *va = pyju_unwrap_unionall(pyju_tparam0(tt));
        PyjuValue_t *ttT = pyju_unwrap_vararg(va);
        PyjuValue_t *ttN = pyju_unwrap_vararg_num(va);
        PyjuTypeEnv_t *e = env;
        while (e != NULL) {
            if ((PyjuValue_t*)e->var == ttT)
                T = e->val;
            else if ((PyjuValue_t*)e->var == ttN)
                N = e->val;
            e = e->prev;
        }
        if (T != NULL && N != NULL && pyju_is_long(N)) {
            ssize_t nt = pyju_unbox_long(N);
            if (nt < 0)
                pyju_errorf("size or dimension is negative: %zd", nt);
            return (PyjuValue_t*)pyju_tupletype_fill(nt, T);
        }
    }
    PyjuValue_t **iparams;
    int onstack = ntp < pyju_page_size / sizeof(PyjuValue_t*);
    PYJU_GC_PUSHARGS(iparams, onstack ? ntp : 1);
    PyjuSvec_t *ip_heap = NULL;
    if (!onstack) {
        ip_heap = pyju_alloc_svec(ntp);
        iparams[0] = (PyjuValue_t*)ip_heap;
        iparams = pyju_svec_data(ip_heap);
    }
    int bound = 0;
    int i;
    for (i = 0; i < ntp; i++) {
        PyjuValue_t *elt = pyju_svecref(tp, i);
        PyjuValue_t *pi = inst_type_w_(elt, env, stack, 0);
        iparams[i] = pi;
        if (ip_heap)
            pyju_gc_wb(ip_heap, pi);
        bound |= (pi != elt);
    }
    if (bound)
        t = inst_datatype_inner(tt, ip_heap, iparams, ntp, stack, env);
    PYJU_GC_POP();
    return t;
}

static PyjuValue_t *inst_type_w_(PyjuValue_t *t, PyjuTypeEnv_t *env, pyju_typestack_t *stack, int check)
{
    size_t i;
    if (pyju_is_typevar(t)) {
        PyjuTypeEnv_t *e = env;
        while (e != NULL) {
            if (e->var == (PyjuTVar_t*)t) {
                PyjuValue_t *val = e->val;
                return val;
            }
            e = e->prev;
        }
        return t;
    }
    if (pyju_is_unionall(t)) {
        PyjuUnionAll_t *ua = (PyjuUnionAll_t*)t;
        PyjuValue_t *lb = NULL;
        PyjuValue_t *var = NULL;
        PyjuValue_t *newbody = NULL;
        PYJU_GC_PUSH3(&lb, &var, &newbody);
        lb = inst_type_w_(ua->var->lb, env, stack, check);
        var = inst_type_w_(ua->var->ub, env, stack, check);
        if (lb != ua->var->lb || var != ua->var->ub) {
            var = (PyjuValue_t*)pyju_new_typevar(ua->var->name, lb, var);
        }
        else {
            var = (PyjuValue_t*)ua->var;
        }
        PyjuTypeEnv_t newenv = { ua->var, var, env };
        newbody = inst_type_w_(ua->body, &newenv, stack, check);
        if (newbody == (PyjuValue_t*)pyju_emptytuple_type) {
            // NTuple{0} => Tuple{} can make a typevar disappear
            t = (PyjuValue_t*)pyju_emptytuple_type;
        }
        else if (newbody != ua->body || var != (PyjuValue_t*)ua->var) {
            // if t's parameters are not bound in the environment, return it uncopied (#9378)
            t = pyju_new_struct(pyju_unionall_type, var, newbody);
        }
        PYJU_GC_POP();
        return t;
    }
    if (pyju_is_uniontype(t)) {
        PyjuUnionType_t *u = (PyjuUnionType_t*)t;
        PyjuValue_t *a = inst_type_w_(u->a, env, stack, check);
        PyjuValue_t *b = NULL;
        PYJU_GC_PUSH2(&a, &b);
        b = inst_type_w_(u->b, env, stack, check);
        if (a != u->a || b != u->b) {
            PyjuValue_t *uargs[2] = {a, b};
            t = pyju_type_union(uargs, 2);
        }
        PYJU_GC_POP();
        return t;
    }
    if (pyju_is_vararg(t)) {
        PyjuVararg_t *v = (PyjuVararg_t*)t;
        PyjuValue_t *T = NULL;
        PyjuValue_t *N = NULL;
        PYJU_GC_PUSH2(&T, &N);
        if (v->T) {
            T = inst_type_w_(v->T, env, stack, check);
            if (v->N)
                N = inst_type_w_(v->N, env, stack, check);
        }
        if (T != v->T || N != v->N) {
            t = (PyjuValue_t*)pyju_wrap_vararg(T, N);
        }
        PYJU_GC_POP();
        return t;
    }
    if (!pyju_is_datatype(t))
        return t;
    PyjuDataType_t *tt = (PyjuDataType_t*)t;
    PyjuSvec_t *tp = tt->parameters;
    if (tp == pyju_emptysvec)
        return t;
    PyjuTypeName_t *tn = tt->name;
    if (tn == pyju_tuple_typename)
        return inst_tuple_w_(t, env, stack, check);
    size_t ntp = pyju_svec_len(tp);
    PyjuValue_t **iparams;
    PYJU_GC_PUSHARGS(iparams, ntp);
    int bound = 0;
    for (i = 0; i < ntp; i++) {
        PyjuValue_t *elt = pyju_svecref(tp, i);
        PyjuValue_t *pi = inst_type_w_(elt, env, stack, check);
        iparams[i] = pi;
        bound |= (pi != elt);
    }
    // if t's parameters are not bound in the environment, return it uncopied (#9378)
    if (bound)
        t = inst_datatype_inner(tt, NULL, iparams, ntp, stack, env);
    PYJU_GC_POP();
    return t;
}

PyjuDataType_t *pyju_wrap_Type(PyjuValue_t *t)
{
    return (PyjuDataType_t*)pyju_instantiate_unionall(pyju_type_type, t);
}

static PyjuTupleType_t *pyju_apply_tuple_type_v_(PyjuValue_t **p, size_t np, PyjuSvec_t *params)
{
    return (PyjuDatatype_t*)inst_datatype_inner(pyju_anytuple_type, params, p, np, NULL, NULL);
}

PYJU_DLLEXPORT PyjuTupleType_t *pyju_apply_tuple_type_v(PyjuValue_t **p, size_t np)
{
    return pyju_apply_tuple_type_v_(p, np, NULL);
}

PYJU_DLLEXPORT PyjuTupleType_t *pyju_apply_tuple_type(PyjuSvec_t *params)
{
    return pyju_apply_tuple_type_v_(pyju_svec_data(params), pyju_svec_len(params), params);
}

// Build an environment mapping a TypeName's parameters to parameter values.
// This is the environment needed for instantiating a type's supertype and field types.
static PyjuValue_t *inst_datatype_env(PyjuValue_t *dt, PyjuSvec_t *p, PyjuValue_t **iparams, size_t ntp,
                                     pyju_typestack_t *stack, PyjuTypeEnv_t *env, int c)
{
    DEBUG_FUNC
    if (pyju_is_datatype(dt))
        return inst_datatype_inner((PyjuDataType_t*)dt, p, iparams, ntp, stack, env);
    DEBUG_FUNC
    assert(pyju_is_unionall(dt));
    DEBUG_FUNC
    PyjuUnionAll_t *ua = (PyjuUnionAll_t*)dt;
    DEBUG_FUNC
    PyjuTypeEnv_t e = { ua->var, iparams[c], env };
    DEBUG_FUNC
    return inst_datatype_env(ua->body, p, iparams, ntp, stack, &e, c + 1);
}

PyjuValue_t *pyju_apply_type(PyjuValue_t *tc, PyjuValue_t **params, size_t n)
{
    DEBUG_FUNC
    if (tc == (PyjuValue_t*)pyju_anytuple_type)
        return (PyjuValue_t*)pyju_apply_tuple_type_v(params, n);
    if (tc == (PyjuValue_t*)pyju_uniontype_type)
        return (PyjuValue_t*)pyju_type_union(params, n);
    size_t i;
    DEBUG_FUNC
    if (n > 1) {
        DEBUG_FUNC
        // detect common case of applying a wrapper, where we know that all parameters will
        // end up as direct parameters of a certain datatype, which can be optimized.
        PyjuValue_t *u = pyju_unwrap_unionall(tc);
        if (pyju_is_datatype(u) && n == pyju_nparams((PyjuDataType_t*)u) &&
            ((PyjuDataType_t*)u)->name->wrapper == tc) {
            DEBUG_FUNC
            return inst_datatype_env(tc, NULL, params, n, NULL, NULL, 0);
        }
        DEBUG_FUNC
    }
    DEBUG_FUNC
    PYJU_GC_PUSH1(&tc);
    PyjuValue_t *tc0 = tc;
    for (i=0; i < n; i++) {
        DEBUG_FUNC
        if (!pyju_is_unionall(tc0))
            pyju_error("too many parameters for type");
        PyjuValue_t *pi = params[i];
        DEBUG_FUNC

        tc0 = ((PyjuUnionAll_t*)tc0)->body;
        // doing a substitution can cause later UnionAlls to be dropped,
        // as in `NTuple{0,T} where T` => `Tuple{}`. allow values to be
        // substituted for these missing parameters.
        // TODO: figure out how to get back a type error for e.g.
        // S = Tuple{Vararg{T,N}} where T<:NTuple{N} where N
        // S{0,Int}
        if (!pyju_is_unionall(tc)) continue;
        DEBUG_FUNC

        PyjuUnionAll_t *ua = (PyjuUnionAll_t*)tc;
        if (!pyju_has_free_typevars(ua->var->lb) && !pyju_has_free_typevars(ua->var->ub) &&
            !within_typevar(pi, ua->var->lb, ua->var->ub)) {
            DEBUG_FUNC
            PyjuDataType_t *inner = (PyjuDataType_t*)pyju_unwrap_unionall(tc);
            int iswrapper = 0;
            if (pyju_is_datatype(inner)) {
                PyjuValue_t *temp = inner->name->wrapper;
                while (pyju_is_unionall(temp)) {
                    if (temp == tc) {
                        iswrapper = 1;
                        break;
                    }
                    temp = ((PyjuUnionAll_t*)temp)->body;
                }
            }
            // if this is a wrapper, let check_datatype_parameters give the error
            if (!iswrapper)
                pyju_type_error_rt(pyju_is_datatype(inner) ? pyju_symbol_name(inner->name->name) : "Type",
                                 pyju_symbol_name(ua->var->name), (PyjuValue_t*)ua->var, pi);
        }
        DEBUG_FUNC
        tc = pyju_instantiate_unionall(ua, pi);
    }
    DEBUG_FUNC
    PYJU_GC_POP();
    return tc;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_apply_type1(PyjuValue_t *tc, PyjuValue_t *p1)
{
    return pyju_apply_type(tc, &p1, 1);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_apply_type2(PyjuValue_t *tc, PyjuValue_t *p1, PyjuValue_t *p2)
{
    PyjuValue_t *args[2];
    args[0] = p1;
    args[1] = p2;
    return pyju_apply_type(tc, args, 2);
}

PyjuDataType_t *pyju_apply_modify_type(PyjuValue_t *dt)
{
    PyjuDataType_t *rettyp = (PyjuDataType_t*)pyju_apply_type2(pyju_pair_type, dt, dt);
    PYJU_GC_PROMISE_ROOTED(rettyp); // (PYJU_ALWAYS_LEAFTYPE)
    return rettyp;
}

void pyju_init_types(void) PYJU_GC_DISABLED {
    PyjuModule_t *core = nullptr;

    // create base objects
    pyju_datatype_type = pyju_new_uninitialized_datatype();
    pyju_set_typeof(pyju_datatype_type, pyju_datatype_type);
    pyju_typename_type = pyju_new_uninitialized_datatype();
    pyju_symbol_type = pyju_new_uninitialized_datatype();
    pyju_simplevector_type = pyju_new_uninitialized_datatype();
    pyju_methtable_type = pyju_new_uninitialized_datatype();

    pyju_emptysvec = (PyjuSvec_t*)pyju_gc_permobj(sizeof(void*) + PYJU_TV_SIZE, pyju_simplevector_type);
    pyju_svec_set_len_unsafe(pyju_emptysvec, 0);

    pyju_any_type = (PyjuDataType_t*)pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("Any"), core, NULL, pyju_emptysvec);
    pyju_any_type->super = pyju_any_type;
    // 在pyju_new_abstracttype中pyju_any_type->name->mt的值就是pyju_nonfunction_mt, 这样赋值不自相矛盾吗？
    pyju_nonfunction_mt = pyju_any_type->name->mt;
    pyju_any_type->name->mt = NULL;

    pyju_type_type = (PyjuUnionAll_t*)pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("Type"), core, pyju_any_type, pyju_emptysvec);
    pyju_type_typename = ((PyjuDataType_t*)pyju_type_type)->name;
    pyju_type_type_mt = pyju_new_method_table(pyju_type_typename->name, core);
    pyju_type_typename->mt = pyju_type_type_mt;

    // initialize them. lots of cycles.
    // NOTE: types are not actually mutable, but we want to ensure they are heap-allocated with stable address
    pyju_datatype_type->name = pyju_new_typename_in(pyju_symbol("DataType"), core, 0, 1);
    pyju_datatype_type->name->wrapper = (PyjuValue_t*)pyju_datatype_type;
    pyju_datatype_type->super = (PyjuDataType_t*)pyju_type_type;
    pyju_datatype_type->parameters = pyju_emptysvec;
    pyju_datatype_type->name->n_uninitialized = 9 - 3;
    pyju_datatype_type->name->names = pyju_perm_symsvec(9,
        "name",
        "super",
        "parameters",
        "types",
        "instance",
        "layout",
        "size",
        "hash",
        "flags"); // "hasfreetypevars", "isconcretetype", "isdispatchtuple", "isbitstype", "zeroinit", "has_concrete_subtype", "cached_by_hash"
    pyju_datatype_type->types = pyju_svec(9,
        pyju_typename_type,
        pyju_datatype_type,
        pyju_simplevector_type,
        pyju_simplevector_type,
        pyju_any_type, // instance
        pyju_any_type, // pyju_voidpointer_type
        pyju_any_type, // pyju_int32_type
        pyju_any_type, // pyju_int32_type
        pyju_any_type // pyju_uint8_type
        );
    const static uint32_t datatype_constfields[1] = { 0x00000097 }; // (1<<0)|(1<<1)|(1<<2)|(1<<4)|(1<<7)
    pyju_datatype_type->name->constfields = datatype_constfields;
    pyju_precompute_memoized_dt(pyju_datatype_type, 1);

    pyju_typename_type->name = pyju_new_typename_in(pyju_symbol("TypeName"), core, 0, 1);
    pyju_typename_type->name->wrapper = (PyjuValue_t*)pyju_typename_type;
    pyju_typename_type->name->mt = pyju_nonfunction_mt;
    pyju_typename_type->super = pyju_any_type;
    pyju_typename_type->parameters = pyju_emptysvec;
    pyju_typename_type->name->n_uninitialized = 13 - 2;
    pyju_typename_type->name->names = pyju_perm_symsvec(13, "name", "module",
                                                        "names", "atomicfields", "constfields",
                                                        "wrapper", "cache", "linearcache",
                                                        "mt", "partial",
                                                        "hash", "n_uninitialized",
                                                        "flags"); // "abstract", "mutable", "mayinlinealloc"
    pyju_typename_type->types = pyju_svec(13, pyju_symbol_type, pyju_any_type /*pyju_module_type*/,
                                          pyju_simplevector_type, pyju_any_type /*pyju_voidpointer_type*/, pyju_any_type /*pyju_voidpointer_type*/,
                                          pyju_type_type, pyju_simplevector_type, pyju_simplevector_type,
                                          pyju_methtable_type, pyju_any_type,
                                          pyju_any_type /*pyju_long_type*/, pyju_any_type /*pyju_int32_type*/,
                                          pyju_any_type /*pyju_uint8_type*/);
    const static uint32_t typename_constfields[1] = { 0x00001d3f }; // (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<8)|(1<<10)|(1<<11)|(1<<12)
    pyju_typename_type->name->constfields = typename_constfields;
    pyju_precompute_memoized_dt(pyju_typename_type, 1);

    pyju_methtable_type->name = pyju_new_typename_in(pyju_symbol("MethodTable"), core, 0, 1);
    pyju_methtable_type->name->wrapper = (PyjuValue_t*)pyju_methtable_type;
    pyju_methtable_type->name->mt = pyju_nonfunction_mt;
    pyju_methtable_type->super = pyju_any_type;
    pyju_methtable_type->parameters = pyju_emptysvec;
    pyju_methtable_type->name->n_uninitialized = 12 - 5;
    pyju_methtable_type->name->names = pyju_perm_symsvec(12, "name", "defs",
                                                         "leafcache", "cache", "max_args",
                                                         "kwsorter", "module",
                                                         "backedges", "", "", "offs", "");
    pyju_methtable_type->types = pyju_svec(12, pyju_symbol_type, pyju_any_type, pyju_any_type,
                                           pyju_any_type, pyju_any_type /*pyju_long*/,
                                           pyju_any_type, pyju_any_type /*module*/,
                                           pyju_any_type /*any vector*/, pyju_any_type /*voidpointer*/, pyju_any_type/*int32*/,
                                           pyju_any_type /*uint8*/, pyju_any_type/*uint8*/);
    const static uint32_t methtable_constfields[1] = { 0x00000040 }; // (1<<6)
    pyju_methtable_type->name->constfields = methtable_constfields;
    pyju_precompute_memoized_dt(pyju_methtable_type, 1);

    pyju_symbol_type->name = pyju_new_typename_in(pyju_symbol("Symbol"), core, 0, 1);
    pyju_symbol_type->name->wrapper = (PyjuValue_t*)pyju_symbol_type;
    pyju_symbol_type->name->mt = pyju_nonfunction_mt;
    pyju_symbol_type->super = pyju_any_type;
    pyju_symbol_type->parameters = pyju_emptysvec;
    pyju_symbol_type->name->n_uninitialized = 0;
    pyju_symbol_type->name->names = pyju_emptysvec;
    pyju_symbol_type->types = pyju_emptysvec;
    pyju_symbol_type->size = 0;
    pyju_precompute_memoized_dt(pyju_symbol_type, 1);

    pyju_simplevector_type->name = pyju_new_typename_in(pyju_symbol("SimpleVector"), core, 0, 1);
    pyju_simplevector_type->name->wrapper = (PyjuValue_t*)pyju_simplevector_type;
    pyju_simplevector_type->name->mt = pyju_nonfunction_mt;
    pyju_simplevector_type->super = pyju_any_type;
    pyju_simplevector_type->parameters = pyju_emptysvec;
    pyju_simplevector_type->name->n_uninitialized = 0;
    pyju_simplevector_type->name->names = pyju_emptysvec;
    pyju_simplevector_type->types = pyju_emptysvec;
    pyju_precompute_memoized_dt(pyju_simplevector_type, 1);

    pyju_nothing_type = pyju_new_datatype(pyju_symbol("Nothing"), core, pyju_any_type, pyju_emptysvec,
                                          pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 0, 0, 0);
    pyju_void_type = pyju_nothing_type; // deprecated alias
    // 之前初始化pyju_nothing设置的type是无效的，重新设置一次
    pyju_astaggedvalue(pyju_nothing)->header = ((uintptr_t)pyju_nothing_type) | GC_OLD_MARKED;
    pyju_nothing_type->instance = pyju_nothing;

    PyjuDataType_t *type_type = (PyjuDataType_t*)pyju_type_type;
    pyju_typeofbottom_type = pyju_new_datatype(pyju_symbol("TypeofBottom"), core, type_type, pyju_emptysvec,
                                             pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 0, 0, 0);
    pyju_bottom_type = pyju_new_struct(pyju_typeofbottom_type);
    pyju_typeofbottom_type->instance = pyju_bottom_type;

    pyju_uniontype_type = pyju_new_datatype(pyju_symbol("Union"), core, type_type, pyju_emptysvec,
                                        pyju_perm_symsvec(2, "a", "b"),
                                        pyju_svec(2, pyju_any_type, pyju_any_type),
                                        pyju_emptysvec, 0, 0, 2);
    pyju_tvar_type = pyju_new_datatype(pyju_symbol("TypeVar"), core, pyju_any_type, pyju_emptysvec,
                                   pyju_perm_symsvec(3, "name", "lb", "ub"),
                                   pyju_svec(3, pyju_symbol_type, pyju_any_type, pyju_any_type),
                                   pyju_emptysvec, 0, 1, 3);

    pyju_unionall_type = pyju_new_datatype(pyju_symbol("UnionAll"), core, type_type, pyju_emptysvec,
                                       pyju_perm_symsvec(2, "var", "body"),
                                       pyju_svec(2, pyju_tvar_type, pyju_any_type),
                                       pyju_emptysvec, 0, 0, 2);

    pyju_vararg_type = pyju_new_datatype(pyju_symbol("TypeofVararg"), core, pyju_any_type, pyju_emptysvec,
                                            pyju_perm_symsvec(2, "T", "N"),
                                            pyju_svec(2, pyju_any_type, pyju_any_type),
                                            pyju_emptysvec, 0, 0, 0);

    PyjuSvec_t *anytuple_params = pyju_svec(1, pyju_wrap_vararg((PyjuValue_t*)pyju_any_type, (PyjuValue_t*)NULL));
    pyju_anytuple_type = pyju_new_datatype(pyju_symbol("Tuple"), core, pyju_any_type, anytuple_params,
                                       pyju_emptysvec, anytuple_params, pyju_emptysvec, 0, 0, 0);
    pyju_tuple_typename = pyju_anytuple_type->name;
    // fix some miscomputed values, since we didn't know this was going to be a Tuple in pyju_precompute_memoized_dt
    pyju_tuple_typename->wrapper = (PyjuValue_t*)pyju_anytuple_type; // remove UnionAll wrappers
    pyju_anytuple_type->isconcretetype = 0;
    pyju_anytuple_type->layout = NULL;
    pyju_anytuple_type->size = 0;
    pyju_anytuple_type->cached_by_hash = 0;

    PyjuTVar_t *tttvar = tvar("T");
    ((PyjuDataType_t*)pyju_type_type)->parameters = pyju_svec(1, tttvar);
    ((PyjuDataType_t*)pyju_type_type)->hasfreetypevars = 1;
    ((PyjuDataType_t*)pyju_type_type)->cached_by_hash = 0;
    pyju_type_typename->wrapper = pyju_new_struct(pyju_unionall_type, tttvar, (PyjuValue_t*)pyju_type_type);
    pyju_type_type = (PyjuUnionAll_t*)pyju_type_typename->wrapper;

    pyju_typeofbottom_type->super = pyju_wrap_Type(pyju_bottom_type);

    pyju_emptytuple_type = (PyjuDataType_t*)pyju_apply_tuple_type(pyju_emptysvec);
    pyju_emptytuple = pyju_gc_permobj(0 + PYJU_TV_SIZE, pyju_emptytuple_type);
    pyju_emptytuple_type->instance = pyju_emptytuple;

    // non-primitive definitions follow
    pyju_int32_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("Int32"), core,
                                         pyju_any_type, pyju_emptysvec, 32);
    pyju_int64_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("Int64"), core,
                                         pyju_any_type, pyju_emptysvec, 64);
    pyju_uint32_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("UInt32"), core,
                                          pyju_any_type, pyju_emptysvec, 32);
    pyju_uint64_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("UInt64"), core,
                                          pyju_any_type, pyju_emptysvec, 64);
    pyju_uint8_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("UInt8"), core,
                                         pyju_any_type, pyju_emptysvec, 8);

    pyju_ssavalue_type = pyju_new_datatype(pyju_symbol("SSAValue"), core, pyju_any_type, pyju_emptysvec,
                                       pyju_perm_symsvec(1, "id"),
                                       pyju_svec1(pyju_long_type),
                                       pyju_emptysvec, 0, 0, 1);

    pyju_abstractslot_type = pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("Slot"), core, pyju_any_type,
                                               pyju_emptysvec);

    pyju_slotnumber_type = pyju_new_datatype(pyju_symbol("SlotNumber"), core, pyju_abstractslot_type, pyju_emptysvec,
                                         pyju_perm_symsvec(1, "id"),
                                         pyju_svec1(pyju_long_type),
                                         pyju_emptysvec, 0, 0, 1);
    pyju_typedslot_type = pyju_new_datatype(pyju_symbol("TypedSlot"), core, pyju_abstractslot_type, pyju_emptysvec,
                                        pyju_perm_symsvec(2, "id", "typ"),
                                        pyju_svec(2, pyju_long_type, pyju_any_type),
                                        pyju_emptysvec, 0, 0, 2);

    pyju_argument_type = pyju_new_datatype(pyju_symbol("Argument"), core, pyju_any_type, pyju_emptysvec,
                                       pyju_perm_symsvec(1, "n"),
                                       pyju_svec1(pyju_long_type),
                                       pyju_emptysvec, 0, 0, 1);

    pyju_init_int32_int64_cache();

    pyju_bool_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("Bool"), core,
                                        pyju_any_type, pyju_emptysvec, 8);
    pyju_false = pyju_permbox8(pyju_bool_type, 0);
    pyju_true  = pyju_permbox8(pyju_bool_type, 1);

    pyju_abstractstring_type = pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("AbstractString"), core, pyju_any_type, pyju_emptysvec);
    pyju_string_type = pyju_new_datatype(pyju_symbol("String"), core, pyju_abstractstring_type, pyju_emptysvec,
                                     pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 0, 1, 0);
    pyju_string_type->instance = NULL;
    pyju_compute_field_offsets(pyju_string_type);
    pyju_an_empty_string = pyju_pchar_to_string("\0", 1);
    // *(size_t*)pyju_an_empty_string = 0;
    pyju_string_len(pyju_an_empty_string) = 0;

    pyju_typemap_level_type =
        pyju_new_datatype(pyju_symbol("TypeMapLevel"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(6,
                            "arg1",
                            "targ",
                            "name1",
                            "tname",
                            "list",
                            "any"),
                        pyju_svec(6,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type),
                        pyju_emptysvec,
                        0, 1, 6);

    pyju_typemap_entry_type =
        pyju_new_datatype(pyju_symbol("TypeMapEntry"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(10,
                            "next",
                            "sig",
                            "simplesig",
                            "guardsigs",
                            "min_world",
                            "max_world",
                            "func",
                            "isleafsig",
                            "issimplesig",
                            "va"),
                        pyju_svec(10,
                            pyju_any_type, // Union{TypeMapEntry, Nothing}
                            pyju_type_type, // TupleType
                            pyju_any_type, // TupleType
                            pyju_any_type, // SimpleVector{TupleType}
                            pyju_ulong_type, // UInt
                            pyju_ulong_type, // UInt
                            pyju_any_type, // Any
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_bool_type),
                        pyju_emptysvec,
                        0, 1, 4);
    const static uint32_t typemap_entry_constfields[1] = { 0x000003fe }; // (1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<9);
    pyju_typemap_entry_type->name->constfields = typemap_entry_constfields;

    pyju_function_type = pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("Function"), core, pyju_any_type, pyju_emptysvec);
    pyju_builtin_type  = pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("Builtin"), core, pyju_function_type, pyju_emptysvec);
    pyju_function_type->name->mt = NULL; // subtypes of Function have independent method tables
    pyju_builtin_type->name->mt = NULL;  // so they don't share the Any type table

    PyjuSvec_t *tv = pyju_svec2(tvar("T"), tvar("N"));
    pyju_abstractarray_type = (PyjuUnionAll_t*)
        pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("AbstractArray"), core,
                            pyju_any_type, tv)->name->wrapper;


    tv = pyju_svec2(tvar("T"), tvar("N"));
    pyju_densearray_type = (PyjuUnionAll_t*)
        pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("DenseArray"), core,
                            (PyjuDataType_t*)pyju_apply_type((PyjuValue_t*)pyju_abstractarray_type, pyju_svec_data(tv), 2),
                            tv)->name->wrapper;

    tv = pyju_svec2(tvar("T"), tvar("N"));
    pyju_array_type = (PyjuUnionAll_t*)
        pyju_new_datatype(pyju_symbol("Array"), core,
                        (PyjuDataType_t*)pyju_apply_type((PyjuValue_t*)pyju_densearray_type, pyju_svec_data(tv), 2),
                        tv, pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 0, 1, 0)->name->wrapper;
    pyju_array_typename = ((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_array_type))->name;
    pyju_compute_field_offsets((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_array_type));

    DEBUG_FUNC
    pyju_array_any_type = pyju_apply_type2((PyjuValue_t*)pyju_array_type, (PyjuValue_t*)pyju_any_type, pyju_box_long(1));
    DEBUG_FUNC
    pyju_array_symbol_type = pyju_apply_type2((PyjuValue_t*)pyju_array_type, (PyjuValue_t*)pyju_symbol_type, pyju_box_long(1));
    DEBUG_FUNC
    pyju_array_uint8_type = pyju_apply_type2((PyjuValue_t*)pyju_array_type, (PyjuValue_t*)pyju_uint8_type, pyju_box_long(1));
    DEBUG_FUNC
    pyju_array_int32_type = pyju_apply_type2((PyjuValue_t*)pyju_array_type, (PyjuValue_t*)pyju_int32_type, pyju_box_long(1));
    DEBUG_FUNC
    pyju_array_uint64_type = pyju_apply_type2((PyjuValue_t*)pyju_array_type, (PyjuValue_t*)pyju_uint64_type, pyju_box_long(1));
    DEBUG_FUNC
    pyju_an_empty_vec_any = (PyjuValue_t*)pyju_alloc_vec_any(0); // used internally
    DEBUG_FUNC
    pyju_atomic_store_relaxed(&pyju_nonfunction_mt->leafcache, (PyjuArray_t*)pyju_an_empty_vec_any);
    DEBUG_FUNC
    pyju_atomic_store_relaxed(&pyju_type_type_mt->leafcache, (PyjuArray_t*)pyju_an_empty_vec_any);
    DEBUG_FUNC

    pyju_expr_type =
        pyju_new_datatype(pyju_symbol("Expr"), core,
                        pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(2, "head", "args"),
                        pyju_svec(2, pyju_symbol_type, pyju_array_any_type),
                        pyju_emptysvec, 0, 1, 2);

    pyju_module_type =
        pyju_new_datatype(pyju_symbol("Module"), core, pyju_any_type, pyju_emptysvec,
                        pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 0, 1, 0);
    pyju_module_type->instance = NULL;
    pyju_compute_field_offsets(pyju_module_type);


    PyjuValue_t *symornothing[2] = { (PyjuValue_t*)pyju_symbol_type, (PyjuValue_t*)pyju_void_type };
    pyju_linenumbernode_type =
        pyju_new_datatype(pyju_symbol("LineNumberNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(2, "line", "file"),
                        pyju_svec(2, pyju_long_type, pyju_type_union(symornothing, 2)),
                        pyju_emptysvec, 0, 0, 2);

    pyju_lineinfonode_type =
        pyju_new_datatype(pyju_symbol("LineInfoNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(5, "module", "method", "file", "line", "inlined_at"),
                        pyju_svec(5, pyju_module_type, pyju_any_type, pyju_symbol_type, pyju_long_type, pyju_long_type),
                        pyju_emptysvec, 0, 0, 5);

    pyju_gotonode_type =
        pyju_new_datatype(pyju_symbol("GotoNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(1, "label"),
                        pyju_svec(1, pyju_long_type),
                        pyju_emptysvec, 0, 0, 1);

    pyju_gotoifnot_type =
        pyju_new_datatype(pyju_symbol("GotoIfNot"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(2, "cond", "dest"),
                        pyju_svec(2, pyju_any_type, pyju_long_type),
                        pyju_emptysvec, 0, 0, 2);


    pyju_returnnode_type =
        pyju_new_datatype(pyju_symbol("ReturnNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(1, "val"),
                        pyju_svec(1, pyju_any_type),
                        pyju_emptysvec, 0, 0, 0);


    pyju_pinode_type =
        pyju_new_datatype(pyju_symbol("PiNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(2, "val", "typ"),
                        pyju_svec(2, pyju_any_type, pyju_any_type),
                        pyju_emptysvec, 0, 0, 2);

    pyju_phinode_type =
        pyju_new_datatype(pyju_symbol("PhiNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(2, "edges", "values"),
                        pyju_svec(2, pyju_array_int32_type, pyju_array_any_type),
                        pyju_emptysvec, 0, 0, 2);

    pyju_phicnode_type =
        pyju_new_datatype(pyju_symbol("PhiCNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(1, "values"),
                        pyju_svec(1, pyju_array_any_type),
                        pyju_emptysvec, 0, 0, 1);

    pyju_upsilonnode_type =
        pyju_new_datatype(pyju_symbol("UpsilonNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(1, "val"),
                        pyju_svec(1, pyju_any_type),
                        pyju_emptysvec, 0, 0, 0);

    pyju_quotenode_type =
        pyju_new_datatype(pyju_symbol("QuoteNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(1, "value"),
                        pyju_svec(1, pyju_any_type),
                        pyju_emptysvec, 0, 0, 1);

    pyju_newvarnode_type =
        pyju_new_datatype(pyju_symbol("NewvarNode"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(1, "slot"),
                        pyju_svec(1, pyju_slotnumber_type),
                        pyju_emptysvec, 0, 0, 1);

    pyju_globalref_type =
        pyju_new_datatype(pyju_symbol("GlobalRef"), core, pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(2, "mod", "name"),
                        pyju_svec(2, pyju_module_type, pyju_symbol_type),
                        pyju_emptysvec, 0, 0, 2);


    pyju_code_info_type =
        pyju_new_datatype(pyju_symbol("CodeInfo"), core,
                        pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(20,
                            "code",
                            "codelocs",
                            "ssavaluetypes",
                            "ssaflags",
                            "method_for_inference_limit_heuristics",
                            "linetable",
                            "slotnames",
                            "slotflags",
                            "slottypes",
                            "rettype",
                            "parent",
                            "edges",
                            "min_world",
                            "max_world",
                            "inferred",
                            "inlineable",
                            "propagate_inbounds",
                            "pure",
                            "constprop",
                            "purity"),
                        pyju_svec(20,
                            pyju_array_any_type,
                            pyju_array_int32_type,
                            pyju_any_type,
                            pyju_array_uint8_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_array_symbol_type,
                            pyju_array_uint8_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_ulong_type,
                            pyju_ulong_type,
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_uint8_type,
                            pyju_uint8_type),
                        pyju_emptysvec,
                        0, 1, 20);


    pyju_method_type =
        pyju_new_datatype(pyju_symbol("Method"), core,
                        pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(29,
                            "name",
                            "module",
                            "file",
                            "line",
                            "primary_world",
                            "deleted_world", // !const
                            "sig",
                            "specializations", // !const
                            "speckeyset", // !const
                            "slot_syms",
                            "external_mt",
                            "source", // !const
                            "unspecialized", // !const
                            "generator", // !const
                            "roots", // !const
                            "root_blocks", // !const
                            "nroots_sysimg",
                            "ccallable", // !const
                            "invokes", // !const
                            "recursion_relation", // !const
                            "nargs",
                            "called",
                            "nospecialize",
                            "nkw",
                            "isva",
                            "pure",
                            "is_for_opaque_closure",
                            "constprop",
                            "purity"),
                        pyju_svec(29,
                            pyju_symbol_type,
                            pyju_module_type,
                            pyju_symbol_type,
                            pyju_int32_type,
                            pyju_ulong_type,
                            pyju_ulong_type,
                            pyju_type_type,
                            pyju_simplevector_type,
                            pyju_array_type,
                            pyju_string_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type, // pyju_method_instance_type
                            pyju_any_type,
                            pyju_array_any_type,
                            pyju_array_uint64_type,
                            pyju_int32_type,
                            pyju_simplevector_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_int32_type,
                            pyju_int32_type,
                            pyju_int32_type,
                            pyju_int32_type,
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_uint8_type,
                            pyju_uint8_type),
                        pyju_emptysvec,
                        0, 1, 10);
    //const static uint32_t method_constfields[1] = { 0x03fc065f }; // (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<6)|(1<<9)|(1<<10)|(1<<18)|(1<<19)|(1<<20)|(1<<21)|(1<<22)|(1<<23)|(1<<24)|(1<<25);
    //pyju_method_type->name->constfields = method_constfields;

    pyju_method_instance_type =
        pyju_new_datatype(pyju_symbol("MethodInstance"), core,
                        pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(9,
                            "def",
                            "specTypes",
                            "sparam_vals",
                            "uninferred",
                            "backedges",
                            "callbacks",
                            "cache",
                            "inInference",
                            "precompiled"),
                        pyju_svec(9,
                            pyju_new_struct(pyju_uniontype_type, pyju_method_type, pyju_module_type),
                            pyju_any_type,
                            pyju_simplevector_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_bool_type,
                            pyju_bool_type),
                        pyju_emptysvec,
                        0, 1, 3);
    //const static uint32_t method_instance_constfields[1] = { 0x00000007 }; // (1<<0)|(1<<1)|(1<<2);
    //pyju_method_instance_type->name->constfields = method_instance_constfields;

    pyju_code_instance_type =
        pyju_new_datatype(pyju_symbol("CodeInstance"), core,
                        pyju_any_type, pyju_emptysvec,
                        pyju_perm_symsvec(15,
                            "def",
                            "next",
                            "min_world",
                            "max_world",
                            "rettype",
                            "rettype_const",
                            "inferred",
                            //"edges",
                            //"absolute_max",
	                        "ipo_purity_bits", "purity_bits",
                            "argescapes",
                            "isspecsig", "precompile", "invoke", "specptr", // function object decls
                            "relocatability"),
                        pyju_svec(15,
                            pyju_method_instance_type,
                            pyju_any_type,
                            pyju_ulong_type,
                            pyju_ulong_type,
                            pyju_any_type,
                            pyju_any_type,
                            pyju_any_type,
                            //pyju_any_type,
                            //pyju_bool_type,
                            pyju_uint32_type, pyju_uint32_type,
                            pyju_any_type,
                            pyju_bool_type,
                            pyju_bool_type,
                            pyju_any_type, pyju_any_type, // fptrs
                            pyju_uint8_type),
                        pyju_emptysvec,
                        0, 1, 1);
    pyju_svecset(pyju_code_instance_type->types, 1, pyju_code_instance_type);
    const static uint32_t code_instance_constfields[1] = { 0x00000001 }; // (1<<1);
    pyju_code_instance_type->name->constfields = code_instance_constfields;

    pyju_const_type = pyju_new_datatype(pyju_symbol("Const"), core, pyju_any_type, pyju_emptysvec,
                                       pyju_perm_symsvec(1, "val"),
                                       pyju_svec1(pyju_any_type),
                                       pyju_emptysvec, 0, 0, 1);

    pyju_partial_struct_type = pyju_new_datatype(pyju_symbol("PartialStruct"), core, pyju_any_type, pyju_emptysvec,
                                       pyju_perm_symsvec(2, "typ", "fields"),
                                       pyju_svec2(pyju_any_type, pyju_array_any_type),
                                       pyju_emptysvec, 0, 0, 2);

    pyju_interconditional_type = pyju_new_datatype(pyju_symbol("InterConditional"), core, pyju_any_type, pyju_emptysvec,
                                          pyju_perm_symsvec(3, "slot", "vtype", "elsetype"),
                                          pyju_svec(3, pyju_long_type, pyju_any_type, pyju_any_type),
                                          pyju_emptysvec, 0, 0, 3);

    pyju_method_match_type = pyju_new_datatype(pyju_symbol("MethodMatch"), core, pyju_any_type, pyju_emptysvec,
                                       pyju_perm_symsvec(4, "spec_types", "sparams", "method", "fully_covers"),
                                       pyju_svec(4, pyju_type_type, pyju_simplevector_type, pyju_method_type, pyju_bool_type),
                                       pyju_emptysvec, 0, 0, 4);

    // all Kinds share the Type method table (not the nonfunction one)
    pyju_unionall_type->name->mt = pyju_uniontype_type->name->mt = pyju_datatype_type->name->mt =
        pyju_type_type_mt;

    pyju_intrinsic_type = pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("IntrinsicFunction"), core,
                                             pyju_builtin_type, pyju_emptysvec, 32);

    tv = pyju_svec1(tvar("T"));
    pyju_ref_type = (PyjuUnionAll_t*)
        pyju_new_abstracttype((PyjuValue_t*)pyju_symbol("Ref"), core, pyju_any_type, tv)->name->wrapper;

    tv = pyju_svec1(tvar("T"));
    pyju_pointer_type = (PyjuUnionAll_t*)
        pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("Ptr"), core,
                             (PyjuDataType_t*)pyju_apply_type((PyjuValue_t*)pyju_ref_type, pyju_svec_data(tv), 1), tv,
                             sizeof(void*)*8)->name->wrapper;
    pyju_pointer_typename = ((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_pointer_type))->name;


    // LLVMPtr{T, AS} where {T, AS}
    tv = pyju_svec2(tvar("T"), tvar("AS"));
    PyjuSvec_t*tv_base = pyju_svec1(tvar("T"));
    pyju_llvmpointer_type = (PyjuUnionAll_t*)
        pyju_new_primitivetype((PyjuValue_t*)pyju_symbol("LLVMPtr"), core,
                             (PyjuDataType_t*)pyju_apply_type((PyjuValue_t*)pyju_ref_type, pyju_svec_data(tv_base), 1), tv,
                             sizeof(void*)*8)->name->wrapper;
    pyju_llvmpointer_typename = ((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_llvmpointer_type))->name;


    // Type{T} where T<:Tuple
    tttvar = pyju_new_typevar(pyju_symbol("T"),
                            (PyjuValue_t*)pyju_bottom_type,
                            (PyjuValue_t*)pyju_anytuple_type);
    pyju_anytuple_type_type = (PyjuUnionAll_t*)pyju_new_struct(pyju_unionall_type,
                                                          tttvar, (PyjuValue_t*)pyju_wrap_Type((PyjuValue_t*)tttvar));

    PyjuTVar_t *ntval_var = pyju_new_typevar(pyju_symbol("T"), (PyjuValue_t*)pyju_bottom_type,
                                          (PyjuValue_t*)pyju_anytuple_type);
    tv = pyju_svec2(tvar("names"), ntval_var);
    PyjuDataType_t *ntt = pyju_new_datatype(pyju_symbol("NamedTuple"), core, pyju_any_type, tv,
                                         pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 0, 0, 0);
    pyju_namedtuple_type = (PyjuUnionAll_t*)ntt->name->wrapper;
    ((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_namedtuple_type))->layout = NULL;
    pyju_namedtuple_typename = ntt->name;


    pyju_task_type = (PyjuDataType_t*)
        pyju_new_datatype(pyju_symbol("Task"),
                        NULL,
                        pyju_any_type,
                        pyju_emptysvec,
                        pyju_perm_symsvec(14,
                                        "next",
                                        "queue",
                                        "storage",
                                        "donenotify",
                                        "result",
                                        "logstate",
                                        "code",
                                        "rngState0",
                                        "rngState1",
                                        "rngState2",
                                        "rngState3",
                                        "_state",
                                        "sticky",
                                        "_isexception"),
                        pyju_svec(14,
                                pyju_any_type,
                                pyju_any_type,
                                pyju_any_type,
                                pyju_any_type,
                                pyju_any_type,
                                pyju_any_type,
                                pyju_any_type,
                                pyju_uint64_type,
                                pyju_uint64_type,
                                pyju_uint64_type,
                                pyju_uint64_type,
                                pyju_uint8_type,
                                pyju_bool_type,
                                pyju_bool_type),
                        pyju_emptysvec,
                        0, 1, 6);
    PyjuValue_t *listt = pyju_new_struct(pyju_uniontype_type, pyju_task_type, pyju_nothing_type);
    pyju_svecset(pyju_task_type->types, 0, listt);
    pyju_astaggedvalue(pyju_current_task)->header = (uintptr_t)pyju_task_type | pyju_astaggedvalue(pyju_current_task)->header;

    PyjuValue_t *pointer_void = pyju_apply_type1((PyjuValue_t*)pyju_pointer_type, (PyjuValue_t*)pyju_nothing_type);

    tv = pyju_svec2(tvar("A"), tvar("R"));
    pyju_opaque_closure_type = (PyjuUnionAll_t*)pyju_new_datatype(pyju_symbol("OpaqueClosure"), core, pyju_function_type, tv,
        pyju_perm_symsvec(5, "captures", "world", "source", "invoke", "specptr"),
        pyju_svec(5, pyju_any_type, pyju_long_type, pyju_any_type, pointer_void, pointer_void),
        pyju_emptysvec, 0, 0, 5)->name->wrapper;
    pyju_opaque_closure_typename = ((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_opaque_closure_type))->name;
    pyju_compute_field_offsets((PyjuDataType_t*)pyju_unwrap_unionall((PyjuValue_t*)pyju_opaque_closure_type));

    pyju_partial_opaque_type = pyju_new_datatype(pyju_symbol("PartialOpaque"), core, pyju_any_type, pyju_emptysvec,
        pyju_perm_symsvec(4, "typ", "env", "parent", "source"),
        pyju_svec(4, pyju_type_type, pyju_any_type, pyju_method_instance_type, pyju_method_type),
        pyju_emptysvec, 0, 0, 4);


    // complete builtin type metadata
    pyju_voidpointer_type = (PyjuDataType_t*)pointer_void;
    pyju_uint8pointer_type = (PyjuDataType_t*)pyju_apply_type1((PyjuValue_t*)pyju_pointer_type, (PyjuValue_t*)pyju_uint8_type);
    pyju_svecset(pyju_datatype_type->types, 5, pyju_voidpointer_type);
    pyju_svecset(pyju_datatype_type->types, 6, pyju_int32_type);
    pyju_svecset(pyju_datatype_type->types, 7, pyju_int32_type);
    pyju_svecset(pyju_datatype_type->types, 8, pyju_uint8_type);
    pyju_svecset(pyju_typename_type->types, 1, pyju_module_type);
    pyju_svecset(pyju_typename_type->types, 3, pyju_voidpointer_type);
    pyju_svecset(pyju_typename_type->types, 4, pyju_voidpointer_type);
    pyju_svecset(pyju_typename_type->types, 5, pyju_type_type);
    pyju_svecset(pyju_typename_type->types, 10, pyju_long_type);
    pyju_svecset(pyju_typename_type->types, 11, pyju_int32_type);
    pyju_svecset(pyju_typename_type->types, 12, pyju_uint8_type);
    pyju_svecset(pyju_methtable_type->types, 4, pyju_long_type);
    pyju_svecset(pyju_methtable_type->types, 6, pyju_module_type);
    pyju_svecset(pyju_methtable_type->types, 7, pyju_array_any_type);
    pyju_svecset(pyju_methtable_type->types, 8, pyju_long_type); // voidpointer
    pyju_svecset(pyju_methtable_type->types, 9, pyju_long_type); // uint32_t plus alignment
    pyju_svecset(pyju_methtable_type->types, 10, pyju_uint8_type);
    pyju_svecset(pyju_methtable_type->types, 11, pyju_uint8_type);
    pyju_svecset(pyju_method_type->types, 12, pyju_method_instance_type);
    pyju_svecset(pyju_method_instance_type->types, 6, pyju_code_instance_type);
    pyju_svecset(pyju_code_instance_type->types, 12, pyju_voidpointer_type);
    pyju_svecset(pyju_code_instance_type->types, 13, pyju_voidpointer_type);

    pyju_compute_field_offsets(pyju_datatype_type);
    pyju_compute_field_offsets(pyju_typename_type);
    pyju_compute_field_offsets(pyju_uniontype_type);
    pyju_compute_field_offsets(pyju_tvar_type);
    pyju_compute_field_offsets(pyju_methtable_type);
    pyju_compute_field_offsets(pyju_module_type);
    pyju_compute_field_offsets(pyju_method_instance_type);
    pyju_compute_field_offsets(pyju_code_instance_type);
    pyju_compute_field_offsets(pyju_unionall_type);
    pyju_compute_field_offsets(pyju_simplevector_type);
    pyju_compute_field_offsets(pyju_symbol_type);

    // override the preferred layout for a couple types
    pyju_lineinfonode_type->name->mayinlinealloc = 0; // FIXME: assumed to be a pointer by codegen
    // It seems like we probably usually end up needing the box for kinds (used in an Any context)--but is that true?
    pyju_uniontype_type->name->mayinlinealloc = 0;
    pyju_unionall_type->name->mayinlinealloc = 0;
}

#ifdef __cplusplus
}   // extern "C"
#endif