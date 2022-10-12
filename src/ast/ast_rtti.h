// Generated from ast_rtti.txt by gen_rtti.py

#ifndef AST_RTTI_TXT_
#define AST_RTTI_TXT_

#include <string_view>

namespace PYJU {

enum class AstNodeKind {
  Module = 0,
  Interactive = 1,
  ModExpression = 2,
  FunctionType = 3,
  TestDeclaration = 4,
  FunctionDef = 5,
  AsyncFunctionDef = 6,
  ClassDef = 7,
  Return = 8,
  Delete = 9,
  Assign = 10,
  AugAssign = 11,
  AnnAssign = 12,
  For = 13,
  AsyncFor = 14,
  While = 15,
  If = 16,
  With = 17,
  WithItem = 18,
  AsyncWith = 19,
  Match = 20,
  Raise = 21,
  Try = 22,
  ExceptHandler = 23,
  Assert = 24,
  Import = 25,
  ImportFrom = 26,
  Global = 27,
  NonLocal = 28,
  ExprStmt = 29,
  TupleStmt = 30,
  Pass = 31,
  Break = 32,
  Continue = 33,
  BoolOp = 34,
  NamedExpr = 35,
  BinOp = 36,
  UnaryOp = 37,
  Lambda = 38,
  IfExp = 39,
  Dict = 40,
  Set = 41,
  Comprehension = 42,
  ListComp = 43,
  SetComp = 44,
  DictComp = 45,
  GeneratorExp = 46,
  Await = 47,
  Yield = 48,
  YieldFrom = 49,
  Compare = 50,
  Call = 51,
  FormattedValue = 52,
  JoinedStr = 53,
  ConstantStr = 54,
  ConstantInt = 55,
  ConstantFloat = 56,
  ConstantComplex = 57,
  ConstantEllipsis = 58,
  ConstantNone = 59,
  ConstantBool = 60,
  ConstantBytes = 61,
  Attribute = 62,
  Subscript = 63,
  Starred = 64,
  Star = 65,
  Keyword = 66,
  Arg = 67,
  NoPosOnlyArg = 68,
  StarArg = 69,
  FnArg = 70,
  Arguments = 71,
  Name = 72,
  List = 73,
  Tuple = 74,
  Slice = 75,
  Alias = 76,
  MatchValue = 77,
  MatchSingleton = 78,
  MatchSequence = 79,
  MatchMapping = 80,
  MatchClass = 81,
  MatchStar = 82,
  MatchAs = 83,
  MatchOr = 84,
  TypeIgnore = 85,
};

std::string_view AstNodeKindName(AstNodeKind k);

enum class ModuleBaseKind {
  Module = 0,
  Interactive = 1,
  ModExpression = 2,
  FunctionType = 3,
};

std::string_view ModuleBaseKindName(ModuleBaseKind k);

inline bool InheritsFromModuleBase(AstNodeKind kind) {
  return kind >= AstNodeKind::Module
      && kind < AstNodeKind::TestDeclaration
      ;
}

inline bool InheritsFromModule(AstNodeKind kind) {
    return kind == AstNodeKind::Module;
}

inline bool InheritsFromInteractive(AstNodeKind kind) {
    return kind == AstNodeKind::Interactive;
}

inline bool InheritsFromModExpression(AstNodeKind kind) {
    return kind == AstNodeKind::ModExpression;
}

inline bool InheritsFromFunctionType(AstNodeKind kind) {
    return kind == AstNodeKind::FunctionType;
}

enum class DeclarationKind {
  TestDeclaration = 4,
};

std::string_view DeclarationKindName(DeclarationKind k);

inline bool InheritsFromDeclaration(AstNodeKind kind) {
  return kind >= AstNodeKind::TestDeclaration
      && kind < AstNodeKind::FunctionDef
      ;
}

inline bool InheritsFromTestDeclaration(AstNodeKind kind) {
    return kind == AstNodeKind::TestDeclaration;
}

enum class StatementKind {
  FunctionDef = 5,
  AsyncFunctionDef = 6,
  ClassDef = 7,
  Return = 8,
  Delete = 9,
  Assign = 10,
  AugAssign = 11,
  AnnAssign = 12,
  For = 13,
  AsyncFor = 14,
  While = 15,
  If = 16,
  With = 17,
  WithItem = 18,
  AsyncWith = 19,
  Match = 20,
  Raise = 21,
  Try = 22,
  ExceptHandler = 23,
  Assert = 24,
  Import = 25,
  ImportFrom = 26,
  Global = 27,
  NonLocal = 28,
  ExprStmt = 29,
  TupleStmt = 30,
  Pass = 31,
  Break = 32,
  Continue = 33,
};

std::string_view StatementKindName(StatementKind k);

inline bool InheritsFromStatement(AstNodeKind kind) {
  return kind >= AstNodeKind::FunctionDef
      && kind < AstNodeKind::BoolOp
      ;
}

inline bool InheritsFromFunctionDef(AstNodeKind kind) {
    return kind == AstNodeKind::FunctionDef;
}

inline bool InheritsFromAsyncFunctionDef(AstNodeKind kind) {
    return kind == AstNodeKind::AsyncFunctionDef;
}

inline bool InheritsFromClassDef(AstNodeKind kind) {
    return kind == AstNodeKind::ClassDef;
}

inline bool InheritsFromReturn(AstNodeKind kind) {
    return kind == AstNodeKind::Return;
}

inline bool InheritsFromDelete(AstNodeKind kind) {
    return kind == AstNodeKind::Delete;
}

inline bool InheritsFromAssign(AstNodeKind kind) {
    return kind == AstNodeKind::Assign;
}

inline bool InheritsFromAugAssign(AstNodeKind kind) {
    return kind == AstNodeKind::AugAssign;
}

inline bool InheritsFromAnnAssign(AstNodeKind kind) {
    return kind == AstNodeKind::AnnAssign;
}

inline bool InheritsFromFor(AstNodeKind kind) {
    return kind == AstNodeKind::For;
}

inline bool InheritsFromAsyncFor(AstNodeKind kind) {
    return kind == AstNodeKind::AsyncFor;
}

inline bool InheritsFromWhile(AstNodeKind kind) {
    return kind == AstNodeKind::While;
}

inline bool InheritsFromIf(AstNodeKind kind) {
    return kind == AstNodeKind::If;
}

inline bool InheritsFromWith(AstNodeKind kind) {
    return kind == AstNodeKind::With;
}

inline bool InheritsFromWithItem(AstNodeKind kind) {
    return kind == AstNodeKind::WithItem;
}

inline bool InheritsFromAsyncWith(AstNodeKind kind) {
    return kind == AstNodeKind::AsyncWith;
}

inline bool InheritsFromMatch(AstNodeKind kind) {
    return kind == AstNodeKind::Match;
}

inline bool InheritsFromRaise(AstNodeKind kind) {
    return kind == AstNodeKind::Raise;
}

inline bool InheritsFromTry(AstNodeKind kind) {
    return kind == AstNodeKind::Try;
}

inline bool InheritsFromExceptHandler(AstNodeKind kind) {
    return kind == AstNodeKind::ExceptHandler;
}

inline bool InheritsFromAssert(AstNodeKind kind) {
    return kind == AstNodeKind::Assert;
}

inline bool InheritsFromImport(AstNodeKind kind) {
    return kind == AstNodeKind::Import;
}

inline bool InheritsFromImportFrom(AstNodeKind kind) {
    return kind == AstNodeKind::ImportFrom;
}

inline bool InheritsFromGlobal(AstNodeKind kind) {
    return kind == AstNodeKind::Global;
}

inline bool InheritsFromNonLocal(AstNodeKind kind) {
    return kind == AstNodeKind::NonLocal;
}

inline bool InheritsFromExprStmt(AstNodeKind kind) {
    return kind == AstNodeKind::ExprStmt;
}

inline bool InheritsFromTupleStmt(AstNodeKind kind) {
    return kind == AstNodeKind::TupleStmt;
}

inline bool InheritsFromPass(AstNodeKind kind) {
    return kind == AstNodeKind::Pass;
}

inline bool InheritsFromBreak(AstNodeKind kind) {
    return kind == AstNodeKind::Break;
}

inline bool InheritsFromContinue(AstNodeKind kind) {
    return kind == AstNodeKind::Continue;
}

enum class ExpressionKind {
  BoolOp = 34,
  NamedExpr = 35,
  BinOp = 36,
  UnaryOp = 37,
  Lambda = 38,
  IfExp = 39,
  Dict = 40,
  Set = 41,
  Comprehension = 42,
  ListComp = 43,
  SetComp = 44,
  DictComp = 45,
  GeneratorExp = 46,
  Await = 47,
  Yield = 48,
  YieldFrom = 49,
  Compare = 50,
  Call = 51,
  FormattedValue = 52,
  JoinedStr = 53,
  ConstantStr = 54,
  ConstantInt = 55,
  ConstantFloat = 56,
  ConstantComplex = 57,
  ConstantEllipsis = 58,
  ConstantNone = 59,
  ConstantBool = 60,
  ConstantBytes = 61,
  Attribute = 62,
  Subscript = 63,
  Starred = 64,
  Star = 65,
  Keyword = 66,
  Arg = 67,
  NoPosOnlyArg = 68,
  StarArg = 69,
  FnArg = 70,
  Arguments = 71,
  Name = 72,
  List = 73,
  Tuple = 74,
  Slice = 75,
  Alias = 76,
};

std::string_view ExpressionKindName(ExpressionKind k);

inline bool InheritsFromExpression(AstNodeKind kind) {
  return kind >= AstNodeKind::BoolOp
      && kind < AstNodeKind::MatchValue
      ;
}

inline bool InheritsFromBoolOp(AstNodeKind kind) {
    return kind == AstNodeKind::BoolOp;
}

inline bool InheritsFromNamedExpr(AstNodeKind kind) {
    return kind == AstNodeKind::NamedExpr;
}

inline bool InheritsFromBinOp(AstNodeKind kind) {
    return kind == AstNodeKind::BinOp;
}

inline bool InheritsFromUnaryOp(AstNodeKind kind) {
    return kind == AstNodeKind::UnaryOp;
}

inline bool InheritsFromLambda(AstNodeKind kind) {
    return kind == AstNodeKind::Lambda;
}

inline bool InheritsFromIfExp(AstNodeKind kind) {
    return kind == AstNodeKind::IfExp;
}

inline bool InheritsFromDict(AstNodeKind kind) {
    return kind == AstNodeKind::Dict;
}

inline bool InheritsFromSet(AstNodeKind kind) {
    return kind == AstNodeKind::Set;
}

inline bool InheritsFromComprehension(AstNodeKind kind) {
    return kind == AstNodeKind::Comprehension;
}

inline bool InheritsFromListComp(AstNodeKind kind) {
    return kind == AstNodeKind::ListComp;
}

inline bool InheritsFromSetComp(AstNodeKind kind) {
    return kind == AstNodeKind::SetComp;
}

inline bool InheritsFromDictComp(AstNodeKind kind) {
    return kind == AstNodeKind::DictComp;
}

inline bool InheritsFromGeneratorExp(AstNodeKind kind) {
    return kind == AstNodeKind::GeneratorExp;
}

inline bool InheritsFromAwait(AstNodeKind kind) {
    return kind == AstNodeKind::Await;
}

inline bool InheritsFromYield(AstNodeKind kind) {
    return kind == AstNodeKind::Yield;
}

inline bool InheritsFromYieldFrom(AstNodeKind kind) {
    return kind == AstNodeKind::YieldFrom;
}

inline bool InheritsFromCompare(AstNodeKind kind) {
    return kind == AstNodeKind::Compare;
}

inline bool InheritsFromCall(AstNodeKind kind) {
    return kind == AstNodeKind::Call;
}

inline bool InheritsFromFormattedValue(AstNodeKind kind) {
    return kind == AstNodeKind::FormattedValue;
}

inline bool InheritsFromJoinedStr(AstNodeKind kind) {
    return kind == AstNodeKind::JoinedStr;
}

inline bool InheritsFromConstantStr(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantStr;
}

inline bool InheritsFromConstantInt(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantInt;
}

inline bool InheritsFromConstantFloat(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantFloat;
}

inline bool InheritsFromConstantComplex(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantComplex;
}

inline bool InheritsFromConstantEllipsis(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantEllipsis;
}

inline bool InheritsFromConstantNone(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantNone;
}

inline bool InheritsFromConstantBool(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantBool;
}

inline bool InheritsFromConstantBytes(AstNodeKind kind) {
    return kind == AstNodeKind::ConstantBytes;
}

inline bool InheritsFromAttribute(AstNodeKind kind) {
    return kind == AstNodeKind::Attribute;
}

inline bool InheritsFromSubscript(AstNodeKind kind) {
    return kind == AstNodeKind::Subscript;
}

inline bool InheritsFromStarred(AstNodeKind kind) {
    return kind == AstNodeKind::Starred;
}

inline bool InheritsFromStar(AstNodeKind kind) {
    return kind == AstNodeKind::Star;
}

inline bool InheritsFromKeyword(AstNodeKind kind) {
    return kind == AstNodeKind::Keyword;
}

inline bool InheritsFromArg(AstNodeKind kind) {
    return kind == AstNodeKind::Arg;
}

inline bool InheritsFromNoPosOnlyArg(AstNodeKind kind) {
    return kind == AstNodeKind::NoPosOnlyArg;
}

inline bool InheritsFromStarArg(AstNodeKind kind) {
    return kind == AstNodeKind::StarArg;
}

inline bool InheritsFromFnArg(AstNodeKind kind) {
    return kind == AstNodeKind::FnArg;
}

inline bool InheritsFromArguments(AstNodeKind kind) {
    return kind == AstNodeKind::Arguments;
}

inline bool InheritsFromName(AstNodeKind kind) {
    return kind == AstNodeKind::Name;
}

inline bool InheritsFromList(AstNodeKind kind) {
    return kind == AstNodeKind::List;
}

inline bool InheritsFromTuple(AstNodeKind kind) {
    return kind == AstNodeKind::Tuple;
}

inline bool InheritsFromSlice(AstNodeKind kind) {
    return kind == AstNodeKind::Slice;
}

inline bool InheritsFromAlias(AstNodeKind kind) {
    return kind == AstNodeKind::Alias;
}

enum class PatternKind {
  MatchValue = 77,
  MatchSingleton = 78,
  MatchSequence = 79,
  MatchMapping = 80,
  MatchClass = 81,
  MatchStar = 82,
  MatchAs = 83,
  MatchOr = 84,
};

std::string_view PatternKindName(PatternKind k);

inline bool InheritsFromPattern(AstNodeKind kind) {
  return kind >= AstNodeKind::MatchValue
      && kind < AstNodeKind::TypeIgnore
      ;
}

inline bool InheritsFromMatchValue(AstNodeKind kind) {
    return kind == AstNodeKind::MatchValue;
}

inline bool InheritsFromMatchSingleton(AstNodeKind kind) {
    return kind == AstNodeKind::MatchSingleton;
}

inline bool InheritsFromMatchSequence(AstNodeKind kind) {
    return kind == AstNodeKind::MatchSequence;
}

inline bool InheritsFromMatchMapping(AstNodeKind kind) {
    return kind == AstNodeKind::MatchMapping;
}

inline bool InheritsFromMatchClass(AstNodeKind kind) {
    return kind == AstNodeKind::MatchClass;
}

inline bool InheritsFromMatchStar(AstNodeKind kind) {
    return kind == AstNodeKind::MatchStar;
}

inline bool InheritsFromMatchAs(AstNodeKind kind) {
    return kind == AstNodeKind::MatchAs;
}

inline bool InheritsFromMatchOr(AstNodeKind kind) {
    return kind == AstNodeKind::MatchOr;
}

inline bool InheritsFromTypeIgnore(AstNodeKind kind) {
    return kind == AstNodeKind::TypeIgnore;
}

}  // namespace PYJU

#endif  // AST_RTTI_TXT_
