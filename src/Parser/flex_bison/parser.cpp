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
      case symbol_kind::S_augassign_statement: // augassign_statement
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
      case symbol_kind::S_augassign_statement: // augassign_statement
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
      case symbol_kind::S_augassign_statement: // augassign_statement
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
      case symbol_kind::S_augassign_statement: // augassign_statement
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
      case symbol_kind::S_augassign_statement: // augassign_statement
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
#line 290 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1199 "./parser.cpp"
    break;

  case 3: // units: script_unit
#line 291 "parser.ypp"
                          { RESULT(yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1205 "./parser.cpp"
    break;

  case 5: // script_unit: statement
#line 296 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1211 "./parser.cpp"
    break;

  case 6: // statements: INDENT statements1 DEDENT
#line 300 "parser.ypp"
                                { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1217 "./parser.cpp"
    break;

  case 7: // sep_statements: sep statements
#line 304 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1223 "./parser.cpp"
    break;

  case 8: // body_stmts: single_line_statements
#line 308 "parser.ypp"
                             { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1229 "./parser.cpp"
    break;

  case 9: // body_stmts: sep_statements
#line 309 "parser.ypp"
                     { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1235 "./parser.cpp"
    break;

  case 10: // statements1: statements1 statement
#line 313 "parser.ypp"
                            { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1241 "./parser.cpp"
    break;

  case 11: // statements1: statement
#line 314 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ()); }
#line 1247 "./parser.cpp"
    break;

  case 12: // single_line_statements: single_line_multi_statements NEWLINE
#line 318 "parser.ypp"
                                           { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1253 "./parser.cpp"
    break;

  case 13: // single_line_statements: single_line_multi_statements COMMENT NEWLINE
#line 319 "parser.ypp"
                                                   { yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); }
#line 1259 "./parser.cpp"
    break;

  case 14: // single_line_statements: single_line_statement NEWLINE
#line 320 "parser.ypp"
                                    { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ()); }
#line 1265 "./parser.cpp"
    break;

  case 15: // single_line_statements: single_line_statement ";" NEWLINE
#line 321 "parser.ypp"
                                              {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1273 "./parser.cpp"
    break;

  case 16: // single_line_statements: single_line_statement ";" COMMENT NEWLINE
#line 324 "parser.ypp"
                                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[3].value.as < Nonnull<Statement*> > ());
      }
#line 1281 "./parser.cpp"
    break;

  case 17: // single_line_statements: single_line_statement COMMENT NEWLINE
#line 327 "parser.ypp"
                                            {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[2].value.as < Nonnull<Statement*> > ());
      }
#line 1289 "./parser.cpp"
    break;

  case 18: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement
#line 333 "parser.ypp"
                                                             {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > ());
      }
#line 1297 "./parser.cpp"
    break;

  case 19: // single_line_multi_statements: single_line_multi_statements_opt single_line_statement ";"
#line 336 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1305 "./parser.cpp"
    break;

  case 20: // single_line_multi_statements_opt: single_line_multi_statements_opt single_line_statement ";"
#line 342 "parser.ypp"
                                                                       {
        yylhs.value.as < std::vector<Nonnull<Statement*>> > () = yystack_[2].value.as < std::vector<Nonnull<Statement*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1313 "./parser.cpp"
    break;

  case 21: // single_line_multi_statements_opt: single_line_statement ";"
#line 345 "parser.ypp"
                                      {
        LIST_NEW(yylhs.value.as < std::vector<Nonnull<Statement*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Statement*>> > (), yystack_[1].value.as < Nonnull<Statement*> > ());
      }
#line 1321 "./parser.cpp"
    break;

  case 22: // statement: single_line_statement sep
#line 351 "parser.ypp"
                                { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1327 "./parser.cpp"
    break;

  case 23: // statement: multi_line_statement
#line 352 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1333 "./parser.cpp"
    break;

  case 24: // statement: multi_line_statement sep
#line 353 "parser.ypp"
                               { yylhs.value.as < Nonnull<Statement*> > () = yystack_[1].value.as < Nonnull<Statement*> > (); }
#line 1339 "./parser.cpp"
    break;

  case 25: // pass_statement: PASS
#line 358 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = PASS(context.source_loc()); }
#line 1345 "./parser.cpp"
    break;

  case 26: // break_statement: BREAK
#line 362 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = BREAK(context.source_loc()); }
#line 1351 "./parser.cpp"
    break;

  case 27: // continue_statement: CONTINUE
#line 366 "parser.ypp"
               { yylhs.value.as < Nonnull<Statement*> > () = CONTINUE(context.source_loc()); }
#line 1357 "./parser.cpp"
    break;

  case 28: // assert_statement: ASSERT expr
#line 370 "parser.ypp"
                  { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1363 "./parser.cpp"
    break;

  case 29: // assert_statement: ASSERT expr "," expr
#line 371 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = ASSERT_02(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1369 "./parser.cpp"
    break;

  case 30: // tuple_item: expr_list
#line 375 "parser.ypp"
                { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1375 "./parser.cpp"
    break;

  case 31: // tuple_item: expr_list ","
#line 376 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1381 "./parser.cpp"
    break;

  case 32: // tuple_item: "(" expr_list "," ")"
#line 377 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1387 "./parser.cpp"
    break;

  case 33: // tuple_item: "(" expr_list "," expr ")"
#line 378 "parser.ypp"
                                  { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1393 "./parser.cpp"
    break;

  case 34: // raise_statement: RAISE
#line 382 "parser.ypp"
            { yylhs.value.as < Nonnull<Statement*> > () = RAISE_01(context.source_loc()); }
#line 1399 "./parser.cpp"
    break;

  case 35: // raise_statement: RAISE expr
#line 383 "parser.ypp"
                 { yylhs.value.as < Nonnull<Statement*> > () = RAISE_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1405 "./parser.cpp"
    break;

  case 36: // raise_statement: RAISE expr FROM expr
#line 384 "parser.ypp"
                           { yylhs.value.as < Nonnull<Statement*> > () = RAISE_03(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1411 "./parser.cpp"
    break;

  case 37: // return_statement: RETURN
#line 388 "parser.ypp"
             { yylhs.value.as < Nonnull<Statement*> > () = RETURN_01(context.source_loc()); }
#line 1417 "./parser.cpp"
    break;

  case 38: // return_statement: RETURN tuple_item
#line 389 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = RETURN_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1423 "./parser.cpp"
    break;

  case 39: // delete_statement: DEL expr_list
#line 394 "parser.ypp"
                    { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1429 "./parser.cpp"
    break;

  case 40: // delete_statement: DEL expr_list ","
#line 395 "parser.ypp"
                        { yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1435 "./parser.cpp"
    break;

  case 41: // delete_statement: DEL "(" expr_list "," ")"
#line 396 "parser.ypp"
                                {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1442 "./parser.cpp"
    break;

  case 42: // delete_statement: DEL "(" expr_list "," expr ")"
#line 398 "parser.ypp"
                                     {
        yylhs.value.as < Nonnull<Statement*> > () = DELETE_01(TUPLE_(yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()), context.source_loc()); }
#line 1449 "./parser.cpp"
    break;

  case 43: // augassign_statement: expr augassign_op expr
#line 404 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = AUGASSIGN_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < operatorType > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1455 "./parser.cpp"
    break;

  case 44: // augassign_op: "+="
#line 408 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Add, context.source_loc()); }
#line 1461 "./parser.cpp"
    break;

  case 45: // augassign_op: "-="
#line 409 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Sub, context.source_loc()); }
#line 1467 "./parser.cpp"
    break;

  case 46: // augassign_op: "*="
#line 410 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mult, context.source_loc()); }
#line 1473 "./parser.cpp"
    break;

  case 47: // augassign_op: "/="
#line 411 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Div, context.source_loc()); }
#line 1479 "./parser.cpp"
    break;

  case 48: // augassign_op: "%="
#line 412 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(Mod, context.source_loc()); }
#line 1485 "./parser.cpp"
    break;

  case 49: // augassign_op: "&="
#line 413 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitAnd, context.source_loc()); }
#line 1491 "./parser.cpp"
    break;

  case 50: // augassign_op: "|="
#line 414 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitOr, context.source_loc()); }
#line 1497 "./parser.cpp"
    break;

  case 51: // augassign_op: "^="
#line 415 "parser.ypp"
           { yylhs.value.as < operatorType > () = OPERATOR(BitXor, context.source_loc()); }
#line 1503 "./parser.cpp"
    break;

  case 52: // augassign_op: "<<="
#line 416 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(LShift, context.source_loc()); }
#line 1509 "./parser.cpp"
    break;

  case 53: // augassign_op: ">>="
#line 417 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(RShift, context.source_loc()); }
#line 1515 "./parser.cpp"
    break;

  case 54: // augassign_op: "**="
#line 418 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(Pow, context.source_loc()); }
#line 1521 "./parser.cpp"
    break;

  case 55: // augassign_op: "//="
#line 419 "parser.ypp"
            { yylhs.value.as < operatorType > () = OPERATOR(FloorDiv, context.source_loc()); }
#line 1527 "./parser.cpp"
    break;

  case 56: // single_line_statement: expression_statment
#line 423 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1533 "./parser.cpp"
    break;

  case 57: // single_line_statement: assert_statement
#line 425 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1539 "./parser.cpp"
    break;

  case 58: // single_line_statement: assignment_statement
#line 426 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1545 "./parser.cpp"
    break;

  case 59: // single_line_statement: augassign_statement
#line 427 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1551 "./parser.cpp"
    break;

  case 60: // single_line_statement: pass_statement
#line 429 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1557 "./parser.cpp"
    break;

  case 61: // single_line_statement: delete_statement
#line 430 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1563 "./parser.cpp"
    break;

  case 62: // single_line_statement: return_statement
#line 431 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1569 "./parser.cpp"
    break;

  case 63: // single_line_statement: raise_statement
#line 432 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1575 "./parser.cpp"
    break;

  case 64: // single_line_statement: break_statement
#line 433 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1581 "./parser.cpp"
    break;

  case 65: // single_line_statement: continue_statement
#line 434 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1587 "./parser.cpp"
    break;

  case 66: // single_line_statement: import_statement
#line 435 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1593 "./parser.cpp"
    break;

  case 67: // single_line_statement: global_statement
#line 436 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1599 "./parser.cpp"
    break;

  case 68: // single_line_statement: nonlocal_statement
#line 437 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1605 "./parser.cpp"
    break;

  case 69: // module: module "." id
#line 442 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1611 "./parser.cpp"
    break;

  case 70: // module: id
#line 443 "parser.ypp"
         { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > ()); }
#line 1617 "./parser.cpp"
    break;

  case 71: // module_as_id: module
#line 447 "parser.ypp"
             { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_01(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1623 "./parser.cpp"
    break;

  case 72: // module_as_id: module AS id
#line 448 "parser.ypp"
                   { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1629 "./parser.cpp"
    break;

  case 73: // module_as_id: "*"
#line 449 "parser.ypp"
          { yylhs.value.as < Nonnull<Alias*> > () = MOD_ID_03(context.source_loc()); }
#line 1635 "./parser.cpp"
    break;

  case 74: // module_item_list: module_item_list "," module_as_id
#line 453 "parser.ypp"
                                        { yylhs.value.as < std::vector<Nonnull<Alias*>> > () = yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1641 "./parser.cpp"
    break;

  case 75: // module_item_list: module_as_id
#line 454 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Alias*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Alias*>> > (), yystack_[0].value.as < Nonnull<Alias*> > ()); }
#line 1647 "./parser.cpp"
    break;

  case 76: // dot_list: dot_list "."
#line 458 "parser.ypp"
                   { DOT_COUNT_01(); }
#line 1653 "./parser.cpp"
    break;

  case 77: // dot_list: "."
#line 459 "parser.ypp"
          { DOT_COUNT_01(); }
#line 1659 "./parser.cpp"
    break;

  case 78: // import_statement: IMPORT module_item_list
#line 465 "parser.ypp"
                              { yylhs.value.as < Nonnull<Statement*> > () = IMPORT_01(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1665 "./parser.cpp"
    break;

  case 79: // import_statement: FROM module IMPORT module_item_list
#line 466 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1672 "./parser.cpp"
    break;

  case 80: // import_statement: FROM module IMPORT "(" module_item_list comma_opt ")"
#line 468 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_02(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1679 "./parser.cpp"
    break;

  case 81: // import_statement: FROM dot_list IMPORT module_item_list
#line 470 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1686 "./parser.cpp"
    break;

  case 82: // import_statement: FROM dot_list module IMPORT module_item_list
#line 472 "parser.ypp"
                                                   {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1693 "./parser.cpp"
    break;

  case 83: // import_statement: FROM dot_list IMPORT "(" module_item_list comma_opt ")"
#line 474 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_03(yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1700 "./parser.cpp"
    break;

  case 84: // import_statement: FROM dot_list module IMPORT "(" module_item_list comma_opt ")"
#line 476 "parser.ypp"
                                                                     {
        yylhs.value.as < Nonnull<Statement*> > () = IMPORT_04(yystack_[5].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Alias*>> > (), context.source_loc()); }
#line 1707 "./parser.cpp"
    break;

  case 85: // multi_line_statement: if_statement
#line 481 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1713 "./parser.cpp"
    break;

  case 86: // multi_line_statement: function_def
#line 485 "parser.ypp"
      { yylhs.value.as < Nonnull<Statement*> > () = yystack_[0].value.as < Nonnull<Statement*> > (); }
#line 1719 "./parser.cpp"
    break;

  case 87: // decorators_opt: decorators
#line 494 "parser.ypp"
                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 1725 "./parser.cpp"
    break;

  case 88: // decorators_opt: %empty
#line 495 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 1731 "./parser.cpp"
    break;

  case 89: // decorators: decorators "@" expr sep
#line 499 "parser.ypp"
                              { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[3].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1737 "./parser.cpp"
    break;

  case 90: // decorators: "@" expr sep
#line 500 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1743 "./parser.cpp"
    break;

  case 91: // parameter: id
#line 504 "parser.ypp"
         { yylhs.value.as < Nonnull<Arg*> > () = ARGS_01(yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 1749 "./parser.cpp"
    break;

  case 92: // parameter: id ":" expr
#line 505 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_02(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1755 "./parser.cpp"
    break;

  case 93: // parameter: id "=" expr
#line 506 "parser.ypp"
                  { yylhs.value.as < Nonnull<Arg*> > () = ARGS_03(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1761 "./parser.cpp"
    break;

  case 94: // parameter: id ":" expr "=" expr
#line 507 "parser.ypp"
                           { yylhs.value.as < Nonnull<Arg*> > () = ARGS_04(yystack_[4].value.as < Nonnull<Name*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1767 "./parser.cpp"
    break;

  case 95: // parameter_list: defparameter_list "," "/" comma_opt
#line 511 "parser.ypp"
                                          {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[3].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1774 "./parser.cpp"
    break;

  case 96: // parameter_list: defparameter_list "," "/" "," parameter_list_no_posonly
#line 513 "parser.ypp"
                                                              {
        yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_01(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1781 "./parser.cpp"
    break;

  case 97: // parameter_list: parameter_list_no_posonly
#line 515 "parser.ypp"
                                { yylhs.value.as < Nonnull<FnArg*> > () = PARAMETER_LIST_02(yystack_[0].value.as < Nonnull<NoPosOnlyArg*> > ()); }
#line 1787 "./parser.cpp"
    break;

  case 98: // parameter_list_no_posonly: defparameter_list comma_opt
#line 519 "parser.ypp"
                                  { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > (), std::nullopt); }
#line 1793 "./parser.cpp"
    break;

  case 99: // parameter_list_no_posonly: defparameter_list "," parameter_list_starargs
#line 520 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_03(yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1800 "./parser.cpp"
    break;

  case 100: // parameter_list_no_posonly: parameter_list_starargs
#line 522 "parser.ypp"
                              { yylhs.value.as < Nonnull<NoPosOnlyArg*> > () = PARAMETER_LIST_04(yystack_[0].value.as < Nonnull<StarArg*> > ()); }
#line 1806 "./parser.cpp"
    break;

  case 101: // defparameter_list: defparameter_list "," parameter
#line 526 "parser.ypp"
                                      { yylhs.value.as < std::vector<Nonnull<Arg*>> > () = yystack_[2].value.as < std::vector<Nonnull<Arg*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1812 "./parser.cpp"
    break;

  case 102: // defparameter_list: parameter
#line 527 "parser.ypp"
                { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Arg*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Arg*>> > (), yystack_[0].value.as < Nonnull<Arg*> > ()); }
#line 1818 "./parser.cpp"
    break;

  case 103: // parameter_list_starargs: "*" "," defparameter_list comma_opt
#line 535 "parser.ypp"
                                          { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_05(yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1824 "./parser.cpp"
    break;

  case 104: // parameter_list_starargs: "*" "," "**" parameter comma_opt
#line 536 "parser.ypp"
                                       { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1830 "./parser.cpp"
    break;

  case 105: // parameter_list_starargs: "*" "," defparameter_list "," "**" parameter comma_opt
#line 537 "parser.ypp"
                                                             {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_07(yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1837 "./parser.cpp"
    break;

  case 106: // parameter_list_starargs: "*" parameter comma_opt
#line 539 "parser.ypp"
                              { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_08(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1843 "./parser.cpp"
    break;

  case 107: // parameter_list_starargs: "*" parameter "," defparameter_list comma_opt
#line 540 "parser.ypp"
                                                    {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_09(yystack_[3].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < std::vector<Nonnull<Arg*>> > ()); }
#line 1850 "./parser.cpp"
    break;

  case 108: // parameter_list_starargs: "*" parameter "," "**" parameter comma_opt
#line 542 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_10(yystack_[4].value.as < Nonnull<Arg*> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1857 "./parser.cpp"
    break;

  case 109: // parameter_list_starargs: "*" parameter "," defparameter_list "," "**" parameter comma_opt
#line 544 "parser.ypp"
                                                                       {
        yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_11(yystack_[6].value.as < Nonnull<Arg*> > (), yystack_[4].value.as < std::vector<Nonnull<Arg*>> > (), yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1864 "./parser.cpp"
    break;

  case 110: // parameter_list_starargs: "**" parameter comma_opt
#line 546 "parser.ypp"
                               { yylhs.value.as < Nonnull<StarArg*> > () = PARAMETER_LIST_06(yystack_[1].value.as < Nonnull<Arg*> > ()); }
#line 1870 "./parser.cpp"
    break;

  case 111: // parameter_list_opt: parameter_list
#line 550 "parser.ypp"
                     { yylhs.value.as < Nonnull<Arguments*> > () = FUNC_ARGS_01(arena, context.source_loc(), yystack_[0].value.as < Nonnull<FnArg*> > ()); }
#line 1876 "./parser.cpp"
    break;

  case 112: // parameter_list_opt: %empty
#line 551 "parser.ypp"
             { yylhs.value.as < Nonnull<Arguments*> > () = PARAMETER_LIST_12(context.source_loc()); }
#line 1882 "./parser.cpp"
    break;

  case 115: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" ":" body_stmts
#line 561 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_01(yystack_[7].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[5].value.as < Nonnull<Name*> > (), yystack_[3].value.as < Nonnull<Arguments*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1888 "./parser.cpp"
    break;

  case 116: // function_def: decorators_opt DEF id "(" parameter_list_opt ")" "->" expr ":" body_stmts
#line 563 "parser.ypp"
                   { yylhs.value.as < Nonnull<Statement*> > () = FUNCTION_02(yystack_[9].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[7].value.as < Nonnull<Name*> > (), yystack_[5].value.as < Nonnull<Arguments*> > (), yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1894 "./parser.cpp"
    break;

  case 117: // global_statement: GLOBAL expr_list
#line 573 "parser.ypp"
                       { yylhs.value.as < Nonnull<Statement*> > () = GLOBAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1900 "./parser.cpp"
    break;

  case 118: // ternary_if_statement: expr IF expr ELSE expr
#line 577 "parser.ypp"
                             { yylhs.value.as < Nonnull<Expression*> > () = TERNARY(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1906 "./parser.cpp"
    break;

  case 119: // nonlocal_statement: NONLOCAL expr_list
#line 581 "parser.ypp"
                         { yylhs.value.as < Nonnull<Statement*> > () = NON_LOCAL(yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 1912 "./parser.cpp"
    break;

  case 120: // elif_statement: ELIF expr ":" sep statements
#line 585 "parser.ypp"
                                   { yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (),context.source_loc()); }
#line 1918 "./parser.cpp"
    break;

  case 121: // elif_statement: ELIF expr ":" sep statements ELSE ":" sep statements
#line 586 "parser.ypp"
                                                           {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[7].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc()); }
#line 1925 "./parser.cpp"
    break;

  case 122: // elif_statement: ELIF expr ":" sep statements elif_statement
#line 588 "parser.ypp"
                                                  {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1932 "./parser.cpp"
    break;

  case 123: // if_statement: IF expr ":" body_stmts
#line 593 "parser.ypp"
                             {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_01(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1940 "./parser.cpp"
    break;

  case 124: // if_statement: IF expr ":" body_stmts ELSE ":" body_stmts
#line 596 "parser.ypp"
                                                 {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_02(yystack_[5].value.as < Nonnull<Expression*> > (), yystack_[3].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < std::vector<Nonnull<Statement*>> > (), context.source_loc());
      }
#line 1948 "./parser.cpp"
    break;

  case 125: // if_statement: IF expr ":" body_stmts elif_statement
#line 599 "parser.ypp"
                                            {
        yylhs.value.as < Nonnull<Statement*> > () = IF_STMT_03(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Statement*>> > (), yystack_[0].value.as < Nonnull<Statement*> > (), context.source_loc()); }
#line 1955 "./parser.cpp"
    break;

  case 126: // target_list: target_list tuple_item "="
#line 604 "parser.ypp"
                                 { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1961 "./parser.cpp"
    break;

  case 127: // target_list: tuple_item "="
#line 605 "parser.ypp"
                     { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[1].value.as < Nonnull<Expression*> > ()); }
#line 1967 "./parser.cpp"
    break;

  case 128: // assignment_statement: target_list tuple_item
#line 609 "parser.ypp"
                             { yylhs.value.as < Nonnull<Statement*> > () = ASSIGNMENT(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1973 "./parser.cpp"
    break;

  case 129: // expression_statment: expr
#line 614 "parser.ypp"
           { yylhs.value.as < Nonnull<Statement*> > () = EXPR_01(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 1979 "./parser.cpp"
    break;

  case 130: // string: string string_literal
#line 622 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = STRING2(yystack_[1].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 1985 "./parser.cpp"
    break;

  case 131: // string: string_literal
#line 623 "parser.ypp"
                     {
        yylhs.value.as < Nonnull<Expression*> > () = STRING1(yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 1993 "./parser.cpp"
    break;

  case 132: // string: id string_literal
#line 626 "parser.ypp"
                        {
        yylhs.value.as < Nonnull<Expression*> > () = STRING3(yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2001 "./parser.cpp"
    break;

  case 133: // string: string id string_literal
#line 629 "parser.ypp"
                               {
        yylhs.value.as < Nonnull<Expression*> > () = STRING4(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < Nonnull<Name*> > (), yystack_[0].value.as < std::string > (), context.source_loc());
      }
#line 2009 "./parser.cpp"
    break;

  case 134: // expr_list_opt: expr_list
#line 635 "parser.ypp"
                { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2015 "./parser.cpp"
    break;

  case 135: // expr_list_opt: %empty
#line 636 "parser.ypp"
             { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); }
#line 2021 "./parser.cpp"
    break;

  case 136: // expr_list: expr_list "," expr
#line 640 "parser.ypp"
                         { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2027 "./parser.cpp"
    break;

  case 137: // expr_list: expr
#line 641 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Expression*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Expression*>> > (), yystack_[0].value.as < Nonnull<Expression*> > ()); }
#line 2033 "./parser.cpp"
    break;

  case 138: // dict: expr ":" expr
#line 651 "parser.ypp"
                    { yylhs.value.as < PairNonnullExpr > () = DICT_EXPR(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2039 "./parser.cpp"
    break;

  case 139: // dict_list: dict_list "," dict
#line 655 "parser.ypp"
                         { yylhs.value.as < std::vector<PairNonnullExpr> > () = yystack_[2].value.as < std::vector<PairNonnullExpr> > (); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2045 "./parser.cpp"
    break;

  case 140: // dict_list: dict
#line 656 "parser.ypp"
           { LIST_NEW(yylhs.value.as < std::vector<PairNonnullExpr> > ()); LIST_ADD(yylhs.value.as < std::vector<PairNonnullExpr> > (), yystack_[0].value.as < PairNonnullExpr > ()); }
#line 2051 "./parser.cpp"
    break;

  case 141: // call_arguement_list: expr_list_opt
#line 660 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[0].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2057 "./parser.cpp"
    break;

  case 142: // call_arguement_list: expr_list ","
#line 661 "parser.ypp"
                    { yylhs.value.as < std::vector<Nonnull<Expression*>> > () = yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (); }
#line 2063 "./parser.cpp"
    break;

  case 143: // keyword_item: id "=" expr
#line 666 "parser.ypp"
                  { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_01(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2069 "./parser.cpp"
    break;

  case 144: // keyword_item: "**" expr
#line 667 "parser.ypp"
                { yylhs.value.as < Nonnull<Keyword*> > () = CALL_KEYWORD_02(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2075 "./parser.cpp"
    break;

  case 145: // keyword_items: keyword_items "," keyword_item
#line 671 "parser.ypp"
                                     { yylhs.value.as < std::vector<Nonnull<Keyword*>> > () = yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2081 "./parser.cpp"
    break;

  case 146: // keyword_items: keyword_item
#line 672 "parser.ypp"
                   { LIST_NEW(yylhs.value.as < std::vector<Nonnull<Keyword*>> > ()); LIST_ADD(yylhs.value.as < std::vector<Nonnull<Keyword*>> > (), yystack_[0].value.as < Nonnull<Keyword*> > ()); }
#line 2087 "./parser.cpp"
    break;

  case 147: // primary: id
#line 677 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2093 "./parser.cpp"
    break;

  case 148: // primary: string
#line 678 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2099 "./parser.cpp"
    break;

  case 149: // primary: expr "." id
#line 679 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2105 "./parser.cpp"
    break;

  case 150: // function_call: primary "(" call_arguement_list ")"
#line 683 "parser.ypp"
                                          { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2111 "./parser.cpp"
    break;

  case 151: // function_call: primary "(" expr_list "," keyword_items comma_opt ")"
#line 684 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2118 "./parser.cpp"
    break;

  case 152: // function_call: primary "(" keyword_items "," expr_list comma_opt ")"
#line 686 "parser.ypp"
                                                            {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2125 "./parser.cpp"
    break;

  case 153: // function_call: primary "(" keyword_items comma_opt ")"
#line 688 "parser.ypp"
                                              { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2131 "./parser.cpp"
    break;

  case 154: // function_call: function_call "(" call_arguement_list ")"
#line 689 "parser.ypp"
                                                { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[3].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2137 "./parser.cpp"
    break;

  case 155: // function_call: function_call "(" expr_list "," keyword_items comma_opt ")"
#line 690 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[4].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2144 "./parser.cpp"
    break;

  case 156: // function_call: function_call "(" keyword_items "," expr_list comma_opt ")"
#line 692 "parser.ypp"
                                                                  {
        yylhs.value.as < Nonnull<Expression*> > () = CALL_02(yystack_[6].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), yystack_[4].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2151 "./parser.cpp"
    break;

  case 157: // function_call: function_call "(" keyword_items comma_opt ")"
#line 694 "parser.ypp"
                                                    { yylhs.value.as < Nonnull<Expression*> > () = CALL_03(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[2].value.as < std::vector<Nonnull<Keyword*>> > (), context.source_loc()); }
#line 2157 "./parser.cpp"
    break;

  case 158: // function_call: "(" expr ")" "(" call_arguement_list ")"
#line 701 "parser.ypp"
                                               { yylhs.value.as < Nonnull<Expression*> > () = CALL_01(yystack_[4].value.as < Nonnull<Expression*> > (), yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2163 "./parser.cpp"
    break;

  case 159: // expr: id
#line 705 "parser.ypp"
         { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Name*> > (); }
#line 2169 "./parser.cpp"
    break;

  case 160: // expr: integer_literal
#line 706 "parser.ypp"
                      {
        std::cout << "integer lit: " << yystack_[0].value.as < long long > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = INTEGER(yystack_[0].value.as < long long > (), context.source_loc());
      }
#line 2178 "./parser.cpp"
    break;

  case 161: // expr: string
#line 710 "parser.ypp"
             { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2184 "./parser.cpp"
    break;

  case 162: // expr: real_literal
#line 711 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = FLOAT(yystack_[0].value.as < double > (), context.source_loc()); }
#line 2190 "./parser.cpp"
    break;

  case 163: // expr: image_literal
#line 712 "parser.ypp"
                    {
        std::cout << "image_literal: " << yystack_[0].value.as < double > () << std::endl;
        yylhs.value.as < Nonnull<Expression*> > () = COMPLEX(yystack_[0].value.as < double > (), context.source_loc());
      }
#line 2199 "./parser.cpp"
    break;

  case 164: // expr: TRUE
#line 716 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = BOOL(true, context.source_loc()); }
#line 2205 "./parser.cpp"
    break;

  case 165: // expr: FALSE
#line 717 "parser.ypp"
            { yylhs.value.as < Nonnull<Expression*> > () = BOOL(false, context.source_loc()); }
#line 2211 "./parser.cpp"
    break;

  case 166: // expr: NONE
#line 718 "parser.ypp"
           { yylhs.value.as < Nonnull<Expression*> > () = NONE(context.source_loc()); }
#line 2217 "./parser.cpp"
    break;

  case 167: // expr: "..."
#line 719 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = ELLIPSIS(context.source_loc()); }
#line 2223 "./parser.cpp"
    break;

  case 168: // expr: "(" expr ")"
#line 720 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = yystack_[1].value.as < Nonnull<Expression*> > (); }
#line 2229 "./parser.cpp"
    break;

  case 169: // expr: "(" ")"
#line 721 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = TUPLE_EMPTY(context.source_loc()); }
#line 2235 "./parser.cpp"
    break;

  case 170: // expr: function_call
#line 722 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2241 "./parser.cpp"
    break;

  case 171: // expr: "[" expr_list_opt "]"
#line 724 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2247 "./parser.cpp"
    break;

  case 172: // expr: "[" expr_list "," "]"
#line 725 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = LIST(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2253 "./parser.cpp"
    break;

  case 173: // expr: "{" expr_list "}"
#line 726 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[1].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2259 "./parser.cpp"
    break;

  case 174: // expr: "{" expr_list "," "}"
#line 727 "parser.ypp"
                            { yylhs.value.as < Nonnull<Expression*> > () = SET(yystack_[2].value.as < std::vector<Nonnull<Expression*>> > (), context.source_loc()); }
#line 2265 "./parser.cpp"
    break;

  case 175: // expr: expr "." id
#line 728 "parser.ypp"
                  { yylhs.value.as < Nonnull<Expression*> > () = ATTRIBUTE_REF(yystack_[2].value.as < Nonnull<Expression*> > (), yystack_[0].value.as < Nonnull<Name*> > (), context.source_loc()); }
#line 2271 "./parser.cpp"
    break;

  case 176: // expr: "{" "}"
#line 730 "parser.ypp"
              { yylhs.value.as < Nonnull<Expression*> > () = DICT_01(context.source_loc()); }
#line 2277 "./parser.cpp"
    break;

  case 177: // expr: "{" dict_list "}"
#line 731 "parser.ypp"
                        { yylhs.value.as < Nonnull<Expression*> > () = DICT_02(yystack_[1].value.as < std::vector<PairNonnullExpr> > (), context.source_loc()); }
#line 2283 "./parser.cpp"
    break;

  case 178: // expr: id ":=" expr
#line 735 "parser.ypp"
                   { yylhs.value.as < Nonnull<Expression*> > () = NAMEDEXPR(yystack_[2].value.as < Nonnull<Name*> > (), yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2289 "./parser.cpp"
    break;

  case 179: // expr: "*" expr
#line 736 "parser.ypp"
               { yylhs.value.as < Nonnull<Expression*> > () = STARRED_ARG(yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2295 "./parser.cpp"
    break;

  case 180: // expr: expr "+" expr
#line 738 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Add, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2301 "./parser.cpp"
    break;

  case 181: // expr: expr "-" expr
#line 739 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Sub, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2307 "./parser.cpp"
    break;

  case 182: // expr: expr "*" expr
#line 740 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2313 "./parser.cpp"
    break;

  case 183: // expr: expr "/" expr
#line 741 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Div, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2319 "./parser.cpp"
    break;

  case 184: // expr: expr "%" expr
#line 742 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Mod, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2325 "./parser.cpp"
    break;

  case 185: // expr: "-" expr
#line 743 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), USub, context.source_loc()); }
#line 2331 "./parser.cpp"
    break;

  case 186: // expr: "+" expr
#line 744 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), UAdd, context.source_loc()); }
#line 2337 "./parser.cpp"
    break;

  case 187: // expr: "~" expr
#line 745 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Invert, context.source_loc()); }
#line 2343 "./parser.cpp"
    break;

  case 188: // expr: expr "**" expr
#line 746 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), Pow, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2349 "./parser.cpp"
    break;

  case 189: // expr: expr "//" expr
#line 747 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), FloorDiv, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2355 "./parser.cpp"
    break;

  case 190: // expr: expr "@" expr
#line 748 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), MatMult, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2361 "./parser.cpp"
    break;

  case 191: // expr: expr "&" expr
#line 750 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitAnd, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2367 "./parser.cpp"
    break;

  case 192: // expr: expr "|" expr
#line 751 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitOr, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2373 "./parser.cpp"
    break;

  case 193: // expr: expr "^" expr
#line 752 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), BitXor, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2379 "./parser.cpp"
    break;

  case 194: // expr: expr "<<" expr
#line 753 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), LShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2385 "./parser.cpp"
    break;

  case 195: // expr: expr ">>" expr
#line 754 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BINOP(yystack_[2].value.as < Nonnull<Expression*> > (), RShift, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2391 "./parser.cpp"
    break;

  case 196: // expr: expr "==" expr
#line 756 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Eq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2397 "./parser.cpp"
    break;

  case 197: // expr: expr "!=" expr
#line 757 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotEq, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2403 "./parser.cpp"
    break;

  case 198: // expr: expr "<" expr
#line 758 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Lt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2409 "./parser.cpp"
    break;

  case 199: // expr: expr "<=" expr
#line 759 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), LtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2415 "./parser.cpp"
    break;

  case 200: // expr: expr ">" expr
#line 760 "parser.ypp"
                    { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Gt, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2421 "./parser.cpp"
    break;

  case 201: // expr: expr ">=" expr
#line 761 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), GtE, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2427 "./parser.cpp"
    break;

  case 202: // expr: expr "is" expr
#line 762 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), Is, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2433 "./parser.cpp"
    break;

  case 203: // expr: expr "is not" expr
#line 763 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), IsNot, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2439 "./parser.cpp"
    break;

  case 204: // expr: expr "in" expr
#line 764 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), In, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2445 "./parser.cpp"
    break;

  case 205: // expr: expr "not in" expr
#line 765 "parser.ypp"
                         { yylhs.value.as < Nonnull<Expression*> > () = COMPARE(yystack_[2].value.as < Nonnull<Expression*> > (), NotIn, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2451 "./parser.cpp"
    break;

  case 206: // expr: expr "and" expr
#line 767 "parser.ypp"
                      { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), And, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2457 "./parser.cpp"
    break;

  case 207: // expr: expr "or" expr
#line 768 "parser.ypp"
                     { yylhs.value.as < Nonnull<Expression*> > () = BOOLOP(yystack_[2].value.as < Nonnull<Expression*> > (), Or, yystack_[0].value.as < Nonnull<Expression*> > (), context.source_loc()); }
#line 2463 "./parser.cpp"
    break;

  case 208: // expr: "not" expr
#line 769 "parser.ypp"
                 { yylhs.value.as < Nonnull<Expression*> > () = UNARY(yystack_[0].value.as < Nonnull<Expression*> > (), Not, context.source_loc()); }
#line 2469 "./parser.cpp"
    break;

  case 209: // expr: ternary_if_statement
#line 776 "parser.ypp"
                           { yylhs.value.as < Nonnull<Expression*> > () = yystack_[0].value.as < Nonnull<Expression*> > (); }
#line 2475 "./parser.cpp"
    break;

  case 210: // id: identifier
#line 781 "parser.ypp"
                 { yylhs.value.as < Nonnull<Name*> > () = SYMBOL(yystack_[0].value.as < std::string > (), context.source_loc()); }
#line 2481 "./parser.cpp"
    break;

  case 211: // sep: sep sep_one
#line 785 "parser.ypp"
                  { yylhs.value.as < std::vector<std::string> > () = yystack_[1].value.as < std::vector<std::string> > (); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2487 "./parser.cpp"
    break;

  case 212: // sep: sep_one
#line 786 "parser.ypp"
              { LIST_NEW(yylhs.value.as < std::vector<std::string> > ()); LIST_ADD(yylhs.value.as < std::vector<std::string> > (), yystack_[0].value.as < std::string > ()); }
#line 2493 "./parser.cpp"
    break;

  case 213: // sep_one: NEWLINE
#line 790 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("newline"); }
#line 2499 "./parser.cpp"
    break;

  case 214: // sep_one: COMMENT
#line 791 "parser.ypp"
              { yylhs.value.as < std::string > () = std::string("comment"); }
#line 2505 "./parser.cpp"
    break;

  case 215: // sep_one: ";"
#line 792 "parser.ypp"
                { yylhs.value.as < std::string > () = std::string(";"); }
#line 2511 "./parser.cpp"
    break;


#line 2515 "./parser.cpp"

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









  const short  Parser ::yypact_ninf_ = -353;

  const short  Parser ::yytable_ninf_ = -150;

  const short
   Parser ::yypact_[] =
  {
     460,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  2002,
    2002,  -353,  -353,  2040,    25,  2002,  2002,     8,  2002,  2002,
    -353,  2062,  1749,  1633,  2002,  2002,  2002,  2002,  2002,  2002,
    -353,  -353,  -353,  -353,  1558,  -353,  -353,  -353,  -353,  -353,
    -353,   -28,  -353,  -353,  -353,  -353,    91,  -353,    91,    23,
      -8,  -353,  -353,  -353,  -353,  -353,  2062,  -353,  -353,    41,
       7,    49,   116,   645,    46,    91,  -353,  1633,   782,   846,
    1633,    29,  1391,  -353,    83,     9,  -353,    43,   891,  -353,
      98,  -353,   135,    43,  2079,  -353,  -353,   -14,  -353,    94,
     955,  -353,   137,  1000,   118,   148,   115,   115,   115,   711,
     115,  -353,  -353,  -353,    91,    91,   196,  2002,   164,  -353,
     210,  2002,  1966,  1966,  2002,  2002,  2002,  2002,  2002,  2002,
    2002,  2002,  2002,  2002,  2002,   196,  2002,  2002,  2002,  2002,
    2002,  2002,  2002,  2002,  2002,  2002,  2002,  2002,  2002,  2002,
    -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,  -353,
    -353,  -353,  2002,  2002,  -353,  2002,  -353,  1000,  2002,  2002,
     168,  2002,    33,   196,    35,  -353,   133,  2002,   533,   196,
       8,  1785,  -353,  2002,  -353,  2002,  1673,   166,  -353,  1597,
      91,   169,   711,  -353,  -353,  1391,  2002,  -353,   170,   147,
    -353,   174,    56,   183,   158,   185,  2079,  1064,   242,   242,
     242,   242,  1479,   213,   378,   242,   167,   180,   167,   115,
     115,   115,   115,   115,   335,   444,   444,   242,   242,   242,
     242,   115,   242,  1391,  1435,  1391,  1391,  1709,     8,   135,
    -353,     8,   135,    39,  -353,   181,  -353,   108,  1927,    99,
      85,  -353,  -353,  -353,  -353,   955,  1391,  -353,  1109,  2002,
    -353,    13,    91,  1391,  1966,  -353,  1966,   163,  2002,  1966,
    -353,  1966,   172,  2002,  -353,  1173,   190,   190,     8,   135,
    2002,   195,  -353,  -353,   149,   173,   111,  -353,   165,  1859,
    -353,  -353,   211,   184,    36,   196,  -353,  -353,  -353,   214,
    -353,   191,   142,   218,   219,  -353,  -353,  1391,   218,   219,
    -353,  1435,  -353,     8,   204,   207,   190,  1237,   533,  -353,
     113,  -353,   187,  -353,   606,  -353,  2002,  -353,    15,   236,
     237,     3,  -353,    -6,  2002,  2002,    16,   215,  2002,   220,
     222,   223,  -353,  -353,   241,    91,  -353,  -353,  -353,  -353,
     196,   240,    26,  -353,  -353,  -353,   244,  -353,  -353,   533,
    2002,  1282,  1391,   193,  -353,  -353,  -353,  -353,  -353,    85,
     237,    28,  -353,   196,   245,    13,  -353,  -353,  1346,  2002,
     192,  -353,   196,   237,    30,  -353,  -353,   269,   533,  1391,
     273,  -353,   237,  -353,   196,    13,  -353,    91,  -353,   237,
      85,  -353,  -353
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
      88,   160,   162,   163,   210,   131,   165,   164,   166,     0,
      34,    26,    27,     0,     0,     0,     0,     0,     0,     0,
      25,    37,     0,     0,   135,     0,     0,     0,     0,     0,
     167,   215,   213,   214,    88,     3,     5,    60,    64,    65,
      57,     0,    63,    62,    61,    59,     0,    66,    23,     0,
      87,    86,    67,   209,    68,    85,     0,    58,    56,   161,
      30,     0,   170,   129,   159,     4,   212,     0,    28,    35,
       0,    39,   137,    77,     0,     0,    70,   117,     0,    73,
      71,    75,    78,   119,   208,    38,   176,     0,   140,     0,
     137,   169,     0,   137,     0,   134,   185,   186,   179,     0,
     187,     1,     2,   127,    22,    24,     0,     0,   128,   130,
       0,    31,   135,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     0,     0,   132,     0,   211,     0,     0,     0,
       0,    40,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,   173,     0,   177,     0,     0,   168,   171,     0,
      90,     0,     0,   126,   133,   136,     0,   141,   134,     0,
     146,   114,   159,   134,     0,   114,   206,     0,   204,   202,
     203,   205,   207,   191,   193,   196,   181,   175,   180,   182,
     188,   190,   189,   184,   192,   194,   195,   198,   199,   200,
     201,   183,   197,    43,   178,    29,    36,     0,     0,    79,
      69,     0,    81,     0,     9,   123,     8,     0,     0,     0,
       0,    72,    74,   174,   139,     0,   138,    32,   136,   135,
     172,   112,    89,   144,   142,   150,   113,     0,     0,   142,
     154,   113,     0,     0,    41,   136,   114,   114,     0,    82,
       0,     0,   125,    12,     0,    18,    21,    14,     0,    88,
       7,    33,   134,     0,     0,     0,   102,   111,    97,   114,
     100,     0,    91,   114,   114,   145,   153,   143,   114,   114,
     157,   118,    42,   113,     0,     0,   114,     0,     0,    13,
      20,    15,     0,    17,    88,    11,   142,   158,     0,   114,
     114,   113,    98,     0,     0,     0,   113,     0,   113,     0,
       0,     0,    80,    83,     0,     0,   124,    16,     6,    10,
       0,   114,   113,   106,   113,   110,   114,   101,    99,     0,
       0,    92,    93,     0,   151,   152,   155,   156,    84,     0,
     114,   113,   103,     0,   114,   113,    95,   115,     0,     0,
     120,   104,     0,   114,   113,   107,    96,   114,     0,    94,
       0,   122,   114,   108,     0,   113,   116,     0,   105,   114,
       0,   109,   121
  };

  const short
   Parser ::yypgoto_[] =
  {
    -353,  -353,   290,  -352,  -353,  -296,  -353,  -353,  -353,  -353,
    -263,  -353,  -353,  -353,  -353,   105,  -353,  -353,  -353,  -353,
    -353,  -164,   -12,  -162,   -76,  -353,  -353,  -353,  -353,  -353,
    -118,  -353,   -37,  -261,  -318,  -353,    47,  -353,  -353,  -353,
    -353,   -40,  -353,  -353,  -353,  -353,  -353,   307,    37,   159,
    -353,  -107,  -243,  -108,  -353,  -353,     1,    88,     0,   -32
  };

  const short
   Parser ::yydefgoto_[] =
  {
       0,    34,    35,   280,   234,   235,   314,   236,   237,   238,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     153,    46,    80,    81,    82,    75,    47,    48,    49,    50,
     286,   287,   288,   289,   290,   291,   322,    51,    52,    53,
      54,   272,    55,    56,    57,    58,    59,   187,    60,    88,
      89,   189,   190,   191,    61,    62,    72,    64,   240,    66
  };

  const short
   Parser ::yytable_[] =
  {
      65,    63,    74,   348,   239,   195,   194,   370,   242,     4,
      68,    69,   336,   295,     4,     4,   315,    78,   295,     4,
      84,     4,     4,    90,    93,   103,    96,    97,    98,    99,
     100,     4,     4,   156,     4,    63,     4,   171,   392,     4,
     164,     4,     4,   349,   106,     4,   104,     4,   105,   109,
      71,   339,    77,   367,   154,    83,   107,   341,   111,    87,
      92,    95,   172,   166,   154,   284,   285,   348,   157,   165,
      79,    93,   156,   156,   275,   284,   285,   350,   340,   186,
     161,   364,   386,   295,   346,    73,   229,   318,   232,   363,
     228,   372,   231,   384,   167,    79,   268,    79,  -148,   180,
     155,    79,    76,  -147,   377,    76,   112,   160,   182,   258,
     155,   169,   185,  -147,   162,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    85,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   242,   283,   163,   239,   173,   293,   110,   156,   188,
     193,   298,   266,   222,   223,   267,   224,   269,   163,   225,
     226,   108,   185,    76,   233,    31,   319,   320,   185,    63,
     174,    31,   185,   113,   245,   125,   246,   248,   128,   276,
     185,   279,   252,    32,    33,   239,   170,   253,   176,    32,
      33,   324,   306,   163,   181,   325,   178,   277,   278,   179,
     192,   192,     4,   347,   270,   271,   273,   274,   156,   311,
     312,   -19,   -19,   207,   239,   270,   380,   183,   184,   227,
     156,   254,   360,   249,   255,   256,   251,   125,   265,   127,
     128,   129,   130,   131,   259,   260,   261,  -149,   257,    63,
     296,   303,   262,   347,   308,   373,   258,   309,   139,   300,
      76,   230,    76,   310,   382,   185,   347,   241,    76,   297,
     185,   317,   316,   313,   301,   321,   389,   347,   323,   326,
     328,   307,   124,   125,   126,   127,   128,   129,   130,   131,
      63,   332,   133,   134,   333,   337,   282,   342,   344,   121,
     122,   361,   354,   294,   139,   365,   374,   355,   299,   356,
     357,   124,   125,   126,   127,   128,   129,   130,   131,    63,
     132,   133,   134,   304,   305,    63,    76,   185,   358,    76,
     385,    76,   387,   139,   102,   351,   352,   156,   376,   185,
     381,    94,   244,     0,     0,   359,     0,     0,     0,   292,
     327,   329,   192,     0,   192,   330,   331,   192,     0,   192,
      63,   368,     0,   334,     0,     0,    76,     0,   156,     0,
       0,     0,     0,     0,     0,     0,   343,   345,     0,     0,
     379,     0,   292,   292,     0,     0,     0,     0,     0,    63,
       0,     0,   121,   122,     0,     0,     0,   390,   362,     0,
       0,    76,     0,   366,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,   133,   134,   292,   371,     0,   292,
       0,   375,     0,     0,   353,     0,   139,     0,     0,     0,
     383,     0,     0,     0,     0,   121,     0,     0,   292,   388,
     292,     0,     0,     0,     0,     0,   391,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,   133,   134,   292,
       0,   292,     0,   292,     0,     0,     0,     0,     0,   139,
     292,     0,   292,     1,     2,     3,     4,     0,     5,     6,
       7,     8,   292,   292,     9,    10,     0,     0,    11,     0,
      12,     0,    13,     0,     0,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    18,    19,     0,
      20,    21,     0,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,    26,    27,     0,    28,   139,     0,    29,     0,     0,
       0,     0,     0,     0,     0,    30,     1,     2,     3,     4,
      31,     5,     6,     7,     8,     0,     0,     9,    10,     0,
       0,    11,     0,    12,     0,    13,     0,     0,    32,    33,
       0,    14,    15,     0,    17,     0,     0,     0,     0,     0,
      18,    19,     0,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,     0,    26,    27,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,    30,     1,
       2,     3,     4,    31,     5,     6,     7,     8,     0,     0,
       9,    10,     0,     0,    11,     0,    12,     0,    13,     0,
       0,    32,    33,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,    18,    19,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
       0,     0,    22,    23,    24,    25,     0,    26,    27,     0,
      28,     0,     0,    29,     0,   115,     0,   116,   117,   118,
     119,    30,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,     0,  -137,     0,  -137,     0,
     123,     0,     0,   338,   124,   125,   126,   127,   128,   129,
     130,   131,     0,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,   114,     0,     0,   139,     0,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   115,     0,   116,   117,   118,   119,   152,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,   131,     0,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,    31,   139,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,   115,   152,   116,   117,   118,   119,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,   121,
     122,     0,     0,   158,     0,     0,     0,   123,     0,     0,
       0,   124,   125,   126,   127,   128,   129,   130,   131,     0,
     132,   133,   134,   135,   136,   137,   138,     0,   114,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,     0,   115,     0,   116,   117,
     118,   119,     0,     0,   152,   120,     0,     0,     0,     0,
       0,     0,     0,   121,   122,     0,     0,     0,     0,     0,
       0,   123,     0,   114,     0,   124,   125,   126,   127,   128,
     129,   130,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   115,     0,   116,   117,   118,   119,   139,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     168,     0,     0,     0,     0,     0,   123,     0,   152,     0,
     124,   125,   126,   127,   128,   129,   130,   131,     0,   132,
     133,   134,   135,   136,   137,   138,     0,   114,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,   116,   117,   118,
     119,     0,     0,   152,   120,     0,     0,     0,     0,     0,
       0,     0,   121,   122,   175,     0,     0,     0,     0,     0,
     123,     0,   114,     0,   124,   125,   126,   127,   128,   129,
     130,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     115,     0,   116,   117,   118,   119,   139,     0,     0,   120,
       0,     0,     0,     0,     0,     0,     0,   121,   122,     0,
       0,     0,     0,     0,     0,   123,     0,   152,     0,   124,
     125,   126,   127,   128,   129,   130,   131,     0,   132,   133,
     134,   135,   136,   137,   138,     0,   114,   177,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,   263,     0,
       0,     0,     0,     0,   115,     0,   116,   117,   118,   119,
       0,     0,   152,   120,     0,     0,     0,     0,     0,     0,
       0,   121,   122,     0,     0,     0,     0,     0,     0,   123,
       0,   114,     0,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   115,
       0,   116,   117,   118,   119,   139,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,   121,   122,     0,     0,
       0,     0,     0,     0,   123,     0,   152,     0,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   132,   133,   134,
     135,   136,   137,   138,     0,   114,   281,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,     0,   116,   117,   118,   119,     0,
       0,   152,   120,     0,     0,     0,     0,     0,     0,     0,
     121,   122,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,   131,
       0,   132,   133,   134,   135,   136,   137,   138,     0,   114,
     302,     0,     0,     0,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,   116,
     117,   118,   119,     0,     0,   152,   120,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   335,     0,     0,     0,
       0,     0,   123,     0,   114,     0,   124,   125,   126,   127,
     128,   129,   130,   131,     0,   132,   133,   134,   135,   136,
     137,   138,   115,     0,   116,   117,   118,   119,   139,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,   121,
     122,     0,     0,     0,     0,   369,     0,   123,     0,   152,
       0,   124,   125,   126,   127,   128,   129,   130,   131,     0,
     132,   133,   134,   135,   136,   137,   138,     0,   114,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,   116,   117,
     118,   119,     0,     0,   152,   120,     0,     0,     0,     0,
       0,     0,     0,   121,   122,   378,     0,     0,     0,     0,
       0,   123,     0,   114,     0,   124,   125,   126,   127,   128,
     129,   130,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   115,     0,   116,   117,   118,   119,   139,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
       0,     0,     0,     0,     0,     0,   123,   114,   152,     0,
     124,   125,   126,   127,   128,   129,   130,   131,     0,   132,
     133,   134,   135,   136,   137,   138,     0,   116,   117,   118,
     119,     0,   139,     0,   120,     0,     0,     0,     0,     0,
       0,     0,   121,   122,     0,     0,     0,     0,     0,     0,
     123,   114,     0,   152,   124,   125,   126,   127,   128,   129,
     130,   131,     0,   132,   133,   134,   135,   136,   137,   138,
       0,   116,   117,   118,   119,     0,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,   122,     0,     0,
       0,     0,     0,     0,   123,     0,     0,   152,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,   101,     0,
     139,     1,     2,     3,     4,     0,     5,     6,     7,     8,
       0,     0,     9,    10,     0,     0,    11,     0,    12,     0,
      13,   152,     0,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,    18,    19,     0,    20,    21,
       1,     2,     3,     4,     0,     5,     6,     7,     8,     0,
       0,     0,     0,     0,    22,    23,    24,    25,     0,    26,
      27,     0,    28,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    19,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    67,    24,    25,     0,    26,    27,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,    19,    30,     0,     0,   250,     1,     2,     3,     4,
       0,     5,     6,     7,     8,     0,     0,     0,     0,    22,
      67,    24,    25,     0,    26,    27,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      91,    19,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      67,    24,    25,     0,    26,    27,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,    19,    30,     0,
     247,     0,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     0,     0,    22,    67,    24,    25,     0,
      26,    27,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    30,     0,   264,    19,     1,     2,
       3,     4,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    67,    24,    25,     0,
      26,    27,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,    19,    30,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    67,    24,    25,     0,    26,    27,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
      30,   243,     1,     2,     3,     4,     0,     5,     6,     7,
       8,     0,     0,     9,    10,     0,     0,    11,     0,    12,
       0,    13,     0,     0,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,    18,    19,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,     0,
      26,    27,     0,    28,     0,     0,    29,     0,     0,     0,
       1,     2,     3,     4,    30,     5,     6,     7,     8,     0,
       0,     9,    10,     0,     0,    11,     0,    12,     0,    13,
       0,     0,     0,     0,     0,    14,    15,     0,    17,     0,
       0,     0,     0,     0,    18,    19,     0,    20,    21,     1,
       2,     3,     4,     0,     5,     6,     7,     8,     0,     0,
       0,     0,     0,    22,    23,    24,    25,     0,    26,    27,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,    30,     0,    19,     1,     2,     3,     4,     0,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    67,    24,    25,     0,    26,    27,   186,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      19,    30,     0,     1,     2,     3,     4,     0,     5,     6,
       7,     8,     0,     0,     0,     0,     0,     0,    22,    67,
      24,    25,     0,    26,    27,     1,     2,     3,     4,    29,
       5,     6,     7,     8,     0,     0,     0,    30,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    70,    24,    25,
      19,    26,    27,     0,     0,     0,     0,    29,     0,     0,
       0,   116,   117,   118,   119,    30,     0,     0,    22,    23,
      24,    25,     0,    26,    27,     0,   121,   122,     0,    29,
       0,     0,     0,     0,   123,     0,     0,    30,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152
  };

  const short
   Parser ::yycheck_[] =
  {
       0,     0,    14,   321,   168,   113,   113,   359,   170,     6,
       9,    10,   308,   256,     6,     6,   279,    16,   261,     6,
      19,     6,     6,    22,    23,    53,    25,    26,    27,    28,
      29,     6,     6,    65,     6,    34,     6,    51,   390,     6,
      31,     6,     6,    49,    21,     6,    46,     6,    48,     8,
      13,   314,    15,   349,     8,    18,    64,   318,    51,    22,
      23,    24,    76,    75,     8,    62,    63,   385,    67,    60,
      62,    70,   104,   105,   238,    62,    63,    83,    63,    63,
      51,   342,   378,   326,    81,    60,   162,    51,   164,    63,
      57,    63,    57,    63,    51,    62,    57,    62,    57,    99,
      54,    62,    14,    57,   365,    17,    57,    70,   107,    53,
      54,    13,   111,    57,    31,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    21,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   303,   249,    60,   308,    51,   254,    59,   180,   112,
     113,   259,   228,   152,   153,   231,   155,   233,    60,   158,
     159,    56,   161,    75,    31,    80,   284,   285,   167,   168,
      76,    80,   171,    57,   173,    60,   175,   176,    63,    80,
     179,    96,   182,    98,    99,   349,    51,   186,    51,    98,
      99,    49,   268,    60,   106,    53,    78,    98,    99,    51,
     112,   113,     6,   321,    23,    24,    98,    99,   240,    98,
      99,    98,    99,   125,   378,    23,    24,    53,     8,    51,
     252,    51,   340,    57,    77,    51,    57,    60,   227,    62,
      63,    64,    65,    66,    51,    77,    51,    57,   191,   238,
      77,    51,   195,   361,    49,   363,    53,    98,    81,    77,
     162,   163,   164,    80,   372,   254,   374,   169,   170,   258,
     259,    77,    51,    98,   263,    51,   384,   385,    77,    51,
      51,   270,    59,    60,    61,    62,    63,    64,    65,    66,
     279,    77,    69,    70,    77,    98,   249,    51,    51,    47,
      48,    51,    77,   256,    81,    51,    51,    77,   261,    77,
      77,    59,    60,    61,    62,    63,    64,    65,    66,   308,
      68,    69,    70,   266,   267,   314,   228,   316,    77,   231,
      51,   233,    49,    81,    34,   324,   325,   359,   365,   328,
     370,    24,   173,    -1,    -1,   335,    -1,    -1,    -1,   251,
     293,   294,   254,    -1,   256,   298,   299,   259,    -1,   261,
     349,   350,    -1,   306,    -1,    -1,   268,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   319,   320,    -1,    -1,
     369,    -1,   284,   285,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,    47,    48,    -1,    -1,    -1,   387,   341,    -1,
      -1,   303,    -1,   346,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    69,    70,   318,   360,    -1,   321,
      -1,   364,    -1,    -1,   326,    -1,    81,    -1,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    47,    -1,    -1,   340,   382,
     342,    -1,    -1,    -1,    -1,    -1,   389,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    69,    70,   361,
      -1,   363,    -1,   365,    -1,    -1,    -1,    -1,    -1,    81,
     372,    -1,   374,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,   384,   385,    14,    15,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    61,    62,    -1,    64,    81,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,     3,     4,     5,     6,
      80,     8,     9,    10,    11,    -1,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    98,    99,
      -1,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,     3,
       4,     5,     6,    80,     8,     9,    10,    11,    -1,    -1,
      14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,
      -1,    98,    99,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    -1,
      64,    -1,    -1,    67,    -1,    30,    -1,    32,    33,    34,
      35,    75,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    51,    -1,    53,    -1,
      55,    -1,    -1,    97,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    12,    -1,    -1,    81,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    30,    -1,    32,    33,    34,    35,   102,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    81,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    30,   102,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    51,    -1,    -1,    -1,    55,    -1,    -1,
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
      55,    -1,    12,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      30,    -1,    32,    33,    34,    35,    81,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,   102,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    12,    77,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      -1,    -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    12,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    30,
      -1,    32,    33,    34,    35,    81,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,   102,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    12,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    -1,
      -1,   102,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    12,
      77,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    -1,    -1,   102,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
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
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    12,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    30,    -1,    32,    33,    34,    35,    81,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    12,   102,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    32,    33,    34,
      35,    -1,    81,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    12,    -1,   102,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    32,    33,    34,    35,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,   102,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,     0,    -1,
      81,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,
      22,   102,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,
      62,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    38,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    75,    -1,    -1,    78,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      77,    38,     3,     4,     5,     6,    -1,     8,     9,    10,
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
      -1,    -1,    -1,    38,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    14,    15,    -1,    -1,    18,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    -1,    -1,
       3,     4,     5,     6,    75,     8,     9,    10,    11,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    38,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    75,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,     3,     4,     5,     6,    67,
       8,     9,    10,    11,    -1,    -1,    -1,    75,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      38,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    32,    33,    34,    35,    75,    -1,    -1,    56,    57,
      58,    59,    -1,    61,    62,    -1,    47,    48,    -1,    67,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    75,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     8,     9,    10,    11,    14,
      15,    18,    20,    22,    28,    29,    30,    31,    37,    38,
      40,    41,    56,    57,    58,    59,    61,    62,    64,    67,
      75,    80,    98,    99,   105,   106,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   125,   130,   131,   132,
     133,   141,   142,   143,   144,   146,   147,   148,   149,   150,
     152,   158,   159,   160,   161,   162,   163,    57,   160,   160,
      57,   152,   160,    60,   126,   129,   161,   152,   160,    62,
     126,   127,   128,   152,   160,   119,    76,   152,   153,   154,
     160,    77,   152,   160,   151,   152,   160,   160,   160,   160,
     160,     0,   106,    53,   162,   162,    21,    64,   119,     8,
     161,    51,    57,    57,    12,    30,    32,    33,    34,    35,
      39,    47,    48,    55,    59,    60,    61,    62,    63,    64,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    81,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   102,   124,     8,    54,   163,   160,    51,    28,
     152,    51,    31,    60,    31,    60,   126,    51,    49,    13,
      51,    51,    76,    51,    76,    49,    51,    77,    78,    51,
     162,   161,   160,    53,     8,   160,    63,   151,   152,   155,
     156,   157,   161,   152,   155,   157,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,    51,    57,   128,
     161,    57,   128,    31,   108,   109,   111,   112,   113,   125,
     162,   161,   127,    76,   153,   160,   160,    77,   160,    57,
      78,    57,   162,   160,    51,    77,    51,   140,    53,    51,
      77,    51,   140,    24,    77,   160,   128,   128,    57,   128,
      23,    24,   145,    98,    99,   125,    80,    98,    99,    96,
     107,    77,   152,   155,    62,    63,   134,   135,   136,   137,
     138,   139,   161,   157,   152,   156,    77,   160,   157,   152,
      77,   160,    77,    51,   140,   140,   128,   160,    49,    98,
      80,    98,    99,    98,   110,   114,    51,    77,    51,   134,
     134,    51,   140,    77,    49,    53,    51,   140,    51,   140,
     140,   140,    77,    77,   140,    49,   109,    98,    97,   114,
      63,   137,    51,   140,    51,   140,    81,   134,   138,    49,
      83,   160,   160,   161,    77,    77,    77,    77,    77,   162,
     134,    51,   140,    63,   137,    51,   140,   109,   160,    53,
     107,   140,    63,   134,    51,   140,   136,   137,    49,   160,
      24,   145,   134,   140,    63,    51,   109,    49,   140,   134,
     162,   140,   107
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,   104,   105,   105,   105,   106,   107,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   115,   116,   117,   118,   118,
     119,   119,   119,   119,   120,   120,   120,   121,   121,   122,
     122,   122,   122,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   135,   135,   135,   136,   136,
     136,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   140,   140,   141,   141,   142,   143,   144,
     145,   145,   145,   146,   146,   146,   147,   147,   148,   149,
     150,   150,   150,   150,   151,   151,   152,   152,   153,   154,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   162,   162,   163,   163,   163
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     3,     2,     1,     1,
       2,     1,     2,     3,     2,     3,     4,     3,     2,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     2,     4,
       1,     2,     4,     5,     1,     2,     4,     1,     2,     2,
       3,     5,     6,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     3,     1,     2,     1,     2,     4,
       7,     4,     5,     7,     8,     1,     1,     1,     0,     4,
       3,     1,     3,     3,     5,     4,     5,     1,     2,     3,
       1,     3,     1,     4,     5,     7,     3,     5,     6,     8,
       3,     1,     0,     1,     0,     8,    10,     2,     5,     2,
       5,     9,     6,     4,     7,     5,     3,     2,     2,     1,
       2,     1,     2,     3,     1,     0,     3,     1,     3,     3,
       1,     1,     2,     3,     2,     3,     1,     1,     1,     3,
       4,     7,     7,     5,     4,     7,     7,     5,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     3,     4,     3,     4,     3,     2,     3,     3,     2,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       1,     2,     1,     1,     1,     1
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
  "tuple_item", "raise_statement", "return_statement", "delete_statement",
  "augassign_statement", "augassign_op", "single_line_statement", "module",
  "module_as_id", "module_item_list", "dot_list", "import_statement",
  "multi_line_statement", "decorators_opt", "decorators", "parameter",
  "parameter_list", "parameter_list_no_posonly", "defparameter_list",
  "parameter_list_starargs", "parameter_list_opt", "comma_opt",
  "function_def", "global_statement", "ternary_if_statement",
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
       0,   290,   290,   291,   292,   296,   300,   304,   308,   309,
     313,   314,   318,   319,   320,   321,   324,   327,   333,   336,
     342,   345,   351,   352,   353,   358,   362,   366,   370,   371,
     375,   376,   377,   378,   382,   383,   384,   388,   389,   394,
     395,   396,   398,   404,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   423,   425,   426,   427,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   442,
     443,   447,   448,   449,   453,   454,   458,   459,   465,   466,
     468,   470,   472,   474,   476,   481,   485,   494,   495,   499,
     500,   504,   505,   506,   507,   511,   513,   515,   519,   520,
     522,   526,   527,   535,   536,   537,   539,   540,   542,   544,
     546,   550,   551,   555,   556,   560,   562,   573,   577,   581,
     585,   586,   588,   593,   596,   599,   604,   605,   609,   614,
     622,   623,   626,   629,   635,   636,   640,   641,   651,   655,
     656,   660,   661,   666,   667,   671,   672,   677,   678,   679,
     683,   684,   686,   688,   689,   690,   692,   694,   701,   705,
     706,   710,   711,   712,   716,   717,   718,   719,   720,   721,
     722,   724,   725,   726,   727,   728,   730,   731,   735,   736,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   750,   751,   752,   753,   754,   756,   757,   758,   759,
     760,   761,   762,   763,   764,   765,   767,   768,   769,   776,
     781,   785,   786,   790,   791,   792
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
#line 3472 "./parser.cpp"

#line 795 "parser.ypp"
