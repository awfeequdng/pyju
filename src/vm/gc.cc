#include "gc.h"
#include "pyju_gcext.h"
#include "pyju_assert.h"
#ifdef __GLIBC__
#include <malloc.h> // for malloc_trim
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Linked list of callback functions
typedef void (*pyju_gc_cb_func_t)(void);

struct PyjuGcCallbackList_t {
    PyjuGcCallbackList_t *next;
    pyju_gc_cb_func_t func;
};

static PyjuGcCallbackList_t *gc_cblist_root_scanner;
static PyjuGcCallbackList_t *gc_cblist_task_scanner;
static PyjuGcCallbackList_t *gc_cblist_pre_gc;
static PyjuGcCallbackList_t *gc_cblist_post_gc;
static PyjuGcCallbackList_t *gc_cblist_notify_external_alloc;
static PyjuGcCallbackList_t *gc_cblist_notify_external_free;

#define gc_invoke_callbacks(ty, list, args) \
    do {    \
        for (auto *cb = list; cb != NULL; cb = cb->next)    \
        {   \
            ((ty)(cb->func))args;   \
        }   \
    } while (0)

static void pyju_gc_register_callback(PyjuGcCallbackList_t **list,
        pyju_gc_cb_func_t func)
{
    while (*list != NULL) {
        if ((*list)->func == func)
            return;
        list = &((*list)->next);
    }
    *list = (PyjuGcCallbackList_t*)malloc_s(sizeof(PyjuGcCallbackList_t));
    (*list)->next = NULL;
    (*list)->func = func;
}

static void pyju_gc_deregister_callback(PyjuGcCallbackList_t **list, pyju_gc_cb_func_t func) {
    while (*list != NULL) {
        if ((*list)->func == func) {
            auto tmp = *list;
            (*list) = (*list)->next;
            free(tmp);
            return;
        }
        list = &((*list)->next);
    }
}

PYJU_DLLEXPORT void pyju_gc_set_cb_root_scanner(pyju_gc_cb_root_scanner_t cb, int enable) {
    if (enable)
        pyju_gc_register_callback(&gc_cblist_root_scanner, (pyju_gc_cb_func_t)cb);
    else
        pyju_gc_deregister_callback(&gc_cblist_root_scanner, (pyju_gc_cb_func_t)cb);
}

PYJU_DLLEXPORT void pyju_gc_set_cb_task_scanner(pyju_gc_cb_task_scanner_t cb, int enable)
{
    if (enable)
        pyju_gc_register_callback(&gc_cblist_task_scanner, (pyju_gc_cb_func_t)cb);
    else
        pyju_gc_deregister_callback(&gc_cblist_task_scanner, (pyju_gc_cb_func_t)cb);
}

PYJU_DLLEXPORT void pyju_gc_set_cb_pre_gc(pyju_gc_cb_pre_gc_t cb, int enable)
{
    if (enable)
        pyju_gc_register_callback(&gc_cblist_pre_gc, (pyju_gc_cb_func_t)cb);
    else
        pyju_gc_deregister_callback(&gc_cblist_pre_gc, (pyju_gc_cb_func_t)cb);
}

PYJU_DLLEXPORT void pyju_gc_set_cb_post_gc(pyju_gc_cb_post_gc_t cb, int enable)
{
    if (enable)
        pyju_gc_register_callback(&gc_cblist_post_gc, (pyju_gc_cb_func_t)cb);
    else
        pyju_gc_deregister_callback(&gc_cblist_post_gc, (pyju_gc_cb_func_t)cb);
}

PYJU_DLLEXPORT void pyju_gc_set_cb_notify_external_alloc(pyju_gc_cb_notify_external_alloc_t cb, int enable)
{
    if (enable)
        pyju_gc_register_callback(&gc_cblist_notify_external_alloc, (pyju_gc_cb_func_t)cb);
    else
        pyju_gc_deregister_callback(&gc_cblist_notify_external_alloc, (pyju_gc_cb_func_t)cb);
}

PYJU_DLLEXPORT void pyju_gc_set_cb_notify_external_free(pyju_gc_cb_notify_external_free_t cb, int enable)
{
    if (enable)
        pyju_gc_register_callback(&gc_cblist_notify_external_free, (pyju_gc_cb_func_t)cb);
    else
        pyju_gc_deregister_callback(&gc_cblist_notify_external_free, (pyju_gc_cb_func_t)cb);
}

// Save/restore local mark stack to/from thread-local storage.

STATIC_INLINE void export_gc_state(PyjuPtls_t ptls, PyjuGcMarkSp_t *sp) {
    ptls->gc_mark_sp = *sp;
}

STATIC_INLINE void import_gc_state(PyjuPtls_t ptls, PyjuGcMarkSp_t *sp) {
    // Has the stack been reallocated in the meantime?
    *sp = ptls->gc_mark_sp;
}

