#include "interpreter/run_ast.h"

using namespace PYJU;
namespace vm
{
auto RunAst(PYJU::Nonnull<PYJU::Arena*> arena, PYJU::ASTPtr ast,
            std::optional<PYJU::Nonnull<llvm::raw_ostream*>> trace_stream)
    -> PYJU::ErrorOr<int> {

    if (trace_stream) {
        **trace_stream << "********** source program **********\n";
        **trace_stream << "stmt cnt: " << ast->statements.size() << "\n";
        for (const auto stmt : ast->statements) {

            **trace_stream << *stmt;
        }
    }
    return 0;
}

} // namespace vm
