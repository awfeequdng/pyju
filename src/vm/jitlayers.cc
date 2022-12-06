#include "jitlayers.h"
#include <memory>
#include "pyju_internal.h"

#ifdef PYJU_USE_JITLINK
# if PYJU_LLVM_VERSION >= 140000
#  include <llvm/ExecutionEngine/Orc/DebuggerSupportPlugin.h>
# endif
# include <llvm/ExecutionEngine/JITLink/EHFrameSupport.h>
# include <llvm/ExecutionEngine/JITLink/JITLinkMemoryManager.h>
#else
# include <llvm/ExecutionEngine/SectionMemoryManager.h>
#endif
#include <llvm/IR/Mangler.h>
#include <llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/SmallVectorMemoryBuffer.h>
#include <llvm/Target/TargetMachine.h>
#if JL_LLVM_VERSION >= 140000
#include <llvm/MC/TargetRegistry.h>
#else
#include <llvm/Support/TargetRegistry.h>
#endif

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

PyjuOJIT *pyju_ExecutionEngine;

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
static void addPassesForOptLevel(legacy::PassManager &PM, TargetMachine &TM, raw_svector_ostream &ObjStream, MCContext *Ctx, int optlevel)
{
    addTargetPasses(&PM, &TM);
    addOptimizationPasses(&PM, optlevel);
    addMachinePasses(&PM, &TM, optlevel);
    if (TM.addPassesToEmitMC(PM, Ctx, ObjStream))
        llvm_unreachable("Target does not support MC emission.");
}

CodeGenOpt::Level CodeGenOptLevelFor(int optlevel)
{
#ifdef DISABLE_OPT
    return CodeGenOpt::None;
#else
    return optlevel < 2 ? CodeGenOpt::None :
        optlevel == 2 ? CodeGenOpt::Default :
        CodeGenOpt::Aggressive;
#endif
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

void registerRTDyldJITObject(const object::ObjectFile &Object,
                             const RuntimeDyld::LoadedObjectInfo &L,
                             const std::shared_ptr<RTDyldMemoryManager> &MemMgr)
{
    auto SavedObject = L.getObjectForDebug(Object).takeBinary();
    // If the debug object is unavailable, save (a copy of) the original object
    // for our backtraces.
    // This copy seems unfortunate, but there doesn't seem to be a way to take
    // ownership of the original buffer.
    if (!SavedObject.first) {
        auto NewBuffer =
            MemoryBuffer::getMemBufferCopy(Object.getData(), Object.getFileName());
        auto NewObj =
            cantFail(object::ObjectFile::createObjectFile(NewBuffer->getMemBufferRef()));
        SavedObject = std::make_pair(std::move(NewObj), std::move(NewBuffer));
    }
    const object::ObjectFile *DebugObj = SavedObject.first.release();
    SavedObject.second.release();

    StringMap<object::SectionRef> loadedSections;
    // Use the original Object, not the DebugObject, as this is used for the
    // RuntimeDyld::LoadedObjectInfo lookup.
    for (const object::SectionRef &lSection : Object.sections()) {
        auto sName = lSection.getName();
        if (sName) {
            bool inserted = loadedSections.insert(std::make_pair(*sName, lSection)).second;
            assert(inserted);
            (void)inserted;
        }
    }
    auto getLoadAddress = [loadedSections = std::move(loadedSections),
                           &L](const StringRef &sName) -> uint64_t {
        auto search = loadedSections.find(sName);
        if (search == loadedSections.end())
            return 0;
        return L.getSectionLoadAddress(search->second);
    };

    pyju_register_jit_object(*DebugObj, getLoadAddress, nullptr);
}



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
#ifdef PYJU_USE_JITLINK
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
#ifdef PYJU_USE_JITLINK
# if defined(_OS_DARWIN_) && defined(LLVM_SHLIB)
    // When dynamically linking against LLVM, use our custom EH frame registration code
    // also used with RTDyld to inform both our and the libc copy of libunwind.
    auto ehRegistrar = std::make_unique<JLEHFrameRegistrar>();
# else
    auto ehRegistrar = std::make_unique<jitlink::InProcessEHFrameRegistrar>();
# endif
    ObjectLayer.addPlugin(std::make_unique<EHFrameRegistrationPlugin>(
        ES, std::move(ehRegistrar)));

    ObjectLayer.addPlugin(std::make_unique<JLDebuginfoPlugin>());
#else
    ObjectLayer.setNotifyLoaded(
        [this](orc::MaterializationResponsibility &MR,
               const object::ObjectFile &Object,
               const RuntimeDyld::LoadedObjectInfo &LO) {
            registerRTDyldJITObject(Object, LO, MemMgr);
        });
#endif
    for (int i = 0; i < 4; i++) {
        TMs[i] = TM.getTarget().createTargetMachine(TM.getTargetTriple().getTriple(), TM.getTargetCPU(),
                TM.getTargetFeatureString(), TM.Options, Reloc::Static, TM.getCodeModel(),
                CodeGenOptLevelFor(i), true);
    }
    addPassesForOptLevel(PM0, *TMs[0], ObjStream, Ctx, 0);
    addPassesForOptLevel(PM1, *TMs[1], ObjStream, Ctx, 1);
    addPassesForOptLevel(PM2, *TMs[2], ObjStream, Ctx, 2);
    addPassesForOptLevel(PM3, *TMs[3], ObjStream, Ctx, 3);

    // Make sure SectionMemoryManager::getSymbolAddressInProcess can resolve
    // symbols in the program as well. The nullptr argument to the function
    // tells DynamicLibrary to load the program, not a library.
    std::string ErrorStr;
    if (sys::DynamicLibrary::LoadLibraryPermanently(nullptr, &ErrorStr))
        report_fatal_error(llvm::Twine("FATAL: unable to dlopen self\n") + ErrorStr);
    GlobalJD.addGenerator(
      cantFail(orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(
        DL.getGlobalPrefix())));
    // Resolve non-lock free atomic functions in the libatomic1 library.
    // This is the library that provides support for c11/c++11 atomic operations.
    const char *const libatomic = "libatomic.so.1";

    if (libatomic) {
        printf("not impl load dynamic library\n");
        // static void *atomic_hdl = pyju_load_dynamic_library(libatomic, PYJU_RTLD_LOCAL, 0);
        // if (atomic_hdl != NULL) {
        //     GlobalJD.addGenerator(
        //       cantFail(orc::DynamicLibrarySearchGenerator::Load(
        //           libatomic,
        //           DL.getGlobalPrefix(),
        //           [&](const orc::SymbolStringPtr &S) {
        //                 const char *const atomic_prefix = "__atomic_";
        //                 return (*S).startswith(atomic_prefix);
        //           })));
        // }
    }
    JD.addToLinkOrder(GlobalJD, orc::JITDylibLookupFlags::MatchExportedSymbolsOnly);

    orc::SymbolAliasMap jl_crt = {
        { mangle("__gnu_h2f_ieee"), { mangle("julia__gnu_h2f_ieee"), JITSymbolFlags::Exported } },
        { mangle("__extendhfsf2"),  { mangle("julia__gnu_h2f_ieee"), JITSymbolFlags::Exported } },
        { mangle("__gnu_f2h_ieee"), { mangle("julia__gnu_f2h_ieee"), JITSymbolFlags::Exported } },
        { mangle("__truncsfhf2"),   { mangle("julia__gnu_f2h_ieee"), JITSymbolFlags::Exported } },
        { mangle("__truncdfhf2"),   { mangle("julia__truncdfhf2"),   JITSymbolFlags::Exported } }
    };
    cantFail(GlobalJD.define(orc::symbolAliases(jl_crt)));

}

