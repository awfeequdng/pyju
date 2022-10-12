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
#line 295 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1224 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 296 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1230 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 301 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1236 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 305 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1242 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 309 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1248 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 313 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1254 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 314 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1260 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 318 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1266 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 319 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1272 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 323 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1278 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 324 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1284 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 325 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1290 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 326 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1298 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 329 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1306 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 332 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1314 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 338 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1322 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 341 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1330 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 347 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1338 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 350 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1346 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 356 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1352 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 357 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1358 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 358 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1364 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 363 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1370 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 367 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1376 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 371 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1382 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 375 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1388 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 376 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1394 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 380 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1400 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 381 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1406 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 382 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1412 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 383 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1418 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 387 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1424 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 388 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1430 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 389 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1436 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 390 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1442 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 394 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1448 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 395 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1454 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 396 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1460 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 400 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1466 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 401 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1472 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 406 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1478 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 407 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1484 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 408 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1491 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 410 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1498 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 416 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1504 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 420 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1510 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 421 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1516 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 422 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1522 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 423 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1528 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 424 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1534 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 425 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1540 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 426 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1546 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 427 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1552 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 428 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1558 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 429 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1564 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 430 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1570 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 431 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1576 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 435 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1582 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 436 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1588 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 440 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1594 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 441 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1600 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 442 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1606 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 443 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1612 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 444 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1618 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 445 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1624 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 446 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1630 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 447 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1636 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 448 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1642 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 449 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1648 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 450 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1654 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 451 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1660 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 452 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1666 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 453 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1672 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 458 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1678 "./parser.cpp"
    break;

  case 77: // module: id
#line 459 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1684 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 463 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1690 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 464 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1696 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 465 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1702 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 469 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1708 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 470 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1714 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 474 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1720 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 475 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1726 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 481 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1732 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 482 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1739 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 484 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1746 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 486 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1753 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 488 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1760 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 490 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1767 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 492 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1774 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 497 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1780 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 498 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1787 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 502 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1794 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 505 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1800 "./parser.cpp"
    break;

  case 96: // multi_line_statement: if_statement
#line 516 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1806 "./parser.cpp"
    break;

  case 97: // multi_line_statement: for_statement
#line 517 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1812 "./parser.cpp"
    break;

  case 98: // multi_line_statement: function_def
#line 520 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1818 "./parser.cpp"
    break;

  case 99: // multi_line_statement: while_statement
#line 525 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1824 "./parser.cpp"
    break;

  case 100: // decorators_opt: decorators
#line 529 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1830 "./parser.cpp"
    break;

  case 101: // decorators_opt: %empty
#line 530 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1836 "./parser.cpp"
    break;

  case 102: // decorators: decorators "@" expr sep
#line 534 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1842 "./parser.cpp"
    break;

  case 103: // decorators: "@" expr sep
#line 535 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1848 "./parser.cpp"
    break;

  case 104: // parameter: id
#line 539 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1854 "./parser.cpp"
    break;

  case 105: // parameter: id ":" expr
#line 540 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1860 "./parser.cpp"
    break;

  case 106: // parameter: id "=" expr
#line 541 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1866 "./parser.cpp"
    break;

  case 107: // parameter: id ":" expr "=" expr
#line 542 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1872 "./parser.cpp"
    break;

  case 108: // parameter_list: defparameter_list "," "/" comma_opt
#line 546 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1879 "./parser.cpp"
    break;

  case 109: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 548 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1886 "./parser.cpp"
    break;

  case 110: // parameter_list: parameter_list_no_posonly
#line 550 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1892 "./parser.cpp"
    break;

  case 111: // parameter_list_no_posonly: defparameter_list comma_opt
#line 554 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1898 "./parser.cpp"
    break;

  case 112: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 555 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1905 "./parser.cpp"
    break;

  case 113: // parameter_list_no_posonly: parameter_list_starargs
#line 557 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1911 "./parser.cpp"
    break;

  case 114: // defparameter_list: defparameter_list "," parameter
#line 561 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1917 "./parser.cpp"
    break;

  case 115: // defparameter_list: parameter
#line 562 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1923 "./parser.cpp"
    break;

  case 116: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 570 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1929 "./parser.cpp"
    break;

  case 117: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 571 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1935 "./parser.cpp"
    break;

  case 118: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 572 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1942 "./parser.cpp"
    break;

  case 119: // parameter_list_starargs: "*" parameter comma_opt
#line 574 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1948 "./parser.cpp"
    break;

  case 120: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 575 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1955 "./parser.cpp"
    break;

  case 121: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 577 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1962 "./parser.cpp"
    break;

  case 122: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 579 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1969 "./parser.cpp"
    break;

  case 123: // parameter_list_starargs: "**" parameter comma_opt
#line 581 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1975 "./parser.cpp"
    break;

  case 124: // parameter_list_opt: parameter_list
#line 585 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1981 "./parser.cpp"
    break;

  case 125: // parameter_list_opt: %empty
#line 586 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1987 "./parser.cpp"
    break;

  case 128: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 596 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1993 "./parser.cpp"
    break;

  case 129: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 598 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1999 "./parser.cpp"
    break;

  case 130: // global_statement: GLOBAL expr_list
#line 608 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2005 "./parser.cpp"
    break;

  case 131: // ternary_if_statement: expr IF expr ELSE expr
#line 612 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2011 "./parser.cpp"
    break;

  case 132: // nonlocal_statement: NONLOCAL expr_list
#line 616 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2017 "./parser.cpp"
    break;

  case 133: // elif_statement: ELIF expr ":" sep statements
#line 620 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2023 "./parser.cpp"
    break;

  case 134: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 621 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2030 "./parser.cpp"
    break;

  case 135: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 623 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2037 "./parser.cpp"
    break;

  case 136: // if_statement: IF expr ":" body_stmts
