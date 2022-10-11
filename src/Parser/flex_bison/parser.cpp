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
#line 271 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1159 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 272 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1165 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 277 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1171 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 281 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1177 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 285 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1183 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 289 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1189 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 290 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1195 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 294 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1201 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 295 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1207 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 299 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1213 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 300 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1219 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 301 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1225 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 302 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1233 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 305 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1241 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 308 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1249 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 314 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1257 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 317 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1265 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 323 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1273 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 326 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1281 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 332 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1287 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 333 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1293 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 334 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1299 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 339 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1305 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 343 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1311 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 347 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1317 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 351 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1323 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 352 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1329 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 356 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1335 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 357 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1341 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 358 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1347 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 359 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1353 "./parser.cpp"
    break;

  case 34: // raise_statement: RAISE
#line 363 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1359 "./parser.cpp"
    break;

  case 35: // raise_statement: RAISE expr
#line 364 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1365 "./parser.cpp"
    break;

  case 36: // raise_statement: RAISE expr FROM expr
#line 365 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1371 "./parser.cpp"
    break;

  case 37: // return_statement: RETURN
#line 369 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1377 "./parser.cpp"
    break;

  case 38: // return_statement: RETURN tuple_item
#line 370 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1383 "./parser.cpp"
    break;

  case 39: // single_line_statement: expression_statment
#line 374 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1389 "./parser.cpp"
    break;

  case 40: // single_line_statement: tuple_statement
#line 375 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1395 "./parser.cpp"
    break;

  case 41: // single_line_statement: assert_statement
#line 376 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1401 "./parser.cpp"
    break;

  case 42: // single_line_statement: pass_statement
#line 380 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1407 "./parser.cpp"
    break;

  case 43: // single_line_statement: return_statement
#line 382 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1413 "./parser.cpp"
    break;

  case 44: // single_line_statement: raise_statement
#line 383 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1419 "./parser.cpp"
    break;

  case 45: // single_line_statement: break_statement
#line 384 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1425 "./parser.cpp"
    break;

  case 46: // single_line_statement: continue_statement
#line 385 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1431 "./parser.cpp"
    break;

  case 47: // single_line_statement: import_statement
#line 386 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1437 "./parser.cpp"
    break;

  case 48: // single_line_statement: global_statement
#line 387 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1443 "./parser.cpp"
    break;

  case 49: // single_line_statement: nonlocal_statement
#line 388 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1449 "./parser.cpp"
    break;

  case 50: // module: module "." id
#line 393 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1455 "./parser.cpp"
    break;

  case 51: // module: id
#line 394 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1461 "./parser.cpp"
    break;

  case 52: // module_as_id: module
#line 398 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1467 "./parser.cpp"
    break;

  case 53: // module_as_id: module AS id
#line 399 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1473 "./parser.cpp"
    break;

  case 54: // module_as_id: "*"
#line 400 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1479 "./parser.cpp"
    break;

  case 55: // module_item_list: module_item_list "," module_as_id
#line 404 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1485 "./parser.cpp"
    break;

  case 56: // module_item_list: module_as_id
#line 405 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1491 "./parser.cpp"
    break;

  case 57: // dot_list: dot_list "."
#line 409 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1497 "./parser.cpp"
    break;

  case 58: // dot_list: "."
#line 410 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1503 "./parser.cpp"
    break;

  case 59: // import_statement: IMPORT module_item_list
#line 416 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1509 "./parser.cpp"
    break;

  case 60: // import_statement: FROM module IMPORT module_item_list
#line 417 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1516 "./parser.cpp"
    break;

  case 61: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 419 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1523 "./parser.cpp"
    break;

  case 62: // import_statement: FROM dot_list IMPORT module_item_list
#line 421 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1530 "./parser.cpp"
    break;

  case 63: // import_statement: FROM dot_list module IMPORT module_item_list
#line 423 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1537 "./parser.cpp"
    break;

  case 64: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 425 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1544 "./parser.cpp"
    break;

  case 65: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 427 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1551 "./parser.cpp"
    break;

  case 66: // multi_line_statement: if_statement
#line 432 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1557 "./parser.cpp"
    break;

  case 67: // multi_line_statement: function_def
#line 436 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1563 "./parser.cpp"
    break;

  case 68: // decorators_opt: decorators
#line 445 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1569 "./parser.cpp"
    break;

  case 69: // decorators_opt: %empty
#line 446 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1575 "./parser.cpp"
    break;

  case 70: // decorators: decorators "@" expr sep
#line 450 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1581 "./parser.cpp"
    break;

  case 71: // decorators: "@" expr sep
#line 451 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1587 "./parser.cpp"
    break;

  case 72: // parameter: id
#line 455 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1593 "./parser.cpp"
    break;

  case 73: // parameter: id ":" expr
#line 456 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1599 "./parser.cpp"
    break;

  case 74: // parameter: id "=" expr
#line 457 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1605 "./parser.cpp"
    break;

  case 75: // parameter: id ":" expr "=" expr
#line 458 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1611 "./parser.cpp"
    break;

  case 76: // parameter_list: defparameter_list "," "/" comma_opt
