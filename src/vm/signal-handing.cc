
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>
#include "pyju.h"
#include "pyju_internal.h"

#include <unistd.h>
#include <sys/mman.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "threading.h"


static uint64_t pyju_last_sigint_trigger = 0;
static uint64_t pyju_disable_sigint_time = 0;
static void pyju_clear_force_sigint(void)
{
    pyju_last_sigint_trigger = 0;
}

static int pyju_check_force_sigint(void)
{
    static double accum_weight = 0;
    uint64_t cur_time = uv_hrtime();
    uint64_t dt = cur_time - pyju_last_sigint_trigger;
    uint64_t last_t = pyju_last_sigint_trigger;
    pyju_last_sigint_trigger = cur_time;
    if (last_t == 0) {
        accum_weight = 0;
        return 0;
    }
    double new_weight = accum_weight * exp(-(dt / 1e9)) + 0.3;
    if (!isnormal(new_weight))
        new_weight = 0;
    accum_weight = new_weight;
    if (new_weight > 1) {
        pyju_disable_sigint_time = cur_time + (uint64_t)0.5e9;
        return 1;
    }
    pyju_disable_sigint_time = 0;
    return 0;
}

static volatile int pyju_sigint_passed = 0;
static sigset_t pyju_sigint_sset;

static int pyju_ignore_sigint(void)
{
    // On Unix, we get the SIGINT before the debugger which makes it very
    // hard to interrupt a running process in the debugger with `Ctrl-C`.
    // Manually raise a `SIGINT` on current thread with the signal temporarily
    // unblocked and use it's behavior to decide if we need to handle the signal.
    pyju_sigint_passed = 0;
    pthread_sigmask(SIG_UNBLOCK, &pyju_sigint_sset, NULL);
    // This can swallow an external `SIGINT` but it's not an issue
    // since we don't deliver the same number of signals anyway.
    pthread_kill(pthread_self(), SIGINT);
    pthread_sigmask(SIG_BLOCK, &pyju_sigint_sset, NULL);
    if (!pyju_sigint_passed)
        return 1;
    // Force sigint requires pressing `Ctrl-C` repeatedly.
    // Ignore sigint for a short time after that to avoid rethrowing sigint too
    // quickly again. (Code that has this issue is inherently racy but this is
    // an interactive feature anyway.)
    return pyju_disable_sigint_time && pyju_disable_sigint_time > uv_hrtime();
}

static int exit_on_sigint = 0;
PYJU_DLLEXPORT void pyju_exit_on_sigint(int on)
{
    exit_on_sigint = on;
}

#include "signals.inc"

#ifdef __cplusplus
}
#endif
