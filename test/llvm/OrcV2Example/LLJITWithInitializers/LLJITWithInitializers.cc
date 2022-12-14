#include <cstdint>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/Support/TargetSelect.h>

#include "../ExampleModule.h"

llvm::ExitOnError ExitOnErr;

using namespace llvm;
using namespace llvm::orc;

StringRef TestMod = R"(
@InitializedFlag = external global i32
@DeInitializedFlag = external global i32

declare i32 @__cxa_atexit(void(i8*)*, i8*, i8*)
@__dso_handle = external hidden global i8

@llvm.global_ctors =
    appending global [1 x {i32, void()*, i8*}]
    [{i32, void()*, i8*}{i32 65535, void()* @init_flag, i8* null}]

define void @init_flag() {
entry:
    store i32 1, i32 *@InitializedFlag
    call i32 @__cxa_atexit(void(i8*)* @deinit_flag, i8* null, i8* @__dso_handle)
    ret void
}

define void @deinit_flag(i8* %0) {
    store i32 2, i32* @DeInitializedFlag
    ret void
}


)";

int main () {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    auto M = ExitOnErr(createModule(TestMod));
    auto lljit = ExitOnErr(LLJITBuilder().create());
    ExitOnErr(lljit->addIRModule(std::move(M)));

    int32_t InitializedFlag = 0;
    int32_t DeInitializedFlag = 0;


    ExitOnErr(lljit->getMainJITDylib().define(absoluteSymbols({
        {lljit->mangleAndIntern("InitializedFlag"), JITEvaluatedSymbol::fromPointer(&InitializedFlag)},
        {lljit->mangleAndIntern("DeInitializedFlag"), JITEvaluatedSymbol::fromPointer(&DeInitializedFlag)}
    })));

    ExitOnErr(lljit->initialize(lljit->getMainJITDylib()));

    ExitOnErr(lljit->deinitialize(lljit->getMainJITDylib()));

    outs() << "InitializedFlag: " << InitializedFlag << "\n"
           << "DeInitializedFlag: " << DeInitializedFlag << "\n";

    return 0;
}