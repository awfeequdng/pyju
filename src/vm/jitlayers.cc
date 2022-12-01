#include "jitlayers.h"
#include <memory>
#include "pyju_internal.h"

#include <llvm/Support/SmallVectorMemoryBuffer.h>

#include "codegen_shared.h"

void pyju_init_jit(void) { }

// Snooping on which functions are being compiled, and how long it takes
PYJU_STREAM *dump_compiles_stream = NULL;

extern "C" PYJU_DLLEXPORT
void pyju_dump_compiles_impl(void *s)
{
    dump_compiles_stream = (PYJU_STREAM*)s;
}
PYJU_STREAM *dump_llvm_opt_stream = NULL;
extern "C" PYJU_DLLEXPORT
void pyju_dump_llvm_opt_impl(void *s)
{
    dump_llvm_opt_stream = (PYJU_STREAM*)s;
}

static void pyju_add_to_ee(std::unique_ptr<Module> m);
static void pyju_add_to_ee(std::unique_ptr<Module> &M, StringMap<std::unique_ptr<Module>*> &NewExports);
static uint64_t getAddressForFunction(StringRef fname);

void pyju_link_global(GlobalVariable *GV, void *addr)
{
    Constant *P = literal_static_pointer_val(addr, GV->getValueType());
    GV->setInitializer(P);
    if (pyju_options.image_codegen) {
        // If we are forcing imaging mode codegen for debugging,
        // emit external non-const symbol to avoid LLVM optimizing the code
        // similar to non-imaging mode.
        GV->setLinkage(GlobalValue::ExternalLinkage);
    }
    else {
        GV->setConstant(true);
        GV->setLinkage(GlobalValue::PrivateLinkage);
        GV->setUnnamedAddr(GlobalValue::UnnamedAddr::Global);
    }
}

void pyju_jit_globals(std::map<void *, GlobalVariable*> &globals)
{
    for (auto &global : globals) {
        pyju_link_global(global.second, global.first);
    }
}

static auto countBasicBlocks(const Function &F)
{
    return std::distance(F.begin(), F.end());
}

CompilerResultT PyjuOJIT::CompilerT::operator()(Module &M)
{
    uint64_t start_time = 0;
    if (dump_llvm_opt_stream != NULL) {
        // Print LLVM function statistics _before_ optimization
        // Print all the information about this invocation as a YAML object
        pyju_printf(dump_llvm_opt_stream, "- \n");
        // We print the name and some statistics for each function in the module, both
        // before optimization and again afterwards.
        pyju_printf(dump_llvm_opt_stream, "  before: \n");
        for (auto &F : M.functions()) {
            if (F.isDeclaration() || F.getName().startswith("jfptr_")) {
                continue;
            }
            // Each function is printed as a YAML object with several attributes
            pyju_printf(dump_llvm_opt_stream, "    \"%s\":\n", F.getName().str().c_str());
            pyju_printf(dump_llvm_opt_stream, "        instructions: %u\n", F.getInstructionCount());
            pyju_printf(dump_llvm_opt_stream, "        basicblocks: %lu\n", countBasicBlocks(F));
        }

        start_time = pyju_hrtime();
    }

    PYJU_TIMING(LLVM_OPT);

    int optlevel;
    int optlevel_min;
    if (pyju_generating_output()) {
        optlevel = 0;
    }
    else {
        optlevel = pyju_options.opt_level;
        optlevel_min = pyju_options.opt_level_min;
        for (auto &F : M.functions()) {
            if (!F.getBasicBlockList().empty()) {
                Attribute attr = F.getFnAttribute("pyju-optimization-level");
                StringRef val = attr.getValueAsString();
                if (val != "") {
                    int ol = (int)val[0] - '0';
                    if (ol >= 0 && ol < optlevel)
                        optlevel = ol;
                }
            }
        }
        optlevel = std::max(optlevel, optlevel_min);
    }
    if (optlevel == 0)
        jit.PM0.run(M);
    else if (optlevel == 1)
        jit.PM1.run(M);
    else if (optlevel == 2)
        jit.PM2.run(M);
    else if (optlevel >= 3)
        jit.PM3.run(M);

    std::unique_ptr<MemoryBuffer> ObjBuffer(
        new SmallVectorMemoryBuffer(std::move(jit.ObjBufferSV)));
    auto Obj = object::ObjectFile::createObjectFile(ObjBuffer->getMemBufferRef());

    if (!Obj) {
        llvm_dump(&M);
        std::string Buf;
        raw_string_ostream OS(Buf);
        logAllUnhandledErrors(Obj.takeError(), OS, "");
        OS.flush();
        llvm::report_fatal_error(llvm::Twine("FATAL: Unable to compile LLVM Module: '") + Buf + "'\n"
                                 "The module's content was printed above. Please file a bug report");
    }

    uint64_t end_time = 0;
    if (dump_llvm_opt_stream != NULL) {
        end_time = pyju_hrtime();
        pyju_printf(dump_llvm_opt_stream, "  time_ns: %" PRIu64 "\n", end_time - start_time);
        pyju_printf(dump_llvm_opt_stream, "  optlevel: %d\n", optlevel);

        // Print LLVM function statistics _after_ optimization
        pyju_printf(dump_llvm_opt_stream, "  after: \n");
        for (auto &F : M.functions()) {
            if (F.isDeclaration() || F.getName().startswith("jfptr_")) {
                continue;
            }
            pyju_printf(dump_llvm_opt_stream, "    \"%s\":\n", F.getName().str().c_str());
            pyju_printf(dump_llvm_opt_stream, "        instructions: %u\n", F.getInstructionCount());
            pyju_printf(dump_llvm_opt_stream, "        basicblocks: %lu\n", countBasicBlocks(F));
        }
    }

    return CompilerResultT(std::move(ObjBuffer));
}

