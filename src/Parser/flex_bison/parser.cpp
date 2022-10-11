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
      case symbol_kind::S_assignment_statement: // assignment_statement
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
      case symbol_kind::S_target_list: // target_list
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
      case symbol_kind::S_assignment_statement: // assignment_statement
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
      case symbol_kind::S_target_list: // target_list
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
      case symbol_kind::S_assignment_statement: // assignment_statement
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
      case symbol_kind::S_target_list: // target_list
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
      case symbol_kind::S_assignment_statement: // assignment_statement
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
      case symbol_kind::S_target_list: // target_list
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
      case symbol_kind::S_assignment_statement: // assignment_statement
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
      case symbol_kind::S_target_list: // target_list
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
#line 275 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1174 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 276 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1180 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 281 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1186 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 285 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1192 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 289 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1198 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 293 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1204 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 294 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1210 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 298 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1216 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 299 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1222 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 303 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1228 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 304 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1234 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 305 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1240 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 306 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1248 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 309 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1256 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 312 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1264 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 318 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1272 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 321 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1280 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 327 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1288 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 330 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1296 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 336 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1302 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 337 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1308 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 338 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1314 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 343 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1320 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 347 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1326 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 351 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1332 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 355 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1338 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 356 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1344 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 360 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1350 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 361 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1356 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 362 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1362 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 363 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1368 "./parser.cpp"
    break;

  case 34: // raise_statement: RAISE
#line 367 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1374 "./parser.cpp"
    break;

  case 35: // raise_statement: RAISE expr
#line 368 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1380 "./parser.cpp"
    break;

  case 36: // raise_statement: RAISE expr FROM expr
#line 369 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1386 "./parser.cpp"
    break;

  case 37: // return_statement: RETURN
#line 373 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1392 "./parser.cpp"
    break;

  case 38: // return_statement: RETURN tuple_item
#line 374 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1398 "./parser.cpp"
    break;

  case 39: // delete_statement: DEL expr_list
#line 379 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1404 "./parser.cpp"
    break;

  case 40: // delete_statement: DEL expr_list ","
#line 380 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1410 "./parser.cpp"
    break;

  case 41: // delete_statement: DEL "(" expr_list "," ")"
#line 381 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1417 "./parser.cpp"
    break;

  case 42: // delete_statement: DEL "(" expr_list "," expr ")"
#line 383 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1424 "./parser.cpp"
    break;

  case 43: // single_line_statement: expression_statment
#line 388 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1430 "./parser.cpp"
    break;

  case 44: // single_line_statement: assert_statement
#line 390 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1436 "./parser.cpp"
    break;

  case 45: // single_line_statement: assignment_statement
#line 391 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1442 "./parser.cpp"
    break;

  case 46: // single_line_statement: pass_statement
#line 394 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1448 "./parser.cpp"
    break;

  case 47: // single_line_statement: delete_statement
#line 395 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1454 "./parser.cpp"
    break;

  case 48: // single_line_statement: return_statement
#line 396 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1460 "./parser.cpp"
    break;

  case 49: // single_line_statement: raise_statement
#line 397 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1466 "./parser.cpp"
    break;

  case 50: // single_line_statement: break_statement
#line 398 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1472 "./parser.cpp"
    break;

  case 51: // single_line_statement: continue_statement
#line 399 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1478 "./parser.cpp"
    break;

  case 52: // single_line_statement: import_statement
#line 400 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1484 "./parser.cpp"
    break;

  case 53: // single_line_statement: global_statement
#line 401 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1490 "./parser.cpp"
    break;

  case 54: // single_line_statement: nonlocal_statement
#line 402 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1496 "./parser.cpp"
    break;

  case 55: // module: module "." id
#line 407 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1502 "./parser.cpp"
    break;

  case 56: // module: id
#line 408 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1508 "./parser.cpp"
    break;

  case 57: // module_as_id: module
#line 412 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1514 "./parser.cpp"
    break;

  case 58: // module_as_id: module AS id
#line 413 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1520 "./parser.cpp"
    break;

  case 59: // module_as_id: "*"
#line 414 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1526 "./parser.cpp"
    break;

  case 60: // module_item_list: module_item_list "," module_as_id
#line 418 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1532 "./parser.cpp"
    break;

  case 61: // module_item_list: module_as_id
#line 419 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1538 "./parser.cpp"
    break;

  case 62: // dot_list: dot_list "."
#line 423 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1544 "./parser.cpp"
    break;

  case 63: // dot_list: "."
#line 424 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1550 "./parser.cpp"
    break;

  case 64: // import_statement: IMPORT module_item_list
#line 430 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1556 "./parser.cpp"
    break;

  case 65: // import_statement: FROM module IMPORT module_item_list
#line 431 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1563 "./parser.cpp"
    break;

  case 66: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 433 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1570 "./parser.cpp"
    break;

  case 67: // import_statement: FROM dot_list IMPORT module_item_list
#line 435 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1577 "./parser.cpp"
    break;

  case 68: // import_statement: FROM dot_list module IMPORT module_item_list
#line 437 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1584 "./parser.cpp"
    break;

  case 69: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 439 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1591 "./parser.cpp"
    break;

  case 70: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 441 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1598 "./parser.cpp"
    break;

  case 71: // multi_line_statement: if_statement
#line 446 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1604 "./parser.cpp"
    break;

  case 72: // multi_line_statement: function_def
#line 450 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1610 "./parser.cpp"
    break;

  case 73: // decorators_opt: decorators
#line 459 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1616 "./parser.cpp"
    break;

  case 74: // decorators_opt: %empty
#line 460 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1622 "./parser.cpp"
    break;

  case 75: // decorators: decorators "@" expr sep
