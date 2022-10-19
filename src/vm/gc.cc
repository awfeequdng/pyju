#include "gc.h"
#include "pyju_gcext.h"
#include "pyju_assert.h"
#include "pyju_object.h"
#include "pyju_threads.h"
#include "support/dtypes.h"
#include <cstdint>
#include <cstdlib>
#include <sys/types.h>
#ifdef __GLIBC__
#include <malloc.h> // for malloc_trim
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _P64
#define default_collect_interval (5600*1024*sizeof(void*))
static size_t max_collect_interval = 1250000000UL;
#else
#define default_collect_interval (3200*1024*sizeof(void*))
static size_t max_collect_interval =  500000000UL;
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
 * When entering `pyju_gc_collect()`, `pyju_gc_running` is atomically changed from
 * `0` to `1` to make sure that only one thread can be running the GC. Other
 * threads that enters `pyju_gc_collect()` at the same time (or later calling
 * from unmanaged code) will wait in `pyju_gc_collect()` until the GC is finished.
 *
 * Before starting the mark phase the GC thread calls `pyju_safepoint_gc_start()`
 * and `pyju_gc_wait_for_the_world()`
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
 * flag (see `pyju_gc_state_save_and_set()`. it is possible that the thread might
 * have `gc_state == 0` in the middle of the GC transition back before entering
 * the safepoint. This is fine since the thread won't be executing any GC
 * critical region during that time).
 *
 * The finalizers are run after the GC finishes in normal mode (the `gc_state`
 * when `pyju_gc_collect` is called) with `pyju_in_finalizer = 1`. (TODO:) When we
 * have proper support of GC transition in codegen, we should execute the
 * finalizers in unmanaged (GC safe) mode.
 */

PyjuGcNum_t gc_num = {0};

static size_t last_long_collect_interval;

pagetable_t memory_map;

// List of marked big objects.  Not per-thread.  Accessed only by master thread.
bigval_t *big_objects_marked = NULL;

// finalization
// `ptls->finalizers` and `finalizer_list_marked` might have tagged pointers.
// If an object pointer has the lowest bit set, the next pointer is an unboxed
// c function pointer.
// `to_finalize` should not have tagged pointers.
arraylist_t finalizer_list_marked;
arraylist_t to_finalize;
PYJU_DLLEXPORT _Atomic(int) pyju_gc_have_pending_finalizers = 0;

NOINLINE uintptr_t gc_get_stack_ptr(void)
{
    return (uintptr_t)pyju_get_frame_addr();
}

#define should_timeout() 0

static void pyju_gc_wait_for_the_world(void)
{
    if (pyju_n_threads > 1)
        pyju_wake_libuv();
    for (int i = 0; i < pyju_n_threads; i++) {
        PyjuPtls_t ptls2 = pyju_all_tls_states[i];
        // This acquire load pairs with the release stores
        // in the signal handler of safepoint so we are sure that
        // all the stores on those threads are visible.
        // We're currently also using atomic store release in mutator threads
        // (in pyju_gc_state_set), but we may want to use signals to flush the
        // memory operations on those threads lazily instead.
        while (!pyju_atomic_load_relaxed(&ptls2->gc_state) || !pyju_atomic_load_acquire(&ptls2->gc_state))
            pyju_cpu_pause(); // yield?
    }
}

STATIC_INLINE void *pyju_malloc_aligned(size_t sz, size_t align)
{
#if defined(_P64) || defined(__APPLE__)
    if (align <= 16)
        return malloc(sz);
#endif
    void *ptr;
    if (posix_memalign(&ptr, align, sz))
        return NULL;
    return ptr;
}
STATIC_INLINE void *pyju_realloc_aligned(void *d, size_t sz, size_t oldsz,
                                       size_t align)
{
#if defined(_P64) || defined(__APPLE__)
    if (align <= 16)
        return realloc(d, sz);
#endif
    void *b = pyju_malloc_aligned(sz, align);
    if (b != NULL) {
        memcpy(b, d, oldsz > sz ? sz : oldsz);
        free(d);
    }
    return b;
}
STATIC_INLINE void pyju_free_aligned(void *p) PYJU_NOTSAFEPOINT
{
    free(p);
}

