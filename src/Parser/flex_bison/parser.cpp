// A Bison parser, made by GNU Bison 3.8.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 44 "parser.ypp"

  #include <algorithm>
  #include <cstdarg>
  #include <cstdio>
  #include <cstdlib>
  #include <vector>
  #include <utility>

  #include "base/check.h"
  #include "Parser/flex_bison/parser.h"
  #include "Parser/flex_bison/parse_and_lex_context.h"
  #include "llvm/ADT/StringExtras.h"
  #include "llvm/Support/raw_ostream.h"

#line 54 "./parser.cpp"




#include "parser.h"


// Unqualified %code blocks.
#line 77 "parser.ypp"

  void PYJU::Parser::error(const location_type&, const std::string& message) {
    context.RecordSyntaxError(message);
  }

#line 69 "./parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 21 "parser.ypp"
namespace  PYJU  {
#line 162 "./parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (PYJU::Nonnull<PYJU::Arena*> arena_yyarg, yyscan_t yyscanner_yyarg, ParseAndLexContext& context_yyarg, std::optional<PYJU::ASTPtr>* ast_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      arena (arena_yyarg),
      yyscanner (yyscanner_yyarg),
      context (context_yyarg),
      ast (ast_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.YY_MOVE_OR_COPY< Nonnull<Alias*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.YY_MOVE_OR_COPY< Nonnull<Arg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.YY_MOVE_OR_COPY< Nonnull<Arguments*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< Nonnull<FnArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.YY_MOVE_OR_COPY< Nonnull<Keyword*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.YY_MOVE_OR_COPY< Nonnull<Name*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.YY_MOVE_OR_COPY< Nonnull<NoPosOnlyArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.YY_MOVE_OR_COPY< Nonnull<StarArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.YY_MOVE_OR_COPY< Nonnull<Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict: // dict
        value.YY_MOVE_OR_COPY< PairNonnullExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Alias*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Keyword*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Statement*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.YY_MOVE_OR_COPY< std::vector<PairNonnullExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sep: // sep
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.move< Nonnull<Alias*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< Nonnull<Arg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.move< Nonnull<Arguments*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.move< Nonnull<Keyword*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< Nonnull<Name*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.move< Nonnull<NoPosOnlyArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.move< Nonnull<StarArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.move< Nonnull<Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict: // dict
        value.move< PairNonnullExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.move< std::vector<Nonnull<Alias*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.move< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.move< std::vector<Nonnull<Keyword*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.move< std::vector<Nonnull<Statement*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.move< std::vector<PairNonnullExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sep: // sep
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.copy< Nonnull<Alias*> > (that.value);
        break;

      case symbol_kind::S_parameter: // parameter
        value.copy< Nonnull<Arg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.copy< Nonnull<Arguments*> > (that.value);
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.copy< Nonnull<Expression*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< Nonnull<FnArg*> > (that.value);
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.copy< Nonnull<Keyword*> > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.copy< Nonnull<Name*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.copy< Nonnull<NoPosOnlyArg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.copy< Nonnull<StarArg*> > (that.value);
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.copy< Nonnull<Statement*> > (that.value);
        break;

      case symbol_kind::S_dict: // dict
        value.copy< PairNonnullExpr > (that.value);
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.copy< std::vector<Nonnull<Alias*>> > (that.value);
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.copy< std::vector<Nonnull<Arg*>> > (that.value);
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.copy< std::vector<Nonnull<Expression*>> > (that.value);
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.copy< std::vector<Nonnull<Keyword*>> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.copy< std::vector<Nonnull<Statement*>> > (that.value);
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.copy< std::vector<PairNonnullExpr> > (that.value);
        break;

      case symbol_kind::S_sep: // sep
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.move< Nonnull<Alias*> > (that.value);
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< Nonnull<Arg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.move< Nonnull<Arguments*> > (that.value);
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (that.value);
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.move< Nonnull<Keyword*> > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.move< Nonnull<Name*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.move< Nonnull<NoPosOnlyArg*> > (that.value);
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.move< Nonnull<StarArg*> > (that.value);
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        value.move< Nonnull<Statement*> > (that.value);
        break;

      case symbol_kind::S_dict: // dict
        value.move< PairNonnullExpr > (that.value);
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.move< double > (that.value);
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.move< std::vector<Nonnull<Alias*>> > (that.value);
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (that.value);
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.move< std::vector<Nonnull<Expression*>> > (that.value);
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.move< std::vector<Nonnull<Keyword*>> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        value.move< std::vector<Nonnull<Statement*>> > (that.value);
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.move< std::vector<PairNonnullExpr> > (that.value);
        break;

      case symbol_kind::S_sep: // sep
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (arena, yyscanner, context));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_module_as_id: // module_as_id
        yylhs.value.emplace< Nonnull<Alias*> > ();
        break;

      case symbol_kind::S_parameter: // parameter
        yylhs.value.emplace< Nonnull<Arg*> > ();
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        yylhs.value.emplace< Nonnull<Arguments*> > ();
        break;

      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Nonnull<Expression*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< Nonnull<FnArg*> > ();
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        yylhs.value.emplace< Nonnull<Keyword*> > ();
        break;

      case symbol_kind::S_id: // id
        yylhs.value.emplace< Nonnull<Name*> > ();
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        yylhs.value.emplace< Nonnull<NoPosOnlyArg*> > ();
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        yylhs.value.emplace< Nonnull<StarArg*> > ();
        break;

      case symbol_kind::S_script_unit: // script_unit
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_pass_statement: // pass_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_continue_statement: // continue_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
        yylhs.value.emplace< Nonnull<Statement*> > ();
        break;

