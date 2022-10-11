#pragma once

#include <map>
#include <optional>
#include <string>
#include <variant>
#include <vector>
#include <utility>

#include "base/ostream.h"
#include "ast/ast_node.h"
#include "base/arena.h"
#include "base/source_location.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/Support/Compiler.h"

namespace PYJU {

enum operatorType
{
    Add, Sub, Mult, MatMult, Div, Mod, Pow, LShift, RShift, BitOr, BitXor, BitAnd, FloorDiv
};

enum unaryopType
{
    Invert, Not, UAdd, USub
};

enum cmpopType
{
    Eq, NotEq, Lt, LtE, Gt, GtE, Is, IsNot, In, NotIn
};

enum boolopType
{
    And, Or
};
std::string operatorTypeStr(const operatorType &x);
std::string unaryopTypeStr(const unaryopType &x);
std::string cmpopTypeStr(const cmpopType &x);
std::string boolopTypeStr(const boolopType &x);

class Expression : public AstNode {
 public:
  ~Expression() override = 0;

  void Print(llvm::raw_ostream& out) const override;
  void PrintID(llvm::raw_ostream& out) const override;

  static auto classof(const AstNode* node) {
    return InheritsFromExpression(node->kind());
  }

  // Returns the enumerator corresponding to the most-derived type of this
  // object.
  auto kind() const -> ExpressionKind {
    return static_cast<ExpressionKind>(root_kind());
  }

 protected:
  // Constructs an Expression representing syntax at the given line number.
  // `kind` must be the enumerator corresponding to the most-derived type being
  // constructed.
  Expression(AstNodeKind kind, PYJU::SourceLocation source_loc)
      : AstNode(kind, source_loc) {}

 private:
};

} // PYJU

using NonnullExpr = PYJU::Nonnull<PYJU::Expression*>;
using NonnullArena = PYJU::Nonnull<PYJU::Arena*>;
using PairNonnullExpr = std::pair<PYJU::Nonnull<PYJU::Expression*>,
                                  PYJU::Nonnull<PYJU::Expression*>>;

namespace PYJU {
class ConstantInt : public Expression {
public:
    static Nonnull<ConstantInt*> make_ConstantInt(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        int64_t val) {
        return arena->New<ConstantInt>(loc, val);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantInt(node->kind());
    }

    ConstantInt(PYJU::SourceLocation loc, int64_t val)
        : Expression(AstNodeKind::ConstantInt, loc),
          val_(val) {}

    int64_t value() const {
        return val_;
    }
private:
    int64_t val_;
};

class ConstantBool : public Expression {
public:
    static Nonnull<ConstantBool*> make_ConstantBool(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        bool val) {
        return arena->New<ConstantBool>(loc, val);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantBool(node->kind());
    }

    ConstantBool(PYJU::SourceLocation loc, bool val)
        : Expression(AstNodeKind::ConstantBool, loc),
          val_(val) {}

    bool value() const {
        return val_;
    }
private:
    bool val_;
};

class ConstantNone : public Expression {
public:
    static Nonnull<ConstantNone*> make_ConstantNone(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<ConstantNone>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantNone(node->kind());
    }

    ConstantNone(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::ConstantNone, loc) {}
};

class ConstantEllipsis : public Expression {
public:
    static Nonnull<ConstantEllipsis*> make_ConstantEllipsis(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<ConstantEllipsis>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantEllipsis(node->kind());
    }

    ConstantEllipsis(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::ConstantEllipsis, loc) {}
};

class ConstantFloat : public Expression {
public:
    static Nonnull<ConstantFloat*> make_ConstantFloat(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        double val) {
        return arena->New<ConstantFloat>(loc, val);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantFloat(node->kind());
    }

    ConstantFloat(SourceLocation loc, double val)
        : Expression(AstNodeKind::ConstantFloat, loc),
          val_(val) {}

    double value() const {
        return val_;
    }
private:
    double val_;
};

class ConstantComplex : public Expression {
public:
    static Nonnull<ConstantComplex*> make_ConstantComplex(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        double real, double image) {
        return arena->New<ConstantComplex>(loc, real, image);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantComplex(node->kind());
    }

    ConstantComplex(SourceLocation loc, double real, double image)
        : Expression(AstNodeKind::ConstantComplex, loc),
          real_(real), image_(image) {}

