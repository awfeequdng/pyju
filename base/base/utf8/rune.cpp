#include "base/utf8/rune.h"

#include <ostream>

namespace PYJU::utf8 {

bool rune_t::is_eof() const { return _value == rune_eof._value; }

bool rune_t::is_bom() const { return _value == rune_bom._value; }

bool rune_t::is_digit() const {
    if (_value < 0x80) return isdigit(_value) != 0;
    return utf8proc_category(_value) == UTF8PROC_CATEGORY_ND;
}

// in the Latin-1 space this is
//	'\t', '\n', '\v', '\f', '\r', ' ', U+0085 (NEL), U+00A0 (NBSP).
// Other definitions of spacing characters are set by category
// Z and property Pattern_White_Space.
bool rune_t::is_space() const {
    if (_value < 0x80) {
        return isspace(_value);
    } else if (_value <= 0xff) {
        switch (_value) {
            case 0x85:
                [[fallthrough]];
            case 0xA0:
                return true;
            default:
                return false;
        }
    } else {
        // todo: this is not test
        switch (utf8proc_category(_value)) {
            case UTF8PROC_CATEGORY_MC:
            case UTF8PROC_CATEGORY_ZS:
                return true;
            default:
                return false;
        }
    }
}

bool rune_t::is_xdigit() const {
    if (_value < 0x80) return isxdigit(_value) != 0;
    const auto cat = utf8proc_category(_value);
    return cat == UTF8PROC_CATEGORY_ND || cat == UTF8PROC_CATEGORY_NL;
}

bool rune_t::is_alpha() const {
    if (_value < 0x80) {
        if (_value == '_') return true;
        return isalpha(_value) != 0;
    }
    switch (utf8proc_category(_value)) {
        case UTF8PROC_CATEGORY_LU:
        case UTF8PROC_CATEGORY_LL:
        case UTF8PROC_CATEGORY_LT:
        case UTF8PROC_CATEGORY_LM:
        case UTF8PROC_CATEGORY_LO:
            return true;
        default:
            break;
    }
    return false;
}

bool rune_t::is_alnum() const { return is_alpha() || is_digit(); }

rune_t::operator char() const { return static_cast<char>(_value); }

bool rune_t::is_invalid() const { return _value == rune_invalid._value; }

bool rune_t::is_errored() const { return is_eof() || is_invalid(); }

rune_t::operator int32_t() const { return _value; }

rune_t::operator std::size_t() const { return _value; }

rune_t::operator std::string() const {
    std::string temp{};
    auto encode_result = encode(rune_t(_value));
    for (size_t j = 0; j < encode_result.width; j++) {
        temp += static_cast<char>(encode_result.data[j]);
    }
    return temp;
}

rune_t &rune_t::operator=(int32_t rhs) {
    _value = rhs;
    return *this;
}

rune_t &rune_t::operator=(char rhs) {
    _value = rhs;
    return *this;
}

bool rune_t::operator==(char rhs) const {
    // todo: this is error when _value greater than 255
    //    return static_cast<char>(_value) == rhs;
    return _value == rhs;
}

bool rune_t::operator!=(char rhs) const {
    //    todo: this is error when _value greater than 255
    //    return static_cast<char>(_value) != rhs;
    return _value != rhs;
}

bool rune_t::operator<(int32_t rhs) const { return _value < rhs; }

bool rune_t::operator<=(int32_t rhs) const { return _value <= rhs; }

bool rune_t::operator>(int32_t rhs) const { return _value > rhs; }

bool rune_t::operator>=(int32_t rhs) const { return _value >= rhs; }

bool rune_t::operator<(const rune_t &rhs) const { return _value < rhs._value; }

bool rune_t::operator<=(const rune_t &rhs) const { return _value <= rhs._value; }

bool rune_t::operator==(const rune_t &rhs) const { return _value == rhs._value; }

bool rune_t::operator!=(const rune_t &rhs) const { return _value != rhs._value; }

bool rune_t::operator>(const rune_t &rhs) const { return _value > rhs._value; }

bool rune_t::operator>=(const rune_t &rhs) const { return _value >= rhs._value; }

std::ostream &operator<<(std::ostream &os, const rune_t &rune) {
    auto encode_result = encode(rune);
    for (size_t j = 0; j < encode_result.width; j++) os << static_cast<char>(encode_result.data[j]);
    return os;
}

///////////////////////////////////////////////////////////////////////////

int64_t strlen(std::string_view str) {
    int64_t len = 0;
    auto p = str.data();
    for (; *p; len++) {
        auto c = static_cast<uint8_t>(*p);

        size_t cp_size = 0;
        if (c < 0x80)
            cp_size = 1;
        else if ((c & 0xe0) == 0xc0)
            cp_size = 2;
        else if ((c & 0xf0) == 0xe0)
            cp_size = 3;
        else if ((c & 0xf8) == 0xf0)
            cp_size = 4;
        else
            return -1;

        p += cp_size;
    }
    return len;
}

encoded_rune_t encode(const rune_t &r) {
    encoded_rune_t e{};

    const auto r_int = static_cast<int>(r);

    auto i = r_int;
    uint8_t mask = 0x3f;
    if (i <= (1 << 7) - 1) {
        e.data[0] = static_cast<int>(r);
        e.width = 1;
        return e;
    }

    // todo: can not encode the rune, so return it
    //    if (i <= (1 << 8) - 1) {
    //        e.data[0] = r_int;
    //        e.width = 1;
    //        return e;
    //    }

    if (i <= (1 << 11) - 1) {
        e.data[0] = static_cast<uint8_t>(0xc0 | static_cast<uint8_t>((r_int >> 6)));
        e.data[1] = static_cast<uint8_t>(0x80 | (static_cast<uint8_t>((r_int)) & mask));
        e.width = 2;
        return e;
    }

    if (i > static_cast<int>(rune_max) || (i >= 0xd800 && i <= 0xdfff)) {
        e.data[0] = static_cast<uint8_t>(0xe0 | (uint8_t)(r_int >> 12));
        e.data[1] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int >> 6) & mask));
        e.data[2] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int)&mask));
        e.value = rune_invalid;
        e.width = 3;
        return e;
    }

    if (i <= (1 << 16) - 1) {
        e.data[0] = static_cast<uint8_t>(0xe0 | (uint8_t)(r_int >> 12));
        e.data[1] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int >> 6) & mask));
        e.data[2] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int)&mask));
        e.width = 3;
        return e;
    }

    e.data[0] = static_cast<uint8_t>(0xf0 | (uint8_t)(r_int >> 18));
    e.data[1] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int >> 12) & mask));
    e.data[2] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int >> 6) & mask));
    e.data[3] = static_cast<uint8_t>(0x80 | ((uint8_t)(r_int)&mask));
    e.width = 4;

    return e;
}