#define malloc_cache_align(sz) pyju_malloc_aligned(sz, PYJU_CACHE_BYTE_ALIGNMENT)
#define realloc_cache_align(p, sz, oldsz) pyju_realloc_aligned(p, sz, oldsz, PYJU_CACHE_BYTE_ALIGNMENT)


static void schedule_finalization(void *o, void *f) PYJU_NOTSAFEPOINT
{
    arraylist_push(&to_finalize, o);
    arraylist_push(&to_finalize, f);
    // doesn't need release, since we'll keep checking (on the reader) until we see the work and
    // release our lock, and that will have a release barrier by then
    pyju_atomic_store_relaxed(&pyju_gc_have_pending_finalizers, 1);
}


// static void run_finalizer(PyjuTask_t *ct, PyjuValue_t *o, PyjuValue_t *ff)
// {
//     if (gc_ptr_tag(o, 1)) {
//         ((void (*)(void*))ff)(gc_ptr_clear_tag(o, 1));
//         return;
//     }
//     PyjuValue_t *args[2] = {ff,o};
//     PYJU_TRY {
//         size_t last_age = ct->world_age;
//         ct->world_age = pyju_atomic_load_acquire(&pyju_world_counter);
//         pyju_apply(args, 2);
//         ct->world_age = last_age;
//     }
//     PYJU_CATCH {
//         pyju_printf((PYJU_STREAM*)STDERR_FILENO, "error in running finalizer: ");
//         pyju_static_show((PYJU_STREAM*)STDERR_FILENO, pyju_current_exception());
//         pyju_printf((PYJU_STREAM*)STDERR_FILENO, "\n");
//         jlbacktrace(); // written to STDERR_FILENO
//     }
// }

// mark phase

PYJU_DLLEXPORT void pyju_gc_queue_root(const PyjuValue_t *ptr)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    PyjuTaggedValue_t *o = pyju_astaggedvalue(ptr);
    // The modification of the `gc_bits` is not atomic but it
    // should be safe here since GC is not allowed to run here and we only
    // write GC_OLD to the GC bits outside GC. This could cause
    // duplicated objects in the remset but that shouldn't be a problem.
    o->bits.gc = GC_MARKED;
    arraylist_push(ptls->heap.remset, (PyjuValue_t*)ptr);
    ptls->heap.remset_nptr++; // conservative
}

void pyju_gc_queue_multiroot(const PyjuValue_t *parent, const PyjuValue_t* ptr) PYJU_NOTSAFEPOINT
{
    // first check if this is really necessary
    // TODO: should we store this info in one of the extra gc bits?
    PyjuDataType_t *dt = (PyjuDataType_t *)pyju_typeof(ptr);
    const PyjuDataTypeLayout_t *ly = dt->layout;
    uint32_t npointers = ly->npointers;
    // if (npointers = 0)   // this was checked by the caller
    //     return;

    PyjuValue_t *ptrf = ((PyjuValue_t**)ptr)[ly->first_ptr];
    if (ptrf && (pyju_astaggedvalue(ptrf)->bits.gc & 1) == 0) {
        // this pointer was young, move the barrier back now
        pyju_gc_wb_back(parent);
    }

    const uint8_t *ptrs8 = (const uint8_t *)pyju_dt_layout_ptrs(ly);
    const uint16_t *ptrs16 = (const uint16_t *)pyju_dt_layout_ptrs(ly);
    const uint32_t *ptrs32 = (const uint32_t *)pyju_dt_layout_ptrs(ly);
    for (size_t i = 1; i < npointers; i++) {
        uint32_t fld;
        if (ly->fielddesc_type == 0) {
            fld = ptrs8[i];
        } else if (ly->fielddesc_type == 1) {
            fld = ptrs16[i];
        } else {
            assert(ly->fielddesc_type == 2);
            fld = ptrs32[i];
        }
        PyjuValue_t *ptrf = ((PyjuValue_t **)ptr)[fld];
        if (ptrf && (pyju_astaggedvalue(ptrf)->bits.gc & 1) == 0) {
            // this pointer was young, move the barrier back now
            pyju_gc_wb_back(parent);
        }
    }
}