      case symbol_kind::S_dict: // dict
        yylhs.value.emplace< PairNonnullExpr > ();
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        yylhs.value.emplace< std::vector<Nonnull<Alias*>> > ();
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        yylhs.value.emplace< std::vector<Nonnull<Arg*>> > ();
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        yylhs.value.emplace< std::vector<Nonnull<Expression*>> > ();
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        yylhs.value.emplace< std::vector<Nonnull<Keyword*>> > ();
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_sep_statements: // sep_statements
      case symbol_kind::S_body_stmts: // body_stmts
      case symbol_kind::S_statements1: // statements1
      case symbol_kind::S_single_line_statements: // single_line_statements
      case symbol_kind::S_single_line_multi_statements: // single_line_multi_statements
      case symbol_kind::S_single_line_multi_statements_opt: // single_line_multi_statements_opt
        yylhs.value.emplace< std::vector<Nonnull<Statement*>> > ();
        break;

      case symbol_kind::S_dict_list: // dict_list
        yylhs.value.emplace< std::vector<PairNonnullExpr> > ();
        break;

      case symbol_kind::S_sep: // sep
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // units: units script_unit
#line 265 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1134 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 266 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1140 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 271 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1146 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 275 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1152 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 279 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1158 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 283 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1164 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 284 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1170 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 288 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1176 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 289 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1182 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 293 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1188 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 294 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1194 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 295 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1200 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 296 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1208 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 299 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1216 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 302 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1224 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 308 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1232 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 311 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1240 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 317 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1248 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 320 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1256 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 326 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1262 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 327 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1268 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 328 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1274 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 333 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1280 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 337 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1286 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 341 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1292 "./parser.cpp"
    break;

  case 28: // single_line_statement: expression_statment
#line 345 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1298 "./parser.cpp"
    break;

  case 29: // single_line_statement: pass_statement
#line 350 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1304 "./parser.cpp"
    break;

  case 30: // single_line_statement: break_statement
#line 354 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1310 "./parser.cpp"
    break;

  case 31: // single_line_statement: continue_statement
#line 355 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1316 "./parser.cpp"
    break;

  case 32: // single_line_statement: import_statement
#line 356 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1322 "./parser.cpp"
    break;

  case 33: // single_line_statement: global_statement
#line 357 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1328 "./parser.cpp"
    break;

  case 34: // single_line_statement: nonlocal_statement
#line 358 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1334 "./parser.cpp"
    break;

  case 35: // module: module "." id
#line 363 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1340 "./parser.cpp"
    break;

  case 36: // module: id
#line 364 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1346 "./parser.cpp"
    break;

  case 37: // module_as_id: module
#line 368 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1352 "./parser.cpp"
    break;

  case 38: // module_as_id: module AS id
#line 369 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1358 "./parser.cpp"
    break;

  case 39: // module_as_id: "*"
#line 370 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1364 "./parser.cpp"
    break;

  case 40: // module_item_list: module_item_list "," module_as_id
#line 374 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1370 "./parser.cpp"
    break;

  case 41: // module_item_list: module_as_id
#line 375 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1376 "./parser.cpp"
    break;

  case 42: // dot_list: dot_list "."
#line 379 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1382 "./parser.cpp"
    break;

  case 43: // dot_list: "."
#line 380 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1388 "./parser.cpp"
    break;

  case 44: // import_statement: IMPORT module_item_list
#line 386 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1394 "./parser.cpp"
    break;

  case 45: // import_statement: FROM module IMPORT module_item_list
#line 387 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1401 "./parser.cpp"
    break;

  case 46: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 389 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1408 "./parser.cpp"
    break;

  case 47: // import_statement: FROM dot_list IMPORT module_item_list
#line 391 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1415 "./parser.cpp"
    break;

  case 48: // import_statement: FROM dot_list module IMPORT module_item_list
#line 393 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1422 "./parser.cpp"
    break;

  case 49: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 395 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1429 "./parser.cpp"
    break;

  case 50: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 397 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1436 "./parser.cpp"
    break;

  case 51: // multi_line_statement: if_statement
#line 402 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1442 "./parser.cpp"
    break;

  case 52: // multi_line_statement: function_def
#line 406 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1448 "./parser.cpp"
    break;

  case 53: // decorators_opt: decorators
#line 415 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1454 "./parser.cpp"
    break;

  case 54: // decorators_opt: %empty
#line 416 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1460 "./parser.cpp"
    break;

  case 55: // decorators: decorators "@" expr sep
#line 420 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1466 "./parser.cpp"
    break;

  case 56: // decorators: "@" expr sep
#line 421 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1472 "./parser.cpp"
    break;

  case 57: // parameter: id
#line 425 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1478 "./parser.cpp"
    break;

  case 58: // parameter: id ":" expr
#line 426 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1484 "./parser.cpp"
    break;

  case 59: // parameter: id "=" expr
#line 427 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1490 "./parser.cpp"
    break;

  case 60: // parameter: id ":" expr "=" expr
#line 428 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1496 "./parser.cpp"
    break;

  case 61: // parameter_list: defparameter_list "," "/" comma_opt
#line 432 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1503 "./parser.cpp"
    break;

  case 62: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 434 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1510 "./parser.cpp"
    break;

  case 63: // parameter_list: parameter_list_no_posonly
#line 436 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1516 "./parser.cpp"
    break;

  case 64: // parameter_list_no_posonly: defparameter_list comma_opt
#line 440 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1522 "./parser.cpp"
    break;

  case 65: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 441 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1529 "./parser.cpp"
    break;

  case 66: // parameter_list_no_posonly: parameter_list_starargs
#line 443 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1535 "./parser.cpp"
    break;

  case 67: // defparameter_list: defparameter_list "," parameter
#line 447 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1541 "./parser.cpp"
    break;

  case 68: // defparameter_list: parameter
#line 448 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1547 "./parser.cpp"
    break;

  case 69: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 456 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1553 "./parser.cpp"
    break;

  case 70: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 457 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1559 "./parser.cpp"
    break;

  case 71: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 458 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1566 "./parser.cpp"
    break;

  case 72: // parameter_list_starargs: "*" parameter comma_opt
#line 460 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1572 "./parser.cpp"
    break;

