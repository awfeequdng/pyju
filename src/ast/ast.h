#pragma once
#include "base/nonnull.h"
#include <string>
#include <memory>

#include "ast/statement.h"

namespace PYJU {

struct AST {
    std::string filename;
    // The file's ordered statement.
    std::vector<PYJU::Nonnull<Statement*>> statements;
};
using ASTPtr = std::shared_ptr<AST>;
}