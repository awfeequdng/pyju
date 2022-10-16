#pragma once

#include "pyju_object.h"

#ifdef __cplusplus
extern "C" {
#endif

// Callbacks that allow C code to hook into the GC.

// Marking callbacks for global roots and tasks, respectively. These,
// along with custom mark functions must not alter the GC state except
// through calling pyju_gc_mark_queue_obj() and pyju_gc_mark_queue_objarray().
typedef void (*pyju_gc_cb_root_scanner_t)(int full) PYJU_NOTSAFEPOINT;
typedef void (*pyju_gc_cb_task_scanner_t)(PyjuTask_t *task, int full) PYJU_NOTSAFEPOINT;

// Callbacks that are invoked before and after a collection.
typedef void (*pyju_gc_cb_pre_gc_t)(int full) PYJU_NOTSAFEPOINT;
typedef void (*pyju_gc_cb_post_gc_t)(int full) PYJU_NOTSAFEPOINT;

// Callbacks to track external object allocations.
typedef void (*pyju_gc_cb_notify_external_alloc_t)(void *addr, size_t size) PYJU_NOTSAFEPOINT;
typedef void (*pyju_gc_cb_notify_external_free_t)(void *addr) PYJU_NOTSAFEPOINT;

PYJU_DLLEXPORT void pyju_gc_set_cb_root_scanner(pyju_gc_cb_root_scanner_t cb, int enable);
PYJU_DLLEXPORT void pyju_gc_set_cb_task_scanner(pyju_gc_cb_task_scanner_t cb, int enable);
PYJU_DLLEXPORT void pyju_gc_set_cb_pre_gc(pyju_gc_cb_pre_gc_t cb, int enable);
PYJU_DLLEXPORT void pyju_gc_set_cb_post_gc(pyju_gc_cb_post_gc_t cb, int enable);
PYJU_DLLEXPORT void pyju_gc_set_cb_notify_external_alloc(pyju_gc_cb_notify_external_alloc_t cb,
        int enable);
PYJU_DLLEXPORT void pyju_gc_set_cb_notify_external_free(pyju_gc_cb_notify_external_free_t cb,
        int enable);

// Types for custom mark and sweep functions.
typedef uintptr_t (*pyju_markfunc_t)(PyjuPtls_t, PyjuValue_t *obj);
typedef void (*pyju_sweepfunc_t)(PyjuValue_t *obj);

// Function to create a new foreign type with custom
// mark and sweep functions.
PYJU_DLLEXPORT PyjuDataType_t *pyju_new_foreign_type(
        PyjuSym_t *name,
        PyjuModule_t *module,
        PyjuDataType_t *super,
        pyju_markfunc_t markfunc,
        pyju_sweepfunc_t sweepfunc,
        int haspointers,
        int large);

PYJU_DLLEXPORT int pyju_is_foreign_type(PyjuDataType_t *dt);
PYJU_DLLEXPORT size_t pyju_gc_max_internal_obj_size();
PYJU_DLLEXPORT size_t pyju_gc_external_obj_hdr_size();

// Field layout descriptor for custom types that do
// not fit Julia layout conventions. This is associated with
// PyjuDataType_t instances where fielddesc_type == 3.

typedef struct {
    pyju_markfunc_t markfunc;
    pyju_sweepfunc_t sweepfunc;
} pyju_fielddescdyn_t;

// Allocate an object of a foreign type.
PYJU_DLLEXPORT void *pyju_gc_alloc_typed(PyjuPtls_t ptls, size_t sz, void *ty);

// Queue an object or array of objects for scanning by the garbage collector.
// These functions must only be called from within a root scanner callback
// or from within a custom mark function.
PYJU_DLLEXPORT int pyju_gc_mark_queue_obj(PyjuPtls_t ptls, PyjuValue_t *obj);
PYJU_DLLEXPORT void pyju_gc_mark_queue_objarray(PyjuPtls_t ptls, PyjuValue_t *parent,
    PyjuValue_t **objs, size_t nobjs);

// Sweep functions will not automatically be called for objects of
// foreign types, as that may not always be desired. Only calling
// pyju_gc_schedule_foreign_sweepfunc() on an object of a foreign type
// will result in the custome sweep function actually being called.
// This must be done at most once per object and should usually be
// done right after allocating the object.
PYJU_DLLEXPORT void pyju_gc_schedule_foreign_sweepfunc(PyjuPtls_t ptls, PyjuValue_t * bj);


// The following functions enable support for conservative marking. This
// functionality allows the user to determine if a machine word can be
// interpreted as a pointer to an object (including the interior of an
// object). It can be used to, for example, scan foreign stack frames or
// data structures with an unknown layout. It is called conservative
// marking, because it can lead to false positives, as non-pointer data
// can mistakenly be interpreted as a pointer to a Julia object.

// CAUTION: This is a sharp tool and should only be used as a measure of
// last resort. The user should be familiar with the risk of memory
// leaks (especially on 32-bit machines) if used inappropriately and how
// optimizing compilers can hide references from conservative stack
// scanning. In particular, arrays must be kept explicitly visible to
// the GC (by using PYJU_GC_PUSH1(), storing them in a location marked by
// the Julia GC, etc.) while their contents are being accessed. The
// reason is that array contents aren't marked separately, so if the
// object itself is not visible to the GC, neither are the contents.

// Enable support for conservative marking. The function returns
// whether support was already enabled. The function may implicitly
// trigger a full garbage collection to properly update all internal
// data structures.
PYJU_DLLEXPORT int pyju_gc_enable_conservative_gc_support(void);

// This function returns whether support for conservative scanning has
// been enabled. The return values are the same as for
// pyju_gc_enable_conservative_gc_support().
PYJU_DLLEXPORT int pyju_gc_conservative_gc_support_enabled(void);

// Returns the base address of a memory block, assuming it is stored in
// a julia memory pool. Return NULL otherwise. Conservative support
// *must* have been enabled for this to work reliably.
//
// NOTE: This will only work for internal pool allocations. For external
// allocations, the user must track allocations using the notification
// callbacks above and verify that they are valid objects. Note that
// external allocations may not all be valid objects and that for those,
// the user *must* validate that they have a proper type, i.e. that
// pyju_typeof(obj) is an actual type object.
PYJU_DLLEXPORT PyjuValue_t *pyju_gc_internal_obj_base_ptr(void *p);

// Return a non-null pointer to the start of the stack area if the task
// has an associated stack buffer. In that case, *size will also contain
// the size of that stack buffer upon return. Also, if task is a thread's
// current task, that thread's id will be stored in *tid; otherwise,
// *tid will be set to -1.
//
// DEPRECATED: use pyju_active_task_stack() instead.
PYJU_DLLEXPORT void *pyju_task_stack_buffer(PyjuTask_t *task, size_t *size, int *tid);

// Query the active and total stack range for the given task, and set
// *active_start and *active_end respectively *total_start and *total_end
// accordingly. The range for the active part is a best-effort approximation
// and may not be tight.
PYJU_DLLEXPORT void pyju_active_task_stack(PyjuTask_t *task,
                                       char **active_start, char **active_end,
                                       char **total_start, char **total_end);

#ifdef __cplusplus
}
#endif