  case 73: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 461 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1579 "./parser.cpp"
    break;

  case 74: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 463 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1586 "./parser.cpp"
    break;

  case 75: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 465 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1593 "./parser.cpp"
    break;

  case 76: // parameter_list_starargs: "**" parameter comma_opt
#line 467 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1599 "./parser.cpp"
    break;

  case 77: // parameter_list_opt: parameter_list
#line 471 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1605 "./parser.cpp"
    break;

  case 78: // parameter_list_opt: %empty
#line 472 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1611 "./parser.cpp"
    break;

  case 81: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 482 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1617 "./parser.cpp"
    break;

  case 82: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 484 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1623 "./parser.cpp"
    break;

  case 83: // global_statement: GLOBAL expr_list
#line 494 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1629 "./parser.cpp"
    break;

  case 84: // ternary_if_statement: expr IF expr ELSE expr
#line 498 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1635 "./parser.cpp"
    break;

  case 85: // nonlocal_statement: NONLOCAL expr_list
#line 502 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1641 "./parser.cpp"
    break;

  case 86: // if_statement: IF expr ":" body_stmts
#line 506 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1649 "./parser.cpp"
    break;

  case 87: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 509 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1657 "./parser.cpp"
    break;

  case 88: // expression_statment: expr
#line 517 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1663 "./parser.cpp"
    break;

  case 89: // string: string string_literal
#line 521 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1669 "./parser.cpp"
    break;

  case 90: // string: string_literal
#line 522 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1677 "./parser.cpp"
    break;

  case 91: // string: id string_literal
#line 525 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1685 "./parser.cpp"
    break;

  case 92: // string: string id string_literal
#line 528 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1693 "./parser.cpp"
    break;

  case 93: // expr_list_opt: expr_list
#line 534 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1699 "./parser.cpp"
    break;

  case 94: // expr_list_opt: %empty
#line 535 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1705 "./parser.cpp"
    break;

  case 95: // expr_list: expr_list "," expr
#line 539 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1711 "./parser.cpp"
    break;

  case 96: // expr_list: expr
#line 540 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1717 "./parser.cpp"
    break;

  case 97: // dict: expr ":" expr
#line 550 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1723 "./parser.cpp"
    break;

  case 98: // dict_list: dict_list "," dict
#line 554 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1729 "./parser.cpp"
    break;

  case 99: // dict_list: dict
#line 555 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1735 "./parser.cpp"
    break;

  case 100: // call_arguement_list: expr_list_opt
#line 559 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1741 "./parser.cpp"
    break;

  case 101: // call_arguement_list: expr_list ","
#line 560 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1747 "./parser.cpp"
    break;

  case 102: // keyword_item: id "=" expr
#line 565 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1753 "./parser.cpp"
    break;

  case 103: // keyword_item: "**" expr
#line 566 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1759 "./parser.cpp"
    break;

  case 104: // keyword_items: keyword_items "," keyword_item
#line 570 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1765 "./parser.cpp"
    break;

  case 105: // keyword_items: keyword_item
#line 571 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1771 "./parser.cpp"
    break;

  case 106: // primary: id
#line 576 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1777 "./parser.cpp"
    break;

  case 107: // primary: string
#line 577 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1783 "./parser.cpp"
    break;

  case 108: // primary: expr "." id
#line 578 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1789 "./parser.cpp"
    break;

  case 109: // function_call: primary "(" call_arguement_list ")"
#line 582 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1795 "./parser.cpp"
    break;

  case 110: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 583 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1802 "./parser.cpp"
    break;

  case 111: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 585 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1809 "./parser.cpp"
    break;

  case 112: // function_call: primary "(" keyword_items comma_opt ")"
#line 587 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1815 "./parser.cpp"
    break;

  case 113: // function_call: function_call "(" call_arguement_list ")"
#line 588 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1821 "./parser.cpp"
    break;

  case 114: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 589 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1828 "./parser.cpp"
    break;

  case 115: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 591 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1835 "./parser.cpp"
    break;

  case 116: // function_call: function_call "(" keyword_items comma_opt ")"
#line 593 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1841 "./parser.cpp"
    break;

  case 117: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 600 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1847 "./parser.cpp"
    break;

  case 118: // expr: id
#line 604 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1853 "./parser.cpp"
    break;

  case 119: // expr: integer_literal
#line 605 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1862 "./parser.cpp"
    break;

  case 120: // expr: string
#line 609 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1868 "./parser.cpp"
    break;

  case 121: // expr: real_literal
#line 610 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1874 "./parser.cpp"
    break;

  case 122: // expr: image_literal
#line 611 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 1883 "./parser.cpp"
    break;

  case 123: // expr: TRUE
#line 615 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 1889 "./parser.cpp"
    break;

  case 124: // expr: FALSE
#line 616 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 1895 "./parser.cpp"
    break;

  case 125: // expr: NONE
#line 617 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 1901 "./parser.cpp"
    break;

  case 126: // expr: "..."
#line 618 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 1907 "./parser.cpp"
    break;

  case 127: // expr: "(" expr ")"
#line 619 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 1913 "./parser.cpp"
    break;

  case 128: // expr: "(" ")"
#line 620 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 1919 "./parser.cpp"
    break;

  case 129: // expr: function_call
#line 621 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1925 "./parser.cpp"
    break;

  case 130: // expr: "[" expr_list_opt "]"
#line 623 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1931 "./parser.cpp"
    break;

  case 131: // expr: "[" expr_list "," "]"
#line 624 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1937 "./parser.cpp"
    break;

  case 132: // expr: "{" expr_list "}"
#line 625 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1943 "./parser.cpp"
    break;

  case 133: // expr: "{" expr_list "," "}"
#line 626 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1949 "./parser.cpp"
    break;

  case 134: // expr: expr "." id
#line 627 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1955 "./parser.cpp"
    break;

  case 135: // expr: "{" "}"
#line 629 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 1961 "./parser.cpp"
    break;

