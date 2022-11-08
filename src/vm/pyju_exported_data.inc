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
    XX(pyju_vecelement_typename) \
    XX(pyju_core_module) \
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
    XX(pyju_abstractslot_type) \
    XX(pyju_typedslot_type) \
    XX(pyju_argument_type) \
    XX(pyju_abstractstring_type) \
    XX(pyju_typemap_level_type) \
    XX(pyju_typemap_entry_type) \
    XX(pyju_abstractarray_type) \
    XX(pyju_densearray_type) \
    XX(pyju_array_symbol_type) \
    XX(pyju_array_int32_type) \
    XX(pyju_array_uint64_type) \
    XX(pyju_expr_type) \
    XX(pyju_linenumbernode_type) \
    XX(pyju_lineinfonode_type) \
    XX(pyju_gotonode_type) \
    XX(pyju_gotoifnot_type) \
    XX(pyju_returnnode_type) \
    XX(pyju_pinode_type) \
    XX(pyju_phinode_type) \
    XX(pyju_phicnode_type) \
    XX(pyju_upsilonnode_type) \
    XX(pyju_quotenode_type) \
    XX(pyju_newvarnode_type) \
    XX(pyju_globalref_type) \
    XX(pyju_code_info_type) \
    XX(pyju_method_type) \
    XX(pyju_method_instance_type) \
    XX(pyju_code_instance_type) \
    XX(pyju_const_type) \
    XX(pyju_partial_struct_type) \
    XX(pyju_interconditional_type) \
    XX(pyju_method_match_type) \
    XX(pyju_intrinsic_type) \
    XX(pyju_ref_type) \
    XX(pyju_pointer_type) \
    XX(pyju_pointer_typename) \
    XX(pyju_llvmpointer_type) \
    XX(pyju_llvmpointer_typename) \
    XX(pyju_anytuple_type_type) \
    XX(pyju_namedtuple_type) \
    XX(pyju_namedtuple_typename) \
    XX(pyju_opaque_closure_type) \
    XX(pyju_opaque_closure_typename) \
    XX(pyju_partial_opaque_type) \
    XX(pyju_datatype_type)


// Data symbols that are defined inside the public libjulia
#define PYJU_EXPORTED_DATA_SYMBOLS(XX) \
    XX(pyju_n_threads, int) \
    XX(pyju_options, pyju_options_t)

// end of file
