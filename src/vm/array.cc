/*
  array constructors and primitives
*/
#include <stdlib.h>
#include <string.h>

#include "pyju.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "pyju_threads.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PYJU_ARRAY_IMPL_NUL 1

#define PYJU_ARRAY_ALIGN(pyju_value, nbytes) LLT_ALIGN(pyju_value, nbytes)

static inline void arrayassign_safe(int hasptr, PyjuValue_t *parent, char *dst, const PyjuValue_t *src, size_t nb) PYJU_NOTSAFEPOINT
{
    // array can assume more alignment than a field would normally have
    assert(nb >= pyju_datatype_size(pyju_typeof(src))); // nb might move some undefined bits, but we should be okay with that
    if (hasptr) {
        size_t nptr = nb / sizeof(void*);
        memmove_refs((void**)dst, (void* const*)pyju_data_ptr(src), nptr);
        pyju_gc_multi_wb(parent, src);
    }
    else {
        switch (nb) {
        case  0: break;
        case  1: *(uint8_t*)dst  = *(uint8_t*)pyju_data_ptr(src);  break;
        case  2: *(uint16_t*)dst = *(uint16_t*)pyju_data_ptr(src); break;
        case  4: *(uint32_t*)dst = *(uint32_t*)pyju_data_ptr(src); break;
        case  8: *(uint64_t*)dst = *(uint64_t*)pyju_data_ptr(src); break;
        case 16:
            memcpy(pyju_assume_aligned(dst, 16), pyju_assume_aligned(pyju_data_ptr(src), 16), 16);
            break;
        default: memcpy(dst, pyju_data_ptr(src), nb);
        }
    }
}

static inline void memmove_safe(int hasptr, char *dst, const char *src, size_t nb) PYJU_NOTSAFEPOINT
{
    if (hasptr)
        memmove_refs((void**)dst, (void**)src, nb / sizeof(void*));
    else
        memmove(dst, src, nb);
}

// array constructors ---------------------------------------------------------
PYJU_DLLEXPORT char *pyju_array_typetagdata(PyjuArray_t *a) PYJU_NOTSAFEPOINT
{
    assert(pyju_array_isbitsunion(a));
    return ((char*)pyju_array_data(a)) + ((pyju_array_ndims(a) == 1 ? (a->maxsize - a->offset) : pyju_array_len(a)) * a->elsize) + a->offset;
}

STATIC_INLINE PyjuValue_t *pyju_array_owner(PyjuArray_t *a PYJU_PROPAGATES_ROOT) PYJU_NOTSAFEPOINT
{
    if (a->flags.how == 3) {
        a = (PyjuArray_t*)pyju_array_data_owner(a);
        assert(pyju_is_string(a) || a->flags.how != 3);
    }
    return (PyjuValue_t*)a;
}

#if defined(_P64) && defined(UINT128MAX)
typedef __uint128_t wideint_t;
#else
typedef uint64_t wideint_t;
#endif

#define MAXINTVAL (((size_t)-1)>>1)

PYJU_DLLEXPORT int pyju_array_validate_dims(size_t *nel, size_t *tot, uint32_t ndims, size_t *dims, size_t elsz)
{
    size_t i;
    size_t _nel = 1;
    for(i=0; i < ndims; i++) {
        size_t di = dims[i];
        wideint_t prod = (wideint_t)_nel * (wideint_t)di;
        if (prod >= (wideint_t) MAXINTVAL || di >= MAXINTVAL)
            return 1;
        _nel = prod;
    }
    wideint_t prod = (wideint_t)elsz * (wideint_t)_nel;
    if (prod >= (wideint_t) MAXINTVAL)
        return 2;
    *nel = _nel;
    *tot = (size_t)prod;
    return 0;
}

static PyjuArray_t *_new_array_(PyjuValue_t *atype, uint32_t ndims, size_t *dims,
                               int8_t isunboxed, int8_t hasptr, int8_t isunion, int8_t zeroinit, size_t elsz)
{
    PyjuTask_t *ct = pyju_current_task;
    size_t i, tot, nel;
    void *data;
    PyjuArray_t *a;
    assert(isunboxed || elsz == sizeof(void*));
    assert(atype == NULL || isunion == pyju_is_uniontype(pyju_tparam0(atype)));
    int validated = pyju_array_validate_dims(&nel, &tot, ndims, dims, elsz);
    if (validated == 1)
        pyju_exceptionf(pyju_argumenterror_type, "invalid Array dimensions");
    else if (validated == 2)
        pyju_error("invalid Array size");
    if (isunboxed) {
        if (elsz == 1 && !isunion) {
            // extra byte for all julia allocated byte arrays
            tot++;
        }
        if (isunion) {
            // an extra byte for each isbits union array element, stored after a->maxsize
            tot += nel;
        }
    }

    int ndimwords = pyju_array_ndimwords(ndims);
    int tsz = sizeof(PyjuArray_t) + ndimwords*sizeof(size_t);
    if (tot <= ARRAY_INLINE_NBYTES) {
        // align data area
        if (tot >= ARRAY_CACHE_ALIGN_THRESHOLD)
            tsz = PYJU_ARRAY_ALIGN(tsz, PYJU_CACHE_BYTE_ALIGNMENT);
        else if (isunboxed && elsz >= 4)
            tsz = PYJU_ARRAY_ALIGN(tsz, PYJU_SMALL_BYTE_ALIGNMENT);
        size_t doffs = tsz;
        tsz += tot;
        // PyjuArray_t is large enough that objects will always be aligned 16
        a = (PyjuArray_t*)pyju_gc_alloc(ct->ptls, tsz, atype);
        // 数据字段按16字节对其
        assert((((size_t)a + PYJU_TV_SIZE) & 15) == 0);
        // No allocation or safepoint allowed after this
        a->flags.how = 0;
        data = (char*)a + doffs;
    }
    else {
        data = pyju_gc_managed_malloc(tot);
        // Allocate the Array **after** allocating the data
        // to make sure the array is still young
        a = (PyjuArray_t*)pyju_gc_alloc(ct->ptls, tsz, atype);
        // No allocation or safepoint allowed after this
        a->flags.how = 2;
        pyju_gc_track_malloced_array(ct->ptls, a);
    }
    a->flags.pooled = tsz <= GC_MAX_SZCLASS;

    if (zeroinit)
        memset(data, 0, tot);
    a->data = data;
    if (PYJU_ARRAY_IMPL_NUL && elsz == 1)
        ((char*)data)[tot - 1] = '\0';
    a->length = nel;
    a->flags.ndims = ndims;
    a->flags.ptrarray = !isunboxed;
    a->flags.hasptr = hasptr;
    a->elsize = elsz;
    a->flags.isshared = 0;
    a->flags.isaligned = 1;
    a->offset = 0;
    if (ndims == 1) {
        a->nrows = nel;
        a->maxsize = nel;
    }
    else if (a->flags.ndims != ndims) {
        pyju_exceptionf(pyju_argumenterror_type, "invalid Array dimensions");
    }
    else {
        size_t *adims = &a->nrows;
        for (i = 0; i < ndims; i++)
            adims[i] = dims[i];
    }

    return a;
}

