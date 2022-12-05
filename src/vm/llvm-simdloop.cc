// This file is a part of Julia. License is MIT: https://julialang.org/license

#include "llvm-version.h"

#define DEBUG_TYPE "lower_simd_loop"

// This file defines a LLVM pass that:
// 1. Set's loop information in form of metadata
// 2. If the metadata contains `julia.simdloop` finds reduction chains and marks
//    floating-point operations as fast-math. `See enableUnsafeAlgebraIfReduction`.
// 3. If the metadata contains `julia.ivdep` marks all memory accesses in the loop
//    as independent of each other.
//
// The pass hinges on a call to a marker function that has metadata attached to it.
// To construct the pass call `createLowerSimdLoopPass`.

#include "support/dtypes.h"

#include <llvm/Analysis/LoopPass.h>
#include <llvm/IR/LegacyPassManager.h>
