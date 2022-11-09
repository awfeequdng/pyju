#include "support/platform.h"

#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// current line number in a file
PYJU_DLLEXPORT int pyju_lineno = 0; // need to update jl_critical_error if this is TLS
// current file name
PYJU_DLLEXPORT const char *pyju_filename = "none"; // need to update jl_critical_error if this is TLS

htable_t pyju_current_modules;
PyjuMutex_t pyju_modules_mutex;

PYJU_DLLEXPORT void pyju_add_standard_imports(PyjuModule_t *m)
{
    PyjuModule_t *base_module = pyju_base_relative_to(m);
    assert(base_module != NULL);
    // using Base
    pyju_module_using(m, base_module);
}

// module referenced by (top ...) from within m
// this is only needed because of the bootstrapping process:
// - initially Base doesn't exist and top === Core
// - later, it refers to either old Base or new Base
PYJU_DLLEXPORT PyjuModule_t *pyju_base_relative_to(PyjuModule_t *m)
{
    for (;;) {
        if (m->istopmod)
            return m;
        if (m == m->parent)
            break;
        m = m->parent;
    }
    return pyju_top_module;
}

#ifdef __cplusplus
}
#endif
