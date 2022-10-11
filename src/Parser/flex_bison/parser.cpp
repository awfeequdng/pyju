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
      case symbol_kind::S_delete_statement: // delete_statement
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
      case symbol_kind::S_delete_statement: // delete_statement
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
      case symbol_kind::S_delete_statement: // delete_statement
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
      case symbol_kind::S_delete_statement: // delete_statement
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
      case symbol_kind::S_delete_statement: // delete_statement
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
#line 273 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1169 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 274 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1175 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 279 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1181 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 283 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1187 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 287 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1193 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 291 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1199 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 292 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1205 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 296 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1211 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 297 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1217 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 301 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1223 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 302 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1229 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 303 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1235 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 304 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1243 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 307 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1251 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 310 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1259 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 316 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1267 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 319 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1275 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 325 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1283 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 328 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1291 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 334 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1297 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 335 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1303 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 336 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1309 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 341 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1315 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 345 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1321 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 349 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1327 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 353 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1333 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 354 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1339 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 358 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1345 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 359 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1351 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 360 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1357 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 361 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1363 "./parser.cpp"
    break;

  case 34: // raise_statement: RAISE
#line 365 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1369 "./parser.cpp"
    break;

  case 35: // raise_statement: RAISE expr
#line 366 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1375 "./parser.cpp"
    break;

  case 36: // raise_statement: RAISE expr FROM expr
#line 367 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1381 "./parser.cpp"
    break;

  case 37: // return_statement: RETURN
#line 371 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1387 "./parser.cpp"
    break;

  case 38: // return_statement: RETURN tuple_item
#line 372 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1393 "./parser.cpp"
    break;

  case 39: // delete_statement: DEL expr_list
#line 377 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1399 "./parser.cpp"
    break;

  case 40: // delete_statement: DEL expr_list ","
#line 378 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1405 "./parser.cpp"
    break;

  case 41: // delete_statement: DEL "(" expr_list "," ")"
#line 379 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1412 "./parser.cpp"
    break;

  case 42: // delete_statement: DEL "(" expr_list "," expr ")"
#line 381 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1419 "./parser.cpp"
    break;

  case 43: // single_line_statement: expression_statment
#line 386 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1425 "./parser.cpp"
    break;

  case 44: // single_line_statement: tuple_statement
#line 387 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1431 "./parser.cpp"
    break;

  case 45: // single_line_statement: assert_statement
#line 388 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1437 "./parser.cpp"
    break;

  case 46: // single_line_statement: pass_statement
#line 392 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1443 "./parser.cpp"
    break;

  case 47: // single_line_statement: delete_statement
#line 393 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1449 "./parser.cpp"
    break;

  case 48: // single_line_statement: return_statement
#line 394 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1455 "./parser.cpp"
    break;

  case 49: // single_line_statement: raise_statement
#line 395 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1461 "./parser.cpp"
    break;

  case 50: // single_line_statement: break_statement
#line 396 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1467 "./parser.cpp"
    break;

  case 51: // single_line_statement: continue_statement
#line 397 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1473 "./parser.cpp"
    break;

  case 52: // single_line_statement: import_statement
#line 398 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1479 "./parser.cpp"
    break;

  case 53: // single_line_statement: global_statement
#line 399 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1485 "./parser.cpp"
    break;

  case 54: // single_line_statement: nonlocal_statement
#line 400 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1491 "./parser.cpp"
    break;

  case 55: // module: module "." id
#line 405 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1497 "./parser.cpp"
    break;

  case 56: // module: id
#line 406 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1503 "./parser.cpp"
    break;

  case 57: // module_as_id: module
#line 410 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1509 "./parser.cpp"
    break;

  case 58: // module_as_id: module AS id
#line 411 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1515 "./parser.cpp"
    break;

  case 59: // module_as_id: "*"
#line 412 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1521 "./parser.cpp"
    break;

  case 60: // module_item_list: module_item_list "," module_as_id
#line 416 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1527 "./parser.cpp"
    break;

  case 61: // module_item_list: module_as_id
#line 417 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1533 "./parser.cpp"
    break;

  case 62: // dot_list: dot_list "."
#line 421 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1539 "./parser.cpp"
    break;

  case 63: // dot_list: "."
#line 422 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1545 "./parser.cpp"
    break;

  case 64: // import_statement: IMPORT module_item_list
#line 428 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1551 "./parser.cpp"
    break;

  case 65: // import_statement: FROM module IMPORT module_item_list
#line 429 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1558 "./parser.cpp"
    break;

  case 66: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 431 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1565 "./parser.cpp"
    break;

  case 67: // import_statement: FROM dot_list IMPORT module_item_list
#line 433 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1572 "./parser.cpp"
    break;

  case 68: // import_statement: FROM dot_list module IMPORT module_item_list
#line 435 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1579 "./parser.cpp"
    break;

  case 69: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 437 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1586 "./parser.cpp"
    break;

  case 70: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 439 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1593 "./parser.cpp"
    break;

  case 71: // multi_line_statement: if_statement
#line 444 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1599 "./parser.cpp"
    break;

  case 72: // multi_line_statement: function_def
#line 448 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1605 "./parser.cpp"
    break;

  case 73: // decorators_opt: decorators
#line 457 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1611 "./parser.cpp"
    break;

  case 74: // decorators_opt: %empty
#line 458 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1617 "./parser.cpp"
    break;

  case 75: // decorators: decorators "@" expr sep
#line 462 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1623 "./parser.cpp"
    break;

  case 76: // decorators: "@" expr sep
#line 463 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1629 "./parser.cpp"
    break;

  case 77: // parameter: id
