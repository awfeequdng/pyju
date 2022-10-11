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

      case symbol_kind::S_tuple_item: // tuple_item
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
      case symbol_kind::S_assert_statement: // assert_statement
      case symbol_kind::S_raise_statement: // raise_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_elif_statement: // elif_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
      case symbol_kind::S_tuple_statement: // tuple_statement
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

      case symbol_kind::S_tuple_item: // tuple_item
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
      case symbol_kind::S_assert_statement: // assert_statement
      case symbol_kind::S_raise_statement: // raise_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_elif_statement: // elif_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
      case symbol_kind::S_tuple_statement: // tuple_statement
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

      case symbol_kind::S_tuple_item: // tuple_item
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
      case symbol_kind::S_assert_statement: // assert_statement
      case symbol_kind::S_raise_statement: // raise_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_elif_statement: // elif_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
      case symbol_kind::S_tuple_statement: // tuple_statement
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

      case symbol_kind::S_tuple_item: // tuple_item
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
      case symbol_kind::S_assert_statement: // assert_statement
      case symbol_kind::S_raise_statement: // raise_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_elif_statement: // elif_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
      case symbol_kind::S_tuple_statement: // tuple_statement
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

      case symbol_kind::S_tuple_item: // tuple_item
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
      case symbol_kind::S_assert_statement: // assert_statement
      case symbol_kind::S_raise_statement: // raise_statement
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_multi_line_statement: // multi_line_statement
      case symbol_kind::S_function_def: // function_def
      case symbol_kind::S_global_statement: // global_statement
      case symbol_kind::S_nonlocal_statement: // nonlocal_statement
      case symbol_kind::S_elif_statement: // elif_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_expression_statment: // expression_statment
      case symbol_kind::S_tuple_statement: // tuple_statement
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
#line 272 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1164 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 273 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1170 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 278 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1176 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 282 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1182 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 286 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1188 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 290 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1194 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 291 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1200 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 295 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1206 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 296 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1212 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 300 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1218 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 301 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1224 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 302 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1230 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 303 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1238 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 306 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1246 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 309 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1254 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 315 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1262 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 318 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1270 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 324 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1278 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 327 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1286 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 333 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1292 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 334 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1298 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 335 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1304 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 340 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1310 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 344 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1316 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 348 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1322 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 352 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1328 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 353 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1334 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 357 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1340 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 358 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1346 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 359 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1352 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 360 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1358 "./parser.cpp"
    break;

  case 34: // raise_statement: RAISE
#line 364 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1364 "./parser.cpp"
    break;

  case 35: // raise_statement: RAISE expr
#line 365 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1370 "./parser.cpp"
    break;

  case 36: // raise_statement: RAISE expr FROM expr
#line 366 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1376 "./parser.cpp"
    break;

  case 37: // return_statement: RETURN
#line 370 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1382 "./parser.cpp"
    break;

  case 38: // return_statement: RETURN tuple_item
#line 371 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1388 "./parser.cpp"
    break;

  case 39: // single_line_statement: expression_statment
#line 375 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1394 "./parser.cpp"
    break;

  case 40: // single_line_statement: tuple_statement
#line 376 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1400 "./parser.cpp"
    break;

  case 41: // single_line_statement: assert_statement
#line 377 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1406 "./parser.cpp"
    break;

  case 42: // single_line_statement: pass_statement
#line 381 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1412 "./parser.cpp"
    break;

  case 43: // single_line_statement: return_statement
#line 383 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1418 "./parser.cpp"
    break;

  case 44: // single_line_statement: raise_statement
#line 384 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1424 "./parser.cpp"
    break;

  case 45: // single_line_statement: break_statement
#line 385 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1430 "./parser.cpp"
    break;

  case 46: // single_line_statement: continue_statement
#line 386 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1436 "./parser.cpp"
    break;

  case 47: // single_line_statement: import_statement
#line 387 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1442 "./parser.cpp"
    break;

  case 48: // single_line_statement: global_statement
#line 388 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1448 "./parser.cpp"
    break;

  case 49: // single_line_statement: nonlocal_statement
#line 389 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1454 "./parser.cpp"
    break;

  case 50: // module: module "." id
#line 394 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1460 "./parser.cpp"
    break;

  case 51: // module: id
#line 395 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1466 "./parser.cpp"
    break;

  case 52: // module_as_id: module
#line 399 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1472 "./parser.cpp"
    break;

  case 53: // module_as_id: module AS id
#line 400 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1478 "./parser.cpp"
    break;

  case 54: // module_as_id: "*"
#line 401 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1484 "./parser.cpp"
    break;

  case 55: // module_item_list: module_item_list "," module_as_id
#line 405 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1490 "./parser.cpp"
    break;

  case 56: // module_item_list: module_as_id
#line 406 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1496 "./parser.cpp"
    break;

  case 57: // dot_list: dot_list "."
#line 410 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1502 "./parser.cpp"
    break;

  case 58: // dot_list: "."
#line 411 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1508 "./parser.cpp"
    break;

  case 59: // import_statement: IMPORT module_item_list
#line 417 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1514 "./parser.cpp"
    break;

  case 60: // import_statement: FROM module IMPORT module_item_list
#line 418 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1521 "./parser.cpp"
    break;

  case 61: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 420 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1528 "./parser.cpp"
    break;

  case 62: // import_statement: FROM dot_list IMPORT module_item_list
#line 422 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1535 "./parser.cpp"
    break;

  case 63: // import_statement: FROM dot_list module IMPORT module_item_list
#line 424 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1542 "./parser.cpp"
    break;

  case 64: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 426 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1549 "./parser.cpp"
    break;

  case 65: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 428 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1556 "./parser.cpp"
    break;

  case 66: // multi_line_statement: if_statement
