#include <stdlib.h>

#include "pyju.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT int pyju_generating_output(void)
{
    return pyju_options.outputo || pyju_options.outputbc || pyju_options.outputunoptbc || pyju_options.outputji || pyju_options.outputasm;
}

#ifdef __cplusplus
} // extern "C"
#endif
