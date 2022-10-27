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

    char **new_argv = argv;
    pyju_parse_opts(&argc, (char***)&new_argv);


    pyju_init();
    int ret = true_main(argc, argv);
    return ret;
}

// get the name of a type as a string
PYJU_DLLEXPORT const char *pyju_typename_str(PyjuValue_t *v)
{
    if (!pyju_is_datatype(v))
        return NULL;
    return pyju_symbol_name(((PyjuDataType_t*)v)->name->name);
}

// get the name of typeof(v) as a string
PYJU_DLLEXPORT const char *pyju_typeof_str(PyjuValue_t *v)
{
    return pyju_typename_str((PyjuValue_t*)pyju_typeof(v));
}


#ifdef __cplusplus
}
#endif