#line 433 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1562 "./parser.cpp"
    break;

  case 67: // multi_line_statement: function_def
#line 437 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1568 "./parser.cpp"
    break;

  case 68: // decorators_opt: decorators
#line 446 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1574 "./parser.cpp"
    break;

  case 69: // decorators_opt: %empty
#line 447 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1580 "./parser.cpp"
    break;

  case 70: // decorators: decorators "@" expr sep
#line 451 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1586 "./parser.cpp"
    break;

  case 71: // decorators: "@" expr sep
#line 452 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1592 "./parser.cpp"
    break;

  case 72: // parameter: id
#line 456 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1598 "./parser.cpp"
    break;

  case 73: // parameter: id ":" expr
#line 457 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1604 "./parser.cpp"
    break;

  case 74: // parameter: id "=" expr
#line 458 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1610 "./parser.cpp"
    break;

  case 75: // parameter: id ":" expr "=" expr
#line 459 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1616 "./parser.cpp"
    break;

  case 76: // parameter_list: defparameter_list "," "/" comma_opt
#line 463 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1623 "./parser.cpp"
    break;

  case 77: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 465 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1630 "./parser.cpp"
    break;

  case 78: // parameter_list: parameter_list_no_posonly
#line 467 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1636 "./parser.cpp"
    break;

  case 79: // parameter_list_no_posonly: defparameter_list comma_opt
#line 471 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1642 "./parser.cpp"
    break;

  case 80: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 472 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1649 "./parser.cpp"
    break;

  case 81: // parameter_list_no_posonly: parameter_list_starargs
#line 474 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1655 "./parser.cpp"
    break;

  case 82: // defparameter_list: defparameter_list "," parameter
#line 478 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1661 "./parser.cpp"
    break;

  case 83: // defparameter_list: parameter
#line 479 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1667 "./parser.cpp"
    break;

  case 84: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 487 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1673 "./parser.cpp"
    break;

  case 85: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 488 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1679 "./parser.cpp"
    break;

  case 86: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 489 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1686 "./parser.cpp"
    break;

  case 87: // parameter_list_starargs: "*" parameter comma_opt
#line 491 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1692 "./parser.cpp"
    break;

  case 88: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 492 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1699 "./parser.cpp"
    break;

  case 89: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 494 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1706 "./parser.cpp"
    break;

  case 90: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 496 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1713 "./parser.cpp"
    break;

  case 91: // parameter_list_starargs: "**" parameter comma_opt
#line 498 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1719 "./parser.cpp"
    break;

  case 92: // parameter_list_opt: parameter_list
#line 502 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1725 "./parser.cpp"
    break;

  case 93: // parameter_list_opt: %empty
#line 503 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1731 "./parser.cpp"
    break;

  case 96: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 513 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1737 "./parser.cpp"
    break;

  case 97: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 515 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1743 "./parser.cpp"
    break;

  case 98: // global_statement: GLOBAL expr_list
#line 525 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1749 "./parser.cpp"
    break;

  case 99: // ternary_if_statement: expr IF expr ELSE expr
#line 529 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1755 "./parser.cpp"
    break;

  case 100: // nonlocal_statement: NONLOCAL expr_list
#line 533 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1761 "./parser.cpp"
    break;

  case 101: // elif_statement: ELIF expr ":" sep statements
#line 537 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 1767 "./parser.cpp"
    break;

  case 102: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 538 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1774 "./parser.cpp"
    break;

  case 103: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 540 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1781 "./parser.cpp"
    break;

  case 104: // if_statement: IF expr ":" body_stmts
#line 545 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1789 "./parser.cpp"
    break;

  case 105: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 548 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1797 "./parser.cpp"
    break;

  case 106: // if_statement: IF expr ":" body_stmts elif_statement
#line 551 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1804 "./parser.cpp"
    break;

  case 107: // expression_statment: expr
#line 556 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1810 "./parser.cpp"
    break;

  case 108: // tuple_statement: expr "," expr_list_opt
#line 560 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = TUPLE_STMT(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1816 "./parser.cpp"
    break;

  case 109: // string: string string_literal
#line 564 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1822 "./parser.cpp"
    break;

  case 110: // string: string_literal
#line 565 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1830 "./parser.cpp"
    break;

  case 111: // string: id string_literal
#line 568 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1838 "./parser.cpp"
    break;

  case 112: // string: string id string_literal
#line 571 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1846 "./parser.cpp"
    break;

  case 113: // expr_list_opt: expr_list
#line 577 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1852 "./parser.cpp"
    break;

  case 114: // expr_list_opt: %empty
#line 578 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1858 "./parser.cpp"
    break;

  case 115: // expr_list: expr_list "," expr
#line 582 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1864 "./parser.cpp"
    break;

  case 116: // expr_list: expr
#line 583 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1870 "./parser.cpp"
    break;

  case 117: // dict: expr ":" expr
#line 593 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1876 "./parser.cpp"
    break;

  case 118: // dict_list: dict_list "," dict
#line 597 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1882 "./parser.cpp"
    break;

  case 119: // dict_list: dict
#line 598 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1888 "./parser.cpp"
    break;

  case 120: // call_arguement_list: expr_list_opt
#line 602 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1894 "./parser.cpp"
    break;

  case 121: // call_arguement_list: expr_list ","
#line 603 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1900 "./parser.cpp"
    break;

  case 122: // keyword_item: id "=" expr
#line 608 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1906 "./parser.cpp"
    break;

  case 123: // keyword_item: "**" expr
#line 609 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1912 "./parser.cpp"
    break;

  case 124: // keyword_items: keyword_items "," keyword_item
