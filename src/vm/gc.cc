#include "gc.h"
#include "pyju_assert.h"
#ifdef __GLIBC__
#include <malloc.h> // for malloc_trim
#endif

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif
