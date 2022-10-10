#pragma once

#include "ast/expression.h"

namespace PYJU
{
class Name : public Expression {
public:
    static PYJU::Nonnull<Name*> make_Name(
        PYJU::Nonnull<PYJU::Arena*> arena,
        PYJU::SourceLocation loc,
        std::string name) {
        return arena->New<Name>(loc, name);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromName(node->kind());
    }

    Name(PYJU::SourceLocation loc, std::string name)
        : Expression(AstNodeKind::Name, loc),
          name_(name) {}

    std::string name() const {
        return name_;
    }
private:
    std::string name_;
};
} // namespace PYJU
