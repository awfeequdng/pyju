// This file is a part of Julia. License is MIT: https://julialang.org/license

#include <inttypes.h>
#include "pyju.h"
#include "pyju_internal.h"
#include "options.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ENABLE_TIMINGS
#include "timing.h"

#ifndef HAVE_TIMING_SUPPORT
#error Timings are not supported on your compiler
#endif

static uint64_t t0;
PYJU_DLLEXPORT uint64_t pyju_timing_data[(int)PYJU_TIMING_LAST] = {0};
const char *pyju_timing_names[(int)PYJU_TIMING_LAST] =
    {
#define X(name) #name
        PYJU_TIMING_OWNERS
#undef X
    };

void pyju_print_timings(void)
{
    uint64_t total_time = cycleclock() - t0;
    uint64_t root_time = total_time;
    for (int i = 0; i < PYJU_TIMING_LAST; i++) {
        root_time -= pyju_timing_data[i];
    }
    pyju_timing_data[0] = root_time;
    for (int i = 0; i < PYJU_TIMING_LAST; i++) {
        if (pyju_timing_data[i] != 0)
            fprintf(stderr, "%-25s : %5.2f %%   %" PRIu64 "\n", pyju_timing_names[i],
                    100 * (((double)pyju_timing_data[i]) / total_time), pyju_timing_data[i]);
    }
}

void pyju_init_timing(void)
{
    t0 = cycleclock();
}

void pyju_destroy_timing(void)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    PyjuTimingBlock_t *stack = ptls->timing_stack;
    while (stack) {
        _pyju_timing_block_destroy(stack);
        stack = stack->prev;
    }
}

PyjuTimingBlock_t *pyju_pop_timing_block(PyjuTimingBlock_t *cur_block)
{
    _pyju_timing_block_destroy(cur_block);
    return cur_block->prev;
}

void pyju_timing_block_start(PyjuTimingBlock_t *cur_block)
{
    _pyju_timing_block_start(cur_block, cycleclock());
}

void pyju_timing_block_stop(PyjuTimingBlock_t *cur_block)
{
    _pyju_timing_block_stop(cur_block, cycleclock());
}

#else

void pyju_init_timing(void) { }
void pyju_destroy_timing(void) { }

#endif

#ifdef __cplusplus
}
#endif
