#pragma once

#include <variant>
#include <stack>

#include "base/nonnull.h"
#include "base/source_location.h"
#include "ast/ast.h"
#include "Parser/flex_bison/parser.h"  // from parser.ypp

namespace PYJU {

// The state and functionality that is threaded "globally" through the
// lexing/parsing process.
class ParseAndLexContext {
 public:
  // Creates an instance analyzing the given input file.
  ParseAndLexContext(PYJU::Nonnull<const std::string*> input_file_name,
                     bool parser_debug)
      : input_file_name_(input_file_name), parser_debug_(parser_debug) {}

  // Formats ands records a lexer error. Returns an error token as a
  // convenience.
  auto RecordSyntaxError(const std::string& message,
                         bool prefix_with_newline = false)
      -> Parser::symbol_type;

  auto source_loc() const -> PYJU::SourceLocation {
    return PYJU::SourceLocation(input_file_name_,
                          static_cast<int>(current_token_position.begin.line),
                          static_cast<int>(current_token_position.begin.column)
                          );
  }

  auto parser_debug() const -> bool { return parser_debug_; }

  // The source range of the token being (or just) lex'd.
  location current_token_position;

  // 记录当前为止的各个缩进值
  std::stack<size_t> indent_stk;

  // 当前的缩进空格数
  size_t current_line_indent = 0;

  auto error_messages() const -> const std::vector<std::string> {
    return error_messages_;
  }

 private:
  // A path to the file processed, relative to the current working directory
  // when *this is called.
  PYJU::Nonnull<const std::string*> input_file_name_;

  bool parser_debug_;

  std::vector<std::string> error_messages_;
};

}  // namespace PYJU

// Gives flex the yylex prototype we want.
#define YY_DECL                                                         \
  PYJU::Parser::symbol_type yylex(PYJU::Nonnull<PYJU::Arena*> arena, yyscan_t yyscanner, \
             PYJU::ParseAndLexContext& context)

// Declares yylex for the parser's sake.
YY_DECL;

