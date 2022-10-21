#include "pyju_internal.h"

/*
  defining DataTypes
  basic operations on struct and bits values
*/


#include <cstddef>
#include <cstdint>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include "pyju_atomics.h"
#include "pyju_locks.h"
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "pyju_gcext.h"
#include "pyju_threads.h"
#include "support/dtypes.h"
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

static PyjuDataTypeLayout_t *pyju_get_layout(uint32_t nfields,
                                             uint32_t npointers,
                                             uint32_t alignment,
                                             int haspadding,
                                             PyjuFieldDesc32_t desc[],
                                             uint32_t pointers[]) PYJU_NOTSAFEPOINT
{
    assert(alignment); // should have been verified by caller

    // compute the smallest fielddesc type that can hold the layout description
    int fielddesc_type = 0;
    if (nfields > 0) {
        uint32_t max_size = 0;
        uint32_t max_offset = desc[nfields - 1].offset;
        if (npointers > 0 && pointers[npointers - 1] > max_offset)
            max_offset = pointers[npointers - 1];
        for (size_t i = 0; i < nfields; i++) {
            if (desc[i].size > max_size)
                max_size = desc[i].size;
        }
        PyjuFieldDesc8_t maxdesc8 = { 0, (uint8_t)max_size, (uint8_t)max_offset };
        PyjuFieldDesc16_t maxdesc16 = { 0, (uint16_t)max_size, (uint16_t)max_offset };
        PyjuFieldDesc32_t maxdesc32 = { 0, max_size, max_offset };
        if (maxdesc8.size != max_size || maxdesc8.offset != max_offset) {
            fielddesc_type = 1;
            if (maxdesc16.size != max_size || maxdesc16.offset != max_offset) {
                fielddesc_type = 2;
                if (maxdesc32.size != max_size || maxdesc32.offset != max_offset) {
                    assert(0); // should have been verified by caller
                }
            }
        }
    }

    // allocate a new descriptor
    // TODO: lots of these are the same--take advantage of the fact these are immutable to combine them
    uint32_t fielddesc_size = pyju_fielddesc_size(fielddesc_type);
    PyjuDataTypeLayout_t *flddesc = (PyjuDataTypeLayout_t*)pyju_gc_perm_alloc(
                sizeof(PyjuDataTypeLayout_t) + nfields * fielddesc_size + (npointers << fielddesc_type),
                0, 4, 0);
    flddesc->nfields = nfields;
    flddesc->alignment = alignment;
    flddesc->haspadding = haspadding;
    flddesc->fielddesc_type = fielddesc_type;
    flddesc->npointers = npointers;
    flddesc->first_ptr = (npointers > 0 ? pointers[0] : -1);

    // fill out the fields of the new descriptor
    PyjuFieldDesc8_t* desc8 = (PyjuFieldDesc8_t*)pyju_dt_layout_fields(flddesc);
    PyjuFieldDesc16_t* desc16 = (PyjuFieldDesc16_t*)pyju_dt_layout_fields(flddesc);
    PyjuFieldDesc32_t* desc32 = (PyjuFieldDesc32_t*)pyju_dt_layout_fields(flddesc);
    for (size_t i = 0; i < nfields; i++) {
        if (fielddesc_type == 0) {
            desc8[i].offset = desc[i].offset;
            desc8[i].size = desc[i].size;
            desc8[i].isptr = desc[i].isptr;
        }
        else if (fielddesc_type == 1) {
            desc16[i].offset = desc[i].offset;
            desc16[i].size = desc[i].size;
            desc16[i].isptr = desc[i].isptr;
        }
        else {
            desc32[i].offset = desc[i].offset;
            desc32[i].size = desc[i].size;
            desc32[i].isptr = desc[i].isptr;
        }
    }
    uint8_t* ptrs8 = (uint8_t*)pyju_dt_layout_ptrs(flddesc);
    uint16_t* ptrs16 = (uint16_t*)pyju_dt_layout_ptrs(flddesc);
    uint32_t* ptrs32 = (uint32_t*)pyju_dt_layout_ptrs(flddesc);
    for (size_t i = 0; i < npointers; i++) {
        if (fielddesc_type == 0) {
            ptrs8[i] = pointers[i];
        }
        else if (fielddesc_type == 1) {
            ptrs16[i] = pointers[i];
        }
        else {
            ptrs32[i] = pointers[i];
        }
    }
    return flddesc;
}