#line 467 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1635 "./parser.cpp"
    break;

  case 78: // parameter: id ":" expr
#line 468 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1641 "./parser.cpp"
    break;

  case 79: // parameter: id "=" expr
#line 469 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1647 "./parser.cpp"
    break;

  case 80: // parameter: id ":" expr "=" expr
#line 470 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1653 "./parser.cpp"
    break;

  case 81: // parameter_list: defparameter_list "," "/" comma_opt
#line 474 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1660 "./parser.cpp"
    break;

  case 82: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 476 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1667 "./parser.cpp"
    break;

  case 83: // parameter_list: parameter_list_no_posonly
#line 478 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1673 "./parser.cpp"
    break;

  case 84: // parameter_list_no_posonly: defparameter_list comma_opt
#line 482 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1679 "./parser.cpp"
    break;

  case 85: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 483 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1686 "./parser.cpp"
    break;

  case 86: // parameter_list_no_posonly: parameter_list_starargs
#line 485 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1692 "./parser.cpp"
    break;

  case 87: // defparameter_list: defparameter_list "," parameter
#line 489 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1698 "./parser.cpp"
    break;

  case 88: // defparameter_list: parameter
#line 490 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1704 "./parser.cpp"
    break;

  case 89: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 498 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1710 "./parser.cpp"
    break;

  case 90: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 499 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1716 "./parser.cpp"
    break;

  case 91: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 500 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1723 "./parser.cpp"
    break;

  case 92: // parameter_list_starargs: "*" parameter comma_opt
#line 502 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1729 "./parser.cpp"
    break;

  case 93: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 503 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1736 "./parser.cpp"
    break;

  case 94: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 505 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1743 "./parser.cpp"
    break;

  case 95: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 507 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1750 "./parser.cpp"
    break;

  case 96: // parameter_list_starargs: "**" parameter comma_opt
#line 509 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1756 "./parser.cpp"
    break;

  case 97: // parameter_list_opt: parameter_list
#line 513 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1762 "./parser.cpp"
    break;

  case 98: // parameter_list_opt: %empty
#line 514 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1768 "./parser.cpp"
    break;

  case 101: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 524 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1774 "./parser.cpp"
    break;

  case 102: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 526 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1780 "./parser.cpp"
    break;

  case 103: // global_statement: GLOBAL expr_list
#line 536 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1786 "./parser.cpp"
    break;

  case 104: // ternary_if_statement: expr IF expr ELSE expr
#line 540 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1792 "./parser.cpp"
    break;

  case 105: // nonlocal_statement: NONLOCAL expr_list
#line 544 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1798 "./parser.cpp"
    break;

  case 106: // elif_statement: ELIF expr ":" sep statements
#line 548 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 1804 "./parser.cpp"
    break;

  case 107: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 549 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1811 "./parser.cpp"
    break;

  case 108: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 551 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1818 "./parser.cpp"
    break;

  case 109: // if_statement: IF expr ":" body_stmts
#line 556 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1826 "./parser.cpp"
    break;

  case 110: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 559 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1834 "./parser.cpp"
    break;

  case 111: // if_statement: IF expr ":" body_stmts elif_statement
#line 562 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1841 "./parser.cpp"
    break;

  case 112: // expression_statment: expr
#line 567 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1847 "./parser.cpp"
    break;

  case 113: // tuple_statement: expr "," expr_list_opt
#line 571 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = TUPLE_STMT(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1853 "./parser.cpp"
    break;

  case 114: // string: string string_literal
#line 575 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1859 "./parser.cpp"
    break;

  case 115: // string: string_literal
#line 576 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1867 "./parser.cpp"
    break;

  case 116: // string: id string_literal
#line 579 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1875 "./parser.cpp"
    break;

  case 117: // string: string id string_literal
#line 582 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1883 "./parser.cpp"
    break;

  case 118: // expr_list_opt: expr_list
#line 588 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1889 "./parser.cpp"
    break;

  case 119: // expr_list_opt: %empty
#line 589 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1895 "./parser.cpp"
    break;

  case 120: // expr_list: expr_list "," expr
#line 593 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1901 "./parser.cpp"
    break;

  case 121: // expr_list: expr
#line 594 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1907 "./parser.cpp"
    break;

  case 122: // dict: expr ":" expr
#line 604 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1913 "./parser.cpp"
    break;

  case 123: // dict_list: dict_list "," dict
#line 608 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1919 "./parser.cpp"
    break;

  case 124: // dict_list: dict
#line 609 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1925 "./parser.cpp"
    break;

  case 125: // call_arguement_list: expr_list_opt
#line 613 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1931 "./parser.cpp"
    break;

  case 126: // call_arguement_list: expr_list ","
#line 614 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1937 "./parser.cpp"
    break;

  case 127: // keyword_item: id "=" expr
#line 619 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1943 "./parser.cpp"
    break;

  case 128: // keyword_item: "**" expr
#line 620 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1949 "./parser.cpp"
    break;

  case 129: // keyword_items: keyword_items "," keyword_item
#line 624 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1955 "./parser.cpp"
    break;

  case 130: // keyword_items: keyword_item
#line 625 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1961 "./parser.cpp"
    break;

  case 131: // primary: id
#line 630 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1967 "./parser.cpp"
    break;

  case 132: // primary: string
#line 631 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1973 "./parser.cpp"
    break;

  case 133: // primary: expr "." id
#line 632 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1979 "./parser.cpp"
    break;

  case 134: // function_call: primary "(" call_arguement_list ")"
