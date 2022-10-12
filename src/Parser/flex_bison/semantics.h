#pragma once

#include "ast/ast.h"
#include "ast/name.h"
#include "ast/statement.h"
#include "llvm/Support/Casting.h"

#include <iostream>

#define RESULT(x) do { \
    if (*ast == std::nullopt) { \
        *ast = std::make_shared<PYJU::AST>();    \
    }   \
    ast->value()->statements.push_back(x);   \
} while (0)

#define SYMBOL(x, l) PYJU::Name::make_Name(arena, l, x)

#define LIST_NEW(l) l.reserve(4)
#define LIST_ADD(l, x) l.push_back(x)

#define EXPR_01(e, l) PYJU::ExprStmt::make_ExprStmt(arena, l, e)

#define IF_STMT_01(e, stmt, l) PYJU::If::make_If(arena, l, \
        e, stmt, {})
#define IF_STMT_02(e, stmt, orelse, l) PYJU::If::make_If(arena, l, \
        e, stmt, orelse)
#define IF_STMT_03(e, stmt, orelse, l) PYJU::If::make_If(arena, l, \
        e, stmt, {orelse})

#define INTEGER(x, l) PYJU::ConstantInt::make_ConstantInt(arena, l, x)
#define FLOAT(x, l) PYJU::ConstantFloat::make_ConstantFloat(arena, l, x)
#define COMPLEX(x, l) PYJU::ConstantComplex::make_ConstantComplex(arena, l, 0, x)
#define BOOL(x, l) PYJU::ConstantBool::make_ConstantBool(arena, l, x)

#define ELLIPSIS(l) PYJU::ConstantEllipsis::make_ConstantEllipsis(arena,l)
#define NONE(l) PYJU::ConstantNone::make_ConstantNone(arena, l)

#define STRING1(x, l) PYJU::ConstantStr::make_ConstantStr(arena, l, \
        unescape(x))
#define STRING2(x, y, l) concat_string(arena, l, x, y)
#define STRING3(id, x, l) PREFIX_STRING(arena, l, id->name(), x)
#define STRING4(x, id, y, l) concat_string(arena, l, x, STRING3(id, y, l))

static inline std::string unescape(const std::string &s) {
    // std::string x;
    // for (size_t idx=0; idx < s.size(); idx++) {
    //     if (s[idx] == '\\' && s[idx+1] == 'n') {
    //         x += "\n";
    //         idx++;
    //     } else {
    //         x += s[idx];
    //     }
    // }
    // return x;
    return s;
}

static inline PYJU::Nonnull<PYJU::Expression*> concat_string(
    PYJU::Nonnull<PYJU::Arena*> arena,
    const PYJU::SourceLocation &loc,
    PYJU::Nonnull<PYJU::Expression*> a,
    PYJU::Nonnull<PYJU::Expression*> b) {
    if (PYJU::JoinedStr::classof(a)) {
        // JoinedStr
        auto &joinedStr = llvm::cast<PYJU::JoinedStr>(*a);
        joinedStr.join(b);
        return a;
    } else if (PYJU::ConstantStr::classof(a) ||
               PYJU::ConstantBytes::classof(a)) {
        if (PYJU::ConstantStr::classof(b) ||
            PYJU::ConstantBytes::classof(b) ||
            PYJU::JoinedStr::classof(b)) {
            llvm::cast<PYJU::ConstantStr>(*a).extend(b);
        } else {
            std::cout << "Error: invalid expression kind" << std::endl;
            exit(0);
        }

        return a;
    } else {
        std::cout << "Error: invalid expression kind" << std::endl;
        exit(0);
    }
}

