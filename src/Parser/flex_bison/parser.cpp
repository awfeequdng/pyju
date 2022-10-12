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
#line 294 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1219 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 295 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1225 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 300 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1231 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 304 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1237 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 308 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1243 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 312 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1249 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 313 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1255 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 317 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1261 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 318 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1267 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 322 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1273 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 323 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1279 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 324 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1285 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 325 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1293 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 328 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1301 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 331 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1309 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 337 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1317 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 340 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1325 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 346 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1333 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 349 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1341 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 355 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1347 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 356 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1353 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 357 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1359 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 362 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1365 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 366 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1371 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 370 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1377 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 374 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1383 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 375 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1389 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 379 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1395 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 380 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1401 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 381 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1407 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 382 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1413 "./parser.cpp"
    break;

  case 34: // for_tuple_item: expr_for_list
#line 386 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1419 "./parser.cpp"
    break;

  case 35: // for_tuple_item: expr_for_list ","
#line 387 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1425 "./parser.cpp"
    break;

  case 36: // for_tuple_item: "(" expr_for_list "," ")"
#line 388 "parser.ypp"
                                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_03(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1431 "./parser.cpp"
    break;

  case 37: // for_tuple_item: "(" expr_for_list "," expr ")"
#line 389 "parser.ypp"
                                      { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1437 "./parser.cpp"
    break;

  case 38: // raise_statement: RAISE
#line 393 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1443 "./parser.cpp"
    break;

  case 39: // raise_statement: RAISE expr
#line 394 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1449 "./parser.cpp"
    break;

  case 40: // raise_statement: RAISE expr FROM expr
#line 395 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1455 "./parser.cpp"
    break;

  case 41: // return_statement: RETURN
#line 399 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1461 "./parser.cpp"
    break;

  case 42: // return_statement: RETURN tuple_item
#line 400 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1467 "./parser.cpp"
    break;

  case 43: // delete_statement: DEL expr_list
#line 405 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1473 "./parser.cpp"
    break;

  case 44: // delete_statement: DEL expr_list ","
#line 406 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1479 "./parser.cpp"
    break;

  case 45: // delete_statement: DEL "(" expr_list "," ")"
#line 407 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1486 "./parser.cpp"
    break;

  case 46: // delete_statement: DEL "(" expr_list "," expr ")"
#line 409 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1493 "./parser.cpp"
    break;

  case 47: // augassign_statement: expr augassign_op expr
#line 415 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1499 "./parser.cpp"
    break;

  case 48: // augassign_op: "+="
#line 419 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1505 "./parser.cpp"
    break;

  case 49: // augassign_op: "-="
#line 420 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1511 "./parser.cpp"
    break;

  case 50: // augassign_op: "*="
#line 421 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1517 "./parser.cpp"
    break;

  case 51: // augassign_op: "/="
#line 422 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1523 "./parser.cpp"
    break;

  case 52: // augassign_op: "%="
#line 423 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1529 "./parser.cpp"
    break;

  case 53: // augassign_op: "&="
#line 424 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1535 "./parser.cpp"
    break;

  case 54: // augassign_op: "|="
#line 425 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1541 "./parser.cpp"
    break;

  case 55: // augassign_op: "^="
#line 426 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1547 "./parser.cpp"
    break;

  case 56: // augassign_op: "<<="
#line 427 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1553 "./parser.cpp"
    break;

  case 57: // augassign_op: ">>="
#line 428 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1559 "./parser.cpp"
    break;

  case 58: // augassign_op: "**="
#line 429 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1565 "./parser.cpp"
    break;

  case 59: // augassign_op: "//="
#line 430 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1571 "./parser.cpp"
    break;

  case 60: // ann_assignment_statement: expr ":" expr
#line 434 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (),context.source_loc()); }
#line 1577 "./parser.cpp"
    break;

  case 61: // ann_assignment_statement: expr ":" expr "=" expr
#line 435 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ANNASSIGN_02(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1583 "./parser.cpp"
    break;

  case 62: // single_line_statement: expression_statment
#line 439 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1589 "./parser.cpp"
    break;

  case 63: // single_line_statement: assert_statement
#line 440 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1595 "./parser.cpp"
    break;

  case 64: // single_line_statement: assignment_statement
#line 441 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1601 "./parser.cpp"
    break;

  case 65: // single_line_statement: augassign_statement
#line 442 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1607 "./parser.cpp"
    break;

  case 66: // single_line_statement: ann_assignment_statement
#line 443 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1613 "./parser.cpp"
    break;

  case 67: // single_line_statement: pass_statement
#line 444 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1619 "./parser.cpp"
    break;

  case 68: // single_line_statement: delete_statement
#line 445 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1625 "./parser.cpp"
    break;

  case 69: // single_line_statement: return_statement
#line 446 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1631 "./parser.cpp"
    break;

  case 70: // single_line_statement: raise_statement
#line 447 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1637 "./parser.cpp"
    break;

  case 71: // single_line_statement: break_statement
#line 448 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1643 "./parser.cpp"
    break;

  case 72: // single_line_statement: continue_statement
#line 449 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1649 "./parser.cpp"
    break;

  case 73: // single_line_statement: import_statement
#line 450 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1655 "./parser.cpp"
    break;

  case 74: // single_line_statement: global_statement
#line 451 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1661 "./parser.cpp"
    break;

  case 75: // single_line_statement: nonlocal_statement
#line 452 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1667 "./parser.cpp"
    break;

  case 76: // module: module "." id
#line 457 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1673 "./parser.cpp"
    break;

  case 77: // module: id
#line 458 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1679 "./parser.cpp"
    break;

  case 78: // module_as_id: module
#line 462 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1685 "./parser.cpp"
    break;

  case 79: // module_as_id: module AS id
#line 463 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1691 "./parser.cpp"
    break;

  case 80: // module_as_id: "*"
#line 464 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1697 "./parser.cpp"
    break;

  case 81: // module_item_list: module_item_list "," module_as_id
#line 468 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1703 "./parser.cpp"
    break;

  case 82: // module_item_list: module_as_id
#line 469 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1709 "./parser.cpp"
    break;

  case 83: // dot_list: dot_list "."
#line 473 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1715 "./parser.cpp"
    break;

  case 84: // dot_list: "."
#line 474 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1721 "./parser.cpp"
    break;

  case 85: // import_statement: IMPORT module_item_list
#line 480 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1727 "./parser.cpp"
    break;

  case 86: // import_statement: FROM module IMPORT module_item_list
#line 481 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1734 "./parser.cpp"
    break;

  case 87: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 483 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1741 "./parser.cpp"
    break;

  case 88: // import_statement: FROM dot_list IMPORT module_item_list
#line 485 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1748 "./parser.cpp"
    break;

  case 89: // import_statement: FROM dot_list module IMPORT module_item_list
#line 487 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1755 "./parser.cpp"
    break;

  case 90: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 489 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1762 "./parser.cpp"
    break;

  case 91: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 491 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1769 "./parser.cpp"
    break;

  case 92: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements
#line 497 "parser.ypp"
                                                          {
        yylhs.value.as < Nonnull<Statement*> > () = FOR_01(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1776 "./parser.cpp"
    break;

  case 93: // for_statement: FOR for_tuple_item "in" tuple_item ":" sep statements ELSE ":" sep statements
#line 500 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = FOR_02(yystack_[9].value.as < Nonnull<Expression*> > (), yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1782 "./parser.cpp"
    break;

  case 94: // multi_line_statement: if_statement
#line 511 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1788 "./parser.cpp"
    break;

  case 95: // multi_line_statement: for_statement
#line 512 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1794 "./parser.cpp"
    break;

  case 96: // multi_line_statement: function_def
#line 515 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1800 "./parser.cpp"
    break;

  case 97: // decorators_opt: decorators
#line 524 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1806 "./parser.cpp"
    break;

  case 98: // decorators_opt: %empty
#line 525 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1812 "./parser.cpp"
    break;

  case 99: // decorators: decorators "@" expr sep
#line 529 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1818 "./parser.cpp"
    break;

  case 100: // decorators: "@" expr sep
#line 530 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1824 "./parser.cpp"
    break;

  case 101: // parameter: id
#line 534 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1830 "./parser.cpp"
    break;

  case 102: // parameter: id ":" expr
#line 535 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1836 "./parser.cpp"
    break;

  case 103: // parameter: id "=" expr
#line 536 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1842 "./parser.cpp"
    break;

  case 104: // parameter: id ":" expr "=" expr
#line 537 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1848 "./parser.cpp"
    break;

  case 105: // parameter_list: defparameter_list "," "/" comma_opt
#line 541 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1855 "./parser.cpp"
    break;

  case 106: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 543 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1862 "./parser.cpp"
    break;

  case 107: // parameter_list: parameter_list_no_posonly
#line 545 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1868 "./parser.cpp"
    break;

  case 108: // parameter_list_no_posonly: defparameter_list comma_opt
#line 549 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1874 "./parser.cpp"
    break;

  case 109: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 550 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1881 "./parser.cpp"
    break;

  case 110: // parameter_list_no_posonly: parameter_list_starargs
#line 552 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1887 "./parser.cpp"
    break;

  case 111: // defparameter_list: defparameter_list "," parameter
#line 556 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1893 "./parser.cpp"
    break;

  case 112: // defparameter_list: parameter
#line 557 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1899 "./parser.cpp"
    break;

  case 113: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 565 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1905 "./parser.cpp"
    break;

  case 114: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 566 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1911 "./parser.cpp"
    break;

  case 115: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 567 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1918 "./parser.cpp"
    break;

  case 116: // parameter_list_starargs: "*" parameter comma_opt
#line 569 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1924 "./parser.cpp"
    break;

  case 117: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 570 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1931 "./parser.cpp"
    break;

  case 118: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 572 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1938 "./parser.cpp"
    break;

  case 119: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 574 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1945 "./parser.cpp"
    break;

  case 120: // parameter_list_starargs: "**" parameter comma_opt
#line 576 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1951 "./parser.cpp"
    break;

  case 121: // parameter_list_opt: parameter_list
#line 580 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1957 "./parser.cpp"
    break;

  case 122: // parameter_list_opt: %empty
#line 581 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1963 "./parser.cpp"
    break;

  case 125: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 591 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1969 "./parser.cpp"
    break;

  case 126: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 593 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1975 "./parser.cpp"
    break;

  case 127: // global_statement: GLOBAL expr_list
#line 603 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1981 "./parser.cpp"
    break;

  case 128: // ternary_if_statement: expr IF expr ELSE expr
#line 607 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1987 "./parser.cpp"
    break;

  case 129: // nonlocal_statement: NONLOCAL expr_list
#line 611 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1993 "./parser.cpp"
    break;

  case 130: // elif_statement: ELIF expr ":" sep statements
#line 615 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 1999 "./parser.cpp"
    break;

  case 131: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 616 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 2006 "./parser.cpp"
    break;

  case 132: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 618 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2013 "./parser.cpp"
    break;

  case 133: // if_statement: IF expr ":" body_stmts
#line 623 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2021 "./parser.cpp"
    break;

  case 134: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 626 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 2029 "./parser.cpp"
    break;

  case 135: // if_statement: IF expr ":" body_stmts elif_statement
#line 629 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 2036 "./parser.cpp"
    break;

  case 136: // target_list: target_list tuple_item "="
#line 634 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2042 "./parser.cpp"
    break;

  case 137: // target_list: tuple_item "="
#line 635 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 2048 "./parser.cpp"
    break;

  case 138: // assignment_statement: target_list tuple_item
#line 639 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2054 "./parser.cpp"
    break;

  case 139: // expression_statment: expr
#line 644 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2060 "./parser.cpp"
    break;

  case 140: // string: string string_literal
#line 652 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2066 "./parser.cpp"
    break;

  case 141: // string: string_literal
#line 653 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2074 "./parser.cpp"
    break;

  case 142: // string: id string_literal
#line 656 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2082 "./parser.cpp"
    break;

  case 143: // string: string id string_literal
#line 659 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2090 "./parser.cpp"
    break;

  case 144: // expr_list_opt: expr_list
#line 665 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2096 "./parser.cpp"
    break;

  case 145: // expr_list_opt: %empty
#line 666 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2102 "./parser.cpp"
    break;

  case 146: // expr_list: expr_list "," expr
#line 670 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2108 "./parser.cpp"
    break;

  case 147: // expr_list: expr
#line 671 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2114 "./parser.cpp"
    break;

  case 148: // expr_for_list: expr_for_list "," expr
#line 683 "parser.ypp"
                                       { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2120 "./parser.cpp"
    break;

  case 149: // expr_for_list: expr
#line 684 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2126 "./parser.cpp"
    break;

  case 150: // dict: expr ":" expr
#line 693 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2132 "./parser.cpp"
    break;

  case 151: // dict_list: dict_list "," dict
#line 696 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2138 "./parser.cpp"
    break;

  case 152: // dict_list: dict
#line 697 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2144 "./parser.cpp"
    break;

  case 153: // call_arguement_list: expr_list_opt
#line 701 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2150 "./parser.cpp"
    break;

  case 154: // call_arguement_list: expr_list ","
#line 702 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2156 "./parser.cpp"
    break;

  case 155: // keyword_item: id "=" expr
#line 707 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2162 "./parser.cpp"
    break;

  case 156: // keyword_item: "**" expr
#line 708 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2168 "./parser.cpp"
    break;

  case 157: // keyword_items: keyword_items "," keyword_item
#line 712 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2174 "./parser.cpp"
    break;

  case 158: // keyword_items: keyword_item
#line 713 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2180 "./parser.cpp"
    break;

  case 159: // primary: id
#line 718 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2186 "./parser.cpp"
    break;

  case 160: // primary: string
#line 719 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2192 "./parser.cpp"
    break;

  case 161: // primary: expr "." id
#line 720 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2198 "./parser.cpp"
    break;

  case 162: // function_call: primary "(" call_arguement_list ")"
#line 724 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2204 "./parser.cpp"
    break;

  case 163: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 725 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2211 "./parser.cpp"
    break;

  case 164: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 727 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2218 "./parser.cpp"
    break;

  case 165: // function_call: primary "(" keyword_items comma_opt ")"
#line 729 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2224 "./parser.cpp"
    break;

  case 166: // function_call: function_call "(" call_arguement_list ")"
#line 730 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2230 "./parser.cpp"
    break;

  case 167: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 731 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2237 "./parser.cpp"
    break;

  case 168: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 733 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2244 "./parser.cpp"
    break;

  case 169: // function_call: function_call "(" keyword_items comma_opt ")"
#line 735 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2250 "./parser.cpp"
    break;

  case 170: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 742 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2256 "./parser.cpp"
    break;

  case 171: // expr: id
#line 746 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2262 "./parser.cpp"
    break;

  case 172: // expr: integer_literal
#line 747 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2271 "./parser.cpp"
    break;

  case 173: // expr: string
#line 751 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2277 "./parser.cpp"
    break;

  case 174: // expr: real_literal
#line 752 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2283 "./parser.cpp"
    break;

  case 175: // expr: image_literal
#line 753 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2292 "./parser.cpp"
    break;

  case 176: // expr: TRUE
#line 757 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2298 "./parser.cpp"
    break;

  case 177: // expr: FALSE
#line 758 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2304 "./parser.cpp"
    break;

  case 178: // expr: NONE
#line 759 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2310 "./parser.cpp"
    break;

  case 179: // expr: "..."
#line 760 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2316 "./parser.cpp"
    break;

  case 180: // expr: "(" expr ")"
#line 761 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2322 "./parser.cpp"
    break;

  case 181: // expr: "(" ")"
#line 762 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2328 "./parser.cpp"
    break;

  case 182: // expr: function_call
#line 763 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2334 "./parser.cpp"
    break;

  case 183: // expr: "[" expr_list_opt "]"
#line 765 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2340 "./parser.cpp"
    break;

  case 184: // expr: "[" expr_list "," "]"
#line 766 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2346 "./parser.cpp"
    break;

  case 185: // expr: "{" expr_list "}"
#line 767 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2352 "./parser.cpp"
    break;

  case 186: // expr: "{" expr_list "," "}"
#line 768 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2358 "./parser.cpp"
    break;

  case 187: // expr: expr "." id
#line 769 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2364 "./parser.cpp"
    break;

  case 188: // expr: "{" "}"
#line 771 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2370 "./parser.cpp"
    break;

  case 189: // expr: "{" dict_list "}"
#line 772 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2376 "./parser.cpp"
    break;

  case 190: // expr: id ":=" expr
#line 776 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2382 "./parser.cpp"
    break;

  case 191: // expr: "*" expr
#line 777 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2388 "./parser.cpp"
    break;

  case 192: // expr: expr "+" expr
#line 779 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2394 "./parser.cpp"
    break;

  case 193: // expr: expr "-" expr
#line 780 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2400 "./parser.cpp"
    break;

  case 194: // expr: expr "*" expr
#line 781 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2406 "./parser.cpp"
    break;

  case 195: // expr: expr "/" expr
#line 782 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2412 "./parser.cpp"
    break;

  case 196: // expr: expr "%" expr
#line 783 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2418 "./parser.cpp"
    break;

  case 197: // expr: "-" expr
#line 784 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2424 "./parser.cpp"
    break;

  case 198: // expr: "+" expr
#line 785 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2430 "./parser.cpp"
    break;

  case 199: // expr: "~" expr
#line 786 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2436 "./parser.cpp"
    break;

  case 200: // expr: expr "**" expr
#line 787 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2442 "./parser.cpp"
    break;

  case 201: // expr: expr "//" expr
#line 788 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2448 "./parser.cpp"
    break;

  case 202: // expr: expr "@" expr
#line 789 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2454 "./parser.cpp"
    break;

  case 203: // expr: expr "&" expr
#line 791 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2460 "./parser.cpp"
    break;

  case 204: // expr: expr "|" expr
#line 792 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2466 "./parser.cpp"
    break;

  case 205: // expr: expr "^" expr
#line 793 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2472 "./parser.cpp"
    break;

  case 206: // expr: expr "<<" expr
#line 794 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2478 "./parser.cpp"
    break;

  case 207: // expr: expr ">>" expr
#line 795 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2484 "./parser.cpp"
    break;

  case 208: // expr: expr "==" expr
#line 797 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2490 "./parser.cpp"
    break;

  case 209: // expr: expr "!=" expr
#line 798 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2496 "./parser.cpp"
    break;

  case 210: // expr: expr "<" expr
#line 799 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2502 "./parser.cpp"
    break;

  case 211: // expr: expr "<=" expr
#line 800 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2508 "./parser.cpp"
    break;

  case 212: // expr: expr ">" expr
#line 801 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2514 "./parser.cpp"
    break;

  case 213: // expr: expr ">=" expr
#line 802 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2520 "./parser.cpp"
    break;

  case 214: // expr: expr "is" expr
#line 803 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2526 "./parser.cpp"
    break;

  case 215: // expr: expr "is not" expr
#line 804 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2532 "./parser.cpp"
    break;

  case 216: // expr: expr "in" expr
#line 805 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2538 "./parser.cpp"
    break;

  case 217: // expr: expr "not in" expr
#line 806 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2544 "./parser.cpp"
    break;

  case 218: // expr: expr "and" expr
#line 808 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2550 "./parser.cpp"
    break;

  case 219: // expr: expr "or" expr
#line 809 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2556 "./parser.cpp"
    break;

  case 220: // expr: "not" expr
#line 810 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2562 "./parser.cpp"
    break;

  case 221: // expr: ternary_if_statement
#line 817 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2568 "./parser.cpp"
    break;

  case 222: // id: identifier
#line 822 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2574 "./parser.cpp"
    break;

  case 223: // sep: sep sep_one
#line 826 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2580 "./parser.cpp"
    break;

  case 224: // sep: sep_one
#line 827 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2586 "./parser.cpp"
    break;

  case 225: // sep_one: NEWLINE
#line 831 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2592 "./parser.cpp"
    break;

  case 226: // sep_one: COMMENT
#line 832 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2598 "./parser.cpp"
    break;

  case 227: // sep_one: ";"
#line 833 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2604 "./parser.cpp"
    break;


#line 2608 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -327;

  const short  Parser ::yytable_ninf_ = -162;

  const short
   Parser ::yypact_[] =
  {
     463,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  2221,
    2221,  -327,  -327,  2247,  2289,    54,  2221,  2221,    21,  2221,
    2221,  -327,  2315,  1937,  1785,  2221,  2221,  2221,  2221,  2221,
    2221,  -327,  -327,  -327,  -327,  1710,  -327,  -327,  -327,  -327,
    -327,  -327,    -8,  -327,  -327,  -327,  -327,  -327,    97,  -327,
    -327,    97,    46,   -21,  -327,  -327,  -327,  -327,  -327,  2315,
    -327,  -327,    62,     4,    14,    19,   648,    51,    97,  -327,
    1785,   785,   849,  1785,    64,  1522,  1785,    53,    66,  1586,
    -327,    22,    38,  -327,   106,   894,  -327,   157,  -327,   128,
     106,  2135,  -327,  -327,     1,  -327,   125,   958,  -327,   133,
    1003,    89,   137,   123,   123,   123,   714,   123,  -327,  -327,
    -327,    97,    97,   168,  2221,   144,  -327,   184,  2221,  2209,
    2209,  2221,  2221,  2221,  2221,  2221,  2221,  2221,  2221,  2221,
    2221,  2221,  2221,   168,  2221,  2221,  2221,  2221,  2221,  2221,
    2221,  2221,  2221,  2221,  2221,  2221,  2221,  2221,  -327,  -327,
    -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,  -327,
    2221,  2221,  -327,  2221,  -327,  1003,  2221,  2221,   165,  2221,
     171,  1003,  2315,  2221,    50,   168,    56,  -327,    33,  2221,
     536,   168,    21,  1976,  -327,  2221,  -327,  2221,  1825,   151,
    -327,  1749,    97,   202,   714,  -327,  -327,  1522,  2221,  -327,
     209,   162,  -327,   210,   145,   212,   187,   214,  2135,  1067,
    1958,  1958,  1958,  1958,  1631,   519,   188,  1112,  1958,   163,
     211,   163,   123,   123,   123,   123,   123,   383,   357,   357,
    1958,  1958,  1958,  1958,   123,  1958,  1522,  1522,  1522,  1522,
    1861,  1901,   217,  1586,    21,   128,  -327,    21,   128,   116,
    -327,   182,  -327,   120,  2118,   132,   111,  -327,  -327,  -327,
    -327,   958,  1522,  -327,  1176,  2221,  -327,    27,    97,  1522,
    2209,  -327,  2209,   193,  2221,  2209,  -327,  2209,   194,  2221,
    2221,  -327,  1240,  -327,  1304,    97,   224,   224,    21,   128,
    2221,   230,  -327,  -327,   175,   204,   134,  -327,   189,  2050,
    -327,  -327,   238,   213,   160,   168,  -327,  -327,  -327,   240,
    -327,   218,    12,   243,   245,  -327,  -327,  1522,   243,   245,
    -327,   448,  1522,  -327,  -327,   111,    21,   220,   221,   224,
    1368,   536,  -327,   139,  -327,   201,  -327,   609,  -327,  2221,
    -327,    32,   251,   252,    11,  -327,   -25,  2221,  2221,    34,
     227,  2221,   228,   231,   233,   283,  -327,  -327,   235,    97,
    -327,  -327,  -327,  -327,   168,   262,    36,  -327,  -327,  -327,
     264,  -327,  -327,   536,  2221,  1413,  1522,   265,  -327,  -327,
    -327,  -327,   268,  -327,   111,   252,    40,  -327,   168,   269,
      27,  -327,  -327,  1477,  2221,    97,   222,  -327,   168,   252,
      41,  -327,  -327,   270,   536,  1522,   111,   274,  -327,   252,
    -327,   168,    27,  -327,  -327,    97,  -327,   252,   111,  -327,
    -327
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      98,   172,   174,   175,   222,   141,   177,   176,   178,     0,
      38,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    41,     0,     0,   145,     0,     0,     0,     0,
       0,   179,   227,   225,   226,    98,     3,     5,    67,    71,
      72,    63,     0,    70,    69,    68,    65,    66,     0,    73,
      95,    23,     0,    97,    96,    74,   221,    75,    94,     0,
      64,    62,   173,    30,     0,   182,   139,   171,     4,   224,
       0,    28,    39,     0,    43,   147,     0,     0,    34,   149,
      84,     0,     0,    77,   127,     0,    80,    78,    82,    85,
     129,   220,    42,   188,     0,   152,     0,   147,   181,     0,
     147,     0,   144,   197,   198,   191,     0,   199,     1,     2,
     137,    22,    24,     0,     0,   138,   140,     0,    31,   145,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,   142,     0,   223,     0,     0,     0,     0,    44,
       0,   149,     0,    35,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,   185,     0,   189,     0,     0,   180,
     183,     0,   100,     0,     0,   136,   143,   146,     0,   153,
     144,     0,   158,   124,   171,   144,     0,   124,   218,     0,
     216,   214,   215,   217,   219,   203,   205,    60,   208,   193,
     187,   192,   194,   200,   202,   201,   196,   204,   206,   207,
     210,   211,   212,   213,   195,   209,    47,   190,    29,    40,
       0,     0,     0,   148,     0,    86,    76,     0,    88,     0,
       9,   133,     8,     0,     0,     0,     0,    79,    81,   186,
     151,     0,   150,    32,   146,   145,   184,   122,    99,   156,
     154,   162,   123,     0,     0,   154,   166,   123,     0,     0,
       0,    45,   146,    36,   148,     0,   124,   124,     0,    89,
       0,     0,   135,    12,     0,    18,    21,    14,     0,    98,
       7,    33,   144,     0,     0,     0,   112,   121,   107,   124,
     110,     0,   101,   124,   124,   157,   165,   155,   124,   124,
     169,   128,    61,    46,    37,     0,   123,     0,     0,   124,
       0,     0,    13,    20,    15,     0,    17,    98,    11,   154,
     170,     0,   124,   124,   123,   108,     0,     0,     0,   123,
       0,   123,     0,     0,     0,    92,    87,    90,     0,     0,
     134,    16,     6,    10,     0,   124,   123,   116,   123,   120,
     124,   111,   109,     0,     0,   102,   103,     0,   163,   164,
     167,   168,     0,    91,     0,   124,   123,   113,     0,   124,
     123,   105,   125,     0,     0,     0,   130,   114,     0,   124,
     123,   117,   106,   124,     0,   104,     0,     0,   132,   124,
     118,     0,   123,   126,    93,     0,   115,   124,     0,   119,
     131
  };

  const short
   Parser ::yypgoto_[] =
  {
    -327,  -327,   284,  -318,  -327,  -323,  -327,  -327,  -327,  -327,
    -250,  -327,  -327,  -327,  -327,   -18,  -327,  -327,  -327,  -327,
    -327,  -327,  -327,  -170,    20,  -162,  -153,  -327,  -327,  -327,
    -327,  -327,  -327,   -64,  -327,   -65,  -186,  -326,  -327,    71,
    -327,  -327,  -327,  -327,   -70,  -327,  -327,  -327,  -327,  -327,
     303,   -10,   253,   146,  -327,  -115,  -238,  -119,  -327,  -327,
       2,    39,     0,   -32
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    35,    36,   300,   250,   251,   337,   252,   253,   254,
      37,    38,    39,    40,    41,    42,    77,    43,    44,    45,
      46,   161,    47,    48,    87,    88,    89,    82,    49,    50,
      51,    52,    53,   306,   307,   308,   309,   310,   311,   345,
      54,    55,    56,    57,   292,    58,    59,    60,    61,    62,
     199,    63,    78,    95,    96,   201,   202,   203,    64,    65,
      75,    67,   256,    69
  };

  const short
   Parser ::yytable_[] =
  {
      68,   207,    66,    74,    92,   206,    84,   355,   360,    90,
     255,    71,    72,    94,    99,   102,    79,     4,   372,    85,
     258,   245,    91,   248,   373,    97,   100,     4,   103,   104,
     105,   106,   107,     4,   315,    81,   164,    66,     4,   315,
       4,   115,     4,   114,     4,   110,     4,     4,   111,   338,
     392,   112,   183,   174,    83,   118,     4,    83,   374,   162,
       4,   347,     4,   168,   249,   348,   396,   113,     4,   176,
     116,   119,   165,   304,   305,   100,   120,   184,   171,   164,
     164,   413,   175,    86,   295,   172,   372,   363,   414,   304,
     305,   286,   370,   175,   287,   364,   289,   198,   177,   388,
     420,   117,   178,   398,   411,   163,   192,   244,  -159,   200,
     205,   315,    86,   247,    80,   169,   194,   173,    86,  -160,
     197,    83,     4,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   329,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     303,   313,   193,   162,   242,   365,   318,   179,   204,   204,
     164,   255,   235,   236,   258,   237,     4,   190,   238,   239,
     181,   197,   220,   288,     4,   243,   185,    32,    86,   182,
     389,   197,    66,   133,   188,   197,   136,   261,   191,   262,
     264,    32,   196,   197,   268,    33,    34,   195,   274,   163,
     269,   186,  -159,   255,   403,   290,   291,   299,   265,    33,
      34,   341,   296,    83,   246,    83,   240,   175,   293,   294,
     257,    83,   241,   133,   164,   135,   136,   137,   138,   139,
     297,   298,   334,   335,   255,   128,   164,   -19,   -19,   271,
     342,   343,   282,   284,   147,   290,   407,   132,   133,   134,
     135,   136,   137,   138,   139,   302,    66,   141,   142,   267,
     270,   272,   314,   275,   276,   277,   285,   319,  -161,   147,
     316,   320,   197,   332,   273,   326,   317,   197,   278,   331,
     371,   321,   322,    83,   333,   325,    83,   336,    83,   339,
     340,   344,   330,   164,   349,   346,   351,   356,   357,   361,
     385,    66,   366,   368,   378,   379,   312,   382,   380,   204,
     381,   204,   383,   386,   204,   390,   204,   395,   274,   109,
     400,   412,   371,   415,   399,   402,   408,    83,   101,   170,
       0,   260,     0,    66,   409,     0,   371,     0,     0,    66,
       0,   197,     0,   312,   312,     0,     0,   417,   371,   375,
     376,     0,   164,   197,     0,     0,     0,   327,   328,   384,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,   164,    66,   393,     0,     0,     0,
     312,     0,     0,   312,   350,   352,   164,     0,   377,   353,
     354,     0,     0,     0,     0,   406,   405,     0,     0,     0,
     358,     0,     0,   312,     0,   312,    66,     0,     0,     0,
       0,     0,     0,   367,   369,   418,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   312,     0,   312,     0,   312,
     128,   129,     0,     0,     0,     0,   387,   312,   147,   312,
       0,   391,   132,   133,   134,   135,   136,   137,   138,   139,
     312,   312,   141,   142,     0,     0,   397,     0,     0,     0,
     401,     0,     0,     0,   147,     0,     1,     2,     3,     4,
     410,     5,     6,     7,     8,     0,     0,     9,    10,     0,
     416,    11,     0,    12,     0,    13,     0,     0,   419,     0,
      14,    15,    16,    17,    18,   128,   129,     0,     0,     0,
      19,    20,     0,    21,    22,     0,     0,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,   141,   142,    23,
      24,    25,    26,     0,    27,    28,     0,    29,     0,   147,
      30,     0,     0,     0,     0,     0,     0,     0,    31,     1,
       2,     3,     4,    32,     5,     6,     7,     8,     0,     0,
       9,    10,     0,     0,    11,     0,    12,     0,    13,     0,
       0,    33,    34,     0,    15,    16,     0,    18,     0,     0,
       0,     0,     0,    19,    20,     0,    21,    22,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,   141,   142,
       0,     0,    23,    24,    25,    26,     0,    27,    28,     0,
     147,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    31,     1,     2,     3,     4,    32,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,    13,     0,     0,    33,    34,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    20,     0,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,     0,    23,    24,    25,    26,     0,
      27,    28,     0,    29,     0,     0,    30,     0,   122,     0,
     123,   124,   125,   126,    31,     0,     0,   127,     0,     0,
       0,     0,     0,     0,     0,   128,   129,   130,     0,  -147,
       0,  -147,     0,   131,     0,     0,   362,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   121,     0,     0,   147,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   122,     0,   123,   124,   125,   126,
     160,     0,     0,   127,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,   132,   133,   134,   135,   136,   137,   138,
     139,     0,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,     0,     0,    32,   147,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,     0,   122,   160,   123,   124,   125,
     126,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,   128,   129,     0,     0,   166,     0,     0,     0,
     131,     0,     0,     0,   132,   133,   134,   135,   136,   137,
     138,   139,     0,   140,   141,   142,   143,   144,   145,   146,
       0,   121,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,   122,
       0,   123,   124,   125,   126,     0,     0,   160,   127,     0,
       0,     0,     0,     0,     0,     0,   128,   129,     0,     0,
       0,     0,     0,     0,   131,     0,   121,     0,   132,   133,
     134,   135,   136,   137,   138,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   122,     0,   123,   124,   125,   126,
     147,     0,     0,   127,     0,     0,     0,     0,     0,     0,
       0,   128,   129,   180,     0,     0,     0,     0,     0,   131,
       0,   160,     0,   132,   133,   134,   135,   136,   137,   138,
     139,     0,   140,   141,   142,   143,   144,   145,   146,     0,
     121,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     123,   124,   125,   126,     0,     0,   160,   127,     0,     0,
       0,     0,     0,     0,     0,   128,   129,   187,     0,     0,
       0,     0,     0,   131,     0,   121,     0,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   122,     0,   123,   124,   125,   126,   147,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,   131,     0,
     160,     0,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,   141,   142,   143,   144,   145,   146,     0,   121,
     189,     0,     0,     0,   147,     0,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,     0,   122,     0,   123,
     124,   125,   126,     0,     0,   160,   127,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,   131,     0,   121,     0,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   122,     0,   123,   124,   125,   126,   147,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,   128,
     129,     0,     0,     0,     0,   280,     0,   131,     0,   160,
       0,   132,   133,   134,   135,   136,   137,   138,   139,     0,
     140,   141,   142,   143,   144,   145,   146,     0,   121,     0,
       0,     0,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,   123,   124,
     125,   126,     0,     0,   160,   127,     0,     0,     0,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,     0,
       0,   131,     0,     0,     0,   132,   133,   134,   135,   136,
     137,   138,   139,     0,   140,   141,   142,   143,   144,   145,
     146,     0,   121,   301,     0,     0,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     122,     0,   123,   124,   125,   126,     0,     0,   160,   127,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     0,   132,
     133,   134,   135,   136,   137,   138,   139,     0,   140,   141,
     142,   143,   144,   145,   146,     0,   121,   323,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,   123,   124,   125,   126,
       0,     0,   160,   127,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,   132,   133,   134,   135,   136,   137,   138,
     139,     0,   140,   141,   142,   143,   144,   145,   146,     0,
     121,   324,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     123,   124,   125,   126,     0,     0,   160,   127,     0,     0,
       0,     0,     0,     0,     0,   128,   129,   359,     0,     0,
       0,     0,     0,   131,     0,   121,     0,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   122,     0,   123,   124,   125,   126,   147,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,   394,     0,   131,     0,
     160,     0,   132,   133,   134,   135,   136,   137,   138,   139,
       0,   140,   141,   142,   143,   144,   145,   146,     0,   121,
       0,     0,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,   123,
     124,   125,   126,     0,     0,   160,   127,     0,     0,     0,
       0,     0,     0,     0,   128,   129,   404,     0,     0,     0,
       0,     0,   131,     0,   121,     0,   132,   133,   134,   135,
     136,   137,   138,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   122,     0,   123,   124,   125,   126,   147,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,   128,
     129,     0,     0,     0,     0,     0,     0,   131,     0,   160,
       0,   132,   133,   134,   135,   136,   137,   138,   139,     0,
     140,   141,   142,   143,   144,   145,   146,     0,   121,     0,
       0,     0,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,   124,
     125,   126,     0,     0,   160,   127,     0,     0,     0,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,     0,
       0,   131,     0,   121,     0,   132,   133,   134,   135,   136,
     137,   138,   139,     0,   140,   141,   142,   143,   144,   145,
     146,   122,     0,   123,   124,   125,   126,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,   131,     0,   160,     0,
     132,   133,   134,   135,   136,   137,   138,   139,     0,   140,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
     108,     0,   147,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     9,    10,     0,     0,    11,     0,
      12,     0,    13,   160,     0,     0,     0,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,    19,    20,     0,
      21,    22,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,    23,    24,    25,    26,
       0,    27,    28,     0,    29,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,    31,     0,    20,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    70,    25,    26,     0,
      27,    28,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,    20,    31,     0,     0,   266,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,    23,    70,    25,    26,     0,    27,    28,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
      31,     0,    98,    20,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    70,    25,    26,     0,    27,    28,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    20,
      31,     0,   263,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,    23,    70,    25,
      26,     0,    27,    28,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,    31,     0,   281,    20,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    70,    25,
      26,     0,    27,    28,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    20,    31,     0,   283,     1,
       2,     3,     4,     0,     5,     6,     7,     8,   122,     0,
       0,     0,     0,    23,    70,    25,    26,     0,    27,    28,
       0,     0,     0,     0,    30,   128,   129,     0,     0,     0,
       0,     0,    31,    93,    20,     0,     0,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,   141,   142,     0,
       0,     0,    23,    70,    25,    26,     0,    27,    28,   147,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    31,   259,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     9,    10,     0,     0,    11,     0,
      12,     0,    13,     0,     0,     0,     0,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,    19,    20,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
       0,    27,    28,     0,    29,     0,     0,    30,     0,     0,
       0,     1,     2,     3,     4,    31,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,     0,     0,     0,     0,     0,    15,    16,     0,    18,
       0,     0,     0,     0,     0,    19,    20,     0,    21,    22,
       0,     0,     0,     0,     0,   122,     0,   123,   124,   125,
     126,     0,     0,     0,    23,    24,    25,    26,     0,    27,
      28,     0,   128,   129,     0,    30,     0,     0,     0,     0,
     131,     0,     0,    31,   132,   133,   134,   135,   136,   137,
     138,   139,     0,   140,   141,   142,   143,   144,   145,   146,
       0,     0,     1,     2,     3,     4,   147,     5,     6,     7,
       8,     0,     0,     0,     1,     2,     3,     4,     0,     5,
       6,     7,     8,     0,     0,     0,     0,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       1,     2,     3,     4,     0,     5,     6,     7,     8,    20,
       0,     0,     0,     0,     0,    23,    70,    25,    26,     0,
      27,    28,   198,     0,     0,     0,    30,    23,    70,    25,
      26,     0,    27,    28,    31,    20,     0,     0,    30,     0,
       0,     0,     1,     2,     3,     4,    31,     5,     6,     7,
       8,     0,     0,    23,    73,    25,    26,     0,    27,    28,
       0,     0,     0,     0,    30,     0,     0,     0,     1,     2,
       3,     4,    31,     5,     6,     7,     8,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    76,    25,    26,     0,
      27,    28,     0,    20,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,     0,    27,    28,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
      31
  };

  const short
   Parser ::yycheck_[] =
  {
       0,   120,     0,    13,    22,   120,    16,   325,   331,    19,
     180,     9,    10,    23,    24,    25,    14,     6,   344,    17,
     182,   174,    20,   176,    49,    23,    24,     6,    26,    27,
      28,    29,    30,     6,   272,    15,    68,    35,     6,   277,
       6,    59,     6,    64,     6,    53,     6,     6,    48,   299,
     373,    51,    51,    31,    15,    51,     6,    18,    83,     8,
       6,    49,     6,    73,    31,    53,   384,    21,     6,    31,
       8,    57,    70,    62,    63,    73,    57,    76,    76,   111,
     112,   404,    60,    62,   254,    32,   412,   337,   406,    62,
      63,   244,    81,    60,   247,    63,   249,    63,    60,    63,
     418,    62,    82,    63,    63,    54,   106,    57,    57,   119,
     120,   349,    62,    57,    60,    51,   114,    51,    62,    57,
     118,    82,     6,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   288,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     265,   270,   113,     8,   172,   341,   275,    51,   119,   120,
     192,   331,   160,   161,   326,   163,     6,    78,   166,   167,
      13,   169,   133,    57,     6,   173,    51,    80,    62,    51,
     366,   179,   180,    60,    51,   183,    63,   185,    51,   187,
     188,    80,     8,   191,   194,    98,    99,    53,    53,    54,
     198,    76,    57,   373,   390,    23,    24,    96,    57,    98,
      99,    51,    80,   174,   175,   176,    51,    60,    98,    99,
     181,   182,    51,    60,   256,    62,    63,    64,    65,    66,
      98,    99,    98,    99,   404,    47,   268,    98,    99,    77,
     304,   305,   240,   241,    81,    23,    24,    59,    60,    61,
      62,    63,    64,    65,    66,   265,   254,    69,    70,    57,
      51,    51,   272,    51,    77,    51,    49,   277,    57,    81,
      77,    77,   270,    98,   203,    51,   274,   275,   207,    49,
     344,   279,   280,   244,    80,   285,   247,    98,   249,    51,
      77,    51,   290,   325,    51,    77,    51,    77,    77,    98,
     364,   299,    51,    51,    77,    77,   267,    24,    77,   270,
      77,   272,    77,    51,   275,    51,   277,    49,    53,    35,
      51,    51,   386,    49,   388,   390,   396,   288,    25,    76,
      -1,   185,    -1,   331,   398,    -1,   400,    -1,    -1,   337,
      -1,   339,    -1,   304,   305,    -1,    -1,   411,   412,   347,
     348,    -1,   384,   351,    -1,    -1,    -1,   286,   287,   359,
      -1,    -1,    -1,    -1,    -1,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   406,   373,   374,    -1,    -1,    -1,
     341,    -1,    -1,   344,   313,   314,   418,    -1,   349,   318,
     319,    -1,    -1,    -1,    -1,   395,   394,    -1,    -1,    -1,
     329,    -1,    -1,   364,    -1,   366,   404,    -1,    -1,    -1,
      -1,    -1,    -1,   342,   343,   415,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,   386,    -1,   388,    -1,   390,
      47,    48,    -1,    -1,    -1,    -1,   365,   398,    81,   400,
      -1,   370,    59,    60,    61,    62,    63,    64,    65,    66,
     411,   412,    69,    70,    -1,    -1,   385,    -1,    -1,    -1,
     389,    -1,    -1,    -1,    81,    -1,     3,     4,     5,     6,
     399,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
     409,    18,    -1,    20,    -1,    22,    -1,    -1,   417,    -1,
      27,    28,    29,    30,    31,    47,    48,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    56,
      57,    58,    59,    -1,    61,    62,    -1,    64,    -1,    81,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,     3,
       4,     5,     6,    80,     8,     9,    10,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,
      -1,    98,    99,    -1,    28,    29,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    69,    70,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      81,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,     3,     4,     5,     6,    80,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    22,    -1,    -1,    98,    99,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    30,    -1,
      32,    33,    34,    35,    75,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    51,
      -1,    53,    -1,    55,    -1,    -1,    97,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    12,    -1,    -1,    81,
      -1,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    30,    -1,    32,    33,    34,    35,
     102,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    30,   102,    32,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    12,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    32,    33,    34,    35,    -1,    -1,   102,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    12,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    30,    -1,    32,    33,    34,    35,
      81,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,
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
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    12,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    30,    -1,    32,    33,    34,    35,    81,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,   102,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,   102,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
       0,    -1,    81,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    -1,    22,   102,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    64,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    38,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    75,    -1,    -1,    78,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    77,    38,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      75,    -1,    77,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    77,    38,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    75,    -1,    77,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    30,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    47,    48,    -1,    -1,    -1,
      -1,    -1,    75,    76,    38,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    68,    69,    70,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    81,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    64,    -1,    -1,    67,    -1,    -1,
      -1,     3,     4,     5,     6,    75,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    47,    48,    -1,    67,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    75,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,     3,     4,     5,     6,    81,     8,     9,    10,
      11,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    38,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    -1,    -1,    67,    56,    57,    58,
      59,    -1,    61,    62,    75,    38,    -1,    -1,    67,    -1,
      -1,    -1,     3,     4,     5,     6,    75,     8,     9,    10,
      11,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,     3,     4,
       5,     6,    75,     8,     9,    10,    11,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    38,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    27,    28,    29,    30,    31,    37,
      38,    40,    41,    56,    57,    58,    59,    61,    62,    64,
      67,    75,    80,    98,    99,   105,   106,   114,   115,   116,
     117,   118,   119,   121,   122,   123,   124,   126,   127,   132,
     133,   134,   135,   136,   144,   145,   146,   147,   149,   150,
     151,   152,   153,   155,   162,   163,   164,   165,   166,   167,
      57,   164,   164,    57,   155,   164,    57,   120,   156,   164,
      60,   128,   131,   165,   155,   164,    62,   128,   129,   130,
     155,   164,   119,    76,   155,   157,   158,   164,    77,   155,
     164,   154,   155,   164,   164,   164,   164,   164,     0,   106,
      53,   166,   166,    21,    64,   119,     8,   165,    51,    57,
      57,    12,    30,    32,    33,    34,    35,    39,    47,    48,
      49,    55,    59,    60,    61,    62,    63,    64,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    81,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     102,   125,     8,    54,   167,   164,    51,    28,   155,    51,
     156,   164,    32,    51,    31,    60,    31,    60,   128,    51,
      49,    13,    51,    51,    76,    51,    76,    49,    51,    77,
      78,    51,   166,   165,   164,    53,     8,   164,    63,   154,
     155,   159,   160,   161,   165,   155,   159,   161,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     165,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
      51,    51,   119,   164,    57,   130,   165,    57,   130,    31,
     108,   109,   111,   112,   113,   127,   166,   165,   129,    76,
     157,   164,   164,    77,   164,    57,    78,    57,   166,   164,
      51,    77,    51,   143,    53,    51,    77,    51,   143,    24,
      53,    77,   164,    77,   164,    49,   130,   130,    57,   130,
      23,    24,   148,    98,    99,   127,    80,    98,    99,    96,
     107,    77,   155,   159,    62,    63,   137,   138,   139,   140,
     141,   142,   165,   161,   155,   160,    77,   164,   161,   155,
      77,   164,   164,    77,    77,   166,    51,   143,   143,   130,
     164,    49,    98,    80,    98,    99,    98,   110,   114,    51,
      77,    51,   137,   137,    51,   143,    77,    49,    53,    51,
     143,    51,   143,   143,   143,   107,    77,    77,   143,    49,
     109,    98,    97,   114,    63,   140,    51,   143,    51,   143,
      81,   137,   141,    49,    83,   164,   164,   165,    77,    77,
      77,    77,    24,    77,   166,   137,    51,   143,    63,   140,
      51,   143,   109,   164,    53,    49,   107,   143,    63,   137,
      51,   143,   139,   140,    49,   164,   166,    24,   148,   137,
     143,    63,    51,   109,   107,    49,   143,   137,   166,   143,
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
     132,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   138,   138,   138,   139,   139,
     139,   140,   140,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   146,   147,
     148,   148,   148,   149,   149,   149,   150,   150,   151,   152,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   158,   158,   159,   159,   160,   160,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   165,   166,   166,   167,   167,   167
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
       7,     8,     7,    11,     1,     1,     1,     1,     0,     4,
       3,     1,     3,     3,     5,     4,     5,     1,     2,     3,
       1,     3,     1,     4,     5,     7,     3,     5,     6,     8,
       3,     1,     0,     1,     0,     8,    10,     2,     5,     2,
       5,     9,     6,     4,     7,     5,     3,     2,     2,     1,
       2,     1,     2,     3,     1,     0,     3,     1,     3,     1,
       3,     3,     1,     1,     2,     3,     2,     3,     1,     1,
       1,     3,     4,     7,     7,     5,     4,     7,     7,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     3,     4,     3,     4,     3,     2,     3,
       3,     2,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
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
  "for_statement", "multi_line_statement", "decorators_opt", "decorators",
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
       0,   294,   294,   295,   296,   300,   304,   308,   312,   313,
     317,   318,   322,   323,   324,   325,   328,   331,   337,   340,
     346,   349,   355,   356,   357,   362,   366,   370,   374,   375,
     379,   380,   381,   382,   386,   387,   388,   389,   393,   394,
     395,   399,   400,   405,   406,   407,   409,   415,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     434,   435,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   457,   458,   462,   463,
     464,   468,   469,   473,   474,   480,   481,   483,   485,   487,
     489,   491,   497,   499,   511,   512,   515,   524,   525,   529,
     530,   534,   535,   536,   537,   541,   543,   545,   549,   550,
     552,   556,   557,   565,   566,   567,   569,   570,   572,   574,
     576,   580,   581,   585,   586,   590,   592,   603,   607,   611,
     615,   616,   618,   623,   626,   629,   634,   635,   639,   644,
     652,   653,   656,   659,   665,   666,   670,   671,   683,   684,
     693,   696,   697,   701,   702,   707,   708,   712,   713,   718,
     719,   720,   724,   725,   727,   729,   730,   731,   733,   735,
     742,   746,   747,   751,   752,   753,   757,   758,   759,   760,
     761,   762,   763,   765,   766,   767,   768,   769,   771,   772,
     776,   777,   779,   780,   781,   782,   783,   784,   785,   786,
     787,   788,   789,   791,   792,   793,   794,   795,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,   808,   809,
     810,   817,   822,   826,   827,   831,   832,   833
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
#line 3622 "./parser.cpp"

#line 836 "parser.ypp"