PYJU_DLLEXPORT PyjuMethTable_t *pyju_new_method_table(PyjuSym_t *name, PyjuModule_t *module) {
    PyjuTask_t *ct = pyju_current_task;
    PyjuMethTable_t *mt = (PyjuMethTable_t *)pyju_gc_alloc(ct->ptls, sizeof(PyjuMethTable_t), pyju_methtable_type);
    mt->name = pyju_demangle_typename(name);
    mt->module = module;
    pyju_atomic_store_relaxed(&mt->defs, pyju_nothing);
    // pyju_an_empty_vec_any可能还没有初始化
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

// return whether all concrete subtypes of this type have the same layout
int pyju_struct_try_layout(PyjuDataType_t *dt)
{
    if (dt->layout)
        return 1;
    else if (!pyju_has_fixed_layout(dt))
        return 0;
    // jl_has_fixed_layout also ensured that dt->types is assigned now
    pyju_compute_field_offsets(dt);
    assert(dt->layout);
    return 1;
}

int pyju_datatype_isinlinealloc(PyjuDataType_t *ty, int pointerfree)
{
    if (ty->name->mayinlinealloc && pyju_struct_try_layout(ty)) {
        if (ty->layout->npointers > 0) {
            if (pointerfree)
                return 0;
            if (ty->name->n_uninitialized != 0)
                return 0;
            if (ty->layout->fielddesc_type > 1) // GC only implements support for 8 and 16 (not array32)
                return 0;
        }
        return 1;
    }
    return 0;
}

static unsigned union_isinlinable(PyjuValue_t *ty, int pointerfree, size_t *nbytes, size_t *align, int asfield)
{
    if (pyju_is_uniontype(ty)) {
        unsigned na = union_isinlinable(((PyjuUnionType_t*)ty)->a, 1, nbytes, align, asfield);
        if (na == 0)
            return 0;
        unsigned nb = union_isinlinable(((PyjuUnionType_t*)ty)->b, 1, nbytes, align, asfield);
        if (nb == 0)
            return 0;
        return na + nb;
    }
    if (pyju_is_datatype(ty) && pyju_datatype_isinlinealloc((PyjuDataType_t*)ty, pointerfree)) {
        size_t sz = pyju_datatype_size(ty);
        size_t al = pyju_datatype_align(ty);
        // primitive types in struct slots need their sizes aligned. issue #37974
        if (asfield && pyju_is_primitivetype(ty))
            sz = LLT_ALIGN(sz, al);
        if (*nbytes < sz)
            *nbytes = sz;
        if (*align < al)
            *align = al;
        return 1;
    }
    return 0;
}

int pyju_uniontype_size(PyjuValue_t *ty, size_t *sz)
{
    size_t al = 0;
    return union_isinlinable(ty, 0, sz, &al, 0) != 0;
}

PYJU_DLLEXPORT int pyju_islayout_inline(PyjuValue_t *eltype, size_t *fsz, size_t *al)
{
    unsigned countbits = union_isinlinable(eltype, 0, fsz, al, 1);
    return (countbits > 0 && countbits < 127) ? countbits : 0;
}

PYJU_DLLEXPORT int pyju_stored_inline(PyjuValue_t *eltype)
{
    size_t fsz = 0, al = 0;
    return pyju_islayout_inline(eltype, &fsz, &al);
}

// whether instances of this type can use pointer comparison for `===`
int pyju_pointer_egal(PyjuValue_t *t)
{
    if (t == (PyjuValue_t*)pyju_any_type)
        return 0; // when setting up the initial types, pyju_is_type_type gets confused about this
    if (t == (PyjuValue_t*)pyju_symbol_type)
        return 1;
    if (t == (PyjuValue_t*)pyju_bool_type)
        return 1;
    if (pyju_is_mutable_datatype(pyju_unwrap_unionall(t)) && // excludes abstract types
        t != (PyjuValue_t*)pyju_string_type && // technically mutable, but compared by contents
        t != (PyjuValue_t*)pyju_simplevector_type &&
        !pyju_is_kind(t))
        return 1;
    if ((pyju_is_datatype(t) && pyju_is_datatype_singleton((PyjuDataType_t*)t)) ||
        t == (PyjuValue_t*)pyju_typeofbottom_type->super)
        return 1;
    if (pyju_is_type_type(t) && pyju_is_datatype(pyju_tparam0(t))) {
        // need to use typeseq for most types
        // but can compare some types by pointer
        PyjuDataType_t *dt = (PyjuDataType_t*)pyju_tparam0(t);
        // `Core.TypeofBottom` and `Type{Union{}}` are used interchangeably
        // with different pointer values even though `Core.TypeofBottom` is a concrete type.
        // See `Core.Compiler.hasuniquerep`
        if (dt != pyju_typeofbottom_type &&
            (dt->isconcretetype || pyju_svec_len(dt->parameters) == 0)) {
            // Concrete types have unique pointer values
            // If the type has zero type parameters it'll also have only one possible
            // pointer value.
            return 1;
        }
    }
    if (pyju_is_uniontype(t)) {
        PyjuUnionType_t *u = (PyjuUnionType_t*)t;
        return pyju_pointer_egal(u->a) && pyju_pointer_egal(u->b);
    }
    return 0;
}


static void throw_ovf(int should_malloc, void *desc, PyjuDataType_t* st, int offset)
{
    if (should_malloc)
        free(desc);
    pyju_errorf("type %s has field offset %d that exceeds the page size", pyju_symbol_name(st->name->name), offset);
}

STATIC_INLINE int pyju_is_datatype_make_singleton(PyjuDataType_t *d) PYJU_NOTSAFEPOINT
{
    return (!d->name->abstract && pyju_datatype_size(d) == 0 && d != pyju_symbol_type && d->name != pyju_array_typename &&
            d->isconcretetype && !d->name->mutabl);
}

STATIC_INLINE void pyju_maybe_allocate_singleton_instance(PyjuDataType_t *st) PYJU_NOTSAFEPOINT
{
    if (pyju_is_datatype_make_singleton(st)) {
        // It's possible for st to already have an ->instance if it was redefined
        if (!st->instance)
            st->instance = pyju_gc_permobj(0 + PYJU_TV_SIZE, st);
    }
}

static int is_anonfn_typename(char *name)
{
    if (name[0] != '#' || name[1] == '#')
        return 0;
    char *other = strrchr(name, '#');
    return other > &name[1] && is10digit(other[1]);
}

void pyju_compute_field_offsets(PyjuDataType_t *st)
{
    const uint64_t max_offset = (((uint64_t)1) << 32) - 1;
    const uint64_t max_size = max_offset >> 1;

    if (st->name->wrapper == NULL)
        return; // we got called too early--we'll be back
    PyjuDataType_t *w = (PyjuDataType_t*)pyju_unwrap_unionall(st->name->wrapper);
    if (st == w && st->layout) {
        // this check allows us to force re-computation of the layout for some types during init
        st->layout = NULL;
        st->size = 0;
        st->zeroinit = 0;
        st->has_concrete_subtype = 1;
    }
    int isbitstype = st->isconcretetype && st->name->mayinlinealloc;
    // If layout doesn't depend on type parameters, it's stored in st->name->wrapper
    // and reused by all subtypes.
    if (w->layout) {
        st->layout = w->layout;
        st->size = w->size;
        st->zeroinit = w->zeroinit;
        st->has_concrete_subtype = w->has_concrete_subtype;
        if (!pyju_is_layout_opaque(st->layout)) {
            st->isbitstype = isbitstype && st->layout->npointers == 0;
            pyju_maybe_allocate_singleton_instance(st);
        }
        return;
    }
    assert(st->types && w->types);
    size_t i, nfields = pyju_svec_len(st->types);
    assert(st->name->n_uninitialized <= nfields);
    if (nfields == 0) {
        // if we have no fields, we can trivially skip the rest
        if (st == pyju_symbol_type || st == pyju_string_type) {
            // opaque layout - heap-allocated blob
            static const PyjuDataTypeLayout_t opaque_byte_layout = {0, 1, -1, 1, 0, 0};
            st->layout = &opaque_byte_layout;
            return;
        } else if (st == pyju_simplevector_type || st == pyju_module_type || st->name == pyju_array_typename) {
            static const PyjuDataTypeLayout_t opaque_ptr_layout = {0, 1, -1, sizeof(void*), 0, 0};
            st->layout = &opaque_ptr_layout;
            return;
        } else {
            // reuse the same layout for all singletons
            static const PyjuDataTypeLayout_t singleton_layout = {0, 0, -1, 1, 0, 0};
            st->layout = &singleton_layout;
        }
    } else {
        for (i = 0; st->has_concrete_subtype && i < nfields - st->name->n_uninitialized; i++) {
            PyjuValue_t *fld = pyju_svecref(st->types, i);
            if (fld == pyju_bottom_type)
                st->has_concrete_subtype = 0;
            else
                st->has_concrete_subtype = !pyju_is_datatype(fld) || ((PyjuDataType_t*)fld)->has_concrete_subtype;
        }
        // compute layout for the wrapper object if the field types have no free variables
        if (!st->isconcretetype && !pyju_has_fixed_layout(st)) {
            assert(st == w); // otherwise caller should not have requested this layout
            return;
        }
    }

    for (i = 0; isbitstype && i < nfields; i++) {
        PyjuValue_t *fld = pyju_field_type(st, i);
        isbitstype = pyju_isbits(fld);
    }

    // if we didn't reuse the layout above, compute it now
    if (st->layout == NULL) {
        size_t descsz = nfields * sizeof(PyjuFieldDesc32_t);
        PyjuFieldDesc32_t *desc;
        uint32_t *pointers;
        int should_malloc = descsz >= pyju_page_size;
        if (should_malloc)
            desc = (PyjuFieldDesc32_t*)malloc_s(descsz);
        else
            desc = (PyjuFieldDesc32_t*)alloca(descsz);
        size_t sz = 0;
        size_t alignm = 1;
        int zeroinit = 0;
        int haspadding = 0;
        int homogeneous = 1;
        int needlock = 0;
        uint32_t npointers = 0;
        PyjuValue_t *firstty = pyju_field_type(st, 0);
        for (i = 0; i < nfields; i++) {
            PyjuValue_t *fld = pyju_field_type(st, i);
            int isatomic = pyju_field_isatomic(st, i);
            size_t fsz = 0, al = 1;
            if (pyju_islayout_inline(fld, &fsz, &al) && (!isatomic || pyju_is_datatype(fld))) {
                if (__unlikely(fsz > max_size))
                    // Should never happen
                    throw_ovf(should_malloc, desc, st, fsz);
                desc[i].isptr = 0;
                if (pyju_is_uniontype(fld)) {
                    haspadding = 1;
                    fsz += 1; // selector byte
                    zeroinit = 1;
                } else {
                    uint32_t fld_npointers = ((PyjuDataType_t *)fld)->layout->npointers;
                    if (((PyjuDataType_t*)fld)->layout->haspadding)
                        haspadding = 1;
                    if (i >= nfields - st->name->n_uninitialized && fld_npointers && fld_npointers * sizeof(void*) != fsz) {
                        // field may be undef (may be uninitialized)
                        haspadding = 1;
                    }
                    if (!zeroinit)
                        zeroinit = ((PyjuDataType_t*)fld)->zeroinit;
                    npointers += fld_npointers;
                }
            } else {
                fsz = sizeof(void*);
                if (fsz > MAX_ALIGN)
                    fsz = MAX_ALIGN;
                al = fsz;
                desc[i].isptr = 1;
                zeroinit = 1;
                npointers++;
                if (!pyju_pointer_egal(fld)) {
                    // this some what poorly named flag says whether some of the bits can be ono-unique
                    haspadding = 1;
                }
            }
            if (isatomic && fsz > MAX_ATOMIC_SIZE)
                needlock = 1;
            if (isatomic && fsz <= MAX_ATOMIC_SIZE)
                al = fsz = next_power_of_two(fsz);
            if (al != 0) {
                size_t alsz = LLT_ALIGN(sz, al);
                if (alsz != sz)
                    haspadding = 1;
                sz = alsz;
                if (al > alignm)
                    alignm = al;
            }
            homogeneous &= firstty == fld;
            desc[i].offset = sz;
            desc[i].size = fsz;
            if (__unlikely(max_offset - sz < fsz))
                throw_ovf(should_malloc, desc, st, sz);
            sz += fsz;
        }
        if (needlock) {
            size_t offset = LLT_ALIGN(sizeof(PyjuMutex_t), alignm);
            for (i = 0; i < nfields; i++) {
                desc[i].offset += offset;
            }
            if (__unlikely(max_offset - sz < offset))
                throw_ovf(should_malloc, desc, st, sz);
            sz += offset;
            haspadding = 1;
        }
        if (homogeneous && pyju_is_tuple_type(st)) {
            // Some tuples become LLVM vectors with stronger alignment than what was calculated above.
            unsigned al = pyju_special_vector_alignment(nfields, firstty);
            assert(al % alignm == 0);
            if (al > alignm)
                alignm = al;
        }
        st->size = LLT_ALIGN(sz, alignm);
        if (st->size > sz)
            haspadding = 1;
        if (should_malloc && npointers)
            pointers = (uint32_t*)malloc_s(npointers * sizeof(uint32_t));
        else
            pointers = (uint32_t*)alloca(npointers * sizeof(uint32_t));
        size_t ptr_i = 0;
        for (i = 0; i < nfields; i++) {
            PyjuValue_t *fld = pyju_field_type(st, i);
            uint32_t offset = desc[i].offset / sizeof(PyjuValue_t**);
            if (desc[i].isptr)
                pointers[ptr_i++] = offset;
            else if (pyju_is_datatype(fld)) {
                int j, npointers = ((PyjuDataType_t*)fld)->layout->npointers;
                for (j = 0; j < npointers; j++) {
                    pointers[ptr_i++] = offset + pyju_ptr_offset((PyjuDataType_t*)fld, j);
                }
            }
        }
        assert(ptr_i == npointers);
        st->layout = pyju_get_layout(nfields, npointers, alignm, haspadding, desc, pointers);
        if (should_malloc) {
            free(desc);
            if (npointers)
                free(pointers);
        }
        st->zeroinit = zeroinit;
    }

    // now finish deciding if this instantiation qualifies for special properties
    assert(!isbitstype || st->layout->npointers == 0); // the definition of isbits
    st->isbitstype = isbitstype;
    pyju_maybe_allocate_singleton_instance(st);
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
    size_t i;
    PYJU_TRY {
        for (i = 0; i + 1 < pyju_svec_len(fattrs); i += 2) {
            PyjuValue_t *fldi = pyju_svecref(fattrs, i);
            PyjuSym_t *attr = (PyjuSym_t*)pyju_svecref(fattrs, i + 1);
            PYJU_TYPECHK(typeassert, long, fldi);
            PYJU_TYPECHK(typeassert, symbol, (PyjuValue_t*)attr);
            size_t fldn = pyju_unbox_long(fldi);
            if (fldn < 1 || fldn > pyju_svec_len(fnames))
                pyju_errorf("invalid field attribute %lld", (long long)fldn);
            fldn--;
            if (attr == pyju_atomic_sym) {
                if (!mutabl)
                    pyju_errorf("invalid field attribute atomic for immutable struct");
                if (atomicfields == NULL) {
                    size_t nb = (pyju_svec_len(fnames) + 31) / 32 * sizeof(uint32_t);
                    atomicfields = (uint32_t*)malloc_s(nb);
                    memset(atomicfields, 0, nb);
                }
                atomicfields[fldn / 32] |= 1 << (fldn % 32);
            }
            else if (attr == pyju_const_sym) {
                if (!mutabl)
                    pyju_errorf("invalid field attribute const for immutable struct");
                if (constfields == NULL) {
                    size_t nb = (pyju_svec_len(fnames) + 31) / 32 * sizeof(uint32_t);
                    constfields = (uint32_t*)malloc_s(nb);
                    memset(constfields, 0, nb);
                }
                constfields[fldn / 32] |= 1 << (fldn % 32);
            }
            else {
                pyju_errorf("invalid field attribute %s", pyju_symbol_name(attr));
            }
        }
    }
    PYJU_CATCH {
        free(atomicfields);
        free(constfields);
        pyju_rethrow();
    }
    tn->atomicfields = atomicfields;
    tn->constfields = constfields;

    if (t->name->wrapper == NULL) {
        t->name->wrapper = (PyjuValue_t*)t;
        pyju_gc_wb(t->name, t);
        int i, np = pyju_svec_len(parameters);
        for (i = np - 1; i >= 0; i--) {
            t->name->wrapper = pyju_new_struct(pyju_unionall_type, pyju_svecref(parameters, i), t->name->wrapper);
            pyju_gc_wb(t->name, t->name->wrapper);
        }
        if (!mutabl && !abstract && ftypes != NULL)
            tn->mayinlinealloc = 1;
    }
    pyju_precompute_memoized_dt(t, 0);

    if (!abstract && t->types != NULL)
        pyju_compute_field_offsets(t);

    PYJU_GC_POP();
    return t;
}


// Determine if homogeneous tuple with fields of type t will have
// a special alignment beyond normal Julia rules.
// Return special alignment if one exists, 0 if normal alignment rules hold.
// A non-zero result *must* match the LLVM rules for a vector type <nfields x t>.
// For sake of Ahead-Of-Time (AOT) compilation, this routine has to work
// without LLVM being available.
unsigned pyju_special_vector_alignment(size_t nfields, PyjuValue_t *t)
{
    if (!pyju_is_vecelement_type(t))
        return 0;
    assert(pyju_datatype_nfields(t) == 1);
    PyjuValue_t *ty = pyju_field_type((PyjuDataType_t*)t, 0);
    if (!pyju_is_primitivetype(ty))
        // LLVM requires that a vector element be a primitive type.
        // LLVM allows pointer types as vector elements, but until a
        // motivating use case comes up for Julia, we reject pointers.
        return 0;
    size_t elsz = pyju_datatype_size(ty);
    if (elsz != 1 && elsz != 2 && elsz != 4 && elsz != 8)
        // Only handle power-of-two-sized elements (for now)
        return 0;
    size_t size = nfields * elsz;
    // Use natural alignment for this vector: this matches LLVM and clang.
    return next_power_of_two(size);
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
        boxed_ssavalue_cache[i] = pyju_permbox32(pyju_ssavalue_type, i);
        boxed_slotnumber_cache[i] = pyju_permbox32(pyju_slotnumber_type, i);
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

// struct constructors --------------------------------------------------------

PYJU_DLLEXPORT PyjuValue_t *pyju_new_struct(PyjuDataType_t *type, ...)
{
    PyjuTask_t *ct = pyju_current_task;
    if (type->instance != NULL) return type->instance;
    va_list args;
    size_t i, nf = pyju_datatype_nfields(type);
    va_start(args, type);
    PyjuValue_t *pv = pyju_gc_alloc(ct->ptls, pyju_datatype_size(type) + PYJU_TV_SIZE, type);
    if (nf > 0 && pyju_field_offset(type, 0) != 0) {
        memset(pyju_data_ptr(pv), 0, pyju_field_offset(type, 0));
    }
    for (i = 0; i < nf; i++) {
        set_nth_field(type, pv, i, va_arg(args, PyjuValue_t*), 0);
    }
    va_end(args);
    return pv;
}


// field access ---------------------------------------------------------------

PYJU_DLLEXPORT void pyju_lock_value(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    PYJU_LOCK_NOGC((PyjuMutex_t*)v);
}

PYJU_DLLEXPORT void pyju_unlock_value(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    PYJU_UNLOCK_NOGC((PyjuMutex_t*)v);
}



static inline void memassign_safe(int hasptr, PyjuValue_t *parent, char *dst, const PyjuValue_t *src, size_t nb) PYJU_NOTSAFEPOINT
{

    if (hasptr) {
        // assert that although dst might have some undefined bits, the src heap box should be okay with that
        assert(LLT_ALIGN(nb, sizeof(void*)) == LLT_ALIGN(pyju_datatype_size(pyju_typeof(src)), sizeof(void*)));
        size_t nptr = nb / sizeof(void*);
        memmove_refs((void**)dst, (void**)pyju_data_ptr(src), nptr);
        pyju_gc_multi_wb(parent, src);
        src = (PyjuValue_t*)((char*)pyju_data_ptr(src) + nptr * sizeof(void*));
        dst = dst + nptr * sizeof(void*);
        nb -= nptr * sizeof(void*);
    }
    else {
        // src must be a heap box.
        assert(nb == pyju_datatype_size(pyju_typeof(src)));
        if (nb >= 16) {
            memcpy(dst, pyju_assume_aligned(pyju_data_ptr(src), 16), nb);
            return;
        }
    }
    memcpy(dst, pyju_assume_aligned(src, sizeof(void*)), nb);
}

void set_nth_field(PyjuDataType_t *st, PyjuValue_t *v, size_t i, PyjuValue_t *rhs, int isatomic) PYJU_NOTSAFEPOINT
{
    size_t offs = pyju_field_offset(st, i);
    if (rhs == NULL) { // TODO: this should be invalid, but it happens frequently in ircode.c
        assert(pyju_field_isptr(st, i) && *(PyjuValue_t**)((char*)pyju_data_ptr(v) + offs) == NULL);
        return;
    }
    if (pyju_field_isptr(st, i)) {
        pyju_atomic_store_relaxed((_Atomic(PyjuValue_t*)*)((char*)pyju_data_ptr(v) + offs), rhs);
        pyju_gc_wb(v, rhs);
    } else {
        PyjuValue_t *ty = pyju_field_type_concrete(st, i);
        PyjuValue_t *rty = pyju_typeof(rhs);
        int hasptr;
        int isunion = pyju_is_uniontype(ty);
        if (isunion) {
            assert(!isatomic);
            size_t fsz = pyju_field_size(st, i);
            uint8_t *psel = &((uint8_t*)pyju_data_ptr(v))[offs + fsz - 1];
            unsigned nth = 0;
            if (!pyju_find_union_component(ty, rty, &nth))
                assert(0 && "invalid field assignment to isbits union");
            *psel = nth;
            if (pyju_is_datatype_singleton((PyjuDataType_t*)rty))
                return;
            hasptr = 0;
        } else {
            hasptr = ((PyjuDataType_t*)ty)->layout->npointers > 0;
        }
        size_t fsz = pyju_datatype_size((PyjuDataType_t*)rty); // need to shrink-wrap the final copy
        int needlock = (isatomic && fsz > MAX_ATOMIC_SIZE);
        if (isatomic && !needlock) {
            pyju_atomic_store_bits((char*)pyju_data_ptr(v) + offs, rhs, fsz);
            if (hasptr)
                pyju_gc_multi_wb(v, rhs); // rhs is immutable
        } else if (needlock) {
            // 如果变量v需要加锁，那么它的第一个参数一定要是PyjuMutex_t 对象，否则不能使用如下的加锁函数
            pyju_lock_value((PyjuValue_t*)pyju_data_ptr(v));
            memcpy((char*)pyju_data_ptr(v) + offs, (char*)pyju_data_ptr(rhs), fsz);
            pyju_unlock_value((PyjuValue_t*)pyju_data_ptr(v));
        } else {
            memassign_safe(hasptr, v, (char*)pyju_data_ptr(v) + offs, rhs, fsz);
        }
    }
}


// bits constructors ----------------------------------------------------------

#if MAX_ATOMIC_SIZE > MAX_POINTERATOMIC_SIZE
#error MAX_ATOMIC_SIZE too large
#endif
#if MAX_ATOMIC_SIZE >= 16 && !defined(_P64)
#error 12 byte GC pool size alignment unimplemented for 32-bit
#endif
#if MAX_POINTERATOMIC_SIZE > 16
#error MAX_POINTERATOMIC_SIZE too large
#endif
#if BYTE_ORDER != LITTLE_ENDIAN
#error using masks for atomics (instead of memcpy like nb == 16) assumes little endian
#endif

#if MAX_POINTERATOMIC_SIZE >= 16
typedef struct _pyju_uint128_t {
    uint64_t a;
    uint64_t b;
} pyju_uint128_t;
#endif

static inline uint32_t zext_read32(const void *x, size_t nb) PYJU_NOTSAFEPOINT
{
    uint32_t y = *(uint32_t*)x;
    if (nb == 4)
        return y;
    else // if (nb == 3)
        return 0xffffffu & y;
}

#if MAX_POINTERATOMIC_SIZE >= 8
static inline uint64_t zext_read64(const void *x, size_t nb) PYJU_NOTSAFEPOINT
{
    uint64_t y = *(uint64_t*)x;
    if (nb == 8)
        return y;
    else if (nb == 7)
        return 0xffffffffffffffu & y;
    else if (nb == 6)
        return 0xffffffffffffu & y;
    else // if (nb == 5)
        return 0xffffffffffu & y;
}
#endif

#if MAX_POINTERATOMIC_SIZE >= 16
static inline pyju_uint128_t zext_read128(const void *x, size_t nb) PYJU_NOTSAFEPOINT
{
    pyju_uint128_t y = {0};
    if (nb == 16)
        y = *(pyju_uint128_t*)x;
    else
        memcpy(&y, x, nb);
    return y;
}
#endif

PYJU_DLLEXPORT void pyju_atomic_store_bits(char *dst, const PyjuValue_t *src, int nb)
{
    // dst must have the required alignment for an atomic of the given size
    // src must be aligned by the GC
    // we may therefore read too much from src, but will zero the excess bits
    // before the store (so that we can get faster cmpswap later)
    if (nb == 0)
        ;
    else if (nb == 1)
        pyju_atomic_store((_Atomic(uint8_t)*)dst, *(uint8_t*)pyju_data_ptr(src));
    else if (nb == 2)
        pyju_atomic_store((_Atomic(uint8_t)*)dst, *(uint16_t*)pyju_data_ptr(src));
    else if (nb <= 4)
        pyju_atomic_store((_Atomic(uint32_t)*)dst, zext_read32(pyju_data_ptr(src), nb));
#if MAX_POINTERATOMIC_SIZE >= 8
    else if (nb <= 8)
        pyju_atomic_store((_Atomic(uint64_t)*)dst, zext_read64(pyju_data_ptr(src), nb));
#endif
#if MAX_POINTERATOMIC_SIZE >= 16
    else if (nb <= 16)
        pyju_atomic_store((_Atomic(pyju_uint128_t)*)dst, zext_read128(pyju_data_ptr(src), nb));
#endif
    else
        abort();
}

#ifdef __cplusplus
} // extern "C"
#endif