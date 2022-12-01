
#include "pyju.h"

#include <llvm/Support/Debug.h>
#include <llvm/IR/DebugLoc.h>


#define STR(csym)           #csym
#define XSTR(csym)          STR(csym)

enum AddressSpace {
    Generic = 0,
    Tracked = 10,
    Derived = 11,
    CalleeRooted = 12,
    Loaded = 13,
    FirstSpecial = Tracked,
    LastSpecial = Loaded,
};

namespace PyjuType {
static inline llvm::StructType *get_puvalue_ty(llvm::LLVMContext &ctx) {
    return llvm::StructType::get(ctx);
}

}


static void llvm_dump(llvm::Value *v) {
    v->print(llvm::dbgs(), true);
    llvm::dbgs() << "\n";
}

static void llvm_dump(llvm::Type *v) {
    v->print(llvm::dbgs(), true);
    llvm::dbgs() << "\n";
}

static inline void llvm_dump(llvm::Function *f)
{
    f->print(llvm::dbgs(), nullptr, false, true);
}

static inline void llvm_dump(llvm::Module *m)
{
    m->print(llvm::dbgs(), nullptr);
}

static inline void llvm_dump(llvm::Metadata *m)
{
    m->print(llvm::dbgs());
    llvm::dbgs() << "\n";
}

static inline void llvm_dump(llvm::DebugLoc *dbg)
{
    dbg->print(llvm::dbgs());
    llvm::dbgs() << "\n";
}
