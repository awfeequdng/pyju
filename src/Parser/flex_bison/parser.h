// A Bison parser, made by GNU Bison 3.8.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file ./parser.h
 ** Define the  PYJU ::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 60 "parser.ypp"

  #include <optional>

  #include "ast/ast.h"
  #include "base/arena.h"
  #include "base/nonnull.h"
  #include "Parser/flex_bison/semantics.h"
  #include "Parser/flex_bison/parser.h"

  namespace PYJU {
  class ParseAndLexContext;
  }  // namespace PYJU

  typedef void* yyscan_t;

#line 65 "./parser.h"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 21 "parser.ypp"
namespace  PYJU  {
#line 201 "./parser.h"


  /// A point in a source file.
  class position
  {
  public:
    /// Type for file name.
    typedef const std::string filename_type;
    /// Type for line and column numbers.
    typedef int counter_type;

    /// Construct a position.
    explicit position (filename_type* f = YY_NULLPTR,
                       counter_type l = 1,
                       counter_type c = 1)
      : filename (f)
      , line (l)
      , column (c)
    {}


    /// Initialization.
    void initialize (filename_type* fn = YY_NULLPTR,
                     counter_type l = 1,
                     counter_type c = 1)
    {
      filename = fn;
      line = l;
      column = c;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    void lines (counter_type count = 1)
    {
      if (count)
        {
          column = 1;
          line = add_ (line, count, 1);
        }
    }

    /// (column related) Advance to the COUNT next columns.
    void columns (counter_type count = 1)
    {
      column = add_ (column, count, 1);
    }
    /** \} */

    /// File name to which this position refers.
    filename_type* filename;
    /// Current line number.
    counter_type line;
    /// Current column number.
    counter_type column;

  private:
    /// Compute max (min, lhs+rhs).
    static counter_type add_ (counter_type lhs, counter_type rhs, counter_type min)
    {
      return lhs + rhs < min ? min : lhs + rhs;
    }
  };

