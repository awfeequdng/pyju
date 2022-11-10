
#include <stdlib.h>
#include <string.h>


#include "pyju.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

PyjuArray_t *pyju_global_roots_table;
static PyjuMutex_t global_roots_lock;


#ifdef __cplusplus
}
#endif