#pragma once

#include <type_traits>

namespace PYJU {

// A non-nullable pointer. Written as `Nonnull<T*>` instead of `T*`.
//
// Sanitizers enforce this dynamically on assignment, return, and when passing
// as an argument. Static analysis will also track erroneous uses of `nullptr`.
template <typename T,
          typename std::enable_if_t<std::is_pointer_v<T>>* = nullptr>
// using Nonnull = T;
using Nonnull = T _Nonnull;

}  // namespace PYJU