static inline PyjuArray_t *_new_array(PyjuValue_t *atype, uint32_t ndims, size_t *dims)
{
    PyjuValue_t *eltype = pyju_tparam0(atype);
    size_t elsz = 0, al = 0;
    if (!pyju_is_kind(pyju_typeof(eltype)))
        pyju_type_error_rt("Array", "element type", (PyjuValue_t*)pyju_type_type, eltype);
    int isunboxed = pyju_islayout_inline(eltype, &elsz, &al);
    int isunion = pyju_is_uniontype(eltype);
    int hasptr = isunboxed && (pyju_is_datatype(eltype) && ((PyjuDataType_t*)eltype)->layout->npointers > 0);
    if (!isunboxed) {
        elsz = sizeof(void*);
        al = elsz;
    }
    else {
        elsz = LLT_ALIGN(elsz, al);
    }
    int zi = !isunboxed || hasptr || isunion || (pyju_is_datatype(eltype) && ((PyjuDataType_t*)eltype)->zeroinit);

    return _new_array_(atype, ndims, dims, isunboxed, hasptr, isunion, zi, elsz);
}

PyjuArray_t *pyju_new_array_for_deserialization(PyjuValue_t *atype, uint32_t ndims, size_t *dims,
                                             int isunboxed, int hasptr, int isunion, int elsz)
{
    return _new_array_(atype, ndims, dims, isunboxed, hasptr, isunion, 0, (size_t)elsz);
}

#ifndef PYJU_NDEBUG
static inline int is_ntuple_long(PyjuValue_t *v)
{
    if (!pyju_is_tuple(v))
        return 0;
    PyjuValue_t *tt = pyju_typeof(v);
    size_t i, nfields = pyju_nparams(tt);
    for (i = 0; i < nfields; i++) {
        if (pyju_tparam(tt, i) != (PyjuValue_t*)pyju_long_type) {
            return 0;
        }
    }
    return 1;
}
#endif

PYJU_DLLEXPORT PyjuArray_t *pyju_reshape_array(PyjuValue_t *atype, PyjuArray_t *data,
                                          PyjuValue_t *_dims)
{
    PyjuTask_t *ct = pyju_current_task;
    assert(pyju_types_equal(pyju_tparam0(pyju_typeof(data)), pyju_tparam0(atype)));

    size_t ndims = pyju_nfields(_dims);
    assert(is_ntuple_long(_dims));
    size_t *dims = (size_t*)(_dims + PYJU_TV_SIZE);
    int ndimwords = pyju_array_ndimwords(ndims);
    int tsz = sizeof(PyjuArray_t) + ndimwords * sizeof(size_t) + sizeof(void*);
    PyjuArray_t *a = (PyjuArray_t*)pyju_gc_alloc(ct->ptls, tsz, atype);
    // No allocation or safepoint allowed after this
    // copy data (except dims) from the old object
    a->flags.pooled = tsz <= GC_MAX_SZCLASS;
    a->flags.ndims = ndims;
    a->offset = 0;
    a->data = NULL;
    a->flags.isaligned = data->flags.isaligned;
    a->elsize = data->elsize;
    a->flags.ptrarray = data->flags.ptrarray;
    a->flags.hasptr = data->flags.hasptr;

    // if data is itself a shared wrapper,
    // owner should point back to the original array
    PyjuArray_t *owner = (PyjuArray_t*)pyju_array_owner(data);
    pyju_array_data_owner(a) = (PyjuValue_t*)owner;

    a->flags.how = 3;
    a->data = data->data;
    a->flags.isshared = 1;
    data->flags.isshared = 1;

    if (ndims == 1) {
        size_t l = dims[0];
        a->length = l;
        a->nrows = l;
        a->maxsize = l;
    }
    else if (a->flags.ndims != ndims) {
        pyju_exceptionf(pyju_argumenterror_type, "invalid Array dimensions");
    }
    else {
        size_t *adims = &a->nrows;
        size_t l = 1;
        wideint_t prod;
        for (size_t i = 0; i < ndims; i++) {
            adims[i] = dims[i];
            prod = (wideint_t)l * (wideint_t)adims[i];
            if (prod > (wideint_t) MAXINTVAL)
                pyju_exceptionf(pyju_argumenterror_type, "invalid Array dimensions");
            l = prod;
        }
        a->length = l;
    }

    return a;
}

PYJU_DLLEXPORT PyjuArray_t *pyju_string_to_array(PyjuValue_t *str)
{
    PyjuTask_t *ct = pyju_current_task;
    PyjuArray_t *a;

    int ndimwords = pyju_array_ndimwords(1);
    int tsz = sizeof(PyjuArray_t) + ndimwords*sizeof(size_t) + sizeof(void*);
    a = (PyjuArray_t*)pyju_gc_alloc(ct->ptls, tsz, pyju_array_uint8_type);
    a->flags.pooled = tsz <= GC_MAX_SZCLASS;
    a->flags.ndims = 1;
    a->offset = 0;
    a->data = pyju_string_data(str);
    a->flags.isaligned = 0;
    a->elsize = 1;
    a->flags.ptrarray = 0;
    a->flags.hasptr = 0;
    pyju_array_data_owner(a) = str;
    a->flags.how = 3;
    a->flags.isshared = 1;
    size_t l = pyju_string_len(str);
    a->length = l;
    a->nrows = a->maxsize = l;
    return a;
}

