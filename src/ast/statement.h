#pragma once

#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "base/ostream.h"
#include "ast/ast_node.h"
#include "ast/expression.h"
#include "base/arena.h"
#include "base/source_location.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/Support/Compiler.h"

#include "ast/arguments.h"

namespace PYJU {

class Statement : public AstNode {
 public:
  ~Statement() override = 0;

  void Print(llvm::raw_ostream& out) const override { PrintDepth(0, out); }
  void PrintID(llvm::raw_ostream& out) const override { PrintDepth(0, out); }
  void PrintDepth(int depth, llvm::raw_ostream& out) const;
  static llvm::raw_ostream& Space(int depth, llvm::raw_ostream& out);

  static auto classof(const AstNode* node) {
    return InheritsFromStatement(node->kind());
  }

  // Returns the enumerator corresponding to the most-derived type of this
  // object.
  auto kind() const -> StatementKind {
    return static_cast<StatementKind>(root_kind());
  }

 protected:
  Statement(AstNodeKind kind, PYJU::SourceLocation source_loc)
      : AstNode(kind, source_loc) {}
};

class FunctionDef : public Statement {
public:
    static PYJU::Nonnull<FunctionDef*> make_FunctionDef(
                PYJU::Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                Nonnull<Expression*> name,
                Nonnull<Arguments*> args,
                std::vector<PYJU::Nonnull<Statement*>> body,
                std::vector<PYJU::Nonnull<Expression*>> decorator_list,
                std::optional<Nonnull<Expression*>> returns,
                std::optional<Nonnull<Expression*>> type_comment) {
        return arena->New<FunctionDef>(loc, name, args, body,
                                      decorator_list, returns, type_comment);
    }
    static auto classof(const AstNode* node) -> bool {
        return InheritsFromFunctionDef(node->kind());
    }

    FunctionDef(const PYJU::SourceLocation& loc,
                Nonnull<Expression*> name,
                Nonnull<Arguments*> args,
                std::vector<PYJU::Nonnull<Statement*>> body,
                std::vector<PYJU::Nonnull<Expression*>> decorator_list,
                std::optional<Nonnull<Expression*>> returns,
                std::optional<Nonnull<Expression*>> type_comment)
      : Statement(AstNodeKind::FunctionDef, loc),
        name_(name),
        args_(args),
        body_(std::move(body)),
        decorator_list_(std::move(decorator_list)),
        returns_(returns),
        type_comment_(type_comment) {}

// protected:
    Nonnull<Expression*> name_;
    Nonnull<Arguments*> args_;
    std::vector<Nonnull<Statement*>> body_;
    std::vector<Nonnull<Expression*>> decorator_list_;
    std::optional<Nonnull<Expression*>> returns_;
    std::optional<Nonnull<Expression*>> type_comment_;
};

class ExprStmt : public Statement {
public:
    static PYJU::Nonnull<ExprStmt*> make_ExprStmt(
                PYJU::Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                PYJU::Nonnull<Expression*> expr) {
        return arena->New<ExprStmt>(loc, expr);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromExprStmt(node->kind());
    }

    ExprStmt(const PYJU::SourceLocation& loc,
                PYJU::Nonnull<Expression*>& expr)
      : Statement(AstNodeKind::ExprStmt, loc),
        expr_(expr) {}
    auto expression() const -> const Expression& { return *expr_; }
    // auto expression() -> Expression& { return *expr_; }

protected:
    PYJU::Nonnull<Expression*> expr_;
};

class If : public Statement {
public:
    static Nonnull<If*> make_If (
                Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                PYJU::Nonnull<Expression*> test,
                std::vector<Nonnull<Statement*>> body,
                std::vector<Nonnull<Statement*>> orelse) {
        return arena->New<If>(loc, test, body, orelse);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromIf(node->kind());
    }

    If(const PYJU::SourceLocation& loc,
       Nonnull<Expression*> test,
       std::vector<Nonnull<Statement*>> body,
       std::vector<Nonnull<Statement*>> orelse)
      : Statement(AstNodeKind::If, loc),
        test_(test),
        body_(body),
        orelse_(orelse) {}
    auto test() const -> const Expression& { return *test_; }

    auto body() const -> const std::vector<Nonnull<Statement*>>& {
        return body_;
    }