    double real() const {
        return real_;
    }
    double image() const {
        return image_;
    }
private:
    double real_;
    double image_;
};

class ConstantStr : public Expression {
public:
    static Nonnull<ConstantStr*> make_ConstantStr(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::string val,
        std::string kind = std::string()) {
        return arena->New<ConstantStr>(loc, val, kind);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantStr(node->kind());
    }

    ConstantStr(SourceLocation loc, std::string val, std::string kind)
        : Expression(AstNodeKind::ConstantStr, loc),
          val_(val), kind_(kind) {}

    const std::string& value() const {
        return val_;
    }
    const std::vector<Nonnull<Expression*>> &extend() const {
        return extend_;
    }

    void concat(std::string str) {
        val_ += str;
    }
    void extend(Nonnull<Expression*> expr) {
        extend_.push_back(expr);
    }
private:
    std::string val_;
    std::string kind_;
    std::vector<Nonnull<Expression*>> extend_;
};

class ConstantBytes : public Expression {
public:
    static Nonnull<ConstantBytes*> make_ConstantBytes(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::string val,
        std::string kind = std::string()) {
        return arena->New<ConstantBytes>(loc, val, kind);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromConstantBytes(node->kind());
    }

    ConstantBytes(SourceLocation loc, std::string val, std::string kind)
        : Expression(AstNodeKind::ConstantBytes, loc),
          val_(val), kind_(kind) {}

    const std::string& value() const {
        return val_;
    }
    const std::vector<Nonnull<Expression*>> &extend() const {
        return extend_;
    }
    void concat(std::string str) {
        val_ += str;
    }
    void extend(Nonnull<Expression*> expr) {
        extend_.push_back(expr);
    }
private:
    std::string val_;
    std::string kind_;
    std::vector<Nonnull<Expression*>> extend_;
};

class JoinedStr : public Expression {
public:
    static Nonnull<JoinedStr*> make_JoinedStr(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> values) {
        return arena->New<JoinedStr>(loc, values);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromJoinedStr(node->kind());
    }

    JoinedStr(SourceLocation loc, std::vector<Nonnull<Expression*>> values)
        : Expression(AstNodeKind::JoinedStr, loc),
          values_(std::move(values)) {}

    const std::vector<Nonnull<Expression*>>& values() const {
        return values_;
    }
    void join(Nonnull<Expression*> expr) {
        values_.push_back(expr);
    }
private:
    std::vector<Nonnull<Expression*>> values_;
};

class FormattedValue : public Expression {
public:
    static Nonnull<FormattedValue*> make_FormattedValue(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> value,
        int64_t conversion) {
        return arena->New<FormattedValue>(loc, value, conversion);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromFormattedValue(node->kind());
    }

    FormattedValue(SourceLocation loc, Nonnull<Expression*> value,
                  int64_t conversion
                //   Nonnull<Expression*> format_spec
        )
        : Expression(AstNodeKind::FormattedValue, loc),
          value_(value), conversion_(conversion)
        //   format_spec_(format_spec)
          {}

    const Nonnull<Expression*>& value() const {
        return value_;
    }

private:
    Nonnull<Expression*> value_;
    int64_t conversion_;
};

class Tuple : public Expression {
public:
    static Nonnull<Tuple*> make_Tuple(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> elts) {
        return arena->New<Tuple>(loc, elts);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromTuple(node->kind());
    }

    Tuple(PYJU::SourceLocation loc, std::vector<Nonnull<Expression*>> elts)
        : Expression(AstNodeKind::Tuple, loc), elts_(elts) {}

    const std::vector<Nonnull<Expression*>> &elements() const {
        return elts_;
    }

private:
    std::vector<Nonnull<Expression*>> elts_;
};

class List: public Expression {
public:
    static Nonnull<List*> make_List(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> elts) {
        return arena->New<List>(loc, elts);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromList(node->kind());
    }

    List(PYJU::SourceLocation loc, std::vector<Nonnull<Expression*>> elts)
        : Expression(AstNodeKind::List, loc), elts_(elts) {}

    const std::vector<Nonnull<Expression*>> &elements() const {
        return elts_;
    }

private:
    std::vector<Nonnull<Expression*>> elts_;
};

class Set: public Expression {
public:
    static Nonnull<Set*> make_Set(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> elts) {
        return arena->New<Set>(loc, elts);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromSet(node->kind());
    }

