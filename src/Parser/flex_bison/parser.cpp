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
#line 301 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1259 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 302 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1265 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 307 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1271 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 311 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1277 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 315 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1283 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 319 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1289 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 320 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1295 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 324 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1301 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 325 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1307 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 329 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1313 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 330 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1319 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 331 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1325 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 332 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1333 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 335 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1341 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 338 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1349 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 344 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1357 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 347 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1365 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 353 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1373 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 356 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1381 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 362 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1387 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 363 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1393 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 364 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1399 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 369 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1405 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 373 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1411 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 377 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1417 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 381 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1423 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 382 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1429 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 386 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1435 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 387 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1441 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 388 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1447 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 389 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1453 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 393 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1459 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 394 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1465 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 395 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1471 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 396 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1477 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 400 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1483 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 401 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1489 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 402 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1495 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 406 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1501 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 407 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1507 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 412 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1513 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 413 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1519 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 414 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1526 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 416 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1533 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 422 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1539 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 426 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1545 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 427 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1551 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 428 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1557 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 429 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1563 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 430 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1569 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 431 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1575 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 432 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1581 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 433 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1587 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 434 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1593 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 435 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1599 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 436 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1605 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 437 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1611 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 441 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1617 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 442 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1623 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 446 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1629 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 447 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1635 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 448 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1641 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 449 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1647 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 450 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1653 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 451 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1659 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 452 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1665 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 453 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1671 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 454 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1677 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 455 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1683 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 456 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1689 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 457 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1695 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 458 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1701 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 459 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1707 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 464 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1713 "./parser.cpp"
    break;

  case 77: // module: id
#line 465 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1719 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 469 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1725 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 470 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1731 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 471 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1737 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 475 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1743 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 476 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1749 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 480 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1755 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 481 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1761 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 487 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1767 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 488 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1774 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 490 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1781 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 492 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1788 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 494 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1795 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 496 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1802 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 498 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1809 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 503 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1815 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 504 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1822 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 508 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1829 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 511 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1835 "./parser.cpp"
    break;

  case 96: // except_statement: EXCEPT ":" sep statements
#line 521 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_01(yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1841 "./parser.cpp"
    break;

  case 97: // except_statement: EXCEPT expr ":" sep statements
