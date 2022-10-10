
#pragma once

#include <string>

#include "Parser/flex_bison/parse_and_lex_context.h"
#include "Parser/flex_bison/parser.h"

// Exposes yyinput; defined in lexer.lpp.
extern auto YyinputWrapper(yyscan_t yyscanner) -> int;

namespace PYJU {

class StringLexHelper {
 public:
  StringLexHelper(const char* text, yyscan_t yyscanner,
                  ParseAndLexContext& context)
      : str_(text), yyscanner_(yyscanner), context_(context), is_eof_(false) {}
  // Advances yyscanner by one char. Sets is_eof to true and returns false on
  // EOF.
  auto Advance() -> bool;
  // Returns the last scanned char.
  auto last_char() -> char { return str_.back(); };
  // Returns the scanned string.
  auto str() -> const std::string& { return str_; };

  auto is_eof() -> bool { return is_eof_; };

 private:
  std::string str_;
  yyscan_t yyscanner_;
  ParseAndLexContext& context_;
  // Skips reading next char.
  bool is_eof_;
};

// Tries to Read `hashtag_num` hashtags. Returns true on success.
// Reads `hashtag_num` characters on success, and number of consecutive hashtags
// (< `hashtag_num`) + 1 characters on failure.
auto ReadHashTags(StringLexHelper& scan_helper, size_t hashtag_num)
    -> bool;

// Removes quotes and escapes a single line string. Reports an error on
// invalid escaping.
auto ProcessSingleLineString(llvm::StringRef str,
                             ParseAndLexContext& context,
                             size_t hashtag_num) -> Parser::symbol_type;
auto ProcessMultiLineString(llvm::StringRef str,
                            ParseAndLexContext& context,
                            size_t hashtag_num) -> Parser::symbol_type;

}  // namespace PYJU