    auto orelse() const -> const std::vector<Nonnull<Statement*>>& {
        return orelse_;
    }

protected:
    Nonnull<Expression*> test_;
    std::vector<Nonnull<Statement*>> body_;
    std::vector<Nonnull<Statement*>> orelse_;
};

class NonLocal: public Statement {
public:
    static Nonnull<NonLocal*> make_NonLocal(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> names) {
        return arena->New<NonLocal>(loc, names);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromNonLocal(node->kind());
    }

    NonLocal(PYJU::SourceLocation loc,
            std::vector<Nonnull<Expression*>> names)
        : Statement(AstNodeKind::NonLocal, loc),
        names_(names) {}

    const std::vector<Nonnull<Expression*>> &names() const {
        return names_;
    }

private:
    std::vector<Nonnull<Expression*>> names_;
};


class Global: public Statement {
public:
    static Nonnull<Global*> make_Global(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> names) {
        return arena->New<Global>(loc, names);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromGlobal(node->kind());
    }

    Global(PYJU::SourceLocation loc,
            std::vector<Nonnull<Expression*>> names)
        : Statement(AstNodeKind::Global, loc),
        names_(names) {}

    const std::vector<Nonnull<Expression*>> &names() const {
        return names_;
    }

private:
    std::vector<Nonnull<Expression*>> names_;
};

class Import: public Statement {
public:
    static Nonnull<Import*> make_Import(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Alias*>> names) {
        return arena->New<Import>(loc, names);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromImport(node->kind());
    }

    Import(PYJU::SourceLocation loc,
            std::vector<Nonnull<Alias*>> names)
        : Statement(AstNodeKind::Import, loc),
        names_(names) {}

    const std::vector<Nonnull<Alias*>> &names() const {
        return names_;
    }

private:
    std::vector<Nonnull<Alias*>> names_;
};

class ImportFrom: public Statement {
public:
    static Nonnull<ImportFrom*> make_ImportFrom(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> module,
        std::vector<Nonnull<Alias*>> names,
        int level) {
        return arena->New<ImportFrom>(loc, module, names, level);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromImportFrom(node->kind());
    }

    ImportFrom(PYJU::SourceLocation loc,
            std::vector<Nonnull<Expression*>> module,
            std::vector<Nonnull<Alias*>> names,
            int level)
        : Statement(AstNodeKind::ImportFrom, loc),
        module_(module),
        names_(names),
        level_(level) {}

    const std::vector<Nonnull<Expression*>> &mod() const {
        return module_;
    }
    const std::vector<Nonnull<Alias*>> &names() const {
        return names_;
    }
    size_t level() const {
        return level_;
    }

private:
    std::vector<Nonnull<Expression*>> module_;
    std::vector<Nonnull<Alias*>> names_;
    size_t level_{};
};


class Break: public Statement {
public:
    static Nonnull<Break*> make_Break(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Break>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromBreak(node->kind());
    }

    Break(PYJU::SourceLocation loc)
        : Statement(AstNodeKind::Break, loc) {}
};

class Continue: public Statement {
public:
    static Nonnull<Continue*> make_Continue(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Continue>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromContinue(node->kind());
    }

    Continue(PYJU::SourceLocation loc)
        : Statement(AstNodeKind::Continue, loc) {}
};

class Pass: public Statement {
public:
    static Nonnull<Pass*> make_Pass(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Pass>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromPass(node->kind());
    }

    Pass(PYJU::SourceLocation loc)
        : Statement(AstNodeKind::Pass, loc) {}
};


class Assert : public Statement {
public:
    static Nonnull<Assert*> make_Assert (
                Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                PYJU::Nonnull<Expression*> test,
                std::optional<Nonnull<Expression*>> msg) {
        return arena->New<Assert>(loc, test, msg);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromAssert(node->kind());
    }

    Assert(const PYJU::SourceLocation& loc,
       Nonnull<Expression*> test,
       std::optional<Nonnull<Expression*>> msg)
      : Statement(AstNodeKind::Assert, loc),
        test_(test),
        msg_(msg) {}
    auto test() const -> const Expression& { return *test_; }

    auto msg() const -> const std::optional<Nonnull<Expression*>>& {
        return msg_;
    }

protected:
    Nonnull<Expression*> test_;
    std::optional<Nonnull<Expression*>> msg_;
};

class Raise : public Statement {
public:
    static Nonnull<Raise*> make_Raise (
                Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                std::optional<Nonnull<Expression*>> exc,
                std::optional<Nonnull<Expression*>> cause) {
        return arena->New<Raise>(loc, exc, cause);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromRaise(node->kind());
    }

