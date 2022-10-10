#include "base/hex_formatter.h"

#include <fmt/format.h>

#include <sstream>

namespace PYJU {
std::string HexFormatter::dump_to_string(const void *data, size_t size) {
    auto *buf = (const unsigned char *)data;
    std::stringstream stream;
    for (size_t i = 0; i < size; i += 16) {
        stream << fmt::format("{:06x}: ", (unsigned long)(data) + i);
        for (size_t j = 0; j < 16; j++)
            if (i + j < size)
                stream << fmt::format("{:02x} ", buf[i + j]);
            else
                stream << "   ";
        stream << " ";
        for (size_t j = 0; j < 16; j++)
            if (i + j < size) stream << (char)(isprint(buf[i + j]) ? buf[i + j] : '.');
        stream << "\n";
    }
    return stream.str();
}
}  // namespace PYJU