#line 613 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1918 "./parser.cpp"
    break;

  case 125: // keyword_items: keyword_item
#line 614 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1924 "./parser.cpp"
    break;

  case 126: // primary: id
#line 619 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1930 "./parser.cpp"
    break;

  case 127: // primary: string
#line 620 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1936 "./parser.cpp"
    break;

  case 128: // primary: expr "." id
#line 621 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1942 "./parser.cpp"
    break;

  case 129: // function_call: primary "(" call_arguement_list ")"
#line 625 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1948 "./parser.cpp"
    break;

  case 130: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 626 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1955 "./parser.cpp"
    break;

  case 131: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 628 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1962 "./parser.cpp"
    break;

  case 132: // function_call: primary "(" keyword_items comma_opt ")"
#line 630 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1968 "./parser.cpp"
    break;

  case 133: // function_call: function_call "(" call_arguement_list ")"
#line 631 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1974 "./parser.cpp"
    break;

  case 134: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 632 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1981 "./parser.cpp"
    break;

  case 135: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 634 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1988 "./parser.cpp"
    break;

  case 136: // function_call: function_call "(" keyword_items comma_opt ")"
#line 636 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1994 "./parser.cpp"
    break;

  case 137: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 643 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2000 "./parser.cpp"
    break;

  case 138: // expr: id
#line 647 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2006 "./parser.cpp"
    break;

  case 139: // expr: integer_literal
#line 648 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2015 "./parser.cpp"
    break;

  case 140: // expr: string
#line 652 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2021 "./parser.cpp"
    break;

  case 141: // expr: real_literal
#line 653 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2027 "./parser.cpp"
    break;

  case 142: // expr: image_literal
#line 654 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2036 "./parser.cpp"
    break;

  case 143: // expr: TRUE
#line 658 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2042 "./parser.cpp"
    break;

  case 144: // expr: FALSE
#line 659 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2048 "./parser.cpp"
    break;

  case 145: // expr: NONE
#line 660 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2054 "./parser.cpp"
    break;

  case 146: // expr: "..."
#line 661 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2060 "./parser.cpp"
    break;

  case 147: // expr: "(" expr ")"
#line 662 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2066 "./parser.cpp"
    break;

  case 148: // expr: "(" ")"
#line 663 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2072 "./parser.cpp"
    break;

  case 149: // expr: function_call
#line 664 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2078 "./parser.cpp"
    break;

  case 150: // expr: "[" expr_list_opt "]"
#line 666 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2084 "./parser.cpp"
    break;

  case 151: // expr: "[" expr_list "," "]"
#line 667 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2090 "./parser.cpp"
    break;

  case 152: // expr: "{" expr_list "}"
#line 668 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2096 "./parser.cpp"
    break;

  case 153: // expr: "{" expr_list "," "}"
#line 669 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2102 "./parser.cpp"
    break;

  case 154: // expr: expr "." id
#line 670 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2108 "./parser.cpp"
    break;

  case 155: // expr: "{" "}"
#line 672 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2114 "./parser.cpp"
    break;

  case 156: // expr: "{" dict_list "}"
#line 673 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2120 "./parser.cpp"
    break;

  case 157: // expr: id ":=" expr
#line 677 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2126 "./parser.cpp"
    break;

  case 158: // expr: "*" expr
#line 678 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2132 "./parser.cpp"
    break;

  case 159: // expr: expr "+" expr
#line 680 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2138 "./parser.cpp"
    break;

  case 160: // expr: expr "-" expr
#line 681 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2144 "./parser.cpp"
    break;

  case 161: // expr: expr "*" expr
#line 682 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2150 "./parser.cpp"
    break;

  case 162: // expr: expr "/" expr
#line 683 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2156 "./parser.cpp"
    break;

  case 163: // expr: expr "%" expr
#line 684 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2162 "./parser.cpp"
    break;

  case 164: // expr: "-" expr
#line 685 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2168 "./parser.cpp"
    break;

  case 165: // expr: "+" expr
#line 686 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2174 "./parser.cpp"
    break;

  case 166: // expr: "~" expr
#line 687 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2180 "./parser.cpp"
    break;

  case 167: // expr: expr "**" expr
#line 688 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2186 "./parser.cpp"
    break;

  case 168: // expr: expr "//" expr
#line 689 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2192 "./parser.cpp"
    break;

  case 169: // expr: expr "@" expr
#line 690 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2198 "./parser.cpp"
    break;

  case 170: // expr: expr "&" expr
#line 692 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2204 "./parser.cpp"
    break;

  case 171: // expr: expr "|" expr
#line 693 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2210 "./parser.cpp"
    break;

  case 172: // expr: expr "^" expr
#line 694 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2216 "./parser.cpp"
    break;

  case 173: // expr: expr "<<" expr
#line 695 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2222 "./parser.cpp"
    break;

  case 174: // expr: expr ">>" expr
#line 696 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2228 "./parser.cpp"
    break;

  case 175: // expr: expr "==" expr
#line 698 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2234 "./parser.cpp"
    break;

  case 176: // expr: expr "!=" expr
#line 699 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2240 "./parser.cpp"
    break;

  case 177: // expr: expr "<" expr
#line 700 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2246 "./parser.cpp"
    break;

  case 178: // expr: expr "<=" expr
#line 701 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2252 "./parser.cpp"
    break;

  case 179: // expr: expr ">" expr
#line 702 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2258 "./parser.cpp"
    break;

  case 180: // expr: expr ">=" expr
#line 703 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2264 "./parser.cpp"
    break;

  case 181: // expr: expr "is" expr
