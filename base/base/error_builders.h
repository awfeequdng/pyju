#pragma once

#include "base/error.h"
#include "base/source_location.h"

namespace PYJU {

// Builds an Error instance with the specified message. This should be used for
// non-recoverable errors with user input.
//
// For example:
//   return ProgramError(line_num) << "Line is bad!";
//   return ProgramError() << "Application is bad!";
//
// Where possible, try to identify the error as a compilation or runtime error.
// Use CHECK/FATAL for internal errors. The generic program error option is
// provided as a fallback for cases that don't fit those classifications.

inline auto CompilationError(SourceLocation loc) -> ErrorBuilder {
  ErrorBuilder builder;
  (void)(builder << "COMPILATION ERROR: " << loc << ": ");
  return builder;
}

inline auto ProgramError(SourceLocation loc) -> ErrorBuilder {
  ErrorBuilder builder;
  (void)(builder << "PROGRAM ERROR: " << loc << ": ");
  return builder;
}

inline auto RuntimeError(SourceLocation loc) -> ErrorBuilder {
  ErrorBuilder builder;
  (void)(builder << "RUNTIME ERROR: " << loc << ": ");
  return builder;
}

}  // namespace PYJU
