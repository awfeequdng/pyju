
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "pyju.h"
#include "pyju_internal.h"
#include "gc.h"
#include "threading.h"

#ifdef __cplusplus
extern "C" {
#endif

// thread sleep state

// default to DEFAULT_THREAD_SLEEP_THRESHOLD; set via $JULIA_THREAD_SLEEP_THRESHOLD
uint64_t sleep_threshold;

// thread should not be sleeping--it might need to do work.
static const int16_t not_sleeping = 0;

// it is acceptable for the thread to be sleeping.
static const int16_t sleeping = 1;


// invariant: No thread is ever asleep unless sleep_check_state is sleeping (or we have a wakeup signal pending).
// invariant: Any particular thread is not asleep unless that thread's sleep_check_state is sleeping.
// invariant: The transition of a thread state to sleeping must be followed by a check that there wasn't work pending for it.
// information: Observing thread not-sleeping is sufficient to ensure the target thread will subsequently inspect its local queue.
// information: Observing thread is-sleeping says it may be necessary to notify it at least once to wakeup. It may already be awake however for a variety of reasons.
// information: These observations require sequentially-consistent fences to be inserted between each of those operational phases.
// [^store_buffering_1]: These fences are used to avoid the cycle 2b -> 1a -> 1b -> 2a -> 2b where
// * Dequeuer:
//   * 1a: `pyju_atomic_store_relaxed(&ptls->sleep_check_state, sleeping)`
//   * 1b: `multiq_check_empty` returns true
// * Enqueuer:
//   * 2a: `multiq_insert`
//   * 2b: `pyju_atomic_load_relaxed(&ptls->sleep_check_state)` in `pyju_wakeup_thread` returns `not_sleeping`
// i.e., the dequeuer misses the enqueue and enqueuer misses the sleep state transition.
// [^store_buffering_2]: and also
// * Enqueuer:
//   * 1a: `pyju_atomic_store_relaxed(pyju_uv_n_waiters, 1)` in `PYJU_UV_LOCK`
//   * 1b: "cheap read" of `handle->pending` in `uv_async_send` (via `PYJU_UV_LOCK`) loads `0`
// * Dequeuer:
//   * 2a: store `2` to `handle->pending` in `uv_async_send` (via `PYJU_UV_LOCK` in `pyju_task_get_next`)
//   * 2b: `pyju_atomic_load_relaxed(pyju_uv_n_waiters)` in `pyju_task_get_next` returns `0`
// i.e., the dequeuer misses the `n_waiters` is set and enqueuer misses the `uv_stop` flag (in `signal_async`) transition to cleared

PYJU_DEBUG_SLEEPWAKE(
uint64_t wakeup_enter;
uint64_t wakeup_leave;
uint64_t io_wakeup_enter;
uint64_t io_wakeup_leave;
);

uv_mutex_t *sleep_locks;
uv_cond_t *wake_signals;

PYJU_DLLEXPORT int pyju_set_task_tid(PyjuTask_t *task, int tid) PYJU_NOTSAFEPOINT
{
    // Try to acquire the lock on this task.
    int16_t was = pyju_atomic_load_relaxed(&task->tid);
    if (was == tid)
        return 1;
    if (was == -1)
        return pyju_atomic_cmpswap(&task->tid, &was, tid);
    return 0;
}


// multiq
// ---

/* a task heap */
typedef struct taskheap_tag {
    uv_mutex_t lock;
    PyjuTask_t **tasks;
    _Atomic(int32_t) ntasks;
    _Atomic(int16_t) prio;
} taskheap_t;

/* multiqueue parameters */
static const int32_t heap_d = 8;
static const int heap_c = 2;

/* size of each heap */
static const int tasks_per_heap = 65536; // TODO: this should be smaller by default, but growable!

/* the multiqueue's heaps */
static taskheap_t *heaps;
static int32_t heap_p;

/* unbias state for the RNG */
static uint64_t cong_unbias;


static inline void multiq_init(void)
{
    heap_p = heap_c * pyju_n_threads;
    heaps = (taskheap_t *)calloc(heap_p, sizeof(taskheap_t));
    for (int32_t i = 0; i < heap_p; ++i) {
        uv_mutex_init(&heaps[i].lock);
        heaps[i].tasks = (PyjuTask_t **)calloc(tasks_per_heap, sizeof(PyjuTask_t*));
        pyju_atomic_store_relaxed(&heaps[i].ntasks, 0);
        pyju_atomic_store_relaxed(&heaps[i].prio, INT16_MAX);
    }
    unbias_cong(heap_p, &cong_unbias);
}

static inline void sift_up(taskheap_t *heap, int32_t idx)
{
    if (idx > 0) {
        int32_t parent = (idx-1)/heap_d;
        if (heap->tasks[idx]->prio < heap->tasks[parent]->prio) {
            PyjuTask_t *t = heap->tasks[parent];
            heap->tasks[parent] = heap->tasks[idx];
            heap->tasks[idx] = t;
            sift_up(heap, parent);
        }
    }
}

static inline void sift_down(taskheap_t *heap, int32_t idx)
{
    if (idx < pyju_atomic_load_relaxed(&heap->ntasks)) {
        for (int32_t child = heap_d*idx + 1;
                child < tasks_per_heap && child <= heap_d*idx + heap_d;
                ++child) {
            if (heap->tasks[child]
                    && heap->tasks[child]->prio < heap->tasks[idx]->prio) {
                PyjuTask_t *t = heap->tasks[idx];
                heap->tasks[idx] = heap->tasks[child];
                heap->tasks[child] = t;
                sift_down(heap, child);
            }
        }
    }
}

static inline int multiq_insert(PyjuTask_t *task, int16_t priority)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    uint64_t rn;

    task->prio = priority;
    do {
        rn = cong(heap_p, cong_unbias, &ptls->rngseed);
    } while (uv_mutex_trylock(&heaps[rn].lock) != 0);

    if (pyju_atomic_load_relaxed(&heaps[rn].ntasks) >= tasks_per_heap) {
        uv_mutex_unlock(&heaps[rn].lock);
        // multiq insertion failed, increase #tasks per heap
        return -1;
    }

    int32_t ntasks = pyju_atomic_load_relaxed(&heaps[rn].ntasks);
    pyju_atomic_store_relaxed(&heaps[rn].ntasks, ntasks + 1);
    heaps[rn].tasks[ntasks] = task;
    sift_up(&heaps[rn], ntasks);
    int16_t prio = pyju_atomic_load_relaxed(&heaps[rn].prio);
    if (task->prio < prio)
        pyju_atomic_store_relaxed(&heaps[rn].prio, task->prio);
    uv_mutex_unlock(&heaps[rn].lock);

    return 0;
}

