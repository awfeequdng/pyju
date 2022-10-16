

#include "support/platform.h"

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>
#include "pyju_object.h"
#include "pyju_internal.h"
#include "threading.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ALWAYS_COPY_STACKS
# ifndef COPY_STACKS
# error "ALWAYS_COPY_STACKS requires COPY_STACKS"
# endif
static int always_copy_stacks = 1;
#else
static int always_copy_stacks = 0;
#endif

// Do one-time initializations for task system
void pyju_init_tasks(void) PYJU_GC_DISABLED
{
    char *acs = getenv("JULIA_COPY_STACKS");
    if (acs) {
        if (!strcmp(acs, "1") || !strcmp(acs, "yes"))
            always_copy_stacks = 1;
        else if (!strcmp(acs, "0") || !strcmp(acs, "no"))
            always_copy_stacks = 0;
        else {
            pyju_safe_printf("invalid JULIA_COPY_STACKS value: %s\n", acs);
            exit(1);
        }
    }
#ifndef COPY_STACKS
    if (always_copy_stacks) {
        pyju_safe_printf("Julia built without COPY_STACKS support");
        exit(1);
    }
#endif
}

// a version of jl_current_task safe for unmanaged threads
PYJU_DLLEXPORT PyjuTask_t *pyju_get_current_task(void)
{
    PyjuGcFrame_t **pgcstack = pyju_get_pgcstack();
    return pgcstack == NULL ? NULL : container_of(pgcstack, PyjuTask_t, gcstack);
}

#ifdef __cplusplus
}
#endif