  /// Add \a width columns, in place.
  inline position&
  operator+= (position& res, position::counter_type width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns.
  inline position
  operator+ (position res, position::counter_type width)
  {
    return res += width;
  }

  /// Subtract \a width columns, in place.
  inline position&
  operator-= (position& res, position::counter_type width)
  {
    return res += -width;
  }

  /// Subtract \a width columns.
  inline position
  operator- (position res, position::counter_type width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param pos a reference to the position to redirect
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const position& pos)
  {
    if (pos.filename)
      ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
  }

  /// Two points in a source file.
  class location
  {
  public:
    /// Type for file name.
    typedef position::filename_type filename_type;
    /// Type for line and column numbers.
    typedef position::counter_type counter_type;

    /// Construct a location from \a b to \a e.
    location (const position& b, const position& e)
      : begin (b)
      , end (e)
    {}

    /// Construct a 0-width location in \a p.
    explicit location (const position& p = position ())
      : begin (p)
      , end (p)
    {}

    /// Construct a 0-width location in \a f, \a l, \a c.
    explicit location (filename_type* f,
                       counter_type l = 1,
                       counter_type c = 1)
      : begin (f, l, c)
      , end (f, l, c)
    {}


    /// Initialization.
    void initialize (filename_type* f = YY_NULLPTR,
                     counter_type l = 1,
                     counter_type c = 1)
    {
      begin.initialize (f, l, c);
      end = begin;
    }

    /** \name Line and Column related manipulators
     ** \{ */
  public:
    /// Reset initial location to final location.
    void step ()
    {
      begin = end;
    }

    /// Extend the current location to the COUNT next columns.
    void columns (counter_type count = 1)
    {
      end += count;
    }

    /// Extend the current location to the COUNT next lines.
    void lines (counter_type count = 1)
    {
      end.lines (count);
    }
    /** \} */


  public:
    /// Beginning of the located region.
    position begin;
    /// End of the located region.
    position end;
  };

  /// Join two locations, in place.
  inline location&
  operator+= (location& res, const location& end)
  {
    res.end = end.end;
    return res;
  }

  /// Join two locations.
  inline location
  operator+ (location res, const location& end)
  {
    return res += end;
  }

  /// Add \a width columns to the end position, in place.
  inline location&
  operator+= (location& res, location::counter_type width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns to the end position.
  inline location
  operator+ (location res, location::counter_type width)
  {
    return res += width;
  }

  /// Subtract \a width columns to the end position, in place.
  inline location&
  operator-= (location& res, location::counter_type width)
  {
    return res += -width;
  }

  /// Subtract \a width columns to the end position.
  inline location
  operator- (location res, location::counter_type width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param loc a reference to the location to redirect
   **
   ** Avoid duplicate information.
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const location& loc)
  {
    location::counter_type end_col
      = 0 < loc.end.column ? loc.end.column - 1 : 0;
    ostr << loc.begin;
    if (loc.end.filename
        && (!loc.begin.filename
            || *loc.begin.filename != *loc.end.filename))
      ostr << '-' << loc.end.filename << ':' << loc.end.line << '.' << end_col;
    else if (loc.begin.line < loc.end.line)
      ostr << '-' << loc.end.line << '.' << end_col;
    else if (loc.begin.column < end_col)
      ostr << '-' << end_col;
    return ostr;
  }


  /// A Bison parser.
  class  Parser 
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // module_as_id
      char dummy1[sizeof (Nonnull<Alias*>)];

      // parameter
      char dummy2[sizeof (Nonnull<Arg*>)];

      // parameter_list_opt
      char dummy3[sizeof (Nonnull<Arguments*>)];

      // tuple_item
      // for_tuple_item
      // ternary_if_statement
      // string
      // primary
      // function_call
      // expr
      char dummy4[sizeof (Nonnull<Expression*>)];

      // parameter_list
      char dummy5[sizeof (Nonnull<FnArg*>)];

      // keyword_item
      char dummy6[sizeof (Nonnull<Keyword*>)];

      // id
      char dummy7[sizeof (Nonnull<Name*>)];

      // parameter_list_no_posonly
      char dummy8[sizeof (Nonnull<NoPosOnlyArg*>)];

      // parameter_list_starargs
      char dummy9[sizeof (Nonnull<StarArg*>)];

      // script_unit
      // statement
      // pass_statement
      // break_statement
      // continue_statement
      // assert_statement
      // raise_statement
      // return_statement
      // delete_statement
      // augassign_statement
      // ann_assignment_statement
      // single_line_statement
      // import_statement
      // while_statement
      // for_statement
      // except_statement
      // try_statement
      // with_item
      // with_statement
      // multi_line_statement
      // function_def
      // global_statement
      // nonlocal_statement
      // elif_statement
      // if_statement
      // assignment_statement
      // expression_statment
      char dummy10[sizeof (Nonnull<Statement*>)];

      // dict
      char dummy11[sizeof (PairNonnullExpr)];

      // real_literal
      // image_literal
      char dummy12[sizeof (double)];

      // integer_literal
      char dummy13[sizeof (long long)];

      // augassign_op
      char dummy14[sizeof (operatorType)];

      // identifier
      // sized_type_literal
      // string_literal
      // sep_one
      char dummy15[sizeof (std::string)];

      // module_item_list
      char dummy16[sizeof (std::vector<Nonnull<Alias*>>)];

      // defparameter_list
      char dummy17[sizeof (std::vector<Nonnull<Arg*>>)];

      // module
      // decorators_opt
      // decorators
      // target_list
      // expr_list_opt
      // expr_list
      // expr_for_list
      // call_arguement_list
      char dummy18[sizeof (std::vector<Nonnull<Expression*>>)];

      // keyword_items
      char dummy19[sizeof (std::vector<Nonnull<Keyword*>>)];

      // statements
      // sep_statements
      // body_stmts
      // statements1
      // single_line_statements
      // single_line_multi_statements
      // single_line_multi_statements_opt
      // except_list
      // with_item_list
      char dummy20[sizeof (std::vector<Nonnull<Statement*>>)];

      // dict_list
      char dummy21[sizeof (std::vector<PairNonnullExpr>)];

      // sep
      char dummy22[sizeof (std::vector<std::string>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END_OF_FILE = 0,               // END_OF_FILE
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    integer_literal = 258,         // integer_literal
    real_literal = 259,            // real_literal
    image_literal = 260,           // image_literal
    identifier = 261,              // identifier
    sized_type_literal = 262,      // sized_type_literal
    string_literal = 263,          // string_literal
    FALSE = 264,                   // FALSE
    TRUE = 265,                    // TRUE
    NONE = 266,                    // NONE
    AND = 267,                     // "and"
    AS = 268,                      // AS
    ASSERT = 269,                  // ASSERT
    RAISE = 270,                   // RAISE
    ASYNC = 271,                   // ASYNC
    AWAIT = 272,                   // AWAIT
    BREAK = 273,                   // BREAK
    CLASS = 274,                   // CLASS
    CONTINUE = 275,                // CONTINUE
    DEF = 276,                     // DEF
    DEL = 277,                     // DEL
    ELIF = 278,                    // ELIF
    ELSE = 279,                    // ELSE
    EXCEPT = 280,                  // EXCEPT
    FINALLY = 281,                 // FINALLY
    FOR = 282,                     // FOR
    FROM = 283,                    // FROM
    GLOBAL = 284,                  // GLOBAL
    IF = 285,                      // IF
    IMPORT = 286,                  // IMPORT
    IN = 287,                      // "in"
    IS = 288,                      // "is"
    IS_NOT = 289,                  // "is not"
    NOT_IN = 290,                  // "not in"
    LAMBDA = 291,                  // LAMBDA
    NONLOCAL = 292,                // NONLOCAL
    NOT = 293,                     // "not"
    OR = 294,                      // "or"
    PASS = 295,                    // PASS
    RETURN = 296,                  // RETURN
    TRY = 297,                     // TRY
    WHILE = 298,                   // WHILE
    WITH = 299,                    // WITH
    YIELD = 300,                   // YIELD
    ARROW = 301,                   // ARROW
    AMPERSAND = 302,               // "&"
    CARET = 303,                   // "^"
    COLON = 304,                   // ":"
    COLON_BANG = 305,              // ":!"
    COMMA = 306,                   // ","
    DOUBLE_ARROW = 307,            // "=>"
    EQUAL = 308,                   // "="
    COLONEQUAL = 309,              // ":="
    EQUAL_EQUAL = 310,             // "=="
    LBRACE = 311,                  // "{"
    LPARENT = 312,                 // "("
    LBRACKET = 313,                // "["
    MINUS = 314,                   // "-"
    PERIOD = 315,                  // "."
    PLUS = 316,                    // "+"
    STAR = 317,                    // "*"
    POW = 318,                     // "**"
    AT = 319,                      // "@"
    FLOOR_DIV = 320,               // "//"
    MOD = 321,                     // "%"
    TILDE = 322,                   // "~"
    VBAR = 323,                    // "|"
    LSHIFT = 324,                  // "<<"
    RSHIFT = 325,                  // ">>"
    LOWER_THEN = 326,              // "<"
    LOWER_EQUAL = 327,             // "<="
    GREATER_THEN = 328,            // ">"
    GREATER_EQUAL = 329,           // ">="
    ELLIPSIS = 330,                // "..."
    RBRACE = 331,                  // "}"
    RPARENT = 332,                 // ")"
    RBRACKET = 333,                // "]"
    SELF = 334,                    // "self"
    SEMICOLON = 335,               // ";"
    SLASH = 336,                   // "/"
    UNDERSCORE = 337,              // "_"
    RARROW = 338,                  // "->"
    PLUS_EQUAL = 339,              // "+="
    MIN_EQUAL = 340,               // "-="
    STAR_EQUAL = 341,              // "*="
    SLASH_EQUAL = 342,             // "/="
    PERCENT_EQUAL = 343,           // "%="
    AMPER_EQUAL = 344,             // "&="
    VBAR_EQUAL = 345,              // "|="
    CARET_EQUAL = 346,             // "^="
    LEFTSHIFT_EQUAL = 347,         // "<<="
    RIGHTSHIFT_EQUAL = 348,        // ">>="
    POW_EQUAL = 349,               // "**="
    DOUBLESLASH_EQUAL = 350,       // "//="
    INDENT = 351,                  // INDENT
    DEDENT = 352,                  // DEDENT
    NEWLINE = 353,                 // NEWLINE
    COMMENT = 354,                 // COMMENT
    EOLCOMMENT = 355,              // EOLCOMMENT
    TYPE_COMMENT = 356,            // TYPE_COMMENT
    UNARY = 358                    // UNARY
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 104, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END_OF_FILE
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_integer_literal = 3,                   // integer_literal
        S_real_literal = 4,                      // real_literal
        S_image_literal = 5,                     // image_literal
        S_identifier = 6,                        // identifier
        S_sized_type_literal = 7,                // sized_type_literal
        S_string_literal = 8,                    // string_literal
        S_FALSE = 9,                             // FALSE
        S_TRUE = 10,                             // TRUE
        S_NONE = 11,                             // NONE
        S_AND = 12,                              // "and"
        S_AS = 13,                               // AS
        S_ASSERT = 14,                           // ASSERT
        S_RAISE = 15,                            // RAISE
        S_ASYNC = 16,                            // ASYNC
        S_AWAIT = 17,                            // AWAIT
        S_BREAK = 18,                            // BREAK
        S_CLASS = 19,                            // CLASS
        S_CONTINUE = 20,                         // CONTINUE
        S_DEF = 21,                              // DEF
        S_DEL = 22,                              // DEL
        S_ELIF = 23,                             // ELIF
        S_ELSE = 24,                             // ELSE
        S_EXCEPT = 25,                           // EXCEPT
        S_FINALLY = 26,                          // FINALLY
        S_FOR = 27,                              // FOR
        S_FROM = 28,                             // FROM
        S_GLOBAL = 29,                           // GLOBAL
        S_IF = 30,                               // IF
        S_IMPORT = 31,                           // IMPORT
        S_IN = 32,                               // "in"
        S_IS = 33,                               // "is"
        S_IS_NOT = 34,                           // "is not"
        S_NOT_IN = 35,                           // "not in"
        S_LAMBDA = 36,                           // LAMBDA
        S_NONLOCAL = 37,                         // NONLOCAL
        S_NOT = 38,                              // "not"
        S_OR = 39,                               // "or"
        S_PASS = 40,                             // PASS
        S_RETURN = 41,                           // RETURN
        S_TRY = 42,                              // TRY
        S_WHILE = 43,                            // WHILE
        S_WITH = 44,                             // WITH
        S_YIELD = 45,                            // YIELD
        S_ARROW = 46,                            // ARROW
        S_AMPERSAND = 47,                        // "&"
        S_CARET = 48,                            // "^"
        S_COLON = 49,                            // ":"
        S_COLON_BANG = 50,                       // ":!"
        S_COMMA = 51,                            // ","
        S_DOUBLE_ARROW = 52,                     // "=>"
        S_EQUAL = 53,                            // "="
        S_COLONEQUAL = 54,                       // ":="
        S_EQUAL_EQUAL = 55,                      // "=="
        S_LBRACE = 56,                           // "{"
        S_LPARENT = 57,                          // "("
        S_LBRACKET = 58,                         // "["
        S_MINUS = 59,                            // "-"
        S_PERIOD = 60,                           // "."
        S_PLUS = 61,                             // "+"
        S_STAR = 62,                             // "*"
        S_POW = 63,                              // "**"
        S_AT = 64,                               // "@"
        S_FLOOR_DIV = 65,                        // "//"
        S_MOD = 66,                              // "%"
        S_TILDE = 67,                            // "~"
        S_VBAR = 68,                             // "|"
        S_LSHIFT = 69,                           // "<<"
        S_RSHIFT = 70,                           // ">>"
        S_LOWER_THEN = 71,                       // "<"
        S_LOWER_EQUAL = 72,                      // "<="
        S_GREATER_THEN = 73,                     // ">"
        S_GREATER_EQUAL = 74,                    // ">="
        S_ELLIPSIS = 75,                         // "..."
        S_RBRACE = 76,                           // "}"
        S_RPARENT = 77,                          // ")"
        S_RBRACKET = 78,                         // "]"
        S_SELF = 79,                             // "self"
        S_SEMICOLON = 80,                        // ";"
        S_SLASH = 81,                            // "/"
        S_UNDERSCORE = 82,                       // "_"
        S_RARROW = 83,                           // "->"
        S_PLUS_EQUAL = 84,                       // "+="
        S_MIN_EQUAL = 85,                        // "-="
        S_STAR_EQUAL = 86,                       // "*="
        S_SLASH_EQUAL = 87,                      // "/="
        S_PERCENT_EQUAL = 88,                    // "%="
        S_AMPER_EQUAL = 89,                      // "&="
        S_VBAR_EQUAL = 90,                       // "|="
        S_CARET_EQUAL = 91,                      // "^="
        S_LEFTSHIFT_EQUAL = 92,                  // "<<="
        S_RIGHTSHIFT_EQUAL = 93,                 // ">>="
        S_POW_EQUAL = 94,                        // "**="
        S_DOUBLESLASH_EQUAL = 95,                // "//="
        S_INDENT = 96,                           // INDENT
        S_DEDENT = 97,                           // DEDENT
        S_NEWLINE = 98,                          // NEWLINE
        S_COMMENT = 99,                          // COMMENT
        S_EOLCOMMENT = 100,                      // EOLCOMMENT
        S_TYPE_COMMENT = 101,                    // TYPE_COMMENT
        S_102_ = 102,                            // "!="
        S_UNARY = 103,                           // UNARY
        S_YYACCEPT = 104,                        // $accept
        S_units = 105,                           // units
        S_script_unit = 106,                     // script_unit
        S_statements = 107,                      // statements
        S_sep_statements = 108,                  // sep_statements
        S_body_stmts = 109,                      // body_stmts
        S_statements1 = 110,                     // statements1
        S_single_line_statements = 111,          // single_line_statements
        S_single_line_multi_statements = 112,    // single_line_multi_statements
        S_single_line_multi_statements_opt = 113, // single_line_multi_statements_opt
        S_statement = 114,                       // statement
        S_pass_statement = 115,                  // pass_statement
        S_break_statement = 116,                 // break_statement
        S_continue_statement = 117,              // continue_statement
        S_assert_statement = 118,                // assert_statement
        S_tuple_item = 119,                      // tuple_item
        S_for_tuple_item = 120,                  // for_tuple_item
        S_raise_statement = 121,                 // raise_statement
        S_return_statement = 122,                // return_statement
        S_delete_statement = 123,                // delete_statement
        S_augassign_statement = 124,             // augassign_statement
        S_augassign_op = 125,                    // augassign_op
        S_ann_assignment_statement = 126,        // ann_assignment_statement
        S_single_line_statement = 127,           // single_line_statement
        S_module = 128,                          // module
        S_module_as_id = 129,                    // module_as_id
        S_module_item_list = 130,                // module_item_list
        S_dot_list = 131,                        // dot_list
        S_import_statement = 132,                // import_statement
        S_while_statement = 133,                 // while_statement
        S_for_statement = 134,                   // for_statement
        S_except_statement = 135,                // except_statement
        S_except_list = 136,                     // except_list
        S_try_statement = 137,                   // try_statement
        S_with_item = 138,                       // with_item
        S_with_item_list = 139,                  // with_item_list
        S_with_statement = 140,                  // with_statement
        S_multi_line_statement = 141,            // multi_line_statement
        S_decorators_opt = 142,                  // decorators_opt
        S_decorators = 143,                      // decorators
        S_parameter = 144,                       // parameter
        S_parameter_list = 145,                  // parameter_list
        S_parameter_list_no_posonly = 146,       // parameter_list_no_posonly
        S_defparameter_list = 147,               // defparameter_list
        S_parameter_list_starargs = 148,         // parameter_list_starargs
        S_parameter_list_opt = 149,              // parameter_list_opt
        S_comma_opt = 150,                       // comma_opt
        S_function_def = 151,                    // function_def
        S_global_statement = 152,                // global_statement
        S_ternary_if_statement = 153,            // ternary_if_statement
        S_nonlocal_statement = 154,              // nonlocal_statement
        S_elif_statement = 155,                  // elif_statement
        S_if_statement = 156,                    // if_statement
        S_target_list = 157,                     // target_list
        S_assignment_statement = 158,            // assignment_statement
        S_expression_statment = 159,             // expression_statment
        S_string = 160,                          // string
        S_expr_list_opt = 161,                   // expr_list_opt
        S_expr_list = 162,                       // expr_list
        S_expr_for_list = 163,                   // expr_for_list
        S_dict = 164,                            // dict
        S_dict_list = 165,                       // dict_list
        S_call_arguement_list = 166,             // call_arguement_list
        S_keyword_item = 167,                    // keyword_item
        S_keyword_items = 168,                   // keyword_items
        S_primary = 169,                         // primary
        S_function_call = 170,                   // function_call
        S_expr = 171,                            // expr
        S_id = 172,                              // id
        S_sep = 173,                             // sep
        S_sep_one = 174                          // sep_one
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.move< Nonnull<Alias*> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< Nonnull<Arg*> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.move< Nonnull<Arguments*> > (std::move (that.value));
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (std::move (that.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.move< Nonnull<Keyword*> > (std::move (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< Nonnull<Name*> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.move< Nonnull<NoPosOnlyArg*> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.move< Nonnull<StarArg*> > (std::move (that.value));
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
        value.move< Nonnull<Statement*> > (std::move (that.value));
        break;

      case symbol_kind::S_dict: // dict
        value.move< PairNonnullExpr > (std::move (that.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.move< long long > (std::move (that.value));
        break;

      case symbol_kind::S_augassign_op: // augassign_op
        value.move< operatorType > (std::move (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.move< std::vector<Nonnull<Alias*>> > (std::move (that.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (std::move (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.move< std::vector<Nonnull<Expression*>> > (std::move (that.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.move< std::vector<Nonnull<Keyword*>> > (std::move (that.value));
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
        value.move< std::vector<Nonnull<Statement*>> > (std::move (that.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.move< std::vector<PairNonnullExpr> > (std::move (that.value));
        break;

      case symbol_kind::S_sep: // sep
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Alias*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Alias*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Arg*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Arg*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Arguments*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Arguments*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Expression*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Expression*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<FnArg*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<FnArg*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Keyword*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Keyword*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Name*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Name*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<NoPosOnlyArg*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<NoPosOnlyArg*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<StarArg*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<StarArg*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Nonnull<Statement*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Nonnull<Statement*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PairNonnullExpr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PairNonnullExpr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, operatorType&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const operatorType& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Nonnull<Alias*>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Nonnull<Alias*>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Nonnull<Arg*>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Nonnull<Arg*>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Nonnull<Expression*>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Nonnull<Expression*>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Nonnull<Keyword*>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Nonnull<Keyword*>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<Nonnull<Statement*>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<Nonnull<Statement*>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<PairNonnullExpr>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<PairNonnullExpr>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.template destroy< Nonnull<Alias*> > ();
        break;

      case symbol_kind::S_parameter: // parameter
        value.template destroy< Nonnull<Arg*> > ();
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.template destroy< Nonnull<Arguments*> > ();
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.template destroy< Nonnull<Expression*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.template destroy< Nonnull<FnArg*> > ();
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.template destroy< Nonnull<Keyword*> > ();
        break;

      case symbol_kind::S_id: // id
        value.template destroy< Nonnull<Name*> > ();
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.template destroy< Nonnull<NoPosOnlyArg*> > ();
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.template destroy< Nonnull<StarArg*> > ();
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
        value.template destroy< Nonnull<Statement*> > ();
        break;

      case symbol_kind::S_dict: // dict
        value.template destroy< PairNonnullExpr > ();
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.template destroy< double > ();
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.template destroy< long long > ();
        break;

      case symbol_kind::S_augassign_op: // augassign_op
        value.template destroy< operatorType > ();
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.template destroy< std::vector<Nonnull<Alias*>> > ();
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.template destroy< std::vector<Nonnull<Arg*>> > ();
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.template destroy< std::vector<Nonnull<Expression*>> > ();
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.template destroy< std::vector<Nonnull<Keyword*>> > ();
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
        value.template destroy< std::vector<Nonnull<Statement*>> > ();
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.template destroy< std::vector<PairNonnullExpr> > ();
        break;

      case symbol_kind::S_sep: // sep
        value.template destroy< std::vector<std::string> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return  Parser ::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type (token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type (token_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long v, location_type l)
        : super_type (token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const long long& v, const location_type& l)
        : super_type (token_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
     Parser  (PYJU::Nonnull<PYJU::Arena*> arena_yyarg, yyscan_t yyscanner_yyarg, ParseAndLexContext& context_yyarg, std::optional<PYJU::ASTPtr>* ast_yyarg);
    virtual ~ Parser  ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
     Parser  (const  Parser &) = delete;
    /// Non copyable.
     Parser & operator= (const  Parser &) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_OF_FILE (location_type l)
      {
        return symbol_type (token::END_OF_FILE, std::move (l));
      }
#else
      static
      symbol_type
      make_END_OF_FILE (const location_type& l)
      {
        return symbol_type (token::END_OF_FILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_integer_literal (long long v, location_type l)
      {
        return symbol_type (token::integer_literal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_integer_literal (const long long& v, const location_type& l)
      {
        return symbol_type (token::integer_literal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_real_literal (double v, location_type l)
      {
        return symbol_type (token::real_literal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_real_literal (const double& v, const location_type& l)
      {
        return symbol_type (token::real_literal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_image_literal (double v, location_type l)
      {
        return symbol_type (token::image_literal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_image_literal (const double& v, const location_type& l)
      {
        return symbol_type (token::image_literal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_identifier (std::string v, location_type l)
      {
        return symbol_type (token::identifier, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_identifier (const std::string& v, const location_type& l)
      {
        return symbol_type (token::identifier, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_sized_type_literal (std::string v, location_type l)
      {
        return symbol_type (token::sized_type_literal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_sized_type_literal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::sized_type_literal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_string_literal (std::string v, location_type l)
      {
        return symbol_type (token::string_literal, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_string_literal (const std::string& v, const location_type& l)
      {
        return symbol_type (token::string_literal, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NONE (location_type l)
      {
        return symbol_type (token::NONE, std::move (l));
      }
#else
      static
      symbol_type
      make_NONE (const location_type& l)
      {
        return symbol_type (token::NONE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSERT (location_type l)
      {
        return symbol_type (token::ASSERT, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSERT (const location_type& l)
      {
        return symbol_type (token::ASSERT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAISE (location_type l)
      {
        return symbol_type (token::RAISE, std::move (l));
      }
#else
      static
      symbol_type
      make_RAISE (const location_type& l)
      {
        return symbol_type (token::RAISE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASYNC (location_type l)
      {
        return symbol_type (token::ASYNC, std::move (l));
      }
#else
      static
      symbol_type
      make_ASYNC (const location_type& l)
      {
        return symbol_type (token::ASYNC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AWAIT (location_type l)
      {
        return symbol_type (token::AWAIT, std::move (l));
      }
#else
      static
      symbol_type
      make_AWAIT (const location_type& l)
      {
        return symbol_type (token::AWAIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (location_type l)
      {
        return symbol_type (token::CLASS, std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS (const location_type& l)
      {
        return symbol_type (token::CLASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEF (location_type l)
      {
        return symbol_type (token::DEF, std::move (l));
      }
#else
      static
      symbol_type
      make_DEF (const location_type& l)
      {
        return symbol_type (token::DEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEL (location_type l)
      {
        return symbol_type (token::DEL, std::move (l));
      }
#else
      static
      symbol_type
      make_DEL (const location_type& l)
      {
        return symbol_type (token::DEL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELIF (location_type l)
      {
        return symbol_type (token::ELIF, std::move (l));
      }
#else
      static
      symbol_type
      make_ELIF (const location_type& l)
      {
        return symbol_type (token::ELIF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCEPT (location_type l)
      {
        return symbol_type (token::EXCEPT, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCEPT (const location_type& l)
      {
        return symbol_type (token::EXCEPT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FINALLY (location_type l)
      {
        return symbol_type (token::FINALLY, std::move (l));
      }
#else
      static
      symbol_type
      make_FINALLY (const location_type& l)
      {
        return symbol_type (token::FINALLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FROM (location_type l)
      {
        return symbol_type (token::FROM, std::move (l));
      }
#else
      static
      symbol_type
      make_FROM (const location_type& l)
      {
        return symbol_type (token::FROM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GLOBAL (location_type l)
      {
        return symbol_type (token::GLOBAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GLOBAL (const location_type& l)
      {
        return symbol_type (token::GLOBAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPORT (location_type l)
      {
        return symbol_type (token::IMPORT, std::move (l));
      }
#else
      static
      symbol_type
      make_IMPORT (const location_type& l)
      {
        return symbol_type (token::IMPORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (location_type l)
      {
        return symbol_type (token::IN, std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const location_type& l)
      {
        return symbol_type (token::IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS (location_type l)
      {
        return symbol_type (token::IS, std::move (l));
      }
#else
      static
      symbol_type
      make_IS (const location_type& l)
      {
        return symbol_type (token::IS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS_NOT (location_type l)
      {
        return symbol_type (token::IS_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_IS_NOT (const location_type& l)
      {
        return symbol_type (token::IS_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_IN (location_type l)
      {
        return symbol_type (token::NOT_IN, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT_IN (const location_type& l)
      {
        return symbol_type (token::NOT_IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAMBDA (location_type l)
      {
        return symbol_type (token::LAMBDA, std::move (l));
      }
#else
      static
      symbol_type
      make_LAMBDA (const location_type& l)
      {
        return symbol_type (token::LAMBDA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NONLOCAL (location_type l)
      {
        return symbol_type (token::NONLOCAL, std::move (l));
      }
#else
      static
      symbol_type
      make_NONLOCAL (const location_type& l)
      {
        return symbol_type (token::NONLOCAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PASS (location_type l)
      {
        return symbol_type (token::PASS, std::move (l));
      }
#else
      static
      symbol_type
      make_PASS (const location_type& l)
      {
        return symbol_type (token::PASS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (location_type l)
      {
        return symbol_type (token::RETURN, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const location_type& l)
      {
        return symbol_type (token::RETURN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRY (location_type l)
      {
        return symbol_type (token::TRY, std::move (l));
      }
#else
      static
      symbol_type
      make_TRY (const location_type& l)
      {
        return symbol_type (token::TRY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WITH (location_type l)
      {
        return symbol_type (token::WITH, std::move (l));
      }
#else
      static
      symbol_type
      make_WITH (const location_type& l)
      {
        return symbol_type (token::WITH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YIELD (location_type l)
      {
        return symbol_type (token::YIELD, std::move (l));
      }
#else
      static
      symbol_type
      make_YIELD (const location_type& l)
      {
        return symbol_type (token::YIELD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (location_type l)
      {
        return symbol_type (token::ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const location_type& l)
      {
        return symbol_type (token::ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPERSAND (location_type l)
      {
        return symbol_type (token::AMPERSAND, std::move (l));
      }
#else
      static
      symbol_type
      make_AMPERSAND (const location_type& l)
      {
        return symbol_type (token::AMPERSAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET (location_type l)
      {
        return symbol_type (token::CARET, std::move (l));
      }
#else
      static
      symbol_type
      make_CARET (const location_type& l)
      {
        return symbol_type (token::CARET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON_BANG (location_type l)
      {
        return symbol_type (token::COLON_BANG, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON_BANG (const location_type& l)
      {
        return symbol_type (token::COLON_BANG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_ARROW (location_type l)
      {
        return symbol_type (token::DOUBLE_ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE_ARROW (const location_type& l)
      {
        return symbol_type (token::DOUBLE_ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLONEQUAL (location_type l)
      {
        return symbol_type (token::COLONEQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_COLONEQUAL (const location_type& l)
      {
        return symbol_type (token::COLONEQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL_EQUAL (location_type l)
      {
        return symbol_type (token::EQUAL_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL_EQUAL (const location_type& l)
      {
        return symbol_type (token::EQUAL_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPARENT (location_type l)
      {
        return symbol_type (token::LPARENT, std::move (l));
      }
#else
      static
      symbol_type
      make_LPARENT (const location_type& l)
      {
        return symbol_type (token::LPARENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERIOD (location_type l)
      {
        return symbol_type (token::PERIOD, std::move (l));
      }
#else
      static
      symbol_type
      make_PERIOD (const location_type& l)
      {
        return symbol_type (token::PERIOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POW (location_type l)
      {
        return symbol_type (token::POW, std::move (l));
      }
#else
      static
      symbol_type
      make_POW (const location_type& l)
      {
        return symbol_type (token::POW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (location_type l)
      {
        return symbol_type (token::AT, std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const location_type& l)
      {
        return symbol_type (token::AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOOR_DIV (location_type l)
      {
        return symbol_type (token::FLOOR_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOOR_DIV (const location_type& l)
      {
        return symbol_type (token::FLOOR_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE (location_type l)
      {
        return symbol_type (token::TILDE, std::move (l));
      }
#else
      static
      symbol_type
      make_TILDE (const location_type& l)
      {
        return symbol_type (token::TILDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VBAR (location_type l)
      {
        return symbol_type (token::VBAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VBAR (const location_type& l)
      {
        return symbol_type (token::VBAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSHIFT (location_type l)
      {
        return symbol_type (token::LSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_LSHIFT (const location_type& l)
      {
        return symbol_type (token::LSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSHIFT (location_type l)
      {
        return symbol_type (token::RSHIFT, std::move (l));
      }
#else
      static
      symbol_type
      make_RSHIFT (const location_type& l)
      {
        return symbol_type (token::RSHIFT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER_THEN (location_type l)
      {
        return symbol_type (token::LOWER_THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_LOWER_THEN (const location_type& l)
      {
        return symbol_type (token::LOWER_THEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER_EQUAL (location_type l)
      {
        return symbol_type (token::LOWER_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LOWER_EQUAL (const location_type& l)
      {
        return symbol_type (token::LOWER_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_THEN (location_type l)
      {
        return symbol_type (token::GREATER_THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_THEN (const location_type& l)
      {
        return symbol_type (token::GREATER_THEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER_EQUAL (location_type l)
      {
        return symbol_type (token::GREATER_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER_EQUAL (const location_type& l)
      {
        return symbol_type (token::GREATER_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLIPSIS (location_type l)
      {
        return symbol_type (token::ELLIPSIS, std::move (l));
      }
#else
      static
      symbol_type
      make_ELLIPSIS (const location_type& l)
      {
        return symbol_type (token::ELLIPSIS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPARENT (location_type l)
      {
        return symbol_type (token::RPARENT, std::move (l));
      }
#else
      static
      symbol_type
      make_RPARENT (const location_type& l)
      {
        return symbol_type (token::RPARENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SELF (location_type l)
      {
        return symbol_type (token::SELF, std::move (l));
      }
#else
      static
      symbol_type
      make_SELF (const location_type& l)
      {
        return symbol_type (token::SELF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDERSCORE (location_type l)
      {
        return symbol_type (token::UNDERSCORE, std::move (l));
      }
#else
      static
      symbol_type
      make_UNDERSCORE (const location_type& l)
      {
        return symbol_type (token::UNDERSCORE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RARROW (location_type l)
      {
        return symbol_type (token::RARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_RARROW (const location_type& l)
      {
        return symbol_type (token::RARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_EQUAL (location_type l)
      {
        return symbol_type (token::PLUS_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_EQUAL (const location_type& l)
      {
        return symbol_type (token::PLUS_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN_EQUAL (location_type l)
      {
        return symbol_type (token::MIN_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN_EQUAL (const location_type& l)
      {
        return symbol_type (token::MIN_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR_EQUAL (location_type l)
      {
        return symbol_type (token::STAR_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR_EQUAL (const location_type& l)
      {
        return symbol_type (token::STAR_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH_EQUAL (location_type l)
      {
        return symbol_type (token::SLASH_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH_EQUAL (const location_type& l)
      {
        return symbol_type (token::SLASH_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT_EQUAL (location_type l)
      {
        return symbol_type (token::PERCENT_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT_EQUAL (const location_type& l)
      {
        return symbol_type (token::PERCENT_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPER_EQUAL (location_type l)
      {
        return symbol_type (token::AMPER_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_AMPER_EQUAL (const location_type& l)
      {
        return symbol_type (token::AMPER_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VBAR_EQUAL (location_type l)
      {
        return symbol_type (token::VBAR_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_VBAR_EQUAL (const location_type& l)
      {
        return symbol_type (token::VBAR_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET_EQUAL (location_type l)
      {
        return symbol_type (token::CARET_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_CARET_EQUAL (const location_type& l)
      {
        return symbol_type (token::CARET_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFTSHIFT_EQUAL (location_type l)
      {
        return symbol_type (token::LEFTSHIFT_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFTSHIFT_EQUAL (const location_type& l)
      {
        return symbol_type (token::LEFTSHIFT_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHTSHIFT_EQUAL (location_type l)
      {
        return symbol_type (token::RIGHTSHIFT_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHTSHIFT_EQUAL (const location_type& l)
      {
        return symbol_type (token::RIGHTSHIFT_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POW_EQUAL (location_type l)
      {
        return symbol_type (token::POW_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_POW_EQUAL (const location_type& l)
      {
        return symbol_type (token::POW_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLESLASH_EQUAL (location_type l)
      {
        return symbol_type (token::DOUBLESLASH_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLESLASH_EQUAL (const location_type& l)
      {
        return symbol_type (token::DOUBLESLASH_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INDENT (location_type l)
      {
        return symbol_type (token::INDENT, std::move (l));
      }
#else
      static
      symbol_type
      make_INDENT (const location_type& l)
      {
        return symbol_type (token::INDENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEDENT (location_type l)
      {
        return symbol_type (token::DEDENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DEDENT (const location_type& l)
      {
        return symbol_type (token::DEDENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWLINE (location_type l)
      {
        return symbol_type (token::NEWLINE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWLINE (const location_type& l)
      {
        return symbol_type (token::NEWLINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMENT (location_type l)
      {
        return symbol_type (token::COMMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMENT (const location_type& l)
      {
        return symbol_type (token::COMMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOLCOMMENT (location_type l)
      {
        return symbol_type (token::EOLCOMMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_EOLCOMMENT (const location_type& l)
      {
        return symbol_type (token::EOLCOMMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE_COMMENT (location_type l)
      {
        return symbol_type (token::TYPE_COMMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE_COMMENT (const location_type& l)
      {
        return symbol_type (token::TYPE_COMMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNARY (location_type l)
      {
        return symbol_type (token::UNARY, std::move (l));
      }
#else
      static
      symbol_type
      make_UNARY (const location_type& l)
      {
        return symbol_type (token::UNARY, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
     Parser  (const  Parser &);
    /// Non copyable.
     Parser & operator= (const  Parser &);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 2770,     ///< Last index in yytable_.
      yynnts_ = 71,  ///< Number of nonterminal symbols.
      yyfinal_ = 120 ///< Termination state number.
    };


    // User arguments.
    PYJU::Nonnull<PYJU::Arena*> arena;
    yyscan_t yyscanner;
    ParseAndLexContext& context;
    std::optional<PYJU::ASTPtr>* ast;

  };

  inline
   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103
    };
    // Last valid token kind.
    const int code_max = 358;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.copy< Nonnull<Alias*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.copy< Nonnull<Arg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.copy< Nonnull<Arguments*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.copy< Nonnull<Expression*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< Nonnull<FnArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.copy< Nonnull<Keyword*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.copy< Nonnull<Name*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.copy< Nonnull<NoPosOnlyArg*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.copy< Nonnull<StarArg*> > (YY_MOVE (that.value));
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
        value.copy< Nonnull<Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict: // dict
        value.copy< PairNonnullExpr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_augassign_op: // augassign_op
        value.copy< operatorType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.copy< std::vector<Nonnull<Alias*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.copy< std::vector<Nonnull<Arg*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.copy< std::vector<Nonnull<Expression*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.copy< std::vector<Nonnull<Keyword*>> > (YY_MOVE (that.value));
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
        value.copy< std::vector<Nonnull<Statement*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.copy< std::vector<PairNonnullExpr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sep: // sep
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_module_as_id: // module_as_id
        value.move< Nonnull<Alias*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter: // parameter
        value.move< Nonnull<Arg*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list_opt: // parameter_list_opt
        value.move< Nonnull<Arguments*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tuple_item: // tuple_item
      case symbol_kind::S_for_tuple_item: // for_tuple_item
      case symbol_kind::S_ternary_if_statement: // ternary_if_statement
      case symbol_kind::S_string: // string
      case symbol_kind::S_primary: // primary
      case symbol_kind::S_function_call: // function_call
      case symbol_kind::S_expr: // expr
        value.move< Nonnull<Expression*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< Nonnull<FnArg*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_keyword_item: // keyword_item
        value.move< Nonnull<Keyword*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id: // id
        value.move< Nonnull<Name*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list_no_posonly: // parameter_list_no_posonly
        value.move< Nonnull<NoPosOnlyArg*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list_starargs: // parameter_list_starargs
        value.move< Nonnull<StarArg*> > (YY_MOVE (s.value));
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
        value.move< Nonnull<Statement*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dict: // dict
        value.move< PairNonnullExpr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_real_literal: // real_literal
      case symbol_kind::S_image_literal: // image_literal
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_integer_literal: // integer_literal
        value.move< long long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_augassign_op: // augassign_op
        value.move< operatorType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_sized_type_literal: // sized_type_literal
      case symbol_kind::S_string_literal: // string_literal
      case symbol_kind::S_sep_one: // sep_one
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_module_item_list: // module_item_list
        value.move< std::vector<Nonnull<Alias*>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_defparameter_list: // defparameter_list
        value.move< std::vector<Nonnull<Arg*>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_module: // module
      case symbol_kind::S_decorators_opt: // decorators_opt
      case symbol_kind::S_decorators: // decorators
      case symbol_kind::S_target_list: // target_list
      case symbol_kind::S_expr_list_opt: // expr_list_opt
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_expr_for_list: // expr_for_list
      case symbol_kind::S_call_arguement_list: // call_arguement_list
        value.move< std::vector<Nonnull<Expression*>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_keyword_items: // keyword_items
        value.move< std::vector<Nonnull<Keyword*>> > (YY_MOVE (s.value));
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
        value.move< std::vector<Nonnull<Statement*>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dict_list: // dict_list
        value.move< std::vector<PairNonnullExpr> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sep: // sep
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

#line 21 "parser.ypp"
} //  PYJU 
#line 4234 "./parser.h"




#endif // !YY_YY_PARSER_H_INCLUDED