#line 704 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2270 "./parser.cpp"
    break;

  case 182: // expr: expr "is not" expr
#line 705 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2276 "./parser.cpp"
    break;

  case 183: // expr: expr "in" expr
#line 706 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2282 "./parser.cpp"
    break;

  case 184: // expr: expr "not in" expr
#line 707 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2288 "./parser.cpp"
    break;

  case 185: // expr: expr "and" expr
#line 709 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2294 "./parser.cpp"
    break;

  case 186: // expr: expr "or" expr
#line 710 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2300 "./parser.cpp"
    break;

  case 187: // expr: "not" expr
#line 711 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2306 "./parser.cpp"
    break;

  case 188: // expr: ternary_if_statement
#line 718 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2312 "./parser.cpp"
    break;

  case 189: // id: identifier
#line 723 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2318 "./parser.cpp"
    break;

  case 190: // sep: sep sep_one
#line 727 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2324 "./parser.cpp"
    break;

  case 191: // sep: sep_one
#line 728 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2330 "./parser.cpp"
    break;

  case 192: // sep_one: NEWLINE
#line 732 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2336 "./parser.cpp"
    break;

  case 193: // sep_one: COMMENT
#line 733 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2342 "./parser.cpp"
    break;

  case 194: // sep_one: ";"
#line 734 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2348 "./parser.cpp"
    break;


