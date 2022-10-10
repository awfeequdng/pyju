#pragma once

#include <string>
#include <string_view>

#include "base/ostream.h"
#include "base/nonnull.h"

namespace PYJU {
class SourceLocation {
 public:
  // The filename should be eternal or arena-allocated to eliminate copies.
  constexpr SourceLocation(const char* filename, int line_num, int col=0)
      : filename_(filename), line_num_(line_num), column_(col) {}
  SourceLocation(Nonnull<const std::string*> filename, int line_num, int col=0)
      : filename_(filename->c_str()), line_num_(line_num), column_(col) {}

  SourceLocation(const SourceLocation&) = default;
  SourceLocation(SourceLocation&&) = default;
  auto operator=(const SourceLocation&) -> SourceLocation& = default;
  auto operator=(SourceLocation&&) -> SourceLocation& = default;

  auto operator==(SourceLocation other) const -> bool {
    return filename_ == other.filename_ && line_num_ == other.line_num_;
  }

  void Print(llvm::raw_ostream& out) const {
    out << filename_ << ":" << line_num_ << ":" << column_;
  }
  LLVM_DUMP_METHOD void Dump() const { Print(llvm::errs()); }

 private:
  std::string_view filename_;
  int line_num_ {};
  int column_ {};
};

}  // namespace PYJU