#line 462 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1618 "./parser.cpp"
    break;

  case 77: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 464 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1625 "./parser.cpp"
    break;

  case 78: // parameter_list: parameter_list_no_posonly
#line 466 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1631 "./parser.cpp"
    break;

  case 79: // parameter_list_no_posonly: defparameter_list comma_opt
#line 470 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1637 "./parser.cpp"
    break;

  case 80: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 471 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1644 "./parser.cpp"
    break;

  case 81: // parameter_list_no_posonly: parameter_list_starargs
#line 473 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1650 "./parser.cpp"
    break;

  case 82: // defparameter_list: defparameter_list "," parameter
#line 477 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1656 "./parser.cpp"
    break;

  case 83: // defparameter_list: parameter
#line 478 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1662 "./parser.cpp"
    break;

  case 84: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 486 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1668 "./parser.cpp"
    break;

  case 85: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 487 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1674 "./parser.cpp"
    break;

  case 86: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 488 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1681 "./parser.cpp"
    break;

  case 87: // parameter_list_starargs: "*" parameter comma_opt
#line 490 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1687 "./parser.cpp"
    break;

  case 88: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 491 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1694 "./parser.cpp"
    break;

  case 89: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 493 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1701 "./parser.cpp"
    break;

  case 90: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 495 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1708 "./parser.cpp"
    break;

  case 91: // parameter_list_starargs: "**" parameter comma_opt
#line 497 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1714 "./parser.cpp"
    break;

  case 92: // parameter_list_opt: parameter_list
#line 501 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1720 "./parser.cpp"
    break;

  case 93: // parameter_list_opt: %empty
#line 502 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1726 "./parser.cpp"
    break;

  case 96: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 512 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1732 "./parser.cpp"
    break;

  case 97: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 514 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1738 "./parser.cpp"
    break;

  case 98: // global_statement: GLOBAL expr_list
#line 524 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1744 "./parser.cpp"
    break;

  case 99: // ternary_if_statement: expr IF expr ELSE expr
#line 528 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1750 "./parser.cpp"
    break;

  case 100: // nonlocal_statement: NONLOCAL expr_list
#line 532 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1756 "./parser.cpp"
    break;

  case 101: // if_statement: IF expr ":" body_stmts
#line 536 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1764 "./parser.cpp"
    break;

  case 102: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 539 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1772 "./parser.cpp"
    break;

  case 103: // expression_statment: expr
#line 547 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1778 "./parser.cpp"
    break;

  case 104: // tuple_statement: expr "," expr_list_opt
#line 551 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = TUPLE_STMT(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1784 "./parser.cpp"
    break;

  case 105: // string: string string_literal
#line 555 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1790 "./parser.cpp"
    break;

  case 106: // string: string_literal
#line 556 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1798 "./parser.cpp"
    break;

  case 107: // string: id string_literal
#line 559 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1806 "./parser.cpp"
    break;

  case 108: // string: string id string_literal
#line 562 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1814 "./parser.cpp"
    break;

  case 109: // expr_list_opt: expr_list
#line 568 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1820 "./parser.cpp"
    break;

  case 110: // expr_list_opt: %empty
#line 569 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1826 "./parser.cpp"
    break;

  case 111: // expr_list: expr_list "," expr
#line 573 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1832 "./parser.cpp"
    break;

  case 112: // expr_list: expr
#line 574 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1838 "./parser.cpp"
    break;

  case 113: // dict: expr ":" expr
#line 584 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1844 "./parser.cpp"
    break;

  case 114: // dict_list: dict_list "," dict
#line 588 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1850 "./parser.cpp"
    break;

  case 115: // dict_list: dict
#line 589 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1856 "./parser.cpp"
    break;

  case 116: // call_arguement_list: expr_list_opt
#line 593 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1862 "./parser.cpp"
    break;

  case 117: // call_arguement_list: expr_list ","
#line 594 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1868 "./parser.cpp"
    break;

  case 118: // keyword_item: id "=" expr
#line 599 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1874 "./parser.cpp"
    break;

  case 119: // keyword_item: "**" expr
#line 600 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1880 "./parser.cpp"
    break;

  case 120: // keyword_items: keyword_items "," keyword_item
#line 604 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1886 "./parser.cpp"
    break;

  case 121: // keyword_items: keyword_item
#line 605 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1892 "./parser.cpp"
    break;

  case 122: // primary: id
#line 610 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1898 "./parser.cpp"
    break;

  case 123: // primary: string
#line 611 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1904 "./parser.cpp"
    break;

  case 124: // primary: expr "." id
#line 612 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1910 "./parser.cpp"
    break;

  case 125: // function_call: primary "(" call_arguement_list ")"
#line 616 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1916 "./parser.cpp"
    break;

  case 126: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 617 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1923 "./parser.cpp"
    break;

  case 127: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 619 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1930 "./parser.cpp"
    break;

  case 128: // function_call: primary "(" keyword_items comma_opt ")"
#line 621 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1936 "./parser.cpp"
    break;

  case 129: // function_call: function_call "(" call_arguement_list ")"
