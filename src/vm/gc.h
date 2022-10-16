// This file is a part of Julia. License is MIT: https://julialang.org/license

/*
  allocation and garbage collection
  . non-moving, precise mark and sweep collector
  . pool-allocates small objects, keeps big objects on a simple list
*/

#ifndef PYJU_GC_H
#define PYJU_GC_H

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <inttypes.h>
#include "pyju_object.h"
#include "pyju_threads.h"
#include "pyju_internal.h"
#include "threading.h"

#include <sys/mman.h>
#include "pyju_assert.h"
// #include "gc-alloc-profiler.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GC_PAGE_LG2 14 // log2(size of a page)
#define GC_PAGE_SZ (1 << GC_PAGE_LG2) // 16k
#define GC_PAGE_OFFSET (PYJU_HEAP_ALIGNMENT - (sizeof(PyjuTaggedValue_t) % PYJU_HEAP_ALIGNMENT))

#define pyju_malloc_tag ((void*)0xdeadaa01)
#define pyju_singleton_tag ((void*)0xdeadaa02)

// Used by GC_DEBUG_ENV
typedef struct {
    uint64_t num;
    uint64_t next;

    uint64_t min;
    uint64_t interv;
    uint64_t max;
    unsigned short random[3];
} PyjuAllocNum_t;

typedef struct {
    int always_full;
    int wait_for_debugger;
    PyjuAllocNum_t pool;
    PyjuAllocNum_t other;
    PyjuAllocNum_t print;
} pyju_gc_debug_env_t;

// This struct must be kept in sync with the Julia type of the same name in base/util.jl
typedef struct {
    int64_t     allocd;
    int64_t     deferred_alloc;
    int64_t     freed;
    uint64_t    malloc;
    uint64_t    realloc;
    uint64_t    poolalloc;
    uint64_t    bigalloc;
    uint64_t    freecall;
    uint64_t    total_time;
    uint64_t    total_allocd;
    uint64_t    since_sweep;
    size_t      interval;
    int         pause;
    int         full_sweep;
} PyjuGcNum_t;

enum {
    GC_MARK_L_marked_obj,
    GC_MARK_L_scan_only,
    GC_MARK_L_finlist,
    GC_MARK_L_objarray,
    GC_MARK_L_array8,
    GC_MARK_L_array16,
    GC_MARK_L_obj8,
    GC_MARK_L_obj16,
    GC_MARK_L_obj32,
    GC_MARK_L_stack,
    GC_MARK_L_excstack,
    GC_MARK_L_module_binding,
    _GC_MARK_L_MAX
};


// The following structs (`gc_mark_*_t`) contain iterator state used for the
// scanning of various object types.
//
// The `nptr` member records the number of pointers slots referenced by
// an object to be used in the full collection heuristics as well as whether the object
// references young objects.
// `nptr >> 2` is the number of pointers fields referenced by the object.
// The lowest bit of `nptr` is set if the object references young object.
// The 2nd lowest bit of `nptr` is the GC old bits of the object after marking.
// A `0x3` in the low bits means that the object needs to be in the remset.

// An generic object that's marked and needs to be scanned
// The metadata might need update too (depend on the PC)
typedef struct {
    PyjuValue_t *obj; // The object
    uintptr_t tag; // The tag with the GC bits masked out
    uint8_t bits; // The GC bits after tagging (`bits & 1 == 1`)
} gc_mark_marked_obj_t;


// An object array. This can come from an array, svec, or the using array or a module
typedef struct {
    PyjuValue_t *parent; // The parent object to trigger write barrier on.
    PyjuValue_t **begin; // The first slot to be scanned.
    PyjuValue_t **end; // The end address (after the last slot to be scanned)
    uint32_t step; // Number of pointers to jump between marks
    uintptr_t nptr; // See notes about `nptr` above.
} gc_mark_objarray_t;