orc::SymbolStringPtr PyjuOJIT::mangle(StringRef Name)
{
    std::string MangleName = getMangledName(Name);
    return ES.intern(MangleName);
}

void PyjuOJIT::addGlobalMapping(StringRef Name, uint64_t Addr)
{
    cantFail(JD.define(orc::absoluteSymbols({{mangle(Name), JITEvaluatedSymbol::fromPointer((void*)Addr)}})));
}


void PyjuOJIT::addModule(std::unique_ptr<Module> M)
{
    PYJU_TIMING(LLVM_MODULE_FINISH);
    std::vector<std::string> NewExports;
    for (auto &F : M->global_values()) {
        if (!F.isDeclaration() && F.getLinkage() == GlobalValue::ExternalLinkage) {
            NewExports.push_back(getMangledName(F.getName()));
        }
    }
#if !defined(JL_NDEBUG) && !defined(PYJU_USE_JITLINK)
    // validate the relocations for M (not implemented for the JITLink memory manager yet)
    for (Module::global_object_iterator I = M->global_objects().begin(), E = M->global_objects().end(); I != E; ) {
        GlobalObject *F = &*I;
        ++I;
        if (F->isDeclaration()) {
            if (F->use_empty())
                F->eraseFromParent();
            else if (!((isa<Function>(F) && isIntrinsicFunction(cast<Function>(F))) ||
                       findUnmangledSymbol(F->getName()) ||
                       SectionMemoryManager::getSymbolAddressInProcess(
                           getMangledName(F->getName())))) {
                llvm::errs() << "FATAL ERROR: "
                             << "Symbol \"" << F->getName().str() << "\""
                             << "not found";
                abort();
            }
        }
    }
#endif
    // TODO: what is the performance characteristics of this?
    cantFail(CompileLayer.add(JD, orc::ThreadSafeModule(std::move(M), TSCtx)));
    // force eager compilation (for now), due to memory management specifics
    // (can't handle compilation recursion)
    for (auto Name : NewExports)
        cantFail(ES.lookup({&JD}, Name));

}