void gc_queue_binding(PyjuBinding_t *bnd)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    PyjuTaggedValue_t *buf = pyju_astaggedvalue(bnd);
    buf->bits.gc = GC_MARKED;
    arraylist_push(&ptls->heap.rem_bindings, bnd);
}


// big value list

// Size includes the tag and the tag is not cleared!!
static inline PyjuValue_t *pyju_gc_big_alloc_inner(PyjuPtls_t ptls, size_t sz)
{
    // maybe_collect(ptls);
    size_t offs = offsetof(bigval_t, header);
    assert(sz >= sizeof(PyjuTaggedValue_t) && "sz must include tag");
    static_assert(offsetof(bigval_t, header) >= sizeof(void*), "Empty bigval header?");
    static_assert(sizeof(bigval_t) % PYJU_HEAP_ALIGNMENT == 0, "");
    size_t allocsz = LLT_ALIGN(sz + offs, PYJU_CACHE_BYTE_ALIGNMENT);
    if (allocsz < sz)  // overflow in adding offs, size was "negative"
        // jl_throw(pyju_memory_exception);
        abort();

    bigval_t *v = (bigval_t*)malloc_cache_align(allocsz);
    if (v == NULL)
        // jl_throw(pyju_memory_exception);
        abort();

    gc_invoke_callbacks(pyju_gc_cb_notify_external_alloc_t,
        gc_cblist_notify_external_alloc, (v, allocsz));
    pyju_atomic_store_relaxed(&ptls->gc_num.allocd,
        pyju_atomic_load_relaxed(&ptls->gc_num.allocd) + allocsz);
    pyju_atomic_store_relaxed(&ptls->gc_num.bigalloc,
        pyju_atomic_load_relaxed(&ptls->gc_num.bigalloc) + 1);
#ifdef MEMDEBUG
    memset(v, 0xee, allocsz);
#endif
    v->sz = allocsz;
    v->age = 0;
    gc_big_object_link(v, &ptls->heap.big_objects);
    return pyju_valueof(&v->header);
}

// Instrumented version of jl_gc_big_alloc_inner, called into by LLVM-generated code.
PYJU_DLLEXPORT PyjuValue_t *pyju_gc_big_alloc(PyjuPtls_t ptls, size_t sz)
{
    PyjuValue_t *val = pyju_gc_big_alloc_inner(ptls, sz);

    // maybe_record_alloc_to_profile(val, sz, pyju_gc_unknown_type_tag);
    return val;
}

// This wrapper exists only to prevent `jl_gc_big_alloc_inner` from being inlined into
// its callers. We provide an external-facing interface for callers, and inline `jl_gc_big_alloc_inner`
// into this. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
PyjuValue_t *pyju_gc_big_alloc_noinline(PyjuPtls_t ptls, size_t sz) {
    return pyju_gc_big_alloc_inner(ptls, sz);
}


// pool allocation
static inline PyjuTaggedValue_t *reset_page(const PyjuGcPool_t *p, pyju_gc_pagemeta_t *pg, PyjuTaggedValue_t *fl) PYJU_NOTSAFEPOINT
{
    assert(GC_PAGE_OFFSET >= sizeof(void*));
    pg->nfree = (GC_PAGE_SZ - GC_PAGE_OFFSET) / p->osize;
    PyjuPtls_t ptls2 = pyju_all_tls_states[pg->thread_n];
    pg->pool_n = p - ptls2->heap.norm_pools;
    memset(pg->ages, 0, GC_PAGE_SZ / 8 / p->osize + 1);
    PyjuTaggedValue_t *beg = (PyjuTaggedValue_t*)(pg->data + GC_PAGE_OFFSET);
    PyjuTaggedValue_t *next = (PyjuTaggedValue_t*)pg->data;
    if (fl == NULL) {
        next->next = NULL;
    }
    else {
        // Insert free page after first page.
        // This prevents unnecessary fragmentation from multiple pages
        // being allocated from at the same time. Instead, objects will
        // only ever be allocated from the first object in the list.
        // This is specifically being relied on by the implementation
        // of pyju_gc_internal_obj_base_ptr() so that the function does
        // not have to traverse the entire list.
        PyjuTaggedValue_t *flpage = (PyjuTaggedValue_t *)gc_page_data(fl);
        next->next = flpage->next;
        flpage->next = beg;
        beg = fl;
    }
    pg->has_young = 0;
    pg->has_marked = 0;
    pg->fl_begin_offset = -1;
    pg->fl_end_offset = -1;
    return beg;
}

