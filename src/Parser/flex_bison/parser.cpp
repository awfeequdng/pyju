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
#line 306 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1309 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 307 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1315 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 312 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1321 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 316 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1327 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 320 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1333 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 324 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1339 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 325 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1345 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 329 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1351 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 330 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1357 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 334 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1363 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 335 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1369 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 336 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1375 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 337 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1383 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 340 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1391 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 343 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1399 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 349 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1407 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 352 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1415 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 358 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1423 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 361 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1431 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 367 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1437 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 368 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1443 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 369 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1449 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 374 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1455 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 378 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1461 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 382 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1467 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 386 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1473 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 387 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1479 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 391 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1485 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 392 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1491 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 393 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1497 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 394 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1503 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 398 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1509 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 399 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1515 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 400 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1521 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 401 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1527 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 405 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1533 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 406 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1539 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 407 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1545 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 411 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1551 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 412 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1557 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 417 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1563 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 418 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1569 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 419 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1576 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 421 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1583 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 427 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1589 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 431 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1595 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 432 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1601 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 433 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1607 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 434 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1613 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 435 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1619 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 436 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1625 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 437 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1631 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 438 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1637 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 439 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1643 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 440 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1649 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 441 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1655 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 442 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1661 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 446 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1667 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 447 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1673 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 451 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1679 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 452 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1685 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 453 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1691 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 454 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1697 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 455 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1703 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 456 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1709 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 457 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1715 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 458 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1721 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 459 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1727 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 460 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1733 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 461 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1739 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 462 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1745 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 463 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1751 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 464 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1757 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 469 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1763 "./parser.cpp"
    break;

  case 77: // module: id
#line 470 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1769 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 474 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1775 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 475 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1781 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 476 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1787 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 480 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1793 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 481 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1799 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 485 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1805 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 486 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1811 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 492 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1817 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 493 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1824 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 495 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1831 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 497 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1838 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 499 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1845 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 501 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1852 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 503 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1859 "./parser.cpp"
    break;

  case 92: // while_statement: WHILE expr ":" sep statements