static inline PYJU::Nonnull<PYJU::Expression*> concat_string(
    PYJU::Nonnull<PYJU::Arena*> arena,
    const PYJU::SourceLocation &loc,
    PYJU::Nonnull<PYJU::Expression*> a,
    std::string b) {
    if (PYJU::JoinedStr::classof(a)) {
        // JoinedStr
        auto &joinedStr = llvm::cast<PYJU::JoinedStr>(*a);
        auto constantStr = STRING1(std::move(b), loc);
        joinedStr.join(constantStr);
        return a;
    } else if (PYJU::ConstantStr::classof(a)) {
        llvm::cast<PYJU::ConstantStr>(*a).concat(b);
        return a;
    } else {
        std::cout << "Error: invalid expression kind" << std::endl;
        exit(0);
    }
}

static inline NonnullExpr PREFIX_STRING(
    NonnullArena arena,
    const PYJU::SourceLocation &l,
    std::string prefix,
    std::string s) {

    std::vector<NonnullExpr> exprs;
    exprs.reserve(4);
    NonnullExpr tmp = nullptr;
    if (prefix == "U") {
        return PYJU::ConstantStr::make_ConstantStr(arena, l,  s);
    }
    for (size_t i = 0; i < prefix.size(); i++) {
        prefix[i] = tolower(prefix[i]);
    }
    if (prefix == "f" || prefix == "fr" || prefix == "rf") {
        std::string str = s;
        std::string s1 = "";
        std::string id;
        std::vector<std::string> strs;
        bool open_paren = false;
        for (size_t i = 0; i < str.length(); i++) {
            if(str[i] == '{') {
                if(s1 != "") {
                    strs.push_back(s1);
                    s1 = "";
                }
                open_paren = true;
            } else if (str[i] != '}' && open_paren) {
                id.push_back(s[i]);
            } else if (str[i] == '}') {
                if(id != "") {
                    strs.push_back("{" + id + "}");
                    id = "";
                }
                open_paren = false;
            } else if (!open_paren) {
                s1.push_back(str[i]);
            }
            if(i == str.length()-1 && s1 != "") {
                strs.push_back(s1);
            }
        }

        for (size_t i = 0; i < strs.size(); i++) {
            auto last_c = strs[i][strs[i].length()-1];
            if (strs[i][0] == '{' && last_c == '}') {
                strs[i] = strs[i].substr(1, strs[i].length() - 2);
                tmp = PYJU::Name::make_Name(arena, l, strs[i]);
                tmp = PYJU::FormattedValue::make_FormattedValue(arena,
                                                                      l,
                                                                      tmp,
                                                                      -1);
                exprs.push_back(tmp);
            } else {
                tmp = PYJU::ConstantStr::make_ConstantStr(arena,
                                                                l,
                                                                strs[i]);
                exprs.push_back(tmp);
            }
        }
        tmp = PYJU::JoinedStr::make_JoinedStr(arena, l, exprs);
    } else if (prefix == "b" || prefix == "br" || prefix == "rb") {
        std::string str = std::string(s);
        size_t start_pos = 0;
        while((start_pos = str.find("\n", start_pos)) != std::string::npos) {
                str.replace(start_pos, 1, "\\n");
                start_pos += 2;
        }
        str = "b'" + str + "'";
        tmp = PYJU::ConstantBytes::make_ConstantBytes(arena, l, str);
    } else if (prefix == "r") {
        tmp = PYJU::ConstantStr::make_ConstantStr(arena, l,  s);
    } else if (prefix == "u") {
        tmp = PYJU::ConstantStr::make_ConstantStr(
                arena, l, s, std::string("u"));
    } else {
        std::cout << ("The string is not recognized by the parser.")
                  << std::endl;
        exit(0);
    }
    return tmp;
}

#define LIST(e, l) PYJU::List::make_List(arena, l, e)
#define SET(e, l) PYJU::Set::make_Set(arena, l, e)
#define ATTRIBUTE_REF(val, attr, l) \
    PYJU::Attribute::make_Attribute(arena, l, val, attr)

#define DICT_01(l) PYJU::Dict::make_Dict(arena, l, {})
#define DICT_02(dict_list, l) PYJU::Dict::make_Dict(arena, l, dict_list)

#define DICT_EXPR(key, value, l) std::make_pair(key, value)