// Add a new page to the pool. Discards any pages in `p->newpages` before.
static NOINLINE PyjuTaggedValue_t *add_page(PyjuGcPool_t *p) PYJU_NOTSAFEPOINT
{
    // Do not pass in `ptls` as argument. This slows down the fast path
    // in pool_alloc significantly
    PyjuPtls_t ptls = pyju_current_task->ptls;
    pyju_gc_pagemeta_t *pg = pyju_gc_alloc_page();
    pg->osize = p->osize;
    pg->ages = (uint8_t*)malloc_s(GC_PAGE_SZ / 8 / p->osize + 1);
    pg->thread_n = ptls->tid;
    PyjuTaggedValue_t *fl = reset_page(p, pg, NULL);
    p->newpages = fl;
    return fl;
}

// Size includes the tag and the tag is not cleared!!
static inline PyjuValue_t *pyju_gc_pool_alloc_inner(PyjuPtls_t ptls, int pool_offset, int osize)
{
    // Use the pool offset instead of the pool address as the argument
    // to workaround a llvm bug.
    // Ref https://llvm.org/bugs/show_bug.cgi?id=27190
    PyjuGcPool_t *p = (PyjuGcPool_t*)((char*)ptls + pool_offset);
    assert(pyju_atomic_load_relaxed(&ptls->gc_state) == 0);
    #ifdef MEMDEBUG
    return jl_gc_big_alloc(ptls, osize);
    #endif
    // maybe_collect(ptls);
    pyju_atomic_store_relaxed(&ptls->gc_num.allocd,
        pyju_atomic_load_relaxed(&ptls->gc_num.allocd) + osize);
    pyju_atomic_store_relaxed(&ptls->gc_num.poolalloc,
        pyju_atomic_load_relaxed(&ptls->gc_num.poolalloc) + 1);

    // first try to use the freelist
    PyjuTaggedValue_t *v = p->freelist;
    if (v) {
        PyjuTaggedValue_t *next = v->next;
        p->freelist = next;
        if (__unlikely(gc_page_data(v) != gc_page_data(next))) {
            // we only update pg's fields when the freelist changes page
            // since pg's metadata is likely not in cache
            pyju_gc_pagemeta_t *pg = pyju_assume(page_metadata(v));
            assert(pg->osize == p->osize);
            pg->nfree = 0;
            pg->has_young = 1;
        }
        return pyju_valueof(v);
    }
    // if the freelist is empty we reuse empty but not freed pages
    v = p->newpages;
    PyjuTaggedValue_t *next = (PyjuTaggedValue_t*)((char*)v + osize);
        // If there's no pages left or the current page is used up,
    // we need to use the slow path.
    char *cur_page = gc_page_data((char*)v - 1);
    if (__unlikely(!v || cur_page + GC_PAGE_SZ < (char*)next)) {
        if (v) {
            // like the freelist case,
            // but only update the page metadata when it is full
            pyju_gc_pagemeta_t *pg = pyju_assume(page_metadata((char*)v - 1));
            assert(pg->osize == p->osize);
            pg->nfree = 0;
            pg->has_young = 1;
            v = *(PyjuTaggedValue_t**)cur_page;
        }
        // Not an else!!
        if (!v)
            v = add_page(p);
        next = (PyjuTaggedValue_t*)((char*)v + osize);
    }
    p->newpages = next;
    return pyju_valueof(v);
}

// Instrumented version of jl_gc_pool_alloc_inner, called into by LLVM-generated code.
PYJU_DLLEXPORT PyjuValue_t *jl_gc_pool_alloc(PyjuPtls_t ptls, int pool_offset,
                                          int osize)
{
    PyjuValue_t *val = pyju_gc_pool_alloc_inner(ptls, pool_offset, osize);

    // maybe_record_alloc_to_profile(val, osize, pyju_gc_unknown_type_tag);
    return val;
}