  case 136: // expr: "{" dict_list "}"
#line 630 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 1967 "./parser.cpp"
    break;

  case 137: // expr: id ":=" expr
#line 634 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1973 "./parser.cpp"
    break;

  case 138: // expr: "*" expr
#line 635 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1979 "./parser.cpp"
    break;

  case 139: // expr: expr "+" expr
#line 637 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1985 "./parser.cpp"
    break;

  case 140: // expr: expr "-" expr
#line 638 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1991 "./parser.cpp"
    break;

  case 141: // expr: expr "*" expr
#line 639 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1997 "./parser.cpp"
    break;

  case 142: // expr: expr "/" expr
#line 640 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2003 "./parser.cpp"
    break;

  case 143: // expr: expr "%" expr
#line 641 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2009 "./parser.cpp"
    break;

  case 144: // expr: "-" expr
#line 642 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2015 "./parser.cpp"
    break;

  case 145: // expr: "+" expr
#line 643 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2021 "./parser.cpp"
    break;

  case 146: // expr: "~" expr
#line 644 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2027 "./parser.cpp"
    break;

  case 147: // expr: expr "**" expr
#line 645 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2033 "./parser.cpp"
    break;

  case 148: // expr: expr "//" expr
#line 646 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2039 "./parser.cpp"
    break;

  case 149: // expr: expr "@" expr
#line 647 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2045 "./parser.cpp"
    break;

  case 150: // expr: expr "&" expr
#line 649 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2051 "./parser.cpp"
    break;

  case 151: // expr: expr "|" expr
#line 650 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2057 "./parser.cpp"
    break;

  case 152: // expr: expr "^" expr
#line 651 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2063 "./parser.cpp"
    break;

  case 153: // expr: expr "<<" expr
#line 652 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2069 "./parser.cpp"
    break;

  case 154: // expr: expr ">>" expr
#line 653 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2075 "./parser.cpp"
    break;

  case 155: // expr: expr "==" expr
#line 655 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2081 "./parser.cpp"
    break;

  case 156: // expr: expr "!=" expr
#line 656 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2087 "./parser.cpp"
    break;

  case 157: // expr: expr "<" expr
#line 657 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2093 "./parser.cpp"
    break;

  case 158: // expr: expr "<=" expr
#line 658 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2099 "./parser.cpp"
    break;

  case 159: // expr: expr ">" expr
#line 659 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2105 "./parser.cpp"
    break;

  case 160: // expr: expr ">=" expr
#line 660 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2111 "./parser.cpp"
    break;

  case 161: // expr: expr "is" expr
#line 661 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2117 "./parser.cpp"
    break;

  case 162: // expr: expr "is not" expr
#line 662 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2123 "./parser.cpp"
    break;

  case 163: // expr: expr "in" expr
#line 663 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2129 "./parser.cpp"
    break;

  case 164: // expr: expr "not in" expr
#line 664 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2135 "./parser.cpp"
    break;

  case 165: // expr: expr "and" expr
#line 666 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2141 "./parser.cpp"
    break;

  case 166: // expr: expr "or" expr
#line 667 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2147 "./parser.cpp"
    break;

  case 167: // expr: "not" expr
#line 668 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2153 "./parser.cpp"
    break;

  case 168: // expr: ternary_if_statement
#line 675 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2159 "./parser.cpp"
    break;

  case 169: // id: identifier
#line 680 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2165 "./parser.cpp"
    break;

  case 170: // sep: sep sep_one
#line 684 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2171 "./parser.cpp"
    break;

  case 171: // sep: sep_one
#line 685 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2177 "./parser.cpp"
    break;

  case 172: // sep_one: NEWLINE
#line 689 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2183 "./parser.cpp"
    break;

  case 173: // sep_one: COMMENT
#line 690 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2189 "./parser.cpp"
    break;

  case 174: // sep_one: ";"
#line 691 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2195 "./parser.cpp"
    break;


#line 2199 "./parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short  Parser ::yypact_ninf_ = -253;

  const signed char  Parser ::yytable_ninf_ = -109;