#line 628 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2045 "./parser.cpp"
    break;

  case 137: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 631 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2053 "./parser.cpp"
    break;

  case 138: // if_statement: IF expr ":" body_stmts elif_statement
#line 634 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2060 "./parser.cpp"
    break;

  case 139: // target_list: target_list tuple_item "="
#line 639 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2066 "./parser.cpp"
    break;

  case 140: // target_list: tuple_item "="
#line 640 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2072 "./parser.cpp"
    break;

  case 141: // assignment_statement: target_list tuple_item
#line 644 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2078 "./parser.cpp"
    break;

  case 142: // expression_statment: expr
#line 649 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2084 "./parser.cpp"
    break;

  case 143: // string: string string_literal
#line 657 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2090 "./parser.cpp"
    break;

  case 144: // string: string_literal
#line 658 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2098 "./parser.cpp"
    break;

  case 145: // string: id string_literal
#line 661 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2106 "./parser.cpp"
    break;

  case 146: // string: string id string_literal
#line 664 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2114 "./parser.cpp"
    break;

  case 147: // expr_list_opt: expr_list
#line 670 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2120 "./parser.cpp"
    break;

  case 148: // expr_list_opt: %empty
#line 671 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2126 "./parser.cpp"
    break;

  case 149: // expr_list: expr_list "," expr
#line 675 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2132 "./parser.cpp"
    break;

  case 150: // expr_list: expr
#line 676 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2138 "./parser.cpp"
    break;

  case 151: // expr_for_list: expr_for_list "," expr
#line 689 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2144 "./parser.cpp"
    break;

  case 152: // expr_for_list: expr
#line 690 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2150 "./parser.cpp"
    break;

  case 153: // dict: expr ":" expr
#line 699 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2156 "./parser.cpp"
    break;

  case 154: // dict_list: dict_list "," dict
#line 702 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2162 "./parser.cpp"
    break;

  case 155: // dict_list: dict
#line 703 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2168 "./parser.cpp"
    break;

  case 156: // call_arguement_list: expr_list_opt
#line 707 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2174 "./parser.cpp"
    break;

  case 157: // call_arguement_list: expr_list ","
#line 708 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2180 "./parser.cpp"
    break;

  case 158: // keyword_item: id "=" expr
#line 713 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2186 "./parser.cpp"
    break;

  case 159: // keyword_item: "**" expr
#line 714 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2192 "./parser.cpp"
    break;

  case 160: // keyword_items: keyword_items "," keyword_item
#line 718 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2198 "./parser.cpp"
    break;

  case 161: // keyword_items: keyword_item
#line 719 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2204 "./parser.cpp"
    break;

  case 162: // primary: id
#line 724 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2210 "./parser.cpp"
    break;

  case 163: // primary: string
#line 725 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2216 "./parser.cpp"
    break;

  case 164: // primary: expr "." id
#line 726 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2222 "./parser.cpp"
    break;

  case 165: // function_call: primary "(" call_arguement_list ")"
#line 730 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2228 "./parser.cpp"
    break;

  case 166: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 731 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2235 "./parser.cpp"
    break;

  case 167: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 733 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2242 "./parser.cpp"
    break;

  case 168: // function_call: primary "(" keyword_items comma_opt ")"
#line 735 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2248 "./parser.cpp"
    break;

  case 169: // function_call: function_call "(" call_arguement_list ")"
#line 736 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2254 "./parser.cpp"
    break;

  case 170: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 737 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2261 "./parser.cpp"
    break;

  case 171: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 739 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2268 "./parser.cpp"
    break;

  case 172: // function_call: function_call "(" keyword_items comma_opt ")"
#line 741 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2274 "./parser.cpp"
    break;

  case 173: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 748 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2280 "./parser.cpp"
    break;

  case 174: // expr: id
#line 752 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2286 "./parser.cpp"
    break;

  case 175: // expr: integer_literal
#line 753 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2295 "./parser.cpp"
    break;

  case 176: // expr: string
#line 757 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2301 "./parser.cpp"
    break;

  case 177: // expr: real_literal
#line 758 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2307 "./parser.cpp"
    break;

  case 178: // expr: image_literal
#line 759 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2316 "./parser.cpp"
    break;

  case 179: // expr: TRUE
#line 763 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2322 "./parser.cpp"
    break;

  case 180: // expr: FALSE
#line 764 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2328 "./parser.cpp"
    break;

  case 181: // expr: NONE
#line 765 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2334 "./parser.cpp"
    break;

  case 182: // expr: "..."
#line 766 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2340 "./parser.cpp"
    break;

  case 183: // expr: "(" expr ")"
#line 767 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2346 "./parser.cpp"
    break;

  case 184: // expr: "(" ")"
#line 768 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2352 "./parser.cpp"
    break;

  case 185: // expr: function_call
#line 769 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2358 "./parser.cpp"
    break;

  case 186: // expr: "[" expr_list_opt "]"
#line 771 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2364 "./parser.cpp"
    break;

  case 187: // expr: "[" expr_list "," "]"
#line 772 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2370 "./parser.cpp"
    break;

  case 188: // expr: "{" expr_list "}"
#line 773 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2376 "./parser.cpp"
    break;

  case 189: // expr: "{" expr_list "," "}"
#line 774 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2382 "./parser.cpp"
    break;

  case 190: // expr: expr "." id
#line 775 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2388 "./parser.cpp"
    break;

  case 191: // expr: "{" "}"
#line 777 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2394 "./parser.cpp"
    break;

  case 192: // expr: "{" dict_list "}"
#line 778 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2400 "./parser.cpp"
    break;

  case 193: // expr: id ":=" expr
#line 782 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2406 "./parser.cpp"
    break;

  case 194: // expr: "*" expr
