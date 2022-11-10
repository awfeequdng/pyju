#include "support/platform.h"

#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#include "pyju.h"
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


// create a new top-level module
void pyju_init_main_module(void)
{
    assert(pyju_main_module == NULL);
    pyju_main_module = pyju_new_module(pyju_symbol("Main"));
    pyju_main_module->parent = pyju_main_module;
    pyju_set_const(pyju_main_module, pyju_symbol("Core"),
                 (PyjuValue_t*)pyju_core_module);
    pyju_set_const(pyju_core_module, pyju_symbol("Main"),
                 (PyjuValue_t*)pyju_main_module);
}

// static PyjuFunction_t *pyju_module_get_initializer(PyjuModule_t *m PYJU_PROPAGATES_ROOT)
// {
//     return (PyjuFunction_t*)pyju_get_global(m, pyju_symbol("__init__"));
// }


#ifdef __cplusplus
}
#endif