#line 508 "parser.ypp"
                                    { yylhs.value.as < Nonnull<Statement*> > () = WHILE_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1865 "./parser.cpp"
    break;

  case 93: // while_statement: WHILE expr ":" sep statements ELSE ":" sep statements
#line 509 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = WHILE_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1872 "./parser.cpp"
    break;

  case 94: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 513 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1879 "./parser.cpp"
    break;

  case 95: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 516 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1885 "./parser.cpp"
    break;

  case 96: // except_statement: EXCEPT ":" sep statements
#line 526 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_01(yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1891 "./parser.cpp"
    break;

  case 97: // except_statement: EXCEPT expr ":" sep statements
#line 527 "parser.ypp"
                                     { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_02(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1897 "./parser.cpp"
    break;

  case 98: // except_statement: EXCEPT expr AS id ":" sep statements
#line 528 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Statement*> > () = EXCEPT_03(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1903 "./parser.cpp"
    break;

  case 99: // except_list: except_list except_statement
#line 531 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1909 "./parser.cpp"
    break;

  case 100: // except_list: except_statement
#line 532 "parser.ypp"
                       { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1915 "./parser.cpp"
    break;

  case 101: // try_statement: TRY ":" sep statements except_list
#line 536 "parser.ypp"
                                         { yylhs.value.as < Nonnull<Statement*> > () = TRY_01(yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1921 "./parser.cpp"
    break;

  case 102: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements
#line 537 "parser.ypp"
                                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_02(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1928 "./parser.cpp"
    break;

  case 103: // try_statement: TRY ":" sep statements except_list FINALLY ":" sep statements
#line 539 "parser.ypp"
                                                                    {
        yylhs.value.as < Nonnull<Statement*> > () = TRY_03(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1935 "./parser.cpp"
    break;

  case 104: // try_statement: TRY ":" sep statements except_list ELSE ":" sep statements FINALLY ":" sep statements
#line 542 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = TRY_04(yystack_[9].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[8].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1941 "./parser.cpp"
    break;

  case 105: // try_statement: TRY ":" sep statements FINALLY ":" sep statements
#line 543 "parser.ypp"
                                                        { yylhs.value.as < Nonnull<Statement*> > () = TRY_05(yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1947 "./parser.cpp"
    break;

  case 106: // with_item: expr
#line 547 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1953 "./parser.cpp"
    break;

  case 107: // with_item: expr AS expr
#line 548 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = WITH_ITEM_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1959 "./parser.cpp"
    break;

  case 108: // with_item_list: with_item_list "," with_item
#line 552 "parser.ypp"
                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1965 "./parser.cpp"
    break;

  case 109: // with_item_list: with_item
#line 553 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1971 "./parser.cpp"
    break;

  case 110: // with_statement: WITH with_item_list ":" sep statements
#line 557 "parser.ypp"
                                             { yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1977 "./parser.cpp"
    break;

  case 111: // with_statement: WITH "(" with_item_list "," ")" ":" sep statements
#line 558 "parser.ypp"
                                                         {
        yylhs.value.as < Nonnull<Statement*> > () = WITH(yystack_[5].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1984 "./parser.cpp"
    break;

  case 112: // multi_line_statement: if_statement
#line 567 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1990 "./parser.cpp"
    break;

  case 113: // multi_line_statement: for_statement
#line 568 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1996 "./parser.cpp"
    break;

  case 114: // multi_line_statement: try_statement
#line 569 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2002 "./parser.cpp"
    break;

  case 115: // multi_line_statement: with_statement
#line 570 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2008 "./parser.cpp"
    break;

  case 116: // multi_line_statement: function_def
#line 571 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2014 "./parser.cpp"
    break;

  case 117: // multi_line_statement: class_def
#line 572 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2020 "./parser.cpp"
    break;

  case 118: // multi_line_statement: while_statement
#line 576 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 2026 "./parser.cpp"
    break;

  case 119: // decorators_opt: decorators
#line 580 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2032 "./parser.cpp"
    break;

  case 120: // decorators_opt: %empty
#line 581 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2038 "./parser.cpp"
    break;

  case 121: // decorators: decorators "@" expr sep
#line 585 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2044 "./parser.cpp"
    break;

  case 122: // decorators: "@" expr sep
#line 586 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2050 "./parser.cpp"
    break;

  case 123: // parameter: id
#line 590 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2056 "./parser.cpp"
    break;

  case 124: // parameter: id ":" expr
#line 591 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2062 "./parser.cpp"
    break;

  case 125: // parameter: id "=" expr
#line 592 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2068 "./parser.cpp"
    break;

  case 126: // parameter: id ":" expr "=" expr
#line 593 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2074 "./parser.cpp"
    break;

  case 127: // parameter_list: defparameter_list "," "/" comma_opt
#line 597 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2081 "./parser.cpp"
    break;

  case 128: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 599 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2088 "./parser.cpp"
    break;

  case 129: // parameter_list: parameter_list_no_posonly
#line 601 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 2094 "./parser.cpp"
    break;

  case 130: // parameter_list_no_posonly: defparameter_list comma_opt
#line 605 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 2100 "./parser.cpp"
    break;

  case 131: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 606 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2107 "./parser.cpp"
    break;

  case 132: // parameter_list_no_posonly: parameter_list_starargs
#line 608 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 2113 "./parser.cpp"
    break;

  case 133: // defparameter_list: defparameter_list "," parameter
#line 612 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2119 "./parser.cpp"
    break;

  case 134: // defparameter_list: parameter
#line 613 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 2125 "./parser.cpp"
    break;

  case 135: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 621 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2131 "./parser.cpp"
    break;

  case 136: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 622 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2137 "./parser.cpp"
    break;

  case 137: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 623 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2144 "./parser.cpp"
    break;

  case 138: // parameter_list_starargs: "*" parameter comma_opt
#line 625 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2150 "./parser.cpp"
    break;

  case 139: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 626 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 2157 "./parser.cpp"
    break;

  case 140: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 628 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2164 "./parser.cpp"
    break;

  case 141: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 630 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2171 "./parser.cpp"
    break;

  case 142: // parameter_list_starargs: "**" parameter comma_opt
#line 632 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 2177 "./parser.cpp"
    break;

  case 143: // parameter_list_opt: parameter_list
#line 636 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 2183 "./parser.cpp"
    break;

  case 144: // parameter_list_opt: %empty
#line 637 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 2189 "./parser.cpp"
    break;

  case 147: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 647 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2195 "./parser.cpp"
    break;

  case 148: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 649 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2201 "./parser.cpp"
    break;

  case 149: // class_def: decorators_opt CLASS id ":" sep statements
#line 660 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_01(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[3].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2208 "./parser.cpp"
    break;

  case 150: // class_def: decorators_opt CLASS id "(" expr_list_opt ")" ":" sep statements
#line 662 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_02(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2215 "./parser.cpp"
    break;

  case 151: // class_def: decorators_opt CLASS id "(" expr_list "," keyword_items ")" ":" sep statements
#line 665 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[6].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2221 "./parser.cpp"
    break;

  case 152: // class_def: decorators_opt CLASS id "(" keyword_items "," expr_list ")" ":" sep statements
#line 667 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = CLASS_03(yystack_[10].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[8].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2227 "./parser.cpp"
    break;

  case 153: // class_def: decorators_opt CLASS id "(" keyword_items ")" ":" sep statements
#line 668 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<Statement*> > () = CLASS_04(yystack_[8].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[6].value.as < Nonnull<Name*> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2234 "./parser.cpp"
    break;

  case 154: // global_statement: GLOBAL expr_list
#line 674 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2240 "./parser.cpp"
    break;

  case 155: // ternary_if_statement: expr IF expr ELSE expr
#line 678 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2246 "./parser.cpp"
    break;

  case 156: // nonlocal_statement: NONLOCAL expr_list
#line 682 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2252 "./parser.cpp"
    break;

  case 157: // elif_statement: ELIF expr ":" sep statements
#line 686 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 2258 "./parser.cpp"
    break;

  case 158: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 687 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2265 "./parser.cpp"
    break;

  case 159: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 689 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2272 "./parser.cpp"
    break;

  case 160: // if_statement: IF expr ":" body_stmts
#line 694 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2280 "./parser.cpp"
    break;

  case 161: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 697 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2288 "./parser.cpp"
    break;

  case 162: // if_statement: IF expr ":" body_stmts elif_statement
#line 700 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2295 "./parser.cpp"
    break;

  case 163: // target_list: target_list tuple_item "="
#line 705 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2301 "./parser.cpp"
    break;

  case 164: // target_list: tuple_item "="
#line 706 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2307 "./parser.cpp"
    break;

  case 165: // assignment_statement: target_list tuple_item
#line 710 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2313 "./parser.cpp"
    break;

  case 166: // expression_statment: expr
#line 715 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2319 "./parser.cpp"
    break;

  case 167: // string: string string_literal
#line 719 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2325 "./parser.cpp"
    break;

  case 168: // string: string_literal
#line 720 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2333 "./parser.cpp"
    break;

  case 169: // string: id string_literal
#line 723 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2341 "./parser.cpp"
    break;

  case 170: // string: string id string_literal
#line 726 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2349 "./parser.cpp"
    break;

  case 171: // expr_list_opt: expr_list
#line 732 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2355 "./parser.cpp"
    break;

  case 172: // expr_list_opt: %empty
#line 733 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2361 "./parser.cpp"
    break;

  case 173: // expr_list: expr_list "," expr
#line 737 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2367 "./parser.cpp"
    break;

  case 174: // expr_list: expr
#line 738 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2373 "./parser.cpp"
    break;

  case 175: // expr_for_list: expr_for_list "," expr
#line 751 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2379 "./parser.cpp"
    break;

  case 176: // expr_for_list: expr
#line 752 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2385 "./parser.cpp"
    break;

  case 177: // dict: expr ":" expr
#line 756 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2391 "./parser.cpp"
    break;

  case 178: // dict_list: dict_list "," dict
#line 759 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2397 "./parser.cpp"
    break;

  case 179: // dict_list: dict
#line 760 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2403 "./parser.cpp"
    break;

  case 180: // call_arguement_list: expr_list_opt
#line 764 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2409 "./parser.cpp"
    break;

  case 181: // call_arguement_list: expr_list ","
#line 765 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2415 "./parser.cpp"
    break;

  case 182: // keyword_item: id "=" expr
#line 770 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2421 "./parser.cpp"
    break;

  case 183: // keyword_item: "**" expr
#line 771 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2427 "./parser.cpp"
    break;

  case 184: // keyword_items: keyword_items "," keyword_item
#line 775 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2433 "./parser.cpp"
    break;

  case 185: // keyword_items: keyword_item
#line 776 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2439 "./parser.cpp"
    break;

  case 186: // primary: id
#line 781 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2445 "./parser.cpp"
    break;

  case 187: // primary: string
#line 782 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2451 "./parser.cpp"
    break;

  case 188: // primary: expr "." id
#line 783 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2457 "./parser.cpp"
    break;

  case 189: // function_call: primary "(" call_arguement_list ")"
#line 787 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2463 "./parser.cpp"
    break;

  case 190: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 788 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2470 "./parser.cpp"
    break;

  case 191: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 790 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2477 "./parser.cpp"
    break;

  case 192: // function_call: primary "(" keyword_items comma_opt ")"
#line 792 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2483 "./parser.cpp"
    break;

  case 193: // function_call: function_call "(" call_arguement_list ")"
#line 793 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2489 "./parser.cpp"
    break;

  case 194: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 794 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2496 "./parser.cpp"
    break;

  case 195: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 796 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2503 "./parser.cpp"
    break;

  case 196: // function_call: function_call "(" keyword_items comma_opt ")"
#line 798 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2509 "./parser.cpp"
    break;

  case 197: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 805 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2515 "./parser.cpp"
    break;

  case 198: // expr: id
#line 809 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2521 "./parser.cpp"
    break;

  case 199: // expr: integer_literal
#line 810 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2530 "./parser.cpp"
    break;

  case 200: // expr: string
#line 814 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2536 "./parser.cpp"
    break;

  case 201: // expr: real_literal
#line 815 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2542 "./parser.cpp"
    break;

  case 202: // expr: image_literal
#line 816 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2551 "./parser.cpp"
    break;

  case 203: // expr: TRUE
#line 820 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2557 "./parser.cpp"
    break;

  case 204: // expr: FALSE
#line 821 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2563 "./parser.cpp"
    break;

  case 205: // expr: NONE
#line 822 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2569 "./parser.cpp"
    break;

  case 206: // expr: "..."
#line 823 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2575 "./parser.cpp"
    break;

  case 207: // expr: "(" expr ")"
#line 824 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2581 "./parser.cpp"
    break;

  case 208: // expr: "(" ")"
#line 825 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2587 "./parser.cpp"
    break;

  case 209: // expr: function_call
#line 826 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2593 "./parser.cpp"
    break;

  case 210: // expr: "[" expr_list_opt "]"
#line 828 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2599 "./parser.cpp"
    break;

  case 211: // expr: "[" expr_list "," "]"
#line 829 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2605 "./parser.cpp"
    break;

  case 212: // expr: "{" expr_list "}"
#line 830 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2611 "./parser.cpp"
    break;

  case 213: // expr: "{" expr_list "," "}"
#line 831 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2617 "./parser.cpp"
    break;

  case 214: // expr: expr "." id
#line 832 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2623 "./parser.cpp"
    break;

  case 215: // expr: "{" "}"
#line 834 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2629 "./parser.cpp"
    break;

  case 216: // expr: "{" dict_list "}"
#line 835 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2635 "./parser.cpp"
    break;

  case 217: // expr: id ":=" expr
#line 839 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2641 "./parser.cpp"
    break;

  case 218: // expr: "*" expr
#line 840 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2647 "./parser.cpp"
    break;

  case 219: // expr: expr "+" expr
#line 842 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2653 "./parser.cpp"
    break;

  case 220: // expr: expr "-" expr
#line 843 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2659 "./parser.cpp"
    break;

  case 221: // expr: expr "*" expr
#line 844 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2665 "./parser.cpp"
    break;

  case 222: // expr: expr "/" expr
#line 845 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2671 "./parser.cpp"
    break;

  case 223: // expr: expr "%" expr
#line 846 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2677 "./parser.cpp"
    break;

  case 224: // expr: "-" expr
#line 847 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2683 "./parser.cpp"
    break;

  case 225: // expr: "+" expr
#line 848 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2689 "./parser.cpp"
    break;

  case 226: // expr: "~" expr
#line 849 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2695 "./parser.cpp"
    break;

  case 227: // expr: expr "**" expr
#line 850 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2701 "./parser.cpp"
    break;

  case 228: // expr: expr "//" expr
#line 851 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2707 "./parser.cpp"
    break;

  case 229: // expr: expr "@" expr
#line 852 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2713 "./parser.cpp"
    break;

  case 230: // expr: expr "&" expr
#line 854 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2719 "./parser.cpp"
    break;

  case 231: // expr: expr "|" expr
#line 855 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2725 "./parser.cpp"
    break;

  case 232: // expr: expr "^" expr
#line 856 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2731 "./parser.cpp"
    break;

  case 233: // expr: expr "<<" expr
#line 857 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2737 "./parser.cpp"
    break;

  case 234: // expr: expr ">>" expr
#line 858 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2743 "./parser.cpp"
    break;

  case 235: // expr: expr "==" expr
#line 860 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2749 "./parser.cpp"
    break;

  case 236: // expr: expr "!=" expr
#line 861 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2755 "./parser.cpp"
    break;

  case 237: // expr: expr "<" expr
#line 862 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2761 "./parser.cpp"
    break;

  case 238: // expr: expr "<=" expr
#line 863 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2767 "./parser.cpp"
    break;

  case 239: // expr: expr ">" expr
#line 864 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2773 "./parser.cpp"
    break;

  case 240: // expr: expr ">=" expr
#line 865 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2779 "./parser.cpp"
    break;

  case 241: // expr: expr "is" expr
#line 866 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2785 "./parser.cpp"
    break;

  case 242: // expr: expr "is not" expr
#line 867 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2791 "./parser.cpp"
    break;

  case 243: // expr: expr "in" expr
#line 868 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2797 "./parser.cpp"
    break;

  case 244: // expr: expr "not in" expr
#line 869 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2803 "./parser.cpp"
    break;

  case 245: // expr: expr "and" expr
#line 871 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2809 "./parser.cpp"
    break;

  case 246: // expr: expr "or" expr
#line 872 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2815 "./parser.cpp"
    break;

  case 247: // expr: "not" expr
#line 873 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2821 "./parser.cpp"
    break;

  case 248: // expr: "[" expr comp_for_items "]"
#line 876 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = LIST_COMP_1(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 2827 "./parser.cpp"
    break;

  case 249: // expr: "{" expr comp_for_items "}"
#line 877 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = SET_COMP_1(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 2833 "./parser.cpp"
    break;

  case 250: // expr: "{" expr ":" expr comp_for_items "}"
#line 878 "parser.ypp"
                                           { yylhs.value.as < Nonnull<Expression*> > () = DICT_COMP_1(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (), context.source_loc()); }
#line 2839 "./parser.cpp"
    break;

  case 251: // expr: ternary_if_statement
#line 880 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2845 "./parser.cpp"
    break;

  case 252: // id_list: id_list "," id
#line 886 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 2851 "./parser.cpp"
    break;

  case 253: // id_list: id
#line 887 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 2857 "./parser.cpp"
    break;

  case 254: // id_item: id_list
#line 891 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2863 "./parser.cpp"
    break;

  case 255: // id_item: id_list ","
#line 892 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2869 "./parser.cpp"
    break;

  case 256: // id_item: "(" id ")"
#line 893 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Name*> > (); }
#line 2875 "./parser.cpp"
    break;

  case 257: // id_item: "(" id_list "," ")"
#line 894 "parser.ypp"
                          { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2881 "./parser.cpp"
    break;

  case 258: // id_item: "(" id_list "," id ")"
#line 895 "parser.ypp"
                              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Name*> > ()), context.source_loc()); }
#line 2887 "./parser.cpp"
    break;

  case 259: // comp_for: FOR id_item "in" expr
#line 899 "parser.ypp"
                          { yylhs.value.as < Nonnull<Comprehension*> > () = COMP_FOR_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2893 "./parser.cpp"
    break;

  case 260: // comp_for: FOR id_item "in" expr IF expr
#line 900 "parser.ypp"
                                  {
        yylhs.value.as < Nonnull<Comprehension*> > () = COMP_FOR_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2900 "./parser.cpp"
    break;

  case 261: // comp_for_items: comp_for_items comp_for
#line 905 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Comprehension*>> > () = yystack_[1].value.as < std::vector<Nonnull<Comprehension*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > (), yystack_[0].value.as < Nonnull<Comprehension*> > ()); }
#line 2906 "./parser.cpp"
    break;

  case 262: // comp_for_items: comp_for
#line 906 "parser.ypp"
               { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Comprehension*>> > (), yystack_[0].value.as < Nonnull<Comprehension*> > ()); }
#line 2912 "./parser.cpp"
    break;

  case 263: // id: identifier
#line 910 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2918 "./parser.cpp"
    break;

  case 264: // sep: sep sep_one
#line 914 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2924 "./parser.cpp"
    break;

  case 265: // sep: sep_one
#line 915 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2930 "./parser.cpp"
    break;

  case 266: // sep_one: NEWLINE
#line 919 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2936 "./parser.cpp"
    break;

  case 267: // sep_one: COMMENT
#line 920 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2942 "./parser.cpp"
    break;

  case 268: // sep_one: ";"
#line 921 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2948 "./parser.cpp"
    break;


#line 2952 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -416;

  const short  Parser ::yytable_ninf_ = -189;

  const short
   Parser ::yypact_[] =
  {
     799,  -416,  -416,  -416,  -416,  -416,  -416,  -416,  -416,  2903,
    2903,  -416,  -416,  2946,  2971,    36,  2903,  2903,    18,  2903,
    2903,  -416,  2986,    29,  2903,  3046,  2570,  2419,  2903,  2903,
    2903,  2903,  2903,  2903,  -416,  -416,  -416,  -416,  2377,  -416,
    -416,  -416,  -416,  -416,  -416,    -4,  -416,  -416,  -416,  -416,
    -416,   183,  -416,  -416,  -416,  -416,  -416,   183,   182,    27,
    -416,  -416,  -416,  -416,  -416,  -416,  2986,  -416,  -416,    56,
      79,   110,   131,   984,    69,   183,  -416,  2419,  1279,  1343,
    2419,   144,  2189,  2419,   176,   165,  2298,  -416,    16,    30,
    -416,   172,  1388,  -416,    37,  -416,   185,   172,  2789,  -416,
     183,  1452,  2419,  -416,   123,  1497,  -416,   124,  -416,   153,
    1123,  -416,   200,  1561,   156,   207,  1625,   170,   170,   170,
    1050,   170,  -416,  -416,  -416,   183,   183,   256,   256,  2903,
     211,  -416,   258,  2903,  2863,  2863,  2903,  2903,  2903,  2903,
    2903,  2903,  2903,  2903,  2903,  2903,  2903,  2903,   256,  2903,
    2903,  2903,  2903,  2903,  2903,  2903,  2903,  2903,  2903,  2903,
    2903,  2903,  2903,  -416,  -416,  -416,  -416,  -416,  -416,  -416,
    -416,  -416,  -416,  -416,  -416,  2903,  2903,  -416,  2903,  -416,
    1561,  2903,  2903,   217,  2903,   226,  1561,  2986,  2903,    50,
     256,    52,  -416,    23,  2903,   872,   256,    18,   139,   183,
     236,  1168,   183,  2903,  2903,  2630,  -416,  2903,  -416,    49,
    2903,  -416,    41,  2445,   237,  -416,   704,    32,   183,   136,
     248,  1050,  -416,  -416,  2189,  2903,  -416,   255,   230,  -416,
     259,   171,   260,   232,   262,  2789,  1689,   184,   184,   184,
     184,   603,   662,   855,  1734,   184,   306,   264,   306,   170,
     170,   170,   170,   170,   525,   320,   320,   184,   184,   184,
     184,   170,   184,  2189,  2189,  2189,  2189,  2457,  2532,   263,
    2298,    18,   185,  -416,    18,   185,    59,  -416,   216,  -416,
     191,  2772,   187,   139,  -416,  -416,  2704,   267,   139,  2544,
     139,  -416,  2189,  -416,  -416,  1798,   256,   265,   285,  -416,
    1625,  -416,  -416,  -416,  1843,  2903,  -416,  -416,   183,  2863,
      31,   183,  2189,  2863,  -416,  2863,   241,  2903,  2863,  -416,
    2863,   246,  2903,  2903,  -416,  1907,  -416,  1971,   183,   275,
     275,    18,   185,  2903,   280,  -416,  -416,   233,   252,   199,
    -416,   235,  -416,   945,  -416,  2878,   287,  -416,   249,   313,
     289,  -416,  2903,   290,   266,   256,  2903,    92,  -416,   291,
     269,   139,   271,   298,    -8,   119,   256,  -416,  -416,  -416,
     300,  -416,   276,    84,   304,   308,  -416,  -416,  2189,   304,
     308,  -416,   425,  2189,  -416,  -416,   139,    18,   283,   284,
     275,  2035,   872,  -416,   201,  -416,   242,  -416,  -416,  -416,
     183,  1234,   183,   314,   315,  -416,   316,   183,  2189,    11,
    -416,  -416,  2253,  -416,  2903,  -416,  -416,   324,  2863,  2863,
     326,     4,   325,   339,     8,  -416,   -11,  2903,  2903,    35,
     321,  2903,   328,   331,   333,   353,  -416,  -416,   335,   183,
    -416,  -416,   139,   256,   183,   139,   183,   183,   183,   139,
    -416,   336,  2903,   183,    57,    73,   183,   256,   340,    38,
    -416,  -416,  -416,   341,  -416,  -416,   872,  2903,  2080,  2189,
     350,  -416,  -416,  -416,  -416,   344,  -416,   139,  -416,   365,
     139,  -416,   139,   139,   139,  -416,  -416,  1689,   139,    35,
     366,   368,   139,   339,    39,  -416,   256,   367,    31,  -416,
    -416,  2144,  2903,   183,   278,   183,  -416,   393,  -416,  -416,
    -416,   183,   183,  -416,  -416,   256,   339,    40,  -416,  -416,
     370,   872,  2189,   139,   373,  -416,   139,   375,   139,   139,
     339,  -416,   256,    31,  -416,  -416,   183,  -416,   183,  -416,
    -416,  -416,   339,   139,   139,  -416,  -416,  -416
  };

  const short
   Parser ::yydefact_[] =
  {
     120,   199,   201,   202,   263,   168,   204,   203,   205,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    41,     0,     0,     0,     0,     0,   172,     0,
       0,     0,     0,     0,   206,   268,   266,   267,   120,     3,
       5,    67,    71,    72,    63,     0,    70,    69,    68,    65,
      66,     0,    73,   118,   113,   114,   115,    23,     0,   119,
     116,   117,    74,   251,    75,   112,     0,    64,    62,   200,
      30,     0,   209,   166,   198,     4,   265,     0,    28,    39,
       0,    43,   174,     0,     0,    34,   176,    84,     0,     0,
      77,   154,     0,    80,    78,    82,    85,   156,   247,    42,
       0,     0,     0,   109,     0,   106,   215,     0,   179,     0,
     174,   208,     0,   174,     0,   171,   174,   224,   225,   218,
       0,   226,     1,     2,   164,    22,    24,     0,     0,     0,
     165,   167,     0,    31,   172,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,   169,     0,   264,
       0,     0,     0,     0,    44,     0,   176,     0,    35,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,   212,     0,   216,     0,
       0,   262,     0,     0,   207,   210,     0,     0,   122,     0,
       0,     0,   163,   170,   173,     0,   180,   171,     0,   185,
     146,   198,   171,     0,   146,   245,     0,   243,   241,   242,
     244,   246,   230,   232,    60,   235,   220,   214,   219,   221,
     227,   229,   228,   223,   231,   233,   234,   237,   238,   239,
     240,   222,   236,    47,   217,    29,    40,     0,     0,     0,
     175,     0,    86,    76,     0,    88,     0,     9,   160,     8,
       0,     0,     0,     0,    79,    81,   120,     0,     0,     0,
       0,   108,   107,   213,   178,     0,     0,   254,     0,   253,
     177,   249,   261,    32,   173,   172,   211,   248,     0,   172,
     144,   121,   183,   181,   189,   145,     0,     0,   181,   193,
     145,     0,     0,     0,    45,   173,    36,   175,     0,   146,
     146,     0,    89,     0,     0,   162,    12,     0,    18,    21,
      14,     0,     7,   120,    11,     0,     0,   100,   101,    92,
       0,   110,     0,     0,   253,   255,     0,     0,    33,   171,
       0,     0,     0,   171,     0,     0,     0,   134,   143,   129,
     146,   132,     0,   123,   146,   146,   184,   192,   182,   146,
     146,   196,   155,    61,    46,    37,     0,   145,     0,     0,
     146,     0,     0,    13,    20,    15,     0,    17,     6,    10,
       0,     0,     0,     0,     0,    99,     0,     0,   177,     0,
     256,   252,   259,   250,   181,   197,   149,     0,     0,     0,
       0,     0,   146,   146,   145,   130,     0,     0,     0,   145,
       0,   145,     0,     0,     0,    94,    87,    90,     0,     0,
     161,    16,     0,     0,     0,     0,     0,     0,     0,     0,
     257,   252,     0,     0,     0,     0,     0,     0,   146,   145,
     138,   145,   142,   146,   133,   131,     0,     0,   124,   125,
       0,   190,   191,   194,   195,     0,    91,     0,    96,     0,
       0,   105,     0,     0,     0,   111,   258,   260,     0,     0,
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
    -416,  -416,   319,   257,  -416,  -385,  -416,  -416,  -416,  -416,
    -238,  -416,  -416,  -416,  -416,   -14,  -416,  -416,  -416,  -416,
    -416,  -416,  -416,  -194,     6,  -193,  -105,  -416,  -416,  -416,
    -416,    77,  -416,  -416,  -190,   329,  -416,  -416,  -416,  -416,
    -237,  -416,   -72,  -406,  -415,  -416,  -119,  -416,  -416,  -416,
    -416,  -416,   -76,  -416,  -416,  -416,  -416,  -416,   -25,    47,
     349,   227,  -416,  -129,  -297,   -96,  -416,  -416,     2,   140,
    -416,  -192,  -111,   261,     0,   116
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    38,    39,   287,   277,   278,   343,   279,   280,   281,
      40,    41,    42,    43,    44,    45,    84,    46,    47,    48,
      49,   176,    50,    51,    94,    95,    96,    89,    52,    53,
      54,   347,   348,    55,   103,   104,    56,    57,    58,    59,
     367,   368,   369,   370,   371,   372,   425,    60,    61,    62,
      63,    64,   335,    65,    66,    67,    68,    69,   226,    70,
      85,   108,   109,   228,   229,   230,    71,    72,    82,   297,
     298,   211,   212,    74,   283,    76
  };

  const short
   Parser ::yytable_[] =
  {
      75,   282,    73,   114,   285,   217,   233,   440,    99,   465,
       4,    78,    79,   291,     4,   458,    86,     4,   376,    92,
     302,    88,    98,   376,     4,   302,   101,   105,   110,   113,
     116,   117,   118,   119,   120,   121,     4,     4,   466,   234,
      73,     4,     4,   419,     4,     4,     4,   189,   344,   124,
     196,   125,   130,   497,   276,     4,     4,   126,     4,   209,
      81,   191,     4,    91,   131,     4,    97,   457,   209,   420,
     365,   366,   467,   107,   112,   115,   190,   177,   100,   180,
      93,   500,   113,   190,   272,   186,   275,   338,   450,   463,
     192,   129,   520,   365,   366,   193,    87,   190,   225,   291,
     198,   496,   515,   532,   201,   399,   296,   271,   489,   274,
     307,   316,    93,  -187,    93,   321,   331,   301,   465,   209,
     218,    93,   376,   178,   194,     4,  -186,   183,   422,   423,
     133,   221,   376,   427,   490,   224,   534,   428,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     491,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   302,   329,   134,   413,   330,
     421,   332,   202,   269,   203,   205,   360,   262,   263,   177,
     264,   227,   232,   265,   266,   308,   224,   464,   135,   357,
     270,   179,   376,   309,   285,   184,   224,    73,   282,   288,
     206,   127,   290,   128,   207,   105,   292,   224,   187,   295,
     388,   389,   300,   364,   137,   304,   188,   374,   224,    35,
     493,   311,   379,   194,   317,   178,   390,   312,  -186,   208,
     148,   143,   144,   151,   215,   286,   197,    36,    37,   333,
     334,   179,   179,   147,   148,   149,   150,   151,   152,   153,
     154,   213,   155,   156,   157,   430,   432,   464,   216,   516,
     433,   434,     4,    35,   222,   162,   223,   339,   267,   325,
     327,   438,   282,   403,   345,   404,    90,   268,   530,    90,
     464,    36,    37,    73,   362,   340,   341,   289,    73,   336,
     337,   105,   345,   346,   305,   542,   464,   395,   396,   -19,
     -19,   333,   524,   460,   462,   310,   313,   314,   361,   319,
     315,   318,   328,   320,   179,   224,   355,   356,   377,   378,
     224,  -188,   454,   381,   382,   383,   387,   282,   386,   392,
     132,   393,   394,   397,   179,   391,   402,   406,   407,   495,
     441,   409,   414,   410,   499,    73,   415,   401,   417,   418,
      90,   424,   359,   426,   408,   429,   363,   123,   412,   431,
     436,   437,   375,   446,   447,   448,   148,   380,   150,   151,
     152,   153,   154,   453,   514,   456,   459,   475,   518,   147,
     148,   149,   150,   151,   152,   153,   154,   162,   219,   220,
     461,   494,   498,   503,    73,   231,   231,   531,   471,   179,
     442,   162,   445,   317,   179,   472,   179,   449,   473,   247,
     474,   541,   476,   486,   505,   511,   224,   512,   517,   527,
     224,   533,   536,   545,   538,   405,   519,   179,   525,   468,
     469,   200,   185,   224,   294,     0,   353,     0,     0,   477,
       0,     0,     0,     0,   480,     0,   482,   483,   484,     0,
      90,   273,    90,   488,   487,     0,   492,   284,    90,     0,
       0,     0,     0,     0,     0,     0,   455,     0,    73,   501,
     299,     0,   143,   144,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,     0,     0,     0,     0,
       0,     0,   179,   523,   522,   526,   162,     0,     0,     0,
       0,   528,   529,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,    90,   543,    90,   544,     0,
     342,     0,     0,     0,     0,   349,     0,   351,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   179,     0,
       0,   179,     0,     0,     0,   179,     0,     0,     0,     0,
     231,   373,   143,   144,   231,     0,   231,     0,     0,   231,
       0,   231,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,    90,   179,   156,   157,   179,     0,   179,   179,
     179,     0,     0,     0,   179,     0,   162,     0,   179,     0,
       0,     0,     0,     0,     0,   136,   411,     0,   416,     0,
       0,     0,     0,     0,     0,     0,   373,   373,     0,     0,
       0,     0,     0,   137,     0,   138,   139,   140,   141,   179,
       0,     0,   179,   435,   179,   179,     0,     0,    90,     0,
     143,   144,     0,     0,     0,     0,     0,     0,   146,   179,
     179,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     451,   155,   156,   157,   158,   159,   160,   161,     0,   231,
     231,     0,   373,     0,   162,   373,     0,     0,     0,     0,
     470,     0,     0,     0,     0,     0,     0,     0,     0,   478,
       0,     0,   481,     0,   479,   175,   485,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,   373,     0,
     373,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,   156,   157,     0,   504,     0,     0,   506,     0,   507,
     508,   509,    20,   162,     0,   510,     0,     0,     0,   513,
     470,     0,     0,     0,     0,   373,     0,   373,     0,   373,
      26,    77,    28,    29,     0,    30,    31,     0,     0,     0,
       0,    33,     0,     0,     0,     0,   373,     0,   373,    34,
     535,     0,   306,   537,     0,   539,   540,     0,     0,     0,
       0,     0,     0,   373,   373,     0,     0,     0,     0,     0,
     546,   547,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,    13,     0,     0,     0,     0,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,     0,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
      30,    31,     0,    32,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,    34,     1,     2,     3,     4,    35,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,    36,    37,     0,
      15,    16,   143,    18,     0,     0,     0,     0,     0,    19,
      20,     0,    21,    22,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,   156,   157,     0,     0,    26,    27,
      28,    29,     0,    30,    31,     0,   162,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,    34,     1,     2,
       3,     4,    35,     5,     6,     7,     8,     0,     0,     9,
      10,     0,     0,    11,     0,    12,     0,    13,     0,     0,
      36,    37,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,    19,    20,     0,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
       0,    26,    27,    28,    29,     0,    30,    31,     0,    32,
       0,     0,    33,     0,   137,     0,   138,   139,   140,   141,
      34,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   145,     0,  -174,     0,  -174,     0,   146,
       0,     0,   398,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,     0,
       0,     0,   136,     0,     0,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     137,     0,   138,   139,   140,   141,   175,     0,     0,   142,
       0,     0,     0,     0,     0,     0,     0,   143,   144,     0,
       0,     0,     0,     0,     0,   146,     0,     0,     0,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,     0,     0,     0,     0,     0,
      35,   162,     0,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
     209,     0,   175,   137,     0,   138,   139,   140,   141,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   210,     0,     0,     0,     0,     0,   146,     0,
     136,   204,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   156,   157,   158,   159,   160,   161,   137,     0,
     138,   139,   140,   141,   162,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,   143,   144,     0,     0,     0,
       0,     0,     0,   146,     0,   175,     0,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,     0,     0,   214,   136,   443,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,   138,   139,   140,   141,
     175,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   444,     0,     0,     0,     0,     0,   146,
       0,   136,     0,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   137,
       0,   138,   139,   140,   141,   162,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
     181,     0,     0,     0,   146,     0,   175,     0,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,     0,   136,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,     0,   137,     0,   138,   139,   140,   141,     0,
       0,   175,   142,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,     0,     0,     0,     0,     0,   146,     0,
     136,     0,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   156,   157,   158,   159,   160,   161,   137,     0,
     138,   139,   140,   141,   162,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   195,     0,     0,
       0,     0,     0,   146,     0,   175,     0,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,     0,   136,     0,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,   138,   139,   140,   141,     0,     0,
     175,   142,     0,     0,     0,     0,     0,     0,     0,   143,
     144,   199,     0,     0,     0,     0,     0,   146,     0,   136,
     204,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   137,     0,   138,
     139,   140,   141,   162,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,   143,   144,     0,     0,     0,     0,
       0,     0,   146,     0,   175,     0,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,     0,   136,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,     0,     0,   175,
     142,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,     0,     0,     0,     0,     0,   146,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
     156,   157,   158,   159,   160,   161,     0,   136,   214,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,     0,     0,   137,     0,   138,   139,   140,
     141,     0,     0,   175,   142,     0,     0,     0,     0,     0,
       0,     0,   143,   144,     0,     0,     0,     0,     0,     0,
     146,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
       0,   136,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,     0,     0,   175,   142,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
       0,     0,     0,     0,   146,     0,   136,     0,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   137,     0,   138,   139,   140,   141,
     162,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,   144,     0,     0,     0,     0,   323,     0,   146,
       0,   175,     0,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,     0,
     136,     0,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
     138,   139,   140,   141,     0,     0,   175,   142,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   352,     0,     0,
       0,     0,     0,   146,     0,   136,     0,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,   137,     0,   138,   139,   140,   141,   162,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,     0,     0,     0,     0,     0,   146,     0,
     175,     0,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   156,   157,   158,   159,   160,   161,     0,   136,
     358,     0,     0,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,   138,
     139,   140,   141,     0,     0,   175,   142,     0,     0,     0,
       0,     0,     0,     0,   143,   144,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,     0,   136,   384,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,     0,     0,   175,
     142,     0,     0,     0,     0,     0,     0,     0,   143,   144,
       0,     0,     0,     0,     0,     0,   146,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,     0,   155,
     156,   157,   158,   159,   160,   161,     0,   136,   385,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,   138,   139,   140,
     141,     0,     0,   175,   142,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   439,     0,     0,     0,     0,     0,
     146,     0,   136,     0,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     137,     0,   138,   139,   140,   141,   162,     0,     0,   142,
       0,     0,     0,     0,     0,     0,     0,   143,   144,     0,
       0,     0,     0,   502,     0,   146,     0,   175,     0,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,   158,   159,   160,   161,     0,   136,     0,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,   138,   139,   140,   141,
       0,     0,   175,   142,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   521,     0,     0,     0,     0,     0,   146,
       0,   136,     0,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   137,
       0,   138,   139,   140,   141,   162,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
       0,     0,     0,     0,   146,     0,   175,     0,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,     0,   136,     0,     0,     0,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   452,     0,   138,   139,   140,   141,     0,
       0,   175,   142,     0,     0,     0,     0,     0,     0,     0,
     143,   144,     0,     0,     0,     0,     0,     0,   146,     0,
     136,     0,   147,   148,   149,   150,   151,   152,   153,   154,
       0,   155,   156,   157,   158,   159,   160,   161,   137,     0,
       0,   139,   140,   141,   162,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,   143,   144,     0,     0,     0,
       0,     0,     0,   146,     0,   175,     0,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,     0,     0,     0,     0,   122,     0,   162,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     9,    10,     0,     0,    11,     0,    12,     0,    13,
     175,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,    19,    20,     0,    21,    22,    23,
      24,    25,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,    26,    27,    28,    29,     0,    30,    31,
       0,    32,     0,     0,    33,     0,     0,     0,     1,     2,
       3,     4,    34,     5,     6,     7,     8,    20,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,    26,    77,    28,    29,     0,
      30,    31,     0,    20,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,    34,    20,   111,     0,     0,     0,
       0,    26,    77,    28,    29,     0,    30,    31,     0,     0,
       0,     0,    33,    26,    77,    28,    29,     0,    30,    31,
      34,     0,   303,     0,    33,     0,     0,     0,     0,     0,
       0,     0,    34,     0,   324,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,    20,     0,     0,     0,     0,     0,    26,    77,
      28,    29,     0,    30,    31,     0,     0,     0,     0,    33,
      26,    77,    28,    29,     0,    30,    31,    34,    20,   326,
       0,    33,     0,     0,     0,     0,     0,     0,     0,    34,
       0,   350,     0,     0,     0,     0,    26,    77,    28,    29,
       0,    30,    31,     1,     2,     3,     4,    33,     5,     6,
       7,     8,     0,     0,     0,    34,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    77,    28,    29,
       0,    30,    31,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,    34,   293,     1,     2,     3,
       4,     0,     5,     6,     7,     8,     0,     0,     9,    10,
       0,     0,    11,     0,    12,     0,    13,     0,     0,     0,
       0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,    19,    20,     0,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    28,    29,     0,    30,    31,     0,    32,     0,
       0,    33,     0,     0,     0,     1,     2,     3,     4,    34,
       5,     6,     7,     8,     0,     0,     9,    10,     0,     0,
      11,     0,    12,     0,    13,     0,     0,     0,     0,     0,
      15,    16,     0,    18,     0,     0,     0,     0,     0,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,     0,     0,     0,    26,    27,
      28,    29,     0,    30,    31,     0,   143,   144,     0,    33,
       0,     0,     0,     0,   146,     0,     0,    34,   147,   148,
     149,   150,   151,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,     0,     0,     1,     2,     3,     4,
     162,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,    20,     0,     0,    26,
      77,    28,    29,     0,    30,    31,   225,   400,     0,     0,
      33,     0,     0,     0,    26,    77,    28,    29,    34,    30,
      31,    20,     0,     0,     0,    33,     0,     0,     0,     1,
       2,     3,     4,    34,     5,     6,     7,     8,     0,    26,
      77,    28,    29,     0,    30,    31,     0,     0,     0,     0,
      33,     0,     0,     0,     1,     2,     3,     4,    34,     5,
       6,     7,     8,     0,    20,     0,     0,     0,     0,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,    26,    80,    28,    29,     0,    30,    31,    20,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,    20,     0,     0,    26,    83,    28,
      29,     0,    30,    31,     0,     0,     0,     0,    33,     0,
       0,     0,    26,    27,    28,    29,    34,    30,    31,     1,
       2,     3,     4,    33,     5,     6,     7,     8,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,   102,    28,    29,     0,    30,    31,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    34
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   195,     0,    28,   197,   116,   135,   392,    22,   424,
       6,     9,    10,   203,     6,   421,    14,     6,   315,    17,
     212,    15,    20,   320,     6,   217,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     6,     6,    49,   135,
      38,     6,     6,    51,     6,     6,     6,    31,   286,    53,
      13,    51,    66,   459,    31,     6,     6,    57,     6,    27,
      13,    31,     6,    16,     8,     6,    19,    63,    27,    77,
      62,    63,    83,    26,    27,    28,    60,     8,    49,    77,
      62,   466,    80,    60,   189,    83,   191,   281,    77,    81,
      60,    64,   498,    62,    63,    89,    60,    60,    63,   289,
     100,    63,    63,    63,   102,   343,    57,    57,    51,    57,
      78,   230,    62,    57,    62,   234,    57,    76,   533,    27,
     120,    62,   419,    54,    51,     6,    57,    80,   365,   366,
      51,   129,   429,    49,    77,   133,   521,    53,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      77,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   357,   271,    57,    76,   274,
      51,   276,    49,   187,    51,    51,   305,   175,   176,     8,
     178,   134,   135,   181,   182,    49,   184,   424,    57,   300,
     188,    75,   489,    57,   387,    51,   194,   195,   392,   199,
      76,    19,   202,    21,    51,   203,   204,   205,    32,   207,
     329,   330,   210,   309,    30,   213,    51,   313,   216,    80,
     457,   221,   318,    51,    53,    54,   331,   225,    57,    76,
      60,    47,    48,    63,    78,    96,    51,    98,    99,    23,
      24,   125,   126,    59,    60,    61,    62,    63,    64,    65,
      66,    51,    68,    69,    70,   374,   375,   494,    51,   496,
     379,   380,     6,    80,    53,    81,     8,    80,    51,   267,
     268,   390,   466,    24,    25,    26,    15,    51,   515,    18,
     517,    98,    99,   281,   309,    98,    99,    51,   286,    98,
      99,   289,    25,    26,    57,   532,   533,    98,    99,    98,
      99,    23,    24,   422,   423,    57,    51,    77,   308,    77,
      51,    51,    49,    51,   198,   313,    51,    32,    77,   317,
     318,    57,   418,    77,   322,   323,    51,   521,   328,    49,
      69,    98,    80,    98,   218,   333,    49,    24,    49,   458,
      98,    51,    51,    77,   463,   343,    77,   345,    77,    51,
      89,    51,   305,    77,   352,    51,   309,    38,   356,    51,
      77,    77,   315,    49,    49,    49,    60,   320,    62,    63,
      64,    65,    66,    49,   493,    49,    51,    24,   497,    59,
      60,    61,    62,    63,    64,    65,    66,    81,   127,   128,
      51,    51,    51,    49,   392,   134,   135,   516,    77,   283,
     400,    81,   402,    53,   288,    77,   290,   407,    77,   148,
      77,   530,    77,    77,    49,    49,   414,    49,    51,    26,
     418,    51,    49,   542,    49,   348,   498,   311,   504,   427,
     428,   102,    83,   431,   207,    -1,   296,    -1,    -1,   439,
      -1,    -1,    -1,    -1,   444,    -1,   446,   447,   448,    -1,
     189,   190,   191,   453,   452,    -1,   456,   196,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   419,    -1,   466,   467,
     209,    -1,    47,    48,    -1,    -1,    -1,   361,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,   386,   503,   502,   505,    81,    -1,    -1,    -1,
      -1,   511,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   271,    -1,    -1,   274,   536,   276,   538,    -1,
     283,    -1,    -1,    -1,    -1,   288,    -1,   290,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,   442,    -1,
      -1,   445,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,
     309,   310,    47,    48,   313,    -1,   315,    -1,    -1,   318,
      -1,   320,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,   331,   477,    69,    70,   480,    -1,   482,   483,
     484,    -1,    -1,    -1,   488,    -1,    81,    -1,   492,    -1,
      -1,    -1,    -1,    -1,    -1,    12,   355,    -1,   361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   365,   366,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,   523,
      -1,    -1,   526,   386,   528,   529,    -1,    -1,   387,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,   543,
     544,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
     409,    68,    69,    70,    71,    72,    73,    74,    -1,   418,
     419,    -1,   421,    -1,    81,   424,    -1,    -1,    -1,    -1,
     429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,    -1,   445,    -1,   443,   102,   449,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,   457,    -1,
     459,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    69,    70,    -1,   477,    -1,    -1,   480,    -1,   482,
     483,   484,    38,    81,    -1,   488,    -1,    -1,    -1,   492,
     489,    -1,    -1,    -1,    -1,   494,    -1,   496,    -1,   498,
      56,    57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,   515,    -1,   517,    75,
     523,    -1,    78,   526,    -1,   528,   529,    -1,    -1,    -1,
      -1,    -1,    -1,   532,   533,    -1,    -1,    -1,    -1,    -1,
     543,   544,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,    80,
       8,     9,    10,    11,    -1,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    22,    -1,    -1,    98,    99,    -1,
      28,    29,    47,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    81,    -1,    -1,    67,
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
      80,    81,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
      27,    -1,   102,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      12,    13,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      32,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    12,    13,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
     102,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    12,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    32,    33,    34,    35,    81,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      51,    -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
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
      48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,    12,
      13,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    30,    -1,    32,
      33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    12,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,   102,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    12,    77,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    12,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    30,    -1,    32,    33,    34,    35,    81,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
     102,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    12,
      77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    12,    77,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    -1,    -1,   102,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    12,    77,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    12,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    53,    -1,    55,    -1,   102,    -1,    59,
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
      71,    72,    73,    74,    -1,    12,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      12,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    30,    -1,
      -1,    33,    34,    35,    81,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,     0,    -1,    81,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,
     102,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    64,    -1,    -1,    67,    -1,    -1,    -1,     3,     4,
       5,     6,    75,     8,     9,    10,    11,    38,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    38,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    38,    77,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    56,    57,    58,    59,    -1,    61,    62,
      75,    -1,    77,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    77,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    38,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      56,    57,    58,    59,    -1,    61,    62,    75,    38,    77,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    77,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,     3,     4,     5,     6,    67,     8,     9,
      10,    11,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    -1,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    40,    41,    42,    43,    44,    -1,
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
      -1,    -1,    56,    57,    58,    59,    75,    61,    62,     3,
       4,     5,     6,    67,     8,     9,    10,    11,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75
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
     163,   170,   171,   172,   177,   178,   179,    57,   172,   172,
      57,   163,   172,    57,   120,   164,   172,    60,   128,   131,
     177,   163,   172,    62,   128,   129,   130,   163,   172,   119,
      49,   172,    57,   138,   139,   172,    76,   163,   165,   166,
     172,    77,   163,   172,   162,   163,   172,   172,   172,   172,
     172,   172,     0,   106,    53,   178,   178,    19,    21,    64,
     119,     8,   177,    51,    57,    57,    12,    30,    32,    33,
      34,    35,    39,    47,    48,    49,    55,    59,    60,    61,
      62,    63,    64,    65,    66,    68,    69,    70,    71,    72,
      73,    74,    81,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   102,   125,     8,    54,   179,
     172,    51,    28,   163,    51,   164,   172,    32,    51,    31,
      60,    31,    60,   128,    51,    49,    13,    51,   178,    49,
     139,   172,    49,    51,    13,    51,    76,    51,    76,    27,
      49,   175,   176,    51,    77,    78,    51,   176,   178,   177,
     177,   172,    53,     8,   172,    63,   162,   163,   167,   168,
     169,   177,   163,   167,   169,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   177,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,    51,    51,   119,
     172,    57,   130,   177,    57,   130,    31,   108,   109,   111,
     112,   113,   127,   178,   177,   129,    96,   107,   178,    51,
     178,   138,   172,    76,   165,   172,    57,   173,   174,   177,
     172,    76,   175,    77,   172,    57,    78,    78,    49,    57,
      57,   178,   172,    51,    77,    51,   150,    53,    51,    77,
      51,   150,    24,    53,    77,   172,    77,   172,    49,   130,
     130,    57,   130,    23,    24,   156,    98,    99,   127,    80,
      98,    99,   107,   110,   114,    25,    26,   135,   136,   107,
      77,   107,    49,   173,   177,    51,    32,   176,    77,   163,
     167,   178,   162,   163,   169,    62,    63,   144,   145,   146,
     147,   148,   149,   177,   169,   163,   168,    77,   172,   169,
     163,    77,   172,   172,    77,    77,   178,    51,   150,   150,
     130,   172,    49,    98,    80,    98,    99,    98,    97,   114,
      49,   172,    49,    24,    26,   135,    24,    49,   172,    51,
      77,   177,   172,    76,    51,    77,   107,    77,    51,    51,
      77,    51,   144,   144,    51,   150,    77,    49,    53,    51,
     150,    51,   150,   150,   150,   107,    77,    77,   150,    49,
     109,    98,   178,    13,    49,   178,    49,    49,    49,   178,
      77,   177,    30,    49,   169,   163,    49,    63,   147,    51,
     150,    51,   150,    81,   144,   148,    49,    83,   172,   172,
     177,    77,    77,    77,    77,    24,    77,   178,   107,   177,
     178,   107,   178,   178,   178,   107,    77,   172,   178,    51,
      77,    77,   178,   144,    51,   150,    63,   147,    51,   150,
     109,   172,    53,    49,   107,    49,   107,   107,   107,   107,
     107,    49,    49,   107,   150,    63,   144,    51,   150,   146,
     147,    49,   172,   178,    24,   156,   178,    26,   178,   178,
     144,   150,    63,    51,   109,   107,    49,   107,    49,   107,
     107,   150,   144,   178,   178,   150,   107,   107
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
     172,   172,   173,   173,   174,   174,   174,   174,   174,   175,
     175,   176,   176,   177,   178,   178,   179,   179,   179
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
       6,     1,     3,     1,     1,     2,     3,     4,     5,     4,
       6,     2,     1,     1,     2,     1,     1,     1,     1
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
  "id_list", "id_item", "comp_for", "comp_for_items", "id", "sep",
  "sep_one", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,   306,   306,   307,   308,   312,   316,   320,   324,   325,
     329,   330,   334,   335,   336,   337,   340,   343,   349,   352,
     358,   361,   367,   368,   369,   374,   378,   382,   386,   387,
     391,   392,   393,   394,   398,   399,   400,   401,   405,   406,
     407,   411,   412,   417,   418,   419,   421,   427,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     446,   447,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   469,   470,   474,   475,
     476,   480,   481,   485,   486,   492,   493,   495,   497,   499,
     501,   503,   508,   509,   513,   515,   526,   527,   528,   531,
     532,   536,   537,   539,   541,   543,   547,   548,   552,   553,
     557,   558,   567,   568,   569,   570,   571,   572,   576,   580,
     581,   585,   586,   590,   591,   592,   593,   597,   599,   601,
     605,   606,   608,   612,   613,   621,   622,   623,   625,   626,
     628,   630,   632,   636,   637,   641,   642,   646,   648,   660,
     662,   664,   666,   668,   674,   678,   682,   686,   687,   689,
     694,   697,   700,   705,   706,   710,   715,   719,   720,   723,
     726,   732,   733,   737,   738,   751,   752,   756,   759,   760,
     764,   765,   770,   771,   775,   776,   781,   782,   783,   787,
     788,   790,   792,   793,   794,   796,   798,   805,   809,   810,
     814,   815,   816,   820,   821,   822,   823,   824,   825,   826,
     828,   829,   830,   831,   832,   834,   835,   839,   840,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     854,   855,   856,   857,   858,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   871,   872,   873,   876,   877,
     878,   880,   886,   887,   891,   892,   893,   894,   895,   899,
     900,   905,   906,   910,   914,   915,   919,   920,   921
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
#line 4165 "./parser.cpp"

#line 924 "parser.ypp"
