#include "llvm-version.h"
#include "support/platform.h"
#include "support/dtypes.h"

#if defined(_OS_WINDOWS_)
// use ELF because RuntimeDyld COFF i686 support didn't exist
// use ELF because RuntimeDyld COFF X86_64 doesn't seem to work (fails to generate function pointers)?
#define FORCE_ELF
#endif
#if defined(_CPU_X86_)
#define JL_NEED_FLOATTEMP_VAR 1
#endif
#if defined(_OS_WINDOWS_) || defined(_OS_FREEBSD_)
#define JL_DISABLE_FPO
#endif


#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
#endif

#include <setjmp.h>
#include <string>
#include <fstream>
#include <map>
#include <array>
#include <vector>
#include <set>
#include <functional>


extern "C" PYJU_DLLEXPORT void pyju_init_codegen_impl(void)
{

}