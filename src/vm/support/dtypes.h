// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_DTYPES_H
#define PYJU_DTYPES_H

#include <stddef.h>
#include <stddef.h> // double include of stddef.h fixes #3421
#include <stdint.h>
#include <string.h> // memcpy
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // NAN and INF constants

#include <inttypes.h>

#include "platform.h"

#define PYJU_DLLEXPORT __attribute__ ((visibility("default")))
#define PYJU_DLLIMPORT
#define PYJU_NOTSAFEPOINT

#ifdef _OS_LINUX_
#include <endian.h>
#define LITTLE_ENDIAN  __LITTLE_ENDIAN
#define BIG_ENDIAN     __BIG_ENDIAN
#define PDP_ENDIAN     __PDP_ENDIAN
#define BYTE_ORDER     __BYTE_ORDER
#endif

#if defined(__APPLE__) || defined(__FreeBSD__)
#include <machine/endian.h>
#define __LITTLE_ENDIAN  LITTLE_ENDIAN
#define __BIG_ENDIAN     BIG_ENDIAN
#define __PDP_ENDIAN     PDP_ENDIAN
#define __BYTE_ORDER     BYTE_ORDER
#endif


#define LLT_ALLOC(n) malloc(n)
#define LLT_REALLOC(p,n) realloc((p),(n))
#define LLT_FREE(x) free(x)

#define STATIC_INLINE static inline

#define NOINLINE __attribute__((noinline))
#define NOINLINE_DECL(f) f __attribute__((noinline))

#if defined(__GNUC__)
#  define PYJU_ATTRIBUTE_ALIGN_PTRSIZE(x) x __attribute__ ((aligned (sizeof(void*))))
#else
#  define PYJU_ATTRIBUTE_ALIGN_PTRSIZE(x)
#endif

#ifdef __has_builtin
#  define pyju_has_builtin(x) __has_builtin(x)
#else
#  define pyju_has_builtin(x) 0
#endif

#if pyju_has_builtin(__builtin_assume)
#define pyju_assume(cond) (__extension__ ({               \
                __typeof__(cond) cond_ = (cond);        \
                __builtin_assume(!!(cond_));            \
                cond_;                                  \
            }))
#elif defined(__GNUC__)
static inline void pyju_assume_(int cond)
{
    if (!cond) {
        __builtin_unreachable();
    }
}
#define pyju_assume(cond) (__extension__ ({               \
                __typeof__(cond) cond_ = (cond);        \
                pyju_assume_(!!(cond_));                  \
                cond_;                                  \
            }))
#else
#define pyju_assume(cond) (cond)
#endif

#if pyju_has_builtin(__builtin_assume_aligned) || defined(_COMPILER_GCC_)
#define pyju_assume_aligned(ptr, align) __builtin_assume_aligned(ptr, align)
#elif defined(__GNUC__)
#define pyju_assume_aligned(ptr, align) (__extension__ ({         \
                __typeof__(ptr) ptr_ = (ptr);                   \
                pyju_assume(((uintptr_t)ptr) % (align) == 0);     \
                ptr_;                                           \
            }))
#elif defined(__cplusplus)
template<typename T>
static inline T
pyju_assume_aligned(T ptr, unsigned align)
{
    (void)pyju_assume(((uintptr_t)ptr) % align == 0);
    return ptr;
}
#else
#define pyju_assume_aligned(ptr, align) (ptr)
#endif

typedef int bool_t;
typedef unsigned char  byte_t;   /* 1 byte */

#ifdef _P64
#define TOP_BIT 0x8000000000000000
#define NBITS 64
typedef uint64_t uint_t;  // preferred int type on platform
typedef int64_t int_t;
#else
#define TOP_BIT 0x80000000
#define NBITS 32
typedef uint32_t uint_t;
typedef int32_t int_t;
#endif

STATIC_INLINE unsigned int next_power_of_two(unsigned int val)
{
    /* this function taken from libuv src/unix/core.c */
    val -= 1;
    val |= val >> 1;
    val |= val >> 2;
    val |= val >> 4;
    val |= val >> 8;
    val |= val >> 16;
    val += 1;
    return val;
}

#define LLT_ALIGN(x, sz) (((x) + (sz)-1) & ~((sz)-1))

