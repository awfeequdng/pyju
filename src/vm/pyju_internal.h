#pragma once
#include "pyju_object.h"
#include "pyju_fasttls.h"

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


#ifdef __cplusplus
} // extern "C"
#endif