PYJU_JITSymbol PyjuOJIT::findSymbol(StringRef Name, bool ExportedSymbolsOnly)
{
    orc::JITDylib* SearchOrders[2] = {&GlobalJD, &JD};
    ArrayRef<orc::JITDylib*> SearchOrder = makeArrayRef(&SearchOrders[ExportedSymbolsOnly ? 0 : 1], ExportedSymbolsOnly ? 2 : 1);
    auto Sym = ES.lookup(SearchOrder, Name);
    if (Sym)
        return *Sym;
    return Sym.takeError();
}

PYJU_JITSymbol PyjuOJIT::findUnmangledSymbol(StringRef Name)
{
    return findSymbol(getMangledName(Name), true);
}

uint64_t PyjuOJIT::getGlobalValueAddress(StringRef Name)
{
    auto addr = findSymbol(getMangledName(Name), false);
    if (!addr) {
        consumeError(addr.takeError());
        return 0;
    }
    return cantFail(addr.getAddress());
}

uint64_t PyjuOJIT::getFunctionAddress(StringRef Name)
{
    auto addr = findSymbol(getMangledName(Name), false);
    if (!addr) {
        consumeError(addr.takeError());
        return 0;
    }
    return cantFail(addr.getAddress());
}


static int globalUniqueGeneratedNames;
// StringRef PyjuOJIT::getFunctionAtAddress(uint64_t Addr, PyjuCodeInstance_t *codeinst)
// {
//     std::string *fname = &ReverseLocalSymbolTable[(void*)(uintptr_t)Addr];
//     if (fname->empty()) {
//         std::string string_fname;
//         raw_string_ostream stream_fname(string_fname);
//         // try to pick an appropriate name that describes it
//         auto invoke = pyju_atomic_load_relaxed(&codeinst->invoke);
//         if (Addr == (uintptr_t)invoke) {
//             stream_fname << "jsysw_";
//         }
//         else if (invoke == pyju_fptr_args_addr) {
//             stream_fname << "jsys1_";
//         }
//         else if (invoke == pyju_fptr_sparam_addr) {
//             stream_fname << "jsys3_";
//         }
//         else {
//             stream_fname << "jlsys_";
//         }
//         const char* unadorned_name = pyju_symbol_name(codeinst->def->def.method->name);
//         stream_fname << unadorned_name << "_" << globalUniqueGeneratedNames++;
//         *fname = std::move(stream_fname.str()); // store to ReverseLocalSymbolTable
//         addGlobalMapping(*fname, Addr);
//     }
//     return *fname;
// }


#ifdef PYJU_USE_JITLINK
# if JL_LLVM_VERSION < 140000
#  warning "JIT debugging (GDB integration) not available on LLVM < 14.0 (for JITLink)"
void PyjuOJIT::enableJITDebuggingSupport() {}
# else
extern "C" orc::shared::CWrapperFunctionResult
llvm_orc_registerJITLoaderGDBAllocAction(const char *Data, size_t Size);

void PyjuOJIT::enableJITDebuggingSupport()
{
    // We do not use GDBJITDebugInfoRegistrationPlugin::Create, as the runtime name
    // lookup is unnecessarily involved/fragile for our in-process JIT use case
    // (with the llvm_orc_registerJITLoaderGDBAllocAction symbol being in either
    // libjulia-codegen or yet another shared library for LLVM depending on the build
    // flags, etc.).
    const auto Addr = ExecutorAddr::fromPtr(&llvm_orc_registerJITLoaderGDBAllocAction);
    ObjectLayer.addPlugin(std::make_unique<orc::GDBJITDebugInfoRegistrationPlugin>(Addr));
}
# endif
#else
void PyjuOJIT::enableJITDebuggingSupport()
{
    RegisterJITEventListener(JITEventListener::createGDBRegistrationListener());
}

void PyjuOJIT::RegisterJITEventListener(JITEventListener *L)
{
    if (!L)
        return;
    this->ObjectLayer.registerJITEventListener(*L);
}
#endif

const DataLayout& PyjuOJIT::getDataLayout() const
{
    return DL;
}

const Triple& PyjuOJIT::getTargetTriple() const
{
    return TM.getTargetTriple();
}

std::string PyjuOJIT::getMangledName(StringRef Name)
{
    SmallString<128> FullName;
    Mangler::getNameWithPrefix(FullName, Name, DL);
    return FullName.str().str();
}

std::string PyjuOJIT::getMangledName(const GlobalValue *GV)
{
    return getMangledName(GV->getName());
}

#ifdef PYJU_USE_JITLINK
size_t PyjuOJIT::getTotalBytes() const
{
    // TODO: Implement in future custom JITLink memory manager.
    return 0;
}
#else
size_t getRTDyldMemoryManagerTotalBytes(RTDyldMemoryManager *mm);

size_t PyjuOJIT::getTotalBytes() const
{
    return getRTDyldMemoryManagerTotalBytes(MemMgr.get());
}
#endif