#line 783 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2412 "./parser.cpp"
    break;

  case 195: // expr: expr "+" expr
#line 785 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2418 "./parser.cpp"
    break;

  case 196: // expr: expr "-" expr
#line 786 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2424 "./parser.cpp"
    break;

  case 197: // expr: expr "*" expr
#line 787 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2430 "./parser.cpp"
    break;

  case 198: // expr: expr "/" expr
#line 788 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2436 "./parser.cpp"
    break;

  case 199: // expr: expr "%" expr
#line 789 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2442 "./parser.cpp"
    break;

  case 200: // expr: "-" expr
#line 790 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2448 "./parser.cpp"
    break;

  case 201: // expr: "+" expr
#line 791 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2454 "./parser.cpp"
    break;

  case 202: // expr: "~" expr
#line 792 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2460 "./parser.cpp"
    break;

  case 203: // expr: expr "**" expr
#line 793 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2466 "./parser.cpp"
    break;

  case 204: // expr: expr "//" expr
#line 794 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2472 "./parser.cpp"
    break;

  case 205: // expr: expr "@" expr
#line 795 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2478 "./parser.cpp"
    break;

  case 206: // expr: expr "&" expr
#line 797 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2484 "./parser.cpp"
    break;

  case 207: // expr: expr "|" expr
#line 798 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2490 "./parser.cpp"
    break;

  case 208: // expr: expr "^" expr
#line 799 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2496 "./parser.cpp"
    break;

  case 209: // expr: expr "<<" expr
#line 800 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2502 "./parser.cpp"
    break;

  case 210: // expr: expr ">>" expr
#line 801 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2508 "./parser.cpp"
    break;

  case 211: // expr: expr "==" expr
#line 803 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2514 "./parser.cpp"
    break;

  case 212: // expr: expr "!=" expr
#line 804 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2520 "./parser.cpp"
    break;

  case 213: // expr: expr "<" expr
#line 805 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2526 "./parser.cpp"
    break;

  case 214: // expr: expr "<=" expr
#line 806 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2532 "./parser.cpp"
    break;

  case 215: // expr: expr ">" expr
#line 807 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2538 "./parser.cpp"
    break;

  case 216: // expr: expr ">=" expr
#line 808 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2544 "./parser.cpp"
    break;

  case 217: // expr: expr "is" expr
#line 809 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2550 "./parser.cpp"
    break;

  case 218: // expr: expr "is not" expr
#line 810 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2556 "./parser.cpp"
    break;

  case 219: // expr: expr "in" expr
#line 811 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2562 "./parser.cpp"
    break;

  case 220: // expr: expr "not in" expr
#line 812 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2568 "./parser.cpp"
    break;

  case 221: // expr: expr "and" expr
#line 814 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2574 "./parser.cpp"
    break;

  case 222: // expr: expr "or" expr
#line 815 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2580 "./parser.cpp"
    break;

  case 223: // expr: "not" expr
#line 816 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2586 "./parser.cpp"
    break;

  case 224: // expr: ternary_if_statement
#line 823 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2592 "./parser.cpp"
    break;

  case 225: // id: identifier
#line 828 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2598 "./parser.cpp"
    break;

  case 226: // sep: sep sep_one
#line 832 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2604 "./parser.cpp"
    break;

  case 227: // sep: sep_one
#line 833 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2610 "./parser.cpp"
    break;

  case 228: // sep_one: NEWLINE
#line 837 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2616 "./parser.cpp"
    break;

  case 229: // sep_one: COMMENT
#line 838 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2622 "./parser.cpp"
    break;

  case 230: // sep_one: ";"
#line 839 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2628 "./parser.cpp"
    break;


