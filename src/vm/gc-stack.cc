
#include "gc.h"
#ifndef _OS_WINDOWS_
#  include <sys/resource.h>
#endif

#ifdef _P64
# ifdef _OS_WINDOWS_
#  define MAX_STACK_MAPPINGS 500
# else
#  define MAX_STACK_MAPPINGS 30000
# endif
#else
# ifdef _OS_WINDOWS_
#  define MAX_STACK_MAPPINGS 250
# else
#  define MAX_STACK_MAPPINGS 500
# endif
#endif

// number of stacks to always keep available per pool
#define MIN_STACK_MAPPINGS_PER_POOL 5

const size_t pyju_guard_size = (4096 * 8);
static _Atomic(uint32_t) num_stack_mappings = 0;

#ifdef _OS_WINDOWS_
#define MAP_FAILED NULL
static void *malloc_stack(size_t bufsz) JL_NOTSAFEPOINT
{
    void *stk = VirtualAlloc(NULL, bufsz, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (stk == NULL)
        return MAP_FAILED;
    DWORD dwOldProtect;
    if (!VirtualProtect(stk, pyju_guard_size, PAGE_READWRITE | PAGE_GUARD, &dwOldProtect)) {
        VirtualFree(stk, 0, MEM_RELEASE);
        return MAP_FAILED;
    }
    pyju_atomic_fetch_add(&num_stack_mappings, 1);
    return stk;
}


static void free_stack(void *stkbuf, size_t bufsz)
{
    VirtualFree(stkbuf, 0, MEM_RELEASE);
    pyju_atomic_fetch_add(&num_stack_mappings, -1);
}

#else

static void *malloc_stack(size_t bufsz) PYJU_NOTSAFEPOINT
{
    void* stk = mmap(0, bufsz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (stk == MAP_FAILED)
        return MAP_FAILED;
#if !defined(JL_HAVE_UCONTEXT) && !defined(JL_HAVE_SIGALTSTACK)
    // setup a guard page to detect stack overflow
    if (mprotect(stk, pyju_guard_size, PROT_NONE) == -1) {
        munmap(stk, bufsz);
        return MAP_FAILED;
    }
#endif
    pyju_atomic_fetch_add(&num_stack_mappings, 1);
    return stk;
}

static void free_stack(void *stkbuf, size_t bufsz)
{
    munmap(stkbuf, bufsz);
    pyju_atomic_fetch_add(&num_stack_mappings, -1);
}
#endif


const unsigned pool_sizes[] = {
    128 * 1024,
    192 * 1024,
    256 * 1024,
    384 * 1024,
    512 * 1024,
    768 * 1024,
    1024 * 1024,
    1537 * 1024,
    2048 * 1024,
    3 * 1024 * 1024,
    4 * 1024 * 1024,
    6 * 1024 * 1024,
    8 * 1024 * 1024,
    12 * 1024 * 1024,
    16 * 1024 * 1024,
    24 * 1024 * 1024,
};

static_assert(sizeof(pool_sizes) == PYJU_N_STACK_POOLS * sizeof(pool_sizes[0]), "PYJU_N_STACK_POOLS size mismatch");

static unsigned select_pool(size_t nb) PYJU_NOTSAFEPOINT
{
    unsigned pool_id = 0;
    while (pool_sizes[pool_id] < nb)
        pool_id++;
    return pool_id;
}

PYJU_DLLEXPORT void *pyju_malloc_stack(size_t *bufsz, PyjuTask_t *owner) PYJU_NOTSAFEPOINT
{
    PyjuTask_t *ct = pyju_current_task;
    PyjuPtls_t ptls = ct->ptls;
    size_t ssize = *bufsz;
    void *stk = NULL;
    if (ssize <= pool_sizes[PYJU_N_STACK_POOLS - 1]) {
        unsigned pool_id = select_pool(ssize);
        ssize = pool_sizes[pool_id];
        arraylist_t *pool = &ptls->heap.free_stacks[pool_id];
        if (pool->len > 0) {
            stk = arraylist_pop(pool);
        }
    }
    else {
        ssize = LLT_ALIGN(ssize, pyju_page_size);
    }
    if (stk == NULL) {
        if (pyju_atomic_load_relaxed(&num_stack_mappings) >= MAX_STACK_MAPPINGS)
            // we accept that this can go over by as much as nthreads since it's not a CAS
            return NULL;
        // TODO: allocate blocks of stacks? but need to mprotect individually anyways
        stk = malloc_stack(ssize);
        if (stk == MAP_FAILED)
            return NULL;
    }
    *bufsz = ssize;
    if (owner) {
        arraylist_t *live_tasks = &ptls->heap.live_tasks;
        arraylist_push(live_tasks, owner);
    }
    return stk;
}