// This wrapper exists only to prevent `jl_gc_pool_alloc_inner` from being inlined into
// its callers. We provide an external-facing interface for callers, and inline `jl_gc_pool_alloc_inner`
// into this. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
PyjuValue_t *pyju_gc_pool_alloc_noinline(PyjuPtls_t ptls, int pool_offset, int osize) {
    return pyju_gc_pool_alloc_inner(ptls, pool_offset, osize);
}

int pyju_gc_classify_pools(size_t sz, int *osize)
{
    if (sz > GC_MAX_SZCLASS)
        return -1;
    size_t allocsz = sz + sizeof(PyjuTaggedValue_t);
    int klass = pyju_gc_szclass(allocsz);
    *osize = pyju_gc_sizeclasses[klass];
    return (int)(intptr_t)(&((PyjuPtls_t)0)->heap.norm_pools[klass]);
}

// collector entry point and control
static _Atomic(uint32_t) pyju_gc_disable_counter = 1;

PYJU_DLLEXPORT int pyju_gc_enable(int on)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    int prev = !ptls->disable_gc;
    ptls->disable_gc = (on == 0);
    if (on && !prev) {
        // disable -> enable
        if (pyju_atomic_fetch_add(&pyju_gc_disable_counter, -1) == 1) {
            gc_num.allocd += gc_num.deferred_alloc;
            gc_num.deferred_alloc = 0;
        }
    }
    else if (prev && !on) {
        // enable -> disable
        pyju_atomic_fetch_add(&pyju_gc_disable_counter, 1);
        // check if the GC is running and wait for it to finish
        pyju_gc_safepoint_(ptls);
    }
    return prev;
}

PYJU_DLLEXPORT int pyju_gc_is_enabled(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    return !ptls->disable_gc;
}


// allocator entry points

PYJU_DLLEXPORT PyjuValue_t *(pyju_gc_alloc)(PyjuPtls_t ptls, size_t sz, void *ty)
{
    return pyju_gc_alloc_(ptls, sz, ty);
}

PYJU_DLLEXPORT void pyju_gc_run_pending_finalizers(PyjuTask_t *ct)
{
    printf("not impl: pyju_gc_run_pending_finalizers");
}

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


// System-wide initializations
void pyju_gc_init()
{
    PYJU_MUTEX_INIT(&finalizers_lock);
    uv_mutex_init(&gc_cache_lock);
    uv_mutex_init(&gc_perm_lock);

    pyju_gc_init_page();

    arraylist_new(&finalizer_list_marked, 0);
    arraylist_new(&to_finalize, 0);

    gc_num.interval = default_collect_interval;
    last_long_collect_interval = default_collect_interval;
    gc_num.allocd = 0;

    #ifdef _P64
    // on a big memory machine, set max_collect_interval to totalmem / nthreads / 2
    uint64_t total_mem = uv_get_total_memory();
    uint64_t constrained_mem = uv_get_constrained_memory();
    if (constrained_mem != 0)
        total_mem = constrained_mem;
    size_t maxmem = total_mem / pyju_n_threads / 2;
    if (maxmem > max_collect_interval)
        max_collect_interval = maxmem;
    #endif
}

// Perm gen allocator
// 2M pool
#define GC_PERM_POOL_SIZE (2 * 1024 * 1024)
// 20k limit for pool allocation. At most 1% fragmentation
#define GC_PERM_POOL_LIMIT (20 * 1024)
uv_mutex_t gc_perm_lock;
static uintptr_t gc_perm_pool = 0;
static uintptr_t gc_perm_end = 0;


static void *gc_perm_alloc_large(size_t sz, int zero, unsigned align, unsigned offset) PYJU_NOTSAFEPOINT
{
    // `align` must be power of two
    assert(offset == 0 || offset < align);
    const size_t malloc_align = sizeof(void*) == 8 ? 16 : 4;
    if (align > 1 && (offset != 0 || align > malloc_align))
        sz += align - 1;
    int last_errno = errno;
    uintptr_t base = (uintptr_t)(zero ? calloc(1, sz) : malloc(sz));
    if (base == 0) {
        pyju_printf(PYJU_STDERR, "not impl pyju_throw(pyju_memory_exception)\n");
        abort();
        // pyju_throw(pyju_memory_exception);
    }
    errno = last_errno;
    pyju_may_leak(base);
    unsigned diff = (offset - base) % align;
    return (void*)(base + diff);
}


