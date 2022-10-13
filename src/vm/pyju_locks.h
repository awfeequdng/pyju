// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_LOCKS_H
#define PYJU_LOCKS_H

#include "pyju_assert.h"
#include "pyju_threads.h"
#include "support/dtypes.h"
#ifdef __cplusplus
extern "C" {
#endif

// Lock acquire and release primitives

// PYJU_LOCK and pyju_mutex_lock are GC safe points, use uv_mutex_t if that is not desired.
// Always use PYJU_LOCK unless no one holding the lock can trigger a GC or GC
// safepoint. uv_mutex_t should only be needed for GC internal locks.
// The PYJU_LOCK* and PYJU_UNLOCK* macros are no-op for non-threading build
// while the pyju_mutex_* functions are always locking and unlocking the locks.
struct PyjuTask_t;

PYJU_DLLEXPORT void _pyju_mutex_wait(PyjuTask_t *self, PyjuMutex_t *lock, int safepoint);
PYJU_DLLEXPORT void _pyju_mutex_lock(PyjuTask_t *self, PyjuMutex_t *lock);
PYJU_DLLEXPORT int _pyju_mutex_trylock_nogc(PyjuTask_t *self, PyjuMutex_t *lock) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int _pyju_mutex_trylock(PyjuTask_t *self, PyjuMutex_t *lock);
PYJU_DLLEXPORT void _pyju_mutex_unlock(PyjuTask_t *self, PyjuMutex_t *lock);
PYJU_DLLEXPORT void _pyju_mutex_unlock_nogc(PyjuMutex_t *lock) PYJU_NOTSAFEPOINT;

static inline void pyju_mutex_wait(PyjuMutex_t *lock, int safepoint)
{
    _pyju_mutex_wait(pyju_current_task, lock, safepoint);
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

#define PYJU_SIGATOMIC_BEGIN_self() do {          \
        self->ptls->defer_signal++;             \
        pyju_signal_fence();                      \
    } while (0)
#define PYJU_SIGATOMIC_END_self() do {            \
        pyju_signal_fence();                      \
        if (--self->ptls->defer_signal == 0) {  \
            pyju_sigint_safepoint(self->ptls);    \
        }                                       \
    } while (0)

static inline void pyju_mutex_lock(PyjuMutex_t *lock)
{
    _pyju_mutex_lock(pyju_current_task, lock);
}

static inline int pyju_mutex_trylock_nogc(PyjuMutex_t *lock) PYJU_NOTSAFEPOINT
{
    return _pyju_mutex_trylock_nogc(pyju_current_task, lock);
}

static inline int pyju_mutex_trylock(PyjuMutex_t *lock)
{
    return _pyju_mutex_trylock(pyju_current_task, lock);
}

static inline void pyju_mutex_unlock(PyjuMutex_t *lock)
{
    _pyju_mutex_unlock(pyju_current_task, lock);
}

static inline void pyju_mutex_unlock_nogc(PyjuMutex_t *lock) PYJU_NOTSAFEPOINT
{
    _pyju_mutex_unlock_nogc(lock);
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