#line 2352 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -284;

  const short  Parser ::yytable_ninf_ = -129;

  const short
   Parser ::yypact_[] =
  {
     379,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  1702,
    1702,  -284,  -284,    30,  1702,  1702,    14,  1702,  1702,  -284,
    1740,  1446,   537,  1702,  1702,  1702,  1702,  1702,  1702,  -284,
    -284,  -284,  -284,  1371,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,   170,  -284,   170,    19,   -10,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,    44,     2,     5,   651,    59,   170,
    -284,   696,   759,  -284,   136,    12,  -284,    28,  1200,   804,
    -284,    34,  -284,    81,    28,  1757,   537,  -284,   104,  -284,
     -16,  -284,   -13,   849,  -284,   894,    79,   109,    -7,    -7,
      -7,   588,    -7,  -284,  -284,   170,   170,   157,  1702,  -284,
     173,  1666,  1666,  1702,  1702,  1702,  1702,  1702,  1702,  1702,
    1702,  1702,  1702,  1702,  1702,   157,  1702,  1702,  1702,  1702,
    1702,  1702,  1702,  1702,  1702,  1702,  1702,  1702,  1702,  1702,
    1702,  -284,  1702,  -284,  1702,  1702,   141,   157,   144,  -284,
     145,  1702,   464,   157,    14,   132,   894,  1702,  1485,  -284,
    1702,  -284,  1702,   128,  -284,   452,   170,   133,   588,  -284,
    1702,  -284,   143,   123,  -284,   161,   187,   166,   130,   184,
    1757,   957,  1467,  1467,  1467,  1467,  1288,   205,   269,  -284,
      28,  1467,   434,   164,   434,    -7,    -7,    -7,    -7,    -7,
     310,   719,   719,  1467,  1467,  1467,  1467,    -7,  1467,  1244,
    1200,  1200,    14,    81,  -284,    14,    81,   180,  1200,  -284,
     156,  -284,    82,  1627,   196,   -29,  -284,  -284,  1410,  -284,
    -284,   849,  1200,  1702,  -284,     8,   170,  1200,  1666,  -284,
    1666,   162,  1702,  1666,  -284,  1666,   171,  1702,   202,   202,
      14,    81,  1702,   206,  -284,  -284,   172,   179,   124,  -284,
     177,  1559,  -284,  -284,  1002,   226,   201,    18,   157,  -284,
    -284,  -284,   228,  -284,   203,   129,   233,   234,  -284,  -284,
    1200,   233,   234,  -284,  1244,    14,   211,   214,   202,  1065,
     464,  -284,   140,  -284,   207,  -284,   549,  -284,  -284,  1702,
    -284,    25,   244,   245,     3,  -284,    91,  1702,  1702,    26,
     220,  1702,   224,   227,   229,  -284,  -284,   230,   170,  -284,
    -284,  -284,  -284,   157,   249,    33,  -284,  -284,  -284,   252,
    -284,  -284,   464,  1702,  1110,  1200,   256,  -284,  -284,  -284,
    -284,  -284,   -29,   245,    35,  -284,   157,   254,     8,  -284,
    -284,  1155,  1702,   223,  -284,   157,   245,    39,  -284,  -284,
     260,   464,  1200,   264,  -284,   245,  -284,   157,     8,  -284,
     170,  -284,   245,   -29,  -284,  -284
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      69,   139,   141,   142,   189,   110,   144,   143,   145,     0,
      34,    26,    27,     0,     0,     0,     0,     0,     0,    25,
      37,     0,     0,   114,     0,     0,     0,     0,     0,   146,
     194,   192,   193,    69,     3,     5,    42,    45,    46,    41,
      44,    43,     0,    47,    23,     0,    68,    67,    48,   188,
      49,    66,    39,    40,   140,     0,   149,   107,   138,     4,
     191,    28,    35,    58,     0,     0,    51,    98,   116,     0,
      54,    52,    56,    59,   100,   187,     0,    38,    30,   155,
       0,   119,     0,   116,   148,     0,     0,   113,   164,   165,
     158,     0,   166,     1,     2,    22,    24,     0,     0,   109,
       0,   114,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   190,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,   116,    31,     0,   152,
       0,   156,     0,   147,   150,     0,    71,     0,     0,   112,
       0,   120,   113,     0,   125,    95,   138,   113,     0,    95,
     185,     0,   183,   181,   182,   184,   186,   170,   172,   108,
     113,   175,   160,   154,   159,   161,   167,   169,   168,   163,
     171,   173,   174,   177,   178,   179,   180,   162,   176,   157,
      29,    36,     0,    60,    50,     0,    62,     0,   115,     9,
     104,     8,     0,     0,     0,     0,    53,    55,     0,   153,
     118,     0,   117,   114,   151,    93,    70,   123,   121,   129,
      94,     0,     0,   121,   133,    94,     0,     0,    95,    95,
       0,    63,     0,     0,   106,    12,     0,    18,    21,    14,
       0,    69,     7,    32,   115,   113,     0,     0,     0,    83,
      92,    78,    95,    81,     0,    72,    95,    95,   124,   132,
     122,    95,    95,   136,    99,    94,     0,     0,    95,     0,
       0,    13,    20,    15,     0,    17,    69,    11,    33,   121,
     137,     0,    95,    95,    94,    79,     0,     0,     0,    94,
       0,    94,     0,     0,     0,    61,    64,     0,     0,   105,
      16,     6,    10,     0,    95,    94,    87,    94,    91,    95,
      82,    80,     0,     0,    73,    74,     0,   130,   131,   134,
     135,    65,     0,    95,    94,    84,     0,    95,    94,    76,
      96,     0,     0,   101,    85,     0,    95,    94,    88,    77,
      95,     0,    75,     0,   103,    95,    89,     0,    94,    97,
       0,    86,    95,     0,    90,   102
  };

  const short
   Parser ::yypgoto_[] =
  {
    -284,  -284,   281,  -283,  -284,  -276,  -284,  -284,  -284,  -284,
    -203,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -135,    17,
    -129,   -43,  -284,  -284,  -284,  -284,  -284,   -85,  -284,   -19,
    -116,  -273,  -284,  -101,  -284,  -284,  -284,  -284,   -25,  -284,
    -284,  -284,  -284,   -20,   -15,   175,  -284,   -69,  -218,   -89,
    -284,  -284,     1,    87,     0,   -22
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    33,    34,   252,   209,   210,   286,   211,   212,   213,
      35,    36,    37,    38,    39,    77,    40,    41,    42,    71,
      72,    73,    65,    43,    44,    45,    46,   259,   260,   261,
     262,   263,   264,   295,    47,    48,    49,    50,   244,    51,
      52,    53,    54,   161,    67,    81,    82,   163,   164,   165,
      55,    56,    68,    58,   215,    60
  };

  const short
   Parser ::yytable_[] =
  {
      59,    57,    74,    86,   309,    78,    80,   214,    87,     4,
      61,    62,   268,   169,     4,   217,    69,   268,     4,    75,
       4,   321,    83,    85,     4,    88,    89,    90,    91,    92,
      64,     4,     4,   168,    57,   148,     4,   133,   150,     4,
      97,     4,    95,   138,    96,     4,   340,   143,   287,   343,
       4,    30,    99,   115,    98,   251,   118,    31,    32,   101,
     149,   145,   102,   151,   231,   257,   258,   131,   236,   291,
     257,   258,   139,   133,   133,   359,    70,   146,   247,   141,
     365,   268,   140,   312,   319,   321,   162,   167,   313,   160,
      63,   156,   179,   203,   137,   206,   336,   180,   345,   158,
      66,  -127,   357,    66,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   132,   181,   182,  -126,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   144,   199,   133,   200,   201,   276,   277,   266,
     322,   100,   208,    57,   271,   214,   217,     4,   208,   208,
       4,   221,    66,   222,   256,   147,   208,   154,   226,   238,
     155,   227,   239,     4,   241,   300,   302,   136,   245,   246,
     303,   304,   292,   293,   323,   314,   207,   307,   297,   242,
     243,   159,   298,   218,   157,   223,     4,   214,   166,   166,
     225,   316,   318,   133,   228,   131,   137,   278,   202,   337,
     229,   205,   183,    70,   133,   137,    70,   234,   255,   320,
     283,   284,   230,   335,    57,   267,   214,   233,   339,   254,
     272,  -128,   350,    66,   204,    66,   -19,   -19,   333,   208,
     216,    66,   344,   270,   208,   235,   348,   240,   274,   269,
     232,   132,    70,   279,  -126,   356,   242,   353,   273,   320,
      30,   346,    57,   275,   361,   280,    31,    32,   281,   282,
     355,   364,   320,   285,   114,   115,   116,   117,   118,   119,
     120,   121,   362,   320,   123,   124,   248,   289,   290,   294,
     296,    57,   249,   250,   299,   301,   129,    57,   305,    66,
     208,   306,    66,   310,    66,   315,   317,   327,   324,   325,
     334,   328,   208,   338,   329,   347,   330,   331,   332,   232,
     133,   358,   265,   360,    94,   166,   110,   166,   354,   349,
     166,     0,   166,    57,   341,   220,     0,    66,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,   123,   124,
       0,   133,     0,   352,   265,   265,     0,     0,     0,     0,
     129,     0,    57,     0,     0,     0,     0,   110,   111,     0,
     363,     0,    66,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   265,   123,
     124,   265,     1,     2,     3,     4,   326,     5,     6,     7,
       8,   129,     0,     9,    10,     0,     0,    11,     0,    12,
     265,     0,   265,     0,     0,     0,     0,    13,    14,    15,
      16,     0,     0,     0,     0,     0,    17,    18,     0,    19,
      20,   265,     0,   265,     0,   265,     0,     0,     0,     0,
       0,     0,   265,     0,   265,    21,    22,    23,    24,     0,
      25,    26,     0,    27,   265,   265,    28,     0,     0,     0,
       0,     0,     0,     0,    29,     1,     2,     3,     4,    30,
       5,     6,     7,     8,     0,    31,    32,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     9,    10,
       0,     0,    11,     0,    12,     0,     0,     0,     0,     0,
      18,     0,    13,    14,   115,    16,   117,   118,   119,   120,
     121,    17,    18,     0,    19,    20,     0,     0,    21,    22,
      23,    24,     0,    25,    26,   129,     0,     0,     0,    28,
      21,    22,    23,    24,     0,    25,    26,    29,     0,     0,
     224,    28,     0,     0,     0,     0,     0,     0,     0,    29,
       1,     2,     3,     4,    30,     5,     6,     7,     8,     0,
      31,    32,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,     0,     0,     0,     0,    18,     0,    13,    14,    15,
      16,     0,     0,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,    21,    22,    23,    24,     0,    25,    26,
     103,     0,     0,     0,    28,    21,    22,    23,    24,     0,
      25,    26,    29,    27,    84,     0,    28,     0,   104,     0,
     105,   106,   107,   108,    29,     0,     0,   109,     0,     0,
       0,     0,     0,     0,   311,   110,   111,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,   128,   103,     0,     0,     0,     0,    30,   129,
       0,     0,     0,     0,    31,    32,     0,     0,   130,     0,
       0,   104,     0,   105,   106,   107,   108,     0,     0,     0,
     109,     0,     0,     0,     0,     0,     0,     0,   110,   111,
       0,     0,   112,     0,     0,     0,   113,     0,   103,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   104,     0,   105,   106,
     107,   108,   129,     0,     0,   109,     0,     0,     0,     0,
       0,   130,     0,   110,   111,     0,     0,   134,     0,     0,
       0,   113,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   103,     0,     0,     0,     0,     0,   129,   114,   115,
     116,   117,   118,   119,   120,   121,   130,   135,     0,   104,
       0,   105,   106,   107,   108,     0,     0,     0,   109,     0,
     129,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,     0,     0,   113,     0,   103,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,   104,     0,   105,   106,   107,   108,
     129,     0,     0,   109,     0,     0,     0,     0,     0,   130,
       0,   110,   111,   142,     0,     0,     0,     0,     0,   113,
       0,   103,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   104,
       0,   105,   106,   107,   108,   129,     0,     0,   109,     0,
       0,     0,     0,     0,   130,     0,   110,   111,   152,     0,
       0,     0,     0,     0,   113,     0,   103,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,   104,     0,   105,   106,   107,   108,
     129,     0,     0,   109,     0,     0,     0,     0,     0,   130,
       0,   110,   111,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   103,
       0,   153,     0,     0,     0,   129,     0,     0,     0,     0,
       0,   237,     0,     0,   130,     0,     0,   104,     0,   105,
     106,   107,   108,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
       0,     0,   113,     0,   103,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   104,     0,   105,   106,   107,   108,   129,     0,
       0,   109,     0,     0,     0,     0,     0,   130,     0,   110,
     111,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,   123,   124,   125,   126,   127,   128,   103,     0,   288,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,   104,     0,   105,   106,   107,
     108,     0,     0,     0,   109,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   308,     0,     0,     0,     0,     0,
     113,     0,   103,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     104,     0,   105,   106,   107,   108,   129,     0,     0,   109,
       0,     0,     0,     0,     0,   130,     0,   110,   111,     0,
       0,     0,     0,   342,     0,   113,     0,   103,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   104,     0,   105,   106,   107,
     108,   129,     0,     0,   109,     0,     0,     0,     0,     0,
     130,     0,   110,   111,   351,     0,     0,     0,     0,     0,
     113,     0,   103,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
     104,     0,   105,   106,   107,   108,   129,     0,     0,   109,
       0,     0,     0,     0,     0,   130,     0,   110,   111,     0,
       0,     0,     0,     0,     0,   113,   103,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,     0,   105,   106,   107,   108,
       0,   129,     0,   109,     0,     0,     0,     0,     0,     0,
     130,   110,   111,     0,     0,     0,     0,     0,     0,   113,
     103,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,     0,
     105,   106,   107,   108,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   110,   111,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,    93,     0,     0,     1,     2,     3,     4,   130,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,     0,     0,     0,     0,     0,    17,    18,
       0,    19,    20,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,     0,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    18,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,    23,    24,
       0,    25,    26,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,    18,    29,     0,   253,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,    21,    22,    23,    24,     0,    25,    26,     0,
       0,     0,     0,    28,   110,   111,     0,     0,     0,     0,
       0,    29,    79,    18,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,     0,     0,
       0,    21,    22,    23,    24,     0,    25,    26,   129,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
      29,   219,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,     0,     0,     0,     0,     0,     0,    13,    14,    15,
      16,     0,     0,     0,     0,     0,    17,    18,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,     0,
      25,    26,     0,    27,     0,     0,    28,     0,     0,     0,
       1,     2,     3,     4,    29,     5,     6,     7,     8,     0,
       0,     9,    10,     0,     0,    11,     0,    12,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,    19,    20,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,    21,    22,    23,    24,     0,    25,    26,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,    29,     0,    18,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    23,    24,     0,    25,    26,   160,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
      18,    29,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     0,    21,    22,
      23,    24,     0,    25,    26,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,    29,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,     0,     0,     0,    21,    76,    23,    24,
       0,    25,    26,     0,   110,   111,     0,    28,     0,     0,
       0,     0,   113,     0,     0,    29,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
       0,     0,     0,     0,     0,     0,     0,   130
  };

  const short
   Parser ::yycheck_[] =
  {
       0,     0,    17,    23,   280,    20,    21,   142,    23,     6,
       9,    10,   230,   102,     6,   144,    15,   235,     6,    18,
       6,   294,    21,    22,     6,    24,    25,    26,    27,    28,
      13,     6,     6,   102,    33,    51,     6,    59,    51,     6,
      21,     6,    42,    31,    44,     6,   322,    13,   251,   332,
       6,    80,     8,    60,    64,    84,    63,    86,    87,    57,
      76,    76,    57,    76,   165,    62,    63,     8,   169,    51,
      62,    63,    60,    95,    96,   351,    62,    76,   213,    51,
     363,   299,    65,   286,    81,   358,   101,   102,    63,    63,
      60,    91,   112,   136,    60,   138,    63,   112,    63,    98,
      13,    57,    63,    16,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    54,   113,   114,    57,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    51,   132,   156,   134,   135,   238,   239,   228,
      49,    54,   141,   142,   233,   280,   275,     6,   147,   148,
       6,   150,    65,   152,   223,    51,   155,    78,   158,   202,
      51,   160,   205,     6,   207,   266,   267,    31,    86,    87,
     271,   272,   257,   258,    83,   291,    31,   278,    49,    23,
      24,     8,    53,    51,    97,    57,     6,   322,   101,   102,
      57,   292,   293,   215,    51,     8,    60,   240,    57,   315,
      77,    57,   115,    62,   226,    60,    62,    77,   223,   294,
      86,    87,    51,   314,   213,   230,   351,    51,   319,   218,
     235,    57,   338,   136,   137,   138,    86,    87,   313,   228,
     143,   144,   333,   232,   233,    51,   337,    57,   237,    77,
      53,    54,    62,   242,    57,   346,    23,    24,    77,   334,
      80,   336,   251,    51,   355,    49,    86,    87,    86,    80,
     345,   362,   347,    86,    59,    60,    61,    62,    63,    64,
      65,    66,   357,   358,    69,    70,    80,    51,    77,    51,
      77,   280,    86,    87,    51,    51,    81,   286,    77,   202,
     289,    77,   205,    86,   207,    51,    51,    77,   297,   298,
      51,    77,   301,    51,    77,    51,    77,    77,   308,    53,
     332,    51,   225,    49,    33,   228,    47,   230,   343,   338,
     233,    -1,   235,   322,   323,   150,    -1,   240,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    70,
      -1,   363,    -1,   342,   257,   258,    -1,    -1,    -1,    -1,
      81,    -1,   351,    -1,    -1,    -1,    -1,    47,    48,    -1,
     360,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,   291,    69,
      70,   294,     3,     4,     5,     6,   299,     8,     9,    10,
      11,    81,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
     313,    -1,   315,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,   334,    -1,   336,    -1,   338,    -1,    -1,    -1,    -1,
      -1,    -1,   345,    -1,   347,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,   357,   358,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,    80,
       8,     9,    10,    11,    -1,    86,    87,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    28,    29,    60,    31,    62,    63,    64,    65,
      66,    37,    38,    -1,    40,    41,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    81,    -1,    -1,    -1,    67,
      56,    57,    58,    59,    -1,    61,    62,    75,    -1,    -1,
      78,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
       3,     4,     5,     6,    80,     8,     9,    10,    11,    -1,
      86,    87,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      12,    -1,    -1,    -1,    67,    56,    57,    58,    59,    -1,
      61,    62,    75,    64,    77,    -1,    67,    -1,    30,    -1,
      32,    33,    34,    35,    75,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    12,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    90,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    51,    -1,    -1,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    47,    48,    -1,    -1,    51,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    12,    -1,    -1,    -1,    -1,    -1,    81,    59,    60,
      61,    62,    63,    64,    65,    66,    90,    28,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    12,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    32,    33,    34,    35,    81,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    12,
      -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    90,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    12,    -1,    77,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    12,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,    12,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    12,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    12,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    32,    33,    34,    35,
      -1,    81,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      12,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      32,    33,    34,    35,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,     0,    -1,    -1,     3,     4,     5,     6,    90,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    38,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    75,    -1,    77,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    47,    48,    -1,    -1,    -1,    -1,
      -1,    75,    76,    38,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    81,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,
       3,     4,     5,     6,    75,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    38,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    75,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    47,    48,    -1,    67,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    75,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    28,    29,    30,    31,    37,    38,    40,
      41,    56,    57,    58,    59,    61,    62,    64,    67,    75,
      80,    86,    87,    93,    94,   102,   103,   104,   105,   106,
     108,   109,   110,   115,   116,   117,   118,   126,   127,   128,
     129,   131,   132,   133,   134,   142,   143,   144,   145,   146,
     147,   144,   144,    60,   111,   114,   145,   136,   144,   144,
      62,   111,   112,   113,   136,   144,    57,   107,   136,    76,
     136,   137,   138,   144,    77,   144,   135,   136,   144,   144,
     144,   144,   144,     0,    94,   146,   146,    21,    64,     8,
     145,    57,    57,    12,    30,    32,    33,    34,    35,    39,
      47,    48,    51,    55,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    81,
      90,     8,    54,   147,    51,    28,    31,    60,    31,    60,
     111,    51,    49,    13,    51,   136,   144,    51,    51,    76,
      51,    76,    49,    77,    78,    51,   146,   145,   144,     8,
      63,   135,   136,   139,   140,   141,   145,   136,   139,   141,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   135,
     136,   144,   144,   145,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,    57,   113,   145,    57,   113,    31,   144,    96,
      97,    99,   100,   101,   110,   146,   145,   112,    51,    76,
     137,   144,   144,    57,    78,    57,   146,   144,    51,    77,
      51,   125,    53,    51,    77,    51,   125,    24,   113,   113,
      57,   113,    23,    24,   130,    86,    87,   110,    80,    86,
      87,    84,    95,    77,   144,   136,   139,    62,    63,   119,
     120,   121,   122,   123,   124,   145,   141,   136,   140,    77,
     144,   141,   136,    77,   144,    51,   125,   125,   113,   144,
      49,    86,    80,    86,    87,    86,    98,   102,    77,    51,
      77,    51,   119,   119,    51,   125,    77,    49,    53,    51,
     125,    51,   125,   125,   125,    77,    77,   125,    49,    97,
      86,    85,   102,    63,   122,    51,   125,    51,   125,    81,
     119,   123,    49,    83,   144,   144,   145,    77,    77,    77,
      77,    77,   146,   119,    51,   125,    63,   122,    51,   125,
      97,   144,    53,    95,   125,    63,   119,    51,   125,   121,
     122,    49,   144,    24,   130,   119,   125,    63,    51,    97,
      49,   125,   119,   146,   125,    95
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    92,    93,    93,    93,    94,    95,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   103,   104,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   112,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119,   120,   120,   120,   121,
     121,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   128,
     129,   130,   130,   130,   131,   131,   131,   132,   133,   134,
     134,   134,   134,   135,   135,   136,   136,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   145,
     146,   146,   147,   147,   147
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     2,     4,
       1,     2,     4,     5,     1,     2,     4,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     1,     3,     1,     2,     1,     2,
       4,     7,     4,     5,     7,     8,     1,     1,     1,     0,
       4,     3,     1,     3,     3,     5,     4,     5,     1,     2,
       3,     1,     3,     1,     4,     5,     7,     3,     5,     6,
       8,     3,     1,     0,     1,     0,     8,    10,     2,     5,
       2,     5,     9,     6,     4,     7,     5,     1,     3,     2,
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
  "RAISE", "ASYNC", "AWAIT", "BREAK", "CLASS", "CONTINUE", "DEF", "DEL",
  "ELIF", "ELSE", "EXCEPT", "FINALLY", "FOR", "FROM", "GLOBAL", "IF",
  "IMPORT", "\"in\"", "\"is\"", "\"is not\"", "\"not in\"", "LAMBDA",
  "NONLOCAL", "\"not\"", "\"or\"", "PASS", "RETURN", "TRY", "WHILE",
  "WITH", "YIELD", "ARROW", "\"&\"", "\"^\"", "\":\"", "\":!\"", "\",\"",
  "\"=>\"", "\"=\"", "\":=\"", "\"==\"", "\"{\"", "\"(\"", "\"[\"",
  "\"-\"", "\".\"", "\"+\"", "\"*\"", "\"**\"", "\"@\"", "\"//\"", "\"%\"",
  "\"~\"", "\"|\"", "\"<<\"", "\">>\"", "\"<\"", "\"<=\"", "\">\"",
  "\">=\"", "\"...\"", "\"}\"", "\")\"", "\"]\"", "\"self\"", "\";\"",
  "\"/\"", "\"_\"", "\"->\"", "INDENT", "DEDENT", "NEWLINE", "COMMENT",
  "EOLCOMMENT", "TYPE_COMMENT", "\"!=\"", "UNARY", "$accept", "units",
  "script_unit", "statements", "sep_statements", "body_stmts",
  "statements1", "single_line_statements", "single_line_multi_statements",
  "single_line_multi_statements_opt", "statement", "pass_statement",
  "break_statement", "continue_statement", "assert_statement",
  "tuple_item", "raise_statement", "return_statement",
  "single_line_statement", "module", "module_as_id", "module_item_list",
  "dot_list", "import_statement", "multi_line_statement", "decorators_opt",
  "decorators", "parameter", "parameter_list", "parameter_list_no_posonly",
  "defparameter_list", "parameter_list_starargs", "parameter_list_opt",
  "comma_opt", "function_def", "global_statement", "ternary_if_statement",
  "nonlocal_statement", "elif_statement", "if_statement",
  "expression_statment", "tuple_statement", "string", "expr_list_opt",
  "expr_list", "dict", "dict_list", "call_arguement_list", "keyword_item",
  "keyword_items", "primary", "function_call", "expr", "id", "sep",
  "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   272,   272,   273,   274,   278,   282,   286,   290,   291,
     295,   296,   300,   301,   302,   303,   306,   309,   315,   318,
     324,   327,   333,   334,   335,   340,   344,   348,   352,   353,
     357,   358,   359,   360,   364,   365,   366,   370,   371,   375,
     376,   377,   381,   383,   384,   385,   386,   387,   388,   389,
     394,   395,   399,   400,   401,   405,   406,   410,   411,   417,
     418,   420,   422,   424,   426,   428,   433,   437,   446,   447,
     451,   452,   456,   457,   458,   459,   463,   465,   467,   471,
     472,   474,   478,   479,   487,   488,   489,   491,   492,   494,
     496,   498,   502,   503,   507,   508,   512,   514,   525,   529,
     533,   537,   538,   540,   545,   548,   551,   556,   560,   564,
     565,   568,   571,   577,   578,   582,   583,   593,   597,   598,
     602,   603,   608,   609,   613,   614,   619,   620,   621,   625,
     626,   628,   630,   631,   632,   634,   636,   643,   647,   648,
     652,   653,   654,   658,   659,   660,   661,   662,   663,   664,
     666,   667,   668,   669,   670,   672,   673,   677,   678,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     692,   693,   694,   695,   696,   698,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   709,   710,   711,   718,   723,
     727,   728,   732,   733,   734
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
#line 3223 "./parser.cpp"

#line 737 "parser.ypp"