void pyju_register_jit_object(const object::ObjectFile &debugObj,
                            std::function<uint64_t(const StringRef &)> getLoadAddress,
                            std::function<void *(void *)> lookupWriteAddress);


RTDyldMemoryManager* createRTDyldMemoryManager(void);

// A simple forwarding class, since OrcJIT v2 needs a unique_ptr, while we have a shared_ptr
class ForwardingMemoryManager : public RuntimeDyld::MemoryManager {
private:
    std::shared_ptr<RuntimeDyld::MemoryManager> MemMgr;

public:
    ForwardingMemoryManager(std::shared_ptr<RuntimeDyld::MemoryManager> MemMgr) : MemMgr(MemMgr) {}
    virtual ~ForwardingMemoryManager() = default;
    virtual uint8_t *allocateCodeSection(uintptr_t Size, unsigned Alignment,
                                     unsigned SectionID,
                                     StringRef SectionName) override {
        return MemMgr->allocateCodeSection(Size, Alignment, SectionID, SectionName);
    }
    virtual uint8_t *allocateDataSection(uintptr_t Size, unsigned Alignment,
                                     unsigned SectionID,
                                     StringRef SectionName,
                                     bool IsReadOnly) override {
        return MemMgr->allocateDataSection(Size, Alignment, SectionID, SectionName, IsReadOnly);
    }
    virtual void reserveAllocationSpace(uintptr_t CodeSize, uint32_t CodeAlign,
                                        uintptr_t RODataSize,
                                        uint32_t RODataAlign,
                                        uintptr_t RWDataSize,
                                        uint32_t RWDataAlign) override {
        return MemMgr->reserveAllocationSpace(CodeSize, CodeAlign, RODataSize, RODataAlign, RWDataSize, RWDataAlign);
    }
    virtual bool needsToReserveAllocationSpace() override {
        return MemMgr->needsToReserveAllocationSpace();
    }
    virtual void registerEHFrames(uint8_t *Addr, uint64_t LoadAddr,
                                  size_t Size) override {
        return MemMgr->registerEHFrames(Addr, LoadAddr, Size);
    }
    virtual void deregisterEHFrames() override {
        return MemMgr->deregisterEHFrames();
    }
    virtual bool finalizeMemory(std::string *ErrMsg = nullptr) override {
        return MemMgr->finalizeMemory(ErrMsg);
    }
    virtual void notifyObjectLoaded(RuntimeDyld &RTDyld,
                                    const object::ObjectFile &Obj) override {
        return MemMgr->notifyObjectLoaded(RTDyld, Obj);
    }
};

PyjuOJIT::PyjuOJIT(TargetMachine &tm, LLVMContext *ctx)
  : TM(tm),
    DL(tm.createDataLayout()),
    ObjStream(ObjBufferSV),
    TSCtx(std::unique_ptr<LLVMContext>(ctx)),
#if PYJU_LLVM_VERSION >= 130000
    ES(cantFail(orc::SelfExecutorProcessControl::Create())),
#else
    ES(),
#endif
    GlobalJD(ES.createBareJITDylib("PyjuGlobals")),
    JD(ES.createBareJITDylib("PyjuOJIT")),
#ifdef JL_USE_JITLINK
    // TODO: Port our memory management optimisations to JITLink instead of using the
    // default InProcessMemoryManager.
# if JL_LLVM_VERSION < 140000
    ObjectLayer(ES, std::make_unique<jitlink::InProcessMemoryManager>()),
# else
    ObjectLayer(ES, cantFail(jitlink::InProcessMemoryManager::Create())),
# endif
#else
    MemMgr(createRTDyldMemoryManager()),
    ObjectLayer(
            ES,
            [this]() {
                std::unique_ptr<RuntimeDyld::MemoryManager> result(new ForwardingMemoryManager(MemMgr));
                return result;
            }
        ),
#endif
    CompileLayer(ES, ObjectLayer, std::make_unique<CompilerT>(this))
{

}