    Set(PYJU::SourceLocation loc, std::vector<Nonnull<Expression*>> elts)
        : Expression(AstNodeKind::Set, loc), elts_(elts) {}

    const std::vector<Nonnull<Expression*>> &elements() const {
        return elts_;
    }

private:
    std::vector<Nonnull<Expression*>> elts_;
};

class Attribute: public Expression {
public:
    static Nonnull<Attribute*> make_Attribute(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> value,
        Nonnull<Expression*> attr) {
        return arena->New<Attribute>(loc, value, attr);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromAttribute(node->kind());
    }

    Attribute(PYJU::SourceLocation loc,
              Nonnull<Expression*> value,
              Nonnull<Expression*> attr)
        : Expression(AstNodeKind::Attribute, loc), value_(value), attr_(attr) {}

    const Nonnull<Expression*> &value() const {
        return value_;
    }
    const Nonnull<Expression*> &attr() const {
        return attr_;
    }

private:
    Nonnull<Expression*> value_;
    Nonnull<Expression*> attr_;
};

class Dict: public Expression {
public:
    static Nonnull<Dict*> make_Dict(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<PairNonnullExpr> key_value) {
        return arena->New<Dict>(loc, key_value);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromDict(node->kind());
    }

    Dict(PYJU::SourceLocation loc,
        std::vector<PairNonnullExpr> key_value)
        : Expression(AstNodeKind::Dict, loc),
        key_value_(key_value) {}

    const std::vector<PairNonnullExpr> &key_value() const {
        return key_value_;
    }


private:
    std::vector<PairNonnullExpr> key_value_;
};

class NamedExpr: public Expression {
public:
    static Nonnull<NamedExpr*> make_NamedExpr(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> target,
        Nonnull<Expression*> value) {
        return arena->New<NamedExpr>(loc, target, value);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromNamedExpr(node->kind());
    }

    NamedExpr(PYJU::SourceLocation loc,
              Nonnull<Expression*> target,
              Nonnull<Expression*> value)
        : Expression(AstNodeKind::NamedExpr, loc),
        target_(target), value_(value) {}

    const Nonnull<Expression*> &target() const {
        return target_;
    }
    const Nonnull<Expression*> &value() const {
        return value_;
    }

private:
    Nonnull<Expression*> target_;
    Nonnull<Expression*> value_;
};

class BinOp: public Expression {
public:
    static Nonnull<BinOp*> make_BinOp(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> left,
        operatorType op,
        Nonnull<Expression*> right) {
        return arena->New<BinOp>(loc, left, op, right);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromBinOp(node->kind());
    }

    BinOp(PYJU::SourceLocation loc,
              Nonnull<Expression*> left,
              operatorType op,
              Nonnull<Expression*> right)
        : Expression(AstNodeKind::BinOp, loc),
        left_(left), op_(op), right_(right) {}

    const Nonnull<Expression*> &left() const {
        return left_;
    }
    const operatorType &op() const {
        return op_;
    }
    const Nonnull<Expression*> &right() const {
        return right_;
    }

private:
    Nonnull<Expression*> left_;
    operatorType op_;
    Nonnull<Expression*> right_;
};

class Compare: public Expression {
public:
    static Nonnull<Compare*> make_Compare(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> left,
        cmpopType op,
        Nonnull<Expression*> right) {
        return arena->New<Compare>(loc, left, op, right);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromCompare(node->kind());
    }

    Compare(PYJU::SourceLocation loc,
              Nonnull<Expression*> left,
              cmpopType op,
              Nonnull<Expression*> right)
        : Expression(AstNodeKind::Compare, loc),
        left_(left), op_(op), right_(right) {}

    const Nonnull<Expression*> &left() const {
        return left_;
    }
    const cmpopType &op() const {
        return op_;
    }
    const Nonnull<Expression*> &right() const {
        return right_;
    }

private:
    Nonnull<Expression*> left_;
    cmpopType op_;
    Nonnull<Expression*> right_;
};

class BoolOp: public Expression {
public:
    static Nonnull<BoolOp*> make_BoolOp(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> left,
        boolopType op,
        Nonnull<Expression*> right) {
        return arena->New<BoolOp>(loc, left, op, right);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromBoolOp(node->kind());
    }

