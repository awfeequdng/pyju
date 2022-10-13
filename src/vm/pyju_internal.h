#pragma once
#include "pyju_object.h"
#include "pyju_fasttls.h"
#include <uv.h>

#ifdef __cplusplus
extern "C" {
#endif

struct PyjuTypeEnv_t {
    PyjuTVar_t *var;
    PyjuValue_t *val;
    struct PyjuTypeEnv_t *prev;
};


// Exception stack: a stack of pairs of (exception,raw_backtrace).
// The stack may be traversed and accessed with the functions below.
struct PyjuExcStack_t {
    size_t top;
    size_t reserved_size;
    // Pack all stack entries into a growable buffer to amortize allocation
    // across repeated exception handling.
    // Layout: [bt_data1... bt_size1 exc1  bt_data2... bt_size2 exc2  ..]
    // jl_bt_element_t data[]; // Access with jl_excstack_raw
};

#if defined(_OS_DARWIN_)
typedef pthread_key_t pyju_pgcstack_key_t;
#elif defined(_OS_WINDOWS_)
typedef DWORD pyju_pgcstack_key_t;
#else
typedef PyjuGcFrame_t ***(*pyju_pgcstack_key_t)(void) PYJU_NOTSAFEPOINT;
#endif
PYJU_DLLEXPORT void pyju_pgcstack_getkey(pyju_get_pgcstack_func **f, pyju_pgcstack_key_t *k);



// number of cycles since power-on
static inline uint64_t cycleclock(void) PYJU_NOTSAFEPOINT
{
#if defined(_CPU_X86_64_)
    uint64_t low, high;
    __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
    return (high << 32) | low;
#elif defined(_CPU_X86_)
    int64_t ret;
    __asm__ volatile("rdtsc" : "=A"(ret));
    return ret;
#elif defined(_CPU_AARCH64_)
    // System timer of ARMv8 runs at a different frequency than the CPU's.
    // The frequency is fixed, typically in the range 1-50MHz.  It can be
    // read at CNTFRQ special register.  We assume the OS has set up
    // the virtual timer properly.
    int64_t virtual_timer_value;
    __asm__ volatile("mrs %0, cntvct_el0" : "=r"(virtual_timer_value));
    return virtual_timer_value;
#elif defined(_CPU_PPC64_)
    // This returns a time-base, which is not always precisely a cycle-count.
    // https://reviews.llvm.org/D78084
    int64_t tb;
    asm volatile("mfspr %0, 268" : "=r" (tb));
    return tb;
#else
    #warning No cycleclock() definition for your platform
    // copy from https://github.com/google/benchmark/blob/v1.5.0/src/cycleclock.h
    return 0;
#endif
}

#include "timing.h"


// If this is detected in a backtrace of segfault, it means the functions
// that use this value must be reworked into their async form with cb arg
// provided and with JL_UV_LOCK used around the calls
static uv_loop_t *const unused_uv_loop_arg = (uv_loop_t *)0xBAD10;

#ifdef __cplusplus
} // extern "C"
#endif