static inline PyjuTask_t *multiq_deletemin(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    uint64_t rn1 = 0, rn2;
    int32_t i;
    int16_t prio1, prio2;
    PyjuTask_t *task;
 retry:
    pyju_gc_safepoint();
    for (i = 0; i < heap_p; ++i) {
        rn1 = cong(heap_p, cong_unbias, &ptls->rngseed);
        rn2 = cong(heap_p, cong_unbias, &ptls->rngseed);
        prio1 = pyju_atomic_load_relaxed(&heaps[rn1].prio);
        prio2 = pyju_atomic_load_relaxed(&heaps[rn2].prio);
        if (prio1 > prio2) {
            prio1 = prio2;
            rn1 = rn2;
        }
        else if (prio1 == prio2 && prio1 == INT16_MAX)
            continue;
        if (uv_mutex_trylock(&heaps[rn1].lock) == 0) {
            if (prio1 == pyju_atomic_load_relaxed(&heaps[rn1].prio))
                break;
            uv_mutex_unlock(&heaps[rn1].lock);
        }
    }
    if (i == heap_p)
        return NULL;

    task = heaps[rn1].tasks[0];
    if (!pyju_set_task_tid(task, ptls->tid)) {
        uv_mutex_unlock(&heaps[rn1].lock);
        goto retry;
    }
    int32_t ntasks = pyju_atomic_load_relaxed(&heaps[rn1].ntasks) - 1;
    pyju_atomic_store_relaxed(&heaps[rn1].ntasks, ntasks);
    heaps[rn1].tasks[0] = heaps[rn1].tasks[ntasks];
    heaps[rn1].tasks[ntasks] = NULL;
    prio1 = INT16_MAX;
    if (ntasks > 0) {
        sift_down(&heaps[rn1], 0);
        prio1 = heaps[rn1].tasks[0]->prio;
    }
    pyju_atomic_store_relaxed(&heaps[rn1].prio, prio1);
    uv_mutex_unlock(&heaps[rn1].lock);

    return task;
}