    BoolOp(PYJU::SourceLocation loc,
              Nonnull<Expression*> left,
              boolopType op,
              Nonnull<Expression*> right)
        : Expression(AstNodeKind::BoolOp, loc),
        left_(left), op_(op), right_(right) {}

    const Nonnull<Expression*> &left() const {
        return left_;
    }
    const boolopType &op() const {
        return op_;
    }
    const Nonnull<Expression*> &right() const {
        return right_;
    }

private:
    Nonnull<Expression*> left_;
    boolopType op_;
    Nonnull<Expression*> right_;
};

class UnaryOp: public Expression {
public:
    static Nonnull<UnaryOp*> make_UnaryOp(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        unaryopType op,
        Nonnull<Expression*> operand) {
        return arena->New<UnaryOp>(loc, op, operand);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromUnaryOp(node->kind());
    }

    UnaryOp(PYJU::SourceLocation loc,
              unaryopType op,
              Nonnull<Expression*> operand)
        : Expression(AstNodeKind::UnaryOp, loc),
        op_(op), operand_(operand) {}

    const unaryopType &op() const {
        return op_;
    }
    const Nonnull<Expression*> &operand() const {
        return operand_;
    }

private:
    unaryopType op_;
    Nonnull<Expression*> operand_;
};

class Starred: public Expression {
public:
    static Nonnull<Starred*> make_Starred(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> value) {
        return arena->New<Starred>(loc, value);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromStarred(node->kind());
    }

    Starred(PYJU::SourceLocation loc,
            Nonnull<Expression*> value)
        : Expression(AstNodeKind::Starred, loc),
        value_(value) {}

    const Nonnull<Expression*> &value() const {
        return value_;
    }

private:
    Nonnull<Expression*> value_;
};

class Arg: public Expression {
public:
    static Nonnull<Arg*> make_Arg(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> arg) {
        return arena->New<Arg>(loc, arg);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromArg(node->kind());
    }

    Arg(PYJU::SourceLocation loc,
        Nonnull<Expression*> arg)
        : Expression(AstNodeKind::Arg, loc),
          arg_(arg) {}


    const Nonnull<Expression*> &arg() const {
        return arg_;
    }

public:
    std::optional<NonnullExpr> defaults_;
    std::optional<NonnullExpr> annotation_;
    std::optional<NonnullExpr> type_comment_;
    NonnullExpr arg_;

// private:
};

class Arguments: public Expression {
public:
    static Nonnull<Arguments*> make_Arguments(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Arguments>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromArguments(node->kind());
    }

    Arguments(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::Arguments, loc)
         {}

    // const Nonnull<Expression*> &value() const {
    //     return value_;
    // }

    std::vector<Nonnull<Arg*>> posonlyargs_;
    std::vector<Nonnull<Arg*>> args_;
    std::vector<Nonnull<Arg*>> varargs_;
    std::vector<Nonnull<Arg*>> kwonlyargs_;
    std::vector<Nonnull<Expression*>> kw_defaults_;
    std::vector<Nonnull<Arg*>> kwarg_;
    std::vector<Nonnull<Expression*>> defaults_;
};

} // namespace PYJU

using NonnullArg = PYJU::Nonnull<PYJU::Arg*>;

namespace PYJU {

class StarArg: public Expression {
public:
    static Nonnull<StarArg*> make_StarArg(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<StarArg>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromStarArg(node->kind());
    }

    StarArg(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::StarArg, loc) {}

public:
    std::vector<Nonnull<Arg*>> varargs_;
    std::vector<Nonnull<Arg*>> kwonlyargs_;
    std::vector<Nonnull<Arg*>> kwarg_;
};

class NoPosOnlyArg: public Expression {
public:
    static Nonnull<NoPosOnlyArg*> make_NoPosOnlyArg(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<NoPosOnlyArg>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromNoPosOnlyArg(node->kind());
    }

    NoPosOnlyArg(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::NoPosOnlyArg, loc) {}

public:
    std::vector<Nonnull<Arg*>> args_;
    std::optional<Nonnull<StarArg*>> stararg_;
};

class FnArg: public Expression {
public:
    static Nonnull<FnArg*> make_FnArg(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<FnArg>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromFnArg(node->kind());
    }