STATIC_INLINE void *gc_try_perm_alloc_pool(size_t sz, unsigned align, unsigned offset) PYJU_NOTSAFEPOINT
{
    uintptr_t pool = LLT_ALIGN(gc_perm_pool + offset, (uintptr_t)align) - offset;
    uintptr_t end = pool + sz;
    if (end > gc_perm_end)
        return NULL;
    gc_perm_pool = end;
    return (void*)pyju_assume(pool);
}

// **NOT** a safepoint
void *pyju_gc_perm_alloc_nolock(size_t sz, int zero, unsigned align, unsigned offset)
{
    // The caller should have acquired `gc_perm_lock`
    assert(align < GC_PERM_POOL_LIMIT);
#ifndef MEMDEBUG
    if (__unlikely(sz > GC_PERM_POOL_LIMIT))
#endif
        return gc_perm_alloc_large(sz, zero, align, offset);
    void *ptr = gc_try_perm_alloc_pool(sz, align, offset);
    if (__likely(ptr))
        return ptr;
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
    void *pool = VirtualAlloc(NULL, GC_PERM_POOL_SIZE, MEM_COMMIT, PAGE_READWRITE);
    SetLastError(last_error);
    errno = last_errno;
    if (__unlikely(pool == NULL))
        return NULL;
#else
    void *pool = mmap(0, GC_PERM_POOL_SIZE, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    errno = last_errno;
    if (__unlikely(pool == MAP_FAILED))
        return NULL;
#endif
    gc_perm_pool = (uintptr_t)pool;
    gc_perm_end = gc_perm_pool + GC_PERM_POOL_SIZE;
    return gc_try_perm_alloc_pool(sz, align, offset);
}

// **NOT** a safepoint
void *pyju_gc_perm_alloc(size_t sz, int zero, unsigned align, unsigned offset)
{
    assert(align < GC_PERM_POOL_LIMIT);
#ifndef MEMDEBUG
    if (__unlikely(sz > GC_PERM_POOL_LIMIT))
#endif
        return gc_perm_alloc_large(sz, zero, align, offset);
    uv_mutex_lock(&gc_perm_lock);
    void *p = pyju_gc_perm_alloc_nolock(sz, zero, align, offset);
    uv_mutex_unlock(&gc_perm_lock);
    return p;
}

// PYJU_DLLEXPORT void pyju_gc_add_finalizer(pyju_value_t *v, pyju_function_t *f)
// {
//     pyju_ptls_t ptls = pyju_current_task->ptls;
//     pyju_gc_add_finalizer_th(ptls, v, f);
// }

// PYJU_DLLEXPORT void pyju_finalize(pyju_value_t *o)
// {
//     pyju_finalize_th(pyju_current_task, o);
// }

// PYJU_DLLEXPORT pyju_weakref_t *pyju_gc_new_weakref(pyju_value_t *value)
// {
//     pyju_ptls_t ptls = pyju_current_task->ptls;
//     return pyju_gc_new_weakref_th(ptls, value);
// }

PYJU_DLLEXPORT PyjuValue_t *pyju_gc_allocobj(size_t sz)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    return pyju_gc_alloc(ptls, sz, NULL);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_0w(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    return pyju_gc_alloc(ptls, 0 + sizeof(PyjuTaggedValue_t), NULL);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_1w(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    return pyju_gc_alloc(ptls, sizeof(void*) + sizeof(PyjuTaggedValue_t), NULL);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_2w(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    return pyju_gc_alloc(ptls, sizeof(void*) * 2 + sizeof(PyjuTaggedValue_t), NULL);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_3w(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    return pyju_gc_alloc(ptls, sizeof(void*) * 3 + sizeof(PyjuTaggedValue_t), NULL);
}


PYJU_DLLEXPORT size_t pyju_gc_max_internal_obj_size(void)
{
    return GC_MAX_SZCLASS;
}

PYJU_DLLEXPORT size_t pyju_gc_external_obj_hdr_size(void)
{
    return sizeof(bigval_t);
}

PYJU_DLLEXPORT void * pyju_gc_alloc_typed(PyjuPtls_t ptls, size_t sz, void *ty)
{
    return pyju_gc_alloc(ptls, sz, ty);
}

#ifdef __cplusplus
}
#endif