#line 2632 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -339;

  const short  Parser ::yytable_ninf_ = -165;

  const short
   Parser ::yypact_[] =
  {
     461,  -339,  -339,  -339,  -339,  -339,  -339,  -339,  -339,  2246,
    2246,  -339,  -339,  2272,  2314,    50,  2246,  2246,    46,  2246,
    2246,  -339,  2340,  2246,  1965,  1813,  2246,  2246,  2246,  2246,
    2246,  2246,  -339,  -339,  -339,  -339,  1772,  -339,  -339,  -339,
    -339,  -339,  -339,   -11,  -339,  -339,  -339,  -339,  -339,   128,
    -339,  -339,  -339,   128,    14,    19,  -339,  -339,  -339,  -339,
    -339,  2340,  -339,  -339,    55,    48,    49,    57,   646,   107,
     128,  -339,  1813,   783,   847,  1813,    69,  1584,  1813,    65,
     119,  1648,  -339,     8,    51,  -339,   122,   892,  -339,     4,
    -339,   131,   122,  2160,  -339,   956,  -339,    62,  -339,   130,
    1001,  -339,   141,  1065,    97,   145,    10,    10,    10,   712,
      10,  -339,  -339,  -339,   128,   128,   195,  2246,   154,  -339,
     201,  2246,  2234,  2234,  2246,  2246,  2246,  2246,  2246,  2246,
    2246,  2246,  2246,  2246,  2246,  2246,   195,  2246,  2246,  2246,
    2246,  2246,  2246,  2246,  2246,  2246,  2246,  2246,  2246,  2246,
    2246,  -339,  -339,  -339,  -339,  -339,  -339,  -339,  -339,  -339,
    -339,  -339,  -339,  2246,  2246,  -339,  2246,  -339,  1065,  2246,
    2246,   162,  2246,   165,  1065,  2340,  2246,    38,   195,    39,
    -339,   169,  2246,   534,   195,    46,   128,  2001,  -339,  2246,
    -339,  2246,  1849,   188,  -339,   449,   128,   193,   712,  -339,
    -339,  1584,  2246,  -339,   177,   166,  -339,   204,    68,   205,
     181,   212,  2160,  1129,  1983,  1983,  1983,  1983,  1693,   738,
    2357,  1174,  1983,   272,   208,   272,    10,    10,    10,    10,
      10,  2060,   176,   176,  1983,  1983,  1983,  1983,    10,  1983,
    1584,  1584,  1584,  1584,  1889,  1925,   217,  1648,    46,   131,
    -339,    46,   131,    45,  -339,    24,  -339,    61,  2143,   171,
     134,  -339,  -339,   134,  -339,  -339,  1001,  1584,  -339,  1238,
    2246,  -339,     9,   128,  1584,  2234,  -339,  2234,   194,  2246,
    2234,  -339,  2234,   196,  2246,  2246,  -339,  1302,  -339,  1366,
     128,   221,   221,    46,   131,  2246,   225,  -339,  -339,   178,
     198,   124,  -339,   182,  2075,  -339,   251,  -339,   228,   206,
      15,   195,  -339,  -339,  -339,   233,  -339,   215,    16,   234,
     238,  -339,  -339,  1584,   234,   238,  -339,   519,  1584,  -339,
    -339,   134,    46,   222,   226,   221,  1430,   534,  -339,   150,
    -339,   200,  -339,   607,  -339,   245,  2246,  -339,    12,   254,
     256,    -3,  -339,   -21,  2246,  2246,    18,   236,  2246,   237,
     239,   241,   286,  -339,  -339,   242,   128,  -339,  -339,  -339,
    -339,   128,   195,   270,    28,  -339,  -339,  -339,   273,  -339,
    -339,   534,  2246,  1475,  1584,   274,  -339,  -339,  -339,  -339,
     279,  -339,   134,   134,   256,    30,  -339,   195,   278,     9,
    -339,  -339,  1539,  2246,   128,   229,  -339,  -339,   195,   256,
      31,  -339,  -339,   280,   534,  1584,   134,   281,  -339,   256,
    -339,   195,     9,  -339,  -339,   128,  -339,   256,   134,  -339,
    -339
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
     101,   175,   177,   178,   225,   144,   180,   179,   181,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    41,     0,     0,     0,   148,     0,     0,     0,
       0,     0,   182,   230,   228,   229,   101,     3,     5,    67,
      71,    72,    63,     0,    70,    69,    68,    65,    66,     0,
      73,    99,    97,    23,     0,   100,    98,    74,   224,    75,
      96,     0,    64,    62,   176,    30,     0,   185,   142,   174,
       4,   227,     0,    28,    39,     0,    43,   150,     0,     0,
      34,   152,    84,     0,     0,    77,   130,     0,    80,    78,
      82,    85,   132,   223,    42,     0,   191,     0,   155,     0,
     150,   184,     0,   150,     0,   147,   200,   201,   194,     0,
     202,     1,     2,   140,    22,    24,     0,     0,   141,   143,
       0,    31,   148,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,   145,     0,   226,     0,     0,
       0,     0,    44,     0,   152,     0,    35,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,   188,     0,
     192,     0,     0,   183,   186,     0,   103,     0,     0,   139,
     146,   149,     0,   156,   147,     0,   161,   127,   174,   147,
       0,   127,   221,     0,   219,   217,   218,   220,   222,   206,
     208,    60,   211,   196,   190,   195,   197,   203,   205,   204,
     199,   207,   209,   210,   213,   214,   215,   216,   198,   212,
      47,   193,    29,    40,     0,     0,     0,   151,     0,    86,
      76,     0,    88,     0,     9,   136,     8,     0,     0,     0,
       0,    79,    81,     0,   189,   154,     0,   153,    32,   149,
     148,   187,   125,   102,   159,   157,   165,   126,     0,     0,
     157,   169,   126,     0,     0,     0,    45,   149,    36,   151,
       0,   127,   127,     0,    89,     0,     0,   138,    12,     0,
      18,    21,    14,     0,   101,     7,    92,    33,   147,     0,
       0,     0,   115,   124,   110,   127,   113,     0,   104,   127,
     127,   160,   168,   158,   127,   127,   172,   131,    61,    46,
      37,     0,   126,     0,     0,   127,     0,     0,    13,    20,
      15,     0,    17,   101,    11,     0,   157,   173,     0,   127,
     127,   126,   111,     0,     0,     0,   126,     0,   126,     0,
       0,     0,    94,    87,    90,     0,     0,   137,    16,     6,
      10,     0,     0,   127,   126,   119,   126,   123,   127,   114,
     112,     0,     0,   105,   106,     0,   166,   167,   170,   171,
       0,    91,     0,     0,   127,   126,   116,     0,   127,   126,
     108,   128,     0,     0,     0,   133,    93,   117,     0,   127,
     126,   120,   109,   127,     0,   107,     0,     0,   135,   127,
     121,     0,   126,   129,    95,     0,   118,   127,     0,   122,
     134
  };

  const short
   Parser ::yypgoto_[] =
  {
    -339,  -339,   287,  -213,  -339,  -327,  -339,  -339,  -339,  -339,
    -264,  -339,  -339,  -339,  -339,   -18,  -339,  -339,  -339,  -339,
    -339,  -339,  -339,  -160,     5,  -178,    11,  -339,  -339,  -339,
    -339,  -339,  -339,  -339,  -305,  -339,   -59,  -179,  -338,  -339,
     -24,  -339,  -339,  -339,  -339,   -64,  -339,  -339,  -339,  -339,
    -339,   316,   186,   265,   155,  -339,  -115,  -268,  -122,  -339,
    -339,     2,    40,     0,   -29
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    36,    37,   305,   254,   255,   343,   256,   257,   258,
      38,    39,    40,    41,    42,    43,    79,    44,    45,    46,
      47,   164,    48,    49,    89,    90,    91,    84,    50,    51,
      52,    53,    54,    55,   312,   313,   314,   315,   316,   317,
     352,    56,    57,    58,    59,   297,    60,    61,    62,    63,
      64,   203,    65,    80,    98,    99,   205,   206,   207,    66,
      67,    77,    69,   260,    71
  };

  const short
   Parser ::yytable_[] =
  {
      70,   211,    68,     4,    94,   349,   350,   262,   210,   321,
     367,    73,    74,   380,   321,     4,    81,   184,     4,    87,
      83,     4,    93,   259,     4,    95,   100,   103,   381,   106,
     107,   108,   109,   110,     4,   116,     4,     4,    68,   177,
     344,   167,   113,   118,     4,     4,   379,   295,   296,   114,
     306,     4,     4,   115,   401,    85,     4,     4,    85,   310,
     311,     4,   382,   119,   178,   354,   348,   394,   178,   355,
     136,   310,   311,   139,   168,   372,   165,   103,   378,   370,
     174,   202,   179,   117,   380,   167,   167,   423,   321,   181,
     379,   397,   409,   408,   421,   248,   251,   175,   300,   121,
      88,    88,   293,   419,   120,   379,   122,    88,    88,   196,
      82,   180,  -163,   187,   123,   165,   427,   379,   362,   198,
     172,   279,   166,   201,    85,  -162,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   188,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   319,   262,   309,   197,   246,   324,   298,
     299,   166,   208,   208,  -162,   239,   240,   167,   241,   373,
     176,   242,   243,   182,   201,   194,   224,   259,   247,   405,
     406,   189,   185,   278,   201,    68,   263,   283,   249,   201,
     252,   266,   192,   267,   269,   398,   195,   201,   273,    76,
     253,     4,    86,   424,   274,    92,   190,   199,    33,   200,
      97,   102,   105,   244,    33,   430,   245,    85,   250,    85,
     413,   259,   340,   341,   261,    85,    34,    35,   275,   178,
     304,   167,    34,    35,   167,   135,   136,   137,   138,   139,
     140,   141,   142,   276,   167,   270,   287,   289,   -19,   -19,
     272,   301,   295,   417,   259,   277,   280,   150,   281,   291,
      68,   171,   292,   282,   294,  -164,   290,   333,   334,   302,
     303,   322,   332,   326,   337,   345,   338,   201,   339,   346,
     342,   323,   201,   347,   351,   356,   327,   328,    85,   358,
     331,    85,   353,    85,   371,   357,   359,   336,   368,   363,
     360,   361,   167,   364,   335,   374,    68,   376,   204,   209,
     390,   365,   318,   386,   387,   208,   388,   208,   389,   391,
     208,   395,   208,   112,   399,   375,   377,   279,   404,   410,
     425,   422,   136,    85,   138,   139,   140,   141,   142,    68,
     412,   418,   104,   173,   265,    68,     0,     0,   201,   396,
     318,   318,     0,   150,   400,     0,   383,   384,     0,     0,
     201,     0,     0,   167,   167,     0,   392,     0,     0,     0,
     407,   393,    85,     0,   411,     0,     0,     0,     0,     0,
       0,     0,     0,    68,   402,   420,     0,   167,   318,     0,
       0,   318,     0,     0,     0,   426,   385,     0,     0,   167,
       0,     0,     0,   429,   416,   415,     0,     0,     0,     0,
       0,     0,   318,     0,   318,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,   428,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   318,     0,   318,     0,   318,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
     318,     0,     1,     2,     3,     4,   308,     5,     6,     7,
       8,   318,   318,   320,     1,     2,     3,     4,   325,     5,
       6,     7,     8,     0,     0,     9,    10,     0,     0,    11,
       0,    12,     0,    13,     0,     0,     0,    20,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,    19,    20,
       0,    21,    22,     0,    23,    24,    72,    26,    27,     0,
      28,    29,     0,     0,     0,     0,    31,    24,    25,    26,
      27,     0,    28,    29,    32,    30,     0,   271,    31,     0,
       0,     0,     0,     0,     0,     0,    32,     1,     2,     3,
       4,    33,     5,     6,     7,     8,     0,     0,     9,    10,
       0,     0,    11,     0,    12,     0,    13,     0,     0,    34,
      35,     0,    15,    16,     0,    18,   131,   132,     0,     0,
       0,    19,    20,     0,    21,    22,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
      24,    25,    26,    27,     0,    28,    29,     0,     0,     0,
     150,    31,     0,     0,     0,     0,     0,     0,     0,    32,
       1,     2,     3,     4,    33,     5,     6,     7,     8,     0,
       0,     9,    10,     0,     0,    11,     0,    12,     0,    13,
       0,     0,    34,    35,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,    19,    20,     0,    21,    22,     0,
      23,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,     0,    24,    25,    26,    27,     0,    28,    29,
       0,    30,     0,     0,    31,     0,   125,     0,   126,   127,
     128,   129,    32,     0,     0,   130,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,     0,  -150,     0,  -150,
       0,   134,     0,     0,   369,   135,   136,   137,   138,   139,
     140,   141,   142,     0,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,   124,     0,     0,   150,     0,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   125,     0,   126,   127,   128,   129,   163,     0,
       0,   130,     0,     0,     0,     0,     0,     0,     0,   131,
     132,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,     0,    33,   150,     0,   124,     0,   135,   136,   137,
     138,   139,   140,   141,   142,     0,     0,   144,   145,     0,
      34,    35,     0,   125,   163,   126,   127,   128,   129,   150,
       0,     0,   130,     0,     0,     0,     0,     0,     0,     0,
     131,   132,     0,     0,   169,     0,     0,     0,   134,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,   146,   147,   148,   149,     0,   124,
       0,     0,     0,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   170,     0,   125,     0,   126,
     127,   128,   129,     0,     0,   163,   130,     0,     0,     0,
       0,     0,     0,     0,   131,   132,     0,     0,     0,     0,
       0,     0,   134,     0,   124,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,   146,   147,
     148,   149,   125,     0,   126,   127,   128,   129,   150,     0,
       0,   130,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   183,     0,     0,     0,     0,     0,   134,     0,   163,
       0,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,     0,   124,     0,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   126,   127,
     128,   129,     0,     0,   163,   130,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   186,     0,     0,     0,     0,
       0,   134,     0,   124,     0,   135,   136,   137,   138,   139,
     140,   141,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   125,     0,   126,   127,   128,   129,   150,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,   131,   132,
     191,     0,     0,     0,     0,     0,   134,     0,   163,     0,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,   146,   147,   148,   149,     0,   124,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,   126,   127,   128,
     129,     0,     0,   163,   130,     0,     0,     0,     0,     0,
       0,     0,   131,   132,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
       0,   124,   193,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,   284,     0,     0,     0,     0,     0,   125,
       0,   126,   127,   128,   129,     0,     0,   163,   130,     0,
       0,     0,     0,     0,     0,     0,   131,   132,     0,     0,
       0,     0,     0,     0,   134,     0,   124,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   125,     0,   126,   127,   128,   129,
     150,     0,     0,   130,     0,     0,     0,     0,     0,     0,
       0,   131,   132,     0,     0,     0,     0,   285,     0,   134,
       0,   163,     0,   135,   136,   137,   138,   139,   140,   141,
     142,     0,   143,   144,   145,   146,   147,   148,   149,     0,
     124,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
     126,   127,   128,   129,     0,     0,   163,   130,     0,     0,
       0,     0,     0,     0,     0,   131,   132,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,   135,   136,   137,
     138,   139,   140,   141,   142,     0,   143,   144,   145,   146,
     147,   148,   149,     0,   124,   307,     0,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,   126,   127,   128,   129,     0,     0,
     163,   130,     0,     0,     0,     0,     0,     0,     0,   131,
     132,     0,     0,     0,     0,     0,     0,   134,     0,     0,
       0,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,   149,     0,   124,   329,
       0,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   126,   127,
     128,   129,     0,     0,   163,   130,     0,     0,     0,     0,
       0,     0,     0,   131,   132,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,     0,   143,   144,   145,   146,   147,   148,
     149,     0,   124,   330,     0,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,   126,   127,   128,   129,     0,     0,   163,   130,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   366,
       0,     0,     0,     0,     0,   134,     0,   124,     0,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   125,     0,   126,   127,   128,
     129,   150,     0,     0,   130,     0,     0,     0,     0,     0,
       0,     0,   131,   132,     0,     0,     0,     0,   403,     0,
     134,     0,   163,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
       0,   124,     0,     0,     0,     0,   150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   126,   127,   128,   129,     0,     0,   163,   130,     0,
       0,     0,     0,     0,     0,     0,   131,   132,   414,     0,
       0,     0,     0,     0,   134,     0,   124,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   125,     0,   126,   127,   128,   129,
     150,     0,     0,   130,     0,     0,     0,     0,     0,     0,
       0,   131,   132,     0,     0,     0,     0,     0,     0,   134,
       0,   163,     0,   135,   136,   137,   138,   139,   140,   141,
     142,     0,   143,   144,   145,   146,   147,   148,   149,     0,
     124,     0,     0,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,   127,   128,   129,     0,     0,   163,   130,     0,     0,
       0,     0,     0,     0,     0,   131,   132,     0,     0,     0,
       0,     0,     0,   134,     0,   124,     0,   135,   136,   137,
     138,   139,   140,   141,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   125,     0,   126,   127,   128,   129,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   132,     0,     0,     0,     0,     0,     0,   134,     0,
     163,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,   111,     0,   150,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,   163,     0,     0,     0,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,    19,
      20,     0,    21,    22,     0,    23,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,    24,    25,
      26,    27,     0,    28,    29,     0,    30,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,    20,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      72,    26,    27,     0,    28,    29,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,    20,    32,     0,
     101,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,    24,    72,    26,    27,     0,
      28,    29,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,    32,     0,   268,    20,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    72,    26,    27,     0,
      28,    29,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,    20,    32,     0,   286,     0,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,    24,    72,    26,    27,     0,    28,    29,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
      32,     0,   288,    20,     1,     2,     3,     4,     0,     5,
       6,     7,     8,   125,     0,     0,     0,     0,     0,     0,
       0,    24,    72,    26,    27,     0,    28,    29,     0,     0,
     131,   132,    31,     0,     0,     0,     0,     0,     0,    20,
      32,    96,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,     0,     0,    24,    72,    26,
      27,     0,    28,    29,   150,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,    32,   264,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     9,
      10,     0,     0,    11,     0,    12,     0,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,   131,   132,     0,
       0,     0,    19,    20,     0,    21,    22,     0,    23,   135,
     136,   137,   138,   139,   140,   141,   142,     0,     0,   144,
     145,    24,    25,    26,    27,     0,    28,    29,     0,    30,
       0,   150,    31,     0,     0,     0,     1,     2,     3,     4,
      32,     5,     6,     7,     8,     0,     0,     9,    10,     0,
       0,    11,     0,    12,     0,    13,     0,     0,     0,     0,
       0,    15,    16,     0,    18,     0,     0,     0,     0,     0,
      19,    20,     0,    21,    22,     0,     0,     0,     0,     0,
     125,     0,   126,   127,   128,   129,     0,     0,     0,    24,
      25,    26,    27,     0,    28,    29,     0,   131,   132,     0,
      31,     0,     0,     0,     0,   134,     0,     0,    32,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,     0,     0,     1,     2,     3,
       4,   150,     5,     6,     7,     8,     0,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     1,     2,     3,     4,     0,
       5,     6,     7,     8,    20,     0,     0,     0,     0,     0,
      24,    72,    26,    27,     0,    28,    29,   202,     0,     0,
       0,    31,    24,    72,    26,    27,     0,    28,    29,    32,
      20,     0,     0,    31,     0,     0,     0,     1,     2,     3,
       4,    32,     5,     6,     7,     8,     0,     0,    24,    75,
      26,    27,     0,    28,    29,     0,     0,     0,     0,    31,
       0,     0,     0,     1,     2,     3,     4,    32,     5,     6,
       7,     8,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    78,    26,    27,     0,    28,    29,     0,    20,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
       0,    28,    29,     0,   131,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,    32,   135,   136,   137,   138,
     139,   140,   141,   142,     0,     0,   144,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   123,     0,     6,    22,   310,   311,   185,   123,   277,
     337,     9,    10,   351,   282,     6,    14,    13,     6,    17,
      15,     6,    20,   183,     6,    23,    24,    25,    49,    27,
      28,    29,    30,    31,     6,    21,     6,     6,    36,    31,
     304,    70,    53,    61,     6,     6,   351,    23,    24,    49,
     263,     6,     6,    53,   381,    15,     6,     6,    18,    62,
      63,     6,    83,     8,    60,    49,    51,   372,    60,    53,
      60,    62,    63,    63,    72,    63,     8,    75,    81,   343,
      78,    63,    31,    64,   422,   114,   115,   414,   356,    84,
     395,    63,   397,    63,    63,    57,    57,    32,   258,    51,
      62,    62,    57,   408,    64,   410,    57,    62,    62,   109,
      60,    60,    57,    51,    57,     8,   421,   422,   331,   117,
      51,    53,    54,   121,    84,    57,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,    76,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   275,   332,   270,   116,   175,   280,    98,
      99,    54,   122,   123,    57,   163,   164,   196,   166,   348,
      51,   169,   170,    51,   172,    78,   136,   337,   176,   392,
     393,    51,    51,   207,   182,   183,   186,   211,   177,   187,
     179,   189,    51,   191,   192,   374,    51,   195,   198,    13,
      31,     6,    16,   416,   202,    19,    76,    53,    80,     8,
      24,    25,    26,    51,    80,   428,    51,   177,   178,   179,
     399,   381,    98,    99,   184,   185,    98,    99,    51,    60,
      96,   260,    98,    99,   263,    59,    60,    61,    62,    63,
      64,    65,    66,    77,   273,    57,   244,   245,    98,    99,
      57,    80,    23,    24,   414,    51,    51,    81,    77,   248,
     258,    75,   251,    51,   253,    57,    49,   291,   292,    98,
      99,    77,    51,    77,    49,    24,    98,   275,    80,    51,
      98,   279,   280,    77,    51,    51,   284,   285,   248,    51,
     290,   251,    77,   253,    49,   319,   320,   295,    98,    77,
     324,   325,   331,    77,   293,    51,   304,    51,   122,   123,
      24,   335,   272,    77,    77,   275,    77,   277,    77,    77,
     280,    51,   282,    36,    51,   349,   350,    53,    49,    51,
      49,    51,    60,   293,    62,    63,    64,    65,    66,   337,
     399,   405,    26,    78,   189,   343,    -1,    -1,   346,   373,
     310,   311,    -1,    81,   378,    -1,   354,   355,    -1,    -1,
     358,    -1,    -1,   392,   393,    -1,   366,    -1,    -1,    -1,
     394,   371,   332,    -1,   398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   381,   382,   409,    -1,   416,   348,    -1,
      -1,   351,    -1,    -1,    -1,   419,   356,    -1,    -1,   428,
      -1,    -1,    -1,   427,   404,   403,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,   374,    -1,   414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   395,    -1,   397,    -1,   399,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,
     410,    -1,     3,     4,     5,     6,   270,     8,     9,    10,
      11,   421,   422,   277,     3,     4,     5,     6,   282,     8,
       9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    -1,    -1,    38,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    -1,    43,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    56,    57,    58,
      59,    -1,    61,    62,    75,    64,    -1,    78,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,     3,     4,     5,
       6,    80,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,    98,
      99,    -1,    28,    29,    -1,    31,    47,    48,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      81,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
       3,     4,     5,     6,    80,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,
      -1,    -1,    98,    99,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    64,    -1,    -1,    67,    -1,    30,    -1,    32,    33,
      34,    35,    75,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    51,    -1,    53,
      -1,    55,    -1,    -1,    97,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    12,    -1,    -1,    81,    -1,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    30,    -1,    32,    33,    34,    35,   102,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    81,    -1,    12,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    69,    70,    -1,
      98,    99,    -1,    30,   102,    32,    33,    34,    35,    81,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
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
      38,    -1,    40,    41,    -1,    43,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    38,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    38,    75,    -1,
      77,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
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
       9,    10,    11,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      47,    48,    67,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      75,    76,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    81,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    14,
      15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    47,    48,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    -1,    43,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    69,
      70,    56,    57,    58,    59,    -1,    61,    62,    -1,    64,
      -1,    81,    67,    -1,    -1,    -1,     3,     4,     5,     6,
      75,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    47,    48,    -1,
      67,    -1,    -1,    -1,    -1,    55,    -1,    -1,    75,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,     3,     4,     5,
       6,    81,     8,     9,    10,    11,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    38,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      -1,    67,    56,    57,    58,    59,    -1,    61,    62,    75,
      38,    -1,    -1,    67,    -1,    -1,    -1,     3,     4,     5,
       6,    75,     8,     9,    10,    11,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,     3,     4,     5,     6,    75,     8,     9,
      10,    11,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    61,    62,    -1,    38,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    47,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    27,    28,    29,    30,    31,    37,
      38,    40,    41,    43,    56,    57,    58,    59,    61,    62,
      64,    67,    75,    80,    98,    99,   105,   106,   114,   115,
     116,   117,   118,   119,   121,   122,   123,   124,   126,   127,
     132,   133,   134,   135,   136,   137,   145,   146,   147,   148,
     150,   151,   152,   153,   154,   156,   163,   164,   165,   166,
     167,   168,    57,   165,   165,    57,   156,   165,    57,   120,
     157,   165,    60,   128,   131,   166,   156,   165,    62,   128,
     129,   130,   156,   165,   119,   165,    76,   156,   158,   159,
     165,    77,   156,   165,   155,   156,   165,   165,   165,   165,
     165,     0,   106,    53,   167,   167,    21,    64,   119,     8,
     166,    51,    57,    57,    12,    30,    32,    33,    34,    35,
      39,    47,    48,    49,    55,    59,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    72,    73,    74,
      81,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   102,   125,     8,    54,   168,   165,    51,
      28,   156,    51,   157,   165,    32,    51,    31,    60,    31,
      60,   128,    51,    49,    13,    51,    49,    51,    76,    51,
      76,    49,    51,    77,    78,    51,   167,   166,   165,    53,
       8,   165,    63,   155,   156,   160,   161,   162,   166,   156,
     160,   162,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   166,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,    51,    51,   119,   165,    57,   130,
     166,    57,   130,    31,   108,   109,   111,   112,   113,   127,
     167,   166,   129,   167,    76,   158,   165,   165,    77,   165,
      57,    78,    57,   167,   165,    51,    77,    51,   144,    53,
      51,    77,    51,   144,    24,    53,    77,   165,    77,   165,
      49,   130,   130,    57,   130,    23,    24,   149,    98,    99,
     127,    80,    98,    99,    96,   107,   107,    77,   156,   160,
      62,    63,   138,   139,   140,   141,   142,   143,   166,   162,
     156,   161,    77,   165,   162,   156,    77,   165,   165,    77,
      77,   167,    51,   144,   144,   130,   165,    49,    98,    80,
      98,    99,    98,   110,   114,    24,    51,    77,    51,   138,
     138,    51,   144,    77,    49,    53,    51,   144,    51,   144,
     144,   144,   107,    77,    77,   144,    49,   109,    98,    97,
     114,    49,    63,   141,    51,   144,    51,   144,    81,   138,
     142,    49,    83,   165,   165,   166,    77,    77,    77,    77,
      24,    77,   167,   167,   138,    51,   144,    63,   141,    51,
     144,   109,   165,    53,    49,   107,   107,   144,    63,   138,
      51,   144,   140,   141,    49,   165,   167,    24,   149,   138,
     144,    63,    51,   109,   107,    49,   144,   138,   167,   144,
     107
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
     132,   132,   133,   133,   134,   134,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   138,   139,   139,
     139,   140,   140,   140,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   147,   148,   149,   149,   149,   150,   150,   150,   151,
     151,   152,   153,   154,   154,   154,   154,   155,   155,   156,
     156,   157,   157,   158,   159,   159,   160,   160,   161,   161,
     162,   162,   163,   163,   163,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   167,   167,   168,   168,
     168
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
       7,     8,     5,     9,     7,    11,     1,     1,     1,     1,
       1,     0,     4,     3,     1,     3,     3,     5,     4,     5,
       1,     2,     3,     1,     3,     1,     4,     5,     7,     3,
       5,     6,     8,     3,     1,     0,     1,     0,     8,    10,
       2,     5,     2,     5,     9,     6,     4,     7,     5,     3,
       2,     2,     1,     2,     1,     2,     3,     1,     0,     3,
       1,     3,     1,     3,     3,     1,     1,     2,     3,     2,
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
  "while_statement", "for_statement", "multi_line_statement",
  "decorators_opt", "decorators", "parameter", "parameter_list",
  "parameter_list_no_posonly", "defparameter_list",
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
       0,   295,   295,   296,   297,   301,   305,   309,   313,   314,
     318,   319,   323,   324,   325,   326,   329,   332,   338,   341,
     347,   350,   356,   357,   358,   363,   367,   371,   375,   376,
     380,   381,   382,   383,   387,   388,   389,   390,   394,   395,
     396,   400,   401,   406,   407,   408,   410,   416,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     435,   436,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   458,   459,   463,   464,
     465,   469,   470,   474,   475,   481,   482,   484,   486,   488,
     490,   492,   497,   498,   502,   504,   516,   517,   520,   525,
     529,   530,   534,   535,   539,   540,   541,   542,   546,   548,
     550,   554,   555,   557,   561,   562,   570,   571,   572,   574,
     575,   577,   579,   581,   585,   586,   590,   591,   595,   597,
     608,   612,   616,   620,   621,   623,   628,   631,   634,   639,
     640,   644,   649,   657,   658,   661,   664,   670,   671,   675,
     676,   689,   690,   699,   702,   703,   707,   708,   713,   714,
     718,   719,   724,   725,   726,   730,   731,   733,   735,   736,
     737,   739,   741,   748,   752,   753,   757,   758,   759,   763,
     764,   765,   766,   767,   768,   769,   771,   772,   773,   774,
     775,   777,   778,   782,   783,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   797,   798,   799,   800,
     801,   803,   804,   805,   806,   807,   808,   809,   810,   811,
     812,   814,   815,   816,   823,   828,   832,   833,   837,   838,
     839
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
#line 3661 "./parser.cpp"

#line 842 "parser.ypp"
