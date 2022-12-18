#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/Support/TargetSelect.h>

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/IPO.h>
#include <llvm/Transforms/Scalar.h>

#include "../ExampleModule.h"


using namespace llvm;
using namespace llvm::orc;

ExitOnError ExitOnErr;


// Example IR module.
//
// This IR contains a recursive definition of the factorial function:
//
// fac(n) | n == 0    = 1
//        | otherwise = n * fac(n - 1)
//
// It also contains an entry function which calls the factorial function with
// an input value of 5.
//
// We expect the IR optimization transform that we build below to transform
// this into a non-recursive factorial function and an entry function that
// returns a constant value of 5!, or 120.

const llvm::StringRef TestMod =
    R"(

  define i32 @fac(i32 %n) {
  entry:
    %tobool = icmp eq i32 %n, 0
    br i1 %tobool, label %return, label %if.then

  if.then:                                          ; preds = %entry
    %arg = add nsw i32 %n, -1
    %call_result = call i32 @fac(i32 %arg)
    %result = mul nsw i32 %n, %call_result
    br label %return

  return:                                           ; preds = %entry, %if.then
    %final_result = phi i32 [ %result, %if.then ], [ 1, %entry ]
    ret i32 %final_result
  }

  define i32 @entry() {
  entry:
    %result = call i32 @fac(i32 5)
    ret i32 %result
  }

)";

class MyOptimizationTransform {
public:
    MyOptimizationTransform() : PM(std::make_unique<legacy::PassManager>()) {
        PM->add(createTailCallEliminationPass());
        PM->add(createFunctionInliningPass());
        PM->add(createIndVarSimplifyPass());
        PM->add(createCFGSimplificationPass());
    }

    Expected<ThreadSafeModule> operator() (ThreadSafeModule TSM, MaterializationResponsibility &mr) {
        TSM.withModuleDo([this](Module &M) {
            dbgs() << "--- BEFORE OPTIMIZATION ---\n" << M << "\n";
            PM->run(M);
            dbgs() << "--- AFTER OPTIMIZATION ---\n" << M << "\n";
        });
        return std::move(TSM);
    }

private:
    std::unique_ptr<legacy::PassManager> PM;
};

int main() {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    auto M = ExitOnErr(createModule(TestMod));

    auto jit = ExitOnErr(LLJITBuilder().create());

    jit->getIRTransformLayer().setTransform(MyOptimizationTransform());

    ExitOnErr(jit->addIRModule(std::move(M)));

    auto sym = ExitOnErr(jit->lookup("entry"));

    auto entry = (int (*)())sym.getAddress();
    outs() << "result = " << entry() << "\n";
    return 0;
}