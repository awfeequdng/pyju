// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_TIMING_H
#define PYJU_TIMING_H
#include "options.h"

#ifdef __cplusplus
extern "C" {
#endif
void pyju_init_timing(void);
void pyju_destroy_timing(void);
#ifdef __cplusplus
}
#endif

#ifndef ENABLE_TIMINGS
#define PYJU_TIMING(owner)
#else

#include "pyju_assert.h"
#include "support/dtypes.h"

#ifdef __cplusplus
extern "C" {
#endif
struct PyjuTimingBlock_t;

void pyju_print_timings(void);
PyjuTimingBlock_t *pyju_pop_timing_block(PyjuTimingBlock_t *cur_block);
void pyju_timing_block_start(PyjuTimingBlock_t *cur_block);
void pyju_timing_block_stop(PyjuTimingBlock_t *cur_block);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#define HAVE_TIMING_SUPPORT
#elif defined(_COMPILER_CLANG_)
#define HAVE_TIMING_SUPPORT
#elif defined(_COMPILER_GCC_)
#define HAVE_TIMING_SUPPORT
#endif

#ifndef HAVE_TIMING_SUPPORT
#define PYJU_TIMING(owner)
#else

#define PYJU_TIMING_OWNERS          \
        X(ROOT),                  \
        X(GC),                    \
        X(LOWERING),              \
        X(PARSING),               \
        X(INFERENCE),             \
        X(CODEGEN),               \
        X(METHOD_LOOKUP_SLOW),    \
        X(METHOD_LOOKUP_FAST),    \
        X(LLVM_OPT),              \
        X(LLVM_MODULE_FINISH),    \
        X(METHOD_MATCH),          \
        X(TYPE_CACHE_LOOKUP),     \
        X(TYPE_CACHE_INSERT),     \
        X(STAGED_FUNCTION),       \
        X(MACRO_INVOCATION),      \
        X(AST_COMPRESS),          \
        X(AST_UNCOMPRESS),        \
        X(SYSIMG_LOAD),           \
        X(SYSIMG_DUMP),           \
        X(NATIVE_DUMP),           \
        X(ADD_METHOD),            \
        X(LOAD_MODULE),           \
        X(SAVE_MODULE),           \
        X(INIT_MODULE),

enum pyju_timing_owners {
#define X(name) PYJU_TIMING_ ## name
    PYJU_TIMING_OWNERS
#undef X
    PYJU_TIMING_LAST
};

extern uint64_t pyju_timing_data[(int)PYJU_TIMING_LAST];
extern const char *pyju_timing_names[(int)PYJU_TIMING_LAST];

struct PyjuTimingBlock_t { // typedef in julia.h
    PyjuTimingBlock_t *prev;
    uint64_t total;
    uint64_t t0;
    int owner;
#ifdef PYJU_DEBUG_BUILD
    uint8_t running;
#endif
};

STATIC_INLINE void _pyju_timing_block_stop(PyjuTimingBlock_t *block, uint64_t t) {
#ifdef PYJU_DEBUG_BUILD
    assert(block->running);
    block->running = 0;
#endif
    block->total += t - block->t0;
}

STATIC_INLINE void _pyju_timing_block_start(PyjuTimingBlock_t *block, uint64_t t) {
#ifdef PYJU_DEBUG_BUILD
    assert(!block->running);
    block->running = 1;
#endif
    block->t0 = t;
}

STATIC_INLINE uint64_t _pyju_timing_block_init(PyjuTimingBlock_t *block, int owner) {
    uint64_t t = cycleclock();
    block->owner = owner;
    block->total = 0;
#ifdef PYJU_DEBUG_BUILD
    block->running = 0;
#endif
    _pyju_timing_block_start(block, t);
    return t;
}

STATIC_INLINE void _pyju_timing_block_ctor(PyjuTimingBlock_t *block, int owner) {
    uint64_t t = _pyju_timing_block_init(block, owner);
    pyju_task_t *ct = pyju_current_task;
    PyjuTimingBlock_t **prevp = &ct->ptls->timing_stack;
    block->prev = *prevp;
    if (block->prev)
        _pyju_timing_block_stop(block->prev, t);
    *prevp = block;
}

STATIC_INLINE void _pyju_timing_block_destroy(PyjuTimingBlock_t *block) {
    uint64_t t = cycleclock();
    pyju_task_t *ct = pyju_current_task;
    _pyju_timing_block_stop(block, t);
    pyju_timing_data[block->owner] += block->total;
    PyjuTimingBlock_t **pcur = &ct->ptls->timing_stack;
    assert(*pcur == block);
    *pcur = block->prev;
    if (block->prev)
        _pyju_timing_block_start(block->prev, t);
}

#ifdef __cplusplus
struct pyju_timing_block_cpp_t {
    PyjuTimingBlock_t block;
    pyju_timing_block_cpp_t(int owner) {
        _pyju_timing_block_ctor(&block, owner);
    }
    ~pyju_timing_block_cpp_t() {
        _pyju_timing_block_destroy(&block);
    }
    pyju_timing_block_cpp_t(const pyju_timing_block_cpp_t&) = delete;
    pyju_timing_block_cpp_t(const pyju_timing_block_cpp_t&&) = delete;
    pyju_timing_block_cpp_t& operator=(const pyju_timing_block_cpp_t &) = delete;
    pyju_timing_block_cpp_t& operator=(const pyju_timing_block_cpp_t &&) = delete;
};
#define PYJU_TIMING(owner) pyju_timing_block_cpp_t __timing_block(PYJU_TIMING_ ## owner)
#else
#define PYJU_TIMING(owner) \
    __attribute__((cleanup(_pyju_timing_block_destroy))) \
    pyju_timing_block_t __timing_block; \
    _pyju_timing_block_ctor(&__timing_block, PYJU_TIMING_ ## owner)
#endif

#endif
#endif

#endif