  const short
   Parser ::yypact_[] =
  {
     405,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,    57,  1424,  1424,    29,  1424,  1424,  -253,  1186,  1151,
    1424,  1424,  1424,  1424,  1424,  1424,  -253,  -253,  -253,  -253,
    1113,  -253,  -253,  -253,  -253,  -253,   159,  -253,   159,    27,
     -37,  -253,  -253,  -253,  -253,  -253,  -253,   123,    -7,     4,
     943,   132,   159,  -253,  -253,    -2,    11,  -253,    36,   943,
     664,  -253,     3,  -253,    69,    36,  1441,  -253,   -25,  -253,
      92,   709,  -253,   754,    43,    91,   -35,   -35,   -35,   602,
     -35,  -253,  -253,   159,   159,   148,  1424,  -253,   154,  1389,
    1389,  1424,  1424,  1424,  1424,  1424,  1424,  1424,  1424,  1424,
    1424,  1424,   148,  1424,  1424,  1424,  1424,  1424,  1424,  1424,
    1424,  1424,  1424,  1424,  1424,  1424,  1424,  1424,  -253,  1424,
    -253,    95,   148,    96,  -253,     2,  1424,   491,   148,    29,
    1225,  -253,  1424,  -253,  1424,   105,  -253,    89,   159,   112,
     602,  -253,  1424,  -253,   125,    97,  -253,   127,    81,   128,
     100,   130,  1441,   808,   337,   337,   337,   337,  1031,   217,
    1269,   337,   166,   133,   166,   -35,   -35,   -35,   -35,   -35,
     548,   153,   153,   337,   337,   337,   337,   -35,   337,   987,
      29,    69,  -253,    29,    69,   126,   943,  -253,   158,  -253,
     -48,  1351,   170,   157,  -253,  -253,  -253,  -253,   709,   943,
    1424,  -253,    23,   159,   943,  1389,  -253,  1389,   114,  1424,
    1389,  -253,  1389,   116,  1424,   145,   145,    29,    69,   155,
    -253,   115,   129,   -27,  -253,   120,  1284,  -253,   160,   131,
     152,   148,  -253,  -253,  -253,   171,  -253,   147,    -9,   174,
     182,  -253,  -253,   943,   174,   182,  -253,   987,    29,   163,
     172,   145,   491,  -253,    53,  -253,   150,  -253,   563,  -253,
    1424,  -253,     6,   200,   202,    45,  -253,   -26,  1424,  1424,
      34,   177,  1424,   186,   195,   197,  -253,  -253,   207,  -253,
    -253,  -253,  -253,   148,   234,    42,  -253,  -253,  -253,   237,
    -253,  -253,   491,  1424,   853,   943,   236,  -253,  -253,  -253,
    -253,  -253,   202,    46,  -253,   148,   239,    23,  -253,  -253,
     898,  1424,  -253,   148,   202,    47,  -253,  -253,   240,   491,
     943,   202,  -253,   148,    23,  -253,  -253,   202,  -253
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      54,   119,   121,   122,   169,    90,   124,   123,   125,    26,
      27,     0,     0,     0,     0,     0,     0,    25,     0,     0,
      94,     0,     0,     0,     0,     0,   126,   174,   172,   173,
      54,     3,     5,    29,    30,    31,     0,    32,    23,     0,
      53,    52,    33,   168,    34,    51,    28,   120,     0,   129,
      88,   118,     4,   171,    43,     0,     0,    36,    83,    96,
       0,    39,    37,    41,    44,    85,   167,   135,     0,    99,
       0,    96,   128,     0,     0,    93,   144,   145,   138,     0,
     146,     1,     2,    22,    24,     0,     0,    89,     0,    94,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
     170,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   132,     0,   136,     0,   127,   130,     0,    56,     0,
       0,    92,     0,   100,    93,     0,   105,    80,   118,    93,
       0,    80,   165,     0,   163,   161,   162,   164,   166,   150,
     152,   155,   140,   134,   139,   141,   147,   149,   148,   143,
     151,   153,   154,   157,   158,   159,   160,   142,   156,   137,
       0,    45,    35,     0,    47,     0,    95,     9,    86,     8,
       0,     0,     0,     0,    38,    40,   133,    98,     0,    97,
      94,   131,    78,    55,   103,   101,   109,    79,     0,     0,
     101,   113,    79,     0,     0,    80,    80,     0,    48,     0,
      12,     0,    18,    21,    14,     0,    54,     7,    93,     0,
       0,     0,    68,    77,    63,    80,    66,     0,    57,    80,
      80,   104,   112,   102,    80,    80,   116,    84,    79,     0,
       0,    80,     0,    13,    20,    15,     0,    17,    54,    11,
     101,   117,     0,    80,    80,    79,    64,     0,     0,     0,
      79,     0,    79,     0,     0,     0,    46,    49,     0,    87,
      16,     6,    10,     0,    80,    79,    72,    79,    76,    80,
      67,    65,     0,     0,    58,    59,     0,   110,   111,   114,
     115,    50,    80,    79,    69,     0,    80,    79,    61,    81,
       0,     0,    70,     0,    80,    79,    73,    62,    80,     0,
      60,    80,    74,     0,    79,    82,    71,    80,    75
  };

  const short
   Parser ::yypgoto_[] =
  {
    -253,  -253,   261,  -253,  -253,  -238,  -253,  -253,  -253,  -253,
    -203,  -253,  -253,  -253,  -122,    10,  -120,  -103,  -253,  -253,
    -253,  -253,  -253,  -200,  -253,   -12,  -243,  -252,  -253,   -80,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,   273,   -14,   167,
    -253,   -79,  -197,   -83,  -253,  -253,   245,   -11,     8,   -50
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    30,    31,   227,   187,   188,   258,   189,   190,   191,
      32,    33,    34,    35,    36,    62,    63,    64,    56,    37,
      38,    39,    40,   232,   233,   234,   235,   236,   237,   266,
      41,    42,    43,    44,    45,    46,    47,   143,    58,    69,
      70,   145,   146,   147,    48,    49,    50,    51,   193,    53
  };