// Protect all access to `finalizer_list_marked` and `to_finalize`.
// For accessing `ptls->finalizers`, the lock is needed if a thread
// is going to realloc the buffer (of its own list) or accessing the
// list of another thread
static PyjuMutex_t finalizers_lock;
static uv_mutex_t gc_cache_lock;

// Flag that tells us whether we need to support conservative marking
// of objects.
static _Atomic(int) support_conservative_marking = 0;


/**
 * Note about GC synchronization:
 *
 * When entering `jl_gc_collect()`, `jl_gc_running` is atomically changed from
 * `0` to `1` to make sure that only one thread can be running the GC. Other
 * threads that enters `jl_gc_collect()` at the same time (or later calling
 * from unmanaged code) will wait in `jl_gc_collect()` until the GC is finished.
 *
 * Before starting the mark phase the GC thread calls `jl_safepoint_gc_start()`
 * and `jl_gc_wait_for_the_world()`
 * to make sure all the thread are in a safe state for the GC. The function
 * activates the safepoint and wait for all the threads to get ready for the
 * GC (`gc_state != 0`). It also acquires the `finalizers` lock so that no
 * other thread will access them when the GC is running.
 *
 * During the mark and sweep phase of the GC, the threads that are not running
 * the GC should either be running unmanaged code (or code section that does
 * not have a GC critical region mainly including storing to the stack or
 * another object) or paused at a safepoint and wait for the GC to finish.
 * If a thread want to switch from running unmanaged code to running managed
 * code, it has to perform a GC safepoint check after setting the `gc_state`
 * flag (see `jl_gc_state_save_and_set()`. it is possible that the thread might
 * have `gc_state == 0` in the middle of the GC transition back before entering
 * the safepoint. This is fine since the thread won't be executing any GC
 * critical region during that time).
 *
 * The finalizers are run after the GC finishes in normal mode (the `gc_state`
 * when `jl_gc_collect` is called) with `jl_in_finalizer = 1`. (TODO:) When we
 * have proper support of GC transition in codegen, we should execute the
 * finalizers in unmanaged (GC safe) mode.
 */

PyjuGcNum_t gc_num = {0};

// Per-thread initialization
void pyju_init_thread_heap(PyjuPtls_t ptls)
{
    if (ptls->tid == 0)
        ptls->disable_gc = 1;
    PyjuThreadHeap_t *heap = &ptls->heap;
    PyjuGcPool_t *p = heap->norm_pools;
    for (int i = 0; i < PYJU_GC_N_POOLS; i++) {
        p[i].osize = pyju_gc_sizeclasses[i];
        p[i].freelist = NULL;
        p[i].newpages = NULL;
    }
    arraylist_new(&heap->weak_refs, 0);
    arraylist_new(&heap->live_tasks, 0);
    heap->mallocarrays = NULL;
    heap->mafreelist = NULL;
    heap->big_objects = NULL;
    arraylist_new(&heap->rem_bindings, 0);
    heap->remset = &heap->_remset[0];
    heap->last_remset = &heap->_remset[1];
    arraylist_new(heap->remset, 0);
    arraylist_new(heap->last_remset, 0);
    arraylist_new(&ptls->finalizers, 0);
    arraylist_new(&ptls->sweep_objs, 0);

    PyjuGcMarkCache_t *gc_cache = &ptls->gc_cache;
    gc_cache->perm_scanned_bytes = 0;
    gc_cache->scanned_bytes = 0;
    gc_cache->nbig_obj = 0;
    size_t init_size = 1024;
    gc_cache->pc_stack = (void**)malloc_s(init_size * sizeof(void*));
    gc_cache->pc_stack_end = gc_cache->pc_stack + init_size;
    gc_cache->data_stack = (PyjuGcMarkData_t *)malloc_s(init_size * sizeof(PyjuGcMarkData_t));

    memset(&ptls->gc_num, 0, sizeof(ptls->gc_num));
    assert(gc_num.interval == default_collect_interval);
    pyju_atomic_store_relaxed(&ptls->gc_num.allocd, -(int64_t)gc_num.interval);
}

// finalization
// `ptls->finalizers` and `finalizer_list_marked` might have tagged pointers.
// If an object pointer has the lowest bit set, the next pointer is an unboxed
// c function pointer.
// `to_finalize` should not have tagged pointers.
arraylist_t finalizer_list_marked;
arraylist_t to_finalize;
PYJU_DLLEXPORT _Atomic(int) pyju_gc_have_pending_finalizers = 0;

PYJU_DLLEXPORT void pyju_gc_run_pending_finalizers(PyjuTask_t *ct)
{
    printf("not impl: pyju_gc_run_pending_finalizers");
}


// System-wide initializations
void pyju_gc_init()
{
    PYJU_MUTEX_INIT(&finalizers_lock);
}

#ifdef __cplusplus
}
#endif
