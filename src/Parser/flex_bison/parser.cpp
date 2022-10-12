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
      case symbol_kind::S_with_item: // with_item
      case symbol_kind::S_with_statement: // with_statement
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
      case symbol_kind::S_with_item_list: // with_item_list
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
      case symbol_kind::S_with_item: // with_item
      case symbol_kind::S_with_statement: // with_statement
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
      case symbol_kind::S_with_item_list: // with_item_list
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
      case symbol_kind::S_with_item: // with_item
      case symbol_kind::S_with_statement: // with_statement
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
      case symbol_kind::S_with_item_list: // with_item_list
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
      case symbol_kind::S_with_item: // with_item
      case symbol_kind::S_with_statement: // with_statement
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
      case symbol_kind::S_with_item_list: // with_item_list
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
      case symbol_kind::S_with_item: // with_item
      case symbol_kind::S_with_statement: // with_statement
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
      case symbol_kind::S_with_item_list: // with_item_list
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
#line 300 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1254 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 301 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1260 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 306 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1266 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 310 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1272 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 314 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1278 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 318 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1284 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 319 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1290 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 323 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1296 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 324 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1302 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 328 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1308 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 329 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1314 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 330 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1320 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 331 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1328 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 334 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1336 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 337 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1344 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 343 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1352 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 346 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1360 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 352 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1368 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 355 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1376 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 361 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1382 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 362 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1388 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 363 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1394 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 368 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1400 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 372 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1406 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 376 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1412 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 380 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1418 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 381 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1424 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 385 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1430 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 386 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1436 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 387 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1442 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 388 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1448 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 392 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1454 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 393 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1460 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 394 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1466 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 395 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1472 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 399 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1478 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 400 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1484 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 401 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1490 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 405 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1496 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 406 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1502 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 411 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1508 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 412 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1514 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 413 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1521 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 415 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1528 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 421 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1534 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 425 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1540 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 426 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1546 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 427 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1552 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 428 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1558 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 429 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1564 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 430 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1570 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 431 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1576 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 432 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1582 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 433 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1588 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 434 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1594 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 435 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1600 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 436 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1606 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 440 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1612 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 441 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1618 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 445 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1624 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 446 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1630 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 447 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1636 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 448 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1642 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 449 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1648 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 450 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1654 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 451 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1660 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 452 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1666 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 453 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1672 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 454 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1678 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 455 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1684 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 456 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1690 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 457 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1696 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 458 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1702 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 463 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1708 "./parser.cpp"
    break;

  case 77: // module: id
#line 464 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1714 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 468 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1720 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 469 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1726 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 470 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1732 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 474 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1738 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 475 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1744 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 479 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1750 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 480 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1756 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 486 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1762 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 487 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1769 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 489 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1776 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 491 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1783 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 493 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1790 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 495 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1797 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 497 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1804 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 502 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1810 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 503 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1817 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 507 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1824 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 510 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1830 "./parser.cpp"
    break;

  case 96: // except_statement: EXCEPT ":" sep statements
#line 520 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_01(yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1836 "./parser.cpp"
    break;

  case 97: // except_statement: EXCEPT expr ":" sep statements