// branch prediction annotations
#ifdef __GNUC__
#define __unlikely(x) __builtin_expect(!!(x), 0)
#define __likely(x)   __builtin_expect(!!(x), 1)
#define PYJU_EXTENSION __extension__
#else
#define __unlikely(x) (x)
#define __likely(x)   (x)
#define PYJU_EXTENSION
#endif

#define DBL_MAXINT 9007199254740992LL
#define FLT_MAXINT 16777216
#define U64_MAX    18446744073709551615ULL
#define S64_MAX    9223372036854775807LL
#define S64_MIN    (-S64_MAX - 1LL)
#define BIT63      0x8000000000000000LL
#define U32_MAX    4294967295L
#define S32_MAX    2147483647L
#define S32_MIN    (-S32_MAX - 1L)
#define BIT31      0x80000000

#define D_PNAN ((double)+NAN)
#define D_NNAN ((double)-NAN)
#define D_PINF ((double)+INFINITY)
#define D_NINF ((double)-INFINITY)
#define F_PNAN ((float)+NAN)
#define F_NNAN ((float)-NAN)
#define F_PINF ((float)+INFINITY)
#define F_NINF ((float)-INFINITY)

typedef enum { T_INT8, T_UINT8, T_INT16, T_UINT16, T_INT32, T_UINT32,
               T_INT64, T_UINT64, T_FLOAT, T_DOUBLE } numerictype_t;

#define N_NUMTYPES ((int)T_DOUBLE+1)

#ifdef _P64
# define T_PTRDIFF T_INT64
# define T_SIZE T_UINT64
#else
# define T_PTRDIFF T_INT32
# define T_SIZE T_UINT32
#endif

#if defined(__GNUC__) && __GNUC__ >= 7
#define PYJU_FALLTHROUGH __attribute__((fallthrough))
#elif defined(__cplusplus) && defined(__clang_major__) && \
    defined(__clang_minor__) && (__clang_major__ > 4 || __clang_minor__ >= 5)
// We require at least clang 3.x
#define PYJU_FALLTHROUGH [[clang::fallthrough]]
#else
#define PYJU_FALLTHROUGH
#endif

#if defined(__GNUC__)
#define PYJU_UNUSED __attribute__((__unused__))
#else
#define PYJU_UNUSED
#endif

STATIC_INLINE double pyju_load_unaligned_f64(const void *ptr)
{
    double val;
    memcpy(&val, ptr, sizeof(double));
    return val;
}

STATIC_INLINE uint64_t pyju_load_unaligned_i64(const void *ptr)
{
    uint64_t val;
    memcpy(&val, ptr, sizeof(uint64_t));
    return val;
}

STATIC_INLINE double pyju_load_ptraligned_f64(const void *ptr)
{
    double val;
    memcpy(&val, pyju_assume_aligned(ptr, sizeof(void*)), sizeof(double));
    return val;
}

STATIC_INLINE uint64_t pyju_load_ptraligned_i64(const void *ptr)
{
    uint64_t val;
    memcpy(&val, pyju_assume_aligned(ptr, sizeof(void*)), sizeof(uint64_t));
    return val;
}


STATIC_INLINE uint32_t pyju_load_unaligned_i32(const void *ptr)
{
    uint32_t val;
    memcpy(&val, ptr, 4);
    return val;
}
STATIC_INLINE uint16_t pyju_load_unaligned_i16(const void *ptr)
{
    uint16_t val;
    memcpy(&val, ptr, 2);
    return val;
}

STATIC_INLINE void pyju_store_unaligned_i64(void *ptr, uint64_t val)
{
    memcpy(ptr, &val, 8);
}
STATIC_INLINE void pyju_store_unaligned_i32(void *ptr, uint32_t val)
{
    memcpy(ptr, &val, 4);
}
STATIC_INLINE void pyju_store_unaligned_i16(void *ptr, uint16_t val)
{
    memcpy(ptr, &val, 2);
}

STATIC_INLINE void *malloc_s(size_t sz) {
    int last_errno = errno;

    void *p = malloc(sz == 0 ? 1 : sz);
    if (p == NULL) {
        perror("(pyju) malloc");
        abort();
    }

    errno = last_errno;
    return p;
}

STATIC_INLINE void *realloc_s(void *p, size_t sz) {
    int last_errno = errno;
    p = realloc(p, sz == 0 ? 1 : sz);
    if (p == NULL) {
        perror("(julia) realloc");
        abort();
    }
    errno = last_errno;
    return p;
}

#endif /* DTYPES_H */
