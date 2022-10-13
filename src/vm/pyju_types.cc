#include <cstddef>
#include <stdlib.h>
#include <string.h>

#include "pyju_object.h"
#include "pyju_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

_Atomic(PyjuValue_t*) cmpswap_names PYJU_GLOBALLY_ROOTED;

// compute empirical max-probe for a given size
#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)
#define h2index(hv, sz) (size_t)((hv) & ((sz)-1))

// --- type properties and predicates ---

static int typeenv_has(PyjuTypeEnv_t *env, PyjuTVar_t *v) PYJU_NOTSAFEPOINT
{
    while (env != NULL) {
        if (env->var == v)
            return 1;
        env = env->prev;
    }
    return 0;
}


void pyju_init_types(void) PYJU_GC_DISABLED {
    PyjuModule_t *core = nullptr;

    // create base objects
    // pyju_datatype_type = pyju_new_uninilialized_datatype();
    pyju_datatype_type = nullptr;
}

#ifdef __cplusplus
}   // extern "C"
#endif