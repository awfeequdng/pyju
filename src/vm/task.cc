

#include "support/platform.h"

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>
#include "pyju.h"
#include "pyju_internal.h"
#include "threading.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ALWAYS_COPY_STACKS
# ifndef COPY_STACKS
# error "ALWAYS_COPY_STACKS requires COPY_STACKS"
# endif
static int always_copy_stacks = 1;
#else
static int always_copy_stacks = 0;
#endif

#define ROOT_TASK_STACK_ADJUSTMENT 3000000

// Do one-time initializations for task system
void pyju_init_tasks(void) PYJU_GC_DISABLED
{
    char *acs = getenv("JULIA_COPY_STACKS");
    if (acs) {
        if (!strcmp(acs, "1") || !strcmp(acs, "yes"))
            always_copy_stacks = 1;
        else if (!strcmp(acs, "0") || !strcmp(acs, "no"))
            always_copy_stacks = 0;
        else {
            pyju_safe_printf("invalid JULIA_COPY_STACKS value: %s\n", acs);
            exit(1);
        }
    }
#ifndef COPY_STACKS
    if (always_copy_stacks) {
        pyju_safe_printf("Julia built without COPY_STACKS support");
        exit(1);
    }
#endif
}

// a version of pyju_current_task safe for unmanaged threads
PYJU_DLLEXPORT PyjuTask_t *pyju_get_current_task(void)
{
    PyjuGcFrame_t **pgcstack = pyju_get_pgcstack();
    return pgcstack == NULL ? NULL : container_of(pgcstack, PyjuTask_t, gcstack);
}


PyjuTask_t *pyju_init_root_task(PyjuPtls_t ptls, void *stack_lo, void *stack_hi)
{
    assert(ptls->root_task == NULL);
    // We need `gcstack` in `Task` to allocate Julia objects; *including* the `Task` type.
    // However, to allocate a `Task` via `pyju_gc_alloc` as done in `pyju_init_root_task`,
    // we need the `Task` type itself. We use stack-allocated "raw" `PyjuTask_t` struct to
    // workaround this chicken-and-egg problem. Note that this relies on GC to be turned
    // off as GC fails because we don't/can't allocate the type tag.

    struct {
        PyjuValue_t *type;
        PyjuTask_t value;
    } bootstrap_task = {0};
    pyju_set_pgcstack(&bootstrap_task.value.gcstack);
    bootstrap_task.value.ptls = ptls;
    // TODO: pyju_nothing_type and pyju_task_type not initialized yet.
    if (pyju_nothing == NULL) // make a placeholder
        pyju_nothing = pyju_gc_permobj(0 + sizeof(PyjuTaggedValue_t), pyju_nothing_type);
    PyjuTask_t *ct = (PyjuTask_t*)pyju_gc_alloc(ptls, sizeof(PyjuTask_t), pyju_task_type);
    memset(ct, 0, sizeof(PyjuTask_t));
    void *stack = stack_lo;
    size_t ssize = (char*)stack_hi - (char*)stack_lo;
    if (ptls->tid == 0) {
        // TODO: ??????????????????????????????????????????
        stack = (void*)((char*)stack - ROOT_TASK_STACK_ADJUSTMENT); // offset our guess of the address of the bottom of stack to cover the guard pages too
        ssize += ROOT_TASK_STACK_ADJUSTMENT; // sizeof stack is known exactly, but not where we are in that stack
    }

    if (always_copy_stacks) {
        ct->copy_stack = 1;
        ct->bufsz = ssize;
    }

    ct->started = 1;
    ct->next = pyju_nothing;
    ct->queue = pyju_nothing;
    ct->tls = pyju_nothing;
    pyju_atomic_store_relaxed(&ct->_state, PYJU_TASK_STATE_RUNNABLE);
    ct->start = NULL;
    ct->result = pyju_nothing;
    pyju_atomic_store_relaxed(&ct->_isexception, 0);
    ct->logstate = pyju_nothing;
    ct->eh = NULL;
    ct->gcstack = NULL;
    ct->excstack = NULL;
    pyju_atomic_store_relaxed(&ct->tid, ptls->tid);
    ct->sticky = 1;
    ct->ptls = ptls;
    ct->world_age = 1; // OK to run pyju code on this task
    ptls->root_task = ct;
    pyju_atomic_store_relaxed(&ptls->current_task, ct);
    PYJU_GC_PROMISE_ROOTED(ct);
    pyju_set_pgcstack(&ct->gcstack);
    assert(pyju_current_task == ct);
    pyju_printf(PYJU_STDOUT, "pyju_init_root_task\n");

    return ct;
}

// record backtrace and raise an error
PYJU_DLLEXPORT void pyju_throw(PyjuValue_t *e PYJU_MAYBE_UNROOTED)
{
    pyju_printf(PYJU_STDERR, "pyju_throw not impl\n");
    abort();
}

// rethrow with current excstack state
PYJU_DLLEXPORT void pyju_rethrow(void)
{
    pyju_printf(PYJU_STDERR, "pyju_rethrow not impl\n");
    abort();
}


void PYJU_NORETURN pyju_finish_task(PyjuTask_t *t)
{
    DEBUG_FUNC_STR("not impl")
    // PyjuTask_t *ct = pyju_current_task;
    // PYJU_PROBE_RT_FINISH_TASK(ct);
    // PYJU_SIGATOMIC_BEGIN();
    // if (pyju_atomic_load_relaxed(&t->_isexception))
    //     pyju_atomic_store_release(&t->_state, PYJU_TASK_STATE_FAILED);
    // else
    //     pyju_atomic_store_release(&t->_state, PYJU_TASK_STATE_DONE);
    // if (t->copy_stack) // early free of stkbuf
    //     t->stkbuf = NULL;
    // // ensure that state is cleared
    // ct->ptls->in_finalizer = 0;
    // ct->ptls->in_pure_callback = 0;
    // ct->world_age = pyju_atomic_load_acquire(&pyju_world_counter);
    // // let the runtime know this task is dead and find a new task to run
    // pyju_function_t *done = pyju_atomic_load_relaxed(&task_done_hook_func);
    // if (done == NULL) {
    //     done = (pyju_function_t*)pyju_get_global(pyju_base_module, pyju_symbol("task_done_hook"));
    //     if (done != NULL)
    //         pyju_atomic_store_release(&task_done_hook_func, done);
    // }
    // if (done != NULL) {
    //     pyju_value_t *args[2] = {done, (pyju_value_t*)t};
    //     PYJU_TRY {
    //         pyju_apply(args, 2);
    //     }
    //     PYJU_CATCH {
    //         pyju_no_exc_handler(pyju_current_exception());
    //     }
    // }
    // pyju_gc_debug_critical_error();
    abort();
}

#ifdef __cplusplus
}
#endif