#line 464 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1628 "./parser.cpp"
    break;

  case 76: // decorators: "@" expr sep
#line 465 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1634 "./parser.cpp"
    break;

  case 77: // parameter: id
#line 469 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1640 "./parser.cpp"
    break;

  case 78: // parameter: id ":" expr
#line 470 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1646 "./parser.cpp"
    break;

  case 79: // parameter: id "=" expr
#line 471 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1652 "./parser.cpp"
    break;

  case 80: // parameter: id ":" expr "=" expr
#line 472 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1658 "./parser.cpp"
    break;

  case 81: // parameter_list: defparameter_list "," "/" comma_opt
#line 476 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1665 "./parser.cpp"
    break;

  case 82: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 478 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1672 "./parser.cpp"
    break;

  case 83: // parameter_list: parameter_list_no_posonly
#line 480 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1678 "./parser.cpp"
    break;

  case 84: // parameter_list_no_posonly: defparameter_list comma_opt
#line 484 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1684 "./parser.cpp"
    break;

  case 85: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 485 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1691 "./parser.cpp"
    break;

  case 86: // parameter_list_no_posonly: parameter_list_starargs
#line 487 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1697 "./parser.cpp"
    break;

  case 87: // defparameter_list: defparameter_list "," parameter
#line 491 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1703 "./parser.cpp"
    break;

  case 88: // defparameter_list: parameter
#line 492 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1709 "./parser.cpp"
    break;

  case 89: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 500 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1715 "./parser.cpp"
    break;

  case 90: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 501 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1721 "./parser.cpp"
    break;

  case 91: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 502 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1728 "./parser.cpp"
    break;

  case 92: // parameter_list_starargs: "*" parameter comma_opt
#line 504 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1734 "./parser.cpp"
    break;

  case 93: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 505 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1741 "./parser.cpp"
    break;

  case 94: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 507 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1748 "./parser.cpp"
    break;

  case 95: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 509 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1755 "./parser.cpp"
    break;

  case 96: // parameter_list_starargs: "**" parameter comma_opt
#line 511 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1761 "./parser.cpp"
    break;

  case 97: // parameter_list_opt: parameter_list
#line 515 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1767 "./parser.cpp"
    break;

  case 98: // parameter_list_opt: %empty
#line 516 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1773 "./parser.cpp"
    break;

  case 101: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 526 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1779 "./parser.cpp"
    break;

  case 102: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 528 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1785 "./parser.cpp"
    break;

  case 103: // global_statement: GLOBAL expr_list
#line 538 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1791 "./parser.cpp"
    break;

  case 104: // ternary_if_statement: expr IF expr ELSE expr
#line 542 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1797 "./parser.cpp"
    break;

  case 105: // nonlocal_statement: NONLOCAL expr_list
#line 546 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1803 "./parser.cpp"
    break;

  case 106: // elif_statement: ELIF expr ":" sep statements
#line 550 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 1809 "./parser.cpp"
    break;

  case 107: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 551 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1816 "./parser.cpp"
    break;

  case 108: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 553 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1823 "./parser.cpp"
    break;

  case 109: // if_statement: IF expr ":" body_stmts
#line 558 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1831 "./parser.cpp"
    break;

  case 110: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 561 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1839 "./parser.cpp"
    break;

  case 111: // if_statement: IF expr ":" body_stmts elif_statement
#line 564 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1846 "./parser.cpp"
    break;

  case 112: // target_list: target_list tuple_item "="
#line 569 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1852 "./parser.cpp"
    break;

  case 113: // target_list: tuple_item "="
#line 570 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1858 "./parser.cpp"
    break;

  case 114: // assignment_statement: target_list tuple_item
#line 574 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1864 "./parser.cpp"
    break;

  case 115: // expression_statment: expr
#line 579 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1870 "./parser.cpp"
    break;

  case 116: // string: string string_literal
#line 587 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1876 "./parser.cpp"
    break;

  case 117: // string: string_literal
#line 588 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1884 "./parser.cpp"
    break;

  case 118: // string: id string_literal
#line 591 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1892 "./parser.cpp"
    break;

  case 119: // string: string id string_literal
#line 594 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1900 "./parser.cpp"
    break;

  case 120: // expr_list_opt: expr_list
#line 600 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1906 "./parser.cpp"
    break;

  case 121: // expr_list_opt: %empty
#line 601 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1912 "./parser.cpp"
    break;

  case 122: // expr_list: expr_list "," expr
#line 605 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1918 "./parser.cpp"
    break;

  case 123: // expr_list: expr
#line 606 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 1924 "./parser.cpp"
    break;

  case 124: // dict: expr ":" expr
#line 616 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1930 "./parser.cpp"
    break;

  case 125: // dict_list: dict_list "," dict
#line 620 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1936 "./parser.cpp"
    break;

  case 126: // dict_list: dict
#line 621 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 1942 "./parser.cpp"
    break;

  case 127: // call_arguement_list: expr_list_opt
#line 625 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1948 "./parser.cpp"
    break;

  case 128: // call_arguement_list: expr_list ","
#line 626 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1954 "./parser.cpp"
    break;

  case 129: // keyword_item: id "=" expr
#line 631 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1960 "./parser.cpp"
    break;

  case 130: // keyword_item: "**" expr
#line 632 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1966 "./parser.cpp"
    break;

  case 131: // keyword_items: keyword_items "," keyword_item
#line 636 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1972 "./parser.cpp"
    break;

  case 132: // keyword_items: keyword_item
#line 637 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 1978 "./parser.cpp"
    break;

  case 133: // primary: id
#line 642 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 1984 "./parser.cpp"
    break;

  case 134: // primary: string
