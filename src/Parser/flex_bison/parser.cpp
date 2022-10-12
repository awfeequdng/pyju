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
      case symbol_kind::S_for_tuple_item: // for_tuple_item
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
      case symbol_kind::S_augassign_statement: // augassign_statement
      case symbol_kind::S_ann_assignment_statement: // ann_assignment_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_except_statement: // except_statement
      case symbol_kind::S_try_statement: // try_statement
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

      case symbol_kind::S_augassign_op: // augassign_op
        value.YY_MOVE_OR_COPY< operatorType > (YY_MOVE (that.value));
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
      case symbol_kind::S_expr_for_list: // expr_for_list
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
      case symbol_kind::S_except_list: // except_list
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
      case symbol_kind::S_for_tuple_item: // for_tuple_item
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
      case symbol_kind::S_augassign_statement: // augassign_statement
      case symbol_kind::S_ann_assignment_statement: // ann_assignment_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_except_statement: // except_statement
      case symbol_kind::S_try_statement: // try_statement
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

      case symbol_kind::S_augassign_op: // augassign_op
        value.move< operatorType > (YY_MOVE (that.value));
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
      case symbol_kind::S_expr_for_list: // expr_for_list
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
      case symbol_kind::S_except_list: // except_list
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
      case symbol_kind::S_for_tuple_item: // for_tuple_item
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
      case symbol_kind::S_augassign_statement: // augassign_statement
      case symbol_kind::S_ann_assignment_statement: // ann_assignment_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_except_statement: // except_statement
      case symbol_kind::S_try_statement: // try_statement
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

      case symbol_kind::S_augassign_op: // augassign_op
        value.copy< operatorType > (that.value);
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
      case symbol_kind::S_expr_for_list: // expr_for_list
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
      case symbol_kind::S_except_list: // except_list
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
      case symbol_kind::S_for_tuple_item: // for_tuple_item
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
      case symbol_kind::S_augassign_statement: // augassign_statement
      case symbol_kind::S_ann_assignment_statement: // ann_assignment_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_except_statement: // except_statement
      case symbol_kind::S_try_statement: // try_statement
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

      case symbol_kind::S_augassign_op: // augassign_op
        value.move< operatorType > (that.value);
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
      case symbol_kind::S_expr_for_list: // expr_for_list
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
      case symbol_kind::S_except_list: // except_list
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
      case symbol_kind::S_for_tuple_item: // for_tuple_item
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
      case symbol_kind::S_augassign_statement: // augassign_statement
      case symbol_kind::S_ann_assignment_statement: // ann_assignment_statement
      case symbol_kind::S_single_line_statement: // single_line_statement
      case symbol_kind::S_import_statement: // import_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_except_statement: // except_statement
      case symbol_kind::S_try_statement: // try_statement
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

      case symbol_kind::S_augassign_op: // augassign_op
        yylhs.value.emplace< operatorType > ();
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
      case symbol_kind::S_expr_for_list: // expr_for_list
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
      case symbol_kind::S_except_list: // except_list
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
#line 297 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1239 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 298 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1245 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 303 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1251 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 307 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1257 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 311 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1263 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 315 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1269 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 316 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1275 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 320 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1281 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 321 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1287 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 325 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1293 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 326 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1299 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 327 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1305 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 328 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1313 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 331 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1321 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 334 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1329 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 340 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1337 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 343 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1345 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 349 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1353 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 352 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1361 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 358 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1367 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 359 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1373 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 360 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1379 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 365 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1385 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 369 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1391 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 373 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1397 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 377 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1403 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 378 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1409 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 382 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1415 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 383 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1421 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 384 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1427 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 385 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1433 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 389 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1439 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 390 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1445 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 391 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1451 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 392 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1457 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 396 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1463 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 397 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1469 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 398 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1475 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 402 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1481 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 403 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1487 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 408 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1493 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 409 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1499 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 410 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1506 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 412 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1513 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 418 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1519 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 422 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1525 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 423 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1531 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 424 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1537 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 425 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1543 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 426 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1549 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 427 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1555 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 428 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1561 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 429 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1567 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 430 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1573 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 431 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1579 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 432 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1585 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 433 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1591 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 437 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1597 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 438 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1603 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 442 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1609 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 443 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1615 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 444 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1621 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 445 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1627 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 446 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1633 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 447 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1639 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 448 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1645 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 449 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1651 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 450 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1657 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 451 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1663 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 452 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1669 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 453 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1675 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 454 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1681 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 455 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1687 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 460 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1693 "./parser.cpp"
    break;

  case 77: // module: id
#line 461 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1699 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 465 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1705 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 466 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1711 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 467 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1717 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 471 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1723 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 472 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1729 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 476 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1735 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 477 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1741 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 483 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1747 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 484 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1754 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 486 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1761 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 488 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1768 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 490 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1775 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 492 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1782 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 494 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1789 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 499 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1795 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 500 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1802 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 504 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1809 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 507 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1815 "./parser.cpp"
    break;

  case 96: // except_statement: EXCEPT ":" sep statements
#line 517 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_01(yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1821 "./parser.cpp"
    break;

  case 97: // except_statement: EXCEPT expr ":" sep statements