// own_buffer != 0 iff GC should call free() on this pointer eventually
PYJU_DLLEXPORT PyjuArray_t *pyju_ptr_to_array_1d(PyjuValue_t *atype, void *data,
                                            size_t nel, int own_buffer)
{
    PyjuTask_t *ct = pyju_current_task;
    PyjuArray_t *a;
    PyjuValue_t *eltype = pyju_tparam0(atype);

    int isunboxed = pyju_stored_inline(eltype);
    if (isunboxed && pyju_is_uniontype(eltype))
        pyju_exceptionf(pyju_argumenterror_type,
                      "unsafe_wrap: unspecified layout for union element type");
    size_t elsz;
    unsigned align;
    if (isunboxed) {
        elsz = pyju_datatype_size(eltype);
        align = pyju_datatype_align(eltype);
    }
    else {
        align = elsz = sizeof(void*);
    }
    if (((uintptr_t)data) & ((align > PYJU_HEAP_ALIGNMENT ? PYJU_HEAP_ALIGNMENT : align) - 1))
        pyju_exceptionf(pyju_argumenterror_type,
                      "unsafe_wrap: pointer %p is not properly aligned to %u bytes", data, align);

    int ndimwords = pyju_array_ndimwords(1);
    int tsz = sizeof(PyjuArray_t) + ndimwords*sizeof(size_t);
    a = (PyjuArray_t*)pyju_gc_alloc(ct->ptls, tsz, atype);
    // No allocation or safepoint allowed after this
    a->flags.pooled = tsz <= GC_MAX_SZCLASS;
    a->data = data;
    a->length = nel;
    a->elsize = LLT_ALIGN(elsz, align);
    a->flags.ptrarray = !isunboxed;
    a->flags.hasptr = isunboxed && (pyju_is_datatype(eltype) && ((PyjuDataType_t*)eltype)->layout->npointers > 0);
    a->flags.ndims = 1;
    a->flags.isshared = 1;
    a->flags.isaligned = 0;  // TODO: allow passing memalign'd buffers
    if (own_buffer) {
        a->flags.how = 2;
        pyju_gc_track_malloced_array(ct->ptls, a);
        pyju_gc_count_allocd(nel*elsz + (elsz == 1 ? 1 : 0));
    }
    else {
        a->flags.how = 0;
    }

    a->nrows = nel;
    a->maxsize = nel;
    a->offset = 0;
    return a;
}

PYJU_DLLEXPORT PyjuArray_t *pyju_ptr_to_array(PyjuValue_t *atype, void *data,
                                         PyjuValue_t *_dims, int own_buffer)
{
    PyjuTask_t *ct = pyju_current_task;
    size_t nel = 1;
    PyjuArray_t *a;
    size_t ndims = pyju_nfields(_dims);
    wideint_t prod;
    assert(is_ntuple_long(_dims));
    size_t *dims = (size_t*)(_dims + PYJU_TV_SIZE);
    for (size_t i = 0; i < ndims; i++) {
        prod = (wideint_t)nel * (wideint_t)dims[i];
        if (prod > (wideint_t) MAXINTVAL)
            pyju_exceptionf(pyju_argumenterror_type, "invalid Array dimensions");
        nel = prod;
    }
    if (__unlikely(ndims == 1))
        return pyju_ptr_to_array_1d(atype, data, nel, own_buffer);
    PyjuValue_t *eltype = pyju_tparam0(atype);

    int isunboxed = pyju_stored_inline(eltype);
    if (isunboxed && pyju_is_uniontype(eltype))
        pyju_exceptionf(pyju_argumenterror_type,
                      "unsafe_wrap: unspecified layout for union element type");
    size_t elsz;
    unsigned align;
    if (isunboxed) {
        elsz = pyju_datatype_size(eltype);
        align = pyju_datatype_align(eltype);
    }
    else {
        align = elsz = sizeof(void*);
    }
    if (((uintptr_t)data) & ((align > PYJU_HEAP_ALIGNMENT ? PYJU_HEAP_ALIGNMENT : align) - 1))
        pyju_exceptionf(pyju_argumenterror_type,
                      "unsafe_wrap: pointer %p is not properly aligned to %u bytes", data, align);

    int ndimwords = pyju_array_ndimwords(ndims);
    int tsz = sizeof(PyjuArray_t) + ndimwords*sizeof(size_t);
    a = (PyjuArray_t*)pyju_gc_alloc(ct->ptls, tsz, atype);
    // No allocation or safepoint allowed after this
    a->flags.pooled = tsz <= GC_MAX_SZCLASS;
    a->data = data;
    a->length = nel;
    a->elsize = LLT_ALIGN(elsz, align);
    a->flags.ptrarray = !isunboxed;
    a->flags.hasptr = isunboxed && (pyju_is_datatype(eltype) && ((PyjuDataType_t*)eltype)->layout->npointers > 0);
    a->flags.ndims = ndims;
    a->offset = 0;
    a->flags.isshared = 1;
    a->flags.isaligned = 0;
    if (own_buffer) {
        a->flags.how = 2;
        pyju_gc_track_malloced_array(ct->ptls, a);
        pyju_gc_count_allocd(nel*elsz + (elsz == 1 ? 1 : 0));
    }
    else {
        a->flags.how = 0;
    }

    assert(ndims != 1); // handled above
    if (a->flags.ndims != ndims)
        pyju_exceptionf(pyju_argumenterror_type, "invalid Array dimensions");
    memcpy(&a->nrows, dims, ndims * sizeof(size_t));
    return a;
}

PYJU_DLLEXPORT PyjuArray_t *pyju_new_array(PyjuValue_t *atype, PyjuValue_t *_dims)
{
    size_t ndims = pyju_nfields(_dims);
    assert(is_ntuple_long(_dims));
    return _new_array(atype, ndims, (size_t*)_dims);
}

PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_array_1d(PyjuValue_t *atype, size_t nr)
{
    return _new_array(atype, 1, &nr);
}

PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_array_2d(PyjuValue_t *atype, size_t nr,
                                           size_t nc)
{
    size_t d[2] = {nr, nc};
    return _new_array(atype, 2, &d[0]);
}

PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_array_3d(PyjuValue_t *atype, size_t nr,
                                           size_t nc, size_t z)
{
    size_t d[3] = {nr, nc, z};
    return _new_array(atype, 3, &d[0]);
}

