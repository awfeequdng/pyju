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

      case symbol_kind::S_comp_for: // comp_for
        value.YY_MOVE_OR_COPY< Nonnull<Comprehension*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_slice_item: // slice_item
      case symbol_kind::S_tuple_list: // tuple_list
      case symbol_kind::S_subscription: // subscription
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lambda_expression: // lambda_expression
      case symbol_kind::S_id_item: // id_item
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
      case symbol_kind::S_class_def: // class_def
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

      case symbol_kind::S_comp_for_items: // comp_for_items
        value.YY_MOVE_OR_COPY< std::vector<Nonnull<Comprehension*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
      case symbol_kind::S_slice_item_list: // slice_item_list
      case symbol_kind::S_lambda_id_list: // lambda_id_list
      case symbol_kind::S_id_list: // id_list
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

      case symbol_kind::S_comp_for: // comp_for
        value.move< Nonnull<Comprehension*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_slice_item: // slice_item
      case symbol_kind::S_tuple_list: // tuple_list
      case symbol_kind::S_subscription: // subscription
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lambda_expression: // lambda_expression
      case symbol_kind::S_id_item: // id_item
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
      case symbol_kind::S_class_def: // class_def
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

      case symbol_kind::S_comp_for_items: // comp_for_items
        value.move< std::vector<Nonnull<Comprehension*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
      case symbol_kind::S_slice_item_list: // slice_item_list
      case symbol_kind::S_lambda_id_list: // lambda_id_list
      case symbol_kind::S_id_list: // id_list
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

      case symbol_kind::S_comp_for: // comp_for
        value.copy< Nonnull<Comprehension*> > (that.value);
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_slice_item: // slice_item
      case symbol_kind::S_tuple_list: // tuple_list
      case symbol_kind::S_subscription: // subscription
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lambda_expression: // lambda_expression
      case symbol_kind::S_id_item: // id_item
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
      case symbol_kind::S_class_def: // class_def
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

      case symbol_kind::S_comp_for_items: // comp_for_items
        value.copy< std::vector<Nonnull<Comprehension*>> > (that.value);
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
      case symbol_kind::S_slice_item_list: // slice_item_list
      case symbol_kind::S_lambda_id_list: // lambda_id_list
      case symbol_kind::S_id_list: // id_list
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

      case symbol_kind::S_comp_for: // comp_for
        value.move< Nonnull<Comprehension*> > (that.value);
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_slice_item: // slice_item
      case symbol_kind::S_tuple_list: // tuple_list
      case symbol_kind::S_subscription: // subscription
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lambda_expression: // lambda_expression
      case symbol_kind::S_id_item: // id_item
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
      case symbol_kind::S_class_def: // class_def
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

      case symbol_kind::S_comp_for_items: // comp_for_items
        value.move< std::vector<Nonnull<Comprehension*>> > (that.value);
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
      case symbol_kind::S_slice_item_list: // slice_item_list
      case symbol_kind::S_lambda_id_list: // lambda_id_list
      case symbol_kind::S_id_list: // id_list
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

      case symbol_kind::S_comp_for: // comp_for
        yylhs.value.emplace< Nonnull<Comprehension*> > ();
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_slice_item: // slice_item
      case symbol_kind::S_tuple_list: // tuple_list
      case symbol_kind::S_subscription: // subscription
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lambda_expression: // lambda_expression
      case symbol_kind::S_id_item: // id_item
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
      case symbol_kind::S_class_def: // class_def
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

      case symbol_kind::S_comp_for_items: // comp_for_items
        yylhs.value.emplace< std::vector<Nonnull<Comprehension*>> > ();
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
      case symbol_kind::S_slice_item_list: // slice_item_list
      case symbol_kind::S_lambda_id_list: // lambda_id_list
      case symbol_kind::S_id_list: // id_list
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
#line 312 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1339 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 313 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1345 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 318 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1351 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 322 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1357 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 326 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1363 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 330 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1369 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 331 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1375 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 335 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1381 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 336 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1387 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 340 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1393 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 341 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1399 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 342 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1405 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 343 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1413 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 346 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1421 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 349 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1429 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 355 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1437 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 358 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1445 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 364 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1453 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 367 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1461 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 373 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1467 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 374 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1473 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 375 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1479 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 380 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1485 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 384 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1491 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 388 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1497 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 392 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1503 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 393 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1509 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 397 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1515 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 398 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1521 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 399 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1527 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 400 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1533 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 404 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1539 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 405 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1545 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 406 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1551 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 407 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1557 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 411 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1563 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 412 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1569 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 413 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1575 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 417 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1581 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 418 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1587 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 423 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1593 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 424 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1599 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 425 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1606 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 427 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1613 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 433 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1619 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 437 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1625 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 438 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1631 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 439 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1637 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 440 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1643 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 441 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1649 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 442 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1655 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 443 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1661 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 444 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1667 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 445 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1673 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 446 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1679 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 447 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1685 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 448 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1691 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 452 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1697 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 453 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1703 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 457 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1709 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 458 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1715 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 459 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1721 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 460 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1727 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 461 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1733 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 462 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1739 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 463 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1745 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 464 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1751 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 465 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1757 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 466 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1763 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 467 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1769 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 468 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1775 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 469 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1781 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 470 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1787 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 475 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1793 "./parser.cpp"
    break;

  case 77: // module: id
#line 476 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1799 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 480 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1805 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 481 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1811 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 482 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1817 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 486 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1823 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 487 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1829 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 491 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1835 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 492 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1841 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 498 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1847 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 499 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1854 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 501 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1861 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 503 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1868 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 505 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1875 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 507 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1882 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 509 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1889 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 514 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1895 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 515 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1902 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 519 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1909 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 522 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1915 "./parser.cpp"
    break;

  case 96: // except_statement: EXCEPT ":" sep statements
#line 532 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_01(yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1921 "./parser.cpp"
    break;

  case 97: // except_statement: EXCEPT expr ":" sep statements
