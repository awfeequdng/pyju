#include "pyju_internal.h"

/*
  defining DataTypes
  basic operations on struct and bits values
*/


#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "pyju_gcext.h"

#ifdef __cplusplus
extern "C" {
#endif

// allocating TypeNames -----------------------------------------------------------

static int is10digit(char c) PYJU_NOTSAFEPOINT
{
    return (c >= '0' && c <= '9');
}

PyjuDataType_t *pyju_new_uninitialized_datatype(void) {
    PyjuTask_t *ct = pyju_current_task;
    PyjuDataType_t *t = (PyjuDataType_t*)pyju_gc_alloc(ct->ptls, sizeof(PyjuDataType_t), pyju_datatype_type);
    t->hash = 0;
    t->hasfreetypevars = 0;
    t->isdispatchtuple = 0;
    t->isbitstype = 0;
    t->zeroinit = 0;
    t->has_concrete_subtype = 1;
    t->cached_by_hash = 0;
    t->name = NULL;
    t->super = NULL;
    t->parameters = NULL;
    t->layout = NULL;
    t->types = NULL;
    t->instance = NULL;

    return t;
}


#ifdef __cplusplus
} // extern "C"
#endif