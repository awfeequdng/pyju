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
#line 308 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1319 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 309 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1325 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 314 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1331 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 318 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1337 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 322 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1343 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 326 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1349 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 327 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1355 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 331 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1361 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 332 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1367 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 336 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1373 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 337 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1379 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 338 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1385 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 339 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1393 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 342 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1401 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 345 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1409 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 351 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1417 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 354 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1425 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 360 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1433 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 363 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1441 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 369 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1447 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 370 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1453 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 371 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1459 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 376 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1465 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 380 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1471 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 384 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1477 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 388 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1483 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 389 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1489 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 393 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1495 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 394 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1501 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 395 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1507 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 396 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1513 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 400 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1519 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 401 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1525 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 402 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1531 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 403 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1537 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 407 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1543 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 408 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1549 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 409 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1555 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 413 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1561 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 414 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1567 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 419 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1573 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 420 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1579 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 421 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1586 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 423 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1593 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 429 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1599 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 433 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1605 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 434 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1611 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 435 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1617 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 436 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1623 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 437 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1629 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 438 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1635 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 439 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1641 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 440 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1647 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 441 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1653 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 442 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1659 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 443 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1665 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 444 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1671 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 448 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1677 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 449 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1683 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 453 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1689 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 454 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1695 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 455 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1701 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 456 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1707 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 457 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1713 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 458 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1719 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 459 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1725 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 460 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1731 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 461 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1737 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 462 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1743 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 463 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1749 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 464 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1755 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 465 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1761 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 466 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1767 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 471 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1773 "./parser.cpp"
    break;

  case 77: // module: id
#line 472 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1779 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 476 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1785 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 477 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1791 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 478 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1797 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 482 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1803 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 483 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1809 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 487 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1815 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 488 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1821 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 494 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1827 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 495 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1834 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 497 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1841 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 499 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1848 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 501 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1855 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 503 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1862 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 505 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1869 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 510 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1875 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 511 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1882 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 515 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1889 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 518 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1895 "./parser.cpp"
    break;

  case 96: // except_statement: EXCEPT ":" sep statements
#line 528 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_01(yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1901 "./parser.cpp"
    break;

  case 97: // except_statement: EXCEPT expr ":" sep statements
