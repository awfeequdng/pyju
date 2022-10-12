
#include "ast/expression.h"

#include <map>
#include <optional>

#include "base/arena.h"
#include "base/error_builders.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include "ast/name.h"

namespace PYJU {

using llvm::cast;
using llvm::isa;

Expression::~Expression() = default;

std::string operatorTypeStr(const operatorType &x) {
    switch (x) {
        case (operatorType::Add) : {
            return "+";
        }
        case (operatorType::Sub) : {
            return "-";
        }
        case (operatorType::Mult) : {
            return "*";
        }
        case (operatorType::MatMult) : {
            return "@";
        }
        case (operatorType::Div) : {
            return "/";
        }
        case (operatorType::Mod) : {
            return "%";
        }
        case (operatorType::Pow) : {
            return "**";
        }
        case (operatorType::LShift) : {
            return "<<";
        }
        case (operatorType::RShift) : {
            return ">>";
        }
        case (operatorType::BitOr) : {
            return "|";
        }
        case (operatorType::BitXor) : {
            return "^";
        }
        case (operatorType::BitAnd) : {
            return "&";
        }
        case (operatorType::FloorDiv) : {
            return "//";
        }
    }
    return "UnknowOperatorType";
}

std::string unaryopTypeStr(const unaryopType &x) {
    switch (x) {
        case (unaryopType::Invert) : {
            return "~ ";
        }
        case (unaryopType::Not) : {
            return "not ";
        }
        case (unaryopType::UAdd) : {
            return "+ ";
        }
        case (unaryopType::USub) : {
            return "- ";
        }
    }
    return "UnknowunaryopType";
}

std::string cmpopTypeStr(const cmpopType &x) {
    switch (x) {
      // Eq, NotEq, Lt, LtE, Gt, GtE, Is, IsNot, In, NotIn
        case (cmpopType::Eq) : {
            return "eq ";
        }
        case (cmpopType::NotEq) : {
            return "not eq ";
        }
        case (cmpopType::Lt) : {
            return "Lt ";
        }
        case (cmpopType::LtE) : {
            return "LtE ";
        }
        case (cmpopType::Gt) : {
            return "Gt ";
        }
        case (cmpopType::GtE) : {
            return "GtE ";
        }
        case (cmpopType::Is) : {
            return "Is ";
        }
        case (cmpopType::IsNot) : {
            return "Is Not ";
        }
        case (cmpopType::In) : {
            return "In ";
        }
        case (cmpopType::NotIn) : {
            return "Not In ";
        }
    }
    return "Unknown cmpopType";
}

std::string boolopTypeStr(const boolopType &x) {
    switch (x) {
        case (boolopType::And) : {
            return "& ";
        }
        case (boolopType::Or) : {
            return "| ";
        }
    }
    return "Unknown boolopType";
}

void Expression::Print(llvm::raw_ostream& out) const {
  // switch (kind()) {
  //   case ExpressionKind::Name:
  //     out << cast<Name>(this)->name();
  //     break;
  //   default:
  //     break;
  // }
  PrintID(out);
}

static void PrintArguments(llvm::raw_ostream& out, const Arguments& arguments) {
    out << "Arguments(";
    // std::vector<Nonnull<Arg*>> posonlyargs_;
    // std::vector<Nonnull<Arg*>> args_;
    // std::vector<Nonnull<Arg*>> varargs_;
    // std::vector<Nonnull<Arg*>> kwonlyargs_;
    // std::vector<Nonnull<Expression*>> kw_defaults_;
    // std::vector<Nonnull<Arg*>> kwarg_;
    // std::vector<Nonnull<Expression*>> defaults_;
    if (arguments.posonlyargs_.size()) {
      for (auto &posonly : arguments.posonlyargs_) {
        out << *posonly << ",";
      }
      out << " / ,";
    }
    if (arguments.args_.size()) {
        for (auto &arg : arguments.args_) {
        out << *arg << ",";
      }
    }
    if (arguments.varargs_.size()) {
        for (auto &vararg : arguments.varargs_) {
          out << "*" << *vararg << ",";
        }
    }
    if (arguments.kwonlyargs_.size()) {
        out << "* ,";
        for (auto &kwonlyarg : arguments.kwonlyargs_) {
            out << *kwonlyarg << ",";
        }
    }
    if (arguments.kwarg_.size()) {
        for (auto &kwarg : arguments.kwarg_) {
            out << "**" << *kwarg << ", ";
        }
    }
    out << ")";
    return;
}

void Expression::PrintID(llvm::raw_ostream& out) const {
  switch (kind()) {
    case ExpressionKind::Name:
      out << "Name(" << cast<Name>(*this).name() << ")";
      break;
    case ExpressionKind::ConstantInt:
      out << cast<ConstantInt>(*this).value();
      break;
    case ExpressionKind::ConstantBool:
      out << (cast<ConstantBool>(*this).value() ? "True" : "False");
      break;
    case ExpressionKind::ConstantNone:
      out << "None";
      break;
    case ExpressionKind::ConstantEllipsis:
      out << "...";
      break;
    case ExpressionKind::ConstantFloat:
      out << cast<ConstantFloat>(*this).value();
      break;
    case ExpressionKind::ConstantComplex: {
      out << cast<ConstantComplex>(*this).real();
      auto image = cast<ConstantComplex>(*this).image();
      if (!(image < 0)) {
        out << "+";
      }
      out << image << "j";
      break;
    }
    case ExpressionKind::ConstantStr:
      out << "ConstStr(" << cast<ConstantStr>(*this).value() << ")";
      for (auto &expr : cast<ConstantStr>(*this).extend()) {
        out << *expr;
      }
      break;
    case ExpressionKind::JoinedStr: {
      const auto &values = cast<JoinedStr>(*this).values();
      for (auto &val : values) {
        out << *val;
      }
      break;
    }
    case ExpressionKind::ConstantBytes:
      out << cast<ConstantBytes>(*this).value();
      for (auto &expr : cast<ConstantStr>(*this).extend()) {
        out << *expr;
      }
      break;
    case ExpressionKind::FormattedValue:
      out << "{" << *(cast<FormattedValue>(*this).value()) << "}";
      break;
    case ExpressionKind::Tuple:
      out << "Tuple(";
      for (auto &elt: cast<Tuple>(*this).elements()) {
        out << *elt << ",";
      }
      out << ")";
      break;
    case ExpressionKind::List:
      out << "List[";
      for (auto &elt: cast<List>(*this).elements()) {
        out << *elt << ",";
      }
      out << "]";
      break;
    case ExpressionKind::Set:
      out << "Set{";
      for (auto &elt: cast<Set>(*this).elements()) {
        out << *elt << ",";
      }
      out << "}";
      break;
    case ExpressionKind::Attribute:
      out << "Attribute(" << *(cast<Attribute>(*this).value())
          << "." << *(cast<Attribute>(*this).attr())
          << ")";
      break;
    case ExpressionKind::Dict: {
      out << "Dict{";
      size_t cnt = 0;
      size_t sz = cast<Dict>(*this).key_value().size();
      for (auto &key_val : cast<Dict>(*this).key_value()) {
        out << *(key_val.first) << ":" << *(key_val.second);
        cnt++;
        if (cnt < sz) out << ", ";
      }
      out << "}";
      break;
    }
    case ExpressionKind::NamedExpr:
      out << "NamedExpr(" << *(cast<NamedExpr>(*this).target())
          << ":=" << *(cast<NamedExpr>(*this).value())
          << ")";
      break;
    case ExpressionKind::BinOp:
      out << "BinOp(" << *(cast<BinOp>(*this).left())
          << operatorTypeStr(cast<BinOp>(*this).op())
          << *(cast<BinOp>(*this).right())
          << ")";
      break;
    case ExpressionKind::Compare:
      out << "Compare(" << *(cast<Compare>(*this).left())
          << cmpopTypeStr(cast<Compare>(*this).op())
          << *(cast<Compare>(*this).right())
          << ")";
      break;
    case ExpressionKind::BoolOp:
      out << "BoolOp(" << *(cast<BoolOp>(*this).left())
          << boolopTypeStr(cast<BoolOp>(*this).op())
          << *(cast<BoolOp>(*this).right())
          << ")";
      break;
    case ExpressionKind::UnaryOp:
      out << "UnaryOp("
          << unaryopTypeStr(cast<UnaryOp>(*this).op())
          << *(cast<UnaryOp>(*this).operand())
          << ")";
      break;
    case ExpressionKind::Starred:
      out << "Starred(*" << *(cast<Starred>(*this).value()) << ")";
      break;
    case ExpressionKind::Arguments: {
      const auto &arguments = cast<Arguments>(*this);
      PrintArguments(out, arguments);
      break;
    }
    case ExpressionKind::Arg: {
      const auto &arg = cast<Arg>(*this);
      out << *(arg.arg_);
      if (arg.annotation_) {
        out << ": " << **(arg.annotation_);
      }
      if (arg.defaults_) {
        out << " = " << **(arg.defaults_);
      }
      break;
    }
    case ExpressionKind::Call: {
      const auto &call = cast<Call>(*this);
      out << "Call(" << *call.func() << "(";
      auto &args = call.args();
      for (auto &arg : args) {
        out << *(arg) << ", ";
      }
      auto &keywords = call.keywords();
      for (auto &kw : keywords) {
        out << *(kw) << ", ";
      }
      out << ")";
      break;
    }
    case ExpressionKind::Keyword: {
      const auto &keyword = cast<Keyword>(*this);
      auto &arg = keyword.arg();
      auto &value = keyword.value();
      if (arg) {
        out << **arg << "=" << *value;
      } else {
        out << "**" << *value;
      }
      break;
    }
    case ExpressionKind::IfExp: {
      const auto &ifexp = cast<IfExp>(*this);
      auto &test = ifexp.test();
      auto &body = ifexp.body();
      auto &orelse = ifexp.orelse();
      out << *body << " if " << *test << " else " << *orelse;
      break;
    }
    case ExpressionKind::Alias: {
      const auto &alias = cast<Alias>(*this);
      auto &mod = alias.name();
      auto &asname = alias.asname();
      size_t i = 0;
      for (; i < mod.size() - 1; i++) {
        out << *mod[i] << ".";
      }
      out << *mod[i];
      if (asname) {
        out << " as " << **asname;
      }
      break;
    }
    case ExpressionKind::ListComp: {
      auto &comp = cast<ListComp>(*this);
      auto &elt = comp.elt();
      auto &generators = comp.generators();
      out << " [" << *elt;
      for (size_t i = 0; i < generators.size(); i++) {
        out << cast<Expression>(*generators[i]) << " ";
      }
      out << "] ";
      break;
    }
    case ExpressionKind::SetComp: {
      auto &comp = cast<SetComp>(*this);
      auto &elt = comp.elt();
      auto &generators = comp.generators();
      out << " {" << *elt;
      for (size_t i = 0; i < generators.size(); i++) {
        out << cast<Expression>(*generators[i]) << " ";
      }
      out << "} ";
      break;
    }
    case ExpressionKind::DictComp: {
      auto &comp = cast<DictComp>(*this);
      auto &key = comp.key();
      auto &value = comp.value();
      auto &generators = comp.generators();
      out << " {" << *key << " : " << *value;
      for (size_t i = 0; i < generators.size(); i++) {
        out << cast<Expression>(*generators[i]) << " ";
      }
      out << "} ";
      break;
    }
    case ExpressionKind::Comprehension: {
      auto &comp = cast<Comprehension>(*this);
      auto &target = comp.target();
      auto &iter = comp.iter();
      auto &ifs = comp.ifs();
      out << " for " << *target << " in " << *iter;
      if (ifs.size() > 0) {
        for (auto &if_expr: ifs)
          out << " if " << *if_expr;
      }
      break;
    }
    case ExpressionKind::Lambda: {
      auto &lambda = cast<Lambda>(*this);
      auto &args = lambda.args();
      auto &expr = lambda.expr();
      out << "lambda ";

      for (size_t i = 0; i < args.size(); i++) {
        if (i > 0) out << ", ";
        out << *args[i];
      }
      out << ": " << *expr;
      break;
    }
    case ExpressionKind::Slice: {
      auto &slice = cast<Slice>(*this);
      auto &lower = slice.lower();
      auto &upper = slice.upper();
      auto &step = slice.step();
      if (lower) out << **lower;
      out << " : ";
      if (upper) out << **upper;
      out << " : ";
      if (step) out << **step;
      break;
    }
    case ExpressionKind::Subscript: {
      auto &sub = cast<Subscript>(*this);
      auto &value = sub.value();
      auto &slice = sub.slice();
      out << *value << "[" << *slice << "]";
      break;
    }
    default:
      out << "...";
      break;
  }
}

}  // namespace PYJU
