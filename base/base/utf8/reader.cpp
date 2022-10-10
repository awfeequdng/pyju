#include "base/utf8/reader.h"

namespace PYJU::utf8 {

reader_t::reader_t(const std::string &slice) : _slice(slice), _width_stack() { _idx2pos[0] = {}; }

size_t reader_t::length() { return _slice.length(); }

bool reader_t::eof() const { return _index >= _slice.size(); }

Pos reader_t::pos() const { return _pos; }

size_t reader_t::index() const { return _index; }

uint32_t reader_t::width() const {
    uint32_t width;
    read(width);
    return width;
}

bool reader_t::seek(size_t index) {
    if (index > _slice.size() - 1) return false;
    // does not have record of pos index, so it can not move to position to 'index'
    if (_idx2pos.find(index) == _idx2pos.end()) return false;

    // can not move to index behand _index
    if (_index < index) return false;

    auto stk_tmp = _width_stack;
    auto index_tmp = _index;

    while (index_tmp > index && !stk_tmp.empty()) {
        index_tmp -= stk_tmp.top();
        stk_tmp.pop();
    }
    if (index_tmp != index) {
        // does not back to a valid position
        return false;
    }
    _index = index_tmp;
    _width_stack = std::move(stk_tmp);
    _pos = _idx2pos[_index];
    return true;
}

rune_t reader_t::curr() {
    if (eof()) return rune_eof;

    uint32_t width;
    auto r = read(width);
    _last_width = width;

    return r;
}

rune_t reader_t::peek() { return curr(); }

rune_t reader_t::next() {
    if (eof()) return rune_eof;

    uint32_t width;
    auto rune = read(width);
    _index += width;
    _width_stack.push(width);
    _pos._col += width;
    _pos._offset = _index;
    if (rune == '\n') {
        _pos._line++;
        _pos._col = 0;
    }
    _idx2pos[_index] = _pos;
    return rune;
}

rune_t reader_t::prev() {
    if (_index == 0 || _width_stack.empty()) {
        return rune_invalid;
    }
    _index -= _width_stack.top();
    _pos = _idx2pos[_index];
    _width_stack.pop();
    uint32_t width;
    return read(width);
}

bool reader_t::move_prev() {
    if (_index == 0 || _width_stack.empty()) {
        return false;
    }
    _index -= _width_stack.top();
    _pos = _idx2pos[_index];
    _width_stack.pop();

    return true;
}

bool reader_t::move_next() {
    if (eof()) {
        return false;
    }

    uint32_t width;
    rune_t rune = read(width);
    _index += width;
    if (rune == '\n') {
        _pos._line++;
        _pos._col = 0;
    }
    _pos._col += width;
    _pos._offset = _index;
    _idx2pos[_index] = _pos;

    _width_stack.push(width);
    return true;
}

std::string reader_t::slice() const { return _slice; }

rune_t reader_t::read(uint32_t &width) const {
    width = 1;
    uint8_t ch = _slice[_index];
    auto rune = rune_t(ch);
    if (ch == 0) {
        return rune_invalid;
    } else if (ch >= 0x80) {
        auto cp = decode((const char *)(_slice.data() + _index), _slice.size() - _index);
        width = cp.width;
        rune = cp.value;
        if (rune == rune_invalid && width == 1) {
            return rune_invalid;
        } else if (rune == rune_bom && _index > 0) {
            return rune_invalid;
        }
    }
    return rune;
}

std::string reader_t::make_slice(size_t offset, size_t len) const { return _slice.substr(offset, len); }

bool reader_t::is_newline(size_t index) const {
    if (index < _slice.size()) {
        return _slice[index] == '\n';
    }
    return false;
}

bool reader_t::is_dot(size_t index) const {
    if (index < _slice.size()) {
        return _slice[index] == '.';
    }
    return false;
}

bool reader_t::is_doble_quote(size_t index) const {
    if (index < _slice.size()) {
        return _slice[index] == '"';
    }
    return false;
}

rune_t reader_t::incAsLongAs(std::function<bool(rune_t)> fn) {
    while (true) {
        auto ch = peek();
        if (!fn(ch)) {
            return ch;
        }
        if (ch.is_errored()) {
            return rune_t{0};
        }
        next();
    }
}

}  // namespace PYJU::utf8