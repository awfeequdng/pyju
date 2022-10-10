
#include "Parser/flex_bison/lex_scan_helper.h"
#include "base/check.h"
#include "base/string_helpers.h"
#include "Parser/flex_bison/lex_helper.h"
#include <fmt/format.h>

namespace PYJU {

auto StringLexHelper::Advance() -> bool {
  PXC_CHECK(is_eof_ == false);
  const char c = YyinputWrapper(yyscanner_);
  if (c <= 0) {
    context_.RecordSyntaxError("Unexpected end of file");
    is_eof_ = true;
    return false;
  }
  str_.push_back(c);
  return true;
}

auto ReadHashTags(StringLexHelper& scan_helper,
                  const size_t hashtag_num) -> bool {
  for (size_t i = 0; i < hashtag_num; ++i) {
    if (!scan_helper.Advance() || scan_helper.last_char() != '#') {
      return false;
    }
  }
  return true;
}

auto ProcessSingleLineString(llvm::StringRef str,
                             ParseAndLexContext& context,
                             const size_t hashtag_num)
    -> Parser::symbol_type {
  std::string hashtags(hashtag_num, '#');
  const auto str_with_quote = str;
  PXC_CHECK(str.consume_front(hashtags + "\"") &&
               str.consume_back("\"" + hashtags));

  std::optional<std::string> unescaped =
      PYJU::UnescapeStringLiteral(str, hashtag_num);
  if (unescaped == std::nullopt) {
    return context.RecordSyntaxError(
        fmt::format("Invalid escaping in string:{0}: ", str_with_quote));
  }
  return PXC_ARG_TOKEN(string_literal, *unescaped);
}

auto ProcessMultiLineString(llvm::StringRef str,
                            ParseAndLexContext& context,
                            const size_t hashtag_num)
    -> Parser::symbol_type {
  std::string hashtags(hashtag_num, '#');
  PXC_CHECK(str.consume_front(hashtags) && str.consume_back(hashtags));
  PYJU::ErrorOr<std::string> block_string =
        PYJU::ParseBlockStringLiteral(str, hashtag_num);
  if (!block_string.ok()) {
      return context.RecordSyntaxError(fmt::format(
        "Invalid block string: {0}", block_string.error().message()
      ));
  }
  return PXC_ARG_TOKEN(string_literal, *block_string);
}

}  // namespace PYJU
