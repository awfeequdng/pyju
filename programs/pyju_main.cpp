#include "llvm/ADT/SmallString.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"

#include "base/error.h"
#include "base/nonnull.h"
#include "base/arena.h"
#include "Parser/flex_bison/parse.h"
#include "ast/ast.h"
#include <filesystem>
#include <fstream>

#include "vm/run_ast.h"

#include <cstdlib>

namespace fs = std::filesystem;

static auto Main(llvm::StringRef default_prelude_file, int argc, char **argv)
    -> PYJU::ErrorOr<PYJU::Success> {
    llvm::setBugReportMsg(
        "Please report issues to "
        "https://github.com/awfeequdng/pyju/issues and include the "
        "crash backtrace.\n"
    );
    llvm::InitLLVM init_llvm(argc, argv);
    llvm::errs().tie(&llvm::outs());
    llvm::cl::opt<std::string> input_file_name(llvm::cl::Positional, llvm::cl::desc("<input file>"), llvm::cl::Required);
    llvm::cl::opt<bool> parser_debug("parser_debug", llvm::cl::desc("Enable debug output from the parser"));
    llvm::cl::opt<std::string> trace_file_name(
        "trace_file",
        llvm::cl::desc("Output file for tracing; set to `-` to output to stdout.")
    );
    // Find the path of the executable if possible and use that as a relative root
    llvm::cl::opt<std::string> prelude_file_name("prelude", llvm::cl::desc("<prelude file>"),
                                            llvm::cl::init(default_prelude_file.str()));
    llvm::cl::ParseCommandLineOptions(argc, argv);

    // Set up a stream for trace output.
    std::unique_ptr<llvm::raw_ostream> scoped_trace_stream;
    std::optional<PYJU::Nonnull<llvm::raw_ostream*>> trace_stream;
    trace_stream = &llvm::outs();
    if (!trace_file_name.empty()) {
        if (trace_file_name == "-") {
            trace_stream = &llvm::outs();
        } else {
            std::error_code err;
            scoped_trace_stream = std::make_unique<llvm::raw_fd_ostream>(trace_file_name, err);
            if (err) {
                return PYJU::Error(err.message());
            }
            trace_stream = scoped_trace_stream.get();
        }
    }

    PYJU::Arena arena;
    PXC_ASSIGN_OR_RETURN(PYJU::ASTPtr ast,
                         PYJU::Parse(&arena,
                                     input_file_name,
                                     parser_debug));
    PXC_ASSIGN_OR_RETURN(int return_code,
                         vm::RunAst(&arena, ast, trace_stream));
    llvm::outs() << "run ast return code: " << return_code << "\n";

    // When there's dedicated trace file, print the return code to it too.
    if (scoped_trace_stream) {
        **trace_stream << "run ast return code: " << return_code << "\n";
    }

    return PYJU::Success();
}

PYJU::ErrorOr<PYJU::Success> pyju_runscript(std::string &script_text) {
    std::optional<PYJU::Nonnull<llvm::raw_ostream*>> trace_stream;
    trace_stream = &llvm::outs();
    std::string tmp_fname = std::tmpnam(nullptr);

    std::ofstream ofs;
    ofs.open(tmp_fname);
    ofs << script_text << std::endl;

    PYJU::Arena arena;
    PXC_ASSIGN_OR_RETURN(PYJU::ASTPtr ast,
                         PYJU::Parse(&arena,
                                     tmp_fname,
                                     {}));
    PXC_ASSIGN_OR_RETURN(int return_code,
                         vm::RunAst(&arena, ast, trace_stream));
    llvm::outs() << "run ast return code: " << return_code << "\n";

    return PYJU::Success();
}

int pyju_main_script(std::string script_text) {
    if (auto result = pyju_runscript(script_text); !result.ok()) {
        llvm::errs() << result.error().message() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int pyju_main(int argc, char **argv) {
    llvm::SmallString<256> path;
    if (std::error_code err = llvm::sys::fs::current_path(path)) {
        llvm::errs() << "Failed to get working directory: " << err.message();
        return 1;
    }
    llvm::sys::path::append(path, "pxc/data");

    char *build_working_dir = getenv("BUILD_WORKING_DIRECTORY");
    if (build_working_dir != nullptr) {
        if (std::error_code err =
            llvm::sys::fs::set_current_path(build_working_dir)) {
            llvm::errs() << "Failed to set working directory: " << err.message();
            return 1;
        }
    }

    if (auto result = Main(path, argc, argv); !result.ok()) {
        llvm::errs() << result.error().message() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}