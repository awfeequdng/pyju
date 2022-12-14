#include <llvm/Support/TargetSelect.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h>
#include "llvm/ExecutionEngine/JITLink/JITLinkMemoryManager.h"
#include <memory>

#include "../ExampleModule.h"

using namespace llvm;
using namespace llvm::orc;

llvm::ExitOnError ExitOnErr;

// Expected<std::unique_ptr<ObjectLayer>> ObjectLayerCreator(ExecutionSession &ES,const Triple &TT) {
//     return std::make_unique<ObjectLinkingLayer>(ES, std::unique_ptr<jitlink::InProcessMemoryManager>());
// }

int main() {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    auto module = ExitOnErr(createModule());

    auto JTMB = ExitOnErr(JITTargetMachineBuilder::detectHost());
    JTMB.setCodeModel(CodeModel::Model::Small);

    // Create an LLJIT instance with an ObjectLinkingLayer as the base layer.
    auto ctx = module.getContext().getContext();

    // LLJITBuilderState::ObjectLinkingLayerCreator CreateObjectLinkingLayer = ObjectLayerCreator;
    LLJITBuilderState::ObjectLinkingLayerCreator CreateObjectLinkingLayer;
    auto lljit = ExitOnErr(LLJITBuilder()
        .setJITTargetMachineBuilder(JTMB)
        // .setObjectLinkingLayerCreator(CreateObjectLinkingLayer)
        // .setObjectLinkingLayerCreator([](ExecutionSession &ES,const Triple &TT) {
        //     return std::make_unique<ObjectLinkingLayer>(ES, std::make_unique<jitlink::InProcessMemoryManager>());
        // })
        .setObjectLinkingLayerCreator([](ExecutionSession &ES, const Triple &TT) {
            return std::make_unique<ObjectLinkingLayer>(ES, std::make_unique<jitlink::InProcessMemoryManager>());
        })
        .create());

    ExitOnErr(lljit->addIRModule(std::move(module)));

    auto sym = ExitOnErr(lljit->lookup("add"));

    auto add = (int (*)(int))sym.getAddress();
    auto res = add(1024);
    errs() << "add(1024) = " << res << "\n";

    return 0;
}