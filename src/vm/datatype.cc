#include "pyju_internal.h"

/*
  defining DataTypes
  basic operations on struct and bits values
*/


#include <cstdint>
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
    // PYJU_TRY {
    //     for (i = 0; i + 1 < pyju_svec_len(fattrs); i += 2) {
    //         PyjuValue_t *fldi = pyju_svecref(fattrs, i);
    //         PyjuSym_t *attr = (PyjuSym_t*)pyju_svecref(fattrs, i + 1);
    //         PYJU_TYPECHK(typeassert, long, fldi);
    //         PYJU_TYPECHK(typeassert, symbol, (PyjuValue_t*)attr);
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
    // PYJU_CATCH {
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

#define PERMBOXN_FUNC(nb, nw)   \
    PyjuValue_t *pyju_permbox##nb(PyjuDataType_t *t, int##nb##_t x) \
    {   /* NOTE: t must be a concrete isbits datatype */ \
        assert(pyju_datatype_size(t) == sizeof(x)); \
        PyjuValue_t *v = pyju_gc_permobj(nw * sizeof(void*) + PYJU_TV_SIZE, t); \
        *(int##nb##_t*) pyju_data_ptr(v) = x; \
        return v;   \
    }

PERMBOXN_FUNC(8, 1)
PERMBOXN_FUNC(16, 1)
PERMBOXN_FUNC(32, 1)
#ifdef _P64
PERMBOXN_FUNC(64, 1)
#else
PERMBOXN_FUNC(64, 2)
#endif

#define UNBOX_FUNC(pyju_type, c_type)   \
    PYJU_DLLEXPORT c_type pyju_unbox_##pyju_type(PyjuValue_t *v)    \
    {   \
        assert(pyju_is_primitivetype(pyju_typeof(v)));  \
        assert(pyju_datatype_size(pyju_typeof(v)) == sizeof(c_type));   \
        return *(c_type*)pyju_data_ptr(v);    \
    }

UNBOX_FUNC(int8,   int8_t)
UNBOX_FUNC(uint8,  uint8_t)
UNBOX_FUNC(int16,  int16_t)
UNBOX_FUNC(uint16, uint16_t)
UNBOX_FUNC(int32,  int32_t)
UNBOX_FUNC(uint32, uint32_t)
UNBOX_FUNC(int64,  int64_t)
UNBOX_FUNC(uint64, uint64_t)
UNBOX_FUNC(bool,   int8_t)
UNBOX_FUNC(float32, float)
UNBOX_FUNC(float64, double)
UNBOX_FUNC(voidpointer, void*)
UNBOX_FUNC(uint8pointer, uint8_t*)

#define BOX_FUNC(typ, c_type, pfx, nw)  \
    PYJU_DLLEXPORT PyjuValue_t *pfx##_##typ(c_type x) \
    {   \
        PyjuTask_t *ct = pyju_current_task; \
        PyjuValue_t *v = pyju_gc_alloc(ct->ptls, nw * sizeof(void*) + PYJU_TV_SIZE, pyju_##typ##_type); \
        *(c_type*)pyju_data_ptr(v) = x; \
        return v;   \
    }

BOX_FUNC(float32, float,  pyju_box, 1)
BOX_FUNC(voidpointer, void*,  pyju_box, 1)
BOX_FUNC(uint8pointer, uint8_t*,  pyju_box, 1)
#ifdef _P64
BOX_FUNC(float64, double, pyju_box, 1)
#else
BOX_FUNC(float64, double, pyju_box, 2)
#endif

#define NBOX_C 1024

#define SIBOX_FUNC(typ, c_type, nw)   \
    static PyjuValue_t *boxed_##typ##_cache[NBOX_C];    \
    PYJU_DLLEXPORT PyjuValue_t * pyju_box_##typ(c_type x) \
    {   \
        PyjuTask_t *ct = pyju_current_task; \
        c_type idx = x + NBOX_C / 2;   \
        if ((u##c_type)idx < (u##c_type)NBOX_C) \
            return boxed_##typ##_cache[idx]; \
        PyjuValue_t *v = pyju_gc_alloc(ct->ptls, nw * sizeof(void*) + PYJU_TV_SIZE, pyju_##typ##_type); \
        *(c_type*)pyju_data_ptr(v) = x; \
        return v; \
    }
#define UIBOX_FUNC(typ, c_type, nw) \
    static PyjuValue_t *boxed_##typ##_cache[NBOX_C]; \
    PYJU_DLLEXPORT PyjuValue_t *pyju_box_##typ(c_type x) \
    {   \
        PyjuTask_t *ct = pyju_current_task; \
        if (x < NBOX_C) \
            return boxed_##typ##_cache[x]; \
        PyjuValue_t *v = pyju_gc_alloc(ct->ptls, nw * sizeof(void*) + PYJU_TV_SIZE, pyju_##typ##_type); \
        *(c_type*)pyju_data_ptr(v) = x; \
        return v; \
    }

SIBOX_FUNC(int16,  int16_t, 1)
SIBOX_FUNC(int32,  int32_t, 1)
UIBOX_FUNC(uint16, uint16_t, 1)
UIBOX_FUNC(uint32, uint32_t, 1)
UIBOX_FUNC(ssavalue, size_t, 1)
UIBOX_FUNC(slotnumber, size_t, 1)
#ifdef _P64
SIBOX_FUNC(int64,  int64_t, 1)
UIBOX_FUNC(uint64, uint64_t, 1)
#else
SIBOX_FUNC(int64,  int64_t, 2)
UIBOX_FUNC(uint64, uint64_t, 2)
#endif

static PyjuValue_t *boxed_char_cache[128];
PYJU_DLLEXPORT PyjuValue_t *pyju_box_char(uint32_t x)
{
    PyjuTask_t *ct = pyju_current_task;
    // TODO: 为什么要翻转字节？？？
    uint32_t u = bswap_32(x);
    if (u < 128)
        return boxed_char_cache[(uint8_t)u];
    PyjuValue_t *v = pyju_gc_alloc(ct->ptls, sizeof(void*) + PYJU_TV_SIZE, pyju_char_type);
    *(uint32_t*)pyju_data_ptr(v) = x;
    return v;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_boxed_int8_cache[256];
PYJU_DLLEXPORT PyjuValue_t *pyju_boxed_int8(int8_t x)
{
    return pyju_boxed_int8_cache[(uint8_t)x];
}
PYJU_DLLEXPORT PyjuValue_t *pyju_boxed_uint8_cache[256];
PYJU_DLLEXPORT PyjuValue_t *pyju_box_uint8(uint8_t x)
{
    return pyju_boxed_uint8_cache[x];
}

void pyju_init_int32_int64_cache(void)
{
    int64_t i;
    for (i = 0; i < NBOX_C; i++) {
        boxed_int32_cache[i] = pyju_permbox32(pyju_int32_type, i - NBOX_C/2);
        boxed_int64_cache[i] = pyju_permbox64(pyju_int64_type, i - NBOX_C/2);
#ifdef _P64
        boxed_ssavalue_cache[i] = pyju_permbox64(pyju_ssavalue_type, i);
        boxed_slotnumber_cache[i] = pyju_permbox64(pyju_slotnumber_type, i);
#else
        boxed_ssavalue_cache[i] = jl_permbox32(jl_ssavalue_type, i);
        boxed_slotnumber_cache[i] = jl_permbox32(jl_slotnumber_type, i);
#endif
    }
    for (i = 0; i < 256; i++) {
        pyju_boxed_uint8_cache[i] = pyju_permbox8(pyju_uint8_type, i);
    }
}

void pyju_init_box_caches(void)
{
    int64_t i;
    for (i = 0; i < 128; i++) {
        // TODO: 为什么放到高8位上去？
        boxed_char_cache[i] = pyju_permbox32(pyju_char_type, i << 24);
    }
    for (i = 0; i < 256; i++) {
        pyju_boxed_int8_cache[i] = pyju_permbox8(pyju_int8_type, i);
    }
    for (i = 0; i < NBOX_C; i++) {
        boxed_int16_cache[i]  = pyju_permbox16(pyju_int16_type, i-NBOX_C/2);
        boxed_uint16_cache[i] = pyju_permbox16(pyju_uint16_type, i);
        boxed_uint32_cache[i] = pyju_permbox32(pyju_uint32_type, i);
        boxed_uint64_cache[i] = pyju_permbox64(pyju_uint64_type, i);
    }
}

PYJU_DLLEXPORT PyjuValue_t *pyju_box_bool(int8_t x)
{
    if (x)
        return pyju_true;
    return pyju_false;
}

#ifdef __cplusplus
} // extern "C"
#endif