#line 643 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 1990 "./parser.cpp"
    break;

  case 135: // primary: expr "." id
#line 644 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1996 "./parser.cpp"
    break;

  case 136: // function_call: primary "(" call_arguement_list ")"
#line 648 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2002 "./parser.cpp"
    break;

  case 137: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 649 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2009 "./parser.cpp"
    break;

  case 138: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 651 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2016 "./parser.cpp"
    break;

  case 139: // function_call: primary "(" keyword_items comma_opt ")"
#line 653 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2022 "./parser.cpp"
    break;

  case 140: // function_call: function_call "(" call_arguement_list ")"
#line 654 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2028 "./parser.cpp"
    break;

  case 141: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 655 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2035 "./parser.cpp"
    break;

  case 142: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 657 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2042 "./parser.cpp"
    break;

  case 143: // function_call: function_call "(" keyword_items comma_opt ")"
#line 659 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2048 "./parser.cpp"
    break;

  case 144: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 666 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2054 "./parser.cpp"
    break;

  case 145: // expr: id
#line 670 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2060 "./parser.cpp"
    break;

  case 146: // expr: integer_literal
#line 671 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2069 "./parser.cpp"
    break;

  case 147: // expr: string
#line 675 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2075 "./parser.cpp"
    break;

  case 148: // expr: real_literal
#line 676 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2081 "./parser.cpp"
    break;

  case 149: // expr: image_literal
#line 677 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2090 "./parser.cpp"
    break;

  case 150: // expr: TRUE
#line 681 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2096 "./parser.cpp"
    break;

  case 151: // expr: FALSE
#line 682 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2102 "./parser.cpp"
    break;

  case 152: // expr: NONE
#line 683 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2108 "./parser.cpp"
    break;

  case 153: // expr: "..."
#line 684 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2114 "./parser.cpp"
    break;

  case 154: // expr: "(" expr ")"
#line 685 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2120 "./parser.cpp"
    break;

  case 155: // expr: "(" ")"
#line 686 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2126 "./parser.cpp"
    break;

  case 156: // expr: function_call
#line 687 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2132 "./parser.cpp"
    break;

  case 157: // expr: "[" expr_list_opt "]"
#line 689 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2138 "./parser.cpp"
    break;

  case 158: // expr: "[" expr_list "," "]"
#line 690 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2144 "./parser.cpp"
    break;

  case 159: // expr: "{" expr_list "}"
#line 691 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2150 "./parser.cpp"
    break;

  case 160: // expr: "{" expr_list "," "}"
#line 692 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2156 "./parser.cpp"
    break;

  case 161: // expr: expr "." id
#line 693 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2162 "./parser.cpp"
    break;

  case 162: // expr: "{" "}"
#line 695 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2168 "./parser.cpp"
    break;

  case 163: // expr: "{" dict_list "}"
#line 696 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2174 "./parser.cpp"
    break;

  case 164: // expr: id ":=" expr
#line 700 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2180 "./parser.cpp"
    break;

  case 165: // expr: "*" expr
#line 701 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2186 "./parser.cpp"
    break;

  case 166: // expr: expr "+" expr
#line 703 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2192 "./parser.cpp"
    break;

  case 167: // expr: expr "-" expr
#line 704 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2198 "./parser.cpp"
    break;

  case 168: // expr: expr "*" expr
#line 705 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2204 "./parser.cpp"
    break;

  case 169: // expr: expr "/" expr
#line 706 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2210 "./parser.cpp"
    break;

  case 170: // expr: expr "%" expr
#line 707 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2216 "./parser.cpp"
    break;

  case 171: // expr: "-" expr
#line 708 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2222 "./parser.cpp"
    break;

  case 172: // expr: "+" expr
#line 709 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2228 "./parser.cpp"
    break;

  case 173: // expr: "~" expr
#line 710 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2234 "./parser.cpp"
    break;

  case 174: // expr: expr "**" expr
#line 711 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2240 "./parser.cpp"
    break;

  case 175: // expr: expr "//" expr
#line 712 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2246 "./parser.cpp"
    break;

  case 176: // expr: expr "@" expr
#line 713 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2252 "./parser.cpp"
    break;

  case 177: // expr: expr "&" expr
#line 715 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2258 "./parser.cpp"
    break;

  case 178: // expr: expr "|" expr
#line 716 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2264 "./parser.cpp"
    break;

  case 179: // expr: expr "^" expr
#line 717 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2270 "./parser.cpp"
    break;

  case 180: // expr: expr "<<" expr
#line 718 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2276 "./parser.cpp"
    break;

  case 181: // expr: expr ">>" expr
#line 719 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2282 "./parser.cpp"
    break;

  case 182: // expr: expr "==" expr
#line 721 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2288 "./parser.cpp"
    break;

  case 183: // expr: expr "!=" expr
#line 722 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2294 "./parser.cpp"
    break;

  case 184: // expr: expr "<" expr
#line 723 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2300 "./parser.cpp"
    break;

  case 185: // expr: expr "<=" expr
#line 724 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2306 "./parser.cpp"
    break;

  case 186: // expr: expr ">" expr
#line 725 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2312 "./parser.cpp"
    break;

  case 187: // expr: expr ">=" expr
#line 726 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2318 "./parser.cpp"
    break;

  case 188: // expr: expr "is" expr
#line 727 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2324 "./parser.cpp"
    break;

  case 189: // expr: expr "is not" expr
#line 728 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2330 "./parser.cpp"
    break;

  case 190: // expr: expr "in" expr
#line 729 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2336 "./parser.cpp"
    break;

  case 191: // expr: expr "not in" expr
