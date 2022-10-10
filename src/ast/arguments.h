#pragma once

#include "base/source_location.h"
#include "base/nonnull.h"


namespace PYJU
{
class Expression;

struct WithItem {
    // PYJU::SourceLocation loc;
    PYJU::Nonnull<Expression*> context_expr;
    PYJU::Nonnull<Expression*> optional_vars;
};

} // namespace PYJU