    FnArg(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::FnArg, loc) {}

public:
    std::vector<Nonnull<Arg*>> posonlyargs_;
    std::optional<Nonnull<NoPosOnlyArg*>> args_;
};

class Keyword: public Expression {
public:
    static Nonnull<Keyword*> make_Keyword(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::optional<Nonnull<Expression*>> arg,
        Nonnull<Expression*> value) {
        return arena->New<Keyword>(loc, arg, value);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromKeyword(node->kind());
    }

    Keyword(PYJU::SourceLocation loc,
            std::optional<Nonnull<Expression*>> arg,
            Nonnull<Expression*> value)
        : Expression(AstNodeKind::Keyword, loc),
        arg_(arg),
        value_(value) {}

    const std::optional<Nonnull<Expression*>> &arg() const {
        return arg_;
    }

    const Nonnull<Expression*> &value() const {
        return value_;
    }

private:
    std::optional<Nonnull<Expression*>> arg_;
    Nonnull<Expression*> value_;
};

class Call: public Expression {
public:
    static Nonnull<Call*> make_Call(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> func,
        std::vector<Nonnull<Expression*>> args,
        std::vector<Nonnull<Keyword*>> keywords) {
        return arena->New<Call>(loc, func, args, keywords);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromCall(node->kind());
    }

    Call(PYJU::SourceLocation loc,
            Nonnull<Expression*> func,
            std::vector<Nonnull<Expression*>> args,
            std::vector<Nonnull<Keyword*>> keywords)
        : Expression(AstNodeKind::Call, loc),
        func_(func), args_(args), keywords_(keywords) {}

    const Nonnull<Expression*> &func() const {
        return func_;
    }
    const std::vector<Nonnull<Expression*>> &args() const {
        return args_;
    }
    const std::vector<Nonnull<Keyword*>> &keywords() const {
        return keywords_;
    }

private:
    Nonnull<Expression*> func_;
    std::vector<Nonnull<Expression*>> args_;
    std::vector<Nonnull<Keyword*>> keywords_;
};

class IfExp: public Expression {
public:
    static Nonnull<IfExp*> make_IfExp(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        Nonnull<Expression*> test,
        Nonnull<Expression*> body,
        Nonnull<Expression*> orelse) {
        return arena->New<IfExp>(loc, test, body, orelse);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromIfExp(node->kind());
    }

    IfExp(PYJU::SourceLocation loc,
            Nonnull<Expression*> test,
            Nonnull<Expression*> body,
            Nonnull<Expression*> orelse)
        : Expression(AstNodeKind::IfExp, loc),
        test_(test),
        body_(body),
        orelse_(orelse){}

    const Nonnull<Expression*> &test() const {
        return test_;
    }
    const Nonnull<Expression*> &body() const {
        return body_;
    }
    const Nonnull<Expression*> &orelse() const {
        return orelse_;
    }

private:
    Nonnull<Expression*> test_;
    Nonnull<Expression*> body_;
    Nonnull<Expression*> orelse_;
};


class Alias: public Expression {
public:
    static Nonnull<Alias*> make_Alias(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc,
        std::vector<Nonnull<Expression*>> name,
        std::optional<Nonnull<Expression*>> asname) {
        return arena->New<Alias>(loc, name, asname);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromAlias(node->kind());
    }

    Alias(PYJU::SourceLocation loc,
            std::vector<Nonnull<Expression*>> name,
            std::optional<Nonnull<Expression*>> asname)
        : Expression(AstNodeKind::Alias, loc),
        name_(name), asname_(asname) {}

    const std::vector<Nonnull<Expression*>> &name() const {
        return name_;
    }
    const std::optional<Nonnull<Expression*>> &asname() const {
        return asname_;
    }

private:
    std::vector<Nonnull<Expression*>> name_;
    std::optional<Nonnull<Expression*>> asname_;
};

class Star: public Expression {
public:
    static Nonnull<Star*> make_Star(
        Nonnull<PYJU::Arena*> arena,
        SourceLocation loc) {
        return arena->New<Star>(loc);
    }

    static auto classof(const AstNode* node) {
        return InheritsFromStar(node->kind());
    }

    Star(PYJU::SourceLocation loc)
        : Expression(AstNodeKind::Star, loc) {}
};

} // namespace PYJU