#line 521 "parser.ypp"
                                     { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_02(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1842 "./parser.cpp"
    break;

  case 98: // except_statement: EXCEPT expr AS id ":" sep statements
#line 522 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_03(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1848 "./parser.cpp"
    break;

  case 99: // except_list: except_list except_statement
#line 525 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1854 "./parser.cpp"
    break;

  case 100: // except_list: except_statement
#line 526 "parser.ypp"
                       { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1860 "./parser.cpp"
    break;

  case 101: // try_statement: TRY ":" sep statements except_list
#line 530 "parser.ypp"
                                         { yylhs.value.as < Nonnull<Statement*> > () = TRY_01(yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1866 "./parser.cpp"
    break;

  case 102: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements
#line 531 "parser.ypp"
                                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_02(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1873 "./parser.cpp"
    break;

  case 103: // try_statement: TRY ":" sep statements except_list FINALLY ":" sep statements
#line 533 "parser.ypp"
                                                                    {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_03(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1880 "./parser.cpp"
    break;

  case 104: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements FINALLY ":" sep statements
#line 536 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = TRY_04(yystack_[9].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[8].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1886 "./parser.cpp"
    break;

  case 105: // try_statement: TRY ":" sep statements FINALLY ":" sep statements
#line 537 "parser.ypp"
                                                        { yylhs.value.as < Nonnull<Statement*> > () = TRY_05(yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1892 "./parser.cpp"
    break;

  case 106: // with_item: expr
#line 541 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1898 "./parser.cpp"
    break;

  case 107: // with_item: expr AS expr
#line 542 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1904 "./parser.cpp"
    break;

  case 108: // with_item_list: with_item_list "," with_item
#line 546 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1910 "./parser.cpp"
    break;

  case 109: // with_item_list: with_item
#line 547 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1916 "./parser.cpp"
    break;

  case 110: // with_statement: WITH with_item_list ":" sep statements
#line 551 "parser.ypp"
                                             { yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1922 "./parser.cpp"
    break;

  case 111: // with_statement: WITH "(" with_item_list "," ")" ":" sep statements
#line 552 "parser.ypp"
                                                         {
        yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1929 "./parser.cpp"
    break;

  case 112: // multi_line_statement: if_statement
#line 561 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1935 "./parser.cpp"
    break;

  case 113: // multi_line_statement: for_statement
#line 562 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1941 "./parser.cpp"
    break;

  case 114: // multi_line_statement: try_statement
#line 563 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1947 "./parser.cpp"
    break;

  case 115: // multi_line_statement: with_statement
#line 564 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1953 "./parser.cpp"
    break;

  case 116: // multi_line_statement: function_def
#line 565 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1959 "./parser.cpp"
    break;

  case 117: // multi_line_statement: while_statement
#line 570 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1965 "./parser.cpp"
    break;

  case 118: // decorators_opt: decorators
#line 574 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1971 "./parser.cpp"
    break;

  case 119: // decorators_opt: %empty
#line 575 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1977 "./parser.cpp"
    break;

  case 120: // decorators: decorators "@" expr sep
#line 579 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1983 "./parser.cpp"
    break;

  case 121: // decorators: "@" expr sep
#line 580 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1989 "./parser.cpp"
    break;

  case 122: // parameter: id
#line 584 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1995 "./parser.cpp"
    break;

  case 123: // parameter: id ":" expr
#line 585 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2001 "./parser.cpp"
    break;

  case 124: // parameter: id "=" expr
#line 586 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2007 "./parser.cpp"
    break;

  case 125: // parameter: id ":" expr "=" expr
#line 587 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2013 "./parser.cpp"
    break;

  case 126: // parameter_list: defparameter_list "," "/" comma_opt
#line 591 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2020 "./parser.cpp"
    break;

  case 127: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 593 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2027 "./parser.cpp"
    break;

  case 128: // parameter_list: parameter_list_no_posonly
#line 595 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2033 "./parser.cpp"
    break;

  case 129: // parameter_list_no_posonly: defparameter_list comma_opt
#line 599 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2039 "./parser.cpp"
    break;

  case 130: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 600 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2046 "./parser.cpp"
    break;

  case 131: // parameter_list_no_posonly: parameter_list_starargs
#line 602 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2052 "./parser.cpp"
    break;

  case 132: // defparameter_list: defparameter_list "," parameter
#line 606 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2058 "./parser.cpp"
    break;

  case 133: // defparameter_list: parameter
#line 607 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2064 "./parser.cpp"
    break;

  case 134: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 615 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2070 "./parser.cpp"
    break;

  case 135: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 616 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2076 "./parser.cpp"
    break;

  case 136: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 617 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2083 "./parser.cpp"
    break;

  case 137: // parameter_list_starargs: "*" parameter comma_opt
#line 619 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2089 "./parser.cpp"
    break;

  case 138: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 620 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2096 "./parser.cpp"
    break;

  case 139: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 622 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2103 "./parser.cpp"
    break;

  case 140: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 624 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2110 "./parser.cpp"
    break;

  case 141: // parameter_list_starargs: "**" parameter comma_opt
#line 626 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2116 "./parser.cpp"
    break;

  case 142: // parameter_list_opt: parameter_list
#line 630 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 2122 "./parser.cpp"
    break;

  case 143: // parameter_list_opt: %empty
#line 631 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 2128 "./parser.cpp"
    break;

  case 146: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 641 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2134 "./parser.cpp"
    break;

  case 147: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 643 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2140 "./parser.cpp"
    break;

  case 148: // global_statement: GLOBAL expr_list
#line 653 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2146 "./parser.cpp"
    break;

  case 149: // ternary_if_statement: expr IF expr ELSE expr
#line 657 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2152 "./parser.cpp"
    break;

  case 150: // nonlocal_statement: NONLOCAL expr_list
#line 661 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2158 "./parser.cpp"
    break;

  case 151: // elif_statement: ELIF expr ":" sep statements
#line 665 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2164 "./parser.cpp"
    break;

  case 152: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 666 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2171 "./parser.cpp"
    break;

  case 153: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 668 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2178 "./parser.cpp"
    break;

  case 154: // if_statement: IF expr ":" body_stmts
#line 673 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2186 "./parser.cpp"
    break;

  case 155: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 676 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2194 "./parser.cpp"
    break;

  case 156: // if_statement: IF expr ":" body_stmts elif_statement
#line 679 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2201 "./parser.cpp"
    break;

  case 157: // target_list: target_list tuple_item "="
#line 684 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2207 "./parser.cpp"
    break;

  case 158: // target_list: tuple_item "="
#line 685 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2213 "./parser.cpp"
    break;

  case 159: // assignment_statement: target_list tuple_item
#line 689 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2219 "./parser.cpp"
    break;

  case 160: // expression_statment: expr
#line 694 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2225 "./parser.cpp"
    break;

  case 161: // string: string string_literal
#line 698 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2231 "./parser.cpp"
    break;

  case 162: // string: string_literal
#line 699 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2239 "./parser.cpp"
    break;

  case 163: // string: id string_literal
#line 702 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2247 "./parser.cpp"
    break;

  case 164: // string: string id string_literal
#line 705 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2255 "./parser.cpp"
    break;

  case 165: // expr_list_opt: expr_list
#line 711 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2261 "./parser.cpp"
    break;

  case 166: // expr_list_opt: %empty
#line 712 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2267 "./parser.cpp"
    break;

  case 167: // expr_list: expr_list "," expr
#line 716 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2273 "./parser.cpp"
    break;

  case 168: // expr_list: expr
#line 717 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2279 "./parser.cpp"
    break;

  case 169: // expr_for_list: expr_for_list "," expr
#line 730 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2285 "./parser.cpp"
    break;

  case 170: // expr_for_list: expr
#line 731 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2291 "./parser.cpp"
    break;

  case 171: // dict: expr ":" expr
#line 735 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2297 "./parser.cpp"
    break;

  case 172: // dict_list: dict_list "," dict
#line 738 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2303 "./parser.cpp"
    break;

  case 173: // dict_list: dict
#line 739 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2309 "./parser.cpp"
    break;

  case 174: // call_arguement_list: expr_list_opt
#line 743 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2315 "./parser.cpp"
    break;

  case 175: // call_arguement_list: expr_list ","
#line 744 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2321 "./parser.cpp"
    break;

  case 176: // keyword_item: id "=" expr
#line 749 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2327 "./parser.cpp"
    break;

  case 177: // keyword_item: "**" expr
#line 750 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2333 "./parser.cpp"
    break;

  case 178: // keyword_items: keyword_items "," keyword_item
#line 754 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2339 "./parser.cpp"
    break;

  case 179: // keyword_items: keyword_item
#line 755 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2345 "./parser.cpp"
    break;

  case 180: // primary: id
#line 760 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2351 "./parser.cpp"
    break;

  case 181: // primary: string
#line 761 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2357 "./parser.cpp"
    break;

  case 182: // primary: expr "." id
#line 762 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2363 "./parser.cpp"
    break;

  case 183: // function_call: primary "(" call_arguement_list ")"
#line 766 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2369 "./parser.cpp"
    break;

  case 184: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 767 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2376 "./parser.cpp"
    break;

  case 185: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 769 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2383 "./parser.cpp"
    break;

  case 186: // function_call: primary "(" keyword_items comma_opt ")"
#line 771 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2389 "./parser.cpp"
    break;

  case 187: // function_call: function_call "(" call_arguement_list ")"
#line 772 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2395 "./parser.cpp"
    break;

  case 188: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 773 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2402 "./parser.cpp"
    break;

  case 189: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 775 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2409 "./parser.cpp"
    break;

  case 190: // function_call: function_call "(" keyword_items comma_opt ")"
#line 777 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2415 "./parser.cpp"
    break;

  case 191: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 784 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2421 "./parser.cpp"
    break;

  case 192: // expr: id
#line 788 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2427 "./parser.cpp"
    break;

  case 193: // expr: integer_literal
#line 789 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2436 "./parser.cpp"
    break;

  case 194: // expr: string
#line 793 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2442 "./parser.cpp"
    break;

  case 195: // expr: real_literal
#line 794 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2448 "./parser.cpp"
    break;

  case 196: // expr: image_literal
#line 795 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2457 "./parser.cpp"
    break;

  case 197: // expr: TRUE
#line 799 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2463 "./parser.cpp"
    break;

  case 198: // expr: FALSE
#line 800 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2469 "./parser.cpp"
    break;

  case 199: // expr: NONE
#line 801 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2475 "./parser.cpp"
    break;

  case 200: // expr: "..."
#line 802 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2481 "./parser.cpp"
    break;

  case 201: // expr: "(" expr ")"
#line 803 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2487 "./parser.cpp"
    break;

  case 202: // expr: "(" ")"
#line 804 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2493 "./parser.cpp"
    break;

  case 203: // expr: function_call
#line 805 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2499 "./parser.cpp"
    break;

  case 204: // expr: "[" expr_list_opt "]"
#line 807 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2505 "./parser.cpp"
    break;

  case 205: // expr: "[" expr_list "," "]"
#line 808 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2511 "./parser.cpp"
    break;

  case 206: // expr: "{" expr_list "}"
#line 809 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2517 "./parser.cpp"
    break;

  case 207: // expr: "{" expr_list "," "}"
#line 810 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2523 "./parser.cpp"
    break;

  case 208: // expr: expr "." id
#line 811 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2529 "./parser.cpp"
    break;

  case 209: // expr: "{" "}"
#line 813 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2535 "./parser.cpp"
    break;

  case 210: // expr: "{" dict_list "}"
#line 814 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2541 "./parser.cpp"
    break;

  case 211: // expr: id ":=" expr
#line 818 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2547 "./parser.cpp"
    break;

  case 212: // expr: "*" expr
#line 819 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2553 "./parser.cpp"
    break;

  case 213: // expr: expr "+" expr
#line 821 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2559 "./parser.cpp"
    break;

  case 214: // expr: expr "-" expr
#line 822 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2565 "./parser.cpp"
    break;

  case 215: // expr: expr "*" expr
#line 823 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2571 "./parser.cpp"
    break;

  case 216: // expr: expr "/" expr
#line 824 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2577 "./parser.cpp"
    break;

  case 217: // expr: expr "%" expr
#line 825 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2583 "./parser.cpp"
    break;

  case 218: // expr: "-" expr
#line 826 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2589 "./parser.cpp"
    break;

  case 219: // expr: "+" expr
#line 827 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2595 "./parser.cpp"
    break;

  case 220: // expr: "~" expr
#line 828 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2601 "./parser.cpp"
    break;

  case 221: // expr: expr "**" expr
#line 829 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2607 "./parser.cpp"
    break;

  case 222: // expr: expr "//" expr
#line 830 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2613 "./parser.cpp"
    break;

  case 223: // expr: expr "@" expr
#line 831 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2619 "./parser.cpp"
    break;

  case 224: // expr: expr "&" expr
#line 833 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2625 "./parser.cpp"
    break;

  case 225: // expr: expr "|" expr
#line 834 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2631 "./parser.cpp"
    break;

  case 226: // expr: expr "^" expr
#line 835 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2637 "./parser.cpp"
    break;

  case 227: // expr: expr "<<" expr
#line 836 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2643 "./parser.cpp"
    break;

  case 228: // expr: expr ">>" expr
#line 837 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2649 "./parser.cpp"
    break;

  case 229: // expr: expr "==" expr
#line 839 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2655 "./parser.cpp"
    break;

  case 230: // expr: expr "!=" expr
#line 840 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2661 "./parser.cpp"
    break;

  case 231: // expr: expr "<" expr
#line 841 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2667 "./parser.cpp"
    break;

  case 232: // expr: expr "<=" expr
#line 842 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2673 "./parser.cpp"
    break;

  case 233: // expr: expr ">" expr
#line 843 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2679 "./parser.cpp"
    break;

  case 234: // expr: expr ">=" expr
#line 844 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2685 "./parser.cpp"
    break;

  case 235: // expr: expr "is" expr
#line 845 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2691 "./parser.cpp"
    break;

  case 236: // expr: expr "is not" expr
#line 846 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2697 "./parser.cpp"
    break;

  case 237: // expr: expr "in" expr
#line 847 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2703 "./parser.cpp"
    break;

  case 238: // expr: expr "not in" expr
#line 848 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2709 "./parser.cpp"
    break;

  case 239: // expr: expr "and" expr
#line 850 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2715 "./parser.cpp"
    break;

  case 240: // expr: expr "or" expr
#line 851 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2721 "./parser.cpp"
    break;

  case 241: // expr: "not" expr
#line 852 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2727 "./parser.cpp"
    break;

  case 242: // expr: ternary_if_statement
#line 859 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2733 "./parser.cpp"
    break;

  case 243: // id: identifier
#line 864 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2739 "./parser.cpp"
    break;

  case 244: // sep: sep sep_one
#line 868 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2745 "./parser.cpp"
    break;

  case 245: // sep: sep_one
#line 869 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2751 "./parser.cpp"
    break;

  case 246: // sep_one: NEWLINE
#line 873 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2757 "./parser.cpp"
    break;

  case 247: // sep_one: COMMENT
#line 874 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2763 "./parser.cpp"
    break;

  case 248: // sep_one: ";"
#line 875 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2769 "./parser.cpp"
    break;


#line 2773 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -381;

  const short  Parser ::yytable_ninf_ = -183;

  const short
   Parser ::yypact_[] =
  {
     625,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  2552,
    2552,  -381,  -381,  2595,  2620,    42,  2552,  2552,    38,  2552,
    2552,  -381,  2635,   -11,  2552,  2695,  2219,  2068,  2552,  2552,
    2552,  2552,  2552,  2552,  -381,  -381,  -381,  -381,  2026,  -381,
    -381,  -381,  -381,  -381,  -381,    -7,  -381,  -381,  -381,  -381,
    -381,   118,  -381,  -381,  -381,  -381,  -381,   118,    32,    25,
    -381,  -381,  -381,  -381,  -381,  2635,  -381,  -381,    48,    60,
      69,    77,   810,    22,   118,  -381,  2068,   992,  1056,  2068,
      73,  1838,  2068,   115,   131,  1902,  -381,    67,    52,  -381,
     135,  1101,  -381,    47,  -381,   137,   135,  2438,  -381,   118,
    1165,  2068,  -381,    10,  1210,  -381,    40,  -381,    45,  1274,
    -381,   156,  1319,   -10,   169,    59,    59,    59,   876,    59,
    -381,  -381,  -381,   118,   118,   173,  2552,   177,  -381,   202,
    2552,  2512,  2512,  2552,  2552,  2552,  2552,  2552,  2552,  2552,
    2552,  2552,  2552,  2552,  2552,   173,  2552,  2552,  2552,  2552,
    2552,  2552,  2552,  2552,  2552,  2552,  2552,  2552,  2552,  2552,
    -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  2552,  2552,  -381,  2552,  -381,  1319,  2552,  2552,
     182,  2552,   191,  1319,  2635,  2552,    15,   173,    35,  -381,
     102,  2552,   698,   173,    38,    93,   118,   208,   493,   118,
    2552,  2552,  2279,  -381,  2552,  -381,  2552,  2094,   209,  -381,
     433,   118,   213,   876,  -381,  -381,  1838,  2552,  -381,   220,
     183,  -381,   225,   168,   226,   204,   228,  2438,  1383,  2244,
    2244,  2244,  2244,  1947,   395,   681,  1428,  2244,   278,   230,
     278,    59,    59,    59,    59,    59,   556,   231,   231,  2244,
    2244,  2244,  2244,    59,  2244,  1838,  1838,  1838,  1838,  2106,
    2181,   233,  1902,    38,   137,  -381,    38,   137,    44,  -381,
     161,  -381,   128,  2421,   125,    93,  -381,  -381,  2353,   203,
      93,  2193,    93,  -381,  1838,  -381,  -381,  1274,  1838,  -381,
    1492,  2552,  -381,    11,   118,  1838,  2512,  -381,  2512,   212,
    2552,  2512,  -381,  2512,   227,  2552,  2552,  -381,  1556,  -381,
    1620,   118,   234,   234,    38,   137,  2552,   256,  -381,  -381,
     211,   235,   157,  -381,   216,  -381,   771,  -381,  2527,   261,
    -381,   105,   289,   267,  -381,  -381,   266,   243,    18,   173,
    -381,  -381,  -381,   270,  -381,   246,    64,   273,   285,  -381,
    -381,  1838,   273,   285,  -381,   184,  1838,  -381,  -381,    93,
      38,   260,   269,   234,  1684,   698,  -381,   159,  -381,   251,
    -381,  -381,  -381,   118,   947,   118,   306,   307,  -381,   308,
     118,  2552,  -381,    12,   310,   311,     4,  -381,    21,  2552,
    2552,    17,   281,  2552,   286,   287,   288,   342,  -381,  -381,
     291,   118,  -381,  -381,    93,   173,   118,    93,   118,   118,
     118,    93,   173,   318,    19,  -381,  -381,  -381,   320,  -381,
    -381,   698,  2552,  1729,  1838,   319,  -381,  -381,  -381,  -381,
     325,  -381,    93,  -381,   327,    93,  -381,    93,    93,    93,
    -381,   311,    30,  -381,   173,   326,    11,  -381,  -381,  1793,
    2552,   118,   215,   118,  -381,   352,  -381,  -381,  -381,   173,
     311,    31,  -381,  -381,   328,   698,  1838,    93,   332,  -381,
      93,   335,   311,  -381,   173,    11,  -381,  -381,   118,  -381,
     118,  -381,   311,    93,    93,  -381,  -381,  -381
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
     119,   193,   195,   196,   243,   162,   198,   197,   199,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    41,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,   200,   248,   246,   247,   119,     3,
       5,    67,    71,    72,    63,     0,    70,    69,    68,    65,
      66,     0,    73,   117,   113,   114,   115,    23,     0,   118,
     116,    74,   242,    75,   112,     0,    64,    62,   194,    30,
       0,   203,   160,   192,     4,   245,     0,    28,    39,     0,
      43,   168,     0,     0,    34,   170,    84,     0,     0,    77,
     148,     0,    80,    78,    82,    85,   150,   241,    42,     0,
       0,     0,   109,     0,   106,   209,     0,   173,     0,   168,
     202,     0,   168,     0,   165,   218,   219,   212,     0,   220,
       1,     2,   158,    22,    24,     0,     0,   159,   161,     0,
      31,   166,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,   163,     0,   244,     0,     0,     0,
       0,    44,     0,   170,     0,    35,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,   106,     0,
       0,     0,     0,   206,     0,   210,     0,     0,   201,   204,
       0,   121,     0,     0,   157,   164,   167,     0,   174,   165,
       0,   179,   145,   192,   165,     0,   145,   239,     0,   237,
     235,   236,   238,   240,   224,   226,    60,   229,   214,   208,
     213,   215,   221,   223,   222,   217,   225,   227,   228,   231,
     232,   233,   234,   216,   230,    47,   211,    29,    40,     0,
       0,     0,   169,     0,    86,    76,     0,    88,     0,     9,
     154,     8,     0,     0,     0,     0,    79,    81,   119,     0,
       0,     0,     0,   108,   107,   207,   172,     0,   171,    32,
     167,   166,   205,   143,   120,   177,   175,   183,   144,     0,
       0,   175,   187,   144,     0,     0,     0,    45,   167,    36,
     169,     0,   145,   145,     0,    89,     0,     0,   156,    12,
       0,    18,    21,    14,     0,     7,   119,    11,     0,     0,
     100,   101,    92,     0,   110,    33,   165,     0,     0,     0,
     133,   142,   128,   145,   131,     0,   122,   145,   145,   178,
     186,   176,   145,   145,   190,   149,    61,    46,    37,     0,
     144,     0,     0,   145,     0,     0,    13,    20,    15,     0,
      17,     6,    10,     0,     0,     0,     0,     0,    99,     0,
       0,   175,   191,     0,   145,   145,   144,   129,     0,     0,
       0,   144,     0,   144,     0,     0,     0,    94,    87,    90,
       0,     0,   155,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   144,   137,   144,   141,   145,   132,
     130,     0,     0,   123,   124,     0,   184,   185,   188,   189,
       0,    91,     0,    96,     0,     0,   105,     0,     0,     0,
     111,   145,   144,   134,     0,   145,   144,   126,   146,     0,
       0,     0,   151,     0,    97,   102,   103,    93,   135,     0,
     145,   144,   138,   127,   145,     0,   125,     0,     0,   153,
       0,     0,   145,   139,     0,   144,   147,    95,     0,    98,
       0,   136,   145,     0,     0,   140,   152,   104
  };

  const short
   Parser ::yypgoto_[] =
  {
    -381,  -381,   351,   -85,  -381,  -356,  -381,  -381,  -381,  -381,
    -236,  -381,  -381,  -381,  -381,   -18,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,  -187,    -1,  -191,  -143,  -381,  -381,  -381,
    -381,    65,  -381,  -381,  -193,   296,  -381,  -381,  -381,  -381,
    -175,  -381,   -56,  -375,  -380,  -381,  -112,  -381,  -381,  -381,
    -381,   -52,  -381,  -381,  -381,  -381,  -381,   374,    36,   321,
     201,  -381,  -119,  -283,  -131,  -381,  -381,     2,   200,     0,
     140
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    38,    39,   279,   269,   270,   326,   271,   272,   273,
      40,    41,    42,    43,    44,    45,    83,    46,    47,    48,
      49,   173,    50,    51,    93,    94,    95,    88,    52,    53,
      54,   330,   331,    55,   102,   103,    56,    57,    58,    59,
     340,   341,   342,   343,   344,   345,   387,    60,    61,    62,
      63,   318,    64,    65,    66,    67,    68,   218,    69,    84,
     107,   108,   220,   221,   222,    70,    71,    81,    73,   275,
      75
  };

  const short
   Parser ::yytable_[] =
  {
      74,   226,    72,   277,    98,   274,   420,   283,   413,   402,
       4,    77,    78,   225,    87,   349,    85,     4,     4,    91,
     349,     4,    97,     4,     4,     4,   100,   104,   109,   112,
     174,   115,   116,   117,   118,   119,     4,     4,    99,   445,
      72,     4,   327,   264,     4,   267,   122,   127,     4,    80,
       4,   123,    90,   125,     4,    96,   128,   124,     4,   199,
     193,   200,   106,   111,   114,   448,   338,   339,   209,   383,
     421,   464,   263,   338,   339,   412,   175,    92,   177,  -180,
     217,   112,   444,   188,   183,   418,   321,   190,   283,   126,
     372,   202,   266,   459,   474,   420,   204,    92,   186,   195,
      92,   314,    86,   198,   422,  -181,    92,   187,   349,   476,
     299,   130,   189,   389,   304,   180,   203,   390,   211,   145,
     312,   205,   148,   313,   181,   315,   131,   187,   213,   376,
     328,   377,   216,   268,   132,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   184,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   187,   384,   385,   347,   261,   219,   224,   277,
     352,   363,   337,    35,   254,   255,   174,   256,   274,     4,
     257,   258,   185,   216,   316,   317,   191,   262,   194,   278,
     325,    36,    37,   216,    72,   332,   280,   334,    35,   282,
     361,   362,   104,   284,   216,   322,   287,   207,   288,   290,
     215,   419,   216,   294,   176,    89,    36,    37,    89,   295,
     210,   300,   175,   323,   324,  -180,   319,   320,   328,   329,
     214,   140,   141,   259,   274,   392,   394,   441,   316,   468,
     395,   396,   260,   144,   145,   146,   147,   148,   149,   150,
     151,   400,   152,   153,   154,   368,   369,   -19,   -19,   281,
     297,   308,   310,   176,   176,   159,   291,   419,   129,   460,
     293,   296,   415,   417,   397,    72,   298,   301,   274,   303,
      72,   302,   311,   104,   472,   360,   419,  -182,    89,   350,
     144,   145,   146,   147,   148,   149,   150,   151,   216,   482,
     419,   443,   351,   216,   354,   365,   447,   355,   356,   366,
     375,   359,   159,   379,   370,   367,   380,   381,   364,   433,
     382,   386,   436,   388,   391,   212,   440,   336,    72,   458,
     374,   223,   223,   462,   348,   176,   393,   398,   145,   353,
     147,   148,   149,   150,   151,   239,   399,   452,   473,   403,
     454,   176,   455,   456,   457,   408,   409,   410,   426,   159,
     481,   414,   416,   427,   428,   429,   430,    72,   431,   442,
     485,   446,   300,   404,   451,   407,   453,   461,   471,   475,
     411,   478,   477,   216,   480,   479,    89,   265,    89,   121,
     463,   423,   424,   276,    89,   216,   378,   197,   486,   487,
     469,   432,   113,   182,     0,   286,   435,     0,   437,   438,
     439,     0,     0,     0,     0,   176,     0,     0,     0,     0,
     176,     0,   176,    72,   449,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,   467,   466,   470,   144,   145,   146,   147,   148,   149,
     150,   151,     0,    89,   153,   154,    89,    72,    89,     0,
       0,    20,     0,     0,     0,     0,   159,     0,   483,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      76,    28,    29,   346,    30,    31,   223,     0,   223,   176,
      33,   223,     0,   223,     0,   133,   201,     0,    34,     0,
       0,   292,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,     0,
       0,     0,   139,     0,     0,     0,     0,     0,   346,   346,
     140,   141,     0,     0,   176,     0,     0,   176,   143,     0,
       0,   176,   144,   145,   146,   147,   148,   149,   150,   151,
      89,   152,   153,   154,   155,   156,   157,   158,     0,     0,
     208,     0,   176,     0,   159,   176,     0,   176,   176,   176,
       0,     0,     0,   346,     0,     0,   346,     0,     0,     0,
       0,   425,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,   140,   141,   434,     0,   176,     0,     0,
     176,     0,   346,     0,   346,   144,   145,   146,   147,   148,
     149,   150,   151,   176,   176,   153,   154,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,   159,     0,     9,
      10,     0,   346,    11,   346,    12,   346,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,     0,     0,   346,
       0,   346,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,   346,   346,     0,     0,     0,     0,
       0,    26,    27,    28,    29,     0,    30,    31,     0,    32,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      34,     1,     2,     3,     4,    35,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,     0,     0,    36,    37,     0,    15,    16,   140,    18,
       0,     0,     0,     0,     0,    19,    20,     0,    21,    22,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     153,   154,     0,     0,    26,    27,    28,    29,     0,    30,
      31,     0,   159,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,    34,     1,     2,     3,     4,    35,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,    13,     0,     0,    36,    37,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,    19,    20,
       0,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,     0,    26,    27,    28,
      29,     0,    30,    31,     0,    32,     0,     0,    33,     0,
     134,     0,   135,   136,   137,   138,    34,     0,     0,   139,
       0,     0,     0,     0,     0,     0,     0,   140,   141,   142,
       0,  -168,     0,  -168,     0,   143,     0,     0,   371,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,   133,     0,
       0,   159,     0,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   134,     0,   135,   136,
     137,   138,   172,     0,     0,   139,     0,     0,     0,     0,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,    35,   159,     0,   133,
     405,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,     0,   134,   172,   135,
     136,   137,   138,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,   140,   141,   406,     0,     0,     0,
       0,     0,   143,     0,   133,     0,   144,   145,   146,   147,
     148,   149,   150,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   134,     0,   135,   136,   137,   138,   159,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,   140,
     141,     0,     0,   178,     0,     0,     0,   143,     0,   172,
       0,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     152,   153,   154,   155,   156,   157,   158,     0,   133,     0,
       0,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,   134,     0,   135,   136,
     137,   138,     0,     0,   172,   139,     0,     0,     0,     0,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,   143,     0,   133,     0,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   134,     0,   135,   136,   137,   138,   159,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     192,     0,     0,     0,     0,     0,   143,     0,   172,     0,
     144,   145,   146,   147,   148,   149,   150,   151,     0,   152,
     153,   154,   155,   156,   157,   158,     0,   133,     0,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,     0,   135,   136,   137,
     138,     0,     0,   172,   139,     0,     0,     0,     0,     0,
       0,     0,   140,   141,   196,     0,     0,     0,     0,     0,
     143,     0,   133,   201,   144,   145,   146,   147,   148,   149,
     150,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     134,     0,   135,   136,   137,   138,   159,     0,     0,   139,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,   143,     0,   172,     0,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,   153,
     154,   155,   156,   157,   158,     0,   133,     0,     0,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
       0,     0,   172,   139,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   206,     0,     0,     0,     0,     0,   143,
       0,   133,     0,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   134,
       0,   135,   136,   137,   138,   159,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,   140,   141,     0,     0,
       0,     0,     0,     0,   143,     0,   172,     0,   144,   145,
     146,   147,   148,   149,   150,   151,     0,   152,   153,   154,
     155,   156,   157,   158,     0,   133,   208,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,     0,
       0,   172,   139,     0,     0,     0,     0,     0,     0,     0,
     140,   141,     0,     0,     0,     0,     0,     0,   143,     0,
     133,     0,   144,   145,   146,   147,   148,   149,   150,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   134,     0,
     135,   136,   137,   138,   159,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,   140,   141,     0,     0,     0,
       0,   306,     0,   143,     0,   172,     0,   144,   145,   146,
     147,   148,   149,   150,   151,     0,   152,   153,   154,   155,
     156,   157,   158,     0,   133,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,   135,   136,   137,   138,     0,     0,
     172,   139,     0,     0,     0,     0,     0,     0,     0,   140,
     141,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     152,   153,   154,   155,   156,   157,   158,     0,   133,   335,
       0,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,     0,   135,   136,
     137,   138,     0,     0,   172,   139,     0,     0,     0,     0,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,   153,   154,   155,   156,   157,
     158,     0,   133,   357,     0,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,   135,   136,   137,   138,     0,     0,   172,   139,
       0,     0,     0,     0,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,   153,
     154,   155,   156,   157,   158,     0,   133,   358,     0,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,     0,   135,   136,   137,   138,
       0,     0,   172,   139,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   401,     0,     0,     0,     0,     0,   143,
       0,   133,     0,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   134,
       0,   135,   136,   137,   138,   159,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,   140,   141,     0,     0,
       0,     0,   450,     0,   143,     0,   172,     0,   144,   145,
     146,   147,   148,   149,   150,   151,     0,   152,   153,   154,
     155,   156,   157,   158,     0,   133,     0,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   135,   136,   137,   138,     0,
       0,   172,   139,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   465,     0,     0,     0,     0,     0,   143,     0,
     133,     0,   144,   145,   146,   147,   148,   149,   150,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   134,     0,
     135,   136,   137,   138,   159,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,   140,   141,     0,     0,     0,
       0,     0,     0,   143,     0,   172,     0,   144,   145,   146,
     147,   148,   149,   150,   151,     0,   152,   153,   154,   155,
     156,   157,   158,     0,   133,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   136,   137,   138,     0,     0,
     172,   139,     0,     0,     0,     0,     0,     0,     0,   140,
     141,     0,     0,     0,     0,     0,     0,   143,     0,   133,
       0,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   134,     0,   135,
     136,   137,   138,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,   141,     0,     0,     0,     0,
       0,     0,   143,     0,   172,     0,   144,   145,   146,   147,
     148,   149,   150,   151,     0,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,     0,   120,     0,   159,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       9,    10,     0,     0,    11,     0,    12,     0,    13,   172,
       0,     0,     0,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    19,    20,     0,    21,    22,    23,    24,
      25,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,    26,    27,    28,    29,     0,    30,    31,     0,
      32,     0,     0,    33,     0,     0,     0,     1,     2,     3,
       4,    34,     5,     6,     7,     8,    20,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,    26,    76,    28,    29,     0,    30,
      31,     0,    20,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,    34,    20,   110,     0,     0,     0,     0,
      26,    76,    28,    29,     0,    30,    31,     0,     0,     0,
       0,    33,    26,    76,    28,    29,     0,    30,    31,    34,
       0,   289,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    34,     0,   307,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,    20,     0,     0,     0,     0,     0,    26,    76,    28,
      29,     0,    30,    31,     0,     0,     0,     0,    33,    26,
      76,    28,    29,     0,    30,    31,    34,    20,   309,     0,
      33,     0,     0,     0,     0,     0,     0,     0,    34,     0,
     333,     0,     0,     0,   134,    26,    76,    28,    29,     0,
      30,    31,     1,     2,     3,     4,    33,     5,     6,     7,
       8,   140,   141,     0,    34,   105,     0,     0,     0,     0,
       0,     0,     0,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,   153,   154,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    76,    28,    29,     0,
      30,    31,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,    34,   285,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     9,    10,     0,
       0,    11,     0,    12,     0,    13,     0,     0,     0,     0,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
      19,    20,     0,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      27,    28,    29,     0,    30,    31,     0,    32,     0,     0,
      33,     0,     0,     0,     1,     2,     3,     4,    34,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,    13,     0,     0,     0,     0,     0,    15,
      16,     0,    18,     0,     0,     0,     0,     0,    19,    20,
       0,    21,    22,     0,     0,     0,     0,     0,   134,     0,
     135,   136,   137,   138,     0,     0,     0,    26,    27,    28,
      29,     0,    30,    31,     0,   140,   141,     0,    33,     0,
       0,     0,     0,   143,     0,     0,    34,   144,   145,   146,
     147,   148,   149,   150,   151,     0,   152,   153,   154,   155,
     156,   157,   158,     0,     0,     1,     2,     3,     4,   159,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,    20,     0,     0,    26,    76,
      28,    29,     0,    30,    31,   217,   373,     0,     0,    33,
       0,     0,     0,    26,    76,    28,    29,    34,    30,    31,
      20,     0,     0,     0,    33,     0,     0,     0,     1,     2,
       3,     4,    34,     5,     6,     7,     8,     0,    26,    76,
      28,    29,     0,    30,    31,     0,     0,     0,     0,    33,
       0,     0,     0,     1,     2,     3,     4,    34,     5,     6,
       7,     8,     0,    20,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,    26,    79,    28,    29,     0,    30,    31,    20,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,    20,     0,     0,    26,    82,    28,    29,
       0,    30,    31,     0,     0,     0,     0,    33,     0,     0,
       0,    26,    27,    28,    29,    34,    30,    31,     1,     2,
       3,     4,    33,     5,     6,     7,     8,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,   101,    28,    29,     0,    30,    31,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      34
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   132,     0,   194,    22,   192,   386,   200,   383,   365,
       6,     9,    10,   132,    15,   298,    14,     6,     6,    17,
     303,     6,    20,     6,     6,     6,    24,    25,    26,    27,
       8,    29,    30,    31,    32,    33,     6,     6,    49,   414,
      38,     6,   278,   186,     6,   188,    53,    65,     6,    13,
       6,    51,    16,    21,     6,    19,     8,    57,     6,    49,
      13,    51,    26,    27,    28,   421,    62,    63,    78,    51,
      49,   446,    57,    62,    63,    63,    54,    62,    76,    57,
      63,    79,    63,    31,    82,    81,   273,    88,   281,    64,
     326,    51,    57,    63,    63,   475,    51,    62,    31,    99,
      62,    57,    60,   101,    83,    57,    62,    60,   391,   465,
     222,    51,    60,    49,   226,    79,    76,    53,   118,    60,
     263,    76,    63,   266,    51,   268,    57,    60,   126,    24,
      25,    26,   130,    31,    57,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    32,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,    60,   338,   339,   296,   184,   131,   132,   360,
     301,   314,   291,    80,   172,   173,     8,   175,   365,     6,
     178,   179,    51,   181,    23,    24,    51,   185,    51,    96,
     275,    98,    99,   191,   192,   280,   196,   282,    80,   199,
     312,   313,   200,   201,   202,    80,   204,    51,   206,   207,
       8,   386,   210,   213,    74,    15,    98,    99,    18,   217,
      51,    53,    54,    98,    99,    57,    98,    99,    25,    26,
      53,    47,    48,    51,   421,   347,   348,   412,    23,    24,
     352,   353,    51,    59,    60,    61,    62,    63,    64,    65,
      66,   363,    68,    69,    70,    98,    99,    98,    99,    51,
      77,   259,   260,   123,   124,    81,    57,   442,    68,   444,
      57,    51,   384,   385,   359,   273,    51,    51,   465,    51,
     278,    77,    49,   281,   459,    51,   461,    57,    88,    77,
      59,    60,    61,    62,    63,    64,    65,    66,   296,   474,
     475,   413,   300,   301,    77,    49,   418,   305,   306,    98,
      49,   311,    81,    24,    98,    80,    49,    51,   316,   404,
      77,    51,   407,    77,    51,   125,   411,   291,   326,   441,
     328,   131,   132,   445,   298,   195,    51,    77,    60,   303,
      62,    63,    64,    65,    66,   145,    77,   432,   460,    98,
     435,   211,   437,   438,   439,    49,    49,    49,    77,    81,
     472,    51,    51,    77,    77,    77,    24,   365,    77,    51,
     482,    51,    53,   373,    49,   375,    49,    51,    26,    51,
     380,    49,   467,   381,    49,   470,   186,   187,   188,    38,
     446,   389,   390,   193,   194,   393,   331,   101,   483,   484,
     452,   401,    28,    82,    -1,   204,   406,    -1,   408,   409,
     410,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
     280,    -1,   282,   421,   422,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,   451,   450,   453,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,   263,    69,    70,   266,   465,   268,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    81,    -1,   478,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,   293,    61,    62,   296,    -1,   298,   359,
      67,   301,    -1,   303,    -1,    12,    13,    -1,    75,    -1,
      -1,    78,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,   338,   339,
      47,    48,    -1,    -1,   404,    -1,    -1,   407,    55,    -1,
      -1,   411,    59,    60,    61,    62,    63,    64,    65,    66,
     360,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    -1,   432,    -1,    81,   435,    -1,   437,   438,   439,
      -1,    -1,    -1,   383,    -1,    -1,   386,    -1,    -1,    -1,
      -1,   391,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,   405,    -1,   467,    -1,    -1,
     470,    -1,   412,    -1,   414,    59,    60,    61,    62,    63,
      64,    65,    66,   483,   484,    69,    70,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    81,    -1,    14,
      15,    -1,   442,    18,   444,    20,   446,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,   459,
      -1,   461,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,   474,   475,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    64,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,     3,     4,     5,     6,    80,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    98,    99,    -1,    28,    29,    47,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      69,    70,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    81,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,     3,     4,     5,     6,    80,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    -1,    98,    99,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,    -1,
      30,    -1,    32,    33,    34,    35,    75,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    -1,    53,    -1,    55,    -1,    -1,    97,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    12,    -1,
      -1,    81,    -1,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    30,    -1,    32,    33,
      34,    35,   102,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,    -1,    30,   102,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,   102,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    12,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    12,    13,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,   102,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    12,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    12,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    32,    33,    34,    35,    81,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    12,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      12,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    55,    -1,   102,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    12,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    12,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    32,    33,    34,    35,    81,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,    55,    -1,   102,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      12,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,    -1,
     102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,     0,    -1,    81,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,   102,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,    43,
      44,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      64,    -1,    -1,    67,    -1,    -1,    -1,     3,     4,     5,
       6,    75,     8,     9,    10,    11,    38,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    38,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    38,    77,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    56,    57,    58,    59,    -1,    61,    62,    75,
      -1,    77,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    77,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    38,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    56,
      57,    58,    59,    -1,    61,    62,    75,    38,    77,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      77,    -1,    -1,    -1,    30,    56,    57,    58,    59,    -1,
      61,    62,     3,     4,     5,     6,    67,     8,     9,    10,
      11,    47,    48,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,
      67,    -1,    -1,    -1,     3,     4,     5,     6,    75,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    47,    48,    -1,    67,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    75,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,     3,     4,     5,     6,    81,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    38,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    63,    49,    -1,    -1,    67,
      -1,    -1,    -1,    56,    57,    58,    59,    75,    61,    62,
      38,    -1,    -1,    -1,    67,    -1,    -1,    -1,     3,     4,
       5,     6,    75,     8,     9,    10,    11,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,     3,     4,     5,     6,    75,     8,     9,
      10,    11,    -1,    38,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    38,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    38,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    56,    57,    58,    59,    75,    61,    62,     3,     4,
       5,     6,    67,     8,     9,    10,    11,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    27,    28,    29,    30,    31,    37,
      38,    40,    41,    42,    43,    44,    56,    57,    58,    59,
      61,    62,    64,    67,    75,    80,    98,    99,   105,   106,
     114,   115,   116,   117,   118,   119,   121,   122,   123,   124,
     126,   127,   132,   133,   134,   137,   140,   141,   142,   143,
     151,   152,   153,   154,   156,   157,   158,   159,   160,   162,
     169,   170,   171,   172,   173,   174,    57,   171,   171,    57,
     162,   171,    57,   120,   163,   171,    60,   128,   131,   172,
     162,   171,    62,   128,   129,   130,   162,   171,   119,    49,
     171,    57,   138,   139,   171,    76,   162,   164,   165,   171,
      77,   162,   171,   161,   162,   171,   171,   171,   171,   171,
       0,   106,    53,   173,   173,    21,    64,   119,     8,   172,
      51,    57,    57,    12,    30,    32,    33,    34,    35,    39,
      47,    48,    49,    55,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    81,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   102,   125,     8,    54,   174,   171,    51,    28,
     162,    51,   163,   171,    32,    51,    31,    60,    31,    60,
     128,    51,    49,    13,    51,   173,    49,   139,   171,    49,
      51,    13,    51,    76,    51,    76,    49,    51,    77,    78,
      51,   173,   172,   171,    53,     8,   171,    63,   161,   162,
     166,   167,   168,   172,   162,   166,   168,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   172,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,    51,
      51,   119,   171,    57,   130,   172,    57,   130,    31,   108,
     109,   111,   112,   113,   127,   173,   172,   129,    96,   107,
     173,    51,   173,   138,   171,    76,   164,   171,   171,    77,
     171,    57,    78,    57,   173,   171,    51,    77,    51,   150,
      53,    51,    77,    51,   150,    24,    53,    77,   171,    77,
     171,    49,   130,   130,    57,   130,    23,    24,   155,    98,
      99,   127,    80,    98,    99,   107,   110,   114,    25,    26,
     135,   136,   107,    77,   107,    77,   162,   166,    62,    63,
     144,   145,   146,   147,   148,   149,   172,   168,   162,   167,
      77,   171,   168,   162,    77,   171,   171,    77,    77,   173,
      51,   150,   150,   130,   171,    49,    98,    80,    98,    99,
      98,    97,   114,    49,   171,    49,    24,    26,   135,    24,
      49,    51,    77,    51,   144,   144,    51,   150,    77,    49,
      53,    51,   150,    51,   150,   150,   150,   107,    77,    77,
     150,    49,   109,    98,   173,    13,    49,   173,    49,    49,
      49,   173,    63,   147,    51,   150,    51,   150,    81,   144,
     148,    49,    83,   171,   171,   172,    77,    77,    77,    77,
      24,    77,   173,   107,   172,   173,   107,   173,   173,   173,
     107,   144,    51,   150,    63,   147,    51,   150,   109,   171,
      53,    49,   107,    49,   107,   107,   107,   107,   150,    63,
     144,    51,   150,   146,   147,    49,   171,   173,    24,   155,
     173,    26,   144,   150,    63,    51,   109,   107,    49,   107,
      49,   150,   144,   173,   173,   150,   107,   107
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
     136,   137,   137,   137,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   141,   141,   141,   141,   142,   142,
     143,   143,   144,   144,   144,   144,   145,   145,   145,   146,
     146,   146,   147,   147,   148,   148,   148,   148,   148,   148,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   153,
     154,   155,   155,   155,   156,   156,   156,   157,   157,   158,
     159,   160,   160,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   169,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   172,   173,   173,   174,   174,   174
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
       1,     5,     9,     9,    13,     8,     1,     3,     3,     1,
       5,     8,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     3,     1,     3,     3,     5,     4,     5,     1,     2,
       3,     1,     3,     1,     4,     5,     7,     3,     5,     6,
       8,     3,     1,     0,     1,     0,     8,    10,     2,     5,
       2,     5,     9,     6,     4,     7,     5,     3,     2,     2,
       1,     2,     1,     2,     3,     1,     0,     3,     1,     3,
       1,     3,     3,     1,     1,     2,     3,     2,     3,     1,
       1,     1,     3,     4,     7,     7,     5,     4,     7,     7,
       5,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     1,     3,     4,     3,     4,     3,     2,
       3,     3,     2,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     1,     2,     1,     1,     1,     1
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
  "try_statement", "with_item", "with_item_list", "with_statement",
  "multi_line_statement", "decorators_opt", "decorators", "parameter",
  "parameter_list", "parameter_list_no_posonly", "defparameter_list",
  "parameter_list_starargs", "parameter_list_opt", "comma_opt",
  "function_def", "global_statement", "ternary_if_statement",
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
       0,   300,   300,   301,   302,   306,   310,   314,   318,   319,
     323,   324,   328,   329,   330,   331,   334,   337,   343,   346,
     352,   355,   361,   362,   363,   368,   372,   376,   380,   381,
     385,   386,   387,   388,   392,   393,   394,   395,   399,   400,
     401,   405,   406,   411,   412,   413,   415,   421,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     440,   441,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   463,   464,   468,   469,
     470,   474,   475,   479,   480,   486,   487,   489,   491,   493,
     495,   497,   502,   503,   507,   509,   520,   521,   522,   525,
     526,   530,   531,   533,   535,   537,   541,   542,   546,   547,
     551,   552,   561,   562,   563,   564,   565,   570,   574,   575,
     579,   580,   584,   585,   586,   587,   591,   593,   595,   599,
     600,   602,   606,   607,   615,   616,   617,   619,   620,   622,
     624,   626,   630,   631,   635,   636,   640,   642,   653,   657,
     661,   665,   666,   668,   673,   676,   679,   684,   685,   689,
     694,   698,   699,   702,   705,   711,   712,   716,   717,   730,
     731,   735,   738,   739,   743,   744,   749,   750,   754,   755,
     760,   761,   762,   766,   767,   769,   771,   772,   773,   775,
     777,   784,   788,   789,   793,   794,   795,   799,   800,   801,
     802,   803,   804,   805,   807,   808,   809,   810,   811,   813,
     814,   818,   819,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   830,   831,   833,   834,   835,   836,   837,   839,
     840,   841,   842,   843,   844,   845,   846,   847,   848,   850,
     851,   852,   859,   864,   868,   869,   873,   874,   875
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
#line 3891 "./parser.cpp"

#line 878 "parser.ypp"
