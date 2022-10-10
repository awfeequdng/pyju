#pragma once
#include <stack>
#include <string_view>
#include <unordered_map>
#include <memory>
#include <functional>

#include "base/utf8/rune.h"
#include "base/pos.h"

namespace PYJU::utf8 {

class reader_t final {
public:
    reader_t(const std::string &slice);

    bool seek(size_t index);

    [[nodiscard]] size_t length();

    rune_t curr();

    rune_t peek();

    rune_t next();

    rune_t prev();

    bool move_prev();

    bool move_next();

    [[nodiscard]] bool eof() const;

    [[nodiscard]] Pos pos() const;

    [[nodiscard]] size_t index() const;

    [[nodiscard]] uint32_t width() const;

    [[nodiscard]] std::string make_slice(size_t offset, size_t length) const;

    [[nodiscard]] std::string slice() const;

    rune_t incAsLongAs(std::function<bool(rune_t)> fn);

    std::string data(const Pos &from) { return make_slice(from._offset, _index - from._offset); }

    int last_width() const { return _last_width; }

    void updatePos(const Pos &pos) { seek(pos._offset); }

    bool is_newline(size_t index) const;
    bool is_dot(size_t index) const;
    bool is_doble_quote(size_t index) const;
    // inline bool is_newline(size_t index) const;
    // inline bool is_dot(size_t index) const;
    // inline bool is_doble_quote(size_t index) const;

private:
    rune_t read(uint32_t &width) const;

private:
    size_t _index{};
    std::string _slice;
    Pos _pos{0, 0, 0};
    std::unordered_map<size_t, Pos> _idx2pos;
    std::stack<uint32_t> _width_stack;
    int _last_width{1};
};

using ReaderPtr = std::shared_ptr<reader_t>;

}  // namespace PYJU::utf8