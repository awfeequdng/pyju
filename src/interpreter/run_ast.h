#pragma once
#include "base/nonnull.h"
#include "base/arena.h"
#include "base/error.h"
#include "ast/ast.h"
#include <llvm/Support/raw_ostream.h>

namespace vm
{
auto RunAst(PYJU::Nonnull<PYJU::Arena*> arena, PYJU::ASTPtr ast,
            std::optional<PYJU::Nonnull<llvm::raw_ostream*>> trace_stream)
    -> PYJU::ErrorOr<int>;

} // namespace vm
