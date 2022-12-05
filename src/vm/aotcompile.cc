
#include "pyju.h"
#include "pyju_internal.h"
#include "jitlayers.h"
#include "pyju_assert.h"

// target support
#include <llvm/ADT/Triple.h>
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/Analysis/TargetTransformInfo.h>
#include <llvm/IR/DataLayout.h>
#if JL_LLVM_VERSION >= 140000
#include <llvm/MC/TargetRegistry.h>
#else
#include <llvm/Support/TargetRegistry.h>
#endif
#include <llvm/Target/TargetMachine.h>


// analysis passes
#include <llvm/Analysis/Passes.h>
#include <llvm/Analysis/BasicAliasAnalysis.h>
#include <llvm/Analysis/TypeBasedAliasAnalysis.h>
#include <llvm/Analysis/ScopedNoAliasAA.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Transforms/IPO.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Vectorize.h>
#include <llvm/Transforms/Instrumentation/AddressSanitizer.h>
#include <llvm/Transforms/Instrumentation/ThreadSanitizer.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/IPO/AlwaysInliner.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar/InstSimplifyPass.h>
#include <llvm/Transforms/Utils/SimplifyCFGOptions.h>
#include <llvm/Transforms/Utils/ModuleUtils.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>
#if defined(USE_POLLY)
#include <polly/RegisterPasses.h>
#include <polly/LinkAllPasses.h>
#include <polly/CodeGen/CodegenCleanup.h>
#if defined(USE_POLLY_ACC)
#include <polly/Support/LinkGPURuntime.h>
#endif
#endif

// for outputting code
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Bitcode/BitcodeWriterPass.h>
#include "llvm/Object/ArchiveWriter.h"
#include <llvm/IR/IRPrintingPasses.h>

#include <llvm/IR/LegacyPassManagers.h>
#include <llvm/Transforms/Utils/Cloning.h>


template<class T> // for GlobalObject's
static T *addComdat(T *G)
{
#if defined(_OS_WINDOWS_)
    if (!G->isDeclaration()) {
        // add __declspec(dllexport) to everything marked for export
        if (G->getLinkage() == GlobalValue::ExternalLinkage)
            G->setDLLStorageClass(GlobalValue::DLLExportStorageClass);
        else
            G->setDLLStorageClass(GlobalValue::DefaultStorageClass);
    }
#endif
    return G;
}

typedef struct {
    std::unique_ptr<Module> M;
    std::vector<GlobalValue*> pyju_sysimg_fvars;
    std::vector<GlobalValue*> pyju_sysimg_gvars;
    std::map<PyjuCodeInstance_t*, std::tuple<uint32_t, uint32_t>> pyju_fvar_map;
    std::map<void*, int32_t> pyju_value_to_llvm; // uses 1-based indexing
} pyju_native_code_desc_t;

extern "C" PYJU_DLLEXPORT
void pyju_get_function_id_impl(void *native_code, PyjuCodeInstance_t *codeinst,
        int32_t *func_idx, int32_t *specfunc_idx)
{
    pyju_native_code_desc_t *data = (pyju_native_code_desc_t*)native_code;
    if (data) {
        // get the function index in the fvar lookup table
        auto it = data->pyju_fvar_map.find(codeinst);
        if (it != data->pyju_fvar_map.end()) {
            std::tie(*func_idx, *specfunc_idx) = it->second;
        }
    }
}

extern "C" PYJU_DLLEXPORT
int32_t pyju_get_llvm_gv_impl(void *native_code, PyjuValue_t *p)
{
    // map a jl_value_t memory location to a GlobalVariable
    pyju_native_code_desc_t *data = (pyju_native_code_desc_t*)native_code;
    if (data) {
        auto it = data->pyju_value_to_llvm.find(p);
        if (it != data->pyju_value_to_llvm.end()) {
            return it->second;
        }
    }
    return 0;
}


extern "C" PYJU_DLLEXPORT
Module* pyju_get_llvm_module_impl(void *native_code)
{
    pyju_native_code_desc_t *data = (pyju_native_code_desc_t*)native_code;
    if (data)
        return data->M.get();
    else
        return NULL;
}

extern "C" PYJU_DLLEXPORT
GlobalValue* pyju_get_llvm_function_impl(void *native_code, uint32_t idx)
{
    pyju_native_code_desc_t *data = (pyju_native_code_desc_t*)native_code;
    if (data)
        return data->pyju_sysimg_fvars[idx];
    else
        return NULL;
}

