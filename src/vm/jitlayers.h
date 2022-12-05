#include <llvm/ExecutionEngine/Orc/IRCompileLayer.h>

#ifdef JL_USE_JITLINK
# include <llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h>
#else
# include <llvm/ExecutionEngine/RTDyldMemoryManager.h>
# include <llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#endif

#include "llvm/IR/LegacyPassManager.h"
#include <llvm/IR/Constants.h>

// #include "llvm/IR/LLVMContext.h"
// #include "llvm/IR/Type.h"
#include "llvm/Target/TargetMachine.h"

#include "pyju_assert.h"
#include "pyju.h"

using namespace llvm;

extern TargetMachine *pyju_TargetMachine;
void addTargetPasses(legacy::PassManagerBase *PM, TargetMachine *TM);
void addOptimizationPasses(legacy::PassManagerBase *PM, int opt_level, bool lower_intrinsics=true, bool dump_native=false);
void addMachinePasses(legacy::PassManagerBase *PM, TargetMachine *TM, int optlevel);

void pyju_jit_init();

static inline Constant *literal_static_pointer_val(const void *p, Type *T)
{
    // this function will emit a static pointer into the generated code
    // the generated code will only be valid during the current session,
    // and thus, this should typically be avoided in new API's
#if defined(_P64)
    return ConstantExpr::getIntToPtr(ConstantInt::get(Type::getInt64Ty(T->getContext()), (uint64_t)p), T);
#else
    return ConstantExpr::getIntToPtr(ConstantInt::get(Type::getInt32Ty(T->getContext()), (uint32_t)p), T);
#endif
}


typedef JITSymbol PYJU_JITSymbol;
// The type that is similar to SymbolInfo on LLVM 4.0 is actually
// `JITEvaluatedSymbol`. However, we only use this type when a JITSymbol
// is expected.
typedef JITSymbol PYJU_SymbolInfo;

using CompilerResultT = Expected<std::unique_ptr<llvm::MemoryBuffer>>;

class PyjuOJIT {
private:
    struct CompilerT : public orc::IRCompileLayer::IRCompiler {
        CompilerT(PyjuOJIT *pjit)
            : IRCompiler(orc::IRSymbolMapper::ManglingOptions{}),
             jit(*pjit) {}
        virtual CompilerResultT operator()(Module &M) override;
    private:
        PyjuOJIT &jit;
    };
    // Custom object emission notification handler for the JuliaOJIT
    template <typename ObjT, typename LoadResult>
    void registerObject(const ObjT &Obj, const LoadResult &LO);

public:
#ifdef JL_USE_JITLINK
    typedef orc::ObjectLinkingLayer ObjLayerT;
#else
    typedef orc::RTDyldObjectLinkingLayer ObjLayerT;
#endif

    typedef orc::IRCompileLayer CompileLayerT;
    typedef object::OwningBinary<object::ObjectFile> OwningObj;

    PyjuOJIT(TargetMachine &TM, LLVMContext *Ctx);

    void enableJITDebuggingSupport();
#ifndef PYJU_USE_JITLINK
    // JITLink doesn't support old JITEventListeners (yet).
    void RegisterJITEventListener(JITEventListener *L);
#endif

    orc::SymbolStringPtr mangle(StringRef Name);
    void addGlobalMapping(StringRef Name, uint64_t Addr);
    void addModule(std::unique_ptr<Module> M);

    PYJU_JITSymbol findSymbol(StringRef Name, bool ExportedSymbolsOnly);
    PYJU_JITSymbol findUnmangledSymbol(StringRef Name);

    uint64_t getGlobalValueAddress(StringRef Name);
    uint64_t getFunctionAddress(StringRef Name);
    StringRef getFunctionAtAddress(uint64_t Addr, PyjuCodeInstance_t *codeinst);
    const DataLayout& getDataLayout() const;
    const Triple& getTargetTriple() const;
    size_t getTotalBytes() const;

    // JITDebugInfoRegistry &getDebugInfoRegistry() JL_NOTSAFEPOINT {
    //     return DebugRegistry;
    // }
private:
    std::string getMangledName(StringRef Name);
    std::string getMangledName(const GlobalValue *GV);

    TargetMachine &TM;
    const DataLayout DL;
    // Should be big enough that in the common case, The
    // object fits in its entirety
    SmallVector<char, 4096> ObjBufferSV;
    raw_svector_ostream ObjStream;
    legacy::PassManager PM0;  // per-optlevel pass managers
    legacy::PassManager PM1;
    legacy::PassManager PM2;
    legacy::PassManager PM3;
    TargetMachine *TMs[4];

    // Context object for machine code objects
    MCContext *Ctx;

    orc::ThreadSafeContext TSCtx;
    orc::ExecutionSession ES;
    orc::JITDylib &GlobalJD;
    orc::JITDylib &JD;

    // JITDebugInfoRegistry DebugRegistry;

#ifndef JL_USE_JITLINK
    std::shared_ptr<RTDyldMemoryManager> MemMgr;
#endif
    ObjLayerT ObjectLayer;
    CompileLayerT CompileLayer;

    DenseMap<void*, std::string> ReverseLocalSymbolTable;
};

extern PyjuOJIT *jl_ExecutionEngine;

Pass *createDemoteFloat16Pass();