#line 533 "parser.ypp"
                                     { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_02(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1927 "./parser.cpp"
    break;

  case 98: // except_statement: EXCEPT expr AS id ":" sep statements
#line 534 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_03(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1933 "./parser.cpp"
    break;

  case 99: // except_list: except_list except_statement
#line 537 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1939 "./parser.cpp"
    break;

  case 100: // except_list: except_statement
#line 538 "parser.ypp"
                       { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1945 "./parser.cpp"
    break;

  case 101: // try_statement: TRY ":" sep statements except_list
#line 542 "parser.ypp"
                                         { yylhs.value.as < Nonnull<Statement*> > () = TRY_01(yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1951 "./parser.cpp"
    break;

  case 102: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements
#line 543 "parser.ypp"
                                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_02(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1958 "./parser.cpp"
    break;

  case 103: // try_statement: TRY ":" sep statements except_list FINALLY ":" sep statements
#line 545 "parser.ypp"
                                                                    {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_03(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1965 "./parser.cpp"
    break;

  case 104: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements FINALLY ":" sep statements
#line 548 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = TRY_04(yystack_[9].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[8].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1971 "./parser.cpp"
    break;

  case 105: // try_statement: TRY ":" sep statements FINALLY ":" sep statements
#line 549 "parser.ypp"
                                                        { yylhs.value.as < Nonnull<Statement*> > () = TRY_05(yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1977 "./parser.cpp"
    break;

  case 106: // with_item: expr
#line 553 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1983 "./parser.cpp"
    break;

  case 107: // with_item: expr AS expr
#line 554 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1989 "./parser.cpp"
    break;

  case 108: // with_item_list: with_item_list "," with_item
#line 558 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1995 "./parser.cpp"
    break;

  case 109: // with_item_list: with_item
#line 559 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 2001 "./parser.cpp"
    break;

  case 110: // with_statement: WITH with_item_list ":" sep statements
#line 563 "parser.ypp"
                                             { yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2007 "./parser.cpp"
    break;

  case 111: // with_statement: WITH "(" with_item_list "," ")" ":" sep statements
#line 564 "parser.ypp"
                                                         {
        yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2014 "./parser.cpp"
    break;

  case 112: // multi_line_statement: if_statement
#line 573 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2020 "./parser.cpp"
    break;

  case 113: // multi_line_statement: for_statement
#line 574 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2026 "./parser.cpp"
    break;

  case 114: // multi_line_statement: try_statement
#line 575 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2032 "./parser.cpp"
    break;

  case 115: // multi_line_statement: with_statement
#line 576 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2038 "./parser.cpp"
    break;

  case 116: // multi_line_statement: function_def
#line 577 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2044 "./parser.cpp"
    break;

  case 117: // multi_line_statement: class_def
#line 578 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2050 "./parser.cpp"
    break;

  case 118: // multi_line_statement: while_statement
#line 582 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2056 "./parser.cpp"
    break;

  case 119: // decorators_opt: decorators
#line 586 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2062 "./parser.cpp"
    break;

  case 120: // decorators_opt: %empty
#line 587 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2068 "./parser.cpp"
    break;

  case 121: // decorators: decorators "@" expr sep
#line 591 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2074 "./parser.cpp"
    break;

  case 122: // decorators: "@" expr sep
#line 592 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2080 "./parser.cpp"
    break;

  case 123: // parameter: id
#line 596 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2086 "./parser.cpp"
    break;

  case 124: // parameter: id ":" expr
#line 597 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2092 "./parser.cpp"
    break;

  case 125: // parameter: id "=" expr
#line 598 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2098 "./parser.cpp"
    break;

  case 126: // parameter: id ":" expr "=" expr
#line 599 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2104 "./parser.cpp"
    break;

  case 127: // parameter_list: defparameter_list "," "/" comma_opt
#line 603 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2111 "./parser.cpp"
    break;

  case 128: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 605 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2118 "./parser.cpp"
    break;

  case 129: // parameter_list: parameter_list_no_posonly
#line 607 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2124 "./parser.cpp"
    break;

  case 130: // parameter_list_no_posonly: defparameter_list comma_opt
#line 611 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2130 "./parser.cpp"
    break;

  case 131: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 612 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2137 "./parser.cpp"
    break;

  case 132: // parameter_list_no_posonly: parameter_list_starargs
#line 614 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2143 "./parser.cpp"
    break;

  case 133: // defparameter_list: defparameter_list "," parameter
#line 618 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2149 "./parser.cpp"
    break;

  case 134: // defparameter_list: parameter
#line 619 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2155 "./parser.cpp"
    break;

  case 135: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 627 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2161 "./parser.cpp"
    break;

  case 136: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 628 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2167 "./parser.cpp"
    break;

  case 137: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 629 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2174 "./parser.cpp"
    break;

  case 138: // parameter_list_starargs: "*" parameter comma_opt
#line 631 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2180 "./parser.cpp"
    break;

  case 139: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 632 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2187 "./parser.cpp"
    break;

  case 140: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 634 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2194 "./parser.cpp"
    break;

  case 141: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 636 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2201 "./parser.cpp"
    break;

  case 142: // parameter_list_starargs: "**" parameter comma_opt
#line 638 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2207 "./parser.cpp"
    break;

  case 143: // parameter_list_opt: parameter_list
#line 642 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 2213 "./parser.cpp"
    break;

  case 144: // parameter_list_opt: %empty
#line 643 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 2219 "./parser.cpp"
    break;

  case 147: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 653 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2225 "./parser.cpp"
    break;

  case 148: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 655 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2231 "./parser.cpp"
    break;

  case 149: // class_def: decorators_opt CLASS id ":" sep statements
#line 666 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_01(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2238 "./parser.cpp"
    break;

  case 150: // class_def: decorators_opt CLASS id "(" expr_list_opt ")" ":" sep statements
#line 668 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_02(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2245 "./parser.cpp"
    break;

  case 151: // class_def: decorators_opt CLASS id "(" expr_list "," keyword_items ")" ":" sep statements
#line 671 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[6].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2251 "./parser.cpp"
    break;

  case 152: // class_def: decorators_opt CLASS id "(" keyword_items "," expr_list ")" ":" sep statements
#line 673 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2257 "./parser.cpp"
    break;

  case 153: // class_def: decorators_opt CLASS id "(" keyword_items ")" ":" sep statements
#line 674 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_04(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2264 "./parser.cpp"
    break;

  case 154: // global_statement: GLOBAL expr_list
#line 680 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2270 "./parser.cpp"
    break;

  case 155: // ternary_if_statement: expr IF expr ELSE expr
#line 684 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2276 "./parser.cpp"
    break;

  case 156: // nonlocal_statement: NONLOCAL expr_list
#line 688 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2282 "./parser.cpp"
    break;

  case 157: // elif_statement: ELIF expr ":" sep statements
#line 692 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2288 "./parser.cpp"
    break;

  case 158: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 693 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2295 "./parser.cpp"
    break;

  case 159: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 695 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2302 "./parser.cpp"
    break;

  case 160: // if_statement: IF expr ":" body_stmts
#line 700 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2310 "./parser.cpp"
    break;

  case 161: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 703 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2318 "./parser.cpp"
    break;

  case 162: // if_statement: IF expr ":" body_stmts elif_statement
#line 706 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2325 "./parser.cpp"
    break;

  case 163: // target_list: target_list tuple_item "="
#line 711 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2331 "./parser.cpp"
    break;

  case 164: // target_list: tuple_item "="
#line 712 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2337 "./parser.cpp"
    break;

  case 165: // assignment_statement: target_list tuple_item
#line 716 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2343 "./parser.cpp"
    break;

  case 166: // expression_statment: expr
#line 721 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2349 "./parser.cpp"
    break;

  case 167: // string: string string_literal
#line 725 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2355 "./parser.cpp"
    break;

  case 168: // string: string_literal
#line 726 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2363 "./parser.cpp"
    break;

  case 169: // string: id string_literal
#line 729 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2371 "./parser.cpp"
    break;

  case 170: // string: string id string_literal
#line 732 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2379 "./parser.cpp"
    break;

  case 171: // expr_list_opt: expr_list
#line 738 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2385 "./parser.cpp"
    break;

  case 172: // expr_list_opt: %empty
#line 739 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2391 "./parser.cpp"
    break;

  case 173: // expr_list: expr_list "," expr
#line 743 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2397 "./parser.cpp"
    break;

  case 174: // expr_list: expr
#line 744 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2403 "./parser.cpp"
    break;

  case 175: // expr_for_list: expr_for_list "," expr
#line 757 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2409 "./parser.cpp"
    break;

  case 176: // expr_for_list: expr
#line 758 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2415 "./parser.cpp"
    break;

  case 177: // dict: expr ":" expr
#line 762 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2421 "./parser.cpp"
    break;

  case 178: // dict_list: dict_list "," dict
#line 765 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2427 "./parser.cpp"
    break;

  case 179: // dict_list: dict
#line 766 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2433 "./parser.cpp"
    break;

  case 180: // call_arguement_list: expr_list_opt
#line 770 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2439 "./parser.cpp"
    break;

  case 181: // call_arguement_list: expr_list ","
#line 771 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2445 "./parser.cpp"
    break;

  case 182: // keyword_item: id "=" expr
#line 776 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2451 "./parser.cpp"
    break;

  case 183: // keyword_item: "**" expr
#line 777 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2457 "./parser.cpp"
    break;

  case 184: // keyword_items: keyword_items "," keyword_item
#line 781 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2463 "./parser.cpp"
    break;

  case 185: // keyword_items: keyword_item
#line 782 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2469 "./parser.cpp"
    break;

  case 186: // primary: id
#line 787 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2475 "./parser.cpp"
    break;

  case 187: // primary: string
#line 788 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2481 "./parser.cpp"
    break;

  case 188: // primary: expr "." id
#line 789 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2487 "./parser.cpp"
    break;

  case 189: // function_call: primary "(" call_arguement_list ")"
#line 793 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2493 "./parser.cpp"
    break;

  case 190: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 794 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2500 "./parser.cpp"
    break;

  case 191: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 796 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2507 "./parser.cpp"
    break;

  case 192: // function_call: primary "(" keyword_items comma_opt ")"
#line 798 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2513 "./parser.cpp"
    break;

  case 193: // function_call: function_call "(" call_arguement_list ")"
#line 799 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2519 "./parser.cpp"
    break;

  case 194: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 800 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2526 "./parser.cpp"
    break;

  case 195: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 802 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2533 "./parser.cpp"
    break;

  case 196: // function_call: function_call "(" keyword_items comma_opt ")"
#line 804 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2539 "./parser.cpp"
    break;

  case 197: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 811 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2545 "./parser.cpp"
    break;

  case 198: // slice_item_list: slice_item_list "," slice_item
#line 816 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2551 "./parser.cpp"
    break;

  case 199: // slice_item_list: slice_item
#line 817 "parser.ypp"
                 { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2557 "./parser.cpp"
    break;

  case 200: // slice_item: ":"
#line 820 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(std::nullopt, std::nullopt , std::nullopt  , context.source_loc()); }
#line 2563 "./parser.cpp"
    break;

  case 201: // slice_item: expr ":"
#line 821 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(     yystack_[1].value.as < Nonnull<Expression*> > ()     , std::nullopt , std::nullopt  , context.source_loc()); }
#line 2569 "./parser.cpp"
    break;

  case 202: // slice_item: ":" expr
#line 822 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(std::nullopt,      yystack_[0].value.as < Nonnull<Expression*> > ()      , std::nullopt  , context.source_loc()); }
#line 2575 "./parser.cpp"
    break;

  case 203: // slice_item: expr ":" expr
#line 823 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(     yystack_[2].value.as < Nonnull<Expression*> > ()     ,      yystack_[0].value.as < Nonnull<Expression*> > ()      , std::nullopt  , context.source_loc()); }
#line 2581 "./parser.cpp"
    break;

  case 204: // slice_item: ":" ":"
#line 824 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(std::nullopt, std::nullopt , std::nullopt  , context.source_loc()); }
#line 2587 "./parser.cpp"
    break;

  case 205: // slice_item: ":" ":" expr
#line 825 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(std::nullopt, std::nullopt ,      yystack_[0].value.as < Nonnull<Expression*> > ()       , context.source_loc()); }
#line 2593 "./parser.cpp"
    break;

  case 206: // slice_item: expr ":" ":"
#line 826 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(     yystack_[2].value.as < Nonnull<Expression*> > ()    , std::nullopt  , std::nullopt  , context.source_loc()); }
#line 2599 "./parser.cpp"
    break;

  case 207: // slice_item: ":" expr ":"
#line 827 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(std::nullopt,      yystack_[1].value.as < Nonnull<Expression*> > ()      , std::nullopt  , context.source_loc()); }
#line 2605 "./parser.cpp"
    break;

  case 208: // slice_item: expr ":" ":" expr
#line 828 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(     yystack_[3].value.as < Nonnull<Expression*> > ()    , std::nullopt  ,      yystack_[0].value.as < Nonnull<Expression*> > ()       , context.source_loc()); }
#line 2611 "./parser.cpp"
    break;

  case 209: // slice_item: ":" expr ":" expr
#line 829 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(std::nullopt,      yystack_[2].value.as < Nonnull<Expression*> > ()      ,      yystack_[0].value.as < Nonnull<Expression*> > ()       , context.source_loc()); }
#line 2617 "./parser.cpp"
    break;

  case 210: // slice_item: expr ":" expr ":"
#line 830 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(     yystack_[3].value.as < Nonnull<Expression*> > ()    ,      yystack_[1].value.as < Nonnull<Expression*> > ()       , std::nullopt  , context.source_loc()); }
#line 2623 "./parser.cpp"
    break;

  case 211: // slice_item: expr ":" expr ":" expr
#line 831 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = SLICE_01(     yystack_[4].value.as < Nonnull<Expression*> > ()    ,      yystack_[2].value.as < Nonnull<Expression*> > ()       ,      yystack_[0].value.as < Nonnull<Expression*> > ()       , context.source_loc()); }
#line 2629 "./parser.cpp"
    break;

  case 212: // slice_item: expr
#line 832 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2635 "./parser.cpp"
    break;

  case 213: // tuple_list: slice_item_list
#line 836 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2641 "./parser.cpp"
    break;

  case 214: // subscription: primary "[" tuple_list "]"
#line 840 "parser.ypp"
                                 { yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2647 "./parser.cpp"
    break;

  case 215: // subscription: function_call "[" tuple_list "]"
#line 841 "parser.ypp"
                                       { yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2653 "./parser.cpp"
    break;

  case 216: // subscription: "[" expr_list_opt "]" "[" tuple_list "]"
#line 842 "parser.ypp"
                                               {
        yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(LIST(yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2660 "./parser.cpp"
    break;

  case 217: // subscription: "{" expr_list "}" "[" tuple_list "]"
#line 844 "parser.ypp"
                                           {
        yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(SET(yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2667 "./parser.cpp"
    break;

  case 218: // subscription: "(" expr ")" "[" tuple_list "]"
#line 846 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2673 "./parser.cpp"
    break;

  case 219: // subscription: "{" dict_list "}" "[" tuple_list "]"
#line 847 "parser.ypp"
                                           {
        yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(DICT_02(yystack_[4].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2680 "./parser.cpp"
    break;

  case 220: // subscription: subscription "[" tuple_list "]"
#line 849 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = SUBSCRIPT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2686 "./parser.cpp"
    break;

  case 221: // expr: id
#line 853 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2692 "./parser.cpp"
    break;

  case 222: // expr: integer_literal
#line 854 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2701 "./parser.cpp"
    break;

  case 223: // expr: string
#line 858 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2707 "./parser.cpp"
    break;

  case 224: // expr: real_literal
#line 859 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2713 "./parser.cpp"
    break;

  case 225: // expr: image_literal
#line 860 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2722 "./parser.cpp"
    break;

  case 226: // expr: TRUE
#line 864 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2728 "./parser.cpp"
    break;

  case 227: // expr: FALSE
#line 865 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2734 "./parser.cpp"
    break;

  case 228: // expr: NONE
#line 866 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2740 "./parser.cpp"
    break;

  case 229: // expr: "..."
#line 867 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2746 "./parser.cpp"
    break;

  case 230: // expr: "(" expr ")"
#line 868 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2752 "./parser.cpp"
    break;

  case 231: // expr: "(" ")"
#line 869 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2758 "./parser.cpp"
    break;

  case 232: // expr: function_call
#line 870 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2764 "./parser.cpp"
    break;

  case 233: // expr: subscription
#line 871 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2770 "./parser.cpp"
    break;

  case 234: // expr: "[" expr_list_opt "]"
#line 872 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2776 "./parser.cpp"
    break;

  case 235: // expr: "[" expr_list "," "]"
#line 873 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2782 "./parser.cpp"
    break;

  case 236: // expr: "{" expr_list "}"
#line 874 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2788 "./parser.cpp"
    break;

  case 237: // expr: "{" expr_list "," "}"
#line 875 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2794 "./parser.cpp"
    break;

  case 238: // expr: expr "." id
#line 876 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2800 "./parser.cpp"
    break;

  case 239: // expr: "{" "}"
#line 878 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2806 "./parser.cpp"
    break;

  case 240: // expr: "{" dict_list "}"
#line 879 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2812 "./parser.cpp"
    break;

  case 241: // expr: id ":=" expr
#line 883 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2818 "./parser.cpp"
    break;

  case 242: // expr: "*" expr
#line 884 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2824 "./parser.cpp"
    break;

  case 243: // expr: expr "+" expr
#line 886 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2830 "./parser.cpp"
    break;

  case 244: // expr: expr "-" expr
#line 887 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2836 "./parser.cpp"
    break;

  case 245: // expr: expr "*" expr
#line 888 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2842 "./parser.cpp"
    break;

  case 246: // expr: expr "/" expr
#line 889 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2848 "./parser.cpp"
    break;

  case 247: // expr: expr "%" expr
#line 890 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2854 "./parser.cpp"
    break;

  case 248: // expr: "-" expr
#line 891 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2860 "./parser.cpp"
    break;

  case 249: // expr: "+" expr
#line 892 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2866 "./parser.cpp"
    break;

  case 250: // expr: "~" expr
#line 893 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2872 "./parser.cpp"
    break;

  case 251: // expr: expr "**" expr
#line 894 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2878 "./parser.cpp"
    break;

  case 252: // expr: expr "//" expr
#line 895 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2884 "./parser.cpp"
    break;

  case 253: // expr: expr "@" expr
#line 896 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2890 "./parser.cpp"
    break;

  case 254: // expr: expr "&" expr
#line 898 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2896 "./parser.cpp"
    break;

  case 255: // expr: expr "|" expr
#line 899 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2902 "./parser.cpp"
    break;

  case 256: // expr: expr "^" expr
#line 900 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2908 "./parser.cpp"
    break;

  case 257: // expr: expr "<<" expr
#line 901 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2914 "./parser.cpp"
    break;

  case 258: // expr: expr ">>" expr
#line 902 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2920 "./parser.cpp"
    break;

  case 259: // expr: expr "==" expr
#line 904 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2926 "./parser.cpp"
    break;

  case 260: // expr: expr "!=" expr
#line 905 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2932 "./parser.cpp"
    break;

  case 261: // expr: expr "<" expr
#line 906 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2938 "./parser.cpp"
    break;

  case 262: // expr: expr "<=" expr
#line 907 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2944 "./parser.cpp"
    break;

  case 263: // expr: expr ">" expr
#line 908 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2950 "./parser.cpp"
    break;

  case 264: // expr: expr ">=" expr
#line 909 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2956 "./parser.cpp"
    break;

  case 265: // expr: expr "is" expr
#line 910 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2962 "./parser.cpp"
    break;

  case 266: // expr: expr "is not" expr
#line 911 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2968 "./parser.cpp"
    break;

  case 267: // expr: expr "in" expr
#line 912 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2974 "./parser.cpp"
    break;

  case 268: // expr: expr "not in" expr
#line 913 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2980 "./parser.cpp"
    break;

  case 269: // expr: expr "and" expr
#line 915 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2986 "./parser.cpp"
    break;

  case 270: // expr: expr "or" expr
#line 916 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2992 "./parser.cpp"
    break;

  case 271: // expr: "not" expr
#line 917 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2998 "./parser.cpp"
    break;

  case 272: // expr: "[" expr comp_for_items "]"
#line 920 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = LIST_COMP_1(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 3004 "./parser.cpp"
    break;

  case 273: // expr: "{" expr comp_for_items "}"
#line 921 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = SET_COMP_1(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 3010 "./parser.cpp"
    break;

  case 274: // expr: "{" expr ":" expr comp_for_items "}"
#line 922 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Expression*> > () = DICT_COMP_1(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 3016 "./parser.cpp"
    break;

  case 275: // expr: ternary_if_statement
#line 924 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 3022 "./parser.cpp"
    break;

  case 276: // expr: lambda_expression
#line 925 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 3028 "./parser.cpp"
    break;

  case 277: // lambda_id_list: lambda_id_list "," id
#line 930 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 3034 "./parser.cpp"
    break;

  case 278: // lambda_id_list: id
#line 931 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc())); }
#line 3040 "./parser.cpp"
    break;

  case 279: // lambda_expression: LAMBDA ":" expr
#line 935 "parser.ypp"
                                   {
        yylhs.value.as < Nonnull<Expression*> > () = LAMBDA_01({}, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 3047 "./parser.cpp"
    break;

  case 280: // lambda_expression: LAMBDA lambda_id_list ":" expr
#line 937 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = LAMBDA_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 3054 "./parser.cpp"
    break;

  case 281: // id_list: id_list "," id
#line 949 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 3060 "./parser.cpp"
    break;

  case 282: // id_list: id
#line 950 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 3066 "./parser.cpp"
    break;

  case 283: // id_item: id_list
#line 954 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 3072 "./parser.cpp"
    break;

  case 284: // id_item: id_list ","
#line 955 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 3078 "./parser.cpp"
    break;

  case 285: // id_item: "(" id ")"
#line 956 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Name*> > (); }
#line 3084 "./parser.cpp"
    break;

  case 286: // id_item: "(" id_list "," ")"
#line 957 "parser.ypp"
                          { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 3090 "./parser.cpp"
    break;

  case 287: // id_item: "(" id_list "," id ")"
#line 958 "parser.ypp"
                              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Name*> > ()), context.source_loc()); }
#line 3096 "./parser.cpp"
    break;

  case 288: // comp_for: FOR id_item "in" expr
#line 962 "parser.ypp"
                          { yylhs.value.as < Nonnull<Comprehension*> > () = COMP_FOR_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 3102 "./parser.cpp"
    break;

  case 289: // comp_for: FOR id_item "in" expr IF expr
#line 963 "parser.ypp"
                                  {
        yylhs.value.as < Nonnull<Comprehension*> > () = COMP_FOR_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 3109 "./parser.cpp"
    break;

  case 290: // comp_for_items: comp_for_items comp_for
#line 968 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Comprehension*>> > () = yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > (), yystack_[0].value.as < Nonnull<Comprehension*> > ()); }
#line 3115 "./parser.cpp"
    break;

  case 291: // comp_for_items: comp_for
#line 969 "parser.ypp"
               { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > (), yystack_[0].value.as < Nonnull<Comprehension*> > ()); }
#line 3121 "./parser.cpp"
    break;

  case 292: // id: identifier
#line 973 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 3127 "./parser.cpp"
    break;

  case 293: // sep: sep sep_one
#line 977 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 3133 "./parser.cpp"
    break;

  case 294: // sep: sep_one
#line 978 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 3139 "./parser.cpp"
    break;

  case 295: // sep_one: NEWLINE
#line 982 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 3145 "./parser.cpp"
    break;

  case 296: // sep_one: COMMENT
#line 983 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 3151 "./parser.cpp"
    break;

  case 297: // sep_one: ";"
#line 984 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 3157 "./parser.cpp"
    break;


#line 3161 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -464;

  const short  Parser ::yytable_ninf_ = -189;

  const short
   Parser ::yypact_[] =
  {
     867,  -464,  -464,  -464,  -464,  -464,  -464,  -464,  -464,  3272,
    3272,  -464,  -464,  3332,  3347,    63,  3272,  3272,    36,   134,
    3272,  3272,  -464,  3407,    -3,  3272,  3422,  2838,   676,  3272,
    3272,  3272,  3272,  3272,  3272,  -464,  -464,  -464,  -464,  2644,
    -464,  -464,  -464,  -464,  -464,  -464,    -4,  -464,  -464,  -464,
    -464,  -464,   205,  -464,  -464,  -464,  -464,  -464,   205,   123,
     -13,  -464,  -464,  -464,  -464,  -464,  -464,  3407,  -464,  -464,
      78,    80,   199,   212,    -2,  1052,  -464,    67,   205,  -464,
     676,  1347,  1411,   676,    88,  2411,   676,    77,   130,  2520,
    -464,    47,   169,  -464,   133,  1456,  -464,    44,  -464,   140,
    3272,   164,  -464,   133,  3033,  -464,   205,  1520,   676,  -464,
     235,  1565,  -464,    -6,  -464,   175,  1191,  -464,   161,  1629,
      40,   184,  1693,    69,    69,    69,  1118,    69,  -464,  -464,
    -464,   205,   205,   214,   214,  3272,   189,  -464,   252,  3272,
    3107,  3122,  3107,  3122,  3122,  3272,  3272,  3272,  3272,  3272,
    3272,  3272,  3272,  3272,  3272,  3272,  3272,   214,  3272,  3272,
    3272,  3272,  3272,  3272,  3272,  3272,  3272,  3272,  3272,  3272,
    3272,  3272,  -464,  -464,  -464,  -464,  -464,  -464,  -464,  -464,
    -464,  -464,  -464,  -464,  3272,  3272,  -464,  3272,  -464,  1629,
    3272,  3272,   222,  3272,   236,  1629,  3407,  3272,    54,   214,
      58,  -464,   149,  3272,   940,   214,    36,  2411,  3272,   214,
     194,   205,   240,  1236,   205,  3272,  3272,  2874,   187,  3272,
     241,    33,  3272,  -464,    38,  2686,   237,   243,   560,    13,
     205,    30,   248,  1118,  -464,  -464,  2411,  3272,  -464,   260,
     239,  -464,   283,   190,  3182,   292,  -464,   268,  1738,   300,
     271,   301,   275,   276,  3033,  1802,   769,   769,   769,   769,
    2565,   514,   202,  1847,   769,   216,   250,   216,    69,    69,
      69,    69,    69,  2856,   363,   363,   769,   769,   769,   769,
      69,   769,  2411,  2411,  2411,  2411,  2722,  2762,   306,  2520,
      36,   140,  -464,    36,   140,    65,  -464,    53,  -464,   105,
    3016,   220,   194,  -464,  -464,  2411,  -464,  2948,   299,   194,
    2798,   194,  -464,  2411,  -464,  3122,  -464,  1911,  3122,   214,
     307,   327,  -464,  1693,  -464,  -464,  -464,  1956,  3272,  3122,
    3122,  -464,  -464,   205,  3107,    18,   205,  2411,  3107,  -464,
    3107,   284,  3272,  3272,  2020,  3122,  -464,  3197,  3107,  -464,
    3107,   286,  -464,  -464,  3272,  3272,  -464,  2065,  -464,  2129,
     205,   313,   313,    36,   140,  3272,   317,  -464,  -464,   272,
     289,   230,  -464,   274,  -464,  1013,  -464,  3257,   324,  -464,
     297,   354,   331,  -464,   303,  3272,   304,   332,   311,   214,
    3272,   103,  -464,   338,   314,   315,   316,   194,   321,   344,
     145,    62,   214,  -464,  -464,  -464,   346,  -464,   322,   206,
     349,   350,  -464,  -464,  2411,  2411,  3272,  -464,  3272,  2193,
     349,   350,  -464,   925,  2411,  -464,  -464,   194,    36,   326,
     328,   313,  2238,   940,  -464,   238,  -464,   308,  -464,  -464,
    -464,   205,  1302,   205,   355,   358,  -464,   359,   205,  -464,
    2411,  -464,    19,  -464,  -464,  2456,  -464,  3272,  -464,  -464,
    -464,  -464,   361,  3107,  3107,   364,    20,   365,   366,    11,
    -464,   -11,  3272,  3272,    31,   337,  3272,   342,  2411,  2411,
    3272,   353,   357,   391,  -464,  -464,   360,   205,  -464,  -464,
     194,   214,   205,   194,   205,   205,   205,   194,  -464,   362,
    3272,   205,   146,   177,   205,   214,   370,    37,  -464,  -464,
    -464,   380,  -464,  -464,   940,  3272,  2302,  2411,   385,  -464,
    -464,  2411,  -464,  -464,   393,  -464,   194,  -464,   396,   194,
    -464,   194,   194,   194,  -464,  -464,  1802,   194,    31,   397,
     398,   194,   366,    42,  -464,   214,   389,    18,  -464,  -464,
    2347,  3272,   205,   318,   205,  -464,   423,  -464,  -464,  -464,
     205,   205,  -464,  -464,   214,   366,    49,  -464,  -464,   399,
     940,  2411,   194,   402,  -464,   194,   403,   194,   194,   366,
    -464,   214,    18,  -464,  -464,   205,  -464,   205,  -464,  -464,
    -464,   366,   194,   194,  -464,  -464,  -464
  };

  const short
   Parser ::yydefact_[] =
  {
     120,   222,   224,   225,   292,   168,   227,   226,   228,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    41,     0,     0,     0,     0,     0,   172,
       0,     0,     0,     0,     0,   229,   297,   295,   296,   120,
       3,     5,    67,    71,    72,    63,     0,    70,    69,    68,
      65,    66,     0,    73,   118,   113,   114,   115,    23,     0,
     119,   116,   117,    74,   275,    75,   112,     0,    64,    62,
     223,    30,     0,   232,   233,   166,   276,   221,     4,   294,
       0,    28,    39,     0,    43,   174,     0,     0,    34,   176,
      84,     0,     0,    77,   154,     0,    80,    78,    82,    85,
       0,     0,   278,   156,   271,    42,     0,     0,     0,   109,
       0,   106,   239,     0,   179,     0,   174,   231,     0,   174,
       0,   171,   174,   248,   249,   242,     0,   250,     1,     2,
     164,    22,    24,     0,     0,     0,   165,   167,     0,    31,
     172,     0,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,   169,     0,   293,     0,
       0,     0,     0,    44,     0,   176,     0,    35,     0,     0,
       0,    83,     0,     0,     0,     0,     0,   279,     0,     0,
       0,     0,     0,   106,     0,     0,     0,     0,   236,     0,
     240,     0,     0,   291,     0,     0,   230,   234,     0,     0,
     122,     0,     0,     0,   163,   170,   173,     0,   180,   171,
       0,   185,   146,   221,   200,   213,   199,     0,   212,   171,
       0,   146,     0,     0,   269,     0,   267,   265,   266,   268,
     270,   254,   256,    60,   259,   244,   238,   243,   245,   251,
     253,   252,   247,   255,   257,   258,   261,   262,   263,   264,
     246,   260,    47,   241,    29,    40,     0,     0,     0,   175,
       0,    86,    76,     0,    88,     0,     9,   160,     8,     0,
       0,     0,     0,    79,    81,   280,   277,   120,     0,     0,
       0,     0,   108,   107,   237,     0,   178,     0,     0,     0,
     283,     0,   282,   177,   273,   290,    32,   173,   172,     0,
       0,   235,   272,     0,   172,   144,   121,   183,   181,   189,
     145,     0,     0,   204,   202,     0,   214,   201,   181,   193,
     145,     0,   215,   220,     0,     0,    45,   173,    36,   175,
       0,   146,   146,     0,    89,     0,     0,   162,    12,     0,
      18,    21,    14,     0,     7,   120,    11,     0,     0,   100,
     101,    92,     0,   110,     0,     0,     0,     0,   282,   284,
       0,     0,    33,   171,     0,     0,     0,     0,     0,   171,
       0,     0,     0,   134,   143,   129,   146,   132,     0,   123,
     146,   146,   184,   192,   182,   205,   207,   198,   206,   203,
     146,   146,   196,   155,    61,    46,    37,     0,   145,     0,
       0,   146,     0,     0,    13,    20,    15,     0,    17,     6,
      10,     0,     0,     0,     0,     0,    99,     0,     0,   217,
     177,   219,     0,   285,   281,   288,   274,   181,   197,   218,
     216,   149,     0,     0,     0,     0,     0,   146,   146,   145,
     130,     0,     0,     0,   145,     0,   145,     0,   209,   208,
     210,     0,     0,    94,    87,    90,     0,     0,   161,    16,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   281,
       0,     0,     0,     0,     0,     0,   146,   145,   138,   145,
     142,   146,   133,   131,     0,     0,   124,   125,     0,   190,
     191,   211,   194,   195,     0,    91,     0,    96,     0,     0,
     105,     0,     0,     0,   111,   287,   289,     0,     0,     0,
       0,     0,   146,   145,   135,     0,   146,   145,   127,   147,
       0,     0,     0,   157,     0,    97,   102,   103,    93,   150,
       0,     0,   153,   136,     0,   146,   145,   139,   128,   146,
       0,   126,     0,     0,   159,     0,     0,     0,     0,   146,
     140,     0,   145,   148,    95,     0,    98,     0,   151,   152,
     137,   146,     0,     0,   141,   158,   104
  };

  const short
   Parser ::yypgoto_[] =
  {
    -464,  -464,   416,   226,  -464,  -411,  -464,  -464,  -464,  -464,
    -286,  -464,  -464,  -464,  -464,   -14,  -464,  -464,  -464,  -464,
    -464,  -464,  -464,  -199,     5,  -203,  -105,  -464,  -464,  -464,
    -464,    76,  -464,  -464,  -202,   356,  -464,  -464,  -464,  -464,
    -268,  -464,   -90,  -448,  -463,  -464,   -35,  -464,  -464,  -464,
    -464,  -464,   -95,  -464,  -464,  -464,  -464,  -464,   -28,    34,
     375,   244,  -464,  -134,  -336,   -98,  -464,  -464,  -464,   121,
     -77,  -464,     2,  -464,  -464,   148,  -464,  -214,  -115,   320,
       0,   100
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    39,    40,   308,   296,   297,   375,   298,   299,   300,
      41,    42,    43,    44,    45,    46,    87,    47,    48,    49,
      50,   185,    51,    52,    97,    98,    99,    92,    53,    54,
      55,   379,   380,    56,   109,   110,    57,    58,    59,    60,
     403,   404,   405,   406,   407,   408,   470,    61,    62,    63,
      64,    65,   367,    66,    67,    68,    69,    70,   238,    71,
      88,   114,   115,   240,   241,   242,    72,    73,   245,   246,
     247,    74,    85,   101,    76,   320,   321,   223,   224,    77,
     302,    79
  };

  const short
   Parser ::yytable_[] =
  {
      78,   120,    75,   304,   412,   301,   513,   229,   250,   105,
     325,    81,    82,   312,   412,   325,    89,     4,   506,    95,
      91,   376,   488,   104,     4,     4,     4,   107,   111,   116,
     119,   122,   123,   124,   125,   126,   127,     4,   514,     4,
     221,    75,     4,     4,   251,   217,   106,    84,     4,   130,
      94,   135,   131,   136,   103,     4,   144,   205,   132,   546,
       4,   113,   118,   121,     4,   221,   252,   253,     4,     4,
     218,     4,   515,   401,   402,   186,   365,   366,   198,   333,
     401,   402,   189,   505,     4,   119,   137,   334,   195,   440,
     319,   332,   511,   291,   237,   294,   498,   202,    96,   569,
     545,   370,   207,   549,   199,   564,   210,   199,   312,   196,
     213,   290,   581,   466,   324,   293,    96,   192,   227,   513,
      96,   187,   363,    90,  -186,  -186,   230,    96,   412,   157,
     221,   139,   160,   467,   468,  -187,  -187,   233,   412,   193,
       4,   236,   133,   248,   134,   248,   248,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   583,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   239,     4,   249,   325,   188,   456,
     295,   197,   288,   100,   203,   361,   281,   282,   362,   283,
     364,   206,   284,   285,   394,   236,   464,   538,   186,   289,
     200,   512,   412,   368,   369,   236,    75,   341,   391,   199,
     305,   309,   225,   208,   311,   209,   351,   111,   313,   236,
       4,   317,   465,   539,   323,   304,   219,   327,   203,   201,
     236,   188,   188,   336,   301,   228,   400,   542,   384,   337,
     410,   386,   234,   342,   187,   315,   344,  -186,  -186,   152,
     420,   220,   395,   396,   540,   472,   140,   141,   431,   473,
     235,   156,   157,   158,   159,   160,   161,   162,   163,   142,
     143,   165,   166,   286,    36,   512,   157,   565,   159,   160,
     161,   162,   163,   171,   214,    36,   215,   287,   357,   359,
     307,   310,    37,    38,   328,   329,   579,   171,   512,   318,
     371,   330,    75,    37,    38,   335,   398,  -188,  -188,    75,
     188,   338,   111,   591,   512,   301,   339,   248,   372,   373,
     248,   444,   377,   445,   377,   378,   429,   430,   436,   437,
     188,   248,   248,   397,   340,    93,   -19,   -19,    93,   102,
     236,   365,   573,   345,   414,   415,   346,   248,   349,   419,
     236,   348,   350,   352,   353,   360,   423,   424,   389,   390,
     427,   413,   393,   422,   428,   502,   433,   432,   399,   435,
     434,   301,   438,   443,   411,   475,   477,    75,   447,   442,
     448,   449,   451,   452,   421,   481,   482,   450,   453,   457,
     138,   458,   455,   459,   460,   463,   486,   469,   462,   471,
     474,   476,   188,   484,   494,   485,   489,   495,   496,   188,
     501,   188,    93,   504,   519,   524,   507,   509,   478,   520,
     479,   543,   156,   157,   158,   159,   160,   161,   162,   163,
     522,   547,   508,   510,   523,    75,   188,   525,   342,   535,
     566,   490,   552,   493,   171,   554,   560,   561,   497,   576,
     582,   585,   587,   231,   232,   129,   446,   568,   574,   236,
     243,   194,   243,   316,   212,   236,   417,   387,     0,     0,
       0,   544,     0,     0,   516,   517,   548,   266,   236,     0,
       0,     0,   521,     0,     0,     0,     0,   526,     0,     0,
       0,     0,   529,     0,   531,   532,   533,   188,   503,     0,
       0,   537,   536,     0,   541,     0,     0,   563,     0,     0,
       0,   567,     0,     0,     0,     0,    75,   550,    93,   292,
      93,     0,     0,     0,     0,   303,    93,   188,   374,   306,
     580,     0,     0,     0,     0,   381,     0,   383,     0,     0,
       0,   322,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,   572,   571,   575,     0,   594,     0,     0,     0,
     577,   578,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,    75,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,   165,   166,   592,     0,   593,     0,     0,
     188,     0,     0,   188,     0,   171,    19,   188,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    93,     0,    93,    27,    80,    29,    30,
       0,    31,    32,   461,     0,     0,   188,    34,     0,   188,
       0,   188,   188,   188,     0,    35,     0,   188,   331,   388,
       0,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   483,   243,   409,     0,     0,   243,     0,
     243,     0,     0,     0,     0,     0,     0,     0,   243,     0,
     243,     0,   188,     0,     0,   188,     0,   188,   188,     1,
       2,     3,     4,    93,     5,     6,     7,     8,     0,     0,
       0,     0,   188,   188,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
       0,     0,    19,     0,    21,     0,   527,     0,     0,   530,
       0,   409,   409,   534,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    80,    29,    30,     0,    31,    32,     0,
       0,     0,     0,    34,     0,     0,     0,     0,    93,     0,
       0,    35,   553,   117,     0,   555,     0,   556,   557,   558,
       0,     0,     0,   559,     0,     0,     0,   562,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,   243,     0,   409,     0,     0,   409,
       0,     0,     0,     0,   518,     0,     0,     0,   584,   146,
       0,   586,     0,   588,   589,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,   152,   153,   595,   596,
       0,     0,     0,     0,     0,   409,     0,   409,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,   518,     0,
       0,     0,     0,   409,     0,   409,     0,   409,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     9,    10,     0,   409,    11,   409,    12,     0,    13,
       0,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,   409,   409,    19,    20,    21,     0,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,    29,    30,     0,    31,    32,
       0,    33,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    35,     1,     2,     3,     4,    36,     5,     6,
       7,     8,     0,     0,     9,    10,     0,     0,    11,     0,
      12,     0,    13,     0,     0,    37,    38,     0,    15,    16,
       0,    18,   152,   153,     0,     0,    19,    20,    21,     0,
      22,    23,     0,     0,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,   166,    27,    28,    29,    30,
       0,    31,    32,     0,     0,     0,   171,    34,     0,     0,
       0,     0,     0,     0,     0,    35,     1,     2,     3,     4,
      36,     5,     6,     7,     8,     0,     0,     9,    10,     0,
       0,    11,     0,    12,     0,    13,     0,     0,    37,    38,
      14,    15,    16,    17,    18,     0,     0,     0,     0,    19,
      20,    21,     0,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,     0,    27,
      28,    29,    30,     0,    31,    32,     0,    33,     0,     0,
      34,     0,   146,     0,   147,   148,   149,   150,    35,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   154,     0,  -174,     0,  -174,     0,   155,     0,     0,
     439,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
     145,     0,     0,   171,     0,     0,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   146,     0,
     147,   148,   149,   150,   184,     0,     0,   151,     0,     0,
       0,     0,     0,     0,     0,   152,   153,     0,     0,     0,
       0,     0,     0,   155,     0,     0,     0,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,   165,   166,   167,
     168,   169,   170,     0,     0,     0,     0,     0,    36,   171,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,   221,     0,
     184,   146,     0,   147,   148,   149,   150,     0,     0,     0,
     151,     0,     0,     0,     0,     0,     0,     0,   152,   153,
     222,     0,     0,     0,     0,     0,   155,     0,   145,   216,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   146,     0,   147,   148,
     149,   150,   171,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,   152,   153,     0,     0,     0,     0,     0,
       0,   155,     0,   184,     0,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,   168,   169,
     170,     0,     0,   226,   145,   491,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,   147,   148,   149,   150,   184,     0,
       0,   151,     0,     0,     0,     0,     0,     0,     0,   152,
     153,   492,     0,     0,     0,     0,     0,   155,     0,   145,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,   168,   169,   170,   146,     0,   147,
     148,   149,   150,   171,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,   190,     0,
       0,     0,   155,     0,   184,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   164,   165,   166,   167,   168,
     169,   170,     0,   145,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
       0,   146,     0,   147,   148,   149,   150,     0,     0,   184,
     151,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,     0,     0,     0,     0,   155,     0,   145,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   146,     0,   147,   148,
     149,   150,   171,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,   152,   153,   204,     0,     0,     0,     0,
       0,   155,     0,   184,     0,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,   168,   169,
     170,     0,   145,     0,     0,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,   147,   148,   149,   150,     0,     0,   184,   151,
       0,     0,     0,     0,     0,     0,     0,   152,   153,   211,
       0,     0,     0,     0,     0,   155,     0,   145,   216,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,   168,   169,   170,   146,     0,   147,   148,   149,
     150,   171,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,     0,     0,     0,     0,
     155,     0,   184,     0,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,   166,   167,   168,   169,   170,
       0,   145,     0,     0,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   147,   148,   149,   150,     0,     0,   184,   151,     0,
       0,     0,     0,     0,     0,     0,   152,   153,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,   168,   169,   170,     0,   145,   226,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,   146,     0,   147,   148,   149,   150,     0,
       0,   184,   151,     0,     0,     0,     0,     0,     0,     0,
     152,   153,     0,     0,     0,     0,     0,     0,   155,     0,
     145,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   167,   168,   169,   170,   146,     0,
     147,   148,   149,   150,   171,     0,     0,   151,     0,     0,
       0,     0,     0,     0,     0,   152,   153,   347,     0,     0,
       0,     0,     0,   155,     0,   184,     0,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,   165,   166,   167,
     168,   169,   170,     0,   145,     0,     0,     0,     0,   171,
       0,     0,     0,     0,     0,     0,   354,     0,     0,     0,
       0,     0,   146,     0,   147,   148,   149,   150,     0,     0,
     184,   151,     0,     0,     0,     0,     0,     0,     0,   152,
     153,     0,     0,     0,     0,     0,     0,   155,     0,   145,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,   168,   169,   170,   146,     0,   147,
     148,   149,   150,   171,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,   152,   153,     0,     0,     0,     0,
     355,     0,   155,     0,   184,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   164,   165,   166,   167,   168,
     169,   170,     0,   145,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,     0,   147,   148,   149,   150,     0,     0,   184,
     151,     0,     0,     0,     0,     0,     0,     0,   152,   153,
     385,     0,     0,     0,     0,     0,   155,     0,   145,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   146,     0,   147,   148,
     149,   150,   171,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,   152,   153,     0,     0,     0,     0,     0,
       0,   155,     0,   184,     0,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,   168,   169,
     170,     0,   145,   392,     0,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,   147,   148,   149,   150,     0,     0,   184,   151,
       0,     0,     0,     0,     0,     0,     0,   152,   153,   416,
       0,     0,     0,     0,     0,   155,     0,   145,     0,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,   168,   169,   170,   146,     0,   147,   148,   149,
     150,   171,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,     0,     0,     0,     0,
     155,     0,   184,     0,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,   166,   167,   168,   169,   170,
       0,   145,   425,     0,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   147,   148,   149,   150,     0,     0,   184,   151,     0,
       0,     0,     0,     0,     0,     0,   152,   153,     0,     0,
       0,     0,     0,     0,   155,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,   168,   169,   170,     0,   145,   426,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,     0,   147,   148,   149,   150,     0,
       0,   184,   151,     0,     0,     0,     0,     0,     0,     0,
     152,   153,   480,     0,     0,     0,     0,     0,   155,     0,
     145,     0,   156,   157,   158,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   167,   168,   169,   170,   146,     0,
     147,   148,   149,   150,   171,     0,     0,   151,     0,     0,
       0,     0,     0,     0,     0,   152,   153,   487,     0,     0,
       0,     0,     0,   155,     0,   184,     0,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,   165,   166,   167,
     168,   169,   170,     0,   145,     0,     0,     0,     0,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,   147,   148,   149,   150,     0,     0,
     184,   151,     0,     0,     0,     0,     0,     0,     0,   152,
     153,     0,     0,     0,     0,   551,     0,   155,     0,   145,
       0,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,   168,   169,   170,   146,     0,   147,
     148,   149,   150,   171,     0,     0,   151,     0,     0,     0,
       0,     0,     0,     0,   152,   153,   570,     0,     0,     0,
       0,     0,   155,     0,   184,     0,   156,   157,   158,   159,
     160,   161,   162,   163,     0,   164,   165,   166,   167,   168,
     169,   170,     0,   145,     0,     0,     0,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,     0,   147,   148,   149,   150,     0,     0,   184,
     151,     0,     0,     0,     0,     0,     0,     0,   152,   153,
       0,     0,     0,     0,     0,     0,   155,     0,   145,     0,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,   168,   169,   170,   500,     0,   147,   148,
     149,   150,   171,     0,     0,   151,     0,     0,     0,     0,
       0,     0,     0,   152,   153,     0,     0,     0,     0,     0,
       0,   155,     0,   184,     0,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,   168,   169,
     170,     0,   145,     0,     0,     0,     0,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,     0,   148,   149,   150,     0,     0,   184,   151,
       0,     0,     0,     0,     0,     0,     0,   152,   153,     0,
       0,     0,     0,     0,     0,   155,     0,   145,     0,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,   168,   169,   170,   146,     0,   147,   148,   149,
     150,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   153,     0,     0,     0,     0,     0,     0,
     155,     0,   184,     0,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,   166,   167,   168,   169,   170,
       0,     0,     0,     0,   128,     0,   171,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     9,    10,
       0,     0,    11,     0,    12,     0,    13,   184,     0,     0,
       0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
      19,    20,    21,     0,    22,    23,    24,    25,    26,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
      27,    28,    29,    30,     0,    31,    32,     0,    33,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    19,     0,    21,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    80,    29,    30,     0,    31,    32,     0,
       0,     0,     0,    34,     0,     0,     0,     0,    19,     0,
      21,    35,     0,   326,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,    27,    80,
      29,    30,     0,    31,    32,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    35,    19,   356,
      21,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    80,
      29,    30,     0,    31,    32,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    19,     0,    21,    35,     0,   358,
       0,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     0,     0,    27,    80,    29,    30,     0,    31,
      32,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    35,    19,   382,    21,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    80,    29,    30,     0,    31,
      32,     0,     0,   152,   153,    34,     0,     0,     0,     0,
      19,     0,    21,    35,   112,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,   165,   166,     0,     0,     0,
      27,    80,    29,    30,     0,    31,    32,   171,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    35,
     314,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,     0,     0,     0,     0,    14,    15,    16,    17,    18,
       0,     0,     0,     0,    19,    20,    21,     0,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,     0,    31,
      32,     0,    33,     0,     0,    34,     0,     0,     0,     1,
       2,     3,     4,    35,     5,     6,     7,     8,     0,     0,
       9,    10,     0,     0,    11,     0,    12,     0,    13,     0,
       0,     0,     0,     0,    15,    16,     0,    18,     0,     0,
       0,     0,    19,    20,    21,     0,    22,    23,     0,     0,
       0,     0,     0,   146,     0,   147,   148,   149,   150,     0,
       0,     0,    27,    28,    29,    30,     0,    31,    32,     0,
     152,   153,     0,    34,     0,     0,     0,     0,   155,     0,
       0,    35,   156,   157,   158,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   167,   168,   169,   170,     0,     0,
       1,     2,     3,     4,   171,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,   184,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,    27,    80,    29,    30,     0,    31,    32,
     237,   244,     0,     0,    34,     0,     0,     0,    27,    80,
      29,    30,    35,    31,    32,     1,     2,     3,     4,    34,
       5,     6,     7,     8,     0,     0,     0,    35,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   343,     0,    19,     0,    21,     0,     0,    27,    80,
      29,    30,     0,    31,    32,     0,   418,     0,     0,    34,
       0,     0,     0,    27,    80,    29,    30,    35,    31,    32,
       1,     2,     3,     4,    34,     5,     6,     7,     8,     0,
       0,     0,    35,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,     0,    19,     0,
      21,     0,     0,    27,    80,    29,    30,     0,    31,    32,
       0,     0,     0,     0,    34,     0,     0,     0,    27,    80,
      29,    30,    35,    31,    32,     1,     2,     3,     4,    34,
       5,     6,     7,     8,     0,     0,     0,    35,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,    27,    83,
      29,    30,     0,    31,    32,     0,     0,     0,     0,    34,
       0,     0,     0,    27,    86,    29,    30,    35,    31,    32,
       1,     2,     3,     4,    34,     5,     6,     7,     8,     0,
       0,     0,    35,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,    27,    28,    29,    30,     0,    31,    32,
       0,     0,     0,     0,    34,     0,     0,     0,    27,   108,
      29,    30,    35,    31,    32,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    35
  };

  const short
   Parser ::yycheck_[] =
  {
       0,    29,     0,   206,   340,   204,   469,   122,   142,    23,
     224,     9,    10,   215,   350,   229,    14,     6,   466,    17,
      15,   307,   433,    21,     6,     6,     6,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,    49,     6,
      27,    39,     6,     6,   142,    51,    49,    13,     6,    53,
      16,    64,    52,    67,    20,     6,    58,    13,    58,   507,
       6,    27,    28,    29,     6,    27,   143,   144,     6,     6,
      76,     6,    83,    62,    63,     8,    23,    24,    31,    49,
      62,    63,    80,    63,     6,    83,     8,    57,    86,   375,
      57,    78,    81,   198,    63,   200,    77,    92,    62,   547,
      63,   300,   100,   514,    60,    63,   106,    60,   310,    32,
     108,    57,    63,    51,    76,    57,    62,    83,    78,   582,
      62,    54,    57,    60,    57,    58,   126,    62,   464,    60,
      27,    51,    63,   401,   402,    57,    58,   135,   474,    51,
       6,   139,    19,   141,    21,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   570,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   140,     6,   142,   391,    78,    76,
      31,    51,   196,    49,    51,   290,   184,   185,   293,   187,
     295,    51,   190,   191,   328,   193,    51,    51,     8,   197,
      31,   469,   538,    98,    99,   203,   204,   242,   323,    60,
     208,   211,    51,    49,   214,    51,   251,   215,   216,   217,
       6,   219,    77,    77,   222,   428,    51,   225,    51,    60,
     228,   131,   132,   233,   433,    51,   334,   505,   315,   237,
     338,   318,    53,    53,    54,    58,   244,    57,    58,    47,
     348,    76,   329,   330,    77,    49,    57,    58,   363,    53,
       8,    59,    60,    61,    62,    63,    64,    65,    66,    57,
      58,    69,    70,    51,    80,   543,    60,   545,    62,    63,
      64,    65,    66,    81,    49,    80,    51,    51,   286,   287,
      96,    51,    98,    99,    57,    58,   564,    81,   566,    58,
      80,    58,   300,    98,    99,    57,   334,    57,    58,   307,
     210,    51,   310,   581,   582,   514,    77,   315,    98,    99,
     318,    24,    25,    26,    25,    26,   361,   362,    98,    99,
     230,   329,   330,   333,    51,    15,    98,    99,    18,    19,
     338,    23,    24,    51,   342,   343,    78,   345,    77,   347,
     348,    51,    51,    78,    78,    49,   354,   355,    51,    32,
     360,    77,   328,    77,    51,   463,    49,   365,   334,    80,
      98,   570,    98,    49,   340,   410,   411,   375,    24,   377,
      49,    78,    78,    51,   350,   420,   421,   385,    77,    51,
      70,    77,   390,    78,    78,    51,   431,    51,    77,    77,
      51,    51,   302,    77,    49,    77,    98,    49,    49,   309,
      49,   311,    92,    49,    77,    24,    51,    51,   416,    77,
     418,    51,    59,    60,    61,    62,    63,    64,    65,    66,
      77,    51,   467,   468,    77,   433,   336,    77,    53,    77,
      51,   441,    49,   443,    81,    49,    49,    49,   448,    26,
      51,    49,    49,   133,   134,    39,   380,   547,   553,   457,
     140,    86,   142,   219,   108,   463,   345,   319,    -1,    -1,
      -1,   506,    -1,    -1,   472,   473,   511,   157,   476,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    -1,   492,    -1,   494,   495,   496,   397,   464,    -1,
      -1,   501,   500,    -1,   504,    -1,    -1,   542,    -1,    -1,
      -1,   546,    -1,    -1,    -1,    -1,   514,   515,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,   206,   427,   302,   209,
     565,    -1,    -1,    -1,    -1,   309,    -1,   311,    -1,    -1,
      -1,   221,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   552,   551,   554,    -1,   591,    -1,    -1,    -1,
     560,   561,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,   570,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    69,    70,   585,    -1,   587,    -1,    -1,
     490,    -1,    -1,   493,    -1,    81,    36,   497,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     290,    -1,    -1,   293,    -1,   295,    56,    57,    58,    59,
      -1,    61,    62,   397,    -1,    -1,   526,    67,    -1,   529,
      -1,   531,   532,   533,    -1,    75,    -1,   537,    78,   319,
      -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   427,   334,   335,    -1,    -1,   338,    -1,
     340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,
     350,    -1,   572,    -1,    -1,   575,    -1,   577,   578,     3,
       4,     5,     6,   363,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,   592,   593,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,
      -1,    -1,    36,    -1,    38,    -1,   490,    -1,    -1,   493,
      -1,   401,   402,   497,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    75,   526,    77,    -1,   529,    -1,   531,   532,   533,
      -1,    -1,    -1,   537,    -1,    -1,    -1,   541,    -1,    -1,
      -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   463,   464,    -1,   466,    -1,    -1,   469,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,   572,    30,
      -1,   575,    -1,   577,   578,    -1,    -1,    -1,    -1,    -1,
      -1,   491,    -1,    -1,    -1,    -1,    47,    48,   592,   593,
      -1,    -1,    -1,    -1,    -1,   505,    -1,   507,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,    -1,
      -1,    -1,    -1,   543,    -1,   545,    -1,   547,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,   564,    18,   566,    20,    -1,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      -1,   581,   582,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,     3,     4,     5,     6,    80,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    98,    99,    -1,    28,    29,
      -1,    31,    47,    48,    -1,    -1,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    81,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,
      80,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    98,    99,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,
      67,    -1,    30,    -1,    32,    33,    34,    35,    75,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    51,    -1,    53,    -1,    55,    -1,    -1,
      97,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      12,    -1,    -1,    81,    -1,    -1,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    30,    -1,
      32,    33,    34,    35,   102,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,    27,    -1,
     102,    30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    13,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,   102,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    77,    12,    13,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,   102,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,   102,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,   102,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    12,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    -1,    -1,   102,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    13,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,   102,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    12,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,   102,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    12,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      12,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,
     102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,   102,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,   102,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,   102,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    12,    77,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    -1,    -1,   102,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,   102,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    12,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,   102,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    12,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      12,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,
     102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    12,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,   102,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    30,    -1,    32,    33,
      34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,   102,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    12,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    -1,    -1,   102,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    30,    -1,    32,    33,    34,
      35,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,   102,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,     0,    -1,    81,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    -1,    22,   102,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    42,    43,    44,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    64,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    36,    -1,    38,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    36,    -1,
      38,    75,    -1,    77,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    36,    77,
      38,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    36,    -1,    38,    75,    -1,    77,
      -1,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    36,    77,    38,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    -1,    47,    48,    67,    -1,    -1,    -1,    -1,
      36,    -1,    38,    75,    76,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    69,    70,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    81,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,     3,
       4,     5,     6,    75,     8,     9,    10,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      47,    48,    -1,    67,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    75,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
       3,     4,     5,     6,    81,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      63,    49,    -1,    -1,    67,    -1,    -1,    -1,    56,    57,
      58,    59,    75,    61,    62,     3,     4,     5,     6,    67,
       8,     9,    10,    11,    -1,    -1,    -1,    75,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    36,    -1,    38,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    49,    -1,    -1,    67,
      -1,    -1,    -1,    56,    57,    58,    59,    75,    61,    62,
       3,     4,     5,     6,    67,     8,     9,    10,    11,    -1,
      -1,    -1,    75,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    36,    -1,
      38,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    56,    57,
      58,    59,    75,    61,    62,     3,     4,     5,     6,    67,
       8,     9,    10,    11,    -1,    -1,    -1,    75,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    56,    57,    58,    59,    75,    61,    62,
       3,     4,     5,     6,    67,     8,     9,    10,    11,    -1,
      -1,    -1,    75,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    56,    57,
      58,    59,    75,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    27,    28,    29,    30,    31,    36,
      37,    38,    40,    41,    42,    43,    44,    56,    57,    58,
      59,    61,    62,    64,    67,    75,    80,    98,    99,   105,
     106,   114,   115,   116,   117,   118,   119,   121,   122,   123,
     124,   126,   127,   132,   133,   134,   137,   140,   141,   142,
     143,   151,   152,   153,   154,   155,   157,   158,   159,   160,
     161,   163,   170,   171,   175,   176,   178,   183,   184,   185,
      57,   176,   176,    57,   163,   176,    57,   120,   164,   176,
      60,   128,   131,   183,   163,   176,    62,   128,   129,   130,
      49,   177,   183,   163,   176,   119,    49,   176,    57,   138,
     139,   176,    76,   163,   165,   166,   176,    77,   163,   176,
     162,   163,   176,   176,   176,   176,   176,   176,     0,   106,
      53,   184,   184,    19,    21,    64,   119,     8,   183,    51,
      57,    58,    57,    58,    58,    12,    30,    32,    33,    34,
      35,    39,    47,    48,    49,    55,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    70,    71,    72,    73,
      74,    81,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   102,   125,     8,    54,   185,   176,
      51,    28,   163,    51,   164,   176,    32,    51,    31,    60,
      31,    60,   128,    51,    49,    13,    51,   176,    49,    51,
     184,    49,   139,   176,    49,    51,    13,    51,    76,    51,
      76,    27,    49,   181,   182,    51,    77,    78,    51,   182,
     184,   183,   183,   176,    53,     8,   176,    63,   162,   163,
     167,   168,   169,   183,    49,   172,   173,   174,   176,   163,
     167,   169,   174,   174,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   183,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,    51,    51,   119,   176,
      57,   130,   183,    57,   130,    31,   108,   109,   111,   112,
     113,   127,   184,   183,   129,   176,   183,    96,   107,   184,
      51,   184,   138,   176,    76,    58,   165,   176,    58,    57,
     179,   180,   183,   176,    76,   181,    77,   176,    57,    58,
      58,    78,    78,    49,    57,    57,   184,   176,    51,    77,
      51,   150,    53,    49,   176,    51,    78,    49,    51,    77,
      51,   150,    78,    78,    24,    53,    77,   176,    77,   176,
      49,   130,   130,    57,   130,    23,    24,   156,    98,    99,
     127,    80,    98,    99,   107,   110,   114,    25,    26,   135,
     136,   107,    77,   107,   174,    49,   174,   179,   183,    51,
      32,   182,    77,   163,   167,   174,   174,   184,   162,   163,
     169,    62,    63,   144,   145,   146,   147,   148,   149,   183,
     169,   163,   168,    77,   176,   176,    49,   173,    49,   176,
     169,   163,    77,   176,   176,    77,    77,   184,    51,   150,
     150,   130,   176,    49,    98,    80,    98,    99,    98,    97,
     114,    49,   176,    49,    24,    26,   135,    24,    49,    78,
     176,    78,    51,    77,   183,   176,    76,    51,    77,    78,
      78,   107,    77,    51,    51,    77,    51,   144,   144,    51,
     150,    77,    49,    53,    51,   150,    51,   150,   176,   176,
      49,   150,   150,   107,    77,    77,   150,    49,   109,    98,
     184,    13,    49,   184,    49,    49,    49,   184,    77,   183,
      30,    49,   169,   163,    49,    63,   147,    51,   150,    51,
     150,    81,   144,   148,    49,    83,   176,   176,   183,    77,
      77,   176,    77,    77,    24,    77,   184,   107,   183,   184,
     107,   184,   184,   184,   107,    77,   176,   184,    51,    77,
      77,   184,   144,    51,   150,    63,   147,    51,   150,   109,
     176,    53,    49,   107,    49,   107,   107,   107,   107,   107,
      49,    49,   107,   150,    63,   144,    51,   150,   146,   147,
      49,   176,   184,    24,   156,   184,    26,   184,   184,   144,
     150,    63,    51,   109,   107,    49,   107,    49,   107,   107,
     150,   144,   184,   184,   150,   107,   107
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
     140,   140,   141,   141,   141,   141,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   144,   145,   145,   145,
     146,   146,   146,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   152,   152,   152,   153,   154,   155,   156,   156,   156,
     157,   157,   157,   158,   158,   159,   160,   161,   161,   161,
     161,   162,   162,   163,   163,   164,   164,   165,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   170,   170,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   172,   172,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   175,   175,   175,   175,   175,   175,
     175,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   180,   180,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   185,   185
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
       5,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     3,     1,     3,     3,     5,     4,     5,     1,
       2,     3,     1,     3,     1,     4,     5,     7,     3,     5,
       6,     8,     3,     1,     0,     1,     0,     8,    10,     6,
       9,    11,    11,     9,     2,     5,     2,     5,     9,     6,
       4,     7,     5,     3,     2,     2,     1,     2,     1,     2,
       3,     1,     0,     3,     1,     3,     1,     3,     3,     1,
       1,     2,     3,     2,     3,     1,     1,     1,     3,     4,
       7,     7,     5,     4,     7,     7,     5,     6,     3,     1,
       1,     2,     2,     3,     2,     3,     3,     3,     4,     4,
       4,     5,     1,     1,     4,     4,     6,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     1,     3,     4,     3,     4,     3,     2,
       3,     3,     2,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     4,     6,     1,     1,     3,     1,     3,
       4,     3,     1,     1,     2,     3,     4,     5,     4,     6,
       2,     1,     1,     2,     1,     1,     1,     1
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
  "function_def", "class_def", "global_statement", "ternary_if_statement",
  "nonlocal_statement", "elif_statement", "if_statement", "target_list",
  "assignment_statement", "expression_statment", "string", "expr_list_opt",
  "expr_list", "expr_for_list", "dict", "dict_list", "call_arguement_list",
  "keyword_item", "keyword_items", "primary", "function_call",
  "slice_item_list", "slice_item", "tuple_list", "subscription", "expr",
  "lambda_id_list", "lambda_expression", "id_list", "id_item", "comp_for",
  "comp_for_items", "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   312,   312,   313,   314,   318,   322,   326,   330,   331,
     335,   336,   340,   341,   342,   343,   346,   349,   355,   358,
     364,   367,   373,   374,   375,   380,   384,   388,   392,   393,
     397,   398,   399,   400,   404,   405,   406,   407,   411,   412,
     413,   417,   418,   423,   424,   425,   427,   433,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     452,   453,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   475,   476,   480,   481,
     482,   486,   487,   491,   492,   498,   499,   501,   503,   505,
     507,   509,   514,   515,   519,   521,   532,   533,   534,   537,
     538,   542,   543,   545,   547,   549,   553,   554,   558,   559,
     563,   564,   573,   574,   575,   576,   577,   578,   582,   586,
     587,   591,   592,   596,   597,   598,   599,   603,   605,   607,
     611,   612,   614,   618,   619,   627,   628,   629,   631,   632,
     634,   636,   638,   642,   643,   647,   648,   652,   654,   666,
     668,   670,   672,   674,   680,   684,   688,   692,   693,   695,
     700,   703,   706,   711,   712,   716,   721,   725,   726,   729,
     732,   738,   739,   743,   744,   757,   758,   762,   765,   766,
     770,   771,   776,   777,   781,   782,   787,   788,   789,   793,
     794,   796,   798,   799,   800,   802,   804,   811,   816,   817,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   831,   832,   836,   840,   841,   842,   844,   846,   847,
     849,   853,   854,   858,   859,   860,   864,   865,   866,   867,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   878,
     879,   883,   884,   886,   887,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   898,   899,   900,   901,   902,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   915,
     916,   917,   920,   921,   922,   924,   925,   930,   931,   935,
     937,   949,   950,   954,   955,   956,   957,   958,   962,   963,
     968,   969,   973,   977,   978,   982,   983,   984
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
#line 4475 "./parser.cpp"

#line 987 "parser.ypp"
