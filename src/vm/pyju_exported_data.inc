// This file is a part of Julia. License is MIT: https://julialang.org/license

// Pointers that are exposed through the public libjulia
#define PYJU_EXPORTED_DATA_POINTERS(XX) \
    XX(pyju_true) \
    XX(pyju_false) \
    XX(pyju_nothing) \
    XX(pyju_an_empty_vec_any) \
    XX(pyju_emptysvec) \
    XX(pyju_nonfunction_mt) \
    XX(pyju_float32_type) \
    XX(pyju_voidpointer_type) \
    XX(pyju_uint8pointer_type) \
    XX(pyju_float64_type) \
    XX(pyju_int16_type) \
    XX(pyju_int32_type) \
    XX(pyju_uint16_type) \
    XX(pyju_uint32_type) \
    XX(pyju_ssavalue_type) \
    XX(pyju_slotnumber_type) \
    XX(pyju_int64_type) \
    XX(pyju_uint64_type) \
    XX(pyju_char_type) \
    XX(pyju_uint8_type) \
    XX(pyju_int8_type) \
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