#define NAMEDEXPR(x, y, l) PYJU::NamedExpr::make_NamedExpr(arena, l, x, y)
#define STARRED_ARG(e, l) PYJU::Starred::make_Starred(arena, l, e)

#define BINOP(x, op, y, l) PYJU::BinOp::make_BinOp(arena, l, \
        x, PYJU::operatorType::op, y)
#define UNARY(x, op, l) PYJU::UnaryOp::make_UnaryOp(arena, l, \
        PYJU::unaryopType::op, x)

#define COMPARE(x, op, y, l) PYJU::Compare::make_Compare(arena, l, \
        x, cmpopType::op, y)
#define BOOLOP(x, op, y, l) PYJU::BoolOp::make_BoolOp(arena, l, \
        x, boolopType::op, y)


static inline PYJU::Nonnull<PYJU::Arg*>
    FUNC_ARG(NonnullArena arena,
             PYJU::SourceLocation l,
             NonnullExpr arg,
             std::optional<NonnullExpr> annotation,
             std::optional<NonnullExpr> defaults) {
    auto r = PYJU::Arg::make_Arg(arena, l, arg);
    r->annotation_ = annotation;
    r->type_comment_ = std::nullopt;
    r->defaults_ = defaults;
    return r;
}

#define ARGS_01(arg, l) FUNC_ARG(arena, l, \
        arg, std::nullopt, std::nullopt)
#define ARGS_02(arg, annotation, l) FUNC_ARG(arena, l, \
        arg, annotation, std::nullopt)
#define ARGS_03(arg, defaults, l) FUNC_ARG(arena, l, \
        arg, std::nullopt, defaults)
#define ARGS_04(arg, ann, defaults, l) FUNC_ARG(arena, l, \
        arg, ann, defaults)

static inline PYJU::Nonnull<PYJU::FnArg*>
    FN_ARG(NonnullArena arena,
           std::vector<NonnullArg> posonlyargs,
           std::optional<PYJU::Nonnull<PYJU::NoPosOnlyArg*>> args) {
    auto r = PYJU::FnArg::make_FnArg(arena,
                PYJU::SourceLocation("invalid file", 0));
    r->posonlyargs_ = posonlyargs;
    r->args_ = args;
    return r;
}

#define PARAMETER_LIST_01(posonlyargs, args) \
        FN_ARG(arena, posonlyargs, args)

#define PARAMETER_LIST_02(args) FN_ARG(arena, {}, args)


static inline PYJU::Nonnull<PYJU::NoPosOnlyArg*>
    ARGS(NonnullArena arena, std::vector<NonnullArg> args,
    std::optional<PYJU::Nonnull<PYJU::StarArg*>> stararg) {
    auto r = PYJU::NoPosOnlyArg::make_NoPosOnlyArg(arena,
                PYJU::SourceLocation("ARGS", 0));
    r->args_ = args;
    r->stararg_ = stararg;
    return r;
}
#define PARAMETER_LIST_03(args, stararg) ARGS(arena, args, stararg)
#define PARAMETER_LIST_04(stararg) ARGS(arena, {}, stararg)

static inline PYJU::Nonnull<PYJU::StarArg*> STAR_ARG(
        NonnullArena arena,
        std::vector<NonnullArg> varargs,
        std::vector<NonnullArg> kwonlyargs,
        std::vector<NonnullArg> kwarg) {
    auto r = PYJU::StarArg::make_StarArg(arena,
                PYJU::SourceLocation("STAR_ARG", 0));
    r->varargs_ = varargs;
    r->kwonlyargs_ = kwonlyargs;
    r->kwarg_ = kwarg;
    return r;
}
#define PARAMETER_LIST_05(kwonlyargs) STAR_ARG(arena, {}, \
        kwonlyargs, {})
#define PARAMETER_LIST_06(kwarg) STAR_ARG(arena, {}, {}, {kwarg})

#define PARAMETER_LIST_07(kwonlyargs, kwarg) STAR_ARG(arena, {}, \
        kwonlyargs, {kwarg})

