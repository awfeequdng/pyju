// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef __has_feature
#define __has_feature(x) 0
#endif
#if !(defined(__clang__) && __has_feature(nullability))
#define _Nonnull
#endif
#define PYJU_NONNULL _Nonnull

#ifdef __clang_gcanalyzer__

#define PYJU_PROPAGATES_ROOT __attribute__((annotate("julia_propagates_root")))
#define PYJU_NOTSAFEPOINT __attribute__((annotate("julia_not_safepoint")))
#define PYJU_MAYBE_UNROOTED __attribute__((annotate("julia_maybe_unrooted")))
#define PYJU_GLOBALLY_ROOTED __attribute__((annotate("julia_globally_rooted")))
#define PYJU_ROOTING_ARGUMENT __attribute__((annotate("julia_rooting_argument")))
#define PYJU_ROOTED_ARGUMENT __attribute__((annotate("julia_rooted_argument")))
#define PYJU_GC_DISABLED __attribute__((annotate("julia_gc_disabled")))
#define PYJU_ALWAYS_LEAFTYPE PYJU_GLOBALLY_ROOTED
#define PYJU_ROOTS_TEMPORARILY __attribute__((annotate("julia_temporarily_roots")))
#define PYJU_REQUIRE_ROOTED_SLOT __attribute__((annotate("julia_require_rooted_slot")))
#define PYJU_ROOTED_VALUE_COLLECTION __attribute__((annotate("julia_rooted_value_collection")))
#ifdef __cplusplus
extern "C" {
#endif
  void PYJU_GC_PROMISE_ROOTED(void *v) PYJU_NOTSAFEPOINT;
  void pyju_may_leak(uintptr_t) PYJU_NOTSAFEPOINT;
#ifdef __cplusplus
}
#endif

#else

#define PYJU_PROPAGATES_ROOT
#define PYJU_NOTSAFEPOINT
#define PYJU_MAYBE_UNROOTED
#define PYJU_GLOBALLY_ROOTED
#define PYJU_ROOTING_ARGUMENT
#define PYJU_ROOTED_ARGUMENT
#define PYJU_GC_DISABLED
#define PYJU_ALWAYS_LEAFTYPE
#define PYJU_ROOTS_TEMPORARILY
#define PYJU_REQUIRE_ROOTED_SLOT
#define PYJU_ROOTED_VALUE_COLLECTION
#define PYJU_GC_PROMISE_ROOTED(x) (void)(x)
#define pyju_may_leak(x) (void)(x)

#endif
