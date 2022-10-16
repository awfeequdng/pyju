#pragma once

#include "pyju_exported_data.inc"
#include "support/dtypes.h"
#include "pyju_options.h"

// Define pointer data as `const void * $(name);`
#define XX(name)    PYJU_DLLEXPORT const void * name;
PYJU_EXPORTED_DATA_POINTERS(XX)
#undef XX

// Define symbol data as `$(type) $(name);`
#define XX(name, type)    PYJU_DLLEXPORT type name;
PYJU_EXPORTED_DATA_SYMBOLS(XX)
#undef XX

