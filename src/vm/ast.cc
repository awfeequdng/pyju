

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
#include "pyju.h"
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


void pyju_init_common_symbols(void)
{
    pyju_empty_sym = pyju_symbol("");
    pyju_call_sym = pyju_symbol("call");
    pyju_invoke_sym = pyju_symbol("invoke");
    pyju_invoke_modify_sym = pyju_symbol("invoke_modify");
    pyju_foreigncall_sym = pyju_symbol("foreigncall");
    pyju_cfunction_sym = pyju_symbol("cfunction");
    pyju_quote_sym = pyju_symbol("quote");
    pyju_inert_sym = pyju_symbol("inert");
    pyju_top_sym = pyju_symbol("top");
    pyju_core_sym = pyju_symbol("core");
    pyju_globalref_sym = pyju_symbol("globalref");
    pyju_line_sym = pyju_symbol("line");
    pyju_lineinfo_sym = pyju_symbol("lineinfo");
    pyju_incomplete_sym = pyju_symbol("incomplete");
    pyju_error_sym = pyju_symbol("error");
    pyju_goto_sym = pyju_symbol("goto");
    pyju_goto_ifnot_sym = pyju_symbol("gotoifnot");
    pyju_return_sym = pyju_symbol("return");
    pyju_lambda_sym = pyju_symbol("lambda");
    pyju_module_sym = pyju_symbol("module");
    pyju_export_sym = pyju_symbol("export");
    pyju_import_sym = pyju_symbol("import");
    pyju_using_sym = pyju_symbol("using");
    pyju_assign_sym = pyju_symbol("=");
    pyju_method_sym = pyju_symbol("method");
    pyju_exc_sym = pyju_symbol("the_exception");
    pyju_enter_sym = pyju_symbol("enter");
    pyju_leave_sym = pyju_symbol("leave");
    pyju_pop_exception_sym = pyju_symbol("pop_exception");
    pyju_new_sym = pyju_symbol("new");
    pyju_splatnew_sym = pyju_symbol("splatnew");
    pyju_new_opaque_closure_sym = pyju_symbol("new_opaque_closure");
    pyju_opaque_closure_method_sym = pyju_symbol("opaque_closure_method");
    pyju_const_sym = pyju_symbol("const");
    pyju_global_sym = pyju_symbol("global");
    pyju_thunk_sym = pyju_symbol("thunk");
    pyju_toplevel_sym = pyju_symbol("toplevel");
    pyju_dot_sym = pyju_symbol(".");
    pyju_as_sym = pyju_symbol("as");
    pyju_colon_sym = pyju_symbol(":");
    pyju_boundscheck_sym = pyju_symbol("boundscheck");
    pyju_inbounds_sym = pyju_symbol("inbounds");
    pyju_newvar_sym = pyju_symbol("newvar");
    pyju_copyast_sym = pyju_symbol("copyast");
    pyju_loopinfo_sym = pyju_symbol("loopinfo");
    pyju_pure_sym = pyju_symbol("pure");
    pyju_meta_sym = pyju_symbol("meta");
    pyju_list_sym = pyju_symbol("list");
    pyju_unused_sym = pyju_symbol("#unused#");
    pyju_slot_sym = pyju_symbol("slot");
    pyju_static_parameter_sym = pyju_symbol("static_parameter");
    pyju_inline_sym = pyju_symbol("inline");
    pyju_noinline_sym = pyju_symbol("noinline");
    pyju_polly_sym = pyju_symbol("polly");
    pyju_propagate_inbounds_sym = pyju_symbol("propagate_inbounds");
    pyju_aggressive_constprop_sym = pyju_symbol("aggressive_constprop");
    pyju_no_constprop_sym = pyju_symbol("no_constprop");
    pyju_purity_sym = pyju_symbol("purity");
    pyju_isdefined_sym = pyju_symbol("isdefined");
    pyju_nospecialize_sym = pyju_symbol("nospecialize");
    pyju_specialize_sym = pyju_symbol("specialize");
    pyju_optlevel_sym = pyju_symbol("optlevel");
    pyju_compile_sym = pyju_symbol("compile");
    pyju_force_compile_sym = pyju_symbol("force_compile");
    pyju_infer_sym = pyju_symbol("infer");
    pyju_max_methods_sym = pyju_symbol("max_methods");
    pyju_macrocall_sym = pyju_symbol("macrocall");
    pyju_escape_sym = pyju_symbol("escape");
    pyju_hygienicscope_sym = pyju_symbol("hygienic-scope");
    pyju_gc_preserve_begin_sym = pyju_symbol("gc_preserve_begin");
    pyju_gc_preserve_end_sym = pyju_symbol("gc_preserve_end");
    pyju_generated_sym = pyju_symbol("generated");
    pyju_generated_only_sym = pyju_symbol("generated_only");
    pyju_throw_undef_if_not_sym = pyju_symbol("throw_undef_if_not");
    pyju_getfield_undefref_sym = pyju_symbol("##getfield##");
    pyju_do_sym = pyju_symbol("do");
    pyju_coverageeffect_sym = pyju_symbol("code_coverage_effect");
    pyju_aliasscope_sym = pyju_symbol("aliasscope");
    pyju_popaliasscope_sym = pyju_symbol("popaliasscope");
    pyju_thismodule_sym = pyju_symbol("thismodule");
    pyju_block_sym = pyju_symbol("block");
    pyju_atom_sym = pyju_symbol("atom");
    pyju_statement_sym = pyju_symbol("statement");
    pyju_all_sym = pyju_symbol("all");
    pyju_atomic_sym = pyju_symbol("atomic");
    pyju_not_atomic_sym = pyju_symbol("not_atomic");
    pyju_unordered_sym = pyju_symbol("unordered");
    pyju_monotonic_sym = pyju_symbol("monotonic");
    pyju_acquire_sym = pyju_symbol("acquire");
    pyju_release_sym = pyju_symbol("release");
    pyju_acquire_release_sym = pyju_symbol("acquire_release");
    pyju_sequentially_consistent_sym = pyju_symbol("sequentially_consistent");
}

#ifdef __cplusplus
}
#endif