// A normal object with 8bits field descriptors
typedef struct {
    PyjuValue_t *parent; // The parent object to trigger write barrier on.
    uint8_t *begin; // Current field descriptor.
    uint8_t *end; // End of field descriptor.
    uintptr_t nptr; // See notes about `nptr` above.
} gc_mark_obj8_t;

// A normal object with 16bits field descriptors
typedef struct {
    PyjuValue_t *parent; // The parent object to trigger write barrier on.
    uint16_t *begin; // Current field descriptor.
    uint16_t *end; // End of field descriptor.
    uintptr_t nptr; // See notes about `nptr` above.
} gc_mark_obj16_t;

// A normal object with 32bits field descriptors
typedef struct {
    PyjuValue_t *parent; // The parent object to trigger write barrier on.
    uint32_t *begin; // Current field descriptor.
    uint32_t *end; // End of field descriptor.
    uintptr_t nptr; // See notes about `nptr` above.
} gc_mark_obj32_t;

typedef struct {
    PyjuValue_t **begin; // The first slot to be scanned.
    PyjuValue_t **end; // The end address (after the last slot to be scanned)
    uint8_t *rebegin;
    gc_mark_obj8_t elem;
} gc_mark_array8_t;

typedef struct {
    PyjuValue_t **begin; // The first slot to be scanned.
    PyjuValue_t **end; // The end address (after the last slot to be scanned)
    uint16_t *rebegin;
    gc_mark_obj16_t elem;
} gc_mark_array16_t;

// Stack frame
typedef struct {
    PyjuGcFrame_t *s; // The current stack frame
    uint32_t i; // The current slot index in the frame
    uint32_t nroots; // `nroots` fields in the frame
    // Parameters to mark the copy_stack range.
    uintptr_t offset;
    uintptr_t lb;
    uintptr_t ub;
} gc_mark_stackframe_t;

// Exception stack data
typedef struct {
    PyjuExcStack_t *s;   // Stack of exceptions
    size_t itr;         // Iterator into exception stack
    size_t bt_index;    // Current backtrace buffer entry index
    size_t jlval_index; // Index into GC managed values for current bt entry
} gc_mark_excstack_t;

// Module bindings. This is also the beginning of module scanning.
// The loop will start marking other references in a module after the bindings are marked
typedef struct {
    PyjuModule_t *parent; // The parent module to trigger write barrier on.
    PyjuBinding_t **begin; // The first slot to be scanned.
    PyjuBinding_t **end; // The end address (after the last slot to be scanned)
    uintptr_t nptr; // See notes about `nptr` above.
    uint8_t bits; // GC bits of the module (the bits to mark the binding buffer with)
} gc_mark_binding_t;

// Finalizer (or object) list
typedef struct {
    PyjuValue_t **begin;
    PyjuValue_t **end;
} gc_mark_finlist_t;

// This is used to determine the max size of the data objects on the data stack.
// We'll use this size to determine the size of the data stack corresponding to a
// PC stack size. Since the data objects are not all of the same size, we'll waste
// some memory on the data stack this way but that size is unlikely going to be significant.
union PyjuGcMarkData_t {
    gc_mark_marked_obj_t marked;
    gc_mark_objarray_t objarray;
    gc_mark_array8_t array8;
    gc_mark_array16_t array16;
    gc_mark_obj8_t obj8;
    gc_mark_obj16_t obj16;
    gc_mark_obj32_t obj32;
    gc_mark_stackframe_t stackframe;
    gc_mark_excstack_t excstackframe;
    gc_mark_binding_t binding;
    gc_mark_finlist_t finlist;
};

#ifdef _P64
#define default_collect_interval (5600*1024*sizeof(void*))
static size_t max_collect_interval = 1250000000UL;
#else
#define default_collect_interval (3200*1024*sizeof(void*))
static size_t max_collect_interval =  500000000UL;
#endif


#ifdef __cplusplus
}
#endif

#endif