#line 730 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2342 "./parser.cpp"
    break;

  case 192: // expr: expr "and" expr
#line 732 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2348 "./parser.cpp"
    break;

  case 193: // expr: expr "or" expr
#line 733 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2354 "./parser.cpp"
    break;

  case 194: // expr: "not" expr
#line 734 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2360 "./parser.cpp"
    break;

  case 195: // expr: ternary_if_statement
#line 741 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2366 "./parser.cpp"
    break;

  case 196: // id: identifier
#line 746 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2372 "./parser.cpp"
    break;

  case 197: // sep: sep sep_one
#line 750 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2378 "./parser.cpp"
    break;

  case 198: // sep: sep_one
#line 751 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2384 "./parser.cpp"
    break;

  case 199: // sep_one: NEWLINE
#line 755 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2390 "./parser.cpp"
    break;

  case 200: // sep_one: COMMENT
#line 756 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2396 "./parser.cpp"
    break;

  case 201: // sep_one: ";"
#line 757 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2402 "./parser.cpp"
    break;


#line 2406 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -295;

  const short  Parser ::yytable_ninf_ = -136;

  const short
   Parser ::yypact_[] =
  {
     507,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  -295,  1854,
    1854,  -295,  -295,  1892,    36,  1854,  1854,    33,  1854,  1854,
    -295,  1914,  1601,   401,  1854,  1854,  1854,  1854,  1854,  1854,
    -295,  -295,  -295,  -295,  1562,  -295,  -295,  -295,  -295,  -295,
    -295,   -34,  -295,  -295,  -295,    94,  -295,    94,    17,   -24,
    -295,  -295,  -295,  -295,  -295,  1914,  -295,  -295,    43,    52,
       2,   114,   779,    56,    94,  -295,   401,   824,   887,   401,
     136,  1391,  -295,    37,    49,  -295,   138,   932,  -295,    -7,
    -295,   146,   138,  1931,  -295,  -295,   -35,  -295,   116,   977,
    -295,   161,  1022,     4,   165,    23,    23,    23,   716,    23,
    -295,  -295,  -295,    94,    94,   189,  1854,   167,  -295,   213,
    1854,  1818,  1818,  1854,  1854,  1854,  1854,  1854,  1854,  1854,
    1854,  1854,  1854,  1854,   189,  1854,  1854,  1854,  1854,  1854,
    1854,  1854,  1854,  1854,  1854,  1854,  1854,  1854,  1854,  1854,
    -295,  1854,  -295,  1022,  1854,  1854,   171,  1854,    12,   189,
      30,  -295,   144,  1854,   592,   189,    33,  1637,  -295,  1854,
    -295,  1854,   580,   166,  -295,   320,    94,   172,   716,  -295,
    -295,  1391,  1854,  -295,   176,   151,  -295,   180,    48,   182,
     153,   183,  1931,  1085,   492,   492,   492,   492,  1479,  1695,
     227,   492,   145,   178,   145,    23,    23,    23,    23,    23,
    1619,   288,   288,   492,   492,   492,   492,    23,   492,  1435,
    1391,  1391,   665,    33,   146,  -295,    33,   146,    42,  -295,
     170,  -295,   113,  1779,   104,    92,  -295,  -295,  -295,  -295,
     977,  1391,  -295,  1130,  1854,  -295,    16,    94,  1391,  1818,
    -295,  1818,   159,  1854,  1818,  -295,  1818,   160,  1854,  -295,
    1193,   190,   190,    33,   146,  1854,   193,  -295,  -295,   157,
     173,   128,  -295,   164,  1711,  -295,  -295,   196,   175,     9,
     189,  -295,  -295,  -295,   203,  -295,   181,   133,   204,   209,
    -295,  -295,  1391,   204,   209,  -295,  1435,  -295,    33,   184,
     185,   190,  1256,   592,  -295,   132,  -295,   177,  -295,   677,
    -295,  1854,  -295,     8,   215,   216,     3,  -295,   100,  1854,
    1854,    25,   187,  1854,   191,   194,   195,  -295,  -295,   201,
      94,  -295,  -295,  -295,  -295,   189,   228,    26,  -295,  -295,
    -295,   230,  -295,  -295,   592,  1854,  1301,  1391,   242,  -295,
    -295,  -295,  -295,  -295,    92,   216,    27,  -295,   189,   247,
      16,  -295,  -295,  1346,  1854,   179,  -295,   189,   216,    31,
    -295,  -295,   248,   592,  1391,   252,  -295,   216,  -295,   189,
      16,  -295,    94,  -295,   216,    92,  -295,  -295
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      74,   146,   148,   149,   196,   117,   151,   150,   152,     0,
      34,    26,    27,     0,     0,     0,     0,     0,     0,     0,
      25,    37,     0,     0,   121,     0,     0,     0,     0,     0,
     153,   201,   199,   200,    74,     3,     5,    46,    50,    51,
      44,     0,    49,    48,    47,     0,    52,    23,     0,    73,
      72,    53,   195,    54,    71,     0,    45,    43,   147,    30,
       0,   156,   115,   145,     4,   198,     0,    28,    35,     0,
      39,   123,    63,     0,     0,    56,   103,     0,    59,    57,
      61,    64,   105,   194,    38,   162,     0,   126,     0,   123,
     155,     0,   123,     0,   120,   171,   172,   165,     0,   173,
       1,     2,   113,    22,    24,     0,     0,   114,   116,     0,
      31,   121,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,   197,     0,     0,     0,     0,    40,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,   159,     0,
     163,     0,     0,   154,   157,     0,    76,     0,     0,   112,
     119,   122,     0,   127,   120,     0,   132,   100,   145,   120,
       0,   100,   192,     0,   190,   188,   189,   191,   193,   177,
     179,   182,   167,   161,   166,   168,   174,   176,   175,   170,
     178,   180,   181,   184,   185,   186,   187,   169,   183,   164,
      29,    36,     0,     0,    65,    55,     0,    67,     0,     9,
     109,     8,     0,     0,     0,     0,    58,    60,   160,   125,
       0,   124,    32,   122,   121,   158,    98,    75,   130,   128,
     136,    99,     0,     0,   128,   140,    99,     0,     0,    41,
     122,   100,   100,     0,    68,     0,     0,   111,    12,     0,
      18,    21,    14,     0,    74,     7,    33,   120,     0,     0,
       0,    88,    97,    83,   100,    86,     0,    77,   100,   100,
     131,   139,   129,   100,   100,   143,   104,    42,    99,     0,
       0,   100,     0,     0,    13,    20,    15,     0,    17,    74,
      11,   128,   144,     0,   100,   100,    99,    84,     0,     0,
       0,    99,     0,    99,     0,     0,     0,    66,    69,     0,
       0,   110,    16,     6,    10,     0,   100,    99,    92,    99,
      96,   100,    87,    85,     0,     0,    78,    79,     0,   137,
     138,   141,   142,    70,     0,   100,    99,    89,     0,   100,
      99,    81,   101,     0,     0,   106,    90,     0,   100,    99,
      93,    82,   100,     0,    80,     0,   108,   100,    94,     0,
      99,   102,     0,    91,   100,     0,    95,   107
  };

  const short
   Parser ::yypgoto_[] =
  {
    -295,  -295,   269,  -232,  -295,  -288,  -295,  -295,  -295,  -295,
    -214,  -295,  -295,  -295,  -295,   143,  -295,  -295,  -295,  -146,
      -1,  -135,   -57,  -295,  -295,  -295,  -295,  -295,  -100,  -295,
     -46,  -269,  -294,  -295,   140,  -295,  -295,  -295,  -295,   -50,
    -295,  -295,  -295,  -295,  -295,   282,    39,   148,  -295,  -109,
    -239,   -87,  -295,  -295,     1,   127,     0,   -60
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    34,    35,   265,   219,   220,   299,   221,   222,   223,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      79,    80,    81,    74,    46,    47,    48,    49,   271,   272,
     273,   274,   275,   276,   307,    50,    51,    52,    53,   257,
      54,    55,    56,    57,    58,   173,    59,    87,    88,   175,
     176,   177,    60,    61,    71,    63,   225,    65
  };

  const short
   Parser ::yytable_[] =
  {
      64,    62,   280,   180,   142,   321,   155,   280,   224,     4,
      67,    68,   333,    73,     4,     4,   157,    77,     4,   102,
      83,   227,     4,    89,    92,   181,    95,    96,    97,    98,
      99,     4,     4,     4,   326,    62,     4,     4,   105,     4,
     106,   158,     4,   142,   142,   103,   352,   104,     4,     4,
     300,   108,    70,   149,    76,     4,   140,    82,   349,   111,
     303,    86,    91,    94,   140,   269,   270,   143,   148,   213,
      92,   325,   280,   152,    78,   371,   333,   260,   269,   270,
     150,   362,   164,   124,   331,   324,   127,   216,   172,   348,
     357,   214,    78,   217,   369,    78,    72,   149,   166,   253,
    -134,   243,   141,   110,    78,  -133,   142,   168,   146,   151,
     141,   171,   355,  -133,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   268,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    75,   209,   377,    75,   210,   211,   224,   171,   334,
     174,   179,   278,   227,   171,    62,   251,   283,   171,   252,
     230,   254,   231,   233,    84,   142,   171,   159,   237,   304,
     305,   112,    31,   238,    31,   218,   264,   142,    32,    33,
      32,    33,   309,   335,   261,   109,   310,   147,   224,   153,
     262,   263,   160,   255,   256,     4,   291,   156,   107,   258,
     259,    75,   255,   365,   149,   124,   332,   126,   127,   128,
     129,   130,   162,   250,   296,   297,   165,   224,   -19,   -19,
     169,   170,   212,   234,    62,   345,   138,   239,   240,   236,
     245,   241,   167,   244,   246,  -135,   281,   285,   178,   178,
     171,   288,   293,   294,   282,   171,   332,   301,   358,   286,
     298,   193,   302,   295,   306,   311,   292,   367,   308,   332,
     313,   317,   318,   322,   339,    62,   327,   329,   340,   374,
     332,   341,   342,   267,   120,    75,   215,    75,   343,   346,
     279,   350,   226,    75,   142,   284,   123,   124,   125,   126,
     127,   128,   129,   130,    62,   243,   132,   133,   359,   370,
      62,   372,   171,   101,   361,   366,    93,   229,   138,     0,
     336,   337,     0,     0,   171,   142,     0,   242,     0,     0,
     344,   247,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,    62,   353,     0,     0,     0,
      75,     0,     0,    75,     0,    75,     0,   123,   124,   125,
     126,   127,   128,   129,   130,   364,     0,     0,    19,     0,
       0,     0,     0,   277,    62,     0,   178,     0,   178,   138,
       0,   178,   375,   178,     0,     0,    22,    66,    24,    25,
      75,    26,    27,     0,     0,     0,     0,    29,     0,     0,
       0,   289,   290,     0,     0,    30,   277,   277,   235,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,    75,     0,     0,   312,   314,
       0,     0,     0,   315,   316,     0,     0,     0,     0,     0,
     277,   319,     0,   277,     0,     0,     0,     0,   338,    19,
       0,     0,     0,     0,   328,   330,     0,     0,     0,     0,
       0,     0,   277,     0,   277,     0,     0,    22,    66,    24,
      25,     0,    26,    27,     0,     0,   347,     0,    29,     0,
       0,   351,     0,   277,     0,   277,    30,   277,    90,     0,
       0,     0,     0,     0,   277,   356,   277,     0,     0,   360,
       0,     0,     0,     0,     0,     0,   277,   277,   368,     0,
       0,     0,     0,     0,     0,     0,     0,   373,     0,     0,
       1,     2,     3,     4,   376,     5,     6,     7,     8,     0,
       0,     9,    10,     0,     0,    11,     0,    12,     0,    13,
       0,     0,     0,     0,     0,    14,    15,    16,    17,   120,
     121,     0,     0,     0,    18,    19,     0,    20,    21,     0,
       0,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,   132,   133,    22,    23,    24,    25,     0,    26,    27,
       0,    28,     0,   138,    29,     0,     0,     0,     0,     0,
       0,     0,    30,     1,     2,     3,     4,    31,     5,     6,
       7,     8,     0,    32,    33,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,     0,    19,     0,
      14,    15,     0,    17,     0,     0,     0,     0,     0,    18,
      19,     0,    20,    21,     0,     0,    22,    66,    24,    25,
       0,    26,    27,     0,     0,     0,     0,    29,    22,    23,
      24,    25,     0,    26,    27,    30,     0,   232,     0,    29,
       0,     0,     0,     0,     0,     0,     0,    30,     1,     2,
       3,     4,    31,     5,     6,     7,     8,     0,    32,    33,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     9,    10,     0,     0,    11,     0,    12,     0,    13,
       0,     0,     0,    19,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,    18,    19,     0,    20,    21,     0,
       0,    22,    66,    24,    25,     0,    26,    27,   113,     0,
       0,     0,    29,    22,    23,    24,    25,     0,    26,    27,
      30,    28,   249,     0,    29,     0,   114,     0,   115,   116,
     117,   118,    30,     0,     0,   119,     0,     0,     0,     0,
       0,     0,   323,   120,   121,     0,     0,     0,     0,     0,
       0,   122,     0,     0,     0,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   113,     0,     0,     0,     0,    31,   138,     0,     0,
       0,     0,    32,    33,     0,     0,   139,     0,     0,   114,
       0,   115,   116,   117,   118,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,   120,   121,     0,     0,
    -123,     0,  -123,     0,   122,     0,   113,     0,   123,   124,
     125,   126,   127,   128,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   114,     0,   115,   116,   117,   118,
     138,     0,     0,   119,     0,     0,     0,     0,     0,   139,
       0,   120,   121,     0,     0,   144,     0,     0,     0,   122,
       0,     0,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   113,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,   139,   145,     0,   114,     0,   115,
     116,   117,   118,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,   120,   121,     0,     0,     0,     0,
       0,     0,   122,     0,   113,     0,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   114,     0,   115,   116,   117,   118,   138,     0,
       0,   119,     0,     0,     0,     0,     0,   139,     0,   120,
     121,   154,     0,     0,     0,     0,     0,   122,     0,   113,
       0,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   114,     0,   115,
     116,   117,   118,   138,     0,     0,   119,     0,     0,     0,
       0,     0,   139,     0,   120,   121,   161,     0,     0,     0,
       0,     0,   122,     0,   113,     0,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   114,     0,   115,   116,   117,   118,   138,     0,
       0,   119,     0,     0,     0,     0,     0,   139,     0,   120,
     121,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   123,   124,   125,   126,   127,   128,   129,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   113,     0,   163,
       0,     0,     0,   138,     0,     0,     0,     0,     0,   248,
       0,     0,   139,     0,     0,   114,     0,   115,   116,   117,
     118,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
     122,     0,   113,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     114,     0,   115,   116,   117,   118,   138,     0,     0,   119,
       0,     0,     0,     0,     0,   139,     0,   120,   121,     0,
       0,     0,     0,     0,     0,   122,     0,     0,     0,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   113,     0,   266,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,     0,     0,
     139,     0,     0,   114,     0,   115,   116,   117,   118,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,   123,   124,   125,   126,   127,   128,   129,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   113,     0,
     287,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,   139,     0,     0,   114,     0,   115,   116,
     117,   118,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,   120,   121,   320,     0,     0,     0,     0,
       0,   122,     0,   113,     0,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   114,     0,   115,   116,   117,   118,   138,     0,     0,
     119,     0,     0,     0,     0,     0,   139,     0,   120,   121,
       0,     0,     0,     0,   354,     0,   122,     0,   113,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   114,     0,   115,   116,
     117,   118,   138,     0,     0,   119,     0,     0,     0,     0,
       0,   139,     0,   120,   121,   363,     0,     0,     0,     0,
       0,   122,     0,   113,     0,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   114,     0,   115,   116,   117,   118,   138,     0,     0,
     119,     0,     0,     0,     0,     0,   139,     0,   120,   121,
       0,     0,     0,     0,     0,     0,   122,   113,     0,     0,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,     0,   115,   116,   117,
     118,     0,   138,     0,   119,     0,     0,     0,     0,     0,
       0,   139,   120,   121,     0,     0,     0,     0,     0,     0,
     122,   113,     0,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,   131,   132,   133,   134,   135,   136,   137,
       0,   115,   116,   117,   118,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   120,   121,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   123,   124,
     125,   126,   127,   128,   129,   130,     0,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
     138,     0,   100,     0,     0,     1,     2,     3,     4,   139,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     0,     0,     0,    18,
      19,     0,    20,    21,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     0,    22,    23,
      24,    25,     0,    26,    27,     0,    28,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    19,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    66,    24,
      25,     0,    26,    27,     0,     0,   120,   121,    29,     0,
       0,     0,     0,     0,     0,    19,    30,    85,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,   132,   133,
       0,     0,     0,    22,    66,    24,    25,     0,    26,    27,
     138,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,    30,   228,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,    13,     0,     0,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,    18,    19,
       0,    20,    21,     0,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,   132,   133,     0,    22,    23,    24,
      25,     0,    26,    27,     0,    28,   138,     0,    29,     0,
       0,     0,     1,     2,     3,     4,    30,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,    13,     0,     0,     0,     0,     0,    14,    15,     0,
      17,     0,     0,     0,     0,     0,    18,    19,     0,    20,
      21,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     0,     0,     0,    22,    23,    24,    25,     0,
      26,    27,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    19,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    66,    24,    25,     0,    26,
      27,   172,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,    19,    30,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
      22,    66,    24,    25,     0,    26,    27,     1,     2,     3,
       4,    29,     5,     6,     7,     8,     0,     0,     0,    30,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    69,
      24,    25,    19,    26,    27,     0,     0,     0,     0,    29,
       0,     0,     0,   115,   116,   117,   118,    30,     0,     0,
      22,    23,    24,    25,     0,    26,    27,     0,   120,   121,
       0,    29,     0,     0,     0,     0,   122,     0,     0,    30,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,   139
  };

  const short
   Parser ::yycheck_[] =
  {
       0,     0,   241,   112,    64,   293,    13,   246,   154,     6,
       9,    10,   306,    14,     6,     6,    51,    16,     6,    53,
      19,   156,     6,    22,    23,   112,    25,    26,    27,    28,
      29,     6,     6,     6,   303,    34,     6,     6,    21,     6,
      64,    76,     6,   103,   104,    45,   334,    47,     6,     6,
     264,     8,    13,    60,    15,     6,     8,    18,   327,    57,
      51,    22,    23,    24,     8,    62,    63,    66,    31,    57,
      69,    63,   311,    74,    62,   363,   370,   223,    62,    63,
      31,   350,    78,    60,    81,   299,    63,    57,    63,    63,
      63,   148,    62,   150,    63,    62,    60,    60,    98,    57,
      57,    53,    54,    51,    62,    57,   166,   106,    69,    60,
      54,   110,   344,    57,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   234,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    14,   141,   375,    17,   144,   145,   293,   147,    49,
     111,   112,   239,   288,   153,   154,   213,   244,   157,   216,
     159,   218,   161,   162,    21,   225,   165,    51,   168,   269,
     270,    57,    80,   172,    80,    31,    84,   237,    86,    87,
      86,    87,    49,    83,    80,    58,    53,    51,   334,    51,
      86,    87,    76,    23,    24,     6,   253,    51,    55,    86,
      87,    74,    23,    24,    60,    60,   306,    62,    63,    64,
      65,    66,    51,   212,    86,    87,    51,   363,    86,    87,
      53,     8,    51,    57,   223,   325,    81,    51,    77,    57,
      77,    51,   105,    51,    51,    57,    77,    77,   111,   112,
     239,    51,    49,    86,   243,   244,   346,    51,   348,   248,
      86,   124,    77,    80,    51,    51,   255,   357,    77,   359,
      51,    77,    77,    86,    77,   264,    51,    51,    77,   369,
     370,    77,    77,   234,    47,   148,   149,   150,    77,    51,
     241,    51,   155,   156,   344,   246,    59,    60,    61,    62,
      63,    64,    65,    66,   293,    53,    69,    70,    51,    51,
     299,    49,   301,    34,   350,   355,    24,   159,    81,    -1,
     309,   310,    -1,    -1,   313,   375,    -1,   177,    -1,    -1,
     320,   181,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,   334,   335,    -1,    -1,    -1,
     213,    -1,    -1,   216,    -1,   218,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,   354,    -1,    -1,    38,    -1,
      -1,    -1,    -1,   236,   363,    -1,   239,    -1,   241,    81,
      -1,   244,   372,   246,    -1,    -1,    56,    57,    58,    59,
     253,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,   251,   252,    -1,    -1,    75,   269,   270,    78,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,   288,    -1,    -1,   278,   279,
      -1,    -1,    -1,   283,   284,    -1,    -1,    -1,    -1,    -1,
     303,   291,    -1,   306,    -1,    -1,    -1,    -1,   311,    38,
      -1,    -1,    -1,    -1,   304,   305,    -1,    -1,    -1,    -1,
      -1,    -1,   325,    -1,   327,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,   326,    -1,    67,    -1,
      -1,   331,    -1,   346,    -1,   348,    75,   350,    77,    -1,
      -1,    -1,    -1,    -1,   357,   345,   359,    -1,    -1,   349,
      -1,    -1,    -1,    -1,    -1,    -1,   369,   370,   358,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,    -1,
       3,     4,     5,     6,   374,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    47,
      48,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    56,    57,    58,    59,    -1,    61,    62,
      -1,    64,    -1,    81,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,     3,     4,     5,     6,    80,     8,     9,
      10,    11,    -1,    86,    87,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    38,    -1,
      28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    56,    57,
      58,    59,    -1,    61,    62,    75,    -1,    77,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,     3,     4,
       5,     6,    80,     8,     9,    10,    11,    -1,    86,    87,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,
      -1,    -1,    -1,    38,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    12,    -1,
      -1,    -1,    67,    56,    57,    58,    59,    -1,    61,    62,
      75,    64,    77,    -1,    67,    -1,    30,    -1,    32,    33,
      34,    35,    75,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    12,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    86,    87,    -1,    -1,    90,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      51,    -1,    53,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    47,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    12,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    28,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    12,    -1,    77,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    90,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    12,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    12,    -1,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    12,    -1,
      77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    90,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    12,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    32,    33,    34,
      35,    -1,    81,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    12,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    32,    33,    34,    35,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,     0,    -1,    -1,     3,     4,     5,     6,    90,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    38,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    47,    48,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    75,    76,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    70,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      81,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    64,    81,    -1,    67,    -1,
      -1,    -1,     3,     4,     5,     6,    75,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
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
      56,    57,    58,    59,    -1,    61,    62,     3,     4,     5,
       6,    67,     8,     9,    10,    11,    -1,    -1,    -1,    75,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    38,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    32,    33,    34,    35,    75,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    47,    48,
      -1,    67,    -1,    -1,    -1,    -1,    55,    -1,    -1,    75,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    28,    29,    30,    31,    37,    38,
      40,    41,    56,    57,    58,    59,    61,    62,    64,    67,
      75,    80,    86,    87,    93,    94,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   116,   117,   118,   119,
     127,   128,   129,   130,   132,   133,   134,   135,   136,   138,
     144,   145,   146,   147,   148,   149,    57,   146,   146,    57,
     138,   146,    60,   112,   115,   147,   138,   146,    62,   112,
     113,   114,   138,   146,   107,    76,   138,   139,   140,   146,
      77,   138,   146,   137,   138,   146,   146,   146,   146,   146,
       0,    94,    53,   148,   148,    21,    64,   107,     8,   147,
      51,    57,    57,    12,    30,    32,    33,    34,    35,    39,
      47,    48,    55,    59,    60,    61,    62,    63,    64,    65,
      66,    68,    69,    70,    71,    72,    73,    74,    81,    90,
       8,    54,   149,   146,    51,    28,   138,    51,    31,    60,
      31,    60,   112,    51,    49,    13,    51,    51,    76,    51,
      76,    49,    51,    77,    78,    51,   148,   147,   146,    53,
       8,   146,    63,   137,   138,   141,   142,   143,   147,   138,
     141,   143,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   147,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,    51,    57,   114,   147,    57,   114,    31,    96,
      97,    99,   100,   101,   111,   148,   147,   113,    76,   139,
     146,   146,    77,   146,    57,    78,    57,   148,   146,    51,
      77,    51,   126,    53,    51,    77,    51,   126,    24,    77,
     146,   114,   114,    57,   114,    23,    24,   131,    86,    87,
     111,    80,    86,    87,    84,    95,    77,   138,   141,    62,
      63,   120,   121,   122,   123,   124,   125,   147,   143,   138,
     142,    77,   146,   143,   138,    77,   146,    77,    51,   126,
     126,   114,   146,    49,    86,    80,    86,    87,    86,    98,
     102,    51,    77,    51,   120,   120,    51,   126,    77,    49,
      53,    51,   126,    51,   126,   126,   126,    77,    77,   126,
      49,    97,    86,    85,   102,    63,   123,    51,   126,    51,
     126,    81,   120,   124,    49,    83,   146,   146,   147,    77,
      77,    77,    77,    77,   148,   120,    51,   126,    63,   123,
      51,   126,    97,   146,    53,    95,   126,    63,   120,    51,
     126,   122,   123,    49,   146,    24,   131,   120,   126,    63,
      51,    97,    49,   126,   120,   148,   126,    95
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
     132,   132,   133,   133,   134,   135,   136,   136,   136,   136,
     137,   137,   138,   138,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   147,   148,   148,   149,
     149,   149
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
       7,     5,     3,     2,     2,     1,     2,     1,     2,     3,
       1,     0,     3,     1,     3,     3,     1,     1,     2,     3,
       2,     3,     1,     1,     1,     3,     4,     7,     7,     5,
       4,     7,     7,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     3,     4,     3,
       4,     3,     2,     3,     3,     2,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     2,     1,     1,
       1,     1
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
  "nonlocal_statement", "elif_statement", "if_statement", "target_list",
  "assignment_statement", "expression_statment", "string", "expr_list_opt",
  "expr_list", "dict", "dict_list", "call_arguement_list", "keyword_item",
  "keyword_items", "primary", "function_call", "expr", "id", "sep",
  "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   275,   275,   276,   277,   281,   285,   289,   293,   294,
     298,   299,   303,   304,   305,   306,   309,   312,   318,   321,
     327,   330,   336,   337,   338,   343,   347,   351,   355,   356,
     360,   361,   362,   363,   367,   368,   369,   373,   374,   379,
     380,   381,   383,   388,   390,   391,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   407,   408,   412,   413,   414,
     418,   419,   423,   424,   430,   431,   433,   435,   437,   439,
     441,   446,   450,   459,   460,   464,   465,   469,   470,   471,
     472,   476,   478,   480,   484,   485,   487,   491,   492,   500,
     501,   502,   504,   505,   507,   509,   511,   515,   516,   520,
     521,   525,   527,   538,   542,   546,   550,   551,   553,   558,
     561,   564,   569,   570,   574,   579,   587,   588,   591,   594,
     600,   601,   605,   606,   616,   620,   621,   625,   626,   631,
     632,   636,   637,   642,   643,   644,   648,   649,   651,   653,
     654,   655,   657,   659,   666,   670,   671,   675,   676,   677,
     681,   682,   683,   684,   685,   686,   687,   689,   690,   691,
     692,   693,   695,   696,   700,   701,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   715,   716,   717,
     718,   719,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   732,   733,   734,   741,   746,   750,   751,   755,
     756,   757
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
#line 3319 "./parser.cpp"

#line 760 "parser.ypp"