PYJU_DLLEXPORT PyjuArray_t *pyju_pchar_to_array(const char *str, size_t len)
{
    PyjuArray_t *a = pyju_alloc_array_1d(pyju_array_uint8_type, len);
    memcpy(a->data, str, len);
    return a;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_array_to_string(PyjuArray_t *a)
{
    size_t len = pyju_array_len(a);
    if (len == 0) {
        // this may seem like purely an optimization (which it also is), but it
        // also ensures that calling `String(a)` doesn't corrupt a previous
        // string also created the same way, where `a = StringVector(_)`.
        return pyju_an_empty_string;
    }
    // TODO: 什么时候会进入到这个分支？
    if (a->flags.how == 3 && a->offset == 0 && a->elsize == 1 &&
        (pyju_array_ndims(a) != 1 ||
         ((a->maxsize + sizeof(void*) + 1 <= GC_MAX_SZCLASS) == (len + sizeof(void*) + 1 <= GC_MAX_SZCLASS)))) {
        PyjuValue_t *o = pyju_array_data_owner(a);
        if (pyju_is_string(o)) {
            a->flags.isshared = 1;
            pyju_string_len(o) = len;
            a->nrows = 0;
            a->length = 0;
            a->maxsize = 0;
            return o;
        }
    }
    a->nrows = 0;
    a->length = 0;
    a->maxsize = 0;
    return pyju_pchar_to_string((const char*)pyju_array_data(a), len);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_alloc_string(size_t len)
{
    if (len == 0)
        return pyju_an_empty_string;
    size_t sz = sizeof(size_t) + len + 1; // add space for trailing \nul protector and size
    if (sz < len) // overflow
        pyju_throw(pyju_memory_exception);
    PyjuTask_t *ct = pyju_current_task;
    PyjuValue_t *s;
    PyjuPtls_t ptls = ct->ptls;
    const size_t allocsz = sz + sizeof(PyjuTaggedValue_t);
    if (sz <= GC_MAX_SZCLASS) {
        int pool_id = pyju_gc_szclass_align8(allocsz);
        PyjuGcPool_t *p = &ptls->heap.norm_pools[pool_id];
        int osize = pyju_gc_sizeclasses[pool_id];
        // We call `pyju_gc_pool_alloc_noinline` instead of `pyju_gc_pool_alloc` to avoid double-counting in
        // the Allocations Profiler. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
        s = pyju_gc_pool_alloc_noinline(ptls, (char*)p - (char*)ptls, osize);
    }
    else {
        if (allocsz < sz) // overflow in adding offs, size was "negative"
            pyju_throw(pyju_memory_exception);
        s = pyju_gc_big_alloc_noinline(ptls, allocsz);
    }
    pyju_set_typeof(s, pyju_string_type);
    // maybe_record_alloc_to_profile(s, len, pyju_string_type);
    pyju_string_len(s) = len;
    pyju_string_data(s)[len] = 0;
    return s;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_pchar_to_string(const char *str, size_t len)
{
    PyjuValue_t *s = pyju_alloc_string(len);
    if (len > 0)
        memcpy(pyju_string_data(s), str, len);
    return s;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_cstr_to_string(const char *str)
{
    return pyju_pchar_to_string(str, strlen(str));
}

PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_vec_any(size_t n)
{
    return pyju_alloc_array_1d(pyju_array_any_type, n);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_apply_array_type(PyjuValue_t *type, size_t dim)
{
    PyjuValue_t *boxed_dim = pyju_box_long(dim);
    PYJU_GC_PUSH1(&boxed_dim);
    PyjuValue_t *ret = pyju_apply_type2((PyjuValue_t*)pyju_array_type, type, boxed_dim);
    PYJU_GC_POP();
    return ret;
}

// array primitives -----------------------------------------------------------

PYJU_DLLEXPORT PyjuValue_t *pyju_ptrarrayref(PyjuArray_t *a PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT
{
    assert(i < pyju_array_len(a));
    assert(a->flags.ptrarray);
    PyjuValue_t *elt = pyju_atomic_load_relaxed(((_Atomic(PyjuValue_t*)*)a->data) + i);
    if (elt == NULL)
        pyju_throw(pyju_undefref_exception);
    return elt;
}


PYJU_DLLEXPORT PyjuValue_t *pyju_arrayref(PyjuArray_t *a, size_t i)
{
    if (a->flags.ptrarray)
        return pyju_ptrarrayref(a, i);
    assert(i < pyju_array_len(a));
    PyjuValue_t *eltype = (PyjuValue_t*)pyju_tparam0(pyju_typeof(a));
    if (pyju_is_uniontype(eltype)) {
        // isbits union selector bytes are always stored directly after the last array element
        uint8_t sel = pyju_array_typetagdata(a)[i];
        eltype = pyju_nth_union_component(eltype, sel);
        if (pyju_is_datatype_singleton((PyjuDataType_t*)eltype))
            return ((PyjuDataType_t*)eltype)->instance;
    }
    PyjuValue_t *r = undefref_check((PyjuDataType_t*)eltype, pyju_new_bits(eltype, &((char*)a->data)[i * a->elsize]));
    if (__unlikely(r == NULL))
        pyju_throw(pyju_undefref_exception);
    return r;
}

PYJU_DLLEXPORT int pyju_array_isassigned(PyjuArray_t *a, size_t i)
{
    if (a->flags.ptrarray) {
        return pyju_atomic_load_relaxed(((_Atomic(PyjuValue_t*)*)pyju_array_data(a)) + i) != NULL;
    }
    else if (a->flags.hasptr) {
         PyjuDataType_t *eltype = (PyjuDataType_t*)pyju_tparam0(pyju_typeof(a));
         assert(eltype->layout->first_ptr >= 0);
         PyjuValue_t **elem = (PyjuValue_t**)((char*)a->data + i * a->elsize);
         return elem[eltype->layout->first_ptr] != NULL;
    }
    return 1;
}

PYJU_DLLEXPORT void pyju_arrayset(PyjuArray_t *a PYJU_ROOTING_ARGUMENT, PyjuValue_t *rhs PYJU_ROOTED_ARGUMENT PYJU_MAYBE_UNROOTED, size_t i)
{
    assert(i < pyju_array_len(a));
    PyjuValue_t *eltype = pyju_tparam0(pyju_typeof(a));
    if (eltype != (PyjuValue_t*)pyju_any_type) {
        PYJU_GC_PUSH1(&rhs);
        if (!pyju_isa(rhs, eltype))
            pyju_type_error("arrayset", eltype, rhs);
        PYJU_GC_POP();
    }
    if (!a->flags.ptrarray) {
        int hasptr;
        if (pyju_is_uniontype(eltype)) {
            uint8_t *psel = &((uint8_t*)pyju_array_typetagdata(a))[i];
            unsigned nth = 0;
            if (!pyju_find_union_component(eltype, pyju_typeof(rhs), &nth))
                assert(0 && "invalid arrayset to isbits union");
            *psel = nth;
            if (pyju_is_datatype_singleton((PyjuDataType_t*)pyju_typeof(rhs)))
                return;
            hasptr = 0;
        }
        else {
            hasptr = a->flags.hasptr;
        }
        arrayassign_safe(hasptr, pyju_array_owner(a), &((char*)a->data)[i * a->elsize], rhs, a->elsize);
    }
    else {
        pyju_atomic_store_relaxed(((_Atomic(PyjuValue_t*)*)a->data) + i, rhs);
        pyju_gc_wb(pyju_array_owner(a), rhs);
    }
}

PYJU_DLLEXPORT void pyju_arrayunset(PyjuArray_t *a, size_t i)
{
    if (i >= pyju_array_len(a))
        pyju_bounds_error_int((PyjuValue_t*)a, i + 1);
    if (a->flags.ptrarray)
        pyju_atomic_store_relaxed(((_Atomic(PyjuValue_t*)*)a->data) + i, nullptr);
    else if (a->flags.hasptr) {
        size_t elsize = a->elsize;
        pyju_assume(elsize >= sizeof(void*) && elsize % sizeof(void*) == 0);
        memset((char*)a->data + elsize * i, 0, elsize);
    }
}

// at this size and bigger, allocate resized array data with malloc directly
// instead of managing them separately as gc objects
#define MALLOC_THRESH 1048576

// Resize the buffer to a max size of `newlen`
// The buffer can either be newly allocated or realloc'd, the return
// value is 1 if a new buffer is allocated and 0 if it is realloc'd.
// the caller needs to take care of moving the data from the old buffer
// to the new one if necessary.
// When this function returns, the `->data` pointer always points to
// the **beginning** of the new buffer.
static int NOINLINE array_resize_buffer(PyjuArray_t *a, size_t newlen)
{
    PyjuTask_t *ct = pyju_current_task;
    assert(!a->flags.isshared || a->flags.how == 3);
    size_t elsz = a->elsize;
    size_t nbytes = newlen * elsz;
    size_t oldnbytes = a->maxsize * elsz;
    size_t oldoffsnb = a->offset * elsz;
    size_t oldlen = a->nrows;
    int isbitsunion = pyju_array_isbitsunion(a);
    assert(nbytes >= oldnbytes);
    if (elsz == 1 && !isbitsunion) {
        nbytes++;
        oldnbytes++;
    }
    if (isbitsunion) {
        nbytes += newlen;
        oldnbytes += a->maxsize;
    }
    int newbuf = 0;
    if (a->flags.how == 2) {
        // already malloc'd - use realloc
        char *olddata = (char*)a->data - oldoffsnb;
        a->data = pyju_gc_managed_realloc(olddata, nbytes, oldnbytes,
                                        a->flags.isaligned, (PyjuValue_t*)a);
    }
    else if (a->flags.how == 3 && pyju_is_string(pyju_array_data_owner(a)) && !isbitsunion) {
        // if data is in a String, keep it that way
        PyjuValue_t *s;
        if (a->flags.isshared) {
            s = pyju_alloc_string(nbytes - (elsz == 1));
            newbuf = 1;
        }
        else {
            s = pyju_gc_realloc_string(pyju_array_data_owner(a), nbytes - (elsz == 1));
        }
        pyju_array_data_owner(a) = s;
        pyju_gc_wb(a, s);
        a->data = pyju_string_data(s);
    }
    else {
        newbuf = 1;
        if (nbytes >= MALLOC_THRESH) {
            a->data = pyju_gc_managed_malloc(nbytes);
            pyju_gc_track_malloced_array(ct->ptls, a);
            a->flags.how = 2;
            a->flags.isaligned = 1;
        }
        else {
            a->data = pyju_gc_alloc_buf(ct->ptls, nbytes);
            a->flags.how = 1;
            pyju_gc_wb_buf(a, a->data, nbytes);
        }
    }
    if (PYJU_ARRAY_IMPL_NUL && elsz == 1 && !isbitsunion)
        memset((char*)a->data + oldnbytes - 1, 0, nbytes - oldnbytes + 1);
    (void)oldlen;
    assert(oldlen == a->nrows &&
           "Race condition detected: recursive resizing on the same array.");
    a->flags.isshared = 0;
    a->maxsize = newlen;
    return newbuf;
}

static void NOINLINE array_try_unshare(PyjuArray_t *a)
{
    if (a->flags.isshared) {
        if (a->flags.how != 3)
            pyju_error("cannot resize array with shared data");
        // allow resizing when data is shared with a String
        if (pyju_is_string(pyju_array_data_owner(a)))
            return;
        assert(a->offset == 0);
        size_t len = a->maxsize;
        size_t nbytes = len * a->elsize;
        if (pyju_array_isbitsunion(a)) {
            nbytes += len;
        }
        char *olddata = (char*)a->data;
        int newbuf = array_resize_buffer(a, len);
        assert(newbuf);
        (void)newbuf;
        memcpy(a->data, olddata, nbytes);
    }
}

size_t overallocation(size_t maxsize)
{
    if (maxsize < 8)
        return 8;
    // compute maxsize = maxsize + 4*maxsize^(7/8) + maxsize/8
    // for small n, we grow faster than O(n)
    // for large n, we grow at O(n/8)
    // and as we reach O(memory) for memory>>1MB,
    // this means we end by adding about 10% of memory each time
    int exp2 = sizeof(maxsize) * 8 -
#ifdef _P64
        __builtin_clzll(maxsize);
#else
        __builtin_clz(maxsize);
#endif
    maxsize += ((size_t)1 << (exp2 * 7 / 8)) * 4 + maxsize / 8;
    return maxsize;
}

STATIC_INLINE void pyju_array_grow_at_beg(PyjuArray_t *a, size_t idx, size_t inc,
                                        size_t n)
{
    // designed to handle the case of growing and shrinking at both ends
    if (__unlikely(a->flags.isshared)) {
        if (a->flags.how != 3)
            pyju_error("cannot resize array with shared data");
        if (inc == 0) {
            // If inc > 0, it will always trigger the slow path and unshare the
            // buffer
            array_try_unshare(a);
            return;
        }
    }
    size_t newnrows = n + inc;
    size_t elsz = a->elsize;
    size_t nbinc = inc * elsz;
    char *data = (char*)a->data;
    char *newdata;
    char *typetagdata;
    char *newtypetagdata = NULL;
    int isbitsunion = pyju_array_isbitsunion(a);
    if (isbitsunion) typetagdata = pyju_array_typetagdata(a);
    if (a->offset >= inc) {
        // already have enough space in a->offset
        newdata = data - nbinc;
        a->offset -= inc;
        if (isbitsunion) newtypetagdata = typetagdata - inc;
        if (idx > 0) {
            // inserting new elements after 1st element
            memmove_safe(a->flags.hasptr, newdata, data, idx * elsz);
            if (isbitsunion) {
                memmove(newtypetagdata, typetagdata, idx);
                memset(newtypetagdata + idx, 0, inc);
            }
        }
    }
    else {
        // not enough room for requested growth from existing a->offset
        size_t oldoffset = a->offset;
        size_t oldoffsnb = oldoffset * elsz;
        size_t oldmaxsize = a->maxsize;
        size_t nb1 = idx * elsz;
        if (inc > (a->maxsize - n) / 2 - (a->maxsize - n) / 20) {
            // not enough room for requested growth from end of array
            size_t newlen = inc * 2;
            while (n + 2 * inc > newlen - a->offset)
                newlen *= 2;
            size_t newmaxsize = overallocation(a->maxsize);
            if (newlen < newmaxsize)
                newlen = newmaxsize;
            size_t newoffset = (newlen - newnrows) / 2;
            if (!array_resize_buffer(a, newlen)) {
                data = (char*)a->data + oldoffsnb;
            }
            newdata = (char*)a->data + newoffset * elsz;
            if (isbitsunion) {
                typetagdata = data + (oldmaxsize - oldoffset) * elsz + oldoffset;
                newtypetagdata = newdata + (a->maxsize - newoffset) * elsz + newoffset;
                memmove(newtypetagdata, typetagdata, idx);
                memset(newtypetagdata + idx, 0, inc);
                memmove(newtypetagdata + idx + inc, typetagdata + idx, n - idx);
            }
            // We could use memcpy if resizing allocates a new buffer,
            // hopefully it's not a particularly important optimization.
            if (idx > 0 && newdata < data) {
                memmove_safe(a->flags.hasptr, newdata, data, nb1);
            }
            memmove_safe(a->flags.hasptr, newdata + nbinc + nb1, data + nb1, n * elsz - nb1);
            if (idx > 0 && newdata > data) {
                memmove_safe(a->flags.hasptr, newdata, data, nb1);
            }
            a->offset = newoffset;
        }
        else {
            // use extra space between a->nrows & a->maxsize
            a->offset = (a->maxsize - newnrows) / 2;
            newdata = data - oldoffsnb + a->offset * elsz;
            if (isbitsunion) newtypetagdata = newdata + (a->maxsize - a->offset) * elsz + a->offset;
            if (idx > 0 && newdata < data) {
                memmove_safe(a->flags.hasptr, newdata, data, nb1);
                if (isbitsunion) {
                    memmove(newtypetagdata, typetagdata, idx);
                    memset(newtypetagdata + idx, 0, inc);
                }
            }
            memmove_safe(a->flags.hasptr, newdata + nbinc + nb1, data + nb1, n * elsz - nb1);
            if (isbitsunion) memmove(newtypetagdata + idx + inc, typetagdata + idx, n - idx);
            if (idx > 0 && newdata > data) {
                memmove_safe(a->flags.hasptr, newdata, data, nb1);
                if (isbitsunion) {
                    memmove(newtypetagdata, typetagdata, idx);
                    memset(newtypetagdata + idx, 0, inc);
                }
            }
        }
    }
    a->length = newnrows;
    a->nrows = newnrows;
    a->data = newdata;
    if (pyju_is_array_zeroinit(a)) {
        memset(newdata + idx * elsz, 0, nbinc);
    }
    if (newtypetagdata) {
        memset(newtypetagdata + idx, 0, inc);
    }
}

STATIC_INLINE void pyju_array_grow_at_end(PyjuArray_t *a, size_t idx,
                                        size_t inc, size_t n)
{
    // optimized for the case of only growing and shrinking at the end
    if (__unlikely(a->flags.isshared)) {
        if (a->flags.how != 3)
            pyju_error("cannot resize array with shared data");
        if (inc == 0) {
            // If inc > 0, it will always trigger the slow path and unshare the
            // buffer
            array_try_unshare(a);
            return;
        }
    }
    size_t elsz = a->elsize;
    char *data = (char*)a->data;
    char *typetagdata;
    char *newtypetagdata;
    int isbitsunion = pyju_array_isbitsunion(a);
    if (isbitsunion) typetagdata = pyju_array_typetagdata(a);
    int has_gap = n > idx;
    size_t reqmaxsize = a->offset + n + inc;
    if (__unlikely(reqmaxsize > a->maxsize)) {
        size_t nb1 = idx * elsz;
        size_t nbinc = inc * elsz;
        // grow either by our computed overallocation factor or exactly the requested size,
        // whichever is larger
        size_t newmaxsize = overallocation(a->maxsize);
        if (newmaxsize < reqmaxsize)
            newmaxsize = reqmaxsize;
        size_t oldmaxsize = a->maxsize;
        int newbuf = array_resize_buffer(a, newmaxsize);
        char *newdata = (char*)a->data + a->offset * elsz;
        if (isbitsunion) newtypetagdata = newdata + (a->maxsize - a->offset) * elsz + a->offset;
        if (newbuf) {
            memcpy(newdata, data, nb1);
            if (isbitsunion) {
                memcpy(newtypetagdata, typetagdata, idx);
                if (has_gap) memcpy(newtypetagdata + idx + inc, typetagdata + idx, n - idx);
                memset(newtypetagdata + idx, 0, inc);
            }
            if (has_gap) memcpy(newdata + nb1 + nbinc, data + nb1, n * elsz - nb1);
        }
        else {
            if (isbitsunion) {
                typetagdata = newdata + (oldmaxsize - a->offset) * elsz + a->offset;
                if (has_gap) memmove(newtypetagdata + idx + inc, typetagdata + idx, n - idx);
                memmove(newtypetagdata, typetagdata, idx);
                memset(newtypetagdata + idx, 0, inc);
            }
            if (has_gap) memmove_safe(a->flags.hasptr, newdata + nb1 + nbinc, newdata + nb1, n * elsz - nb1);
        }
        a->data = data = newdata;
    }
    else if (has_gap) {
        if (isbitsunion) {
            memmove(typetagdata + idx + inc, typetagdata + idx, n - idx);
            memset(typetagdata + idx, 0, inc);
        }
        size_t nb1 = idx * elsz;
        memmove_safe(a->flags.hasptr, data + nb1 + inc * elsz, data + nb1, n * elsz - nb1);
    }
    else {
        // there was enough room for requested growth already in a->maxsize
        if (isbitsunion)
            memset(typetagdata + idx, 0, inc);
    }
    size_t newnrows = n + inc;
    a->length = newnrows;
    a->nrows = newnrows;
    if (pyju_is_array_zeroinit(a)) {
        memset(data + idx * elsz, 0, inc * elsz);
    }
}

PYJU_DLLEXPORT void pyju_array_grow_at(PyjuArray_t *a, ssize_t idx, size_t inc)
{
    // No need to explicitly unshare.
    // Shared arrays are guaranteed to trigger the slow path for growing.
    size_t n = pyju_array_nrows(a);
    if (idx < 0 || idx > n)
        pyju_bounds_error_int((PyjuValue_t*)a, idx + 1);
    if (idx + 1 < n / 2) {
        pyju_array_grow_at_beg(a, idx, inc, n);
    }
    else {
        pyju_array_grow_at_end(a, idx, inc, n);
    }
}

PYJU_DLLEXPORT void pyju_array_grow_end(PyjuArray_t *a, size_t inc)
{
    size_t n = pyju_array_nrows(a);
    pyju_array_grow_at_end(a, n, inc, n);
}

PYJU_DLLEXPORT void pyju_array_grow_beg(PyjuArray_t *a, size_t inc)
{
    size_t n = pyju_array_nrows(a);
    pyju_array_grow_at_beg(a, 0, inc, n);
}

STATIC_INLINE void pyju_array_shrink(PyjuArray_t *a, size_t dec)
{
    //if we don't manage this array return
    if (a->flags.how == 0) return;

    size_t elsz = a->elsize;
    size_t newbytes = (a->maxsize - dec) * a->elsize;
    size_t oldnbytes = (a->maxsize) * a->elsize;
    int isbitsunion = pyju_array_isbitsunion(a);
    if (isbitsunion) {
        newbytes += a->maxsize - dec;
        oldnbytes += a->maxsize;
    }

    if (elsz == 1 && !isbitsunion) {
        newbytes++;
        oldnbytes++;
    }
    char *originalptr = ((char*) a->data) - a->offset * a->elsize;
    if (a->flags.how == 1) {
        //this is a julia-allocated buffer that needs to be marked
        char *typetagdata;
        char *newtypetagdata;
        if (isbitsunion) {
            typetagdata = (char*)malloc_s(a->nrows);
            memcpy(typetagdata, pyju_array_typetagdata(a), a->nrows);
        }
        PyjuTask_t *ct = pyju_current_task;
        char *originaldata = (char*) a->data - a->offset * a->elsize;
        char *newdata = (char*)pyju_gc_alloc_buf(ct->ptls, newbytes);
        pyju_gc_wb_buf(a, newdata, newbytes);
        a->maxsize -= dec;
        if (isbitsunion) {
            newtypetagdata = pyju_array_typetagdata(a);
            memcpy(newtypetagdata, typetagdata, a->nrows);
            free(typetagdata);
        }
        memcpy(newdata, originaldata, newbytes);
        a->data = newdata + a->offset * elsz;
    }
    else if (a->flags.how == 2) {
        //malloc-allocated pointer this array object manages
        char *typetagdata;
        char *newtypetagdata;
        if (isbitsunion) {
            typetagdata = (char*)malloc_s(a->nrows);
            memcpy(typetagdata, pyju_array_typetagdata(a), a->nrows);
        }
        size_t oldoffsnb = a->offset * elsz;
        a->data = ((char*)pyju_gc_managed_realloc(originalptr, newbytes, oldnbytes,
                a->flags.isaligned, (PyjuValue_t*) a)) + oldoffsnb;
        a->maxsize -= dec;
        if (isbitsunion) {
            newtypetagdata = pyju_array_typetagdata(a);
            memcpy(newtypetagdata, typetagdata, a->nrows);
            free(typetagdata);
        }
    }
    else if (a->flags.how == 3) {
        //this has has a pointer to the object that owns the data
    }
}

static size_t pyju_array_limit_offset(PyjuArray_t *a, size_t offset)
{
    // make sure offset doesn't grow forever due to deleting at beginning
    // and growing at end
    if (offset >= 13 * a->maxsize / 20)
        offset = 17 * (a->maxsize - a->nrows) / 100;
#ifdef _P64
    while (offset > (size_t)UINT32_MAX) {
        offset /= 2;
    }
#endif
    return offset;
}

STATIC_INLINE void pyju_array_del_at_beg(PyjuArray_t *a, size_t idx, size_t dec,
                                       size_t n)
{
    // no error checking
    // assume inbounds, assume unshared
    size_t elsz = a->elsize;
    size_t offset = a->offset;
    int isbitsunion = pyju_array_isbitsunion(a);
    offset += dec;
    a->length = n - dec;
    a->nrows = n - dec;
    size_t newoffs = pyju_array_limit_offset(a, offset);
    assert(newoffs <= offset);
    size_t nbdec = dec * elsz;
    if (__unlikely(newoffs != offset) || idx > 0) {
        char *olddata = (char*)a->data;
        char *newdata = olddata - (a->offset - newoffs) * elsz;
        char *typetagdata;
        char *newtypetagdata;
        if (isbitsunion) {
            typetagdata = pyju_array_typetagdata(a);
            newtypetagdata = typetagdata - (a->offset - newoffs);
        }

        size_t nb1 = idx * elsz; // size in bytes of the first block
        size_t nbtotal = a->nrows * elsz; // size in bytes of the new array
        // Implicit '\0' for byte arrays
        if (elsz == 1 && !isbitsunion)
            nbtotal++;
        if (idx > 0) {
            memmove_safe(a->flags.hasptr, newdata, olddata, nb1);
            if (isbitsunion) memmove(newtypetagdata, typetagdata, idx);
        }
        // Move the rest of the data if the offset changed
        if (newoffs != offset) {
            memmove_safe(a->flags.hasptr, newdata + nb1, olddata + nb1 + nbdec, nbtotal - nb1);
            if (isbitsunion) memmove(newtypetagdata + idx, typetagdata + idx + dec, a->nrows - idx);
        }
        a->data = newdata;
    }
    else {
        char *data = (char*)a->data;
        a->data = data + nbdec;
    }
    a->offset = newoffs;
}

STATIC_INLINE void pyju_array_del_at_end(PyjuArray_t *a, size_t idx, size_t dec,
                                       size_t n)
{
    // no error checking
    // assume inbounds, assume unshared
    char *data = (char*)a->data;
    size_t elsz = a->elsize;
    int isbitsunion = pyju_array_isbitsunion(a);
    size_t last = idx + dec;
    if (n > last) {
        memmove_safe(a->flags.hasptr, data + idx * elsz, data + last * elsz, (n - last) * elsz);
        if (isbitsunion) {
            char *typetagdata = pyju_array_typetagdata(a);
            memmove(typetagdata + idx, typetagdata + last, n - last);
        }
    }
    n -= dec;
    if (elsz == 1 && !isbitsunion)
        data[n] = 0;
    a->nrows = n;
    a->length = n;
}

PYJU_DLLEXPORT void pyju_array_del_at(PyjuArray_t *a, ssize_t idx, size_t dec)
{
    size_t n = pyju_array_nrows(a);
    size_t last = idx + dec;
    if (__unlikely(idx < 0))
        pyju_bounds_error_int((PyjuValue_t*)a, idx + 1);
    if (__unlikely(last > n))
        pyju_bounds_error_int((PyjuValue_t*)a, last);
    // The unsharing needs to happen before we modify the buffer
    if (__unlikely(a->flags.isshared))
        array_try_unshare(a);
    if (idx < n - last) {
        pyju_array_del_at_beg(a, idx, dec, n);
    }
    else {
        pyju_array_del_at_end(a, idx, dec, n);
    }
}

PYJU_DLLEXPORT void pyju_array_del_beg(PyjuArray_t *a, size_t dec)
{
    size_t n = pyju_array_nrows(a);
    if (__unlikely(dec > n))
        pyju_bounds_error_int((PyjuValue_t*)a, dec);
    if (__unlikely(a->flags.isshared))
        array_try_unshare(a);
    if (dec == 0)
        return;
    pyju_array_del_at_beg(a, 0, dec, n);
}

PYJU_DLLEXPORT void pyju_array_del_end(PyjuArray_t *a, size_t dec)
{
    size_t n = pyju_array_nrows(a);
    if (__unlikely(n < dec))
        pyju_bounds_error_int((PyjuValue_t*)a, 0);
    if (__unlikely(a->flags.isshared))
        array_try_unshare(a);
    if (dec == 0)
        return;
    pyju_array_del_at_end(a, n - dec, dec, n);
}

PYJU_DLLEXPORT void pyju_array_sizehint(PyjuArray_t *a, size_t sz)
{
    size_t n = pyju_array_nrows(a);

    size_t min = a->offset + a->length;
    sz = (sz < min) ? min : sz;

    if (sz <= a->maxsize) {
        size_t dec = a->maxsize - sz;
        //if we don't save at least an eighth of maxsize then its not worth it to shrink
        if (dec < a->maxsize / 8) return;
        pyju_array_shrink(a, dec);
    }
    else {
        size_t inc = sz - n;
        pyju_array_grow_end(a, inc);

        a->nrows = n;
        a->length = n;
    }
}

PYJU_DLLEXPORT PyjuArray_t *pyju_array_copy(PyjuArray_t *ary)
{
    size_t elsz = ary->elsize;
    size_t len = pyju_array_len(ary);
    int isunion = pyju_is_uniontype(pyju_tparam0(pyju_typeof(ary)));
    PyjuArray_t *new_ary = _new_array_(pyju_typeof(ary), pyju_array_ndims(ary),
                                      &ary->nrows, !ary->flags.ptrarray,
                                      ary->flags.hasptr, isunion, 0, elsz);
    memcpy(new_ary->data, ary->data, len * elsz);
    // ensure isbits union arrays copy their selector bytes correctly
    if (pyju_array_isbitsunion(ary))
        memcpy(pyju_array_typetagdata(new_ary), pyju_array_typetagdata(ary), len);
    return new_ary;
}

// Copy element by element until we hit a young object, at which point
// we can finish by using `memmove`.
static NOINLINE ssize_t pyju_array_ptr_copy_forward(PyjuValue_t *owner,
                                                  void **src_p, void **dest_p,
                                                  ssize_t n) PYJU_NOTSAFEPOINT
{
    _Atomic(void*) *src_pa = (_Atomic(void*)*)src_p;
    _Atomic(void*) *dest_pa = (_Atomic(void*)*)dest_p;
    for (ssize_t i = 0; i < n; i++) {
        void *val = pyju_atomic_load_relaxed(src_pa + i);
        pyju_atomic_store_relaxed(dest_pa + i, val);
        // `val` is young or old-unmarked
        if (val && !(pyju_astaggedvalue(val)->bits.gc & GC_MARKED)) {
            pyju_gc_queue_root(owner);
            return i;
        }
    }
    return n;
}

static NOINLINE ssize_t pyju_array_ptr_copy_backward(PyjuValue_t *owner,
                                                   void **src_p, void **dest_p,
                                                   ssize_t n) PYJU_NOTSAFEPOINT
{
    _Atomic(void*) *src_pa = (_Atomic(void*)*)src_p;
    _Atomic(void*) *dest_pa = (_Atomic(void*)*)dest_p;
    for (ssize_t i = 0; i < n; i++) {
        void *val = pyju_atomic_load_relaxed(src_pa + n - i - 1);
        pyju_atomic_store_relaxed(dest_pa + n - i - 1, val);
        // `val` is young or old-unmarked
        if (val && !(pyju_astaggedvalue(val)->bits.gc & GC_MARKED)) {
            pyju_gc_queue_root(owner);
            return i;
        }
    }
    return n;
}

// Unsafe, assume inbounds and that dest and src have the same eltype
PYJU_DLLEXPORT void pyju_array_ptr_copy(PyjuArray_t *dest, void **dest_p,
                                    PyjuArray_t *src, void **src_p, ssize_t n) PYJU_NOTSAFEPOINT
{
    assert(dest->flags.ptrarray && src->flags.ptrarray);
    PyjuValue_t *owner = pyju_array_owner(dest);
    // Destination is old and doesn't refer to any young object
    if (__unlikely(pyju_astaggedvalue(owner)->bits.gc == GC_OLD_MARKED)) {
        PyjuValue_t *src_owner = pyju_array_owner(src);
        // Source is young or being promoted or might refer to young objects
        // (i.e. source is not an old object that doesn't have wb triggered)
        if (pyju_astaggedvalue(src_owner)->bits.gc != GC_OLD_MARKED) {
            ssize_t done;
            if (dest_p < src_p || dest_p > src_p + n) {
                done = pyju_array_ptr_copy_forward(owner, src_p, dest_p, n);
                dest_p += done;
                src_p += done;
            }
            else {
                done = pyju_array_ptr_copy_backward(owner, src_p, dest_p, n);
            }
            n -= done;
        }
    }
    memmove_refs(dest_p, src_p, n);
}

PYJU_DLLEXPORT void pyju_array_ptr_1d_push(PyjuArray_t *a, PyjuValue_t *item)
{
    assert(pyju_typeis(a, pyju_array_any_type));
    pyju_array_grow_end(a, 1);
    size_t n = pyju_array_nrows(a);
    pyju_array_ptr_set(a, n - 1, item);
}

PYJU_DLLEXPORT void pyju_array_ptr_1d_append(PyjuArray_t *a, PyjuArray_t *a2)
{
    assert(pyju_typeis(a, pyju_array_any_type));
    assert(pyju_typeis(a2, pyju_array_any_type));
    size_t i;
    size_t n = pyju_array_nrows(a);
    size_t n2 = pyju_array_nrows(a2);
    pyju_array_grow_end(a, n2);
    for (i = 0; i < n2; i++) {
        pyju_array_ptr_set(a, n + i, pyju_array_ptr_ref(a2, i));
    }
}

PYJU_DLLEXPORT PyjuValue_t *(pyju_array_data_owner)(PyjuArray_t *a) PYJU_NOTSAFEPOINT
{
    return pyju_array_data_owner(a);
}

STATIC_INLINE int pyju_has_implicit_byte_owned(PyjuArray_t *a)
{
    assert(a->flags.how != 3);
    if (!a->flags.isshared)
        return 1;
    return a->flags.how == 1;
}

STATIC_INLINE int pyju_has_implicit_byte(PyjuArray_t *a)
{
    // * unshared:
    //   * how: 0-2
    //     We own and allocated the data.
    //     It should have the extra byte.
    // * shared:
    //   * how: 0, 2
    //     The data might come from external source without implicit NUL byte.
    //     There could be an entra byte for a `reinterpreted` array
    //     but that should be unlikely for strings.
    //   * how: 1
    //     We allocated the data with the extra byte.
    //   * how: 3
    //     We should check the owner.
    if (a->flags.how == 3) {
        a = (PyjuArray_t*)pyju_array_data_owner(a);
        if (pyju_is_string(a)) return 1;
        return a->elsize == 1 && pyju_has_implicit_byte_owned(a);
    }
    return pyju_has_implicit_byte_owned(a);
}

// Create an array with the same content
PYJU_DLLEXPORT PyjuArray_t *pyju_array_cconvert_cstring(PyjuArray_t *a)
{
    assert(pyju_typeof(a) == pyju_array_uint8_type);
    if (!pyju_has_implicit_byte(a))
        a = pyju_array_copy(a);
    ((char*)a->data)[a->nrows] = 0;
    return a;
}

#ifdef __cplusplus
}
#endif