  const short
   Parser ::yytable_[] =
  {
      57,    65,   120,    57,    68,   192,    75,   151,    52,   195,
     241,   150,     4,   291,   279,   241,   128,     4,   181,   284,
     184,    55,   292,   259,   102,   130,    86,   105,   121,     4,
     263,   264,   185,   120,   120,     4,    88,   220,   221,   268,
       4,   123,   306,   269,    83,    57,    84,    85,     4,    89,
     131,     4,     4,     4,   309,   282,   293,   122,   255,   256,
      90,   122,   122,     4,   318,   290,   125,   208,   283,   222,
     124,   213,   291,   241,   139,   144,   149,   215,   148,   148,
     216,   325,   218,   302,   230,   231,   126,   138,   120,   118,
      61,   163,     1,     2,     3,     4,   142,     5,     6,     7,
       8,     4,     4,   290,   305,   314,   230,   231,   313,   323,
      57,   182,    57,   321,   251,   290,    54,   194,    57,   129,
     136,   229,   239,   327,   290,   289,    16,   244,   195,     4,
     192,    87,     4,   209,   119,   249,   250,  -106,   -19,   -19,
     118,   137,   132,   120,    18,    19,    20,    21,   203,    22,
      23,   180,   183,   120,     4,    25,    61,    61,     4,   271,
     273,   200,   141,    26,   274,   275,   201,   133,   202,    57,
     192,   278,    57,   206,    57,   205,   211,   207,   210,  -107,
     212,   219,   217,   286,   288,   119,   228,    61,  -106,  -108,
     242,   238,   246,   240,   148,   248,   148,   192,   245,   148,
     253,   148,   262,   252,   304,   257,    57,   261,   254,   308,
     260,   101,   102,   103,   104,   105,   106,   107,   108,   238,
     238,   265,   312,   267,   270,   102,   316,   104,   105,   106,
     107,   108,   272,   116,   322,   280,    27,    57,    27,   276,
     226,   326,    28,    29,    28,    29,   116,   328,   277,   223,
     285,   238,   287,   297,   238,   224,   225,    59,    60,   296,
      59,    66,   298,    71,    73,    59,    76,    77,    78,    79,
      80,   299,   238,   300,   238,   101,   102,   103,   104,   105,
     106,   107,   108,   301,   303,   110,   111,   307,   209,   315,
     324,    82,   238,    74,   238,   317,   238,   116,     0,   197,
       0,     0,   238,     0,   238,     0,     0,     0,     0,     0,
       0,     0,   238,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,    59,    59,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,     0,   179,     0,     0,     0,     0,     0,
       0,   186,     0,     0,     0,   186,     0,   198,     0,   199,
       0,     0,   186,    98,    99,     0,     0,   204,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,     0,   109,   110,   111,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,   116,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     0,     0,     0,     0,
       0,    15,    16,     0,    17,    59,     0,     0,     0,     0,
     186,     0,    59,     0,   243,   186,     0,    59,     0,   247,
      18,    19,    20,    21,     0,    22,    23,     0,    24,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      28,    29,     0,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,   186,     0,     0,     9,     0,
      10,     0,     0,   294,   295,     0,     0,   186,    11,    12,
       0,    14,     0,     0,     0,     0,     0,    15,    16,     0,
      17,     0,     0,     0,     0,     0,     0,     0,   310,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
       0,    22,    23,     0,     0,     0,   320,    25,     0,     0,
       0,     0,     0,     0,     0,    26,     1,     2,     3,     4,
      27,     5,     6,     7,     8,     0,    28,    29,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    98,    99,     0,     0,     0,    15,
      16,     0,    17,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,    91,     0,   110,   111,    18,    19,
      20,    21,     0,    22,    23,     0,    24,     0,   116,    25,
       0,    92,     0,    93,    94,    95,    96,    26,     0,     0,
      97,     0,     0,     0,     0,     0,     0,   281,    98,    99,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,     0,   109,
     110,   111,   112,   113,   114,   115,    91,     0,     0,     0,
       0,    27,   116,     0,     0,     0,     0,    28,    29,     0,
       0,   117,     0,    92,     0,    93,    94,    95,    96,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   127,     0,     0,     0,     0,     0,   100,     0,
       0,    91,   101,   102,   103,   104,   105,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,    92,     0,
      93,    94,    95,    96,   116,     0,     0,    97,     0,     0,
       0,     0,     0,   117,     0,    98,    99,   134,     0,     0,
       0,     0,     0,   100,     0,     0,    91,   101,   102,   103,
     104,   105,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,   115,    92,     0,    93,    94,    95,    96,   116,
       0,     0,    97,     0,     0,     0,     0,     0,   117,     0,
      98,    99,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
      91,   109,   110,   111,   112,   113,   114,   115,     0,     0,
     135,   214,     0,     0,   116,     0,     0,    92,     0,    93,
      94,    95,    96,   117,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,     0,     0,
       0,     0,   100,     0,     0,    91,   101,   102,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,    92,     0,    93,    94,    95,    96,   116,     0,
       0,    97,     0,     0,     0,     0,     0,   117,     0,    98,
      99,     0,     0,     0,     0,   311,     0,   100,     0,     0,
      91,   101,   102,   103,   104,   105,   106,   107,   108,     0,
     109,   110,   111,   112,   113,   114,   115,    92,     0,    93,
      94,    95,    96,   116,     0,     0,    97,     0,     0,     0,
       0,     0,   117,     0,    98,    99,   319,     0,     0,     0,
       0,     0,   100,     0,     0,    91,   101,   102,   103,   104,
     105,   106,   107,   108,     0,   109,   110,   111,   112,   113,
     114,   115,    92,     0,    93,    94,    95,    96,   116,     0,
       0,    97,     0,     0,     0,     0,     0,   117,     0,    98,
      99,     0,     0,     0,     0,     0,     0,   100,     0,    91,
       0,   101,   102,   103,   104,   105,   106,   107,   108,     0,
     109,   110,   111,   112,   113,   114,   115,     0,    93,    94,
      95,    96,     0,   116,     0,    97,     0,     0,     0,     0,
       0,     0,   117,    98,    99,     0,     0,     0,     0,     0,
       0,   100,     0,    91,     0,   101,   102,   103,   104,   105,
     106,   107,   108,     0,   109,   110,   111,   112,   113,   114,
     115,     0,    93,    94,    95,    96,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,   117,    98,    99,     0,
       0,     0,     0,     0,     0,   100,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,     0,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,   116,     0,    81,     0,     0,     1,     2,     3,     4,
     117,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,     0,     0,     0,     0,     0,    15,
      16,     0,    17,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     0,    18,    19,
      20,    21,     0,    22,    23,     0,    24,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    26,    16,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
       0,    22,    23,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    16,     0,    26,     0,    72,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,    18,    19,    20,    21,     0,    22,    23,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      26,    67,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,     0,    22,    23,     1,     2,     3,
       4,    25,     5,     6,     7,     8,     0,     0,     0,    26,
     196,     9,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    98,     0,     0,     0,     0,
      15,    16,     0,    17,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,   110,   111,    18,
      19,    20,    21,     0,    22,    23,     0,    24,     0,   116,
      25,     0,     0,     0,     1,     2,     3,     4,    26,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,    14,     0,     0,     0,     0,     0,    15,    16,     0,
      17,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,    18,    19,    20,    21,
       0,    22,    23,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    26,    16,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,     0,    22,
      23,   142,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    16,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,     0,     0,    18,
      19,    20,    21,     0,    22,    23,     0,    98,    99,     0,
      25,     0,     0,     0,     0,   100,     0,     0,    26,   101,
     102,   103,   104,   105,   106,   107,   108,     0,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
     117
  };

