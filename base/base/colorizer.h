#pragma once

#include <cstdint>
#include <string>

namespace PYJU {
enum class term_colors_t : uint8_t {
    black = 30,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    light_gray,
    dark_gray,
    light_red,
    light_green,
    light_yellow,
    light_blue,
    light_magenta,
    light_cyan,
    white
};

// N.B. this is not thread safe
extern bool g_color_enabled;

class colorizer {
public:
    static std::string colorize(const std::string &text, term_colors_t fg_color,
                                term_colors_t bg_color = term_colors_t::black);

    static std::string colorize_range(const std::string &text, size_t begin, size_t end, term_colors_t fg_color,
                                      term_colors_t bg_color = term_colors_t::black);

    static constexpr const char *color_code_reset();

    static std::string color_code(term_colors_t color);

    static constexpr term_colors_t make_bg_color(term_colors_t color);
};
}  // namespace PYJU
