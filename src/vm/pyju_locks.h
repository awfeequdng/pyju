// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_LOCKS_H
#define PYJU_LOCKS_H

#include "pyju_assert.h"
#include "pyju_object.h"

#ifdef __cplusplus
extern "C" {
#endif


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
