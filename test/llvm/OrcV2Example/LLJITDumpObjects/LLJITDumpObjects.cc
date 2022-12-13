
#include <algorithm>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/ObjectTransformLayer.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
// #include <llvm/Support/InitLLVM.h>
#include <memory>

#include "../ExampleModule.h"

using namespace llvm;
using namespace llvm::orc;

llvm::ExitOnError ExitOnErr;


int main() {
    // InitLLVM x(argc, argv);
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    auto M = ExitOnErr(createModule());
    auto lljit = ExitOnErr(LLJITBuilder().create());
    lljit->getObjTransformLayer().setTransform(DumpObjects("./", "add"));
    ExitOnErr(lljit->addIRModule(std::move(M)));
    auto sym = ExitOnErr(lljit->lookup("add"));
    int (*add)(int) = (int (*)(int))sym.getAddress();
    auto ret = add(10);
    errs() << "add(10) = " << ret << "\n";
    return 0;
}