#line 622 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1942 "./parser.cpp"
    break;

  case 130: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 623 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1949 "./parser.cpp"
    break;

  case 131: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 625 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1956 "./parser.cpp"
    break;

  case 132: // function_call: function_call "(" keyword_items comma_opt ")"
#line 627 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 1962 "./parser.cpp"
    break;

  case 133: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 634 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1968 "./parser.cpp"
    break;

  case 134: // expr: id
#line 638 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1974 "./parser.cpp"
    break;

  case 135: // expr: integer_literal
#line 639 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 1983 "./parser.cpp"
    break;

  case 136: // expr: string
#line 643 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1989 "./parser.cpp"
    break;

  case 137: // expr: real_literal
#line 644 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 1995 "./parser.cpp"
    break;

  case 138: // expr: image_literal
#line 645 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2004 "./parser.cpp"
    break;

  case 139: // expr: TRUE
#line 649 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2010 "./parser.cpp"
    break;

  case 140: // expr: FALSE
#line 650 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2016 "./parser.cpp"
    break;

  case 141: // expr: NONE
#line 651 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2022 "./parser.cpp"
    break;

  case 142: // expr: "..."
#line 652 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2028 "./parser.cpp"
    break;

  case 143: // expr: "(" expr ")"
#line 653 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2034 "./parser.cpp"
    break;

  case 144: // expr: "(" ")"
#line 654 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2040 "./parser.cpp"
    break;

  case 145: // expr: function_call
#line 655 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2046 "./parser.cpp"
    break;

  case 146: // expr: "[" expr_list_opt "]"
#line 657 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2052 "./parser.cpp"
    break;

  case 147: // expr: "[" expr_list "," "]"
#line 658 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2058 "./parser.cpp"
    break;

  case 148: // expr: "{" expr_list "}"
#line 659 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2064 "./parser.cpp"
    break;

  case 149: // expr: "{" expr_list "," "}"
#line 660 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2070 "./parser.cpp"
    break;

  case 150: // expr: expr "." id
#line 661 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2076 "./parser.cpp"
    break;

  case 151: // expr: "{" "}"
#line 663 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2082 "./parser.cpp"
    break;

  case 152: // expr: "{" dict_list "}"
#line 664 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2088 "./parser.cpp"
    break;

  case 153: // expr: id ":=" expr
#line 668 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2094 "./parser.cpp"
    break;

  case 154: // expr: "*" expr
#line 669 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2100 "./parser.cpp"
    break;

  case 155: // expr: expr "+" expr
#line 671 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2106 "./parser.cpp"
    break;

  case 156: // expr: expr "-" expr
#line 672 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2112 "./parser.cpp"
    break;

  case 157: // expr: expr "*" expr
#line 673 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2118 "./parser.cpp"
    break;

  case 158: // expr: expr "/" expr
#line 674 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2124 "./parser.cpp"
    break;

  case 159: // expr: expr "%" expr
#line 675 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2130 "./parser.cpp"
    break;

  case 160: // expr: "-" expr
#line 676 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2136 "./parser.cpp"
    break;

  case 161: // expr: "+" expr
#line 677 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2142 "./parser.cpp"
    break;

  case 162: // expr: "~" expr
#line 678 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2148 "./parser.cpp"
    break;

  case 163: // expr: expr "**" expr
#line 679 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2154 "./parser.cpp"
    break;

  case 164: // expr: expr "//" expr
#line 680 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2160 "./parser.cpp"
    break;

  case 165: // expr: expr "@" expr
#line 681 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2166 "./parser.cpp"
    break;

  case 166: // expr: expr "&" expr
#line 683 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2172 "./parser.cpp"
    break;

  case 167: // expr: expr "|" expr
#line 684 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2178 "./parser.cpp"
    break;

  case 168: // expr: expr "^" expr
#line 685 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2184 "./parser.cpp"
    break;

  case 169: // expr: expr "<<" expr
#line 686 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2190 "./parser.cpp"
    break;

  case 170: // expr: expr ">>" expr
#line 687 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2196 "./parser.cpp"
    break;

  case 171: // expr: expr "==" expr
#line 689 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2202 "./parser.cpp"
    break;

  case 172: // expr: expr "!=" expr
#line 690 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2208 "./parser.cpp"
    break;

  case 173: // expr: expr "<" expr
#line 691 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2214 "./parser.cpp"
    break;

  case 174: // expr: expr "<=" expr
#line 692 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2220 "./parser.cpp"
    break;

  case 175: // expr: expr ">" expr
#line 693 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2226 "./parser.cpp"
    break;

  case 176: // expr: expr ">=" expr
#line 694 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2232 "./parser.cpp"
    break;

  case 177: // expr: expr "is" expr
#line 695 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2238 "./parser.cpp"
    break;

  case 178: // expr: expr "is not" expr
#line 696 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2244 "./parser.cpp"
    break;

  case 179: // expr: expr "in" expr
#line 697 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2250 "./parser.cpp"
    break;

  case 180: // expr: expr "not in" expr
#line 698 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2256 "./parser.cpp"
    break;

  case 181: // expr: expr "and" expr
#line 700 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2262 "./parser.cpp"
    break;

  case 182: // expr: expr "or" expr
