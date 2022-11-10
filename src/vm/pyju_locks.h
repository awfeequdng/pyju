// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_LOCKS_H
#define PYJU_LOCKS_H

#include "pyju_assert.h"
#include "pyju.h"

#ifdef __cplusplus
extern "C" {
#endif


// Lock acquire and release primitives

// PYJU_LOCK and pyju_mutex_lock are GC safe points, use uv_mutex_t if that is not desired.
// Always use PYJU_LOCK unless no one holding the lock can trigger a GC or GC
// safepoint. uv_mutex_t should only be needed for GC internal locks.
// The PYJU_LOCK* and PYJU_UNLOCK* macros are no-op for non-threading build
// while the pyju_mutex_* functions are always locking and unlocking the locks.

static inline void pyju_mutex_wait(PyjuMutex_t *lock, int safepoint)
{
    PyjuTask_t *self = pyju_current_task;
    PyjuTask_t *owner = pyju_atomic_load_relaxed(&lock->owner);
    if (owner == self) {
        lock->count++;
        return;
    }
    while (1) {
        if (owner == NULL && pyju_atomic_cmpswap(&lock->owner, &owner, self)) {
            lock->count = 1;
            return;
        }
        if (safepoint) {
            pyju_gc_safepoint_(self->ptls);
        }
        pyju_cpu_pause();
        owner = pyju_atomic_load_relaxed(&lock->owner);
    }
}

static inline void pyju_mutex_lock_nogc(PyjuMutex_t *lock) PYJU_NOTSAFEPOINT
{
#ifndef __clang_gcanalyzer__
    // Hide this body from the analyzer, otherwise it complains that we're calling
    // a non-safepoint from this function. The 0 arguments guarantees that we do
    // not reach the safepoint, but the analyzer can't figure that out
    pyju_mutex_wait(lock, 0);
#endif
}

static inline void pyju_lock_frame_push(PyjuMutex_t *lock)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    small_arraylist_t *locks = &ptls->locks;
    uint32_t len = locks->len;
    if (__unlikely(len >= locks->max)) {
        small_arraylist_grow(locks, 1);
    }
    else {
        locks->len = len + 1;
    }
    locks->items[len] = (void*)lock;
}
static inline void pyju_lock_frame_pop(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    assert(ptls->locks.len > 0);
    ptls->locks.len--;
}

#define PYJU_SIGATOMIC_BEGIN() do {               \
        pyju_current_task->ptls->defer_signal++;  \
        pyju_signal_fence();                      \
    } while (0)
#define PYJU_SIGATOMIC_END() do {                                 \
        pyju_signal_fence();                                      \
        if (--pyju_current_task->ptls->defer_signal == 0) {       \
            pyju_sigint_safepoint(pyju_current_task->ptls);         \
        }                                                       \
    } while (0)


static inline void pyju_mutex_lock(PyjuMutex_t *lock)
{
    PYJU_SIGATOMIC_BEGIN();
    pyju_mutex_wait(lock, 1);
    pyju_lock_frame_push(lock);
}

static inline int pyju_mutex_trylock_nogc(PyjuMutex_t *lock)
{
    PyjuTask_t *self = pyju_current_task;
    PyjuTask_t *owner = pyju_atomic_load_acquire(&lock->owner);
    if (owner == self) {
        lock->count++;
        return 1;
    }
    if (owner == NULL && pyju_atomic_cmpswap(&lock->owner, &owner, self)) {
        lock->count = 1;
        return 1;
    }
    return 0;
}


static inline int pyju_mutex_trylock(PyjuMutex_t *lock)
{
    int got = pyju_mutex_trylock_nogc(lock);
    if (got) {
        PYJU_SIGATOMIC_BEGIN();
        pyju_lock_frame_push(lock);
    }
    return got;
}


static inline void pyju_mutex_unlock_nogc(PyjuMutex_t *lock) PYJU_NOTSAFEPOINT
{
#ifndef __clang_gcanalyzer__
    assert(pyju_atomic_load_relaxed(&lock->owner) == pyju_current_task &&
           "Unlocking a lock in a different thread.");
    if (--lock->count == 0) {
        pyju_atomic_store_release(&lock->owner, (PyjuTask_t*)NULL);
        pyju_cpu_wake();
    }
#endif
}


static inline void pyju_mutex_unlock(PyjuMutex_t *lock)
{
    pyju_mutex_unlock_nogc(lock);
    pyju_lock_frame_pop();
    PYJU_SIGATOMIC_END();
    if (pyju_atomic_load_relaxed(&pyju_gc_have_pending_finalizers)) {
        pyju_gc_run_pending_finalizers(pyju_current_task); // may GC
    }
}

static inline void pyju_mutex_init(PyjuMutex_t *lock) PYJU_NOTSAFEPOINT
{
    pyju_atomic_store_relaxed(&lock->owner, (PyjuTask_t*)NULL);
    lock->count = 0;
}

#define PYJU_MUTEX_INIT(m) pyju_mutex_init(m)
#define PYJU_LOCK(m) pyju_mutex_lock(m)
#define PYJU_UNLOCK(m) pyju_mutex_unlock(m)
#define PYJU_LOCK_NOGC(m) pyju_mutex_lock_nogc(m)
#define PYJU_UNLOCK_NOGC(m) pyju_mutex_unlock_nogc(m)

#ifdef __cplusplus
}
#endif

#endif
