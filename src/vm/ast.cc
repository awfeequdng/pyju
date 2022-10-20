

/*
  AST
  components of the front-end, for obtaining and translating syntax trees
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _OS_WINDOWS_
#include <malloc.h>
#endif
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// head symbols for each expression type
PYJU_DLLEXPORT PyjuSym_t *pyju_call_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_invoke_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_invoke_modify_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_empty_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_top_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_module_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_slot_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_export_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_import_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_toplevel_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_quote_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_line_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_incomplete_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_goto_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_goto_ifnot_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_return_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_lineinfo_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_lambda_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_assign_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_globalref_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_do_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_method_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_core_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_enter_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_leave_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_pop_exception_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_exc_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_error_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_new_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_using_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_splatnew_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_block_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_new_opaque_closure_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_opaque_closure_method_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_const_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_thunk_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_foreigncall_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_as_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_global_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_list_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_dot_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_newvar_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_boundscheck_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_inbounds_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_copyast_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_cfunction_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_pure_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_loopinfo_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_meta_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_inert_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_polly_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_unused_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_static_parameter_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_inline_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_noinline_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_generated_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_generated_only_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_isdefined_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_propagate_inbounds_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_specialize_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_aggressive_constprop_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_no_constprop_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_purity_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_nospecialize_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_macrocall_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_colon_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_hygienicscope_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_throw_undef_if_not_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_getfield_undefref_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_gc_preserve_begin_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_gc_preserve_end_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_coverageeffect_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_escape_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_aliasscope_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_popaliasscope_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_optlevel_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_thismodule_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_atom_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_statement_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_all_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_compile_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_force_compile_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_infer_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_max_methods_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_atomic_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_not_atomic_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_unordered_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_monotonic_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_acquire_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_release_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_acquire_release_sym;
PYJU_DLLEXPORT PyjuSym_t *pyju_sequentially_consistent_sym;


#ifdef __cplusplus
}
#endif
