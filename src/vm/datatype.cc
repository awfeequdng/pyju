#include "pyju_internal.h"

/*
  defining DataTypes
  basic operations on struct and bits values
*/


#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "pyju_gcext.h"
#include "support/hashing.h"

#ifdef __cplusplus
extern "C" {
#endif

// allocating TypeNames -----------------------------------------------------------

static int is10digit(char c) PYJU_NOTSAFEPOINT
{
    return (c >= '0' && c <= '9');
}

static PyjuSym_t *pyju_demangle_typename(PyjuSym_t *s) PYJU_NOTSAFEPOINT
{
    char *n = pyju_symbol_name(s);
    if (n[0] != '#')
        return s;
    char *end = strrchr(n, '#');
    int32_t len;
    if (end == n || end == n+1)
        len = strlen(n) - 1;
    else
        len = (end-n) - 1;  // extract `f` from `#f#...`
    if (is10digit(n[1]))
        return _pyju_symbol(n, len+1);
    return _pyju_symbol(&n[1], len);
}

PYJU_DLLEXPORT PyjuMethTable_t *pyju_new_method_table(PyjuSym_t *name, PyjuModule_t *module) {
    PyjuTask_t *ct = pyju_current_task;
    PyjuMethTable_t *mt = (PyjuMethTable_t *)pyju_gc_alloc(ct->ptls, sizeof(PyjuMethTable_t), pyju_methtable_type);
    mt->name = pyju_demangle_typename(name);
    mt->module = module;
    pyju_atomic_store_relaxed(&mt->defs, pyju_nothing);
    pyju_atomic_store_relaxed(&mt->leafcache, (PyjuArray_t*)pyju_an_empty_vec_any);
    pyju_atomic_store_relaxed(&mt->cache, pyju_nothing);
    mt->max_args = 0;
    mt->kwsorter = NULL;
    mt->backedges = NULL;
    PYJU_MUTEX_INIT(&mt->writelock);
    mt->offs = 0;
    mt->frozen = 0;
    return mt;
}

PYJU_DLLEXPORT PyjuTypeName_t *pyju_new_typename_in(PyjuSym_t *name, PyjuModule_t *module, int abstract, int mutabl) {
    PyjuTask_t *ct = pyju_current_task;
    PyjuTypeName_t *tn = (PyjuTypeName_t*)pyju_gc_alloc(ct->ptls, sizeof(PyjuTypeName_t), pyju_typename_type);
    tn->name = name;
    tn->module = module;
    tn->wrapper = NULL;
    pyju_atomic_store_relaxed(&tn->cache, pyju_emptysvec);
    pyju_atomic_store_relaxed(&tn->linearcache, pyju_emptysvec);
    tn->names = NULL;
    tn->hash = bitmix(bitmix(module ? module->build_id : 0, name->hash), 0xa1ada1da);
    tn->abstract = abstract;
    tn->mutabl = mutabl;
    tn->mayinlinealloc = 0;
    tn->mt = NULL;
    tn->partial = NULL;
    tn->atomicfields = NULL;
    tn->constfields = NULL;
    return tn;
}


// allocating DataTypes -----------------------------------------------------------

static int is_anonfn_typename(char *name)
{
    if (name[0] != '#' || name[1] == '#')
        return 0;
    char *other = strrchr(name, '#');
    return other > &name[1] && is10digit(other[1]);
}

PYJU_DLLEXPORT PyjuDataType_t *pyju_new_datatype(
        PyjuSym_t *name,
        PyjuModule_t *module,
        PyjuDataType_t *super,
        PyjuSvec_t *parameters,
        PyjuSvec_t *fnames,
        PyjuSvec_t *ftypes,
        PyjuSvec_t *fattrs,
        int abstract, int mutabl,
        int ninitialized)
{
    PyjuDataType_t *t = NULL;
    PyjuTypeName_t *tn = NULL;
    PYJU_GC_PUSH2(&t, &tn);

    assert(parameters);

    // init enough before possibly calling pyju_new_typename_in
    t = pyju_new_uninitialized_datatype();
    t->super = super;
    if (super != NULL) pyju_gc_wb(t, t->super);
    t->parameters = parameters;
    pyju_gc_wb(t, t->parameters);
    t->types = ftypes;
    if (ftypes != NULL) pyju_gc_wb(t, t->types);
    t->size = 0;

    t->name = NULL;
    if (pyju_is_typename(name)) {
        // This code-path is used by the Serialization module to bypass normal expectations
        tn = (PyjuTypeName_t*)name;
        tn->abstract = abstract;
        tn->mutabl = mutabl;
    }
    else {
        tn = pyju_new_typename_in((PyjuSym_t*)name, module, abstract, mutabl);
        if (super == pyju_function_type || super == pyju_builtin_type || is_anonfn_typename(pyju_symbol_name(name))) {
            // Callable objects (including compiler-generated closures) get independent method tables
            // as an optimization
            tn->mt = pyju_new_method_table(name, module);
            pyju_gc_wb(tn, tn->mt);
            if (pyju_svec_len(parameters) == 0 && !abstract)
                tn->mt->offs = 1;
        }
        else {
            // Everything else, gets to use the unified table
            tn->mt = pyju_nonfunction_mt;
        }
    }
    t->name = tn;
    pyju_gc_wb(t, t->name);
    t->name->names = fnames;
    pyju_gc_wb(t->name, t->name->names);
    tn->n_uninitialized = pyju_svec_len(fnames) - ninitialized;

    uint32_t *volatile atomicfields = NULL;
    uint32_t *volatile constfields = NULL;
    // int i;
    // JL_TRY {
    //     for (i = 0; i + 1 < pyju_svec_len(fattrs); i += 2) {
    //         PyjuValue_t *fldi = pyju_svecref(fattrs, i);
    //         PyjuSym_t *attr = (PyjuSym_t*)pyju_svecref(fattrs, i + 1);
    //         PYJU_TYPECHK(typeassert, long, fldi);
    //         PYJU_TYPECHK(typeassert, symbol, (jl_value_t*)attr);
    //         size_t fldn = jl_unbox_long(fldi);
    //         if (fldn < 1 || fldn > jl_svec_len(fnames))
    //             jl_errorf("invalid field attribute %lld", (long long)fldn);
    //         fldn--;
    //         if (attr == jl_atomic_sym) {
    //             if (!mutabl)
    //                 jl_errorf("invalid field attribute atomic for immutable struct");
    //             if (atomicfields == NULL) {
    //                 size_t nb = (jl_svec_len(fnames) + 31) / 32 * sizeof(uint32_t);
    //                 atomicfields = (uint32_t*)malloc_s(nb);
    //                 memset(atomicfields, 0, nb);
    //             }
    //             atomicfields[fldn / 32] |= 1 << (fldn % 32);
    //         }
    //         else if (attr == jl_const_sym) {
    //             if (!mutabl)
    //                 jl_errorf("invalid field attribute const for immutable struct");
    //             if (constfields == NULL) {
    //                 size_t nb = (jl_svec_len(fnames) + 31) / 32 * sizeof(uint32_t);
    //                 constfields = (uint32_t*)malloc_s(nb);
    //                 memset(constfields, 0, nb);
    //             }
    //             constfields[fldn / 32] |= 1 << (fldn % 32);
    //         }
    //         else {
    //             jl_errorf("invalid field attribute %s", jl_symbol_name(attr));
    //         }
    //     }
    // }
    // JL_CATCH {
    //     free(atomicfields);
    //     free(constfields);
    //     jl_rethrow();
    // }
    // tn->atomicfields = atomicfields;
    // tn->constfields = constfields;

    // if (t->name->wrapper == NULL) {
    //     t->name->wrapper = (PyjuValue_t*)t;
    //     pyju_gc_wb(t->name, t);
    //     int i, np = pyju_svec_len(parameters);
    //     for (i = np - 1; i >= 0; i--) {
    //         t->name->wrapper = pyju_new_struct(pyju_unionall_type, pyju_svecref(parameters, i), t->name->wrapper);
    //         pyju_gc_wb(t->name, t->name->wrapper);
    //     }
    //     if (!mutabl && !abstract && ftypes != NULL)
    //         tn->mayinlinealloc = 1;
    // }
    // pyju_precompute_memoized_dt(t, 0);

    // if (!abstract && t->types != NULL)
    //     pyju_compute_field_offsets(t);

    PYJU_GC_POP();
    return t;
}

PyjuDataType_t *pyju_new_abstracttype(PyjuValue_t *name, PyjuModule_t *module, PyjuDataType_t *super, PyjuSvec_t *parameters)
{
    return pyju_new_datatype((PyjuSym_t*)name, module, super, parameters, pyju_emptysvec, pyju_emptysvec, pyju_emptysvec, 1, 0, 0);
}

PyjuDataType_t *pyju_new_uninitialized_datatype(void) {
    PyjuTask_t *ct = pyju_current_task;
    PyjuDataType_t *t = (PyjuDataType_t*)pyju_gc_alloc(ct->ptls, sizeof(PyjuDataType_t), pyju_datatype_type);
    t->hash = 0;
    t->hasfreetypevars = 0;
    t->isdispatchtuple = 0;
    t->isbitstype = 0;
    t->zeroinit = 0;
    t->has_concrete_subtype = 1;
    t->cached_by_hash = 0;
    t->name = NULL;
    t->super = NULL;
    t->parameters = NULL;
    t->layout = NULL;
    t->types = NULL;
    t->instance = NULL;

    return t;
}


#ifdef __cplusplus
} // extern "C"
#endif