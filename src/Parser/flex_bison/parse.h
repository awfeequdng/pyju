#pragma once

#include <string>
#include <variant>

#include "ast/ast.h"
#include "base/arena.h"
#include "base/error.h"

namespace PYJU {

// Returns the AST representing the contents of the named file, or an error code
// if parsing fails. Allocations go into the provided arena.
auto Parse(PYJU::Nonnull<PYJU::Arena*> arena, std::string_view input_file_name,
           bool parser_debug) -> PYJU::ErrorOr<PYJU::ASTPtr>;

// Equivalent to `Parse`, but parses the contents of `file_contents`.
// `input_file_name` is used only for reporting source locations, and does
// not need to name a real file.
auto ParseFromString(PYJU::Nonnull<PYJU::Arena*> arena, std::string_view input_file_name,
                     std::string_view file_contents, bool parser_debug)
    -> PYJU::ErrorOr<PYJU::ASTPtr>;

}  // namespace parser::flex_bision

