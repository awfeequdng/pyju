// This file is a part of Julia. License is MIT: https://julialang.org/license

// Pointers that are exposed through the public libjulia
#define PYJU_EXPORTED_DATA_POINTERS(XX) \
    XX(pyju_true) \
    XX(pyju_false) \
    XX(pyju_nothing) \
    XX(pyju_an_empty_vec_any) \
    XX(pyju_emptysvec) \
    XX(pyju_nonfunction_mt) \
    XX(pyju_nothing_type) \
    XX(pyju_symbol_type) \
    XX(pyju_task_type) \
    XX(pyju_methtable_type) \
    XX(pyju_typename_type) \
    XX(pyju_function_type) \
    XX(pyju_builtin_type) \
    XX(pyju_simplevector_type) \
    XX(pyju_datatype_type)


// Data symbols that are defined inside the public libjulia
#define PYJU_EXPORTED_DATA_SYMBOLS(XX) \
    XX(pyju_n_threads, int) \
    XX(pyju_options, pyju_options_t)

// end of file