#line 636 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1985 "./parser.cpp"
    break;

  case 135: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 637 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1992 "./parser.cpp"
    break;

  case 136: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 639 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1999 "./parser.cpp"
    break;

  case 137: // function_call: primary "(" keyword_items comma_opt ")"
#line 641 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2005 "./parser.cpp"
    break;

  case 138: // function_call: function_call "(" call_arguement_list ")"
#line 642 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2011 "./parser.cpp"
    break;

  case 139: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 643 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2018 "./parser.cpp"
    break;

  case 140: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 645 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2025 "./parser.cpp"
    break;

  case 141: // function_call: function_call "(" keyword_items comma_opt ")"
#line 647 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2031 "./parser.cpp"
    break;

  case 142: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 654 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2037 "./parser.cpp"
    break;

  case 143: // expr: id
#line 658 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2043 "./parser.cpp"
    break;

  case 144: // expr: integer_literal
#line 659 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2052 "./parser.cpp"
    break;

  case 145: // expr: string
#line 663 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2058 "./parser.cpp"
    break;

  case 146: // expr: real_literal
#line 664 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2064 "./parser.cpp"
    break;

  case 147: // expr: image_literal
#line 665 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2073 "./parser.cpp"
    break;

  case 148: // expr: TRUE
#line 669 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2079 "./parser.cpp"
    break;

  case 149: // expr: FALSE
#line 670 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2085 "./parser.cpp"
    break;

  case 150: // expr: NONE
#line 671 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2091 "./parser.cpp"
    break;

  case 151: // expr: "..."
#line 672 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2097 "./parser.cpp"
    break;

  case 152: // expr: "(" expr ")"
#line 673 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2103 "./parser.cpp"
    break;

  case 153: // expr: "(" ")"
#line 674 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2109 "./parser.cpp"
    break;

  case 154: // expr: function_call
#line 675 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2115 "./parser.cpp"
    break;

  case 155: // expr: "[" expr_list_opt "]"
#line 677 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2121 "./parser.cpp"
    break;

  case 156: // expr: "[" expr_list "," "]"
#line 678 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2127 "./parser.cpp"
    break;

  case 157: // expr: "{" expr_list "}"
#line 679 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2133 "./parser.cpp"
    break;

  case 158: // expr: "{" expr_list "," "}"
#line 680 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2139 "./parser.cpp"
    break;

  case 159: // expr: expr "." id
#line 681 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2145 "./parser.cpp"
    break;

  case 160: // expr: "{" "}"
#line 683 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2151 "./parser.cpp"
    break;

  case 161: // expr: "{" dict_list "}"
#line 684 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2157 "./parser.cpp"
    break;

  case 162: // expr: id ":=" expr
#line 688 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2163 "./parser.cpp"
    break;

  case 163: // expr: "*" expr
#line 689 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2169 "./parser.cpp"
    break;

  case 164: // expr: expr "+" expr
#line 691 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2175 "./parser.cpp"
    break;

  case 165: // expr: expr "-" expr
#line 692 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2181 "./parser.cpp"
    break;

  case 166: // expr: expr "*" expr
#line 693 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2187 "./parser.cpp"
    break;

  case 167: // expr: expr "/" expr
#line 694 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2193 "./parser.cpp"
    break;

  case 168: // expr: expr "%" expr
#line 695 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2199 "./parser.cpp"
    break;

  case 169: // expr: "-" expr
#line 696 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2205 "./parser.cpp"
    break;

  case 170: // expr: "+" expr
#line 697 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2211 "./parser.cpp"
    break;

  case 171: // expr: "~" expr
#line 698 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2217 "./parser.cpp"
    break;

  case 172: // expr: expr "**" expr
#line 699 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2223 "./parser.cpp"
    break;

  case 173: // expr: expr "//" expr
#line 700 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2229 "./parser.cpp"
    break;

  case 174: // expr: expr "@" expr
#line 701 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2235 "./parser.cpp"
    break;

  case 175: // expr: expr "&" expr
#line 703 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2241 "./parser.cpp"
    break;

  case 176: // expr: expr "|" expr
#line 704 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2247 "./parser.cpp"
    break;

  case 177: // expr: expr "^" expr
#line 705 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2253 "./parser.cpp"
    break;

  case 178: // expr: expr "<<" expr
#line 706 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2259 "./parser.cpp"
    break;

  case 179: // expr: expr ">>" expr
#line 707 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2265 "./parser.cpp"
    break;

  case 180: // expr: expr "==" expr
#line 709 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2271 "./parser.cpp"
    break;

  case 181: // expr: expr "!=" expr
#line 710 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2277 "./parser.cpp"
    break;

  case 182: // expr: expr "<" expr
#line 711 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2283 "./parser.cpp"
    break;

  case 183: // expr: expr "<=" expr
#line 712 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2289 "./parser.cpp"
    break;

  case 184: // expr: expr ">" expr
#line 713 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2295 "./parser.cpp"
    break;

  case 185: // expr: expr ">=" expr
#line 714 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2301 "./parser.cpp"
    break;

  case 186: // expr: expr "is" expr
#line 715 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2307 "./parser.cpp"
    break;

  case 187: // expr: expr "is not" expr
#line 716 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2313 "./parser.cpp"
    break;

  case 188: // expr: expr "in" expr
#line 717 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2319 "./parser.cpp"
    break;

  case 189: // expr: expr "not in" expr
#line 718 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2325 "./parser.cpp"
    break;

  case 190: // expr: expr "and" expr
#line 720 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2331 "./parser.cpp"
    break;

  case 191: // expr: expr "or" expr