extern "C" PYJU_DLLEXPORT
LLVMContext* pyju_get_llvm_context_impl(void *native_code)
{
    pyju_native_code_desc_t *data = (pyju_native_code_desc_t*)native_code;
    if (data)
        return &data->M->getContext();
    else
        return NULL;
}

static bool is_safe_char(unsigned char c)
{
    return ('0' <= c && c <= '9') ||
           ('A' <= c && c <= 'Z') ||
           ('a' <= c && c <= 'z') ||
           (c == '_' || c == '$') ||
           (c >= 128 && c < 255);
}

static const char hexchars[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void addTargetPasses(legacy::PassManagerBase *PM, TargetMachine *TM)
{
    PM->add(new TargetLibraryInfoWrapperPass(Triple(TM->getTargetTriple())));
    PM->add(createTargetTransformInfoWrapperPass(TM->getTargetIRAnalysis()));
}


void addMachinePasses(legacy::PassManagerBase *PM, TargetMachine *TM, int optlevel)
{
    // TODO: don't do this on CPUs that natively support Float16
    PM->add(createDemoteFloat16Pass());
    if (optlevel > 1)
        PM->add(createGVNPass());
}

// this defines the set of optimization passes defined for Julia at various optimization levels.
// it assumes that the TLI and TTI wrapper passes have already been added.
void addOptimizationPasses(legacy::PassManagerBase *PM, int opt_level,
                           bool lower_intrinsics, bool dump_native)
{
//     // Note: LLVM 12 disabled the hoisting of common instruction
//     //       before loop vectorization (https://reviews.llvm.org/D84108).
//     //
//     // TODO: CommonInstruction hoisting/sinking enables AllocOpt
//     //       to merge allocations and sometimes eliminate them,
//     //       since AllocOpt does not handle PhiNodes.
//     //       Enable this instruction hoisting because of this and Union benchmarks.
//     auto simplifyCFGOptions = SimplifyCFGOptions().hoistCommonInsts(true);
// #ifdef JL_DEBUG_BUILD
//     PM->add(createGCInvariantVerifierPass(true));
//     PM->add(createVerifierPass());
// #endif

//     PM->add(createConstantMergePass());
//     if (opt_level < 2) {
//         if (!dump_native) {
//             // we won't be multiversioning, so lower CPU feature checks early on
//             // so that we can avoid an additional CFG simplification pass at the end.
//             PM->add(createCPUFeaturesPass());
//             if (opt_level == 1)
//                 PM->add(createInstSimplifyLegacyPass());
//         }
//         PM->add(createCFGSimplificationPass(simplifyCFGOptions));
//         if (opt_level == 1) {
//             PM->add(createSROAPass());
//             PM->add(createInstructionCombiningPass());
//             PM->add(createEarlyCSEPass());
//             // maybe add GVN?
//             // also try GVNHoist and GVNSink
//         }
//         PM->add(createMemCpyOptPass());
//         PM->add(createAlwaysInlinerLegacyPass()); // Respect always_inline
//         PM->add(createLowerSimdLoopPass()); // Annotate loop marked with "loopinfo" as LLVM parallel loop
//         if (lower_intrinsics) {
//             PM->add(createBarrierNoopPass());
//             PM->add(createLowerExcHandlersPass());
//             PM->add(createGCInvariantVerifierPass(false));
//             PM->add(createRemoveNIPass());
//             PM->add(createLateLowerGCFramePass());
//             PM->add(createFinalLowerGCPass());
//             PM->add(createLowerPTLSPass(dump_native));
//         }
//         else {
//             PM->add(createRemoveNIPass());
//         }
//         PM->add(createLowerSimdLoopPass()); // Annotate loop marked with "loopinfo" as LLVM parallel loop
//         if (dump_native) {
//             PM->add(createMultiVersioningPass());
//             PM->add(createCPUFeaturesPass());
//             // minimal clean-up to get rid of CPU feature checks
//             if (opt_level == 1) {
//                 PM->add(createInstSimplifyLegacyPass());
//                 PM->add(createCFGSimplificationPass(simplifyCFGOptions));
//             }
//         }
// #if defined(_COMPILER_ASAN_ENABLED_)
//         PM->add(createAddressSanitizerFunctionPass());
// #endif
// #if defined(_COMPILER_MSAN_ENABLED_)
//         PM->add(createMemorySanitizerPass(true));
// #endif
// #if defined(_COMPILER_TSAN_ENABLED_)
//         PM->add(createThreadSanitizerLegacyPassPass());
// #endif
//         return;
//     }
//     PM->add(createPropagateJuliaAddrspaces());
//     PM->add(createScopedNoAliasAAWrapperPass());
//     PM->add(createTypeBasedAAWrapperPass());
//     if (opt_level >= 3) {
//         PM->add(createBasicAAWrapperPass());
//     }

//     PM->add(createCFGSimplificationPass(simplifyCFGOptions));
//     PM->add(createDeadCodeEliminationPass());
//     PM->add(createSROAPass());

//     //PM->add(createMemCpyOptPass());

//     PM->add(createAlwaysInlinerLegacyPass()); // Respect always_inline

//     // Running `memcpyopt` between this and `sroa` seems to give `sroa` a hard time
//     // merging the `alloca` for the unboxed data and the `alloca` created by the `alloc_opt`
//     // pass.
//     PM->add(createAllocOptPass());
//     // consider AggressiveInstCombinePass at optlevel > 2
//     PM->add(createInstructionCombiningPass());
//     PM->add(createCFGSimplificationPass(simplifyCFGOptions));
//     if (dump_native)
//         PM->add(createMultiVersioningPass());
//     PM->add(createCPUFeaturesPass());
//     PM->add(createSROAPass());
//     PM->add(createInstSimplifyLegacyPass());
//     PM->add(createJumpThreadingPass());
//     PM->add(createCorrelatedValuePropagationPass());

//     PM->add(createReassociatePass());

//     PM->add(createEarlyCSEPass());

//     // Load forwarding above can expose allocations that aren't actually used
//     // remove those before optimizing loops.
//     PM->add(createAllocOptPass());
//     PM->add(createLoopRotatePass());
//     // moving IndVarSimplify here prevented removing the loop in perf_sumcartesian(10:-1:1)
// #ifdef USE_POLLY
//     // LCSSA (which has already run at this point due to the dependencies of the
//     // above passes) introduces redundant phis that hinder Polly. Therefore we
//     // run InstCombine here to remove them.
//     PM->add(createInstructionCombiningPass());
//     PM->add(polly::createCodePreparationPass());
//     polly::registerPollyPasses(*PM);
//     PM->add(polly::createCodegenCleanupPass());
// #endif
//     // LoopRotate strips metadata from terminator, so run LowerSIMD afterwards
//     PM->add(createLowerSimdLoopPass()); // Annotate loop marked with "loopinfo" as LLVM parallel loop
//     PM->add(createLICMPass());
//     PM->add(createJuliaLICMPass());
//     PM->add(createLoopUnswitchPass());
//     PM->add(createLICMPass());
//     PM->add(createJuliaLICMPass());
//     PM->add(createInductiveRangeCheckEliminationPass()); // Must come before indvars
//     // Subsequent passes not stripping metadata from terminator
//     PM->add(createInstSimplifyLegacyPass());
//     PM->add(createLoopIdiomPass());
//     PM->add(createIndVarSimplifyPass());
//     PM->add(createLoopDeletionPass());
//     PM->add(createSimpleLoopUnrollPass());

//     // Run our own SROA on heap objects before LLVM's
//     PM->add(createAllocOptPass());
//     // Re-run SROA after loop-unrolling (useful for small loops that operate,
//     // over the structure of an aggregate)
//     PM->add(createSROAPass());
//     // might not be necessary:
//     PM->add(createInstSimplifyLegacyPass());

//     PM->add(createGVNPass());
//     PM->add(createMemCpyOptPass());
//     PM->add(createSCCPPass());

//     //These next two passes must come before IRCE to eliminate the bounds check in #43308
//     PM->add(createCorrelatedValuePropagationPass());
//     PM->add(createDeadCodeEliminationPass());

//     PM->add(createInductiveRangeCheckEliminationPass()); // Must come between the two GVN passes

//     // Run instcombine after redundancy elimination to exploit opportunities
//     // opened up by them.
//     // This needs to be InstCombine instead of InstSimplify to allow
//     // loops over Union-typed arrays to vectorize.
//     PM->add(createInstructionCombiningPass());
//     PM->add(createJumpThreadingPass());
//     if (opt_level >= 3) {
//         PM->add(createGVNPass()); // Must come after JumpThreading and before LoopVectorize
//     }
//     PM->add(createDeadStoreEliminationPass());

//     // More dead allocation (store) deletion before loop optimization
//     // consider removing this:
//     PM->add(createAllocOptPass());
//     // see if all of the constant folding has exposed more loops
//     // to simplification and deletion
//     // this helps significantly with cleaning up iteration
//     PM->add(createCFGSimplificationPass()); // See note above, don't hoist instructions before LV
//     PM->add(createLoopDeletionPass());
//     PM->add(createInstructionCombiningPass());
//     PM->add(createLoopVectorizePass());
//     PM->add(createLoopLoadEliminationPass());
//     // Cleanup after LV pass
//     PM->add(createInstructionCombiningPass());
//     PM->add(createCFGSimplificationPass( // Aggressive CFG simplification
//         SimplifyCFGOptions()
//             .forwardSwitchCondToPhi(true)
//             .convertSwitchToLookupTable(true)
//             .needCanonicalLoops(false)
//             .hoistCommonInsts(true)
//             // .sinkCommonInsts(true) // FIXME: Causes assertion in llvm-late-lowering
//     ));
//     PM->add(createSLPVectorizerPass());
//     // might need this after LLVM 11:
//     //PM->add(createVectorCombinePass());

//     PM->add(createAggressiveDCEPass());

//     if (lower_intrinsics) {
//         // LowerPTLS removes an indirect call. As a result, it is likely to trigger
//         // LLVM's devirtualization heuristics, which would result in the entire
//         // pass pipeline being re-exectuted. Prevent this by inserting a barrier.
//         PM->add(createBarrierNoopPass());
//         PM->add(createLowerExcHandlersPass());
//         PM->add(createGCInvariantVerifierPass(false));
//         // Needed **before** LateLowerGCFrame on LLVM < 12
//         // due to bug in `CreateAlignmentAssumption`.
//         PM->add(createRemoveNIPass());
//         PM->add(createLateLowerGCFramePass());
//         PM->add(createFinalLowerGCPass());
//         // We need these two passes and the instcombine below
//         // after GC lowering to let LLVM do some constant propagation on the tags.
//         // and remove some unnecessary write barrier checks.
//         PM->add(createGVNPass());
//         PM->add(createSCCPPass());
//         // Remove dead use of ptls
//         PM->add(createDeadCodeEliminationPass());
//         PM->add(createLowerPTLSPass(dump_native));
//         PM->add(createInstructionCombiningPass());
//         // Clean up write barrier and ptls lowering
//         PM->add(createCFGSimplificationPass());
//     }
//     else {
//         PM->add(createRemoveNIPass());
//     }
//     PM->add(createCombineMulAddPass());
//     PM->add(createDivRemPairsPass());
// #if defined(_COMPILER_ASAN_ENABLED_)
//     PM->add(createAddressSanitizerFunctionPass());
// #endif
// #if defined(_COMPILER_MSAN_ENABLED_)
//     PM->add(createMemorySanitizerPass(true));
// #endif
// #if defined(_COMPILER_TSAN_ENABLED_)
//     PM->add(createThreadSanitizerLegacyPassPass());
// #endif
}

// An LLVM module pass that just runs all julia passes in order. Useful for
// debugging
template <int OptLevel>
class PyjuPipeline : public Pass {
public:
    static char ID;
    PyjuPipeline() : Pass(PT_PassManager, ID) {}

    struct TPMAdaptor : PassManagerBase {
        PMTopLevelManager *TPM;
        TPMAdaptor(PMTopLevelManager *tpm) : TPM(tpm) {}
        void add(Pass *p) override {
            TPM->schedulePass(p);
        }
    };
    void preparePassManager(PMStack &stack) override {
        // pyju_init_llvm();
        PMTopLevelManager *tpm = stack.top()->getTopLevelManager();
        TPMAdaptor adaptor(tpm);
        addTargetPasses(&adaptor, pyju_TargetMachine);
        addOptimizationPasses(&adaptor, OptLevel);
        addMachinePasses(&adaptor, pyju_TargetMachine, OptLevel);

    }
    Pass *createPrinterPass(raw_ostream &O, const std::string &Banner) const override {
        return createPrintModulePass(O, Banner);
    }
};
template<> char PyjuPipeline<0>::ID = 0;
template<> char PyjuPipeline<2>::ID = 0;
template<> char PyjuPipeline<3>::ID = 0;

static RegisterPass<PyjuPipeline<0>> X("pyjuO0", "run the entire pyju pipiline (at -O0", false, false);
static RegisterPass<PyjuPipeline<2>> Y("pyjuO2", "run the entire pyju pipiline (at -O2", false, false);
static RegisterPass<PyjuPipeline<3>> Z("pyjuO3", "run the entire pyju pipiline (at -O3", false, false);