#line 522 "parser.ypp"
                                     { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_02(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1847 "./parser.cpp"
    break;

  case 98: // except_statement: EXCEPT expr AS id ":" sep statements
#line 523 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_03(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1853 "./parser.cpp"
    break;

  case 99: // except_list: except_list except_statement
#line 526 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1859 "./parser.cpp"
    break;

  case 100: // except_list: except_statement
#line 527 "parser.ypp"
                       { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1865 "./parser.cpp"
    break;

  case 101: // try_statement: TRY ":" sep statements except_list
#line 531 "parser.ypp"
                                         { yylhs.value.as < Nonnull<Statement*> > () = TRY_01(yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1871 "./parser.cpp"
    break;

  case 102: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements
#line 532 "parser.ypp"
                                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_02(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1878 "./parser.cpp"
    break;

  case 103: // try_statement: TRY ":" sep statements except_list FINALLY ":" sep statements
#line 534 "parser.ypp"
                                                                    {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_03(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1885 "./parser.cpp"
    break;

  case 104: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements FINALLY ":" sep statements
#line 537 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = TRY_04(yystack_[9].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[8].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1891 "./parser.cpp"
    break;

  case 105: // try_statement: TRY ":" sep statements FINALLY ":" sep statements
#line 538 "parser.ypp"
                                                        { yylhs.value.as < Nonnull<Statement*> > () = TRY_05(yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1897 "./parser.cpp"
    break;

  case 106: // with_item: expr
#line 542 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1903 "./parser.cpp"
    break;

  case 107: // with_item: expr AS expr
#line 543 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1909 "./parser.cpp"
    break;

  case 108: // with_item_list: with_item_list "," with_item
#line 547 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1915 "./parser.cpp"
    break;

  case 109: // with_item_list: with_item
#line 548 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1921 "./parser.cpp"
    break;

  case 110: // with_statement: WITH with_item_list ":" sep statements
#line 552 "parser.ypp"
                                             { yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1927 "./parser.cpp"
    break;

  case 111: // with_statement: WITH "(" with_item_list "," ")" ":" sep statements
#line 553 "parser.ypp"
                                                         {
        yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1934 "./parser.cpp"
    break;

  case 112: // multi_line_statement: if_statement
#line 562 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1940 "./parser.cpp"
    break;

  case 113: // multi_line_statement: for_statement
#line 563 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1946 "./parser.cpp"
    break;

  case 114: // multi_line_statement: try_statement
#line 564 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1952 "./parser.cpp"
    break;

  case 115: // multi_line_statement: with_statement
#line 565 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1958 "./parser.cpp"
    break;

  case 116: // multi_line_statement: function_def
#line 566 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1964 "./parser.cpp"
    break;

  case 117: // multi_line_statement: class_def
#line 567 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1970 "./parser.cpp"
    break;

  case 118: // multi_line_statement: while_statement
#line 571 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1976 "./parser.cpp"
    break;

  case 119: // decorators_opt: decorators
#line 575 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1982 "./parser.cpp"
    break;

  case 120: // decorators_opt: %empty
#line 576 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1988 "./parser.cpp"
    break;

  case 121: // decorators: decorators "@" expr sep
#line 580 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1994 "./parser.cpp"
    break;

  case 122: // decorators: "@" expr sep
#line 581 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2000 "./parser.cpp"
    break;

  case 123: // parameter: id
#line 585 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2006 "./parser.cpp"
    break;

  case 124: // parameter: id ":" expr
#line 586 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2012 "./parser.cpp"
    break;

  case 125: // parameter: id "=" expr
#line 587 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2018 "./parser.cpp"
    break;

  case 126: // parameter: id ":" expr "=" expr
#line 588 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2024 "./parser.cpp"
    break;

  case 127: // parameter_list: defparameter_list "," "/" comma_opt
#line 592 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2031 "./parser.cpp"
    break;

  case 128: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 594 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2038 "./parser.cpp"
    break;

  case 129: // parameter_list: parameter_list_no_posonly
#line 596 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2044 "./parser.cpp"
    break;

  case 130: // parameter_list_no_posonly: defparameter_list comma_opt
#line 600 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2050 "./parser.cpp"
    break;

  case 131: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 601 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2057 "./parser.cpp"
    break;

  case 132: // parameter_list_no_posonly: parameter_list_starargs
#line 603 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2063 "./parser.cpp"
    break;

  case 133: // defparameter_list: defparameter_list "," parameter
#line 607 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2069 "./parser.cpp"
    break;

  case 134: // defparameter_list: parameter
#line 608 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2075 "./parser.cpp"
    break;

  case 135: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 616 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2081 "./parser.cpp"
    break;

  case 136: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 617 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2087 "./parser.cpp"
    break;

  case 137: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 618 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2094 "./parser.cpp"
    break;

  case 138: // parameter_list_starargs: "*" parameter comma_opt
#line 620 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2100 "./parser.cpp"
    break;

  case 139: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 621 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2107 "./parser.cpp"
    break;

  case 140: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 623 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2114 "./parser.cpp"
    break;

  case 141: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 625 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2121 "./parser.cpp"
    break;

  case 142: // parameter_list_starargs: "**" parameter comma_opt
#line 627 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2127 "./parser.cpp"
    break;

  case 143: // parameter_list_opt: parameter_list
#line 631 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 2133 "./parser.cpp"
    break;

  case 144: // parameter_list_opt: %empty
#line 632 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 2139 "./parser.cpp"
    break;

  case 147: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 642 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2145 "./parser.cpp"
    break;

  case 148: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 644 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2151 "./parser.cpp"
    break;

  case 149: // class_def: decorators_opt CLASS id ":" sep statements
#line 655 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_01(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2158 "./parser.cpp"
    break;

  case 150: // class_def: decorators_opt CLASS id "(" expr_list_opt ")" ":" sep statements
#line 657 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_02(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2165 "./parser.cpp"
    break;

  case 151: // class_def: decorators_opt CLASS id "(" expr_list "," keyword_items ")" ":" sep statements
#line 660 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[6].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2171 "./parser.cpp"
    break;

  case 152: // class_def: decorators_opt CLASS id "(" keyword_items "," expr_list ")" ":" sep statements
#line 662 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2177 "./parser.cpp"
    break;

  case 153: // class_def: decorators_opt CLASS id "(" keyword_items ")" ":" sep statements
#line 663 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_04(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2184 "./parser.cpp"
    break;

  case 154: // global_statement: GLOBAL expr_list
#line 669 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2190 "./parser.cpp"
    break;

  case 155: // ternary_if_statement: expr IF expr ELSE expr
#line 673 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2196 "./parser.cpp"
    break;

  case 156: // nonlocal_statement: NONLOCAL expr_list
#line 677 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2202 "./parser.cpp"
    break;

  case 157: // elif_statement: ELIF expr ":" sep statements
#line 681 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2208 "./parser.cpp"
    break;

  case 158: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 682 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2215 "./parser.cpp"
    break;

  case 159: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 684 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2222 "./parser.cpp"
    break;

  case 160: // if_statement: IF expr ":" body_stmts
#line 689 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2230 "./parser.cpp"
    break;

  case 161: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 692 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2238 "./parser.cpp"
    break;

  case 162: // if_statement: IF expr ":" body_stmts elif_statement
#line 695 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2245 "./parser.cpp"
    break;

  case 163: // target_list: target_list tuple_item "="
#line 700 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2251 "./parser.cpp"
    break;

  case 164: // target_list: tuple_item "="
#line 701 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2257 "./parser.cpp"
    break;

  case 165: // assignment_statement: target_list tuple_item
#line 705 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2263 "./parser.cpp"
    break;

  case 166: // expression_statment: expr
#line 710 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2269 "./parser.cpp"
    break;

  case 167: // string: string string_literal
#line 714 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2275 "./parser.cpp"
    break;

  case 168: // string: string_literal
#line 715 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2283 "./parser.cpp"
    break;

  case 169: // string: id string_literal
#line 718 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2291 "./parser.cpp"
    break;

  case 170: // string: string id string_literal
#line 721 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2299 "./parser.cpp"
    break;

  case 171: // expr_list_opt: expr_list
#line 727 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2305 "./parser.cpp"
    break;

  case 172: // expr_list_opt: %empty
#line 728 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2311 "./parser.cpp"
    break;

  case 173: // expr_list: expr_list "," expr
#line 732 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2317 "./parser.cpp"
    break;

  case 174: // expr_list: expr
#line 733 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2323 "./parser.cpp"
    break;

  case 175: // expr_for_list: expr_for_list "," expr
#line 746 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2329 "./parser.cpp"
    break;

  case 176: // expr_for_list: expr
#line 747 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2335 "./parser.cpp"
    break;

  case 177: // dict: expr ":" expr
#line 751 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2341 "./parser.cpp"
    break;

  case 178: // dict_list: dict_list "," dict
#line 754 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2347 "./parser.cpp"
    break;

  case 179: // dict_list: dict
#line 755 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2353 "./parser.cpp"
    break;

  case 180: // call_arguement_list: expr_list_opt
#line 759 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2359 "./parser.cpp"
    break;

  case 181: // call_arguement_list: expr_list ","
#line 760 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2365 "./parser.cpp"
    break;

  case 182: // keyword_item: id "=" expr
#line 765 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2371 "./parser.cpp"
    break;

  case 183: // keyword_item: "**" expr
#line 766 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2377 "./parser.cpp"
    break;

  case 184: // keyword_items: keyword_items "," keyword_item
#line 770 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2383 "./parser.cpp"
    break;

  case 185: // keyword_items: keyword_item
#line 771 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2389 "./parser.cpp"
    break;

  case 186: // primary: id
#line 776 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2395 "./parser.cpp"
    break;

  case 187: // primary: string
#line 777 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2401 "./parser.cpp"
    break;

  case 188: // primary: expr "." id
#line 778 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2407 "./parser.cpp"
    break;

  case 189: // function_call: primary "(" call_arguement_list ")"
#line 782 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2413 "./parser.cpp"
    break;

  case 190: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 783 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2420 "./parser.cpp"
    break;

  case 191: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 785 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2427 "./parser.cpp"
    break;

  case 192: // function_call: primary "(" keyword_items comma_opt ")"
#line 787 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2433 "./parser.cpp"
    break;

  case 193: // function_call: function_call "(" call_arguement_list ")"
#line 788 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2439 "./parser.cpp"
    break;

  case 194: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 789 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2446 "./parser.cpp"
    break;

  case 195: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 791 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2453 "./parser.cpp"
    break;

  case 196: // function_call: function_call "(" keyword_items comma_opt ")"
#line 793 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2459 "./parser.cpp"
    break;

  case 197: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 800 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2465 "./parser.cpp"
    break;

  case 198: // expr: id
#line 804 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2471 "./parser.cpp"
    break;

  case 199: // expr: integer_literal
#line 805 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2480 "./parser.cpp"
    break;

  case 200: // expr: string
#line 809 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2486 "./parser.cpp"
    break;

  case 201: // expr: real_literal
#line 810 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2492 "./parser.cpp"
    break;

  case 202: // expr: image_literal
#line 811 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2501 "./parser.cpp"
    break;

  case 203: // expr: TRUE
#line 815 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2507 "./parser.cpp"
    break;

  case 204: // expr: FALSE
#line 816 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2513 "./parser.cpp"
    break;

  case 205: // expr: NONE
#line 817 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2519 "./parser.cpp"
    break;

  case 206: // expr: "..."
#line 818 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2525 "./parser.cpp"
    break;

  case 207: // expr: "(" expr ")"
#line 819 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2531 "./parser.cpp"
    break;

  case 208: // expr: "(" ")"
#line 820 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2537 "./parser.cpp"
    break;

  case 209: // expr: function_call
#line 821 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2543 "./parser.cpp"
    break;

  case 210: // expr: "[" expr_list_opt "]"
#line 823 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2549 "./parser.cpp"
    break;

  case 211: // expr: "[" expr_list "," "]"
#line 824 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2555 "./parser.cpp"
    break;

  case 212: // expr: "{" expr_list "}"
#line 825 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2561 "./parser.cpp"
    break;

  case 213: // expr: "{" expr_list "," "}"
#line 826 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2567 "./parser.cpp"
    break;

  case 214: // expr: expr "." id
#line 827 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2573 "./parser.cpp"
    break;

  case 215: // expr: "{" "}"
#line 829 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2579 "./parser.cpp"
    break;

  case 216: // expr: "{" dict_list "}"
#line 830 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2585 "./parser.cpp"
    break;

  case 217: // expr: id ":=" expr
#line 834 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2591 "./parser.cpp"
    break;

  case 218: // expr: "*" expr
#line 835 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2597 "./parser.cpp"
    break;

  case 219: // expr: expr "+" expr
#line 837 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2603 "./parser.cpp"
    break;

  case 220: // expr: expr "-" expr
#line 838 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2609 "./parser.cpp"
    break;

  case 221: // expr: expr "*" expr
#line 839 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2615 "./parser.cpp"
    break;

  case 222: // expr: expr "/" expr
#line 840 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2621 "./parser.cpp"
    break;

  case 223: // expr: expr "%" expr
#line 841 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2627 "./parser.cpp"
    break;

  case 224: // expr: "-" expr
#line 842 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2633 "./parser.cpp"
    break;

  case 225: // expr: "+" expr
#line 843 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2639 "./parser.cpp"
    break;

  case 226: // expr: "~" expr
#line 844 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2645 "./parser.cpp"
    break;

  case 227: // expr: expr "**" expr
#line 845 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2651 "./parser.cpp"
    break;

  case 228: // expr: expr "//" expr
#line 846 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2657 "./parser.cpp"
    break;

  case 229: // expr: expr "@" expr
#line 847 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2663 "./parser.cpp"
    break;

  case 230: // expr: expr "&" expr
#line 849 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2669 "./parser.cpp"
    break;

  case 231: // expr: expr "|" expr
#line 850 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2675 "./parser.cpp"
    break;

  case 232: // expr: expr "^" expr
#line 851 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2681 "./parser.cpp"
    break;

  case 233: // expr: expr "<<" expr
#line 852 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2687 "./parser.cpp"
    break;

  case 234: // expr: expr ">>" expr
#line 853 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2693 "./parser.cpp"
    break;

  case 235: // expr: expr "==" expr
#line 855 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2699 "./parser.cpp"
    break;

  case 236: // expr: expr "!=" expr
#line 856 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2705 "./parser.cpp"
    break;

  case 237: // expr: expr "<" expr
#line 857 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2711 "./parser.cpp"
    break;

  case 238: // expr: expr "<=" expr
#line 858 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2717 "./parser.cpp"
    break;

  case 239: // expr: expr ">" expr
#line 859 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2723 "./parser.cpp"
    break;

  case 240: // expr: expr ">=" expr
#line 860 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2729 "./parser.cpp"
    break;

  case 241: // expr: expr "is" expr
#line 861 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2735 "./parser.cpp"
    break;

  case 242: // expr: expr "is not" expr
#line 862 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2741 "./parser.cpp"
    break;

  case 243: // expr: expr "in" expr
#line 863 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2747 "./parser.cpp"
    break;

  case 244: // expr: expr "not in" expr
#line 864 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2753 "./parser.cpp"
    break;

  case 245: // expr: expr "and" expr
#line 866 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2759 "./parser.cpp"
    break;

  case 246: // expr: expr "or" expr
#line 867 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2765 "./parser.cpp"
    break;

  case 247: // expr: "not" expr
#line 868 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2771 "./parser.cpp"
    break;

  case 248: // expr: ternary_if_statement
#line 875 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2777 "./parser.cpp"
    break;

  case 249: // id: identifier
#line 880 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2783 "./parser.cpp"
    break;

  case 250: // sep: sep sep_one
#line 884 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2789 "./parser.cpp"
    break;

  case 251: // sep: sep_one
#line 885 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2795 "./parser.cpp"
    break;

  case 252: // sep_one: NEWLINE
#line 889 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2801 "./parser.cpp"
    break;

  case 253: // sep_one: COMMENT
#line 890 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2807 "./parser.cpp"
    break;

  case 254: // sep_one: ";"
#line 891 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2813 "./parser.cpp"
    break;


#line 2817 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -393;

  const short  Parser ::yytable_ninf_ = -189;

  const short
   Parser ::yypact_[] =
  {
     709,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  2702,
    2702,  -393,  -393,  2745,  2770,    36,  2702,  2702,    24,  2702,
    2702,  -393,  2785,    39,  2702,  2845,  2369,   441,  2702,  2702,
    2702,  2702,  2702,  2702,  -393,  -393,  -393,  -393,  2176,  -393,
    -393,  -393,  -393,  -393,  -393,    64,  -393,  -393,  -393,  -393,
    -393,   114,  -393,  -393,  -393,  -393,  -393,   114,    99,    20,
    -393,  -393,  -393,  -393,  -393,  -393,  2785,  -393,  -393,    59,
      78,    53,   107,   894,    68,   114,  -393,   441,  1142,  1206,
     441,   135,  1988,   441,   168,   156,  2052,  -393,    71,    31,
    -393,   177,  1251,  -393,    43,  -393,   194,   177,  2588,  -393,
     114,  1315,   441,  -393,    84,  1360,  -393,   121,  -393,   139,
    1424,  -393,   196,  1469,   131,   212,     6,     6,     6,   960,
       6,  -393,  -393,  -393,   114,   114,   213,   213,  2702,   209,
    -393,   259,  2702,  2662,  2662,  2702,  2702,  2702,  2702,  2702,
    2702,  2702,  2702,  2702,  2702,  2702,  2702,   213,  2702,  2702,
    2702,  2702,  2702,  2702,  2702,  2702,  2702,  2702,  2702,  2702,
    2702,  2702,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  2702,  2702,  -393,  2702,  -393,  1469,
    2702,  2702,   228,  2702,   229,  1469,  2785,  2702,    11,   213,
      49,  -393,    76,  2702,   782,   213,    24,   145,   114,   230,
    1031,   114,  2702,  2702,  2429,  -393,  2702,  -393,  2702,  2244,
     225,  -393,  2218,   114,   -10,   227,   960,  -393,  -393,  1988,
    2702,  -393,   234,   217,  -393,   238,   176,   239,   218,   246,
    2588,  1533,   517,   517,   517,   517,  2097,   396,   189,  1578,
     517,   211,   231,   211,     6,     6,     6,     6,     6,   338,
     299,   299,   517,   517,   517,   517,     6,   517,  1988,  1988,
    1988,  1988,  2256,  2331,   249,  2052,    24,   194,  -393,    24,
     194,    52,  -393,   179,  -393,   -45,  2571,   119,   145,  -393,
    -393,  2503,   198,   145,  2343,   145,  -393,  1988,  -393,  -393,
    1424,  1988,  -393,  1642,  2702,  -393,   114,  2662,    15,   114,
    1988,  2662,  -393,  2662,   223,  2702,  2662,  -393,  2662,   233,
    2702,  2702,  -393,  1706,  -393,  1770,   114,   251,   251,    24,
     194,  2702,   255,  -393,  -393,   216,   235,   140,  -393,   220,
    -393,   855,  -393,  2677,   256,  -393,   167,   295,   271,  -393,
    -393,   270,   245,   145,   247,   274,    13,    57,   213,  -393,
    -393,  -393,   275,  -393,   252,    79,   277,   280,  -393,  -393,
    1988,   277,   280,  -393,   767,  1988,  -393,  -393,   145,    24,
     260,   262,   251,  1834,   782,  -393,   158,  -393,   242,  -393,
    -393,  -393,   114,  1097,   114,   283,   293,  -393,   294,   114,
    2702,  -393,  -393,   296,  2662,  2662,   297,    17,   300,   302,
       8,  -393,   -11,  2702,  2702,    18,   267,  2702,   273,   289,
     290,   323,  -393,  -393,   291,   114,  -393,  -393,   145,   213,
     114,   145,   114,   114,   114,   145,   114,    46,    98,   114,
     213,   319,    30,  -393,  -393,  -393,   321,  -393,  -393,   782,
    2702,  1879,  1988,   324,  -393,  -393,  -393,  -393,   329,  -393,
     145,  -393,   339,   145,  -393,   145,   145,   145,  -393,   145,
      18,   344,   345,   145,   302,    35,  -393,   213,   336,    15,
    -393,  -393,  1943,  2702,   114,   237,   114,  -393,   387,  -393,
    -393,  -393,   114,   114,  -393,  -393,   213,   302,    38,  -393,
    -393,   363,   782,  1988,   145,   367,  -393,   145,   372,   145,
     145,   302,  -393,   213,    15,  -393,  -393,   114,  -393,   114,
    -393,  -393,  -393,   302,   145,   145,  -393,  -393,  -393
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
     120,   199,   201,   202,   249,   168,   204,   203,   205,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    41,     0,     0,     0,     0,     0,   172,     0,
       0,     0,     0,     0,   206,   254,   252,   253,   120,     3,
       5,    67,    71,    72,    63,     0,    70,    69,    68,    65,
      66,     0,    73,   118,   113,   114,   115,    23,     0,   119,
     116,   117,    74,   248,    75,   112,     0,    64,    62,   200,
      30,     0,   209,   166,   198,     4,   251,     0,    28,    39,
       0,    43,   174,     0,     0,    34,   176,    84,     0,     0,
      77,   154,     0,    80,    78,    82,    85,   156,   247,    42,
       0,     0,     0,   109,     0,   106,   215,     0,   179,     0,
     174,   208,     0,   174,     0,   171,   224,   225,   218,     0,
     226,     1,     2,   164,    22,    24,     0,     0,     0,   165,
     167,     0,    31,   172,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,   169,     0,   250,     0,
       0,     0,     0,    44,     0,   176,     0,    35,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,   212,     0,   216,     0,     0,
     207,   210,     0,   122,     0,     0,     0,   163,   170,   173,
       0,   180,   171,     0,   185,   146,   198,   171,     0,   146,
     245,     0,   243,   241,   242,   244,   246,   230,   232,    60,
     235,   220,   214,   219,   221,   227,   229,   228,   223,   231,
     233,   234,   237,   238,   239,   240,   222,   236,    47,   217,
      29,    40,     0,     0,     0,   175,     0,    86,    76,     0,
      88,     0,     9,   160,     8,     0,     0,     0,     0,    79,
      81,   120,     0,     0,     0,     0,   108,   107,   213,   178,
       0,   177,    32,   173,   172,   211,     0,   172,   144,   121,
     183,   181,   189,   145,     0,     0,   181,   193,   145,     0,
       0,     0,    45,   173,    36,   175,     0,   146,   146,     0,
      89,     0,     0,   162,    12,     0,    18,    21,    14,     0,
       7,   120,    11,     0,     0,   100,   101,    92,     0,   110,
      33,   171,     0,     0,     0,   171,     0,     0,     0,   134,
     143,   129,   146,   132,     0,   123,   146,   146,   184,   192,
     182,   146,   146,   196,   155,    61,    46,    37,     0,   145,
       0,     0,   146,     0,     0,    13,    20,    15,     0,    17,
       6,    10,     0,     0,     0,     0,     0,    99,     0,     0,
     181,   197,   149,     0,     0,     0,     0,     0,   146,   146,
     145,   130,     0,     0,     0,   145,     0,   145,     0,     0,
       0,    94,    87,    90,     0,     0,   161,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   145,   138,   145,   142,   146,   133,   131,     0,
       0,   124,   125,     0,   190,   191,   194,   195,     0,    91,
       0,    96,     0,     0,   105,     0,     0,     0,   111,     0,
       0,     0,     0,     0,   146,   145,   135,     0,   146,   145,
     127,   147,     0,     0,     0,   157,     0,    97,   102,   103,
      93,   150,     0,     0,   153,   136,     0,   146,   145,   139,
     128,   146,     0,   126,     0,     0,   159,     0,     0,     0,
       0,   146,   140,     0,   145,   148,    95,     0,    98,     0,
     151,   152,   137,   146,     0,     0,   141,   158,   104
  };

  const short
   Parser ::yypgoto_[] =
  {
    -393,  -393,   389,   207,  -393,  -365,  -393,  -393,  -393,  -393,
    -256,  -393,  -393,  -393,  -393,   -18,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -193,     5,  -189,  -145,  -393,  -393,  -393,
    -393,    89,  -393,  -393,  -192,   328,  -393,  -393,  -393,  -393,
    -113,  -393,   -38,  -382,  -392,  -393,  -130,  -393,  -393,  -393,
    -393,  -393,   -43,  -393,  -393,  -393,  -393,  -393,   -25,    33,
     350,   232,  -393,  -129,  -290,  -128,  -393,  -393,     2,   222,
       0,    96
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    38,    39,   282,   272,   273,   331,   274,   275,   276,
      40,    41,    42,    43,    44,    45,    84,    46,    47,    48,
      49,   175,    50,    51,    94,    95,    96,    89,    52,    53,
      54,   335,   336,    55,   103,   104,    56,    57,    58,    59,
     349,   350,   351,   352,   353,   354,   401,    60,    61,    62,
      63,    64,   323,    65,    66,    67,    68,    69,   221,    70,
      85,   108,   109,   223,   224,   225,    71,    72,    82,    74,
     278,    76
  };

  const short
   Parser ::yytable_[] =
  {
      75,   277,    73,   114,    99,   228,   229,   280,   438,   416,
     286,    78,    79,   358,     4,   431,    86,     4,   358,    92,
      88,     4,    98,     4,     4,   332,   101,   105,   110,   113,
       4,   116,   117,   118,   119,   120,     4,     4,   439,   296,
      73,     4,     4,   267,     4,   270,    81,   297,   129,    91,
     468,   124,    97,   324,   325,     4,   195,   125,     4,   107,
     112,   115,   190,     4,   395,     4,   147,   130,   266,   150,
     347,   348,   440,    93,   471,   381,   176,   347,   348,   179,
     430,   220,   113,   326,   128,   185,    93,   491,   100,   436,
     396,   191,   286,   467,   192,   304,    87,   460,   486,   309,
     197,   503,   188,   189,   200,   358,   269,   271,   397,   319,
     133,    93,   438,   182,    93,   358,  -187,   123,   126,   213,
     127,   317,   177,   461,   318,  -186,   320,   505,   403,   132,
     216,   189,   404,   201,   219,   202,   189,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   193,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   134,   342,   222,   227,   264,   346,
     358,   178,   204,   356,   372,   462,   257,   258,   361,   259,
     280,   277,   260,   261,   176,   219,   183,   370,   371,   265,
     206,   385,   333,   386,    35,   219,    73,   205,   283,   327,
     186,   285,   321,   322,   105,   287,   219,   187,   290,   211,
     291,   293,    36,    37,   219,   207,   299,   328,   329,     4,
     178,   178,   300,   333,   334,    35,   406,   408,   193,   305,
     177,   409,   410,  -186,   398,   399,   142,    90,   377,   378,
      90,   281,   414,    36,    37,   196,   277,   209,   146,   147,
     148,   149,   150,   151,   152,   153,   -19,   -19,   155,   156,
     321,   495,   217,   212,   313,   315,   427,   218,   433,   435,
     161,   147,   344,   149,   150,   151,   152,   153,    73,   262,
     263,   284,   294,    73,   298,   301,   105,   437,  -188,   303,
     306,   131,   161,   178,   302,   307,   343,   308,   316,   277,
     359,   466,   369,   219,   374,   384,   470,   360,   219,   178,
     363,    90,   364,   365,   375,   376,   368,   464,   379,   388,
     389,   390,   391,   373,   393,   394,   400,   341,   405,   402,
     345,   407,   422,    73,   485,   383,   357,   412,   489,   413,
     417,   362,   423,   424,   444,   426,   429,   448,   214,   215,
     445,   432,   437,   434,   487,   226,   226,   502,   146,   147,
     148,   149,   150,   151,   152,   153,   446,   447,   449,   242,
     465,   512,   469,   501,   178,   437,    73,   305,   474,   178,
     161,   178,   418,   516,   421,   142,   143,   488,   476,   425,
     513,   437,   219,   482,   483,   178,   219,   146,   147,   148,
     149,   150,   151,   152,   153,   441,   442,   155,   156,   219,
      90,   268,    90,   498,   504,   450,   507,   279,    90,   161,
     453,   509,   455,   456,   457,   387,   459,   122,   428,   463,
     199,   490,   496,   184,     0,     0,     0,     0,   289,   178,
       0,    73,   472,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   178,   155,   156,     0,     0,     0,
       0,     0,     0,     0,   494,   493,   497,   161,     0,    20,
       0,     0,   499,   500,     0,   330,     0,     0,    90,     0,
     337,    90,   339,    90,    73,     0,     0,    26,    77,    28,
      29,     0,    30,    31,     0,     0,     0,   514,    33,   515,
       0,     0,     0,     0,   178,     0,    34,   178,   111,   226,
     355,   178,     0,   226,     0,   226,     0,     0,   226,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,   178,   136,     0,   178,
     392,   178,   178,   178,     0,   178,     0,     0,     0,   178,
       0,     0,     0,     0,   142,   143,     0,     0,     0,   355,
     355,     0,     0,     0,     0,   411,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,   156,     0,     0,
     178,    90,     0,   178,     0,   178,   178,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     178,   178,     0,     0,     0,     0,   226,   226,     0,   355,
       0,     0,   355,     0,     0,   451,     0,   443,   454,     0,
       0,     0,   458,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   355,     0,   355,     0,     0,   475,     0,     0,
     477,     0,   478,   479,   480,     0,   481,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   443,     0,     0,     0,     0,   355,     0,   355,
       0,   355,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,   508,     0,   510,   511,   355,     0,
     355,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,   517,   518,     9,    10,   355,   355,    11,     0,    12,
       0,    13,     0,     0,     0,     0,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,     0,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
      30,    31,     0,    32,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,    34,     1,     2,     3,     4,    35,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,    36,    37,     0,
      15,    16,     0,    18,   142,   143,     0,     0,     0,    19,
      20,     0,    21,    22,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,   156,    26,    27,
      28,    29,     0,    30,    31,     0,     0,     0,   161,    33,
       0,     0,     0,     0,     0,     0,     0,    34,     1,     2,
       3,     4,    35,     5,     6,     7,     8,     0,     0,     9,
      10,     0,     0,    11,     0,    12,     0,    13,     0,     0,
      36,    37,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,   135,     0,     0,     0,
       0,    26,    27,    28,    29,     0,    30,    31,     0,    32,
       0,     0,    33,     0,   136,     0,   137,   138,   139,   140,
      34,     0,     0,   141,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,     0,  -174,     0,  -174,     0,   145,
       0,     0,   380,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,   135,     0,     0,   161,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     136,     0,   137,   138,   139,   140,   174,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,   142,   143,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
      35,   161,     0,   135,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
       0,   136,   174,   137,   138,   139,   140,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,     0,   154,
     155,   156,   157,   158,   159,   160,     0,     0,   210,   135,
     419,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,   137,
     138,   139,   140,   174,     0,     0,   141,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   420,     0,     0,     0,
       0,     0,   145,     0,   135,     0,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,   156,   157,   158,
     159,   160,   136,     0,   137,   138,   139,   140,   161,     0,
       0,   141,     0,     0,     0,     0,     0,     0,     0,   142,
     143,     0,     0,   180,     0,     0,     0,   145,     0,   174,
       0,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,     0,   135,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,   136,     0,   137,   138,
     139,   140,     0,     0,   174,   141,     0,     0,     0,     0,
       0,     0,     0,   142,   143,     0,     0,     0,     0,     0,
       0,   145,     0,   135,     0,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   136,     0,   137,   138,   139,   140,   161,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     194,     0,     0,     0,     0,     0,   145,     0,   174,     0,
     146,   147,   148,   149,   150,   151,   152,   153,     0,   154,
     155,   156,   157,   158,   159,   160,     0,   135,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,     0,   137,   138,   139,
     140,     0,     0,   174,   141,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   198,     0,     0,     0,     0,     0,
     145,     0,   135,   203,   146,   147,   148,   149,   150,   151,
     152,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     136,     0,   137,   138,   139,   140,   161,     0,     0,   141,
       0,     0,     0,     0,     0,     0,     0,   142,   143,     0,
       0,     0,     0,     0,     0,   145,     0,   174,     0,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,     0,   135,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,   137,   138,   139,   140,
       0,     0,   174,   141,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   208,     0,     0,     0,     0,     0,   145,
       0,   135,     0,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   136,
       0,   137,   138,   139,   140,   161,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,     0,     0,   145,     0,   174,     0,   146,   147,
     148,   149,   150,   151,   152,   153,     0,   154,   155,   156,
     157,   158,   159,   160,     0,   135,   210,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,   310,     0,     0,
       0,     0,     0,   136,     0,   137,   138,   139,   140,     0,
       0,   174,   141,     0,     0,     0,     0,     0,     0,     0,
     142,   143,     0,     0,     0,     0,     0,     0,   145,     0,
     135,     0,   146,   147,   148,   149,   150,   151,   152,   153,
       0,   154,   155,   156,   157,   158,   159,   160,   136,     0,
     137,   138,   139,   140,   161,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,   143,     0,     0,     0,
       0,   311,     0,   145,     0,   174,     0,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,     0,   135,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   137,   138,   139,   140,     0,     0,
     174,   141,     0,     0,     0,     0,     0,     0,     0,   142,
     143,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,     0,   135,   340,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,   137,   138,
     139,   140,     0,     0,   174,   141,     0,     0,     0,     0,
       0,     0,     0,   142,   143,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,     0,   135,   366,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,     0,   137,   138,   139,   140,     0,     0,   174,   141,
       0,     0,     0,     0,     0,     0,     0,   142,   143,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,     0,   135,   367,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,   137,   138,   139,   140,
       0,     0,   174,   141,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   415,     0,     0,     0,     0,     0,   145,
       0,   135,     0,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   136,
       0,   137,   138,   139,   140,   161,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,   142,   143,     0,     0,
       0,     0,   473,     0,   145,     0,   174,     0,   146,   147,
     148,   149,   150,   151,   152,   153,     0,   154,   155,   156,
     157,   158,   159,   160,     0,   135,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,     0,   137,   138,   139,   140,     0,
       0,   174,   141,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   492,     0,     0,     0,     0,     0,   145,     0,
     135,     0,   146,   147,   148,   149,   150,   151,   152,   153,
       0,   154,   155,   156,   157,   158,   159,   160,   136,     0,
     137,   138,   139,   140,   161,     0,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,   143,     0,     0,     0,
       0,     0,     0,   145,     0,   174,     0,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,     0,   135,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   138,   139,   140,     0,     0,
     174,   141,     0,     0,     0,     0,     0,     0,     0,   142,
     143,     0,     0,     0,     0,     0,     0,   145,     0,   135,
       0,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   136,     0,   137,
     138,   139,   140,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,     0,     0,     0,     0,
       0,     0,   145,     0,   174,     0,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,   156,   157,   158,
     159,   160,     0,     0,     0,     0,   121,     0,   161,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       9,    10,     0,     0,    11,     0,    12,     0,    13,   174,
       0,     0,     0,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,    19,    20,     0,    21,    22,    23,    24,
      25,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,    26,    27,    28,    29,     0,    30,    31,     0,
      32,     0,     0,    33,     0,     0,     0,     1,     2,     3,
       4,    34,     5,     6,     7,     8,    20,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,     0,    26,    77,    28,    29,     0,    30,
      31,     0,    20,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,    34,    20,     0,   295,     0,     0,     0,
      26,    77,    28,    29,     0,    30,    31,     0,     0,     0,
       0,    33,    26,    77,    28,    29,     0,    30,    31,    34,
       0,   292,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    34,     0,   312,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,    20,     0,     0,     0,     0,     0,    26,    77,    28,
      29,     0,    30,    31,     0,     0,     0,     0,    33,    26,
      77,    28,    29,     0,    30,    31,    34,    20,   314,     0,
      33,     0,     0,     0,     0,     0,     0,     0,    34,     0,
     338,     0,     0,     0,     0,    26,    77,    28,    29,     0,
      30,    31,     1,     2,     3,     4,    33,     5,     6,     7,
       8,     0,     0,     0,    34,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    77,    28,    29,     0,
      30,    31,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,    34,   288,     1,     2,     3,     4,
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
       0,    21,    22,     0,     0,     0,     0,     0,   136,     0,
     137,   138,   139,   140,     0,     0,     0,    26,    27,    28,
      29,     0,    30,    31,     0,   142,   143,     0,    33,     0,
       0,     0,     0,   145,     0,     0,    34,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     1,     2,     3,     4,   161,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,    20,     0,     0,    26,    77,
      28,    29,     0,    30,    31,   220,   382,     0,     0,    33,
       0,     0,     0,    26,    77,    28,    29,    34,    30,    31,
      20,     0,     0,     0,    33,     0,     0,     0,     1,     2,
       3,     4,    34,     5,     6,     7,     8,     0,    26,    77,
      28,    29,     0,    30,    31,     0,     0,     0,     0,    33,
       0,     0,     0,     1,     2,     3,     4,    34,     5,     6,
       7,     8,     0,    20,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,    26,    80,    28,    29,     0,    30,    31,    20,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,    20,     0,     0,    26,    83,    28,    29,
       0,    30,    31,     0,     0,     0,     0,    33,     0,     0,
       0,    26,    27,    28,    29,    34,    30,    31,     1,     2,
       3,     4,    33,     5,     6,     7,     8,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,   102,    28,    29,     0,    30,    31,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
      34
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   194,     0,    28,    22,   134,   134,   196,   400,   374,
     202,     9,    10,   303,     6,   397,    14,     6,   308,    17,
      15,     6,    20,     6,     6,   281,    24,    25,    26,    27,
       6,    29,    30,    31,    32,    33,     6,     6,    49,    49,
      38,     6,     6,   188,     6,   190,    13,    57,    66,    16,
     432,    51,    19,    98,    99,     6,    13,    57,     6,    26,
      27,    28,    31,     6,    51,     6,    60,     8,    57,    63,
      62,    63,    83,    62,   439,   331,     8,    62,    63,    77,
      63,    63,    80,   276,    64,    83,    62,   469,    49,    81,
      77,    60,   284,    63,    89,   225,    60,    51,    63,   229,
     100,    63,    31,    60,   102,   395,    57,    31,    51,    57,
      57,    62,   504,    80,    62,   405,    57,    53,    19,   119,
      21,   266,    54,    77,   269,    57,   271,   492,    49,    51,
     128,    60,    53,    49,   132,    51,    60,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    51,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    57,   294,   133,   134,   186,   297,
     460,    75,    51,   301,   319,    77,   174,   175,   306,   177,
     369,   374,   180,   181,     8,   183,    51,   317,   318,   187,
      51,    24,    25,    26,    80,   193,   194,    76,   198,    80,
      32,   201,    23,    24,   202,   203,   204,    51,   206,    78,
     208,   209,    98,    99,   212,    76,   216,    98,    99,     6,
     124,   125,   220,    25,    26,    80,   356,   357,    51,    53,
      54,   361,   362,    57,   347,   348,    47,    15,    98,    99,
      18,    96,   372,    98,    99,    51,   439,    51,    59,    60,
      61,    62,    63,    64,    65,    66,    98,    99,    69,    70,
      23,    24,    53,    51,   262,   263,   394,     8,   398,   399,
      81,    60,   297,    62,    63,    64,    65,    66,   276,    51,
      51,    51,    57,   281,    57,    51,   284,   400,    57,    51,
      51,    69,    81,   197,    77,    77,   296,    51,    49,   492,
      77,   431,    51,   301,    49,    49,   436,   305,   306,   213,
      77,    89,   310,   311,    98,    80,   316,   430,    98,    24,
      49,    51,    77,   321,    77,    51,    51,   294,    51,    77,
     297,    51,    49,   331,   464,   333,   303,    77,   468,    77,
      98,   308,    49,    49,    77,    49,    49,    24,   126,   127,
      77,    51,   465,    51,   467,   133,   134,   487,    59,    60,
      61,    62,    63,    64,    65,    66,    77,    77,    77,   147,
      51,   501,    51,   486,   278,   488,   374,    53,    49,   283,
      81,   285,   382,   513,   384,    47,    48,    51,    49,   389,
     503,   504,   390,    49,    49,   299,   394,    59,    60,    61,
      62,    63,    64,    65,    66,   403,   404,    69,    70,   407,
     188,   189,   190,    26,    51,   415,    49,   195,   196,    81,
     420,    49,   422,   423,   424,   336,   426,    38,   395,   429,
     102,   469,   475,    83,    -1,    -1,    -1,    -1,   206,   343,
      -1,   439,   440,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,   368,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,   473,   476,    81,    -1,    38,
      -1,    -1,   482,   483,    -1,   278,    -1,    -1,   266,    -1,
     283,   269,   285,   271,   492,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,   507,    67,   509,
      -1,    -1,    -1,    -1,   418,    -1,    75,   421,    77,   297,
     298,   425,    -1,   301,    -1,   303,    -1,    -1,   306,    -1,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   319,    -1,    -1,    -1,    -1,   450,    30,    -1,   453,
     343,   455,   456,   457,    -1,   459,    -1,    -1,    -1,   463,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,   347,
     348,    -1,    -1,    -1,    -1,   368,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    -1,    -1,
     494,   369,    -1,   497,    -1,   499,   500,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     514,   515,    -1,    -1,    -1,    -1,   394,   395,    -1,   397,
      -1,    -1,   400,    -1,    -1,   418,    -1,   405,   421,    -1,
      -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   430,    -1,   432,    -1,    -1,   450,    -1,    -1,
     453,    -1,   455,   456,   457,    -1,   459,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,    -1,    -1,   465,    -1,   467,
      -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   494,    -1,    -1,   497,    -1,   499,   500,   486,    -1,
     488,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,   514,   515,    14,    15,   503,   504,    18,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,    80,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    98,    99,    -1,
      28,    29,    -1,    31,    47,    48,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    81,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,     3,     4,
       5,     6,    80,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      98,    99,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    64,
      -1,    -1,    67,    -1,    30,    -1,    32,    33,    34,    35,
      75,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    51,    -1,    53,    -1,    55,
      -1,    -1,    97,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    12,    -1,    -1,    81,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      30,    -1,    32,    33,    34,    35,   102,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
      -1,    30,   102,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
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
      -1,    -1,    -1,    75,    38,    -1,    78,    -1,    -1,    -1,
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
      77,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,     3,     4,     5,     6,    67,     8,     9,    10,
      11,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     151,   152,   153,   154,   155,   157,   158,   159,   160,   161,
     163,   170,   171,   172,   173,   174,   175,    57,   172,   172,
      57,   163,   172,    57,   120,   164,   172,    60,   128,   131,
     173,   163,   172,    62,   128,   129,   130,   163,   172,   119,
      49,   172,    57,   138,   139,   172,    76,   163,   165,   166,
     172,    77,   163,   172,   162,   163,   172,   172,   172,   172,
     172,     0,   106,    53,   174,   174,    19,    21,    64,   119,
       8,   173,    51,    57,    57,    12,    30,    32,    33,    34,
      35,    39,    47,    48,    49,    55,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    70,    71,    72,    73,
      74,    81,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   102,   125,     8,    54,   175,   172,
      51,    28,   163,    51,   164,   172,    32,    51,    31,    60,
      31,    60,   128,    51,    49,    13,    51,   174,    49,   139,
     172,    49,    51,    13,    51,    76,    51,    76,    49,    51,
      77,    78,    51,   174,   173,   173,   172,    53,     8,   172,
      63,   162,   163,   167,   168,   169,   173,   163,   167,   169,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,    51,    51,   119,   172,    57,   130,   173,    57,
     130,    31,   108,   109,   111,   112,   113,   127,   174,   173,
     129,    96,   107,   174,    51,   174,   138,   172,    76,   165,
     172,   172,    77,   172,    57,    78,    49,    57,    57,   174,
     172,    51,    77,    51,   150,    53,    51,    77,    51,   150,
      24,    53,    77,   172,    77,   172,    49,   130,   130,    57,
     130,    23,    24,   156,    98,    99,   127,    80,    98,    99,
     107,   110,   114,    25,    26,   135,   136,   107,    77,   107,
      77,   163,   167,   174,   162,   163,   169,    62,    63,   144,
     145,   146,   147,   148,   149,   173,   169,   163,   168,    77,
     172,   169,   163,    77,   172,   172,    77,    77,   174,    51,
     150,   150,   130,   172,    49,    98,    80,    98,    99,    98,
      97,   114,    49,   172,    49,    24,    26,   135,    24,    49,
      51,    77,   107,    77,    51,    51,    77,    51,   144,   144,
      51,   150,    77,    49,    53,    51,   150,    51,   150,   150,
     150,   107,    77,    77,   150,    49,   109,    98,   174,    13,
      49,   174,    49,    49,    49,   174,    49,   169,   163,    49,
      63,   147,    51,   150,    51,   150,    81,   144,   148,    49,
      83,   172,   172,   173,    77,    77,    77,    77,    24,    77,
     174,   107,   173,   174,   107,   174,   174,   174,   107,   174,
      51,    77,    77,   174,   144,    51,   150,    63,   147,    51,
     150,   109,   172,    53,    49,   107,    49,   107,   107,   107,
     107,   107,    49,    49,   107,   150,    63,   144,    51,   150,
     146,   147,    49,   172,   174,    24,   156,   174,    26,   174,
     174,   144,   150,    63,    51,   109,   107,    49,   107,    49,
     107,   107,   150,   144,   174,   174,   150,   107,   107
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
     172,   172,   172,   172,   172,   172,   172,   172,   172,   173,
     174,   174,   175,   175,   175
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
  "id", "sep", "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   301,   301,   302,   303,   307,   311,   315,   319,   320,
     324,   325,   329,   330,   331,   332,   335,   338,   344,   347,
     353,   356,   362,   363,   364,   369,   373,   377,   381,   382,
     386,   387,   388,   389,   393,   394,   395,   396,   400,   401,
     402,   406,   407,   412,   413,   414,   416,   422,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     441,   442,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   464,   465,   469,   470,
     471,   475,   476,   480,   481,   487,   488,   490,   492,   494,
     496,   498,   503,   504,   508,   510,   521,   522,   523,   526,
     527,   531,   532,   534,   536,   538,   542,   543,   547,   548,
     552,   553,   562,   563,   564,   565,   566,   567,   571,   575,
     576,   580,   581,   585,   586,   587,   588,   592,   594,   596,
     600,   601,   603,   607,   608,   616,   617,   618,   620,   621,
     623,   625,   627,   631,   632,   636,   637,   641,   643,   655,
     657,   659,   661,   663,   669,   673,   677,   681,   682,   684,
     689,   692,   695,   700,   701,   705,   710,   714,   715,   718,
     721,   727,   728,   732,   733,   746,   747,   751,   754,   755,
     759,   760,   765,   766,   770,   771,   776,   777,   778,   782,
     783,   785,   787,   788,   789,   791,   793,   800,   804,   805,
     809,   810,   811,   815,   816,   817,   818,   819,   820,   821,
     823,   824,   825,   826,   827,   829,   830,   834,   835,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     849,   850,   851,   852,   853,   855,   856,   857,   858,   859,
     860,   861,   862,   863,   864,   866,   867,   868,   875,   880,
     884,   885,   889,   890,   891
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
#line 3977 "./parser.cpp"

#line 894 "parser.ypp"