#define PARAMETER_LIST_08(vararg) STAR_ARG(arena, {vararg}, {}, {})
#define PARAMETER_LIST_09(vararg, kwonlyargs)  STAR_ARG(arena, {vararg}, \
        kwonlyargs, {})
#define PARAMETER_LIST_10(vararg, kwarg)  STAR_ARG(arena, {vararg}, {}, {kwarg})
#define PARAMETER_LIST_11(vararg, kwonlyargs, kwarg) STAR_ARG(arena, {vararg}, \
        kwonlyargs, {kwarg})
#define PARAMETER_LIST_12(l) FUNC_ARGS_01(arena, l, std::nullopt)

#define FUNC_ARGS_(x, kw) \
    for(auto exp : x) { \
        r->x##_.push_back(exp); \
        if(exp->defaults_.has_value() && !kw) { \
            defaults.push_back(*(exp->defaults_)); \
        } else if (exp->defaults_.has_value()){ \
            kw_defaults.push_back(*(exp->defaults_)); \
        } \
    }


static inline PYJU::Nonnull<PYJU::Arguments*>
        FUNC_ARGS_01(NonnullArena arena, PYJU::SourceLocation l,
        std::optional<PYJU::Nonnull<PYJU::FnArg*>> parameters) {
    auto r = PYJU::Arguments::make_Arguments(arena, l);
    std::vector<NonnullExpr> defaults;
    defaults.reserve(4);
    std::vector<NonnullExpr> kw_defaults;
    kw_defaults.reserve(4);

    if(parameters == std::nullopt) {
        return r;
    }

    auto &posonlyargs = (*parameters)->posonlyargs_;
    FUNC_ARGS_(posonlyargs, false);

    if (!parameters.has_value() || !(*parameters)->args_.has_value()) {
        r->kw_defaults_ = kw_defaults;
        r->defaults_ = defaults;
        return r;
    }

    auto &noposonlyargs = (*parameters)->args_;
    if (!noposonlyargs.has_value()) {
        r->kw_defaults_ = kw_defaults;
        r->defaults_ = defaults;
        return r;
    }
    auto &args = (*noposonlyargs)->args_;
    FUNC_ARGS_(args, false);

    auto &stararg = (*noposonlyargs)->stararg_;
    if (!stararg.has_value()) {
        r->kw_defaults_ = kw_defaults;
        r->defaults_ = defaults;
        return r;
    }

    auto& varargs = (*stararg)->varargs_;
    FUNC_ARGS_(varargs, false);

    auto &kwonlyargs = (*stararg)->kwonlyargs_;
    FUNC_ARGS_(kwonlyargs, true);

    auto &kwarg = (*stararg)->kwarg_;
    FUNC_ARGS_(kwarg, true);

    r->kw_defaults_ = kw_defaults;
    r->defaults_ = defaults;
    return r;
}


#define FUNCTION_01(decorator, id, args, stmts, l) \
    PYJU::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, std::nullopt, std::nullopt)
#define FUNCTION_02(decorator, id, args, returns, stmts, l) \
    PYJU::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, returns, std::nullopt)
#define FUNCTION_03(decorator, id, args, stmts, type_comment, l) \
    PYJU::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, std::nullopt, type_comment)

#define FUNCTION_04(decorator, id, args, returns, stmts, type_comment, l) \
    PYJU::FunctionDef::make_FunctionDef(arena, l, \
        id, args, stmts, decorator, returns, type_comment)

static inline PYJU::Nonnull<PYJU::Keyword*> CALL_KW(
        NonnullArena arena, PYJU::SourceLocation l,
        std::optional<NonnullExpr> arg, NonnullExpr val) {
    return PYJU::Keyword::make_Keyword(arena, l, arg, val);
}

#define CALL_KEYWORD_01(arg, val, l) CALL_KW(arena, l, arg, val)
#define CALL_KEYWORD_02(val, l) CALL_KW(arena, l, std::nullopt, val)
#define CALL_01(func, args, l) PYJU::Call::make_Call(arena, l, \
        func, args, {})
