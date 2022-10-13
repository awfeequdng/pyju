#include "pyju_internal.h"


#ifdef __cplusplus
extern "C" {
#endif

// allocating TypeNames -----------------------------------------------------------

static int is10digit(char c) PYJU_NOTSAFEPOINT
{
    return (c >= '0' && c <= '9');
}

// PyjuDataType_t *pyju_new_uninitialized_datatype(void) {
//     // PyjuTask_t *ct = pyju_current_task;
// }


#ifdef __cplusplus
} // extern "C"
#endif