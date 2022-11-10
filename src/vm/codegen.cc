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

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Type.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

//Drag some useful type functions into our namespace
//to reduce verbosity of our code
auto getInt1Ty(LLVMContext &ctxt) {
    return Type::getInt1Ty(ctxt);
}
auto getInt8Ty(LLVMContext &ctxt) {
    return Type::getInt8Ty(ctxt);
}
auto getInt16Ty(LLVMContext &ctxt) {
    return Type::getInt16Ty(ctxt);
}
auto getInt32Ty(LLVMContext &ctxt) {
    return Type::getInt32Ty(ctxt);
}
auto getInt64Ty(LLVMContext &ctxt) {
    return Type::getInt64Ty(ctxt);
}
auto getHalfTy(LLVMContext &ctxt) {
    return Type::getHalfTy(ctxt);
}
auto getFloatTy(LLVMContext &ctxt) {
    return Type::getFloatTy(ctxt);
}
auto getDoubleTy(LLVMContext &ctxt) {
    return Type::getDoubleTy(ctxt);
}
auto getFP128Ty(LLVMContext &ctxt) {
    return Type::getFP128Ty(ctxt);
}
auto getVoidTy(LLVMContext &ctxt) {
    return Type::getVoidTy(ctxt);
}
auto getCharTy(LLVMContext &ctxt) {
    return getInt32Ty(ctxt);
}
auto getSizeTy(LLVMContext &ctxt) {
    if (sizeof(size_t) > sizeof(uint32_t)) {
        return getInt64Ty(ctxt);
    } else {
        return getInt32Ty(ctxt);
    }
}
auto getInt8PtrTy(LLVMContext &ctxt) {
    return Type::getInt8PtrTy(ctxt);
}
auto getInt16PtrTy(LLVMContext &ctxt) {
    return Type::getInt16PtrTy(ctxt);
}
auto getInt32PtrTy(LLVMContext &ctxt) {
    return Type::getInt32PtrTy(ctxt);
}
auto getInt64PtrTy(LLVMContext &ctxt) {
    return Type::getInt64PtrTy(ctxt);
}
auto getFloatPtrTy(LLVMContext &ctxt) {
    return Type::getFloatPtrTy(ctxt);
}
auto getDoublePtrTy(LLVMContext &ctxt) {
    return Type::getDoublePtrTy(ctxt);
}
auto getSizePtrTy(LLVMContext &ctxt) {
    if (sizeof(size_t) > sizeof(uint32_t)) {
        return getInt64PtrTy(ctxt);
    } else {
        return getInt32PtrTy(ctxt);
    }
}

#include "pyju.h"
#include "pyju_internal.h"
// #include "jitlayers.h"
// #include "codegen_shared.h"
// #include "processor.h"
#include "pyju_assert.h"

PYJU_STREAM *dump_emitted_mi_name_stream = NULL;
extern "C" PYJU_DLLEXPORT
void pyju_dump_emitted_mi_name_impl(void *s)
{
    dump_emitted_mi_name_stream = (PYJU_STREAM*)s;
}


extern "C" {

// #include "builtin_proto.h"

extern void __stack_chk_fail();

#ifdef _OS_WINDOWS_
#if defined(_CPU_X86_64_)
#if defined(_COMPILER_GCC_)
extern void ___chkstk_ms(void);
#else
extern void __chkstk(void);
#endif
#else
#if defined(_COMPILER_GCC_)
#undef _alloca
extern void _alloca(void);
#else
extern void _chkstk(void);
#endif
#endif
//void *force_chkstk(void) {
//    return alloca(40960);
//}
#endif
} // extern "C"

// for image reloading
bool imaging_mode = false;

// shared llvm state
static LLVMContext &pyju_LLVMContext = *(new LLVMContext());
TargetMachine *pyju_TargetMachine;
static DataLayout &pyju_data_layout = *(new DataLayout(""));

extern "C" PYJU_DLLEXPORT void pyju_init_codegen_impl(void)
{

}
