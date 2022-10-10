
#pragma once

#include "base/check_internal.h"

namespace PYJU {

// Raw exiting stream. This should be used when building other forms of exiting
// macros like those below. It evaluates to a temporary `ExitingStream` object
// that can be manipulated, streamed into, and then will exit the program.
#define PXC_RAW_EXITING_STREAM() \
  PYJU::Internal::ExitingStream::Helper() | PYJU::Internal::ExitingStream()

// Checks the given condition, and if it's false, prints a stack, streams the
// error message, then exits. This should be used for unexpected errors, such as
// a bug in the application.
//
// For example:
//   PXC_CHECK(is_valid) << "Data is not valid!";
#define PXC_CHECK(condition)                                           \
  (condition) ? (void)0                                                   \
              : PXC_RAW_EXITING_STREAM()                               \
                    << "CHECK failure at " << __FILE__ << ":" << __LINE__ \
                    << ": " #condition                                    \
                    << PYJU::Internal::ExitingStream::AddSeparator()

// DCHECK calls CHECK in debug mode, and does nothing otherwise.
#ifndef NDEBUG
#define PXC_DCHECK(condition) PXC_CHECK(condition)
#else
#define PXC_DCHECK(condition) PXC_CHECK(true || (condition))
#endif

// This is similar to CHECK, but is unconditional. Writing PXC_FATAL() is
// clearer than PXC_CHECK(false) because it avoids confusion about control
// flow.
//
// For example:
//   PXC_FATAL() << "Unreachable!";
#define PXC_FATAL()        \
  PXC_RAW_EXITING_STREAM() \
      << "FATAL failure at " << __FILE__ << ":" << __LINE__ << ": "

}  // namespace PYJU