  const short
   Parser ::yycheck_[] =
  {
      11,    15,    52,    14,    18,   127,    20,    90,     0,   129,
     207,    90,     6,   265,   252,   212,    13,     6,   121,   262,
     123,    11,    48,   226,    59,    50,    63,    62,    30,     6,
     230,   231,    30,    83,    84,     6,    47,    85,    86,    48,
       6,    30,   285,    52,    36,    56,    38,    20,     6,    56,
      75,     6,     6,     6,   292,   258,    82,    59,    85,    86,
      56,    59,    59,     6,   307,   265,    56,   147,    62,   191,
      59,   151,   324,   270,    85,    89,    90,   180,    89,    90,
     183,   319,   185,   283,    61,    62,    50,    79,   138,     8,
      61,   102,     3,     4,     5,     6,    62,     8,     9,    10,
      11,     6,     6,   303,    62,   305,    61,    62,    62,    62,
     121,   122,   123,   313,   217,   315,    59,   128,   129,    50,
      77,   200,   205,   323,   324,    80,    37,   210,   248,     6,
     252,     8,     6,    52,    53,   215,   216,    56,    85,    86,
       8,    50,    50,   193,    55,    56,    57,    58,   140,    60,
      61,    56,    56,   203,     6,    66,    61,    61,     6,   239,
     240,    56,     8,    74,   244,   245,    77,    75,    56,   180,
     292,   251,   183,    76,   185,    50,    76,    50,    50,    56,
      50,    23,    56,   263,   264,    53,   200,    61,    56,    56,
      76,   202,    76,   207,   205,    50,   207,   319,   212,   210,
      85,   212,    50,    48,   284,    85,   217,    76,    79,   289,
      50,    58,    59,    60,    61,    62,    63,    64,    65,   230,
     231,    50,   302,    76,    50,    59,   306,    61,    62,    63,
      64,    65,    50,    80,   314,    85,    79,   248,    79,    76,
      83,   321,    85,    86,    85,    86,    80,   327,    76,    79,
      50,   262,    50,    76,   265,    85,    86,    12,    13,   270,
      15,    16,    76,    18,    19,    20,    21,    22,    23,    24,
      25,    76,   283,    76,   285,    58,    59,    60,    61,    62,
      63,    64,    65,    76,    50,    68,    69,    50,    52,    50,
      50,    30,   303,    20,   305,   307,   307,    80,    -1,   132,
      -1,    -1,   313,    -1,   315,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   323,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,   130,    -1,   132,    -1,   134,
      -1,    -1,   137,    46,    47,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    80,    -1,    -1,
      -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    39,   200,    -1,    -1,    -1,    -1,
     205,    -1,   207,    -1,   209,   210,    -1,   212,    -1,   214,
      55,    56,    57,    58,    -1,    60,    61,    -1,    63,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,   260,    -1,    -1,    17,    -1,
      19,    -1,    -1,   268,   269,    -1,    -1,   272,    27,    28,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,   311,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,     3,     4,     5,     6,
      79,     8,     9,    10,    11,    -1,    85,    86,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    46,    47,    -1,    -1,    -1,    36,
      37,    -1,    39,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    12,    -1,    68,    69,    55,    56,
      57,    58,    -1,    60,    61,    -1,    63,    -1,    80,    66,
      -1,    29,    -1,    31,    32,    33,    34,    74,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    84,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    12,    -1,    -1,    -1,
      -1,    79,    80,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    89,    -1,    29,    -1,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    12,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    71,    72,    73,    29,    -1,
      31,    32,    33,    34,    80,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    12,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    29,    -1,    31,    32,    33,    34,    80,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      12,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    23,    -1,    -1,    80,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    89,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    12,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    29,    -1,    31,    32,    33,    34,    80,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    89,    -1,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    -1,
      12,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    29,    -1,    31,
      32,    33,    34,    80,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    12,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    29,    -1,    31,    32,    33,    34,    80,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    89,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    12,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    31,    32,
      33,    34,    -1,    80,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    12,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    31,    32,    33,    34,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,     0,    -1,    -1,     3,     4,     5,     6,
      89,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    39,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    60,    61,    -1,    63,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    37,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    74,    -1,    76,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    60,    61,     3,     4,     5,
       6,    66,     8,     9,    10,    11,    -1,    -1,    -1,    74,
      75,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    46,    -1,    -1,    -1,    -1,
      36,    37,    -1,    39,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    -1,    68,    69,    55,
      56,    57,    58,    -1,    60,    61,    -1,    63,    -1,    80,
      66,    -1,    -1,    -1,     3,     4,     5,     6,    74,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      39,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    37,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      61,    62,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    61,    -1,    46,    47,    -1,
      66,    -1,    -1,    -1,    -1,    54,    -1,    -1,    74,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    17,
      19,    27,    28,    29,    30,    36,    37,    39,    55,    56,
      57,    58,    60,    61,    63,    66,    74,    79,    85,    86,
      92,    93,   101,   102,   103,   104,   105,   110,   111,   112,
     113,   121,   122,   123,   124,   125,   126,   127,   135,   136,
     137,   138,   139,   140,    59,   106,   109,   138,   129,   137,
     137,    61,   106,   107,   108,   129,   137,    75,   129,   130,
     131,   137,    76,   137,   128,   129,   137,   137,   137,   137,
     137,     0,    93,   139,   139,    20,    63,     8,   138,    56,
      56,    12,    29,    31,    32,    33,    34,    38,    46,    47,
      54,    58,    59,    60,    61,    62,    63,    64,    65,    67,
      68,    69,    70,    71,    72,    73,    80,    89,     8,    53,
     140,    30,    59,    30,    59,   106,    50,    48,    13,    50,
      50,    75,    50,    75,    48,    76,    77,    50,   139,   138,
     137,     8,    62,   128,   129,   132,   133,   134,   138,   129,
     132,   134,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   138,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
      56,   108,   138,    56,   108,    30,   137,    95,    96,    98,
      99,   100,   105,   139,   138,   107,    75,   130,   137,   137,
      56,    77,    56,   139,   137,    50,    76,    50,   120,    52,
      50,    76,    50,   120,    23,   108,   108,    56,   108,    23,
      85,    86,   105,    79,    85,    86,    83,    94,   129,   132,
      61,    62,   114,   115,   116,   117,   118,   119,   138,   134,
     129,   133,    76,   137,   134,   129,    76,   137,    50,   120,
     120,   108,    48,    85,    79,    85,    86,    85,    97,   101,
      50,    76,    50,   114,   114,    50,   120,    76,    48,    52,
      50,   120,    50,   120,   120,   120,    76,    76,   120,    96,
      85,    84,   101,    62,   117,    50,   120,    50,   120,    80,
     114,   118,    48,    82,   137,   137,   138,    76,    76,    76,
      76,    76,   114,    50,   120,    62,   117,    50,   120,    96,
     137,    52,   120,    62,   114,    50,   120,   116,   117,    48,
     137,   114,   120,    62,    50,    96,   120,   114,   120
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    91,    92,    92,    92,    93,    94,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   103,   104,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     114,   115,   115,   115,   116,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   123,   124,   125,   125,   126,   127,
     127,   127,   127,   128,   128,   129,   129,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     139,   139,   140,   140,   140
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     2,     1,     2,     4,     7,     4,     5,     7,
       8,     1,     1,     1,     0,     4,     3,     1,     3,     3,
       5,     4,     5,     1,     2,     3,     1,     3,     1,     4,
       5,     7,     3,     5,     6,     8,     3,     1,     0,     1,
       0,     8,    10,     2,     5,     2,     4,     7,     1,     2,
       1,     2,     3,     1,     0,     3,     1,     3,     3,     1,
       1,     2,     3,     2,     3,     1,     1,     1,     3,     4,
       7,     7,     5,     4,     7,     7,     5,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     4,     3,     4,     3,     2,     3,     3,     2,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       2,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "END_OF_FILE", "error", "\"invalid token\"", "integer_literal",
  "real_literal", "image_literal", "identifier", "sized_type_literal",
  "string_literal", "FALSE", "TRUE", "NONE", "\"and\"", "AS", "ASSERT",
  "ASYNC", "AWAIT", "BREAK", "CLASS", "CONTINUE", "DEF", "DEL", "ELIF",
  "ELSE", "EXCEPT", "FINALLY", "FOR", "FROM", "GLOBAL", "IF", "IMPORT",
  "\"in\"", "\"is\"", "\"is not\"", "\"not in\"", "LAMBDA", "NONLOCAL",
  "\"not\"", "\"or\"", "PASS", "RETURN", "TRY", "WHILE", "WITH", "YIELD",
  "ARROW", "\"&\"", "\"^\"", "\":\"", "\":!\"", "\",\"", "\"=>\"", "\"=\"",
  "\":=\"", "\"==\"", "\"{\"", "\"(\"", "\"[\"", "\"-\"", "\".\"", "\"+\"",
  "\"*\"", "\"**\"", "\"@\"", "\"//\"", "\"%\"", "\"~\"", "\"|\"",
  "\"<<\"", "\">>\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\"...\"",
  "\"}\"", "\")\"", "\"]\"", "\"self\"", "\";\"", "\"/\"", "\"_\"",
  "\"->\"", "INDENT", "DEDENT", "NEWLINE", "COMMENT", "EOLCOMMENT",
  "TYPE_COMMENT", "\"!=\"", "UNARY", "$accept", "units", "script_unit",
  "statements", "sep_statements", "body_stmts", "statements1",
  "single_line_statements", "single_line_multi_statements",
  "single_line_multi_statements_opt", "statement", "pass_statement",
  "break_statement", "continue_statement", "single_line_statement",
  "module", "module_as_id", "module_item_list", "dot_list",
  "import_statement", "multi_line_statement", "decorators_opt",
  "decorators", "parameter", "parameter_list", "parameter_list_no_posonly",
  "defparameter_list", "parameter_list_starargs", "parameter_list_opt",
  "comma_opt", "function_def", "global_statement", "ternary_if_statement",
  "nonlocal_statement", "if_statement", "expression_statment", "string",
  "expr_list_opt", "expr_list", "dict", "dict_list", "call_arguement_list",
  "keyword_item", "keyword_items", "primary", "function_call", "expr",
  "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   265,   265,   266,   267,   271,   275,   279,   283,   284,
     288,   289,   293,   294,   295,   296,   299,   302,   308,   311,
     317,   320,   326,   327,   328,   333,   337,   341,   345,   350,
     354,   355,   356,   357,   358,   363,   364,   368,   369,   370,
     374,   375,   379,   380,   386,   387,   389,   391,   393,   395,
     397,   402,   406,   415,   416,   420,   421,   425,   426,   427,
     428,   432,   434,   436,   440,   441,   443,   447,   448,   456,
     457,   458,   460,   461,   463,   465,   467,   471,   472,   476,
     477,   481,   483,   494,   498,   502,   506,   509,   517,   521,
     522,   525,   528,   534,   535,   539,   540,   550,   554,   555,
     559,   560,   565,   566,   570,   571,   576,   577,   578,   582,
     583,   585,   587,   588,   589,   591,   593,   600,   604,   605,
     609,   610,   611,   615,   616,   617,   618,   619,   620,   621,
     623,   624,   625,   626,   627,   629,   630,   634,   635,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     649,   650,   651,   652,   653,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   666,   667,   668,   675,   680,
     684,   685,   689,   690,   691
  };

  void
   Parser ::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
   Parser ::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 21 "parser.ypp"
} //  PYJU 
#line 2986 "./parser.cpp"

#line 694 "parser.ypp"
