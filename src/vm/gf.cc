
/*
  Generic Functions
  . method table and lookup
  . GF constructor
  . dispatch
  . static parameter inference
  . method specialization and caching, invoking type inference
*/
#include <stdlib.h>
#include <string.h>
#include "pyju.h"
#include "pyju_internal.h"
#include <unistd.h>
#include "pyju_assert.h"

// The compilation signature is not used to cache the method if the number of overlapping methods is greater than this
#define MAX_UNSPECIALIZED_CONFLICTS 32

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT _Atomic(size_t) pyju_world_counter = 1; // uses atomic acquire/release
PYJU_DLLEXPORT size_t pyju_get_world_counter(void) PYJU_NOTSAFEPOINT
{
    return pyju_atomic_load_acquire(&pyju_world_counter);
}

PYJU_DLLEXPORT size_t pyju_get_tls_world_age(void) PYJU_NOTSAFEPOINT
{
    return pyju_current_task->world_age;
}

#ifdef __cplusplus
}
#endif