// This file is a part of Julia. License is MIT: https://julialang.org/license

// Pointers that are exposed through the public libjulia
#define PYJU_EXPORTED_DATA_POINTERS(XX) \
    XX(pyju_datatype_type)


// Data symbols that are defined inside the public libjulia
#define PYJU_EXPORTED_DATA_SYMBOLS(XX) \
    XX(pyju_n_threads, int) \
    XX(pyju_options, pyju_options_t)

// end of file
