#include "base/colorizer.h"

#include <sstream>

#include <fmt/format.h>

namespace PYJU {
bool g_color_enabled = true;

std::string colorizer::colorize(const std::string &text, term_colors_t fg_color, term_colors_t bg_color) {
    if (!g_color_enabled) return text;
    return fmt::format("{}{}{}{}", color_code(make_bg_color(bg_color)), color_code(fg_color), text, color_code_reset());
}

std::string colorizer::colorize_range(const std::string &text, size_t begin, size_t end, term_colors_t fg_color,
                                      term_colors_t bg_color) {
    if (!g_color_enabled) return text;
    std::stringstream colored_source;
    for (size_t j = 0; j < text.length(); j++) {
        if (begin == end && j == begin) {
            colored_source << fmt::format("{}{}", color_code(make_bg_color(bg_color)), color_code(fg_color));
            colored_source << text[j];
            colored_source << color_code_reset();
        } else {
            if (j == begin) {
                colored_source << fmt::format("{}{}", color_code(make_bg_color(bg_color)), color_code(fg_color));
            } else if (j == end) {
                colored_source << color_code_reset();
            }
            colored_source << text[j];
        }
    }
    return colored_source.str();
}

constexpr const char *colorizer::color_code_reset() { return "\033[0m"; }

std::string colorizer::color_code(term_colors_t color) { return fmt::format("\033[1;{}m", (uint32_t)color); }

constexpr term_colors_t colorizer::make_bg_color(term_colors_t color) {
    return static_cast<term_colors_t>(static_cast<uint8_t>(color) + 10);
}

}  // namespace PYJU