#line 721 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2337 "./parser.cpp"
    break;

  case 192: // expr: "not" expr
#line 722 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2343 "./parser.cpp"
    break;

  case 193: // expr: ternary_if_statement
#line 729 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2349 "./parser.cpp"
    break;

  case 194: // id: identifier
#line 734 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2355 "./parser.cpp"
    break;

  case 195: // sep: sep sep_one
#line 738 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2361 "./parser.cpp"
    break;

  case 196: // sep: sep_one
#line 739 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2367 "./parser.cpp"
    break;

  case 197: // sep_one: NEWLINE
#line 743 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2373 "./parser.cpp"
    break;

  case 198: // sep_one: COMMENT
#line 744 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2379 "./parser.cpp"
    break;

  case 199: // sep_one: ";"
#line 745 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2385 "./parser.cpp"
    break;


#line 2389 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -299;

  const short  Parser ::yytable_ninf_ = -134;

  const short
   Parser ::yypact_[] =
  {
     390,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  1813,
    1813,  -299,  -299,  1851,    41,  1813,  1813,    30,  1813,  1813,
    -299,  1873,  1560,   548,  1813,  1813,  1813,  1813,  1813,  1813,
    -299,  -299,  -299,  -299,  1445,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,   119,  -299,   119,    20,   -14,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,    43,    -3,    23,   662,
      10,   119,  -299,   707,   770,   548,    45,  1274,  -299,    17,
      25,  -299,    69,   815,  -299,    -5,  -299,   100,    69,  1890,
     548,  -299,   117,  -299,   114,  -299,   127,   860,  -299,   905,
     -26,   141,    -1,    -1,    -1,   599,    -1,  -299,  -299,   119,
     119,   142,  1813,  -299,   180,  1777,  1777,  1813,  1813,  1813,
    1813,  1813,  1813,  1813,  1813,  1813,  1813,  1813,  1813,   142,
    1813,  1813,  1813,  1813,  1813,  1813,  1813,  1813,  1813,  1813,
    1813,  1813,  1813,  1813,  1813,  -299,  1813,  -299,  1813,  1813,
     145,   905,  1813,     3,   142,    36,  -299,   115,  1813,   475,
     142,    30,   149,  1813,  1596,  -299,  1813,  -299,  1813,   147,
    -299,   463,   119,   154,   599,  -299,  1813,  -299,   151,   143,
    -299,   168,    99,   171,   150,   173,  1890,   968,  1578,  1578,
    1578,  1578,  1362,  1833,  1922,  -299,    69,  1578,   251,   172,
     251,    -1,    -1,    -1,    -1,    -1,  1655,   207,   207,  1578,
    1578,  1578,  1578,    -1,  1578,  1318,  1274,  1274,  1484,  1274,
      30,   100,  -299,    30,   100,    37,  -299,   137,  -299,    93,
    1738,   128,   111,  -299,  -299,  1520,  -299,  -299,   860,  1274,
    1813,  -299,     9,   119,  1274,  1777,  -299,  1777,   153,  1813,
    1777,  -299,  1777,   157,  1813,  -299,  1013,   174,   174,    30,
     100,  1813,   186,  -299,  -299,   158,   163,    95,  -299,   160,
    1670,  -299,  -299,  1076,   196,   178,    32,   142,  -299,  -299,
    -299,   197,  -299,   179,     4,   200,   206,  -299,  -299,  1274,
     200,   206,  -299,  1318,  -299,    30,   181,   182,   174,  1139,
     475,  -299,    97,  -299,   176,  -299,   560,  -299,  -299,  1813,
    -299,    13,   209,   224,     6,  -299,   -10,  1813,  1813,    19,
     202,  1813,   203,   204,   208,  -299,  -299,   212,   119,  -299,
    -299,  -299,  -299,   142,   233,    26,  -299,  -299,  -299,   241,
    -299,  -299,   475,  1813,  1184,  1274,   184,  -299,  -299,  -299,
    -299,  -299,   111,   224,    27,  -299,   142,   242,     9,  -299,
    -299,  1229,  1813,   194,  -299,   142,   224,    28,  -299,  -299,
     243,   475,  1274,   246,  -299,   224,  -299,   142,     9,  -299,
     119,  -299,   224,   111,  -299,  -299
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      74,   144,   146,   147,   194,   115,   149,   148,   150,     0,
      34,    26,    27,     0,     0,     0,     0,     0,     0,     0,
      25,    37,     0,     0,   119,     0,     0,     0,     0,     0,
     151,   199,   197,   198,    74,     3,     5,    46,    50,    51,
      45,    49,    48,    47,     0,    52,    23,     0,    73,    72,
      53,   193,    54,    71,    43,    44,   145,     0,   154,   112,
     143,     4,   196,    28,    35,     0,    39,   121,    63,     0,
       0,    56,   103,     0,    59,    57,    61,    64,   105,   192,
       0,    38,    30,   160,     0,   124,     0,   121,   153,     0,
       0,   118,   169,   170,   163,     0,   171,     1,     2,    22,
      24,     0,     0,   114,     0,   119,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   195,     0,     0,
       0,   121,    40,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,    31,     0,   157,     0,   161,     0,   152,
     155,     0,    76,     0,     0,   117,     0,   125,   118,     0,
     130,   100,   143,   118,     0,   100,   190,     0,   188,   186,
     187,   189,   191,   175,   177,   113,   118,   180,   165,   159,
     164,   166,   172,   174,   173,   168,   176,   178,   179,   182,
     183,   184,   185,   167,   181,   162,    29,    36,     0,   120,
       0,    65,    55,     0,    67,     0,     9,   109,     8,     0,
       0,     0,     0,    58,    60,     0,   158,   123,     0,   122,
     119,   156,    98,    75,   128,   126,   134,    99,     0,     0,
     126,   138,    99,     0,     0,    41,   120,   100,   100,     0,
      68,     0,     0,   111,    12,     0,    18,    21,    14,     0,
      74,     7,    32,   120,   118,     0,     0,     0,    88,    97,
      83,   100,    86,     0,    77,   100,   100,   129,   137,   127,
     100,   100,   141,   104,    42,    99,     0,     0,   100,     0,
       0,    13,    20,    15,     0,    17,    74,    11,    33,   126,
     142,     0,   100,   100,    99,    84,     0,     0,     0,    99,
       0,    99,     0,     0,     0,    66,    69,     0,     0,   110,
      16,     6,    10,     0,   100,    99,    92,    99,    96,   100,
      87,    85,     0,     0,    78,    79,     0,   135,   136,   139,
     140,    70,     0,   100,    99,    89,     0,   100,    99,    81,
     101,     0,     0,   106,    90,     0,   100,    99,    93,    82,
     100,     0,    80,     0,   108,   100,    94,     0,    99,   102,
       0,    91,   100,     0,    95,   107
  };

  const short
   Parser ::yypgoto_[] =
  {
    -299,  -299,   262,  -256,  -299,  -287,  -299,  -299,  -299,  -299,
    -238,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -145,
      -7,  -149,   -39,  -299,  -299,  -299,  -299,  -299,   -81,  -299,
     -49,  -264,  -298,  -299,     2,  -299,  -299,  -299,  -299,   -51,
    -299,  -299,  -299,  -299,   -19,   148,   166,  -299,   -92,  -221,
     -93,  -299,  -299,     1,    88,     0,   -21
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    34,    35,   261,   216,   217,   296,   218,   219,   220,
      36,    37,    38,    39,    40,    81,    41,    42,    43,    44,
      75,    76,    77,    70,    45,    46,    47,    48,   268,   269,
     270,   271,   272,   273,   305,    49,    50,    51,    52,   253,
      53,    54,    55,    56,   167,    66,    85,    86,   169,   170,
     171,    57,    58,    67,    60,   222,    62
  };

  const short
   Parser ::yytable_[] =
  {
      61,    59,   224,   319,   221,    90,   331,    69,   150,     4,
      63,    64,     4,   175,   174,     4,   277,    73,   135,     4,
      79,   277,   297,    87,    89,     4,    92,    93,    94,    95,
      96,     4,     4,     4,     4,    59,     4,   324,     4,   332,
     137,   101,     4,     4,    99,   350,   100,     4,   143,     4,
     102,   103,   160,   307,   105,   144,   145,   308,   322,   119,
     210,   347,   122,   147,   136,    74,   141,  -131,   266,   267,
     331,   266,   267,   333,   369,   256,   323,   144,   137,   137,
     106,   141,   166,   301,   360,   146,   353,   329,   277,   346,
     355,   367,    74,   213,   249,   162,   142,   185,    74,    74,
    -132,    68,    71,   164,   211,    71,   214,   135,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   375,   187,   188,
     148,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   224,   205,   265,   206,
     207,   137,   275,   209,   104,   221,   215,   280,     4,   209,
      59,   151,   239,   136,   209,   209,  -131,   228,    71,   229,
     251,   252,   209,    72,   233,   154,    78,   234,   153,    82,
      84,   247,    91,   238,   248,   144,   250,   243,   156,   254,
     255,   293,   294,   -19,   -19,   302,   303,   221,   165,   163,
     155,    31,   161,   172,   172,   260,   208,    32,    33,    31,
     225,   137,   235,   157,   230,    32,    33,   189,   257,   246,
     288,   232,   137,   140,   258,   259,   221,   251,   363,   237,
     236,    59,   240,   330,   242,   285,   263,   241,   152,  -133,
     278,    71,   212,    71,   282,   290,   209,   239,   223,    71,
     279,   209,   343,   292,   291,   283,   295,   299,   304,   286,
     287,   309,   289,   168,   173,   300,   306,   311,   315,   316,
     325,    59,   320,   330,   186,   356,   118,   119,   120,   121,
     122,   123,   124,   125,   365,   327,   330,   310,   312,   337,
     338,   339,   313,   314,   344,   340,   372,   330,   133,   341,
     317,    59,   348,   357,   368,   370,    98,    59,    71,   359,
     209,    71,   364,    71,   326,   328,     0,     0,   334,   335,
       0,   119,   209,   121,   122,   123,   124,   125,   342,     0,
     274,   137,   227,   172,     0,   172,   345,     0,   172,     0,
     172,   349,   133,    59,   351,     0,     0,    71,     0,     0,
       0,     0,     0,     0,     0,   354,     0,     0,     0,   358,
       0,     0,   137,   362,   274,   274,     0,     0,   366,     0,
       0,     0,    59,     0,     0,     0,     0,   371,     0,     0,
     373,     0,     0,    71,   374,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,   274,
     281,     0,   274,     1,     2,     3,     4,   336,     5,     6,
       7,     8,     0,     0,     9,    10,     0,     0,    11,     0,
      12,   274,    13,   274,     0,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    18,    19,     0,
      20,    21,   274,     0,   274,     0,   274,     0,     0,     0,
       0,     0,     0,   274,     0,   274,    22,    23,    24,    25,
       0,    26,    27,     0,    28,   274,   274,    29,     0,     0,
       0,     0,     0,     0,     0,    30,     1,     2,     3,     4,
      31,     5,     6,     7,     8,     0,    32,    33,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     9,
      10,     0,     0,    11,     0,    12,     0,    13,     0,     0,
       0,    19,     0,    14,    15,     0,    17,     0,     0,     0,
       0,     0,    18,    19,     0,    20,    21,     0,     0,    22,
      23,    24,    25,     0,    26,    27,     0,     0,     0,     0,
      29,    22,    23,    24,    25,     0,    26,    27,    30,     0,
       0,   231,    29,     0,     0,     0,     0,     0,     0,     0,
      30,     1,     2,     3,     4,    31,     5,     6,     7,     8,
       0,    32,    33,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     9,    10,     0,     0,    11,     0,
      12,     0,    13,     0,     0,     0,    19,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    18,    19,     0,
      20,    21,     0,     0,    22,    23,    24,    25,     0,    26,
      27,   107,     0,     0,     0,    29,    22,    23,    24,    25,
       0,    26,    27,    30,    28,    88,     0,    29,     0,   108,
       0,   109,   110,   111,   112,    30,     0,     0,   113,     0,
       0,     0,     0,     0,     0,   321,   114,   115,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,   127,   128,
     129,   130,   131,   132,   107,     0,     0,     0,     0,    31,
     133,     0,     0,     0,     0,    32,    33,     0,     0,   134,
       0,     0,   108,     0,   109,   110,   111,   112,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,   114,
     115,     0,     0,   116,     0,     0,     0,   117,     0,   107,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,   127,   128,   129,   130,   131,   132,   108,     0,   109,
     110,   111,   112,   133,     0,     0,   113,     0,     0,     0,
       0,     0,   134,     0,   114,   115,     0,     0,   138,     0,
       0,     0,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,   127,   128,   129,   130,
     131,   132,   107,     0,     0,     0,     0,     0,   133,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   139,     0,
     108,     0,   109,   110,   111,   112,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,   114,   115,     0,
       0,     0,     0,     0,     0,   117,     0,   107,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,   127,
     128,   129,   130,   131,   132,   108,     0,   109,   110,   111,
     112,   133,     0,     0,   113,     0,     0,     0,     0,     0,
     134,     0,   114,   115,   149,     0,     0,     0,     0,     0,
     117,     0,   107,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,   127,   128,   129,   130,   131,   132,
     108,     0,   109,   110,   111,   112,   133,     0,     0,   113,
       0,     0,     0,     0,     0,   134,     0,   114,   115,   158,
       0,     0,     0,     0,     0,   117,     0,   107,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,   127,
     128,   129,   130,   131,   132,   108,     0,   109,   110,   111,
     112,   133,     0,     0,   113,     0,     0,     0,     0,     0,
     134,     0,   114,   115,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,   127,   128,   129,   130,   131,   132,
     107,     0,   159,     0,     0,     0,   133,     0,     0,     0,
       0,     0,   244,     0,     0,   134,     0,     0,   108,     0,
     109,   110,   111,   112,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,   114,   115,     0,     0,     0,
       0,     0,     0,   117,     0,   107,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,   127,   128,   129,
     130,   131,   132,   108,     0,   109,   110,   111,   112,   133,
       0,     0,   113,     0,     0,     0,     0,     0,   134,     0,
     114,   115,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,   127,   128,   129,   130,   131,   132,   107,     0,
     284,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,   108,     0,   109,   110,
     111,   112,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,   114,   115,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,   127,   128,   129,   130,   131,
     132,   107,     0,   298,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,   108,
       0,   109,   110,   111,   112,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   318,     0,
       0,     0,     0,     0,   117,     0,   107,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,   127,   128,
     129,   130,   131,   132,   108,     0,   109,   110,   111,   112,
     133,     0,     0,   113,     0,     0,     0,     0,     0,   134,
       0,   114,   115,     0,     0,     0,     0,   352,     0,   117,
       0,   107,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,   127,   128,   129,   130,   131,   132,   108,
       0,   109,   110,   111,   112,   133,     0,     0,   113,     0,
       0,     0,     0,     0,   134,     0,   114,   115,   361,     0,
       0,     0,     0,     0,   117,     0,   107,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,   127,   128,
     129,   130,   131,   132,   108,     0,   109,   110,   111,   112,
     133,     0,     0,   113,     0,     0,     0,     0,     0,   134,
       0,   114,   115,     0,     0,     0,     0,     0,     0,   117,
     107,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,   127,   128,   129,   130,   131,   132,     0,
     109,   110,   111,   112,     0,   133,     0,   113,     0,     0,
       0,     0,     0,     0,   134,   114,   115,     0,     0,     0,
       0,     0,     0,   117,   107,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,   127,   128,   129,
     130,   131,   132,     0,   109,   110,   111,   112,     0,   133,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   114,
     115,     0,     0,     0,     0,     0,     0,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,   133,     0,    97,     0,     0,     1,     2,
       3,     4,   134,     5,     6,     7,     8,     0,     0,     9,
      10,     0,     0,    11,     0,    12,     0,    13,     0,     0,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,    18,    19,     0,    20,    21,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,    22,    23,    24,    25,     0,    26,    27,     0,    28,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    19,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,     0,    26,    27,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,    19,    30,
       0,   245,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,    22,    23,    24,    25,
       0,    26,    27,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,    30,     0,   262,    19,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,    26,    27,     0,     0,   114,   115,    29,     0,     0,
       0,     0,     0,     0,    19,    30,    83,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,   127,   128,     0,
       0,     0,    22,    23,    24,    25,     0,    26,    27,   133,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,    30,   226,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     9,    10,     0,     0,    11,     0,
      12,     0,    13,     0,     0,     0,     0,     0,    14,    15,
      16,    17,   114,   115,     0,     0,     0,    18,    19,     0,
      20,    21,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,     0,   127,   128,    22,    23,    24,    25,
       0,    26,    27,     0,    28,     0,   133,    29,     0,     0,
       0,     1,     2,     3,     4,    30,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,     0,     0,     0,     0,     0,    14,    15,     0,    17,
       0,     0,     0,     0,     0,    18,    19,     0,    20,    21,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,    22,    23,    24,    25,     0,    26,
      27,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    19,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,     0,    26,    27,
     166,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,    19,    30,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,     0,    26,    27,     1,     2,     3,     4,
      29,     5,     6,     7,     8,     0,     0,     0,    30,    19,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,     0,   127,   128,     0,     0,     0,    22,    65,    24,
      25,    19,    26,    27,   133,     0,     0,     0,    29,     0,
       0,     0,   109,   110,   111,   112,    30,     0,     0,    22,
      80,    24,    25,     0,    26,    27,     0,   114,   115,     0,
      29,     0,     0,     0,     0,   117,     0,     0,    30,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,   114,
       0,   133,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   118,   119,   120,   121,   122,   123,   124,   125,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   133
  };

  const short
   Parser ::yycheck_[] =
  {
       0,     0,   151,   290,   149,    24,   304,    14,    13,     6,
       9,    10,     6,   106,   106,     6,   237,    16,     8,     6,
      19,   242,   260,    22,    23,     6,    25,    26,    27,    28,
      29,     6,     6,     6,     6,    34,     6,   301,     6,    49,
      61,    21,     6,     6,    44,   332,    46,     6,    31,     6,
      64,     8,    78,    49,    57,    60,    31,    53,   296,    60,
      57,   325,    63,    70,    54,    62,    65,    57,    62,    63,
     368,    62,    63,    83,   361,   220,    63,    60,    99,   100,
      57,    80,    63,    51,   348,    60,   342,    81,   309,    63,
      63,    63,    62,    57,    57,    95,    51,   116,    62,    62,
      57,    60,    14,   102,   143,    17,   145,     8,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   373,   117,   118,
      51,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   285,   136,   230,   138,
     139,   162,   235,   142,    56,   290,    31,   240,     6,   148,
     149,    51,    53,    54,   153,   154,    57,   156,    70,   158,
      23,    24,   161,    15,   164,    51,    18,   166,    51,    21,
      22,   210,    24,   171,   213,    60,   215,   175,    51,    86,
      87,    86,    87,    86,    87,   266,   267,   332,     8,   101,
      76,    80,    51,   105,   106,    84,    51,    86,    87,    80,
      51,   222,    51,    76,    57,    86,    87,   119,    80,   208,
     249,    57,   233,    65,    86,    87,   361,    23,    24,    51,
      77,   220,    51,   304,    51,    51,   225,    77,    80,    57,
      77,   143,   144,   145,    77,    49,   235,    53,   150,   151,
     239,   240,   323,    80,    86,   244,    86,    51,    51,   247,
     248,    51,   251,   105,   106,    77,    77,    51,    77,    77,
      51,   260,    86,   344,   116,   346,    59,    60,    61,    62,
      63,    64,    65,    66,   355,    51,   357,   275,   276,    77,
      77,    77,   280,   281,    51,    77,   367,   368,    81,    77,
     288,   290,    51,    51,    51,    49,    34,   296,   210,   348,
     299,   213,   353,   215,   302,   303,    -1,    -1,   307,   308,
      -1,    60,   311,    62,    63,    64,    65,    66,   318,    -1,
     232,   342,   156,   235,    -1,   237,   324,    -1,   240,    -1,
     242,   329,    81,   332,   333,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,   347,
      -1,    -1,   373,   352,   266,   267,    -1,    -1,   356,    -1,
      -1,    -1,   361,    -1,    -1,    -1,    -1,   365,    -1,    -1,
     370,    -1,    -1,   285,   372,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,   301,
     242,    -1,   304,     3,     4,     5,     6,   309,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,   323,    22,   325,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,   344,    -1,   346,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,   355,    -1,   357,    56,    57,    58,    59,
      -1,    61,    62,    -1,    64,   367,   368,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,
      80,     8,     9,    10,    11,    -1,    86,    87,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    38,    -1,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    56,    57,    58,    59,    -1,    61,    62,    75,    -1,
      -1,    78,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,     3,     4,     5,     6,    80,     8,     9,    10,    11,
      -1,    86,    87,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    38,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    12,    -1,    -1,    -1,    67,    56,    57,    58,    59,
      -1,    61,    62,    75,    64,    77,    -1,    67,    -1,    30,
      -1,    32,    33,    34,    35,    75,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    12,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,    90,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    12,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    28,    -1,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    12,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      12,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    90,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    30,    -1,    32,    33,    34,    35,    81,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    12,    -1,
      77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    12,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,    12,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    32,    33,    34,    35,    81,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      12,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      32,    33,    34,    35,    -1,    81,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    12,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    32,    33,    34,    35,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,     0,    -1,    -1,     3,     4,
       5,     6,    90,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    64,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    38,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    38,    75,
      -1,    77,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    77,    38,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    47,    48,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    75,    76,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    81,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    47,    48,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,    56,    57,    58,    59,
      -1,    61,    62,    -1,    64,    -1,    81,    67,    -1,    -1,
      -1,     3,     4,     5,     6,    75,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    38,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    75,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,     3,     4,     5,     6,
      67,     8,     9,    10,    11,    -1,    -1,    -1,    75,    38,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    -1,    -1,    -1,    56,    57,    58,
      59,    38,    61,    62,    81,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    32,    33,    34,    35,    75,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    47,    48,    -1,
      67,    -1,    -1,    -1,    -1,    55,    -1,    -1,    75,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    47,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    28,    29,    30,    31,    37,    38,
      40,    41,    56,    57,    58,    59,    61,    62,    64,    67,
      75,    80,    86,    87,    93,    94,   102,   103,   104,   105,
     106,   108,   109,   110,   111,   116,   117,   118,   119,   127,
     128,   129,   130,   132,   133,   134,   135,   143,   144,   145,
     146,   147,   148,   145,   145,    57,   137,   145,    60,   112,
     115,   146,   137,   145,    62,   112,   113,   114,   137,   145,
      57,   107,   137,    76,   137,   138,   139,   145,    77,   145,
     136,   137,   145,   145,   145,   145,   145,     0,    94,   147,
     147,    21,    64,     8,   146,    57,    57,    12,    30,    32,
      33,    34,    35,    39,    47,    48,    51,    55,    59,    60,
      61,    62,    63,    64,    65,    66,    68,    69,    70,    71,
      72,    73,    74,    81,    90,     8,    54,   148,    51,    28,
     137,   145,    51,    31,    60,    31,    60,   112,    51,    49,
      13,    51,   137,    51,    51,    76,    51,    76,    49,    77,
      78,    51,   147,   146,   145,     8,    63,   136,   137,   140,
     141,   142,   146,   137,   140,   142,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   136,   137,   145,   145,   146,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,    51,   145,
      57,   114,   146,    57,   114,    31,    96,    97,    99,   100,
     101,   111,   147,   146,   113,    51,    76,   138,   145,   145,
      57,    78,    57,   147,   145,    51,    77,    51,   126,    53,
      51,    77,    51,   126,    24,    77,   145,   114,   114,    57,
     114,    23,    24,   131,    86,    87,   111,    80,    86,    87,
      84,    95,    77,   145,   137,   140,    62,    63,   120,   121,
     122,   123,   124,   125,   146,   142,   137,   141,    77,   145,
     142,   137,    77,   145,    77,    51,   126,   126,   114,   145,
      49,    86,    80,    86,    87,    86,    98,   102,    77,    51,
      77,    51,   120,   120,    51,   126,    77,    49,    53,    51,
     126,    51,   126,   126,   126,    77,    77,   126,    49,    97,
      86,    85,   102,    63,   123,    51,   126,    51,   126,    81,
     120,   124,    49,    83,   145,   145,   146,    77,    77,    77,
      77,    77,   147,   120,    51,   126,    63,   123,    51,   126,
      97,   145,    53,    95,   126,    63,   120,    51,   126,   122,
     123,    49,   145,    24,   131,   120,   126,    63,    51,    97,
      49,   126,   120,   147,   126,    95
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    92,    93,    93,    93,    94,    95,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   103,   104,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   121,   121,   121,   122,   122,   122,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   129,   130,   131,   131,   131,   132,
     132,   132,   133,   134,   135,   135,   135,   135,   136,   136,
     137,   137,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   143,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   147,   147,   148,   148,   148
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     2,     4,
       1,     2,     4,     5,     1,     2,     4,     1,     2,     2,
       3,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     2,     1,     2,     4,     7,     4,     5,     7,
       8,     1,     1,     1,     0,     4,     3,     1,     3,     3,
       5,     4,     5,     1,     2,     3,     1,     3,     1,     4,
       5,     7,     3,     5,     6,     8,     3,     1,     0,     1,
       0,     8,    10,     2,     5,     2,     5,     9,     6,     4,
       7,     5,     1,     3,     2,     1,     2,     3,     1,     0,
       3,     1,     3,     3,     1,     1,     2,     3,     2,     3,
       1,     1,     1,     3,     4,     7,     7,     5,     4,     7,
       7,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     4,     3,     4,     3,
       2,     3,     3,     2,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     2,     1,     1,     1,     1
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
  "tuple_item", "raise_statement", "return_statement", "delete_statement",
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
       0,   273,   273,   274,   275,   279,   283,   287,   291,   292,
     296,   297,   301,   302,   303,   304,   307,   310,   316,   319,
     325,   328,   334,   335,   336,   341,   345,   349,   353,   354,
     358,   359,   360,   361,   365,   366,   367,   371,   372,   377,
     378,   379,   381,   386,   387,   388,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   405,   406,   410,   411,   412,
     416,   417,   421,   422,   428,   429,   431,   433,   435,   437,
     439,   444,   448,   457,   458,   462,   463,   467,   468,   469,
     470,   474,   476,   478,   482,   483,   485,   489,   490,   498,
     499,   500,   502,   503,   505,   507,   509,   513,   514,   518,
     519,   523,   525,   536,   540,   544,   548,   549,   551,   556,
     559,   562,   567,   571,   575,   576,   579,   582,   588,   589,
     593,   594,   604,   608,   609,   613,   614,   619,   620,   624,
     625,   630,   631,   632,   636,   637,   639,   641,   642,   643,
     645,   647,   654,   658,   659,   663,   664,   665,   669,   670,
     671,   672,   673,   674,   675,   677,   678,   679,   680,   681,
     683,   684,   688,   689,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   703,   704,   705,   706,   707,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     720,   721,   722,   729,   734,   738,   739,   743,   744,   745
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
#line 3295 "./parser.cpp"

#line 748 "parser.ypp"
