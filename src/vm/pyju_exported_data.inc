// This file is a part of Julia. License is MIT: https://julialang.org/license

// Pointers that are exposed through the public libjulia
#define PYJU_EXPORTED_DATA_POINTERS(XX) \
    XX(pyju_undefref_exception) \
    XX(pyju_true) \
    XX(pyju_false) \
    XX(pyju_nothing) \
    XX(pyju_an_empty_vec_any) \
    XX(pyju_emptysvec) \
    XX(pyju_nonfunction_mt) \
    XX(pyju_type_type_mt) \
    XX(pyju_type_typename) \
    XX(pyju_tuple_typename) \
    XX(pyju_emptytuple) \
    XX(pyju_an_empty_string) \
    XX(pyju_memory_exception) \
    XX(pyju_namedtuple_typename) \
    XX(pyju_vecelement_typename) \
    XX(pyju_void_type) \
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
    XX(pyju_unionall_type) \
    XX(pyju_any_type) \
    XX(pyju_vararg_type) \
    XX(pyju_uniontype_type) \
    XX(pyju_tvar_type) \
    XX(pyju_bool_type) \
    XX(pyju_string_type) \
    XX(pyju_typeofbottom_type) \
    XX(pyju_type_type) \
    XX(pyju_compute_fieldtypes) \
    XX(pyju_array_typename) \
    XX(pyju_module_type) \
    XX(pyju_bottom_type) \
    XX(pyju_anytuple_type) \
    XX(pyju_emptytuple_type) \
    XX(pyju_pair_type) \
    XX(pyju_boundserror_type) \
    XX(pyju_argumenterror_type) \
    XX(pyju_array_uint8_type) \
    XX(pyju_array_any_type) \
    XX(pyju_array_type) \
    XX(pyju_datatype_type)


// Data symbols that are defined inside the public libjulia
#define PYJU_EXPORTED_DATA_SYMBOLS(XX) \
    XX(pyju_n_threads, int) \
    XX(pyju_options, pyju_options_t)

// end of file