#define CALL_02(func, args, keywords, l) PYJU::Call::make_Call(arena, l, \
        func, args, keywords)
#define CALL_03(func, keywords, l) PYJU::Call::make_Call(arena, l, \
        func, {}, keywords)

#define TERNARY(test, body, orelse, l) PYJU::IfExp::make_IfExp(arena, l, \
        test, body, orelse)

#define GLOBAL(names, l) PYJU::Global::make_Global(arena, l, names)

#define NON_LOCAL(names, l) PYJU::NonLocal::make_NonLocal(arena, l, names)


static inline PYJU::Nonnull<PYJU::Alias*> IMPORT_ALIAS_01(NonnullArena arena,
    PYJU::SourceLocation l,
    std::vector<NonnullExpr> name,
    std::optional<NonnullExpr> asname){
    return PYJU::Alias::make_Alias(arena, l, name, asname);
}

#define MOD_ID_01(module, l) IMPORT_ALIAS_01(arena, l, module, std::nullopt)
#define MOD_ID_02(module, as_id, l) IMPORT_ALIAS_01(arena, l, module, as_id)
#define MOD_ID_03(l) IMPORT_ALIAS_01(arena, l, \
    {PYJU::Star::make_Star(arena, l)}, std::nullopt)

inline int dot_count(int inc = 0) {
    static int dot_count = 0;
    if (inc > 0) {
        dot_count += inc;
    }

    if (inc < 0) {
        dot_count = 0;
    }
    return dot_count;
}
#define DOT_COUNT_01() dot_count(1)
#define DOT_COUNT_02() dot_count(3)

#define IMPORT_01(names, l) PYJU::Import::make_Import(arena, l, names)
#define IMPORT_02(module, names, l) PYJU::ImportFrom::make_ImportFrom(arena, l, \
        module, names, 0)
#define IMPORT_03(names, l) PYJU::ImportFrom::make_ImportFrom(arena, l, \
        {}, names, dot_count()); dot_count(-1)
#define IMPORT_04(module, names, l)PYJU::ImportFrom::make_ImportFrom(arena, l, \
        module, names, dot_count()); \
        dot_count(-1)

#define PASS(l) PYJU::Pass::make_Pass(arena, l)
#define BREAK(l) PYJU::Break::make_Break(arena, l)
#define CONTINUE(l) PYJU::Continue::make_Continue(arena, l)

#define RAISE_01(l) PYJU::Raise::make_Raise(arena, l, std::nullopt, std::nullopt)
#define RAISE_02(exec, l) PYJU::Raise::make_Raise(arena, l, exec, std::nullopt)
#define RAISE_03(exec, cause, l) PYJU::Raise::make_Raise(arena, l, exec, cause)

#define ASSERT_01(test, l) PYJU::Assert::make_Assert(arena, l, test, std::nullopt)
#define ASSERT_02(test, msg, l) PYJU::Assert::make_Assert(arena, l, test, msg)

static inline NonnullExpr TUPLE_02(NonnullArena &arena, PYJU::SourceLocation l,
    std::vector<NonnullExpr> elts) {
    if (elts.size() == 1) {
        return elts[0];
    }
    return PYJU::Tuple::make_Tuple(arena, l, elts);
}

#define TUPLE_01(elts, l) TUPLE_02(arena, l, elts)
#define TUPLE_03(elts, l) PYJU::Tuple::make_Tuple(arena, l, elts)
#define TUPLE_EMPTY(l) PYJU::Tuple::make_Tuple(arena, l, {})
inline std::vector<NonnullExpr> TUPLE_APPEND(std::vector<NonnullExpr> &x, NonnullExpr y) {
    std::vector<NonnullExpr> v;
    v.reserve(x.size() + 1);
    for (size_t i = 0; i < x.size(); i++) {
        v.push_back(x[i]);
    }
    v.push_back(y);
    return v;
}
#define TUPLE_(x, y) TUPLE_APPEND(x, y)

