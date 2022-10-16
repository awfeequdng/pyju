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

#ifdef __cplusplus
}
#endif