    Raise(const PYJU::SourceLocation& loc,
       std::optional<Nonnull<Expression*>> exc,
       std::optional<Nonnull<Expression*>> cause)
      : Statement(AstNodeKind::Raise, loc),
        exc_(exc),
        cause_(cause) {}
    auto exc() const -> const std::optional<Nonnull<Expression*>>& {
        return exc_;
    }

    auto cause() const -> const std::optional<Nonnull<Expression*>>& {
        return cause_;
    }

protected:
    std::optional<Nonnull<Expression*>> exc_;
    std::optional<Nonnull<Expression*>> cause_;
};

class Return : public Statement {
public:
    static Nonnull<Return*> make_Return (
                Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                std::optional<Nonnull<Expression*>> value) {
        return arena->New<Return>(loc, value);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromReturn(node->kind());
    }

    Return(const PYJU::SourceLocation& loc,
       std::optional<Nonnull<Expression*>> value)
      : Statement(AstNodeKind::Return, loc),
        value_(value) {}
    auto value() const -> const std::optional<Nonnull<Expression*>>& {
        return value_;
    }

protected:
    std::optional<Nonnull<Expression*>> value_;
};

class TupleStmt : public Statement {
public:
    static PYJU::Nonnull<TupleStmt*> make_TupleStmt(
                PYJU::Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                std::vector<Nonnull<Expression*>> tuple) {
        return arena->New<TupleStmt>(loc, tuple);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromTupleStmt(node->kind());
    }

    TupleStmt(const PYJU::SourceLocation& loc,
              std::vector<Nonnull<Expression*>>& tuple)
      : Statement(AstNodeKind::TupleStmt, loc),
        tuple_(tuple) {}
    auto tuple() const -> const std::vector<Nonnull<Expression*>>& { return tuple_; }

protected:
    std::vector<Nonnull<Expression*>> tuple_;
};

class Delete : public Statement {
public:
    static PYJU::Nonnull<Delete*> make_Delete(
                PYJU::Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                std::vector<Nonnull<Expression*>> targets) {
        return arena->New<Delete>(loc, targets);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromDelete(node->kind());
    }

    Delete(const PYJU::SourceLocation& loc,
              std::vector<Nonnull<Expression*>>& targets)
      : Statement(AstNodeKind::Delete, loc),
        targets_(targets) {}
    auto targets() const -> const std::vector<Nonnull<Expression*>>& { return targets_; }

protected:
    std::vector<Nonnull<Expression*>> targets_;
};

class Assign : public Statement {
public:
    static PYJU::Nonnull<Assign*> make_Assign(
                PYJU::Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                std::vector<Nonnull<Expression*>> targets,
                Nonnull<Expression*>& value) {
        return arena->New<Assign>(loc, targets, value);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromAssign(node->kind());
    }

    Assign(const PYJU::SourceLocation& loc,
              std::vector<Nonnull<Expression*>>& targets,
              Nonnull<Expression*>& value)
      : Statement(AstNodeKind::Assign, loc),
        targets_(targets),
        value_(value) {}
    auto targets() const -> const std::vector<Nonnull<Expression*>>& { return targets_; }
    auto value() const -> const Nonnull<Expression*>& { return value_; }

protected:
    std::vector<Nonnull<Expression*>> targets_;
    Nonnull<Expression*> value_;
};

class AugAssign : public Statement {
public:
    static PYJU::Nonnull<AugAssign*> make_AugAssign(
                PYJU::Nonnull<PYJU::Arena*> arena,
                const PYJU::SourceLocation& loc,
                Nonnull<Expression*> target,
                operatorType op,
                Nonnull<Expression*> value) {
        return arena->New<AugAssign>(loc, target, op, value);
    }

    static auto classof(const AstNode* node) -> bool {
        return InheritsFromAugAssign(node->kind());
    }

    AugAssign(const PYJU::SourceLocation& loc,
              Nonnull<Expression*> target,
              operatorType& op,
              Nonnull<Expression*> value)
      : Statement(AstNodeKind::AugAssign, loc),
        target_(target),
        op_(op),
        value_(value) {}
    auto target() const -> const Nonnull<Expression*>& { return target_; }
    auto op() const -> const operatorType& { return op_; }
    auto value() const -> const Nonnull<Expression*>& { return value_; }

protected:
    Nonnull<Expression*> target_;
    operatorType op_;
    Nonnull<Expression*> value_;
};

} // namespace PYJU