#line 701 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2268 "./parser.cpp"
    break;

  case 183: // expr: "not" expr
#line 702 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2274 "./parser.cpp"
    break;

  case 184: // expr: ternary_if_statement
#line 709 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2280 "./parser.cpp"
    break;

  case 185: // id: identifier
#line 714 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2286 "./parser.cpp"
    break;

  case 186: // sep: sep sep_one
#line 718 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2292 "./parser.cpp"
    break;

  case 187: // sep: sep_one
#line 719 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2298 "./parser.cpp"
    break;

  case 188: // sep_one: NEWLINE
#line 723 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2304 "./parser.cpp"
    break;

  case 189: // sep_one: COMMENT
#line 724 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2310 "./parser.cpp"
    break;

  case 190: // sep_one: ";"
#line 725 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2316 "./parser.cpp"
    break;


#line 2320 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -276;

  const signed char  Parser ::yytable_ninf_ = -125;

  const short
   Parser ::yypact_[] =
  {
     471,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  1674,
    1674,  -276,  -276,    24,  1674,  1674,    39,  1674,  1674,  -276,
    1712,   189,   544,  1674,  1674,  1674,  1674,  1674,  1674,  -276,
    -276,  -276,  -276,  1418,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,    99,  -276,    99,    23,   -18,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,    55,    12,    33,   743,   172,    99,
    -276,   788,   851,  -276,    10,   143,  -276,    20,  1247,   896,
    -276,    19,  -276,    95,    20,  1729,   544,  -276,   100,  -276,
      -9,  -276,    -8,   941,  -276,   986,   -27,   103,    -6,    -6,
      -6,   680,    -6,  -276,  -276,    99,    99,    74,  1674,  -276,
      73,  1638,  1638,  1674,  1674,  1674,  1674,  1674,  1674,  1674,
    1674,  1674,  1674,  1674,  1674,    74,  1674,  1674,  1674,  1674,
    1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,  1674,
    1674,  -276,  1674,  -276,  1674,  1674,   109,    74,   125,  -276,
      18,  1674,   556,    74,    39,   106,   986,  1674,  1457,  -276,
    1674,  -276,  1674,   108,  -276,   330,    99,   110,   680,  -276,
    1674,  -276,   132,   104,  -276,   145,   155,   150,   134,   164,
    1729,  1049,   376,   376,   376,   376,  1335,  1515,  1439,  -276,
      20,   376,   208,   166,   208,    -6,    -6,    -6,    -6,    -6,
     456,   811,   811,   376,   376,   376,   376,    -6,   376,  1291,
    1247,  1247,    39,    95,  -276,    39,    95,   127,  1247,  -276,
     197,  -276,    75,  1599,   130,   -28,  -276,  -276,   629,  -276,
    -276,   941,  1247,  1674,  -276,    29,    99,  1247,  1638,  -276,
    1638,   153,  1674,  1638,  -276,  1638,   154,  1674,   184,   184,
      39,    95,   187,  -276,   157,   159,    86,  -276,   167,  1531,
    -276,  -276,  1094,   190,   163,   139,    74,  -276,  -276,  -276,
     204,  -276,   181,    13,   218,   227,  -276,  -276,  1247,   218,
     227,  -276,  1291,    39,   203,   205,   184,   556,  -276,    89,
    -276,   195,  -276,   641,  -276,  -276,  1674,  -276,    11,   233,
     234,     2,  -276,   -30,  1674,  1674,    14,   210,  1674,   211,
     213,   214,  -276,  -276,   215,  -276,  -276,  -276,  -276,    74,
     242,    25,  -276,  -276,  -276,   245,  -276,  -276,   556,  1674,
    1157,  1247,   244,  -276,  -276,  -276,  -276,  -276,   234,    30,
    -276,    74,   248,    29,  -276,  -276,  1202,  1674,  -276,    74,
     234,    31,  -276,  -276,   249,   556,  1247,   234,  -276,    74,
      29,  -276,  -276,   234,  -276
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      69,   135,   137,   138,   185,   106,   140,   139,   141,     0,
      34,    26,    27,     0,     0,     0,     0,     0,     0,    25,
      37,     0,     0,   110,     0,     0,     0,     0,     0,   142,
     190,   188,   189,    69,     3,     5,    42,    45,    46,    41,
      44,    43,     0,    47,    23,     0,    68,    67,    48,   184,
      49,    66,    39,    40,   136,     0,   145,   103,   134,     4,
     187,    28,    35,    58,     0,     0,    51,    98,   112,     0,
      54,    52,    56,    59,   100,   183,     0,    38,    30,   151,
       0,   115,     0,   112,   144,     0,     0,   109,   160,   161,
     154,     0,   162,     1,     2,    22,    24,     0,     0,   105,
       0,   110,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,   186,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,   112,    31,     0,   148,
       0,   152,     0,   143,   146,     0,    71,     0,     0,   108,
       0,   116,   109,     0,   121,    95,   134,   109,     0,    95,
     181,     0,   179,   177,   178,   180,   182,   166,   168,   104,
     109,   171,   156,   150,   155,   157,   163,   165,   164,   159,
     167,   169,   170,   173,   174,   175,   176,   158,   172,   153,
      29,    36,     0,    60,    50,     0,    62,     0,   111,     9,
     101,     8,     0,     0,     0,     0,    53,    55,     0,   149,
     114,     0,   113,   110,   147,    93,    70,   119,   117,   125,
      94,     0,     0,   117,   129,    94,     0,     0,    95,    95,
       0,    63,     0,    12,     0,    18,    21,    14,     0,    69,
       7,    32,   111,   109,     0,     0,     0,    83,    92,    78,
      95,    81,     0,    72,    95,    95,   120,   128,   118,    95,
      95,   132,    99,    94,     0,     0,    95,     0,    13,    20,
      15,     0,    17,    69,    11,    33,   117,   133,     0,    95,
      95,    94,    79,     0,     0,     0,    94,     0,    94,     0,
       0,     0,    61,    64,     0,   102,    16,     6,    10,     0,
      95,    94,    87,    94,    91,    95,    82,    80,     0,     0,
      73,    74,     0,   126,   127,   130,   131,    65,    95,    94,
      84,     0,    95,    94,    76,    96,     0,     0,    85,     0,
      95,    94,    88,    77,    95,     0,    75,    95,    89,     0,
      94,    97,    86,    95,    90
  };

  const short
   Parser ::yypgoto_[] =
  {
    -276,  -276,   270,  -276,  -276,  -263,  -276,  -276,  -276,  -276,
    -211,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -140,    34,
    -133,   -49,  -276,  -276,  -276,  -276,  -276,   -87,  -276,   -29,
     -54,  -275,  -276,    37,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,   -10,   -16,   158,  -276,   -79,  -201,   -90,  -276,
    -276,     0,   123,     6,   -56
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    33,    34,   250,   209,   210,   283,   211,   212,   213,
      35,    36,    37,    38,    39,    77,    40,    41,    42,    71,
      72,    73,    65,    43,    44,    45,    46,   257,   258,   259,
     260,   261,   262,   292,    47,    48,    49,    50,    51,    52,
      53,    54,   161,    67,    81,    82,   163,   164,   165,    55,
      56,    68,    58,   215,    60
  };

  const short
   Parser ::yytable_[] =
  {
      57,    74,   214,   133,    78,    80,    59,    87,     4,    61,
      62,   217,   169,    86,   305,    69,   317,     4,    75,   318,
       4,    83,    85,   168,    88,    89,    90,    91,    92,   266,
       4,     4,   143,    57,   266,     4,     4,     4,   284,   133,
     133,   136,   148,   150,    97,     4,    98,    64,    95,   207,
      96,   154,    30,   319,   115,   335,   249,   118,    31,    32,
     145,     4,   294,    99,   255,   256,   295,   149,   151,   101,
     137,   141,   308,   245,   309,   317,   146,   160,   137,   137,
       4,   159,   351,   315,    63,   162,   167,   203,   331,   206,
     102,   255,   256,   339,   349,   266,   180,   156,   158,   140,
     133,    70,   179,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  -123,   181,   182,     4,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     4,   199,     4,   200,   201,    66,   214,   264,    66,
     217,   208,    57,   269,   254,     4,   144,   208,   208,     4,
     221,   147,   222,   238,   155,   208,   239,   218,   241,   133,
     227,   243,   244,   131,   226,   223,   202,   225,   289,   290,
     133,    70,   280,   281,   138,   -19,   -19,   100,   214,    30,
     131,   229,   205,   228,   240,    31,    32,    70,    66,    70,
     288,   276,     1,     2,     3,     4,   230,     5,     6,     7,
       8,   233,   231,   139,   316,   214,   236,   253,   232,   132,
     246,   234,  -122,    57,   265,   235,   247,   248,   252,   270,
     157,   242,   328,  -124,   166,   166,   132,    18,   208,  -122,
     267,   271,   268,   208,   310,   273,   277,   272,   183,   279,
     287,   286,   316,   278,   340,    21,    22,    23,    24,    57,
      25,    26,   347,   282,   316,   291,    28,   332,   293,    66,
     204,    66,   353,   316,    29,    79,   216,    66,   115,   296,
     117,   118,   119,   120,   121,   274,   275,    57,   298,   344,
     302,   306,   303,    57,   311,   313,   208,   323,   324,   129,
     325,   326,   327,   329,   320,   321,   333,   232,   208,   341,
     350,   297,   299,    94,   343,     0,   300,   301,   220,     0,
       0,     0,     0,   304,     0,     0,     0,     0,    57,   336,
       0,     0,     0,     0,     0,    66,   312,   314,    66,     0,
      66,     0,     0,     1,     2,     3,     4,   346,     5,     6,
       7,     8,     0,     0,     0,    57,     0,   330,   263,     0,
       0,   166,   334,   166,     0,     0,   166,     0,   166,     0,
       0,     0,     0,    66,     0,   338,     0,     0,    18,   342,
       0,     0,     0,     0,     0,     0,     0,   348,   263,   263,
       0,     0,     0,     0,   352,     0,    21,    22,    23,    24,
     354,    25,    26,     0,     0,     0,    66,    28,     0,     0,
       0,     0,     0,     0,     0,    29,     0,     0,   224,     0,
       0,   263,     0,     0,   263,     0,     0,     0,     0,   322,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
       0,     0,   263,     0,   263,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,     0,     0,     0,
       0,     0,   263,     0,   263,     0,   263,   129,     0,     0,
       0,     0,   263,     0,   263,     0,     0,     0,     0,     0,
       0,     0,   263,   263,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,   110,   111,     0,     0,     0,    17,    18,
       0,    19,    20,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,   123,   124,    21,    22,    23,
      24,     0,    25,    26,     0,    27,     0,   129,    28,     0,
       0,     0,     0,     0,     0,     0,    29,     1,     2,     3,
       4,    30,     5,     6,     7,     8,     0,    31,    32,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       9,    10,     0,     0,    11,     0,    12,     0,     0,     0,
       0,     0,    18,     0,    13,    14,     0,    16,     0,     0,
       0,     0,     0,    17,    18,     0,    19,    20,     0,     0,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
       0,    28,    21,    22,    23,    24,     0,    25,    26,    29,
       0,    84,     0,    28,     0,     0,     0,     0,     0,     0,
       0,    29,     1,     2,     3,     4,    30,     5,     6,     7,
       8,     0,    31,    32,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,     0,     0,     0,     0,    18,     0,    13,
      14,    15,    16,     0,     0,     0,     0,     0,    17,    18,
       0,    19,    20,     0,     0,    21,    22,    23,    24,     0,
      25,    26,   103,     0,     0,     0,    28,    21,    22,    23,
      24,     0,    25,    26,    29,    27,   251,     0,    28,     0,
     104,     0,   105,   106,   107,   108,    29,     0,     0,   109,
       0,     0,     0,     0,     0,     0,   307,   110,   111,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   103,     0,     0,     0,     0,
      30,   129,     0,     0,     0,     0,    31,    32,     0,     0,
     130,     0,     0,   104,     0,   105,   106,   107,   108,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
     110,   111,     0,     0,   112,     0,     0,     0,   113,     0,
     103,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,   123,   124,   125,   126,   127,   128,   104,     0,
     105,   106,   107,   108,   129,     0,     0,   109,     0,     0,
       0,     0,     0,   130,     0,   110,   111,     0,     0,   134,
       0,     0,     0,   113,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   125,
     126,   127,   128,   103,     0,     0,     0,     0,     0,   129,
     114,   115,   116,   117,   118,   119,   120,   121,   130,   135,
       0,   104,     0,   105,   106,   107,   108,     0,     0,     0,
     109,     0,   129,     0,     0,     0,     0,     0,   110,   111,
       0,     0,     0,     0,     0,     0,   113,     0,   103,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   104,     0,   105,   106,
     107,   108,   129,     0,     0,   109,     0,     0,     0,     0,
       0,   130,     0,   110,   111,   142,     0,     0,     0,     0,
       0,   113,     0,   103,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   104,     0,   105,   106,   107,   108,   129,     0,     0,
     109,     0,     0,     0,     0,     0,   130,     0,   110,   111,
     152,     0,     0,     0,     0,     0,   113,     0,   103,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   104,     0,   105,   106,
     107,   108,   129,     0,     0,   109,     0,     0,     0,     0,
       0,   130,     0,   110,   111,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,   125,   126,   127,
     128,   103,     0,   153,     0,     0,     0,   129,     0,     0,
       0,     0,     0,   237,     0,     0,   130,     0,     0,   104,
       0,   105,   106,   107,   108,     0,     0,     0,   109,     0,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,     0,     0,     0,   113,     0,   103,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,   104,     0,   105,   106,   107,   108,
     129,     0,     0,   109,     0,     0,     0,     0,     0,   130,
       0,   110,   111,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   103,
       0,   285,     0,     0,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,   104,     0,   105,
     106,   107,   108,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,   110,   111,     0,     0,     0,     0,
     337,     0,   113,     0,   103,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,   104,     0,   105,   106,   107,   108,   129,     0,
       0,   109,     0,     0,     0,     0,     0,   130,     0,   110,
     111,   345,     0,     0,     0,     0,     0,   113,     0,   103,
       0,   114,   115,   116,   117,   118,   119,   120,   121,     0,
     122,   123,   124,   125,   126,   127,   128,   104,     0,   105,
     106,   107,   108,   129,     0,     0,   109,     0,     0,     0,
       0,     0,   130,     0,   110,   111,     0,     0,     0,     0,
       0,     0,   113,   103,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   125,   126,
     127,   128,     0,   105,   106,   107,   108,     0,   129,     0,
     109,     0,     0,     0,     0,     0,     0,   130,   110,   111,
       0,     0,     0,     0,     0,     0,   113,   103,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,     0,   105,   106,   107,
     108,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   110,   111,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,   122,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,    93,     0,
       0,     1,     2,     3,     4,   130,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,    16,
       0,     0,     0,     0,     0,    17,    18,     0,    19,    20,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,    21,    22,    23,    24,     0,    25,
      26,     0,    27,     0,     0,    28,   110,     0,     0,     0,
       0,     0,     0,    29,     0,    18,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,   123,   124,
       0,     0,     0,    21,    22,    23,    24,     0,    25,    26,
     129,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,    29,   219,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,     0,     0,     0,     0,     0,    17,    18,
       0,    19,    20,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,   123,   124,     0,    21,    22,    23,
      24,     0,    25,    26,     0,    27,   129,     0,    28,     0,
       0,     0,     1,     2,     3,     4,    29,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
      16,     0,     0,     0,     0,     0,    17,    18,     0,    19,
      20,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     0,     0,     0,    21,    22,    23,    24,     0,
      25,    26,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    18,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    22,    23,    24,     0,    25,
      26,   160,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,    18,    29,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
      21,    22,    23,    24,     0,    25,    26,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,     0,    29,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,     0,     0,     0,    21,    76,
      23,    24,     0,    25,    26,     0,   110,   111,     0,    28,
       0,     0,     0,     0,   113,     0,     0,    29,   114,   115,
     116,   117,   118,   119,   120,   121,     0,   122,   123,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,   130
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    17,   142,    59,    20,    21,     0,    23,     6,     9,
      10,   144,   102,    23,   277,    15,   291,     6,    18,    49,
       6,    21,    22,   102,    24,    25,    26,    27,    28,   230,
       6,     6,    13,    33,   235,     6,     6,     6,   249,    95,
      96,    31,    51,    51,    21,     6,    64,    13,    42,    31,
      44,    78,    80,    83,    60,   318,    84,    63,    86,    87,
      76,     6,    49,     8,    62,    63,    53,    76,    76,    57,
      60,    51,   283,   213,    63,   350,    76,    63,    60,    60,
       6,     8,   345,    81,    60,   101,   102,   136,    63,   138,
      57,    62,    63,    63,    63,   296,   112,    91,    98,    65,
     156,    62,   112,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    57,   113,   114,     6,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     6,   132,     6,   134,   135,    13,   277,   228,    16,
     273,   141,   142,   233,   223,     6,    51,   147,   148,     6,
     150,    51,   152,   202,    51,   155,   205,    51,   207,   215,
     160,    86,    87,     8,   158,    57,    57,    57,   255,   256,
     226,    62,    86,    87,    31,    86,    87,    54,   318,    80,
       8,    77,    57,    51,    57,    86,    87,    62,    65,    62,
      51,   240,     3,     4,     5,     6,    51,     8,     9,    10,
      11,    51,   165,    60,   291,   345,   169,   223,    53,    54,
      80,    77,    57,   213,   230,    51,    86,    87,   218,   235,
      97,    24,   309,    57,   101,   102,    54,    38,   228,    57,
      77,    77,   232,   233,   288,    51,    49,   237,   115,    80,
      77,    51,   329,    86,   331,    56,    57,    58,    59,   249,
      61,    62,   339,    86,   341,    51,    67,   311,    77,   136,
     137,   138,   349,   350,    75,    76,   143,   144,    60,    51,
      62,    63,    64,    65,    66,   238,   239,   277,    51,   333,
      77,    86,    77,   283,    51,    51,   286,    77,    77,    81,
      77,    77,    77,    51,   294,   295,    51,    53,   298,    51,
      51,   264,   265,    33,   333,    -1,   269,   270,   150,    -1,
      -1,    -1,    -1,   276,    -1,    -1,    -1,    -1,   318,   319,
      -1,    -1,    -1,    -1,    -1,   202,   289,   290,   205,    -1,
     207,    -1,    -1,     3,     4,     5,     6,   337,     8,     9,
      10,    11,    -1,    -1,    -1,   345,    -1,   310,   225,    -1,
      -1,   228,   315,   230,    -1,    -1,   233,    -1,   235,    -1,
      -1,    -1,    -1,   240,    -1,   328,    -1,    -1,    38,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,   255,   256,
      -1,    -1,    -1,    -1,   347,    -1,    56,    57,    58,    59,
     353,    61,    62,    -1,    -1,    -1,   273,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,   288,    -1,    -1,   291,    -1,    -1,    -1,    -1,   296,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   309,    -1,   311,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,   329,    -1,   331,    -1,   333,    81,    -1,    -1,
      -1,    -1,   339,    -1,   341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   349,   350,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    47,    48,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    69,    70,    56,    57,    58,
      59,    -1,    61,    62,    -1,    64,    -1,    81,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,     3,     4,     5,
       6,    80,     8,     9,    10,    11,    -1,    86,    87,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    56,    57,    58,    59,    -1,    61,    62,    75,
      -1,    77,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,     3,     4,     5,     6,    80,     8,     9,    10,
      11,    -1,    86,    87,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    38,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    12,    -1,    -1,    -1,    67,    56,    57,    58,
      59,    -1,    61,    62,    75,    64,    77,    -1,    67,    -1,
      30,    -1,    32,    33,    34,    35,    75,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    12,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    -1,    -1,    86,    87,    -1,    -1,
      90,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,
      12,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    12,    -1,    -1,    -1,    -1,    -1,    81,
      59,    60,    61,    62,    63,    64,    65,    66,    90,    28,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    81,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    12,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    90,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    12,
      -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    12,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    32,    33,    34,    35,    -1,    81,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    90,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    12,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    32,    33,    34,
      35,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,     0,    -1,
      -1,     3,     4,     5,     6,    90,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    64,    -1,    -1,    67,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    38,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    70,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      81,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    64,    81,    -1,    67,    -1,
      -1,    -1,     3,     4,     5,     6,    75,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    38,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    75,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    47,    48,    -1,    67,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    75,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    28,    29,    30,    31,    37,    38,    40,
      41,    56,    57,    58,    59,    61,    62,    64,    67,    75,
      80,    86,    87,    93,    94,   102,   103,   104,   105,   106,
     108,   109,   110,   115,   116,   117,   118,   126,   127,   128,
     129,   130,   131,   132,   133,   141,   142,   143,   144,   145,
     146,   143,   143,    60,   111,   114,   144,   135,   143,   143,
      62,   111,   112,   113,   135,   143,    57,   107,   135,    76,
     135,   136,   137,   143,    77,   143,   134,   135,   143,   143,
     143,   143,   143,     0,    94,   145,   145,    21,    64,     8,
     144,    57,    57,    12,    30,    32,    33,    34,    35,    39,
      47,    48,    51,    55,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    81,
      90,     8,    54,   146,    51,    28,    31,    60,    31,    60,
     111,    51,    49,    13,    51,   135,   143,    51,    51,    76,
      51,    76,    49,    77,    78,    51,   145,   144,   143,     8,
      63,   134,   135,   138,   139,   140,   144,   135,   138,   140,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   134,
     135,   143,   143,   144,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,    57,   113,   144,    57,   113,    31,   143,    96,
      97,    99,   100,   101,   110,   145,   144,   112,    51,    76,
     136,   143,   143,    57,    78,    57,   145,   143,    51,    77,
      51,   125,    53,    51,    77,    51,   125,    24,   113,   113,
      57,   113,    24,    86,    87,   110,    80,    86,    87,    84,
      95,    77,   143,   135,   138,    62,    63,   119,   120,   121,
     122,   123,   124,   144,   140,   135,   139,    77,   143,   140,
     135,    77,   143,    51,   125,   125,   113,    49,    86,    80,
      86,    87,    86,    98,   102,    77,    51,    77,    51,   119,
     119,    51,   125,    77,    49,    53,    51,   125,    51,   125,
     125,   125,    77,    77,   125,    97,    86,    85,   102,    63,
     122,    51,   125,    51,   125,    81,   119,   123,    49,    83,
     143,   143,   144,    77,    77,    77,    77,    77,   119,    51,
     125,    63,   122,    51,   125,    97,   143,    53,   125,    63,
     119,    51,   125,   121,   122,    49,   143,   119,   125,    63,
      51,    97,   125,   119,   125
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
     129,   130,   130,   131,   132,   133,   133,   133,   133,   134,
     134,   135,   135,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   141,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   144,   145,   145,   146,   146,
     146
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
       2,     4,     7,     1,     3,     2,     1,     2,     3,     1,
       0,     3,     1,     3,     3,     1,     1,     2,     3,     2,
       3,     1,     1,     1,     3,     4,     7,     7,     5,     4,
       7,     7,     5,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     3,     4,     3,     4,
       3,     2,     3,     3,     2,     3,     3,     3,     3,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     2,     1,     1,     1,
       1
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
  "nonlocal_statement", "if_statement", "expression_statment",
  "tuple_statement", "string", "expr_list_opt", "expr_list", "dict",
  "dict_list", "call_arguement_list", "keyword_item", "keyword_items",
  "primary", "function_call", "expr", "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   271,   271,   272,   273,   277,   281,   285,   289,   290,
     294,   295,   299,   300,   301,   302,   305,   308,   314,   317,
     323,   326,   332,   333,   334,   339,   343,   347,   351,   352,
     356,   357,   358,   359,   363,   364,   365,   369,   370,   374,
     375,   376,   380,   382,   383,   384,   385,   386,   387,   388,
     393,   394,   398,   399,   400,   404,   405,   409,   410,   416,
     417,   419,   421,   423,   425,   427,   432,   436,   445,   446,
     450,   451,   455,   456,   457,   458,   462,   464,   466,   470,
     471,   473,   477,   478,   486,   487,   488,   490,   491,   493,
     495,   497,   501,   502,   506,   507,   511,   513,   524,   528,
     532,   536,   539,   547,   551,   555,   556,   559,   562,   568,
     569,   573,   574,   584,   588,   589,   593,   594,   599,   600,
     604,   605,   610,   611,   612,   616,   617,   619,   621,   622,
     623,   625,   627,   634,   638,   639,   643,   644,   645,   649,
     650,   651,   652,   653,   654,   655,   657,   658,   659,   660,
     661,   663,   664,   668,   669,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   683,   684,   685,   686,
     687,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   700,   701,   702,   709,   714,   718,   719,   723,   724,
     725
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
#line 3181 "./parser.cpp"

#line 728 "parser.ypp"