#line 529 "parser.ypp"
                                     { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_02(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1907 "./parser.cpp"
    break;

  case 98: // except_statement: EXCEPT expr AS id ":" sep statements
#line 530 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_03(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1913 "./parser.cpp"
    break;

  case 99: // except_list: except_list except_statement
#line 533 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1919 "./parser.cpp"
    break;

  case 100: // except_list: except_statement
#line 534 "parser.ypp"
                       { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1925 "./parser.cpp"
    break;

  case 101: // try_statement: TRY ":" sep statements except_list
#line 538 "parser.ypp"
                                         { yylhs.value.as < Nonnull<Statement*> > () = TRY_01(yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1931 "./parser.cpp"
    break;

  case 102: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements
#line 539 "parser.ypp"
                                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_02(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1938 "./parser.cpp"
    break;

  case 103: // try_statement: TRY ":" sep statements except_list FINALLY ":" sep statements
#line 541 "parser.ypp"
                                                                    {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_03(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1945 "./parser.cpp"
    break;

  case 104: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements FINALLY ":" sep statements
#line 544 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = TRY_04(yystack_[9].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[8].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1951 "./parser.cpp"
    break;

  case 105: // try_statement: TRY ":" sep statements FINALLY ":" sep statements
#line 545 "parser.ypp"
                                                        { yylhs.value.as < Nonnull<Statement*> > () = TRY_05(yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1957 "./parser.cpp"
    break;

  case 106: // with_item: expr
#line 549 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1963 "./parser.cpp"
    break;

  case 107: // with_item: expr AS expr
#line 550 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1969 "./parser.cpp"
    break;

  case 108: // with_item_list: with_item_list "," with_item
#line 554 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1975 "./parser.cpp"
    break;

  case 109: // with_item_list: with_item
#line 555 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1981 "./parser.cpp"
    break;

  case 110: // with_statement: WITH with_item_list ":" sep statements
#line 559 "parser.ypp"
                                             { yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1987 "./parser.cpp"
    break;

  case 111: // with_statement: WITH "(" with_item_list "," ")" ":" sep statements
#line 560 "parser.ypp"
                                                         {
        yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1994 "./parser.cpp"
    break;

  case 112: // multi_line_statement: if_statement
#line 569 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2000 "./parser.cpp"
    break;

  case 113: // multi_line_statement: for_statement
#line 570 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2006 "./parser.cpp"
    break;

  case 114: // multi_line_statement: try_statement
#line 571 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2012 "./parser.cpp"
    break;

  case 115: // multi_line_statement: with_statement
#line 572 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2018 "./parser.cpp"
    break;

  case 116: // multi_line_statement: function_def
#line 573 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2024 "./parser.cpp"
    break;

  case 117: // multi_line_statement: class_def
#line 574 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2030 "./parser.cpp"
    break;

  case 118: // multi_line_statement: while_statement
#line 578 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2036 "./parser.cpp"
    break;

  case 119: // decorators_opt: decorators
#line 582 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2042 "./parser.cpp"
    break;

  case 120: // decorators_opt: %empty
#line 583 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2048 "./parser.cpp"
    break;

  case 121: // decorators: decorators "@" expr sep
#line 587 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2054 "./parser.cpp"
    break;

  case 122: // decorators: "@" expr sep
#line 588 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2060 "./parser.cpp"
    break;

  case 123: // parameter: id
#line 592 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2066 "./parser.cpp"
    break;

  case 124: // parameter: id ":" expr
#line 593 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2072 "./parser.cpp"
    break;

  case 125: // parameter: id "=" expr
#line 594 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2078 "./parser.cpp"
    break;

  case 126: // parameter: id ":" expr "=" expr
#line 595 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2084 "./parser.cpp"
    break;

  case 127: // parameter_list: defparameter_list "," "/" comma_opt
#line 599 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2091 "./parser.cpp"
    break;

  case 128: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 601 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2098 "./parser.cpp"
    break;

  case 129: // parameter_list: parameter_list_no_posonly
#line 603 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2104 "./parser.cpp"
    break;

  case 130: // parameter_list_no_posonly: defparameter_list comma_opt
#line 607 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2110 "./parser.cpp"
    break;

  case 131: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 608 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2117 "./parser.cpp"
    break;

  case 132: // parameter_list_no_posonly: parameter_list_starargs
#line 610 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2123 "./parser.cpp"
    break;

  case 133: // defparameter_list: defparameter_list "," parameter
#line 614 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2129 "./parser.cpp"
    break;

  case 134: // defparameter_list: parameter
#line 615 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2135 "./parser.cpp"
    break;

  case 135: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 623 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2141 "./parser.cpp"
    break;

  case 136: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 624 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2147 "./parser.cpp"
    break;

  case 137: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 625 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2154 "./parser.cpp"
    break;

  case 138: // parameter_list_starargs: "*" parameter comma_opt
#line 627 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2160 "./parser.cpp"
    break;

  case 139: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 628 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2167 "./parser.cpp"
    break;

  case 140: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 630 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2174 "./parser.cpp"
    break;

  case 141: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 632 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2181 "./parser.cpp"
    break;

  case 142: // parameter_list_starargs: "**" parameter comma_opt
#line 634 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2187 "./parser.cpp"
    break;

  case 143: // parameter_list_opt: parameter_list
#line 638 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 2193 "./parser.cpp"
    break;

  case 144: // parameter_list_opt: %empty
#line 639 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 2199 "./parser.cpp"
    break;

  case 147: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 649 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2205 "./parser.cpp"
    break;

  case 148: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 651 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2211 "./parser.cpp"
    break;

  case 149: // class_def: decorators_opt CLASS id ":" sep statements
#line 662 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_01(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2218 "./parser.cpp"
    break;

  case 150: // class_def: decorators_opt CLASS id "(" expr_list_opt ")" ":" sep statements
#line 664 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_02(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2225 "./parser.cpp"
    break;

  case 151: // class_def: decorators_opt CLASS id "(" expr_list "," keyword_items ")" ":" sep statements
#line 667 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[6].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2231 "./parser.cpp"
    break;

  case 152: // class_def: decorators_opt CLASS id "(" keyword_items "," expr_list ")" ":" sep statements
#line 669 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2237 "./parser.cpp"
    break;

  case 153: // class_def: decorators_opt CLASS id "(" keyword_items ")" ":" sep statements
#line 670 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_04(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2244 "./parser.cpp"
    break;

  case 154: // global_statement: GLOBAL expr_list
#line 676 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2250 "./parser.cpp"
    break;

  case 155: // ternary_if_statement: expr IF expr ELSE expr
#line 680 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2256 "./parser.cpp"
    break;

  case 156: // nonlocal_statement: NONLOCAL expr_list
#line 684 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2262 "./parser.cpp"
    break;

  case 157: // elif_statement: ELIF expr ":" sep statements
#line 688 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2268 "./parser.cpp"
    break;

  case 158: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 689 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2275 "./parser.cpp"
    break;

  case 159: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 691 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2282 "./parser.cpp"
    break;

  case 160: // if_statement: IF expr ":" body_stmts
#line 696 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2290 "./parser.cpp"
    break;

  case 161: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 699 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2298 "./parser.cpp"
    break;

  case 162: // if_statement: IF expr ":" body_stmts elif_statement
#line 702 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2305 "./parser.cpp"
    break;

  case 163: // target_list: target_list tuple_item "="
#line 707 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2311 "./parser.cpp"
    break;

  case 164: // target_list: tuple_item "="
#line 708 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2317 "./parser.cpp"
    break;

  case 165: // assignment_statement: target_list tuple_item
#line 712 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2323 "./parser.cpp"
    break;

  case 166: // expression_statment: expr
#line 717 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2329 "./parser.cpp"
    break;

  case 167: // string: string string_literal
#line 721 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2335 "./parser.cpp"
    break;

  case 168: // string: string_literal
#line 722 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2343 "./parser.cpp"
    break;

  case 169: // string: id string_literal
#line 725 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2351 "./parser.cpp"
    break;

  case 170: // string: string id string_literal
#line 728 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2359 "./parser.cpp"
    break;

  case 171: // expr_list_opt: expr_list
#line 734 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2365 "./parser.cpp"
    break;

  case 172: // expr_list_opt: %empty
#line 735 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2371 "./parser.cpp"
    break;

  case 173: // expr_list: expr_list "," expr
#line 739 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2377 "./parser.cpp"
    break;

  case 174: // expr_list: expr
#line 740 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2383 "./parser.cpp"
    break;

  case 175: // expr_for_list: expr_for_list "," expr
#line 753 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2389 "./parser.cpp"
    break;

  case 176: // expr_for_list: expr
#line 754 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2395 "./parser.cpp"
    break;

  case 177: // dict: expr ":" expr
#line 758 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2401 "./parser.cpp"
    break;

  case 178: // dict_list: dict_list "," dict
#line 761 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2407 "./parser.cpp"
    break;

  case 179: // dict_list: dict
#line 762 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2413 "./parser.cpp"
    break;

  case 180: // call_arguement_list: expr_list_opt
#line 766 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2419 "./parser.cpp"
    break;

  case 181: // call_arguement_list: expr_list ","
#line 767 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2425 "./parser.cpp"
    break;

  case 182: // keyword_item: id "=" expr
#line 772 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2431 "./parser.cpp"
    break;

  case 183: // keyword_item: "**" expr
#line 773 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2437 "./parser.cpp"
    break;

  case 184: // keyword_items: keyword_items "," keyword_item
#line 777 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2443 "./parser.cpp"
    break;

  case 185: // keyword_items: keyword_item
#line 778 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2449 "./parser.cpp"
    break;

  case 186: // primary: id
#line 783 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2455 "./parser.cpp"
    break;

  case 187: // primary: string
#line 784 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2461 "./parser.cpp"
    break;

  case 188: // primary: expr "." id
#line 785 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2467 "./parser.cpp"
    break;

  case 189: // function_call: primary "(" call_arguement_list ")"
#line 789 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2473 "./parser.cpp"
    break;

  case 190: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 790 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2480 "./parser.cpp"
    break;

  case 191: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 792 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2487 "./parser.cpp"
    break;

  case 192: // function_call: primary "(" keyword_items comma_opt ")"
#line 794 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2493 "./parser.cpp"
    break;

  case 193: // function_call: function_call "(" call_arguement_list ")"
#line 795 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2499 "./parser.cpp"
    break;

  case 194: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 796 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2506 "./parser.cpp"
    break;

  case 195: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 798 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2513 "./parser.cpp"
    break;

  case 196: // function_call: function_call "(" keyword_items comma_opt ")"
#line 800 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2519 "./parser.cpp"
    break;

  case 197: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 807 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2525 "./parser.cpp"
    break;

  case 198: // expr: id
#line 811 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2531 "./parser.cpp"
    break;

  case 199: // expr: integer_literal
#line 812 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2540 "./parser.cpp"
    break;

  case 200: // expr: string
#line 816 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2546 "./parser.cpp"
    break;

  case 201: // expr: real_literal
#line 817 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2552 "./parser.cpp"
    break;

  case 202: // expr: image_literal
#line 818 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2561 "./parser.cpp"
    break;

  case 203: // expr: TRUE
#line 822 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2567 "./parser.cpp"
    break;

  case 204: // expr: FALSE
#line 823 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2573 "./parser.cpp"
    break;

  case 205: // expr: NONE
#line 824 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2579 "./parser.cpp"
    break;

  case 206: // expr: "..."
#line 825 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2585 "./parser.cpp"
    break;

  case 207: // expr: "(" expr ")"
#line 826 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2591 "./parser.cpp"
    break;

  case 208: // expr: "(" ")"
#line 827 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2597 "./parser.cpp"
    break;

  case 209: // expr: function_call
#line 828 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2603 "./parser.cpp"
    break;

  case 210: // expr: "[" expr_list_opt "]"
#line 830 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2609 "./parser.cpp"
    break;

  case 211: // expr: "[" expr_list "," "]"
#line 831 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2615 "./parser.cpp"
    break;

  case 212: // expr: "{" expr_list "}"
#line 832 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2621 "./parser.cpp"
    break;

  case 213: // expr: "{" expr_list "," "}"
#line 833 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2627 "./parser.cpp"
    break;

  case 214: // expr: expr "." id
#line 834 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2633 "./parser.cpp"
    break;

  case 215: // expr: "{" "}"
#line 836 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2639 "./parser.cpp"
    break;

  case 216: // expr: "{" dict_list "}"
#line 837 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2645 "./parser.cpp"
    break;

  case 217: // expr: id ":=" expr
#line 841 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2651 "./parser.cpp"
    break;

  case 218: // expr: "*" expr
#line 842 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2657 "./parser.cpp"
    break;

  case 219: // expr: expr "+" expr
#line 844 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2663 "./parser.cpp"
    break;

  case 220: // expr: expr "-" expr
#line 845 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2669 "./parser.cpp"
    break;

  case 221: // expr: expr "*" expr
#line 846 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2675 "./parser.cpp"
    break;

  case 222: // expr: expr "/" expr
#line 847 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2681 "./parser.cpp"
    break;

  case 223: // expr: expr "%" expr
#line 848 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2687 "./parser.cpp"
    break;

  case 224: // expr: "-" expr
#line 849 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2693 "./parser.cpp"
    break;

  case 225: // expr: "+" expr
#line 850 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2699 "./parser.cpp"
    break;

  case 226: // expr: "~" expr
#line 851 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2705 "./parser.cpp"
    break;

  case 227: // expr: expr "**" expr
#line 852 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2711 "./parser.cpp"
    break;

  case 228: // expr: expr "//" expr
#line 853 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2717 "./parser.cpp"
    break;

  case 229: // expr: expr "@" expr
#line 854 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2723 "./parser.cpp"
    break;

  case 230: // expr: expr "&" expr
#line 856 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2729 "./parser.cpp"
    break;

  case 231: // expr: expr "|" expr
#line 857 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2735 "./parser.cpp"
    break;

  case 232: // expr: expr "^" expr
#line 858 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2741 "./parser.cpp"
    break;

  case 233: // expr: expr "<<" expr
#line 859 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2747 "./parser.cpp"
    break;

  case 234: // expr: expr ">>" expr
#line 860 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2753 "./parser.cpp"
    break;

  case 235: // expr: expr "==" expr
#line 862 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2759 "./parser.cpp"
    break;

  case 236: // expr: expr "!=" expr
#line 863 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2765 "./parser.cpp"
    break;

  case 237: // expr: expr "<" expr
#line 864 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2771 "./parser.cpp"
    break;

  case 238: // expr: expr "<=" expr
#line 865 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2777 "./parser.cpp"
    break;

  case 239: // expr: expr ">" expr
#line 866 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2783 "./parser.cpp"
    break;

  case 240: // expr: expr ">=" expr
#line 867 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2789 "./parser.cpp"
    break;

  case 241: // expr: expr "is" expr
#line 868 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2795 "./parser.cpp"
    break;

  case 242: // expr: expr "is not" expr
#line 869 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2801 "./parser.cpp"
    break;

  case 243: // expr: expr "in" expr
#line 870 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2807 "./parser.cpp"
    break;

  case 244: // expr: expr "not in" expr
#line 871 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2813 "./parser.cpp"
    break;

  case 245: // expr: expr "and" expr
#line 873 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2819 "./parser.cpp"
    break;

  case 246: // expr: expr "or" expr
#line 874 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2825 "./parser.cpp"
    break;

  case 247: // expr: "not" expr
#line 875 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2831 "./parser.cpp"
    break;

  case 248: // expr: "[" expr comp_for_items "]"
#line 878 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = LIST_COMP_1(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 2837 "./parser.cpp"
    break;

  case 249: // expr: "{" expr comp_for_items "}"
#line 879 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = SET_COMP_1(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 2843 "./parser.cpp"
    break;

  case 250: // expr: "{" expr ":" expr comp_for_items "}"
#line 880 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Expression*> > () = DICT_COMP_1(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 2849 "./parser.cpp"
    break;

  case 251: // expr: ternary_if_statement
#line 882 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2855 "./parser.cpp"
    break;

  case 252: // expr: lambda_expression
#line 883 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2861 "./parser.cpp"
    break;

  case 253: // lambda_id_list: lambda_id_list "," id
#line 888 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 2867 "./parser.cpp"
    break;

  case 254: // lambda_id_list: id
#line 889 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc())); }
#line 2873 "./parser.cpp"
    break;

  case 255: // lambda_expression: LAMBDA ":" expr
#line 893 "parser.ypp"
                                   {
        yylhs.value.as < Nonnull<Expression*> > () = LAMBDA_01({}, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2880 "./parser.cpp"
    break;

  case 256: // lambda_expression: LAMBDA lambda_id_list ":" expr
#line 895 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = LAMBDA_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2887 "./parser.cpp"
    break;

  case 257: // id_list: id_list "," id
#line 907 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 2893 "./parser.cpp"
    break;

  case 258: // id_list: id
#line 908 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 2899 "./parser.cpp"
    break;

  case 259: // id_item: id_list
#line 912 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2905 "./parser.cpp"
    break;

  case 260: // id_item: id_list ","
#line 913 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2911 "./parser.cpp"
    break;

  case 261: // id_item: "(" id ")"
#line 914 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Name*> > (); }
#line 2917 "./parser.cpp"
    break;

  case 262: // id_item: "(" id_list "," ")"
#line 915 "parser.ypp"
                          { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2923 "./parser.cpp"
    break;

  case 263: // id_item: "(" id_list "," id ")"
#line 916 "parser.ypp"
                              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Name*> > ()), context.source_loc()); }
#line 2929 "./parser.cpp"
    break;

  case 264: // comp_for: FOR id_item "in" expr
#line 920 "parser.ypp"
                          { yylhs.value.as < Nonnull<Comprehension*> > () = COMP_FOR_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2935 "./parser.cpp"
    break;

  case 265: // comp_for: FOR id_item "in" expr IF expr
#line 921 "parser.ypp"
                                  {
        yylhs.value.as < Nonnull<Comprehension*> > () = COMP_FOR_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2942 "./parser.cpp"
    break;

  case 266: // comp_for_items: comp_for_items comp_for
#line 926 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Comprehension*>> > () = yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > (), yystack_[0].value.as < Nonnull<Comprehension*> > ()); }
#line 2948 "./parser.cpp"
    break;

  case 267: // comp_for_items: comp_for
#line 927 "parser.ypp"
               { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > (), yystack_[0].value.as < Nonnull<Comprehension*> > ()); }
#line 2954 "./parser.cpp"
    break;

  case 268: // id: identifier
#line 931 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2960 "./parser.cpp"
    break;

  case 269: // sep: sep sep_one
#line 935 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2966 "./parser.cpp"
    break;

  case 270: // sep: sep_one
#line 936 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2972 "./parser.cpp"
    break;

  case 271: // sep_one: NEWLINE
#line 940 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2978 "./parser.cpp"
    break;

  case 272: // sep_one: COMMENT
#line 941 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2984 "./parser.cpp"
    break;

  case 273: // sep_one: ";"
#line 942 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2990 "./parser.cpp"
    break;


#line 2994 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -418;

  const short  Parser ::yytable_ninf_ = -189;

  const short
   Parser ::yypact_[] =
  {
     802,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  3022,
    3022,  -418,  -418,  3037,  3097,    47,  3022,  3022,    44,    59,
    3022,  3022,  -418,  3112,    -4,  3022,  3172,  2673,  2485,  3022,
    3022,  3022,  3022,  3022,  3022,  -418,  -418,  -418,  -418,  2443,
    -418,  -418,  -418,  -418,  -418,  -418,    -2,  -418,  -418,  -418,
    -418,  -418,   177,  -418,  -418,  -418,  -418,  -418,   177,   101,
      12,  -418,  -418,  -418,  -418,  -418,  -418,  3112,  -418,  -418,
      80,    68,    85,   133,   987,  -418,   162,   177,  -418,  2485,
    1282,  1346,  2485,   149,  2192,  2485,   192,   158,  2301,  -418,
     144,    32,  -418,   167,  1391,  -418,    72,  -418,   181,  3022,
      82,  -418,   167,  2873,  -418,   177,  1455,  2485,  -418,   213,
    1500,  -418,   146,  -418,   160,  1126,  -418,   203,  1564,   183,
     222,  1628,   116,   116,   116,  1053,   116,  -418,  -418,  -418,
     177,   177,   284,   284,  3022,   226,  -418,   291,  3022,  2947,
    2947,  3022,  3022,  3022,  3022,  3022,  3022,  3022,  3022,  3022,
    3022,  3022,  3022,   284,  3022,  3022,  3022,  3022,  3022,  3022,
    3022,  3022,  3022,  3022,  3022,  3022,  3022,  3022,  -418,  -418,
    -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,  -418,
    3022,  3022,  -418,  3022,  -418,  1564,  3022,  3022,   241,  3022,
     249,  1564,  3112,  3022,    18,   284,    53,  -418,   161,  3022,
     875,   284,    44,  2192,  3022,   284,   132,   177,   251,  1171,
     177,  3022,  3022,  2714,  -418,  3022,  -418,    61,  3022,  -418,
      45,  2521,   247,  -418,   566,    63,   177,     7,   248,  1053,
    -418,  -418,  2192,  3022,  -418,   257,   232,  -418,   260,    81,
     261,   236,   263,  2873,  1692,   314,   314,   314,   314,  2364,
     421,   186,  1737,   314,   206,   259,   206,   116,   116,   116,
     116,   116,   645,   526,   526,   314,   314,   314,   314,   116,
     314,  2192,  2192,  2192,  2192,  2561,  2597,   266,  2301,    44,
     181,  -418,    44,   181,    67,  -418,   154,  -418,   142,  2856,
     208,   132,  -418,  -418,  2192,  -418,  2788,   258,   132,  2637,
     132,  -418,  2192,  -418,  -418,  1801,   284,   268,   285,  -418,
    1628,  -418,  -418,  -418,  1846,  3022,  -418,  -418,   177,  2947,
      15,   177,  2192,  2947,  -418,  2947,   243,  3022,  2947,  -418,
    2947,   244,  3022,  3022,  -418,  1910,  -418,  1974,   177,   271,
     271,    44,   181,  3022,   274,  -418,  -418,   228,   252,   187,
    -418,   233,  -418,   948,  -418,  2962,   275,  -418,   234,   309,
     287,  -418,  3022,   288,   269,   284,  3022,    52,  -418,   292,
     270,   132,   272,   297,    -3,    20,   284,  -418,  -418,  -418,
     299,  -418,   276,    13,   303,   312,  -418,  -418,  2192,   303,
     312,  -418,   549,  2192,  -418,  -418,   132,    44,   290,   293,
     271,  2038,   875,  -418,   196,  -418,   267,  -418,  -418,  -418,
     177,  1237,   177,   320,   332,  -418,   338,   177,  2192,    14,
    -418,  -418,  2256,  -418,  3022,  -418,  -418,   339,  2947,  2947,
     340,    19,   341,   342,    49,  -418,    90,  3022,  3022,    31,
     317,  3022,   319,   321,   322,   318,  -418,  -418,   323,   177,
    -418,  -418,   132,   284,   177,   132,   177,   177,   177,   132,
    -418,   325,  3022,   177,   148,   176,   177,   284,   346,    34,
    -418,  -418,  -418,   354,  -418,  -418,   875,  3022,  2083,  2192,
     353,  -418,  -418,  -418,  -418,   358,  -418,   132,  -418,   359,
     132,  -418,   132,   132,   132,  -418,  -418,  1692,   132,    31,
     360,   362,   132,   342,    37,  -418,   284,   365,    15,  -418,
    -418,  2147,  3022,   177,   273,   177,  -418,   392,  -418,  -418,
    -418,   177,   177,  -418,  -418,   284,   342,    40,  -418,  -418,
     368,   875,  2192,   132,   373,  -418,   132,   376,   132,   132,
     342,  -418,   284,    15,  -418,  -418,   177,  -418,   177,  -418,
    -418,  -418,   342,   132,   132,  -418,  -418,  -418
  };

  const short
   Parser ::yydefact_[] =
  {
     120,   199,   201,   202,   268,   168,   204,   203,   205,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    41,     0,     0,     0,     0,     0,   172,
       0,     0,     0,     0,     0,   206,   273,   271,   272,   120,
       3,     5,    67,    71,    72,    63,     0,    70,    69,    68,
      65,    66,     0,    73,   118,   113,   114,   115,    23,     0,
     119,   116,   117,    74,   251,    75,   112,     0,    64,    62,
     200,    30,     0,   209,   166,   252,   198,     4,   270,     0,
      28,    39,     0,    43,   174,     0,     0,    34,   176,    84,
       0,     0,    77,   154,     0,    80,    78,    82,    85,     0,
       0,   254,   156,   247,    42,     0,     0,     0,   109,     0,
     106,   215,     0,   179,     0,   174,   208,     0,   174,     0,
     171,   174,   224,   225,   218,     0,   226,     1,     2,   164,
      22,    24,     0,     0,     0,   165,   167,     0,    31,   172,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,   169,     0,   269,     0,     0,     0,     0,    44,
       0,   176,     0,    35,     0,     0,     0,    83,     0,     0,
       0,     0,     0,   255,     0,     0,     0,     0,     0,   106,
       0,     0,     0,     0,   212,     0,   216,     0,     0,   267,
       0,     0,   207,   210,     0,     0,   122,     0,     0,     0,
     163,   170,   173,     0,   180,   171,     0,   185,   146,   198,
     171,     0,   146,   245,     0,   243,   241,   242,   244,   246,
     230,   232,    60,   235,   220,   214,   219,   221,   227,   229,
     228,   223,   231,   233,   234,   237,   238,   239,   240,   222,
     236,    47,   217,    29,    40,     0,     0,     0,   175,     0,
      86,    76,     0,    88,     0,     9,   160,     8,     0,     0,
       0,     0,    79,    81,   256,   253,   120,     0,     0,     0,
       0,   108,   107,   213,   178,     0,     0,   259,     0,   258,
     177,   249,   266,    32,   173,   172,   211,   248,     0,   172,
     144,   121,   183,   181,   189,   145,     0,     0,   181,   193,
     145,     0,     0,     0,    45,   173,    36,   175,     0,   146,
     146,     0,    89,     0,     0,   162,    12,     0,    18,    21,
      14,     0,     7,   120,    11,     0,     0,   100,   101,    92,
       0,   110,     0,     0,   258,   260,     0,     0,    33,   171,
       0,     0,     0,   171,     0,     0,     0,   134,   143,   129,
     146,   132,     0,   123,   146,   146,   184,   192,   182,   146,
     146,   196,   155,    61,    46,    37,     0,   145,     0,     0,
     146,     0,     0,    13,    20,    15,     0,    17,     6,    10,
       0,     0,     0,     0,     0,    99,     0,     0,   177,     0,
     261,   257,   264,   250,   181,   197,   149,     0,     0,     0,
       0,     0,   146,   146,   145,   130,     0,     0,     0,   145,
       0,   145,     0,     0,     0,    94,    87,    90,     0,     0,
     161,    16,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   257,     0,     0,     0,     0,     0,     0,   146,   145,
     138,   145,   142,   146,   133,   131,     0,     0,   124,   125,
       0,   190,   191,   194,   195,     0,    91,     0,    96,     0,
       0,   105,     0,     0,     0,   111,   263,   265,     0,     0,
       0,     0,     0,   146,   145,   135,     0,   146,   145,   127,
     147,     0,     0,     0,   157,     0,    97,   102,   103,    93,
     150,     0,     0,   153,   136,     0,   146,   145,   139,   128,
     146,     0,   126,     0,     0,   159,     0,     0,     0,     0,
     146,   140,     0,   145,   148,    95,     0,    98,     0,   151,
     152,   137,   146,     0,     0,   141,   158,   104
  };

  const short
   Parser ::yypgoto_[] =
  {
    -418,  -418,   388,   265,  -418,  -360,  -418,  -418,  -418,  -418,
    -249,  -418,  -418,  -418,  -418,   -18,  -418,  -418,  -418,  -418,
    -418,  -418,  -418,  -194,    -8,  -201,  -186,  -418,  -418,  -418,
    -418,    70,  -418,  -418,  -197,   324,  -418,  -418,  -418,  -418,
    -262,  -418,   -79,  -409,  -417,  -418,     1,  -418,  -418,  -418,
    -418,  -418,   -82,  -418,  -418,  -418,  -418,  -418,   -26,    41,
     350,   223,  -418,  -131,  -312,  -125,  -418,  -418,     2,  -418,
    -418,   131,  -418,  -181,  -117,   219,     0,   197
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    39,    40,   297,   285,   286,   353,   287,   288,   289,
      41,    42,    43,    44,    45,    46,    86,    47,    48,    49,
      50,   181,    51,    52,    96,    97,    98,    91,    53,    54,
      55,   357,   358,    56,   108,   109,    57,    58,    59,    60,
     377,   378,   379,   380,   381,   382,   435,    61,    62,    63,
      64,    65,   345,    66,    67,    68,    69,    70,   234,    71,
      87,   113,   114,   236,   237,   238,    72,    73,    84,   100,
      75,   307,   308,   219,   220,    76,   291,    78
  };

  const short
   Parser ::yytable_[] =
  {
      77,   293,    74,   119,   225,   104,   290,    90,   280,   241,
     283,    80,    81,   386,   301,   242,    88,   475,   386,    94,
       4,     4,   468,   103,     4,     4,     4,   106,   110,   115,
     118,   121,   122,   123,   124,   125,   126,     4,     4,   312,
       4,    74,   450,     4,   312,   105,     4,   354,   429,   135,
       4,   129,   130,     4,    83,     4,   318,    93,   131,     4,
     507,   102,   437,   196,   319,     4,   438,     4,   112,   117,
     120,   431,   217,     4,   430,   279,   134,   375,   376,   217,
      95,   185,   467,   198,   118,   201,     4,   191,   136,   182,
     217,   460,   197,   339,   233,   348,   340,   506,   342,   530,
     525,   203,   301,   542,   409,   206,    95,    89,    99,   209,
     282,   375,   376,   432,   433,    95,   510,   386,   306,   138,
     132,   311,   133,   188,   341,   226,   475,   386,   423,    95,
     473,   204,   195,   205,   327,   183,   229,  -187,  -186,   476,
     232,   317,   139,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   400,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     182,   544,   474,   477,   277,   194,   153,   343,   344,   156,
     235,   240,   270,   271,   370,   272,   312,   386,   273,   274,
     140,   232,   284,   367,   374,   278,   293,   213,   384,   499,
     189,   232,    74,   389,   195,   503,   294,   298,   290,   193,
     300,   215,    36,   110,   302,   232,   183,   305,   199,  -186,
     310,   195,   214,   314,   192,   500,   232,   199,   296,   321,
      37,    38,   202,   148,    92,   322,   216,    92,   101,   326,
     346,   347,   474,   331,   526,   152,   153,   154,   155,   156,
     157,   158,   159,   501,   221,   161,   162,    36,   413,   355,
     414,   223,   210,   540,   211,   474,   153,   167,   155,   156,
     157,   158,   159,   224,   184,    37,    38,   335,   337,   230,
     552,   474,   290,   355,   356,   405,   406,   167,   349,   137,
       4,    74,   275,   372,   -19,   -19,   343,   534,    74,   231,
     276,   110,   299,   464,   315,   320,   350,   351,   323,   324,
      92,   325,   328,   329,   330,   338,  -188,   366,   371,   365,
     387,   391,   397,   402,   412,   232,   403,   184,   184,   388,
     232,   407,   404,   416,   392,   393,   417,   290,   396,   419,
     398,   399,   485,   424,   142,   401,   420,   425,   428,   427,
     434,   227,   228,   436,   439,    74,   369,   411,   239,   239,
     373,   148,   149,   441,   418,   451,   385,   446,   422,   456,
     447,   390,   255,   152,   153,   154,   155,   156,   157,   158,
     159,   457,   160,   161,   162,   440,   442,   458,   463,   466,
     443,   444,   469,   471,   481,   167,   482,   504,   483,   484,
     486,   448,   496,   184,    74,   508,   327,   513,   515,   521,
     452,   522,   455,    92,   281,    92,   527,   459,   537,   543,
     292,    92,   546,   184,   295,   548,   232,   128,   415,   529,
     232,   208,   535,   470,   472,   190,   309,   363,   304,   478,
     479,     0,     0,   232,     0,     0,     0,     0,     0,   487,
       0,     0,     0,     0,   490,     0,   492,   493,   494,     0,
       0,     0,     0,   498,   497,     0,   502,     0,     0,   505,
     465,     0,     0,     0,   509,     0,     0,     0,    74,   511,
     152,   153,   154,   155,   156,   157,   158,   159,   184,     0,
     161,   162,     0,     0,     0,   184,     0,   184,    92,     0,
       0,    92,   167,    92,   524,     0,     0,     0,   528,     0,
       0,     0,     0,   533,   532,   536,     0,     0,   184,     0,
       0,   538,   539,     0,     0,   364,     0,   541,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,   239,   383,
       0,   551,   239,     0,   239,     0,   553,   239,   554,   239,
       0,     0,     0,   555,     0,     0,   352,     0,     0,     0,
      92,     0,     0,   359,     0,   361,     0,     0,   184,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,   421,   152,   153,   154,   155,   156,
     157,   158,   159,   184,   383,   383,   148,   149,     0,     0,
       0,     0,    19,     0,    21,     0,     0,   167,   152,   153,
     154,   155,   156,   157,   158,   159,    92,   160,   161,   162,
       0,     0,    27,    79,    29,    30,     0,    31,    32,     0,
     167,     0,     0,    34,     0,     0,   426,     0,   461,     0,
       0,    35,     0,     0,   316,     0,     0,   239,   239,   184,
     383,     0,   184,   383,     0,     0,   184,     0,   480,     0,
       0,   445,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   184,     0,   383,   184,   383,   184,
     184,   184,   148,   149,     0,   184,     0,     0,     0,   184,
       0,     0,     0,     0,   152,   153,   154,   155,   156,   157,
     158,   159,     0,     0,   161,   162,     0,   488,   480,     0,
     491,     0,     0,   383,   495,   383,   167,   383,     0,     0,
     184,     0,     0,   184,     0,   184,   184,     0,     0,     0,
       0,     0,     0,     0,   383,     0,   383,     0,     0,     0,
     184,   184,   514,     0,     0,   516,     0,   517,   518,   519,
       0,   383,   383,   520,     0,     0,     0,   523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   545,     0,
       0,   547,     0,   549,   550,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     9,    10,   556,   557,
      11,     0,    12,     0,    13,     0,     0,     0,     0,    14,
      15,    16,    17,    18,     0,     0,     0,     0,    19,    20,
      21,     0,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,    30,     0,    31,    32,     0,    33,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    35,     1,     2,
       3,     4,    36,     5,     6,     7,     8,     0,     0,     9,
      10,     0,     0,    11,     0,    12,     0,    13,     0,     0,
      37,    38,     0,    15,    16,     0,    18,     0,     0,     0,
       0,    19,    20,    21,     0,    22,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,    29,    30,     0,    31,    32,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      35,     1,     2,     3,     4,    36,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,     0,     0,    37,    38,    14,    15,    16,    17,    18,
       0,     0,     0,     0,    19,    20,    21,     0,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,    27,    28,    29,    30,     0,    31,
      32,     0,    33,     0,     0,    34,     0,   142,     0,   143,
     144,   145,   146,    35,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,     0,  -174,     0,
    -174,     0,   151,     0,     0,   408,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,     0,     0,     0,   141,     0,     0,   167,     0,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   142,     0,   143,   144,   145,   146,   180,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,   151,     0,
       0,     0,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,     0,     0,
       0,     0,     0,    36,   167,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,   217,     0,   180,   142,     0,   143,   144,
     145,   146,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   218,     0,     0,     0,     0,
       0,   151,     0,   141,   212,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   142,     0,   143,   144,   145,   146,   167,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,     0,   151,     0,   180,     0,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,     0,     0,   222,   141,
     453,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,   143,
     144,   145,   146,   180,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   454,     0,     0,     0,
       0,     0,   151,     0,   141,     0,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   142,     0,   143,   144,   145,   146,   167,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,   186,     0,     0,     0,   151,     0,   180,
       0,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,     0,   141,     0,
       0,     0,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,   142,     0,   143,   144,
     145,   146,     0,     0,   180,   147,     0,     0,     0,     0,
       0,     0,     0,   148,   149,     0,     0,     0,     0,     0,
       0,   151,     0,   141,     0,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   142,     0,   143,   144,   145,   146,   167,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     200,     0,     0,     0,     0,     0,   151,     0,   180,     0,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,     0,   141,     0,     0,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,   143,   144,   145,
     146,     0,     0,   180,   147,     0,     0,     0,     0,     0,
       0,     0,   148,   149,   207,     0,     0,     0,     0,     0,
     151,     0,   141,   212,   152,   153,   154,   155,   156,   157,
     158,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     142,     0,   143,   144,   145,   146,   167,     0,     0,   147,
       0,     0,     0,     0,     0,     0,     0,   148,   149,     0,
       0,     0,     0,     0,     0,   151,     0,   180,     0,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,   164,   165,   166,     0,   141,     0,     0,     0,
       0,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,   143,   144,   145,   146,
       0,     0,   180,   147,     0,     0,     0,     0,     0,     0,
       0,   148,   149,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,     0,
     141,   222,     0,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,     0,     0,   142,     0,
     143,   144,   145,   146,     0,     0,   180,   147,     0,     0,
       0,     0,     0,     0,     0,   148,   149,     0,     0,     0,
       0,     0,     0,   151,     0,     0,     0,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,     0,   141,     0,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,   332,     0,     0,     0,
       0,     0,   142,     0,   143,   144,   145,   146,     0,     0,
     180,   147,     0,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,     0,     0,     0,     0,   151,     0,   141,
       0,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   142,     0,   143,
     144,   145,   146,   167,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,     0,     0,     0,     0,
     333,     0,   151,     0,   180,     0,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,     0,   141,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,   143,   144,   145,   146,     0,     0,   180,
     147,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     362,     0,     0,     0,     0,     0,   151,     0,   141,     0,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   142,     0,   143,   144,
     145,   146,   167,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   148,   149,     0,     0,     0,     0,     0,
       0,   151,     0,   180,     0,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,   164,   165,
     166,     0,   141,   368,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,   143,   144,   145,   146,     0,     0,   180,   147,
       0,     0,     0,     0,     0,     0,     0,   148,   149,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   159,     0,   160,   161,
     162,   163,   164,   165,   166,     0,   141,   394,     0,     0,
       0,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,   143,   144,   145,   146,
       0,     0,   180,   147,     0,     0,     0,     0,     0,     0,
       0,   148,   149,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,     0,
     141,   395,     0,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,     0,
     143,   144,   145,   146,     0,     0,   180,   147,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   449,     0,     0,
       0,     0,     0,   151,     0,   141,     0,   152,   153,   154,
     155,   156,   157,   158,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   142,     0,   143,   144,   145,   146,   167,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,   512,     0,   151,     0,
     180,     0,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,     0,   141,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,   143,
     144,   145,   146,     0,     0,   180,   147,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   531,     0,     0,     0,
       0,     0,   151,     0,   141,     0,   152,   153,   154,   155,
     156,   157,   158,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   142,     0,   143,   144,   145,   146,   167,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,     0,     0,     0,     0,   151,     0,   180,
       0,   152,   153,   154,   155,   156,   157,   158,   159,     0,
     160,   161,   162,   163,   164,   165,   166,     0,   141,     0,
       0,     0,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   462,     0,   143,   144,
     145,   146,     0,     0,   180,   147,     0,     0,     0,     0,
       0,     0,     0,   148,   149,     0,     0,     0,     0,     0,
       0,   151,     0,   141,     0,   152,   153,   154,   155,   156,
     157,   158,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   142,     0,     0,   144,   145,   146,   167,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,     0,   151,     0,   180,     0,
     152,   153,   154,   155,   156,   157,   158,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   141,     0,     0,     0,
       0,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,   143,   144,   145,   146,
       0,     0,     0,   180,     0,     0,     0,     0,     0,     0,
       0,   148,   149,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   152,   153,   154,   155,   156,   157,   158,
     159,     0,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,   127,     0,   167,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     9,    10,     0,
       0,    11,     0,    12,     0,    13,   180,     0,     0,     0,
      14,    15,    16,    17,    18,     0,     0,     0,     0,    19,
      20,    21,     0,    22,    23,    24,    25,    26,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,    27,
      28,    29,    30,     0,    31,    32,     0,    33,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,    19,     0,    21,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    79,    29,    30,     0,    31,    32,     0,     0,
       0,     0,    34,     0,     0,     0,     0,    19,     0,    21,
      35,     0,   116,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,    27,    79,    29,
      30,     0,    31,    32,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,    35,    19,   313,    21,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    79,    29,
      30,     0,    31,    32,     0,     0,     0,     0,    34,     0,
       0,     0,     0,    19,     0,    21,    35,     0,   334,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,    27,    79,    29,    30,     0,    31,    32,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    35,    19,   336,    21,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    79,    29,    30,     0,    31,    32,
       0,     0,     0,     0,    34,     0,     0,     0,     0,    19,
       0,    21,    35,     0,   360,     0,     0,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,    27,
      79,    29,    30,     0,    31,    32,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    35,   111,
      19,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    79,    29,    30,     0,    31,    32,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,    35,
     303,     1,     2,     3,     4,     0,     5,     6,     7,     8,
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
       0,     0,     0,   142,     0,   143,   144,   145,   146,     0,
       0,     0,    27,    28,    29,    30,     0,    31,    32,     0,
     148,   149,     0,    34,     0,     0,     0,     0,   151,     0,
       0,    35,   152,   153,   154,   155,   156,   157,   158,   159,
       0,   160,   161,   162,   163,   164,   165,   166,     0,     0,
       1,     2,     3,     4,   167,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,   180,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,    27,    79,    29,    30,     0,    31,    32,
     233,   410,     0,     0,    34,     0,     0,     0,    27,    79,
      29,    30,    35,    31,    32,     1,     2,     3,     4,    34,
       5,     6,     7,     8,     0,     0,     0,    35,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,    27,    79,
      29,    30,     0,    31,    32,     0,     0,     0,     0,    34,
       0,     0,     0,    27,    82,    29,    30,    35,    31,    32,
       1,     2,     3,     4,    34,     5,     6,     7,     8,     0,
       0,     0,    35,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,    27,    85,    29,    30,     0,    31,    32,
       0,     0,     0,     0,    34,     0,     0,     0,    27,    28,
      29,    30,    35,    31,    32,     1,     2,     3,     4,    34,
       5,     6,     7,     8,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,   107,
      29,    30,     0,    31,    32,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    35
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   202,     0,    29,   121,    23,   200,    15,   194,   140,
     196,     9,    10,   325,   211,   140,    14,   434,   330,    17,
       6,     6,   431,    21,     6,     6,     6,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     6,     6,   220,
       6,    39,   402,     6,   225,    49,     6,   296,    51,    67,
       6,    53,    52,     6,    13,     6,    49,    16,    58,     6,
     469,    20,    49,    31,    57,     6,    53,     6,    27,    28,
      29,    51,    27,     6,    77,    57,    64,    62,    63,    27,
      62,    79,    63,    91,    82,    13,     6,    85,     8,     8,
      27,    77,    60,   279,    63,   289,   282,    63,   284,   508,
      63,    99,   299,    63,   353,   105,    62,    60,    49,   107,
      57,    62,    63,   375,   376,    62,   476,   429,    57,    51,
      19,    76,    21,    82,    57,   125,   543,   439,    76,    62,
      81,    49,    60,    51,    53,    54,   134,    57,    57,    49,
     138,    78,    57,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   341,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       8,   531,   434,    83,   192,    31,    60,    23,    24,    63,
     139,   140,   180,   181,   315,   183,   367,   499,   186,   187,
      57,   189,    31,   310,   319,   193,   397,    51,   323,    51,
      51,   199,   200,   328,    60,   467,   204,   207,   402,    51,
     210,    51,    80,   211,   212,   213,    54,   215,    51,    57,
     218,    60,    76,   221,    32,    77,   224,    51,    96,   229,
      98,    99,    51,    47,    15,   233,    76,    18,    19,   238,
      98,    99,   504,   242,   506,    59,    60,    61,    62,    63,
      64,    65,    66,    77,    51,    69,    70,    80,    24,    25,
      26,    78,    49,   525,    51,   527,    60,    81,    62,    63,
      64,    65,    66,    51,    77,    98,    99,   275,   276,    53,
     542,   543,   476,    25,    26,    98,    99,    81,    80,    70,
       6,   289,    51,   319,    98,    99,    23,    24,   296,     8,
      51,   299,    51,   428,    57,    57,    98,    99,    51,    77,
      91,    51,    51,    77,    51,    49,    57,    32,   318,    51,
      77,    77,    51,    49,    49,   323,    98,   130,   131,   327,
     328,    98,    80,    24,   332,   333,    49,   531,   338,    51,
     339,   340,    24,    51,    30,   343,    77,    77,    51,    77,
      51,   132,   133,    77,    51,   353,   315,   355,   139,   140,
     319,    47,    48,    51,   362,    98,   325,    77,   366,    49,
      77,   330,   153,    59,    60,    61,    62,    63,    64,    65,
      66,    49,    68,    69,    70,   384,   385,    49,    49,    49,
     389,   390,    51,    51,    77,    81,    77,    51,    77,    77,
      77,   400,    77,   206,   402,    51,    53,    49,    49,    49,
     410,    49,   412,   194,   195,   196,    51,   417,    26,    51,
     201,   202,    49,   226,   205,    49,   424,    39,   358,   508,
     428,   107,   514,   432,   433,    85,   217,   306,   215,   437,
     438,    -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,   449,
      -1,    -1,    -1,    -1,   454,    -1,   456,   457,   458,    -1,
      -1,    -1,    -1,   463,   462,    -1,   466,    -1,    -1,   468,
     429,    -1,    -1,    -1,   473,    -1,    -1,    -1,   476,   477,
      59,    60,    61,    62,    63,    64,    65,    66,   291,    -1,
      69,    70,    -1,    -1,    -1,   298,    -1,   300,   279,    -1,
      -1,   282,    81,   284,   503,    -1,    -1,    -1,   507,    -1,
      -1,    -1,    -1,   513,   512,   515,    -1,    -1,   321,    -1,
      -1,   521,   522,    -1,    -1,   306,    -1,   526,    -1,    -1,
      -1,    -1,    -1,   531,    -1,    -1,    -1,    -1,   319,   320,
      -1,   540,   323,    -1,   325,    -1,   546,   328,   548,   330,
      -1,    -1,    -1,   552,    -1,    -1,   291,    -1,    -1,    -1,
     341,    -1,    -1,   298,    -1,   300,    -1,    -1,   371,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,   365,    59,    60,    61,    62,    63,
      64,    65,    66,   396,   375,   376,    47,    48,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    -1,    81,    59,    60,
      61,    62,    63,    64,    65,    66,   397,    68,    69,    70,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      81,    -1,    -1,    67,    -1,    -1,   371,    -1,   419,    -1,
      -1,    75,    -1,    -1,    78,    -1,    -1,   428,   429,   452,
     431,    -1,   455,   434,    -1,    -1,   459,    -1,   439,    -1,
      -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   487,    -1,   467,   490,   469,   492,
     493,   494,    47,    48,    -1,   498,    -1,    -1,    -1,   502,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,    -1,   452,   499,    -1,
     455,    -1,    -1,   504,   459,   506,    81,   508,    -1,    -1,
     533,    -1,    -1,   536,    -1,   538,   539,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   525,    -1,   527,    -1,    -1,    -1,
     553,   554,   487,    -1,    -1,   490,    -1,   492,   493,   494,
      -1,   542,   543,   498,    -1,    -1,    -1,   502,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,    -1,
      -1,   536,    -1,   538,   539,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    14,    15,   553,   554,
      18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,     3,     4,
       5,     6,    80,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      98,    99,    -1,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,     3,     4,     5,     6,    80,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    98,    99,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    64,    -1,    -1,    67,    -1,    30,    -1,    32,
      33,    34,    35,    75,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    51,    -1,
      53,    -1,    55,    -1,    -1,    97,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    12,    -1,    -1,    81,    -1,
      -1,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    30,    -1,    32,    33,    34,    35,   102,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,    27,    -1,   102,    30,    -1,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    13,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,   102,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    12,
      13,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,   102,    -1,    -1,    39,    -1,    -1,    -1,
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
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      12,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    12,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      12,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    30,    -1,    32,    33,    34,    35,    81,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
     102,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    12,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,   102,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    12,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    -1,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,   102,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    12,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,     0,    -1,    81,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    -1,    22,   102,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    36,    -1,    38,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    36,    -1,    38,
      75,    -1,    77,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    36,    77,    38,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    36,    -1,    38,    75,    -1,    77,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    36,    77,    38,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    36,
      -1,    38,    75,    -1,    77,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
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
      58,    59,    75,    61,    62,     3,     4,     5,     6,    67,
       8,     9,    10,    11,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
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
     161,   163,   170,   171,   172,   174,   179,   180,   181,    57,
     172,   172,    57,   163,   172,    57,   120,   164,   172,    60,
     128,   131,   179,   163,   172,    62,   128,   129,   130,    49,
     173,   179,   163,   172,   119,    49,   172,    57,   138,   139,
     172,    76,   163,   165,   166,   172,    77,   163,   172,   162,
     163,   172,   172,   172,   172,   172,   172,     0,   106,    53,
     180,   180,    19,    21,    64,   119,     8,   179,    51,    57,
      57,    12,    30,    32,    33,    34,    35,    39,    47,    48,
      49,    55,    59,    60,    61,    62,    63,    64,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    81,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     102,   125,     8,    54,   181,   172,    51,    28,   163,    51,
     164,   172,    32,    51,    31,    60,    31,    60,   128,    51,
      49,    13,    51,   172,    49,    51,   180,    49,   139,   172,
      49,    51,    13,    51,    76,    51,    76,    27,    49,   177,
     178,    51,    77,    78,    51,   178,   180,   179,   179,   172,
      53,     8,   172,    63,   162,   163,   167,   168,   169,   179,
     163,   167,   169,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   179,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,    51,    51,   119,   172,    57,
     130,   179,    57,   130,    31,   108,   109,   111,   112,   113,
     127,   180,   179,   129,   172,   179,    96,   107,   180,    51,
     180,   138,   172,    76,   165,   172,    57,   175,   176,   179,
     172,    76,   177,    77,   172,    57,    78,    78,    49,    57,
      57,   180,   172,    51,    77,    51,   150,    53,    51,    77,
      51,   150,    24,    53,    77,   172,    77,   172,    49,   130,
     130,    57,   130,    23,    24,   156,    98,    99,   127,    80,
      98,    99,   107,   110,   114,    25,    26,   135,   136,   107,
      77,   107,    49,   175,   179,    51,    32,   178,    77,   163,
     167,   180,   162,   163,   169,    62,    63,   144,   145,   146,
     147,   148,   149,   179,   169,   163,   168,    77,   172,   169,
     163,    77,   172,   172,    77,    77,   180,    51,   150,   150,
     130,   172,    49,    98,    80,    98,    99,    98,    97,   114,
      49,   172,    49,    24,    26,   135,    24,    49,   172,    51,
      77,   179,   172,    76,    51,    77,   107,    77,    51,    51,
      77,    51,   144,   144,    51,   150,    77,    49,    53,    51,
     150,    51,   150,   150,   150,   107,    77,    77,   150,    49,
     109,    98,   180,    13,    49,   180,    49,    49,    49,   180,
      77,   179,    30,    49,   169,   163,    49,    63,   147,    51,
     150,    51,   150,    81,   144,   148,    49,    83,   172,   172,
     179,    77,    77,    77,    77,    24,    77,   180,   107,   179,
     180,   107,   180,   180,   180,   107,    77,   172,   180,    51,
      77,    77,   180,   144,    51,   150,    63,   147,    51,   150,
     109,   172,    53,    49,   107,    49,   107,   107,   107,   107,
     107,    49,    49,   107,   150,    63,   144,    51,   150,   146,
     147,    49,   172,   180,    24,   156,   180,    26,   180,   180,
     144,   150,    63,    51,   109,   107,    49,   107,    49,   107,
     107,   150,   144,   180,   180,   150,   107,   107
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
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   174,   174,   175,   175,   176,
     176,   176,   176,   176,   177,   177,   178,   178,   179,   180,
     180,   181,   181,   181
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
       7,     7,     5,     4,     7,     7,     5,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     4,     3,     4,     3,     2,     3,     3,     2,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     4,     4,
       6,     1,     1,     3,     1,     3,     4,     3,     1,     1,
       2,     3,     4,     5,     4,     6,     2,     1,     1,     2,
       1,     1,     1,     1
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
  "keyword_item", "keyword_items", "primary", "function_call", "expr",
  "lambda_id_list", "lambda_expression", "id_list", "id_item", "comp_for",
  "comp_for_items", "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   308,   308,   309,   310,   314,   318,   322,   326,   327,
     331,   332,   336,   337,   338,   339,   342,   345,   351,   354,
     360,   363,   369,   370,   371,   376,   380,   384,   388,   389,
     393,   394,   395,   396,   400,   401,   402,   403,   407,   408,
     409,   413,   414,   419,   420,   421,   423,   429,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     448,   449,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   471,   472,   476,   477,
     478,   482,   483,   487,   488,   494,   495,   497,   499,   501,
     503,   505,   510,   511,   515,   517,   528,   529,   530,   533,
     534,   538,   539,   541,   543,   545,   549,   550,   554,   555,
     559,   560,   569,   570,   571,   572,   573,   574,   578,   582,
     583,   587,   588,   592,   593,   594,   595,   599,   601,   603,
     607,   608,   610,   614,   615,   623,   624,   625,   627,   628,
     630,   632,   634,   638,   639,   643,   644,   648,   650,   662,
     664,   666,   668,   670,   676,   680,   684,   688,   689,   691,
     696,   699,   702,   707,   708,   712,   717,   721,   722,   725,
     728,   734,   735,   739,   740,   753,   754,   758,   761,   762,
     766,   767,   772,   773,   777,   778,   783,   784,   785,   789,
     790,   792,   794,   795,   796,   798,   800,   807,   811,   812,
     816,   817,   818,   822,   823,   824,   825,   826,   827,   828,
     830,   831,   832,   833,   834,   836,   837,   841,   842,   844,
     845,   846,   847,   848,   849,   850,   851,   852,   853,   854,
     856,   857,   858,   859,   860,   862,   863,   864,   865,   866,
     867,   868,   869,   870,   871,   873,   874,   875,   878,   879,
     880,   882,   883,   888,   889,   893,   895,   907,   908,   912,
     913,   914,   915,   916,   920,   921,   926,   927,   931,   935,
     936,   940,   941,   942
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
#line 4237 "./parser.cpp"

#line 945 "parser.ypp"
