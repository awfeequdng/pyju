#pragma once

#include "pyju_exported_data.inc"
#include "support/dtypes.h"

// Define pointer data as `const void * $(name);`
#define XX(name)    PYJU_DLLEXPORT const void * name;
PYJU_EXPORTED_DATA_POINTERS(XX)
#undef XX
