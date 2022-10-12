// Generated from ast_rtti.txt by gen_rtti.py

#include "ast/ast_rtti.h"

namespace PYJU {

std::string_view AstNodeKindName(AstNodeKind k) {
  switch(k) {
    case AstNodeKind::Module: return "module";
    case AstNodeKind::Interactive: return "interactive";
    case AstNodeKind::ModExpression: return "mod expression";
    case AstNodeKind::FunctionType: return "function type";
    case AstNodeKind::TestDeclaration: return "test declaration";
    case AstNodeKind::FunctionDef: return "function def";
    case AstNodeKind::AsyncFunctionDef: return "async function def";
    case AstNodeKind::ClassDef: return "class def";
    case AstNodeKind::Return: return "return";
    case AstNodeKind::Delete: return "delete";
    case AstNodeKind::Assign: return "assign";
    case AstNodeKind::AugAssign: return "aug assign";
    case AstNodeKind::AnnAssign: return "ann assign";
    case AstNodeKind::For: return "for";
    case AstNodeKind::AsyncFor: return "async for";
    case AstNodeKind::While: return "while";
    case AstNodeKind::If: return "if";
    case AstNodeKind::With: return "with";
    case AstNodeKind::WithItem: return "with item";
    case AstNodeKind::AsyncWith: return "async with";
    case AstNodeKind::Match: return "match";
    case AstNodeKind::Raise: return "raise";
    case AstNodeKind::Try: return "try";
    case AstNodeKind::ExceptHandler: return "except handler";
    case AstNodeKind::Assert: return "assert";
    case AstNodeKind::Import: return "import";
    case AstNodeKind::ImportFrom: return "import from";
    case AstNodeKind::Global: return "global";
    case AstNodeKind::NonLocal: return "non local";
    case AstNodeKind::ExprStmt: return "expr stmt";
    case AstNodeKind::TupleStmt: return "tuple stmt";
    case AstNodeKind::Pass: return "pass";
    case AstNodeKind::Break: return "break";
    case AstNodeKind::Continue: return "continue";
    case AstNodeKind::BoolOp: return "bool op";
    case AstNodeKind::NamedExpr: return "named expr";
    case AstNodeKind::BinOp: return "bin op";
    case AstNodeKind::UnaryOp: return "unary op";
    case AstNodeKind::Lambda: return "lambda";
    case AstNodeKind::IfExp: return "if exp";
    case AstNodeKind::Dict: return "dict";
    case AstNodeKind::Set: return "set";
    case AstNodeKind::ListComp: return "list comp";
    case AstNodeKind::SetComp: return "set comp";
    case AstNodeKind::DictComp: return "dict comp";
    case AstNodeKind::GeneratorExp: return "generator exp";
    case AstNodeKind::Await: return "await";
    case AstNodeKind::Yield: return "yield";
    case AstNodeKind::YieldFrom: return "yield from";
    case AstNodeKind::Compare: return "compare";
    case AstNodeKind::Call: return "call";
    case AstNodeKind::FormattedValue: return "formatted value";
    case AstNodeKind::JoinedStr: return "joined str";
    case AstNodeKind::ConstantStr: return "constant str";
    case AstNodeKind::ConstantInt: return "constant int";
    case AstNodeKind::ConstantFloat: return "constant float";
    case AstNodeKind::ConstantComplex: return "constant complex";
    case AstNodeKind::ConstantEllipsis: return "constant ellipsis";
    case AstNodeKind::ConstantNone: return "constant none";
    case AstNodeKind::ConstantBool: return "constant bool";
    case AstNodeKind::ConstantBytes: return "constant bytes";
    case AstNodeKind::Attribute: return "attribute";
    case AstNodeKind::Subscript: return "subscript";
    case AstNodeKind::Starred: return "starred";
    case AstNodeKind::Star: return "star";
    case AstNodeKind::Keyword: return "keyword";
    case AstNodeKind::Arg: return "arg";
    case AstNodeKind::NoPosOnlyArg: return "no pos only arg";
    case AstNodeKind::StarArg: return "star arg";
    case AstNodeKind::FnArg: return "fn arg";
    case AstNodeKind::Arguments: return "arguments";
    case AstNodeKind::Name: return "name";
    case AstNodeKind::List: return "list";
    case AstNodeKind::Tuple: return "tuple";
    case AstNodeKind::Slice: return "slice";
    case AstNodeKind::Alias: return "alias";
    case AstNodeKind::MatchValue: return "match value";
    case AstNodeKind::MatchSingleton: return "match singleton";
    case AstNodeKind::MatchSequence: return "match sequence";
    case AstNodeKind::MatchMapping: return "match mapping";
    case AstNodeKind::MatchClass: return "match class";
    case AstNodeKind::MatchStar: return "match star";
    case AstNodeKind::MatchAs: return "match as";
    case AstNodeKind::MatchOr: return "match or";
    case AstNodeKind::TypeIgnore: return "type ignore";
  }
}

std::string_view ModuleBaseKindName(ModuleBaseKind k) {
  switch(k) {
    case ModuleBaseKind::Module: return "module";
    case ModuleBaseKind::Interactive: return "interactive";
    case ModuleBaseKind::ModExpression: return "mod expression";
    case ModuleBaseKind::FunctionType: return "function type";
  }
}

std::string_view DeclarationKindName(DeclarationKind k) {
  switch(k) {
    case DeclarationKind::TestDeclaration: return "test declaration";
  }
}

std::string_view StatementKindName(StatementKind k) {
  switch(k) {
    case StatementKind::FunctionDef: return "function def";
    case StatementKind::AsyncFunctionDef: return "async function def";
    case StatementKind::ClassDef: return "class def";
    case StatementKind::Return: return "return";
    case StatementKind::Delete: return "delete";
    case StatementKind::Assign: return "assign";
    case StatementKind::AugAssign: return "aug assign";
    case StatementKind::AnnAssign: return "ann assign";
    case StatementKind::For: return "for";
    case StatementKind::AsyncFor: return "async for";
    case StatementKind::While: return "while";
    case StatementKind::If: return "if";
    case StatementKind::With: return "with";
    case StatementKind::WithItem: return "with item";
    case StatementKind::AsyncWith: return "async with";
    case StatementKind::Match: return "match";
    case StatementKind::Raise: return "raise";
    case StatementKind::Try: return "try";
    case StatementKind::ExceptHandler: return "except handler";
    case StatementKind::Assert: return "assert";
    case StatementKind::Import: return "import";
    case StatementKind::ImportFrom: return "import from";
    case StatementKind::Global: return "global";
    case StatementKind::NonLocal: return "non local";
    case StatementKind::ExprStmt: return "expr stmt";
    case StatementKind::TupleStmt: return "tuple stmt";
    case StatementKind::Pass: return "pass";
    case StatementKind::Break: return "break";
    case StatementKind::Continue: return "continue";
  }
}

std::string_view ExpressionKindName(ExpressionKind k) {
  switch(k) {
    case ExpressionKind::BoolOp: return "bool op";
    case ExpressionKind::NamedExpr: return "named expr";
    case ExpressionKind::BinOp: return "bin op";
    case ExpressionKind::UnaryOp: return "unary op";
    case ExpressionKind::Lambda: return "lambda";
    case ExpressionKind::IfExp: return "if exp";
    case ExpressionKind::Dict: return "dict";
    case ExpressionKind::Set: return "set";
    case ExpressionKind::ListComp: return "list comp";
    case ExpressionKind::SetComp: return "set comp";
    case ExpressionKind::DictComp: return "dict comp";
    case ExpressionKind::GeneratorExp: return "generator exp";
    case ExpressionKind::Await: return "await";
    case ExpressionKind::Yield: return "yield";
    case ExpressionKind::YieldFrom: return "yield from";
    case ExpressionKind::Compare: return "compare";
    case ExpressionKind::Call: return "call";
    case ExpressionKind::FormattedValue: return "formatted value";
    case ExpressionKind::JoinedStr: return "joined str";
    case ExpressionKind::ConstantStr: return "constant str";
    case ExpressionKind::ConstantInt: return "constant int";
    case ExpressionKind::ConstantFloat: return "constant float";
    case ExpressionKind::ConstantComplex: return "constant complex";
    case ExpressionKind::ConstantEllipsis: return "constant ellipsis";
    case ExpressionKind::ConstantNone: return "constant none";
    case ExpressionKind::ConstantBool: return "constant bool";
    case ExpressionKind::ConstantBytes: return "constant bytes";
    case ExpressionKind::Attribute: return "attribute";
    case ExpressionKind::Subscript: return "subscript";
    case ExpressionKind::Starred: return "starred";
    case ExpressionKind::Star: return "star";
    case ExpressionKind::Keyword: return "keyword";
    case ExpressionKind::Arg: return "arg";
    case ExpressionKind::NoPosOnlyArg: return "no pos only arg";
    case ExpressionKind::StarArg: return "star arg";
    case ExpressionKind::FnArg: return "fn arg";
    case ExpressionKind::Arguments: return "arguments";
    case ExpressionKind::Name: return "name";
    case ExpressionKind::List: return "list";
    case ExpressionKind::Tuple: return "tuple";
    case ExpressionKind::Slice: return "slice";
    case ExpressionKind::Alias: return "alias";
  }
}

std::string_view PatternKindName(PatternKind k) {
  switch(k) {
    case PatternKind::MatchValue: return "match value";
    case PatternKind::MatchSingleton: return "match singleton";
    case PatternKind::MatchSequence: return "match sequence";
    case PatternKind::MatchMapping: return "match mapping";
    case PatternKind::MatchClass: return "match class";
    case PatternKind::MatchStar: return "match star";
    case PatternKind::MatchAs: return "match as";
    case PatternKind::MatchOr: return "match or";
  }
}

}  // namespace PYJU

