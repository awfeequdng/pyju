

#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>

#include <llvm/IR/IRBuilder.h>
#include <memory>

using namespace llvm;

ExitOnError ExitOnErr;

orc::ThreadSafeModule createModule() {
    auto context = std::make_unique<LLVMContext>();
    auto module = std::make_unique<Module>("test", *context);
    auto FuncType = FunctionType::get(Type::getInt32Ty(*context), Type::getInt32Ty(*context), false);
    Function *funcAdd = Function::Create(FuncType, GlobalValue::LinkageTypes::ExternalLinkage, "add", module.get());

    BasicBlock* BB = BasicBlock::Create(*context, "Entry", funcAdd);
    IRBuilder<> builder(BB);
    // auto one = ConstantInt::get(Type::getInt32Ty(*context), 1);
    auto one = builder.getInt32(1);
    auto arg = funcAdd->getArg(0);
    arg->setName("arg");
    auto add = builder.CreateAdd(one, arg);
    builder.CreateRet(add);
    return orc::ThreadSafeModule(std::move(module), std::move(context));

}

int main(int argc, char **argv) {
    // InitLLVM x(argc, argv);
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    auto lljit = ExitOnErr(orc::LLJITBuilder().create());
    auto M = createModule();
    ExitOnErr(lljit->addIRModule(std::move(M)));
    auto sym = ExitOnErr(lljit->lookup("add"));
    int (*add)(int) = (int(*)(int))sym.getAddress();
    auto res = add(10);
    errs() << "add(10) = " << res << "\n";
    return 0;

}