#define RETURN_01(l) PYJU::Return::make_Return(arena, l, std::nullopt)
#define RETURN_02(e, l) PYJU::Return::make_Return(arena, l, e)


#define TUPLE_STMT(e, elts, l) PYJU::TupleStmt::make_TupleStmt(arena, l, TUPLE_(elts, e))

#define DELETE_01(e, l) PYJU::Delete::make_Delete(arena, l, e)

#define ASSIGNMENT(targets, val, l) PYJU::Assign::make_Assign(arena, l, targets, val)
// #define ASSIGNMENT2(targets, val, type_comment, l) PYJU::Assign::make_Assign(p.m_a, l, \
//         EXPRS(SET_EXPR_CTX_02(SET_STORE_02(targets), Store)), targets.size(), \
//         EXPR(val), extract_type_comment(p, l, type_comment))

#define OPERATOR(op, l) PYJU::operatorType::op
#define AUGASSIGN_01(x, op, y, l) PYJU::AugAssign::make_AugAssign(arena, l, x, op, y)

#define ANNASSIGN_01(x, y, l) PYJU::AnnAssign::make_AnnAssign(arena, l, x, y, std::nullopt)
#define ANNASSIGN_02(x, y, val, l) PYJU::AnnAssign::make_AnnAssign(arena, l, x, y, val)

#define FOR_01(target, iter, stmts, l) PYJU::For::make_For(arena, l,\
        target, iter, stmts, {})
#define FOR_02(target, iter, stmts, orelse, l) PYJU::For::make_For(arena, l,\
        target, iter, stmts, orelse)

#define WHILE_01(e, stmts, l) PYJU::While::make_While(arena, l, \
        e, stmts, {})
#define WHILE_02(e, stmts, orelse, l) PYJU::While::make_While(arena, l, \
        e, stmts, orelse)

#define EXCEPT_01(stmts, l) PYJU::ExceptHandler::make_ExceptHandler(arena, l, \
        std::nullopt, std::nullopt, stmts)
#define EXCEPT_02(e, stmts, l) PYJU::ExceptHandler::make_ExceptHandler(arena, l, \
        e, std::nullopt, stmts)
#define EXCEPT_03(e, id, stmts, l) PYJU::ExceptHandler::make_ExceptHandler(arena, l, \
        e, id, stmts)


#define TRY_01(stmts, except, l) PYJU::Try::make_Try(arena, l, stmts, except, {}, {})
#define TRY_02(stmts, except, orelse, l) PYJU::Try::make_Try(arena, l, stmts, except, orelse, {})
#define TRY_03(stmts, except, final, l) PYJU::Try::make_Try(arena, l, stmts, except, {}, final)
#define TRY_04(stmts, except, orelse, final, l) PYJU::Try::make_Try(arena, l, stmts, except, orelse, final)
#define TRY_05(stmts, final, l) PYJU::Try::make_Try(arena, l, stmts, {}, {}, final)


#define WITH_ITEM_01(expr, l) PYJU::WithItem::make_WithItem(arena, l, expr, std::nullopt)
#define WITH_ITEM_02(expr, vars, l) PYJU::WithItem::make_WithItem(arena, l, expr, vars)
#define WITH(items, body, l) PYJU::With::make_With(arena, l, items, body)


#define CLASS_01(decorator, id, stmts, l) PYJU::ClassDef::make_ClassDef(arena, l, \
        id, {}, {}, stmts, decorator)
#define CLASS_02(decorator, id, args, stmts, l) PYJU::ClassDef::make_ClassDef(arena, l, \
        id, args, {}, stmts, decorator)
#define CLASS_03(decorator, id, args, keywords, stmts, l) PYJU::ClassDef::make_ClassDef(arena, l, \
        id, args, keywords, stmts, decorator)
#define CLASS_04(decorator, id, keywords, stmts, l) PYJU::ClassDef::make_ClassDef(arena, l, \
        id, {}, keywords, stmts, decorator)

