#pragma once

#include <type_traits>

// namespace PYJU {

// C++17-compatible emulation of a C++20 `requires` expression, which queries
// whether a given expression is well-formed. The syntax is best explained
// in terms of an example:
//
// template <typename T>
// static constexpr bool IsStreamableToRawOstream =
//     Requires<const T, llvm::raw_ostream>(
//         [](auto&& t, auto&& out) -> decltype(out << t) {});
//
// The expression enclosed in `decltype` is the expression whose validity the
// trait queries. The lambda parameters declare the names that are used in
// that expression, and the types of those names are specified by the
// corresponding template arguments of the `Requires` call. The lambda
// parameters should always have type `auto&&`, and the template arguments
// should not have `&` or `&&` qualifiers.
template <typename... T, typename F>
constexpr auto Requires(F /* f */) -> bool {
  return std::is_invocable_v<F, T...>;
}

// }  // namespace PYJU
