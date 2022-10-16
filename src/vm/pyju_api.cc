#include "support/dtypes.h"
#include "pyju_internal.h"
#include "pyju_object.h"

#ifdef __cplusplus
extern "C" {
#endif

static NOINLINE int true_main(int argc, char *argv[])
{
    return 0;
}

PYJU_DLLEXPORT int pyju_repl_entrypoint(int argc, char *argv[])
{
    // no-op on Windows, note that the caller must have already converted
    // from `wchar_t` to `UTF-8` already if we're running on Windows.
    uv_setup_args(argc, argv);

    libsupport_init();

    pyju_init();
    int ret = true_main(argc, argv);
    return ret;
}

#ifdef __cplusplus
}
#endif