#pragma once

#include <stdexcept>


/// Throw PYJU::Exception-like exception before its definition.
/// PYJU::Exception derived from Poco::Exception derived from std::exception.
/// PYJU::Exception generally caught as Poco::Exception. std::exception generally has other catch blocks and could lead to other outcomes.
/// PYJU::Exception is not defined yet. It'd better to throw Poco::Exception but we do not want to include any big header here, even <string>.
/// So we throw some std::exception instead in the hope its catch block is the same as PYJU::Exception one.
template <typename T>
[[noreturn]] inline void throwError(const T & err)
{
    throw std::runtime_error(err);
}