codepoint_t decode(const char *str, size_t length) {
    if (length == 0) return {};
    auto s0 = (uint8_t)str[0];
    codepoint_t cp{};
    cp.value = s0;

    uint8_t x = s_utf8_first[s0];
    uint8_t sz;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
    utf8_accept_range_t accept{};

    if (s0 < 0x80) {
        cp.value = s0;
        cp.width = 1;
        return cp;
    }

    if (x >= 0xf0) {
        //        int mask = (x << 31) >> 31;
        //        cp.value = (s0 & (~mask)) | (static_cast<int>(rune_invalid) & mask);
        cp.width = 1;
        return cp;
    }

    sz = static_cast<uint8_t>(x & 7);
    accept = s_utf8_accept_ranges[x >> 4];
    // todo: I think it's wrong here
    //    if (length < sizeof(sz)) return cp;
    if (length < sz) return cp;

    b1 = (uint8_t)str[1];
    if (b1 < accept.low || accept.high < b1) return cp;

    if (sz == 2) {
        // todo: I think it's wrong here
        cp.value = (s0 & 0x1f) << 6 | (b1 & 0x3f);
        //        cp.value = (s0 & 0xff) << 8 | (b1 & 0xff);
        cp.width = 2;
        return cp;
    }

    b2 = (uint8_t)str[2];
    if (!(b2 >= 0x80 && b2 <= 0xbf)) return cp;

    if (sz == 3) {
        // todo: I think it's wrong here
        cp.value = (s0 & 0x1f) << 12 | (b1 & 0x3f) << 6 | (b2 & 0x3f);
        //        cp.value = (s0 & 0xff) << 16 | (b1 & 0xff) << 8 | (b2 & 0xff);
        cp.width = 3;
        return cp;
    }

    b3 = (uint8_t)str[3];
    if (!(b3 >= 0x80 && b3 <= 0xbf)) return cp;

    // todo: I think it's wrong here
    cp.value = (s0 & 0x07) << 18 | (b1 & 0x3f) << 12 | (b2 & 0x3f) << 6 | (b3 & 0x3f);
    //    cp.value = (s0 & 0xff) << 24 | (b1 & 0xff) << 16 | (b2 & 0xff) << 8 | (b3 & 0xff);
    cp.width = 4;

    return cp;
}

}  // namespace PYJU::utf8