#line 518 "parser.ypp"
                                     { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_02(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1827 "./parser.cpp"
    break;

  case 98: // except_statement: EXCEPT expr AS id ":" sep statements
#line 519 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_03(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1833 "./parser.cpp"
    break;

  case 99: // except_list: except_list except_statement
#line 522 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1839 "./parser.cpp"
    break;

  case 100: // except_list: except_statement
#line 523 "parser.ypp"
                       { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1845 "./parser.cpp"
    break;

  case 101: // try_statement: TRY ":" sep statements except_list
#line 527 "parser.ypp"
                                         { yylhs.value.as < Nonnull<Statement*> > () = TRY_01(yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1851 "./parser.cpp"
    break;

  case 102: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements
#line 528 "parser.ypp"
                                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_02(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1858 "./parser.cpp"
    break;

  case 103: // try_statement: TRY ":" sep statements except_list FINALLY ":" sep statements
#line 530 "parser.ypp"
                                                                    {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_03(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1865 "./parser.cpp"
    break;

  case 104: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements FINALLY ":" sep statements
#line 533 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = TRY_04(yystack_[9].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[8].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1871 "./parser.cpp"
    break;

  case 105: // try_statement: TRY ":" sep statements FINALLY ":" sep statements
#line 534 "parser.ypp"
                                                        { yylhs.value.as < Nonnull<Statement*> > () = TRY_05(yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1877 "./parser.cpp"
    break;

  case 106: // multi_line_statement: if_statement
#line 538 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1883 "./parser.cpp"
    break;

  case 107: // multi_line_statement: for_statement
#line 539 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1889 "./parser.cpp"
    break;

  case 108: // multi_line_statement: try_statement
#line 540 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1895 "./parser.cpp"
    break;

  case 109: // multi_line_statement: function_def
#line 542 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1901 "./parser.cpp"
    break;

  case 110: // multi_line_statement: while_statement
#line 547 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1907 "./parser.cpp"
    break;

  case 111: // decorators_opt: decorators
#line 551 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1913 "./parser.cpp"
    break;

  case 112: // decorators_opt: %empty
#line 552 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1919 "./parser.cpp"
    break;

  case 113: // decorators: decorators "@" expr sep
#line 556 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1925 "./parser.cpp"
    break;

  case 114: // decorators: "@" expr sep
#line 557 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1931 "./parser.cpp"
    break;

  case 115: // parameter: id
#line 561 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1937 "./parser.cpp"
    break;

  case 116: // parameter: id ":" expr
#line 562 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1943 "./parser.cpp"
    break;

  case 117: // parameter: id "=" expr
#line 563 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1949 "./parser.cpp"
    break;

  case 118: // parameter: id ":" expr "=" expr
#line 564 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1955 "./parser.cpp"
    break;

  case 119: // parameter_list: defparameter_list "," "/" comma_opt
#line 568 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1962 "./parser.cpp"
    break;

  case 120: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 570 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1969 "./parser.cpp"
    break;

  case 121: // parameter_list: parameter_list_no_posonly
#line 572 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1975 "./parser.cpp"
    break;

  case 122: // parameter_list_no_posonly: defparameter_list comma_opt
#line 576 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1981 "./parser.cpp"
    break;

  case 123: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 577 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1988 "./parser.cpp"
    break;

  case 124: // parameter_list_no_posonly: parameter_list_starargs
#line 579 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1994 "./parser.cpp"
    break;

  case 125: // defparameter_list: defparameter_list "," parameter
#line 583 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2000 "./parser.cpp"
    break;

  case 126: // defparameter_list: parameter
#line 584 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2006 "./parser.cpp"
    break;

  case 127: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 592 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2012 "./parser.cpp"
    break;

  case 128: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 593 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2018 "./parser.cpp"
    break;

  case 129: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 594 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2025 "./parser.cpp"
    break;

  case 130: // parameter_list_starargs: "*" parameter comma_opt
#line 596 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2031 "./parser.cpp"
    break;

  case 131: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 597 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2038 "./parser.cpp"
    break;

  case 132: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 599 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2045 "./parser.cpp"
    break;

  case 133: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 601 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2052 "./parser.cpp"
    break;

  case 134: // parameter_list_starargs: "**" parameter comma_opt
#line 603 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2058 "./parser.cpp"
    break;

  case 135: // parameter_list_opt: parameter_list
#line 607 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 2064 "./parser.cpp"
    break;

  case 136: // parameter_list_opt: %empty
#line 608 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 2070 "./parser.cpp"
    break;

  case 139: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 618 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2076 "./parser.cpp"
    break;

  case 140: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 620 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2082 "./parser.cpp"
    break;

  case 141: // global_statement: GLOBAL expr_list
#line 630 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2088 "./parser.cpp"
    break;

  case 142: // ternary_if_statement: expr IF expr ELSE expr
#line 634 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2094 "./parser.cpp"
    break;

  case 143: // nonlocal_statement: NONLOCAL expr_list
#line 638 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2100 "./parser.cpp"
    break;

  case 144: // elif_statement: ELIF expr ":" sep statements
#line 642 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2106 "./parser.cpp"
    break;

  case 145: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 643 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2113 "./parser.cpp"
    break;

  case 146: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 645 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2120 "./parser.cpp"
    break;

  case 147: // if_statement: IF expr ":" body_stmts
#line 650 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2128 "./parser.cpp"
    break;

  case 148: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 653 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2136 "./parser.cpp"
    break;

  case 149: // if_statement: IF expr ":" body_stmts elif_statement
#line 656 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2143 "./parser.cpp"
    break;

  case 150: // target_list: target_list tuple_item "="
#line 661 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2149 "./parser.cpp"
    break;

  case 151: // target_list: tuple_item "="
#line 662 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2155 "./parser.cpp"
    break;

  case 152: // assignment_statement: target_list tuple_item
#line 666 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2161 "./parser.cpp"
    break;

  case 153: // expression_statment: expr
#line 671 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2167 "./parser.cpp"
    break;

  case 154: // string: string string_literal
#line 675 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2173 "./parser.cpp"
    break;

  case 155: // string: string_literal
#line 676 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2181 "./parser.cpp"
    break;

  case 156: // string: id string_literal
#line 679 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2189 "./parser.cpp"
    break;

  case 157: // string: string id string_literal
#line 682 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2197 "./parser.cpp"
    break;

  case 158: // expr_list_opt: expr_list
#line 688 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2203 "./parser.cpp"
    break;

  case 159: // expr_list_opt: %empty
#line 689 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2209 "./parser.cpp"
    break;

  case 160: // expr_list: expr_list "," expr
#line 693 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2215 "./parser.cpp"
    break;

  case 161: // expr_list: expr
#line 694 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2221 "./parser.cpp"
    break;

  case 162: // expr_for_list: expr_for_list "," expr
#line 707 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2227 "./parser.cpp"
    break;

  case 163: // expr_for_list: expr
#line 708 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2233 "./parser.cpp"
    break;

  case 164: // dict: expr ":" expr
#line 712 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2239 "./parser.cpp"
    break;

  case 165: // dict_list: dict_list "," dict
#line 715 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2245 "./parser.cpp"
    break;

  case 166: // dict_list: dict
#line 716 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2251 "./parser.cpp"
    break;

  case 167: // call_arguement_list: expr_list_opt
#line 720 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2257 "./parser.cpp"
    break;

  case 168: // call_arguement_list: expr_list ","
#line 721 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2263 "./parser.cpp"
    break;

  case 169: // keyword_item: id "=" expr
#line 726 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2269 "./parser.cpp"
    break;

  case 170: // keyword_item: "**" expr
#line 727 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2275 "./parser.cpp"
    break;

  case 171: // keyword_items: keyword_items "," keyword_item
#line 731 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2281 "./parser.cpp"
    break;

  case 172: // keyword_items: keyword_item
#line 732 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2287 "./parser.cpp"
    break;

  case 173: // primary: id
#line 737 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2293 "./parser.cpp"
    break;

  case 174: // primary: string
#line 738 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2299 "./parser.cpp"
    break;

  case 175: // primary: expr "." id
#line 739 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2305 "./parser.cpp"
    break;

  case 176: // function_call: primary "(" call_arguement_list ")"
#line 743 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2311 "./parser.cpp"
    break;

  case 177: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 744 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2318 "./parser.cpp"
    break;

  case 178: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 746 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2325 "./parser.cpp"
    break;

  case 179: // function_call: primary "(" keyword_items comma_opt ")"
#line 748 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2331 "./parser.cpp"
    break;

  case 180: // function_call: function_call "(" call_arguement_list ")"
#line 749 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2337 "./parser.cpp"
    break;

  case 181: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 750 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2344 "./parser.cpp"
    break;

  case 182: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 752 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2351 "./parser.cpp"
    break;

  case 183: // function_call: function_call "(" keyword_items comma_opt ")"
#line 754 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2357 "./parser.cpp"
    break;

  case 184: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 761 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2363 "./parser.cpp"
    break;

  case 185: // expr: id
#line 765 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2369 "./parser.cpp"
    break;

  case 186: // expr: integer_literal
#line 766 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2378 "./parser.cpp"
    break;

  case 187: // expr: string
#line 770 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2384 "./parser.cpp"
    break;

  case 188: // expr: real_literal
#line 771 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2390 "./parser.cpp"
    break;

  case 189: // expr: image_literal
#line 772 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2399 "./parser.cpp"
    break;

  case 190: // expr: TRUE
#line 776 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2405 "./parser.cpp"
    break;

  case 191: // expr: FALSE
#line 777 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2411 "./parser.cpp"
    break;

  case 192: // expr: NONE
#line 778 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2417 "./parser.cpp"
    break;

  case 193: // expr: "..."
#line 779 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2423 "./parser.cpp"
    break;

  case 194: // expr: "(" expr ")"
#line 780 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2429 "./parser.cpp"
    break;

  case 195: // expr: "(" ")"
#line 781 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2435 "./parser.cpp"
    break;

  case 196: // expr: function_call
#line 782 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2441 "./parser.cpp"
    break;

  case 197: // expr: "[" expr_list_opt "]"
#line 784 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2447 "./parser.cpp"
    break;

  case 198: // expr: "[" expr_list "," "]"
#line 785 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2453 "./parser.cpp"
    break;

  case 199: // expr: "{" expr_list "}"
#line 786 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2459 "./parser.cpp"
    break;

  case 200: // expr: "{" expr_list "," "}"
#line 787 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2465 "./parser.cpp"
    break;

  case 201: // expr: expr "." id
#line 788 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2471 "./parser.cpp"
    break;

  case 202: // expr: "{" "}"
#line 790 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2477 "./parser.cpp"
    break;

  case 203: // expr: "{" dict_list "}"
#line 791 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2483 "./parser.cpp"
    break;

  case 204: // expr: id ":=" expr
#line 795 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2489 "./parser.cpp"
    break;

  case 205: // expr: "*" expr
#line 796 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2495 "./parser.cpp"
    break;

  case 206: // expr: expr "+" expr
#line 798 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2501 "./parser.cpp"
    break;

  case 207: // expr: expr "-" expr
#line 799 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2507 "./parser.cpp"
    break;

  case 208: // expr: expr "*" expr
#line 800 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2513 "./parser.cpp"
    break;

  case 209: // expr: expr "/" expr
#line 801 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2519 "./parser.cpp"
    break;

  case 210: // expr: expr "%" expr
#line 802 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2525 "./parser.cpp"
    break;

  case 211: // expr: "-" expr
#line 803 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2531 "./parser.cpp"
    break;

  case 212: // expr: "+" expr
#line 804 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2537 "./parser.cpp"
    break;

  case 213: // expr: "~" expr
#line 805 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2543 "./parser.cpp"
    break;

  case 214: // expr: expr "**" expr
#line 806 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2549 "./parser.cpp"
    break;

  case 215: // expr: expr "//" expr
#line 807 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2555 "./parser.cpp"
    break;

  case 216: // expr: expr "@" expr
#line 808 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2561 "./parser.cpp"
    break;

  case 217: // expr: expr "&" expr
#line 810 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2567 "./parser.cpp"
    break;

  case 218: // expr: expr "|" expr
#line 811 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2573 "./parser.cpp"
    break;

  case 219: // expr: expr "^" expr
#line 812 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2579 "./parser.cpp"
    break;

  case 220: // expr: expr "<<" expr
#line 813 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2585 "./parser.cpp"
    break;

  case 221: // expr: expr ">>" expr
#line 814 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2591 "./parser.cpp"
    break;

  case 222: // expr: expr "==" expr
#line 816 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2597 "./parser.cpp"
    break;

  case 223: // expr: expr "!=" expr
#line 817 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2603 "./parser.cpp"
    break;

  case 224: // expr: expr "<" expr
#line 818 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2609 "./parser.cpp"
    break;

  case 225: // expr: expr "<=" expr
#line 819 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2615 "./parser.cpp"
    break;

  case 226: // expr: expr ">" expr
#line 820 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2621 "./parser.cpp"
    break;

  case 227: // expr: expr ">=" expr
#line 821 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2627 "./parser.cpp"
    break;

  case 228: // expr: expr "is" expr
#line 822 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2633 "./parser.cpp"
    break;

  case 229: // expr: expr "is not" expr
#line 823 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2639 "./parser.cpp"
    break;

  case 230: // expr: expr "in" expr
#line 824 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2645 "./parser.cpp"
    break;

  case 231: // expr: expr "not in" expr
#line 825 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2651 "./parser.cpp"
    break;

  case 232: // expr: expr "and" expr
#line 827 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2657 "./parser.cpp"
    break;

  case 233: // expr: expr "or" expr
#line 828 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2663 "./parser.cpp"
    break;

  case 234: // expr: "not" expr
#line 829 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2669 "./parser.cpp"
    break;

  case 235: // expr: ternary_if_statement
#line 836 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2675 "./parser.cpp"
    break;

  case 236: // id: identifier
#line 841 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2681 "./parser.cpp"
    break;

  case 237: // sep: sep sep_one
#line 845 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2687 "./parser.cpp"
    break;

  case 238: // sep: sep_one
#line 846 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2693 "./parser.cpp"
    break;

  case 239: // sep_one: NEWLINE
#line 850 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2699 "./parser.cpp"
    break;

  case 240: // sep_one: COMMENT
#line 851 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2705 "./parser.cpp"
    break;

  case 241: // sep_one: ";"
#line 852 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2711 "./parser.cpp"
    break;


#line 2715 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -362;

  const short  Parser ::yytable_ninf_ = -176;

  const short
   Parser ::yypact_[] =
  {
     546,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  -362,  2443,
    2443,  -362,  -362,  2486,  2511,    51,  2443,  2443,    37,  2443,
    2443,  -362,  2526,    -2,  2443,  2131,  1979,  2443,  2443,  2443,
    2443,  2443,  2443,  -362,  -362,  -362,  -362,  1902,  -362,  -362,
    -362,  -362,  -362,  -362,    -8,  -362,  -362,  -362,  -362,  -362,
      81,  -362,  -362,  -362,  -362,    81,    28,   -13,  -362,  -362,
    -362,  -362,  -362,  2526,  -362,  -362,    52,    16,    61,    64,
     731,    33,    81,  -362,  1979,   913,   977,  1979,    77,  1714,
    1979,   138,   125,  1778,  -362,     6,    15,  -362,   143,  1022,
    -362,    12,  -362,   145,   143,  2329,  -362,    81,  1086,  -362,
     116,  -362,   127,  1131,  -362,   161,  1195,   111,   164,    -4,
      -4,    -4,   797,    -4,  -362,  -362,  -362,    81,    81,   210,
    2443,   166,  -362,   220,  2443,  2403,  2403,  2443,  2443,  2443,
    2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,   210,
    2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,  2443,
    2443,  2443,  2443,  2443,  -362,  -362,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -362,  -362,  -362,  2443,  2443,  -362,  2443,
    -362,  1195,  2443,  2443,   170,  2443,   179,  1195,  2526,  2443,
      34,   210,    46,  -362,   131,  2443,   619,   210,    37,   149,
      81,  2170,  -362,  2443,  -362,  2443,  2019,   175,  -362,  1943,
      81,   189,   797,  -362,  -362,  1714,  2443,  -362,   183,   172,
    -362,   187,    63,   201,   180,   205,  2329,  1259,   429,   429,
     429,   429,  1823,   823,  2152,  1304,   429,   177,   202,   177,
      -4,    -4,    -4,    -4,    -4,   604,   213,   213,   429,   429,
     429,   429,    -4,   429,  1714,  1714,  1714,  1714,  2055,  2095,
     212,  1778,    37,   145,  -362,    37,   145,    48,  -362,    38,
    -362,   -34,  2312,   126,   149,  -362,  -362,  2244,    98,   149,
    -362,  -362,  1131,  1714,  -362,  1368,  2443,  -362,    11,    81,
    1714,  2403,  -362,  2403,   188,  2443,  2403,  -362,  2403,   191,
    2443,  2443,  -362,  1432,  -362,  1496,    81,   211,   211,    37,
     145,  2443,   221,  -362,  -362,   173,   204,    84,  -362,   192,
    -362,   692,  -362,  2418,   236,  -362,   185,   265,  -362,   240,
     218,   135,   210,  -362,  -362,  -362,   246,  -362,   222,    -5,
     247,   249,  -362,  -362,  1714,   247,   249,  -362,   478,  1714,
    -362,  -362,   149,    37,   224,   225,   211,  1560,   619,  -362,
     101,  -362,   207,  -362,  -362,  -362,    81,   868,    81,   257,
     260,  -362,   261,  2443,  -362,    14,   263,   266,     7,  -362,
      36,  2443,  2443,    23,   234,  2443,   239,   241,   243,   301,
    -362,  -362,   253,    81,  -362,  -362,   149,   210,    81,   149,
      81,    81,    81,   210,   275,    29,  -362,  -362,  -362,   280,
    -362,  -362,   619,  2443,  1605,  1714,   279,  -362,  -362,  -362,
    -362,   284,  -362,   149,  -362,   286,   149,  -362,   149,   149,
     149,   266,    30,  -362,   210,   289,    11,  -362,  -362,  1669,
    2443,    81,   181,    81,  -362,   311,  -362,  -362,  -362,   210,
     266,    32,  -362,  -362,   290,   619,  1714,   149,   293,  -362,
     149,   294,   266,  -362,   210,    11,  -362,  -362,    81,  -362,
      81,  -362,   266,   149,   149,  -362,  -362,  -362
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
     112,   186,   188,   189,   236,   155,   191,   190,   192,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    41,     0,     0,     0,     0,   159,     0,     0,
       0,     0,     0,   193,   241,   239,   240,   112,     3,     5,
      67,    71,    72,    63,     0,    70,    69,    68,    65,    66,
       0,    73,   110,   107,   108,    23,     0,   111,   109,    74,
     235,    75,   106,     0,    64,    62,   187,    30,     0,   196,
     153,   185,     4,   238,     0,    28,    39,     0,    43,   161,
       0,     0,    34,   163,    84,     0,     0,    77,   141,     0,
      80,    78,    82,    85,   143,   234,    42,     0,     0,   202,
       0,   166,     0,   161,   195,     0,   161,     0,   158,   211,
     212,   205,     0,   213,     1,     2,   151,    22,    24,     0,
       0,   152,   154,     0,    31,   159,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,   156,     0,
     237,     0,     0,     0,     0,    44,     0,   163,     0,    35,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,   199,     0,   203,     0,     0,   194,   197,     0,
     114,     0,     0,   150,   157,   160,     0,   167,   158,     0,
     172,   138,   185,   158,     0,   138,   232,     0,   230,   228,
     229,   231,   233,   217,   219,    60,   222,   207,   201,   206,
     208,   214,   216,   215,   210,   218,   220,   221,   224,   225,
     226,   227,   209,   223,    47,   204,    29,    40,     0,     0,
       0,   162,     0,    86,    76,     0,    88,     0,     9,   147,
       8,     0,     0,     0,     0,    79,    81,   112,     0,     0,
     200,   165,     0,   164,    32,   160,   159,   198,   136,   113,
     170,   168,   176,   137,     0,     0,   168,   180,   137,     0,
       0,     0,    45,   160,    36,   162,     0,   138,   138,     0,
      89,     0,     0,   149,    12,     0,    18,    21,    14,     0,
       7,   112,    11,     0,     0,   100,   101,    92,    33,   158,
       0,     0,     0,   126,   135,   121,   138,   124,     0,   115,
     138,   138,   171,   179,   169,   138,   138,   183,   142,    61,
      46,    37,     0,   137,     0,     0,   138,     0,     0,    13,
      20,    15,     0,    17,     6,    10,     0,     0,     0,     0,
       0,    99,     0,   168,   184,     0,   138,   138,   137,   122,
       0,     0,     0,   137,     0,   137,     0,     0,     0,    94,
      87,    90,     0,     0,   148,    16,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   137,   130,   137,   134,   138,
     125,   123,     0,     0,   116,   117,     0,   177,   178,   181,
     182,     0,    91,     0,    96,     0,     0,   105,     0,     0,
       0,   138,   137,   127,     0,   138,   137,   119,   139,     0,
       0,     0,   144,     0,    97,   102,   103,    93,   128,     0,
     138,   137,   131,   120,   138,     0,   118,     0,     0,   146,
       0,     0,   138,   132,     0,   137,   140,    95,     0,    98,
       0,   129,   138,     0,     0,   133,   145,   104
  };

  const short
   Parser ::yypgoto_[] =
  {
    -362,  -362,   307,   -38,  -362,  -339,  -362,  -362,  -362,  -362,
    -243,  -362,  -362,  -362,  -362,   -21,  -362,  -362,  -362,  -362,
    -362,  -362,  -362,  -182,     3,  -183,  -174,  -362,  -362,  -362,
    -362,    31,  -362,  -362,  -362,  -362,  -362,   -86,  -362,   -81,
    -342,  -361,  -362,  -113,  -362,  -362,  -362,  -362,   -80,  -362,
    -362,  -362,  -362,  -362,   319,    88,   274,   167,  -362,  -112,
    -273,  -123,  -362,  -362,     2,   141,     0,    55
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    37,    38,   268,   258,   259,   311,   260,   261,   262,
      39,    40,    41,    42,    43,    44,    81,    45,    46,    47,
      48,   167,    49,    50,    91,    92,    93,    86,    51,    52,
      53,   315,   316,    54,    55,    56,    57,   323,   324,   325,
     326,   327,   328,   369,    58,    59,    60,    61,   303,    62,
      63,    64,    65,    66,   207,    67,    82,   101,   102,   209,
     210,   211,    68,    69,    79,    71,   264,    73
  };

  const short
   Parser ::yytable_[] =
  {
      72,    96,    70,   215,   263,   266,   253,   401,   256,   384,
     332,    75,    76,     4,   214,   332,    83,     4,    85,    89,
       4,     4,    95,   394,   312,   187,    98,   103,   106,     4,
     109,   110,   111,   112,   113,     4,     4,   180,     4,    70,
       4,   168,   121,     4,   371,   116,   182,    97,   372,   119,
     117,   120,     4,   425,     4,   118,   139,     4,     4,   142,
     122,   301,   302,   428,   304,   305,   181,   124,   355,   321,
     322,   168,   181,   321,   322,   183,   171,   393,   297,   106,
     306,   298,   177,   300,   444,   402,   206,   169,   399,   184,
    -173,   252,   424,   439,   401,   454,    90,   189,   284,    90,
     332,    78,   289,   255,    88,   299,   456,    94,    90,  -174,
      90,    84,   200,   100,   105,   108,   285,   169,   125,   403,
    -173,   126,   202,   313,   314,   346,   205,   170,   175,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,     4,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    87,   250,   330,    87,
     266,    34,   257,   335,   320,   174,   263,   191,   243,   244,
     178,   245,   170,   170,   246,   247,   179,   205,   193,    35,
      36,   251,   351,   352,   344,   345,   365,   205,    70,   198,
     269,   181,   192,   205,   185,   272,   188,   273,   275,   -19,
     -19,   205,   279,   194,   301,   448,   307,   123,   280,   359,
     313,   360,   196,   208,   213,   199,     4,   374,   376,   203,
     263,   248,   377,   378,   308,   309,   310,    87,   204,    34,
     249,   317,   276,   382,   281,   366,   367,   139,   283,   141,
     142,   143,   144,   145,   170,   267,   278,    35,    36,   282,
     293,   295,   286,   396,   398,   170,   288,   287,   153,  -175,
     201,   296,   343,   263,    70,   333,   212,   212,   337,    70,
     348,   349,   138,   139,   140,   141,   142,   143,   144,   145,
     228,   423,   400,   205,   350,   358,   427,   334,   205,   362,
     353,   363,   338,   339,   153,   364,   342,   368,   373,   370,
     375,   380,   381,   347,   379,   385,   390,   421,   438,   391,
     392,   407,   442,    70,   395,   357,   408,   397,   409,   170,
     410,    87,   254,    87,   170,   411,   422,   453,   265,    87,
     412,   426,   285,   431,   170,   433,   400,   451,   440,   461,
     441,   455,   458,   460,   115,   443,   107,   361,   414,   465,
      70,   417,   449,   452,   176,   400,   386,     0,   389,     0,
     271,     0,     0,     0,   319,   205,     0,     0,   462,   400,
       0,   331,     0,   404,   405,   432,   336,   205,   434,     0,
     435,   436,   437,   413,     0,     0,     0,     0,   416,     0,
     418,   419,   420,    87,     0,     0,    87,   170,    87,     0,
       0,     0,     0,     0,    70,   429,     0,     0,     0,   457,
       0,     0,   459,     0,     0,     0,     0,     0,     0,   329,
       0,     0,   212,     0,   212,   466,   467,   212,     0,   212,
       0,   447,   446,   450,     0,     0,     0,     0,     0,     0,
      87,   170,     0,     0,   170,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,   128,
     464,     0,   329,   329,     0,     0,     0,     0,   170,     0,
       0,   170,     0,   170,   170,   170,   134,   135,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,   138,   139,
     140,   141,   142,   143,   144,   145,     0,   146,   147,   148,
       0,     0,   170,     0,     0,   170,   329,     0,     0,   329,
     153,     0,     0,     0,   406,     0,     0,     0,   170,   170,
       0,     0,     0,     0,     0,   134,   135,     0,   415,     0,
       0,     0,     0,     0,   329,     0,   329,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,   153,
       9,    10,     0,   329,    11,   329,    12,   329,    13,     0,
       0,     0,     0,    14,    15,    16,    17,    18,     0,     0,
     329,     0,   329,    19,    20,     0,    21,    22,    23,    24,
       0,     0,     0,     0,     0,   329,   329,     0,     0,     0,
       0,     0,    25,    26,    27,    28,     0,    29,    30,     0,
      31,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,    33,     1,     2,     3,     4,    34,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,    13,     0,     0,    35,    36,     0,    15,    16,     0,
      18,   134,   135,     0,     0,     0,    19,    20,     0,    21,
      22,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,   147,   148,    25,    26,    27,    28,     0,
      29,    30,     0,     0,     0,   153,    32,     0,     0,     0,
       0,     0,     0,     0,    33,     1,     2,     3,     4,    34,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,    35,    36,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,    19,
      20,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,    25,    26,
      27,    28,     0,    29,    30,     0,    31,     0,     0,    32,
       0,   128,     0,   129,   130,   131,   132,    33,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,     0,  -161,     0,  -161,     0,   137,     0,     0,   354,
     138,   139,   140,   141,   142,   143,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   127,
       0,     0,   153,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   128,     0,   129,
     130,   131,   132,   166,     0,     0,   133,     0,     0,     0,
       0,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,   137,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,    34,   153,     0,
     127,   387,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,   147,   148,     0,    35,    36,     0,   128,   166,
     129,   130,   131,   132,   153,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   388,     0,     0,
       0,     0,     0,   137,     0,   127,     0,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   128,     0,   129,   130,   131,   132,   153,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     134,   135,     0,     0,   172,     0,     0,     0,   137,     0,
     166,     0,   138,   139,   140,   141,   142,   143,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,     0,   127,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,   128,     0,   129,
     130,   131,   132,     0,     0,   166,   133,     0,     0,     0,
       0,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,   137,     0,   127,     0,   138,   139,   140,   141,
     142,   143,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   128,     0,   129,   130,   131,   132,   153,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   186,     0,     0,     0,     0,     0,   137,     0,   166,
       0,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,   149,   150,   151,   152,     0,   127,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,     0,     0,   166,   133,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   190,     0,     0,     0,     0,
       0,   137,     0,   127,     0,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   128,     0,   129,   130,   131,   132,   153,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     195,     0,     0,     0,     0,     0,   137,     0,   166,     0,
     138,   139,   140,   141,   142,   143,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,     0,   127,     0,     0,
       0,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,   130,   131,
     132,     0,     0,   166,   133,     0,     0,     0,     0,     0,
       0,     0,   134,   135,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,     0,   146,   147,   148,   149,   150,   151,   152,
       0,   127,   197,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,   290,     0,     0,     0,     0,     0,   128,
       0,   129,   130,   131,   132,     0,     0,   166,   133,     0,
       0,     0,     0,     0,     0,     0,   134,   135,     0,     0,
       0,     0,     0,     0,   137,     0,   127,     0,   138,   139,
     140,   141,   142,   143,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   128,     0,   129,   130,   131,   132,
     153,     0,     0,   133,     0,     0,     0,     0,     0,     0,
       0,   134,   135,     0,     0,     0,     0,   291,     0,   137,
       0,   166,     0,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   152,     0,
     127,     0,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,     0,     0,   166,   133,     0,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
       0,     0,     0,   137,     0,     0,     0,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,     0,   127,   318,     0,     0,     0,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,     0,     0,
     166,   133,     0,     0,     0,     0,     0,     0,     0,   134,
     135,     0,     0,     0,     0,     0,     0,   137,     0,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,   149,   150,   151,   152,     0,   127,   340,
       0,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,     0,     0,   166,   133,     0,     0,     0,     0,
       0,     0,     0,   134,   135,     0,     0,     0,     0,     0,
       0,   137,     0,     0,     0,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,   149,   150,   151,
     152,     0,   127,   341,     0,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,     0,     0,   166,   133,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   383,
       0,     0,     0,     0,     0,   137,     0,   127,     0,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   128,     0,   129,   130,   131,
     132,   153,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,   134,   135,     0,     0,     0,     0,   430,     0,
     137,     0,   166,     0,   138,   139,   140,   141,   142,   143,
     144,   145,     0,   146,   147,   148,   149,   150,   151,   152,
       0,   127,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   129,   130,   131,   132,     0,     0,   166,   133,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   445,     0,
       0,     0,     0,     0,   137,     0,   127,     0,   138,   139,
     140,   141,   142,   143,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   128,     0,   129,   130,   131,   132,
     153,     0,     0,   133,     0,     0,     0,     0,     0,     0,
       0,   134,   135,     0,     0,     0,     0,     0,     0,   137,
       0,   166,     0,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   152,     0,
     127,     0,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,   130,   131,   132,     0,     0,   166,   133,     0,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
       0,     0,     0,   137,     0,   127,     0,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   128,     0,   129,   130,   131,   132,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,   137,     0,
     166,     0,   138,   139,   140,   141,   142,   143,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,   114,     0,   153,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,   166,     0,     0,     0,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,    19,
      20,     0,    21,    22,    23,    24,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,    25,    26,
      27,    28,     0,    29,    30,     0,    31,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,    20,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      74,    27,    28,     0,    29,    30,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,    20,    33,     0,
       0,   277,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,    25,    74,    27,    28,     0,
      29,    30,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,    33,     0,   104,    20,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    74,    27,    28,     0,
      29,    30,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,    20,    33,     0,   274,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,    25,    74,    27,    28,     0,    29,    30,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
      33,     0,   292,    20,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    74,    27,    28,     0,    29,    30,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,    20,
      33,     0,   294,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,     0,    25,    74,    27,
      28,     0,    29,    30,     0,     0,     0,     0,    32,   134,
       0,     0,     0,     0,     0,     0,    33,    99,    20,     0,
       0,   138,   139,   140,   141,   142,   143,   144,   145,     0,
       0,   147,   148,     0,     0,     0,    25,    74,    27,    28,
       0,    29,    30,   153,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,    33,   270,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     9,    10,
       0,     0,    11,     0,    12,     0,    13,     0,     0,     0,
       0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,    19,    20,     0,    21,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,     0,    29,    30,     0,    31,     0,
       0,    32,     0,     0,     0,     1,     2,     3,     4,    33,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,     0,     0,     0,
      15,    16,     0,    18,     0,     0,     0,     0,     0,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,   128,
       0,   129,   130,   131,   132,     0,     0,     0,    25,    26,
      27,    28,     0,    29,    30,     0,   134,   135,     0,    32,
       0,     0,     0,     0,   137,     0,     0,    33,   138,   139,
     140,   141,   142,   143,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     1,     2,     3,     4,
     153,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,    20,     0,     0,    25,
      74,    27,    28,     0,    29,    30,   206,   356,     0,     0,
      32,     0,     0,     0,    25,    74,    27,    28,    33,    29,
      30,    20,     0,     0,     0,    32,     0,     0,     0,     1,
       2,     3,     4,    33,     5,     6,     7,     8,     0,    25,
      74,    27,    28,     0,    29,    30,     0,     0,     0,     0,
      32,     0,     0,     0,     1,     2,     3,     4,    33,     5,
       6,     7,     8,     0,    20,     0,     0,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,    25,    77,    27,    28,     0,    29,    30,    20,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,    20,     0,     0,    25,    80,    27,
      28,     0,    29,    30,     0,     0,     0,     0,    32,     0,
       0,     0,    25,    26,    27,    28,    33,    29,    30,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,    33
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    22,     0,   126,   186,   188,   180,   368,   182,   348,
     283,     9,    10,     6,   126,   288,    14,     6,    15,    17,
       6,     6,    20,   365,   267,    13,    24,    25,    26,     6,
      28,    29,    30,    31,    32,     6,     6,    31,     6,    37,
       6,     8,    63,     6,    49,    53,    31,    49,    53,    21,
      50,    64,     6,   395,     6,    55,    60,     6,     6,    63,
       8,    23,    24,   402,    98,    99,    60,    51,   311,    62,
      63,     8,    60,    62,    63,    60,    74,    63,   252,    77,
     262,   255,    80,   257,   426,    49,    63,    54,    81,    86,
      57,    57,    63,    63,   455,    63,    62,    97,   211,    62,
     373,    13,   215,    57,    16,    57,   445,    19,    62,    57,
      62,    60,   112,    25,    26,    27,    53,    54,    57,    83,
      57,    57,   120,    25,    26,   299,   124,    72,    51,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,     6,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    15,   178,   281,    18,
     343,    80,    31,   286,   276,    77,   348,    51,   166,   167,
      32,   169,   117,   118,   172,   173,    51,   175,    51,    98,
      99,   179,    98,    99,   297,   298,    51,   185,   186,    78,
     190,    60,    76,   191,    51,   193,    51,   195,   196,    98,
      99,   199,   202,    76,    23,    24,    80,    66,   206,    24,
      25,    26,    51,   125,   126,    51,     6,   330,   331,    53,
     402,    51,   335,   336,    98,    99,   264,    86,     8,    80,
      51,   269,    57,   346,    51,   321,   322,    60,    51,    62,
      63,    64,    65,    66,   189,    96,    57,    98,    99,    77,
     248,   249,    51,   366,   367,   200,    51,    77,    81,    57,
     119,    49,    51,   445,   262,    77,   125,   126,    77,   267,
      49,    98,    59,    60,    61,    62,    63,    64,    65,    66,
     139,   394,   368,   281,    80,    49,   399,   285,   286,    24,
      98,    51,   290,   291,    81,    77,   296,    51,    51,    77,
      51,    77,    77,   301,   342,    98,    49,   393,   421,    49,
      49,    77,   425,   311,    51,   313,    77,    51,    77,   264,
      77,   180,   181,   182,   269,    24,    51,   440,   187,   188,
      77,    51,    53,    49,   279,    49,   422,    26,   424,   452,
      51,    51,    49,    49,    37,   426,    27,   316,   386,   462,
     348,   389,   432,   439,    80,   441,   356,    -1,   358,    -1,
     193,    -1,    -1,    -1,   276,   363,    -1,    -1,   454,   455,
      -1,   283,    -1,   371,   372,   413,   288,   375,   416,    -1,
     418,   419,   420,   383,    -1,    -1,    -1,    -1,   388,    -1,
     390,   391,   392,   252,    -1,    -1,   255,   342,   257,    -1,
      -1,    -1,    -1,    -1,   402,   403,    -1,    -1,    -1,   447,
      -1,    -1,   450,    -1,    -1,    -1,    -1,    -1,    -1,   278,
      -1,    -1,   281,    -1,   283,   463,   464,   286,    -1,   288,
      -1,   431,   430,   433,    -1,    -1,    -1,    -1,    -1,    -1,
     299,   386,    -1,    -1,   389,    -1,    -1,   445,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    30,
     460,    -1,   321,   322,    -1,    -1,    -1,    -1,   413,    -1,
      -1,   416,    -1,   418,   419,   420,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      -1,    -1,   447,    -1,    -1,   450,   365,    -1,    -1,   368,
      81,    -1,    -1,    -1,   373,    -1,    -1,    -1,   463,   464,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,   387,    -1,
      -1,    -1,    -1,    -1,   393,    -1,   395,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    81,
      14,    15,    -1,   422,    18,   424,    20,   426,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,
     439,    -1,   441,    37,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,   454,   455,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      64,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,     3,     4,     5,     6,    80,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    22,    -1,    -1,    98,    99,    -1,    28,    29,    -1,
      31,    47,    48,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    69,    70,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    81,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,    80,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    98,    99,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    30,    -1,    32,    33,    34,    35,    75,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    51,    -1,    53,    -1,    55,    -1,    -1,    97,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    12,
      -1,    -1,    81,    -1,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    30,    -1,    32,
      33,    34,    35,   102,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      12,    13,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    69,    70,    -1,    98,    99,    -1,    30,   102,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    30,    -1,    32,    33,    34,    35,    81,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,
     102,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    12,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,   102,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    12,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,   102,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    12,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    12,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,   102,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,
      -1,   102,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      12,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    12,    77,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,
     102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    12,    77,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    12,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    -1,    -1,   102,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,   102,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    12,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,   102,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,   102,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      12,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    30,    -1,    32,    33,    34,    35,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
     102,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,     0,    -1,    81,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,   102,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    38,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    38,    75,    -1,
      -1,    78,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    77,    38,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    75,    -1,    77,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    77,    38,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      75,    -1,    77,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    38,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    69,    70,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    81,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    64,    -1,
      -1,    67,    -1,    -1,    -1,     3,     4,     5,     6,    75,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    47,    48,    -1,    67,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    75,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,     3,     4,     5,     6,
      81,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    38,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    63,    49,    -1,    -1,
      67,    -1,    -1,    -1,    56,    57,    58,    59,    75,    61,
      62,    38,    -1,    -1,    -1,    67,    -1,    -1,    -1,     3,
       4,     5,     6,    75,     8,     9,    10,    11,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,     3,     4,     5,     6,    75,     8,
       9,    10,    11,    -1,    38,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    38,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    38,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    56,    57,    58,    59,    75,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    27,    28,    29,    30,    31,    37,
      38,    40,    41,    42,    43,    56,    57,    58,    59,    61,
      62,    64,    67,    75,    80,    98,    99,   105,   106,   114,
     115,   116,   117,   118,   119,   121,   122,   123,   124,   126,
     127,   132,   133,   134,   137,   138,   139,   140,   148,   149,
     150,   151,   153,   154,   155,   156,   157,   159,   166,   167,
     168,   169,   170,   171,    57,   168,   168,    57,   159,   168,
      57,   120,   160,   168,    60,   128,   131,   169,   159,   168,
      62,   128,   129,   130,   159,   168,   119,    49,   168,    76,
     159,   161,   162,   168,    77,   159,   168,   158,   159,   168,
     168,   168,   168,   168,     0,   106,    53,   170,   170,    21,
      64,   119,     8,   169,    51,    57,    57,    12,    30,    32,
      33,    34,    35,    39,    47,    48,    49,    55,    59,    60,
      61,    62,    63,    64,    65,    66,    68,    69,    70,    71,
      72,    73,    74,    81,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   102,   125,     8,    54,
     171,   168,    51,    28,   159,    51,   160,   168,    32,    51,
      31,    60,    31,    60,   128,    51,    49,    13,    51,   170,
      49,    51,    76,    51,    76,    49,    51,    77,    78,    51,
     170,   169,   168,    53,     8,   168,    63,   158,   159,   163,
     164,   165,   169,   159,   163,   165,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   169,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,    51,    51,
     119,   168,    57,   130,   169,    57,   130,    31,   108,   109,
     111,   112,   113,   127,   170,   169,   129,    96,   107,   170,
      76,   161,   168,   168,    77,   168,    57,    78,    57,   170,
     168,    51,    77,    51,   147,    53,    51,    77,    51,   147,
      24,    53,    77,   168,    77,   168,    49,   130,   130,    57,
     130,    23,    24,   152,    98,    99,   127,    80,    98,    99,
     107,   110,   114,    25,    26,   135,   136,   107,    77,   159,
     163,    62,    63,   141,   142,   143,   144,   145,   146,   169,
     165,   159,   164,    77,   168,   165,   159,    77,   168,   168,
      77,    77,   170,    51,   147,   147,   130,   168,    49,    98,
      80,    98,    99,    98,    97,   114,    49,   168,    49,    24,
      26,   135,    24,    51,    77,    51,   141,   141,    51,   147,
      77,    49,    53,    51,   147,    51,   147,   147,   147,   107,
      77,    77,   147,    49,   109,    98,   170,    13,    49,   170,
      49,    49,    49,    63,   144,    51,   147,    51,   147,    81,
     141,   145,    49,    83,   168,   168,   169,    77,    77,    77,
      77,    24,    77,   170,   107,   169,   170,   107,   170,   170,
     170,   141,    51,   147,    63,   144,    51,   147,   109,   168,
      53,    49,   107,    49,   107,   107,   107,   107,   147,    63,
     141,    51,   147,   143,   144,    49,   168,   170,    24,   152,
     170,    26,   141,   147,    63,    51,   109,   107,    49,   107,
      49,   147,   141,   170,   170,   147,   107,   107
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,   104,   105,   105,   105,   106,   107,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   115,   116,   117,   118,   118,
     119,   119,   119,   119,   120,   120,   120,   120,   121,   121,
     121,   122,   122,   123,   123,   123,   123,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   128,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   132,   132,   132,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   138,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   141,   142,
     142,   142,   143,   143,   143,   144,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   150,   151,   152,   152,   152,   153,   153,   153,
     154,   154,   155,   156,   157,   157,   157,   157,   158,   158,
     159,   159,   160,   160,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   166,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   170,   170,   171,
     171,   171
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     2,     4,
       1,     2,     4,     5,     1,     2,     4,     5,     1,     2,
       4,     1,     2,     2,     3,     5,     6,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     3,     1,     2,     1,     2,     4,     7,     4,     5,
       7,     8,     5,     9,     7,    11,     4,     5,     7,     2,
       1,     5,     9,     9,    13,     8,     1,     1,     1,     1,
       1,     1,     0,     4,     3,     1,     3,     3,     5,     4,
       5,     1,     2,     3,     1,     3,     1,     4,     5,     7,
       3,     5,     6,     8,     3,     1,     0,     1,     0,     8,
      10,     2,     5,     2,     5,     9,     6,     4,     7,     5,
       3,     2,     2,     1,     2,     1,     2,     3,     1,     0,
       3,     1,     3,     1,     3,     3,     1,     1,     2,     3,
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
  "\"/\"", "\"_\"", "\"->\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"",
  "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"",
  "\"//=\"", "INDENT", "DEDENT", "NEWLINE", "COMMENT", "EOLCOMMENT",
  "TYPE_COMMENT", "\"!=\"", "UNARY", "$accept", "units", "script_unit",
  "statements", "sep_statements", "body_stmts", "statements1",
  "single_line_statements", "single_line_multi_statements",
  "single_line_multi_statements_opt", "statement", "pass_statement",
  "break_statement", "continue_statement", "assert_statement",
  "tuple_item", "for_tuple_item", "raise_statement", "return_statement",
  "delete_statement", "augassign_statement", "augassign_op",
  "ann_assignment_statement", "single_line_statement", "module",
  "module_as_id", "module_item_list", "dot_list", "import_statement",
  "while_statement", "for_statement", "except_statement", "except_list",
  "try_statement", "multi_line_statement", "decorators_opt", "decorators",
  "parameter", "parameter_list", "parameter_list_no_posonly",
  "defparameter_list", "parameter_list_starargs", "parameter_list_opt",
  "comma_opt", "function_def", "global_statement", "ternary_if_statement",
  "nonlocal_statement", "elif_statement", "if_statement", "target_list",
  "assignment_statement", "expression_statment", "string", "expr_list_opt",
  "expr_list", "expr_for_list", "dict", "dict_list", "call_arguement_list",
  "keyword_item", "keyword_items", "primary", "function_call", "expr",
  "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   297,   297,   298,   299,   303,   307,   311,   315,   316,
     320,   321,   325,   326,   327,   328,   331,   334,   340,   343,
     349,   352,   358,   359,   360,   365,   369,   373,   377,   378,
     382,   383,   384,   385,   389,   390,   391,   392,   396,   397,
     398,   402,   403,   408,   409,   410,   412,   418,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     437,   438,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   460,   461,   465,   466,
     467,   471,   472,   476,   477,   483,   484,   486,   488,   490,
     492,   494,   499,   500,   504,   506,   517,   518,   519,   522,
     523,   527,   528,   530,   532,   534,   538,   539,   540,   542,
     547,   551,   552,   556,   557,   561,   562,   563,   564,   568,
     570,   572,   576,   577,   579,   583,   584,   592,   593,   594,
     596,   597,   599,   601,   603,   607,   608,   612,   613,   617,
     619,   630,   634,   638,   642,   643,   645,   650,   653,   656,
     661,   662,   666,   671,   675,   676,   679,   682,   688,   689,
     693,   694,   707,   708,   712,   715,   716,   720,   721,   726,
     727,   731,   732,   737,   738,   739,   743,   744,   746,   748,
     749,   750,   752,   754,   761,   765,   766,   770,   771,   772,
     776,   777,   778,   779,   780,   781,   782,   784,   785,   786,
     787,   788,   790,   791,   795,   796,   798,   799,   800,   801,
     802,   803,   804,   805,   806,   807,   808,   810,   811,   812,
     813,   814,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   827,   828,   829,   836,   841,   845,   846,   850,
     851,   852
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
#line 3790 "./parser.cpp"

#line 855 "parser.ypp"
