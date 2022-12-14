
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/MemoryBufferRef.h>
#include <llvm/Support/Error.h>
#include <llvm/ExecutionEngine/Orc/ThreadSafeModule.h>


#include "llvm/ADT/StringRef.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/SourceMgr.h"

using namespace llvm;
using namespace llvm::orc;

inline Error createSMDiagnosticError(SMDiagnostic &Diag) {
    std::string msg;
    raw_string_ostream rso(msg);
    Diag.print("", rso);
    return make_error<StringError>(msg, inconvertibleErrorCode());
}

inline Expected<ThreadSafeModule> createModule(StringRef input_ir = "") {
    StringRef ir = R"(
        define i32 @add(i32 %x) {
            %r = add i32 1, %x
            ret i32 %r
        }
    )";
    if (!input_ir.empty()) {
        ir = input_ir;
    }
    // LLVMContext
    auto ctx = std::make_unique<LLVMContext>();
    SMDiagnostic Err;
    auto m = parseIR(MemoryBufferRef(ir, "add"), Err, *ctx);
    if (m) {
        return ThreadSafeModule(std::move(m), std::move(ctx));
    }
    return createSMDiagnosticError(Err);
}