// void pyju_gc_mark_enqueued_tasks(pyju_gc_mark_cache_t *gc_cache, pyju_gc_mark_sp_t *sp)
// {
//     int32_t i, j;
//     for (i = 0; i < heap_p; ++i)
//         for (j = 0; j < pyju_atomic_load_relaxed(&heaps[i].ntasks); ++j)
//             pyju_gc_mark_queue_obj_explicit(gc_cache, sp, (pyju_value_t *)heaps[i].tasks[j]);
// }


static int multiq_check_empty(void)
{
    int32_t i;
    for (i = 0; i < heap_p; ++i) {
        if (pyju_atomic_load_relaxed(&heaps[i].ntasks) != 0)
            return 0;
    }
    return 1;
}


// parallel task runtime
// ---

// initialize the threading infrastructure
// (used only by the main thread)
void pyju_init_threadinginfra(void)
{
    /* initialize the synchronization trees pool and the multiqueue */
    multiq_init();

    sleep_threshold = DEFAULT_THREAD_SLEEP_THRESHOLD;
    char *cp = getenv(THREAD_SLEEP_THRESHOLD_NAME);
    if (cp) {
        if (!strncasecmp(cp, "infinite", 8))
            sleep_threshold = UINT64_MAX;
        else
            sleep_threshold = (uint64_t)strtol(cp, NULL, 10);
    }

    PyjuPtls_t ptls = pyju_current_task->ptls;
    pyju_install_thread_signal_handler(ptls);

    int16_t tid;
    sleep_locks = (uv_mutex_t*)calloc(pyju_n_threads, sizeof(uv_mutex_t));
    wake_signals = (uv_cond_t*)calloc(pyju_n_threads, sizeof(uv_cond_t));
    for (tid = 0; tid < pyju_n_threads; tid++) {
        uv_mutex_init(&sleep_locks[tid]);
        uv_cond_init(&wake_signals[tid]);
    }
}


void PYJU_NORETURN pyju_finish_task(PyjuTask_t *t);

// thread function: used by all except the main thread
void pyju_threadfun(void *arg)
{
    PyjuThreadArg_t *targ = (PyjuThreadArg_t*)arg;

    // initialize this thread (set tid, create heap, set up root task)
    PyjuPtls_t ptls = pyju_init_threadtls(targ->tid);
    void *stack_lo, *stack_hi;
    pyju_init_stack_limits(0, &stack_lo, &stack_hi);
    // warning: this changes `pyju_current_task`, so be careful not to call that from this function
    PyjuTask_t *ct = pyju_init_root_task(ptls, stack_lo, stack_hi);
    PYJU_GC_PROMISE_ROOTED(ct);
    pyju_install_thread_signal_handler(ptls);

    // wait for all threads
    pyju_gc_state_set(ptls, PYJU_GC_STATE_SAFE, 0);
    uv_barrier_wait(targ->barrier);

    // free the thread argument here
    free(targ);

    (void)pyju_gc_unsafe_enter(ptls);
    pyju_finish_task(ct); // noreturn
}

#ifdef __cplusplus
}
#endif
