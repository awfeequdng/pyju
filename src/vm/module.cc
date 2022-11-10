// This file is a part of Julia. License is MIT: https://julialang.org/license

/*
  modules and top-level bindings
*/
#include "pyju.h"
#include "pyju_atomics.h"
#include "pyju_internal.h"
#include "pyju_assert.h"
#include "pyju_threads.h"
#include "support/ptrhash.h"

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT PyjuModule_t*pyju_new_module_(PyjuSym_t *name, uint8_t default_names)
{
    PyjuTask_t *ct = pyju_current_task;
    const PyjuUuid_t uuid_zero = {0, 0};
    PyjuModule_t *m = (PyjuModule_t*)pyju_gc_alloc(ct->ptls, sizeof(PyjuModule_t),
                                               pyju_module_type);
    assert(pyju_is_symbol(name));
    m->name = name;
    m->parent = NULL;
    m->istopmod = 0;
    m->uuid = uuid_zero;
    static unsigned int mcounter; // simple counter backup, in case hrtime is not incrementing
    m->build_id = pyju_hrtime() + (++mcounter);
    if (!m->build_id)
        m->build_id++; // build id 0 is invalid
    m->primary_world = 0;
    m->counter = 1;
    m->nospecialize = 0;
    m->optlevel = -1;
    m->compile = -1;
    m->infer = -1;
    m->max_methods = -1;
    PYJU_MUTEX_INIT(&m->lock);
    htable_new(&m->bindings, 0);
    arraylist_new(&m->usings, 0);
    PYJU_GC_PUSH1(&m);
    if (pyju_core_module && default_names) {
        pyju_module_using(m, pyju_core_module);
    }
    // export own name, so "using Foo" makes "Foo" itself visible
    if (default_names) {
        pyju_set_const(m, name, (PyjuValue_t*)m);
    }
    pyju_module_export(m, name);
    PYJU_GC_POP();
    return m;
}

PYJU_DLLEXPORT PyjuModule_t *pyju_new_module(PyjuSym_t *name)
{
    return pyju_new_module_(name, 1);
}

uint32_t pyju_module_next_counter(PyjuModule_t *m)
{
    return pyju_atomic_fetch_add(&m->counter, 1);
}

PYJU_DLLEXPORT PyjuValue_t *pyju_f_new_module(PyjuSym_t *name, uint8_t std_imports, uint8_t default_names)
{
    // TODO: should we prohibit this during incremental compilation?
    PyjuModule_t *m = pyju_new_module_(name, default_names);
    PYJU_GC_PUSH1(&m);
    m->parent = pyju_main_module; // TODO: this is a lie
    pyju_gc_wb(m, m->parent);
    if (std_imports)
        pyju_add_standard_imports(m);
    PYJU_GC_POP();
    // TODO: should we somehow try to gc-root this correctly?
    return (PyjuValue_t*)m;
}

PYJU_DLLEXPORT void pyju_set_module_nospecialize(PyjuModule_t *self, int on)
{
    self->nospecialize = (on ? -1 : 0);
}

PYJU_DLLEXPORT void pyju_set_module_optlevel(PyjuModule_t *self, int lvl)
{
    self->optlevel = lvl;
}

PYJU_DLLEXPORT int pyju_get_module_optlevel(PyjuModule_t *m)
{
    int lvl = m->optlevel;
    while (lvl == -1 && m->parent != m && m != pyju_base_module) {
        m = m->parent;
        lvl = m->optlevel;
    }
    return lvl;
}

PYJU_DLLEXPORT void pyju_set_module_compile(PyjuModule_t *self, int value)
{
    self->compile = value;
}

PYJU_DLLEXPORT int pyju_get_module_compile(PyjuModule_t *m)
{
    int value = m->compile;
    while (value == -1 && m->parent != m && m != pyju_base_module) {
        m = m->parent;
        value = m->compile;
    }
    return value;
}

PYJU_DLLEXPORT void pyju_set_module_infer(PyjuModule_t *self, int value)
{
    self->infer = value;
    // no reason to specialize if inference is off
    if (!value)
        pyju_set_module_nospecialize(self, 1);
}

PYJU_DLLEXPORT int pyju_get_module_infer(PyjuModule_t *m)
{
    int value = m->infer;
    while (value == -1 && m->parent != m && m != pyju_base_module) {
        m = m->parent;
        value = m->infer;
    }
    return value;
}

PYJU_DLLEXPORT void pyju_set_module_max_methods(PyjuModule_t *self, int value)
{
    self->max_methods = value;
}

PYJU_DLLEXPORT int pyju_get_module_max_methods(PyjuModule_t *m)
{
    int value = m->max_methods;
    while (value == -1 && m->parent != m && m != pyju_base_module) {
        m = m->parent;
        value = m->max_methods;
    }
    return value;
}

PYJU_DLLEXPORT void pyju_set_istopmod(PyjuModule_t *self, uint8_t isprimary)
{
    self->istopmod = 1;
    if (isprimary) {
        pyju_top_module = self;
    }
}

PYJU_DLLEXPORT uint8_t pyju_istopmod(PyjuModule_t *mod)
{
    return mod->istopmod;
}

static PyjuBinding_t *new_binding(PyjuSym_t *name)
{
    PyjuTask_t *ct = pyju_current_task;
    assert(pyju_is_symbol(name));
    PyjuBinding_t *b = (PyjuBinding_t*)pyju_gc_alloc_buf(ct->ptls, sizeof(PyjuBinding_t));
    b->name = name;
    b->value = NULL;
    b->owner = NULL;
    b->ty = NULL;
    b->globalref = NULL;
    b->constp = 0;
    b->exportp = 0;
    b->imported = 0;
    b->deprecated = 0;
    return b;
}

// get binding for assignment
PYJU_DLLEXPORT PyjuBinding_t *pyju_get_binding_wr(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var, int error)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t **bp = (PyjuBinding_t**)ptrhash_bp(&m->bindings, var);
    PyjuBinding_t *b = *bp;

    if (b != HT_NOTFOUND) {
        if (b->owner != m) {
            if (b->owner == NULL) {
                b->owner = m;
            }
            else if (error) {
                PYJU_UNLOCK(&m->lock);
                pyju_errorf("cannot assign a value to variable %s.%s from module %s",
                          pyju_symbol_name(b->owner->name), pyju_symbol_name(var), pyju_symbol_name(m->name));
            }
        }
    }
    else {
        b = new_binding(var);
        b->owner = m;
        *bp = b;
        PYJU_GC_PROMISE_ROOTED(b);
        pyju_gc_wb_buf(m, b, sizeof(PyjuBinding_t));
    }

    PYJU_UNLOCK(&m->lock);
    return b;
}

PYJU_DLLEXPORT void pyju_set_const(PyjuModule_t *m PYJU_ROOTING_ARGUMENT, PyjuSym_t *var, PyjuValue_t *val PYJU_ROOTED_ARGUMENT)
{
    PyjuBinding_t *bp = pyju_get_binding_wr(m, var, 1);
    if (bp->value == NULL) {
        uint8_t constp = 0;
        // if (pyju_atomic_cmpswap(&bp->constp, &constp, 1)) {
        if (constp = bp->constp, bp->constp = 1, constp == 0) {
            PyjuValue_t *old = NULL;
            if (pyju_atomic_cmpswap(&bp->value, &old, val)) {
                pyju_gc_wb_binding(bp, val);
                return;
            }
        }
	    PyjuValue_t *old_ty = NULL;
        pyju_atomic_cmpswap_relaxed(&bp->ty, &old_ty, (PyjuValue_t*)pyju_any_type);
    }
    pyju_errorf("invalid redefinition of constant %s",
              pyju_symbol_name(bp->name));
}

// Hash tables don't generically root their contents, but they do for bindings.
// Express this to the analyzer.
// NOTE: Must hold m->lock while calling these.
#ifdef __clang_gcanalyzer__
PyjuBinding_t *_pyju_get_module_binding(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var) PYJU_NOTSAFEPOINT;
PyjuBinding_t **_pyju_get_module_binding_bp(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var) PYJU_NOTSAFEPOINT;
#else
static inline PyjuBinding_t *_pyju_get_module_binding(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var) PYJU_NOTSAFEPOINT
{
    return (PyjuBinding_t*)ptrhash_get(&m->bindings, var);
}
static inline PyjuBinding_t **_pyju_get_module_binding_bp(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var) PYJU_NOTSAFEPOINT
{
    return (PyjuBinding_t**)ptrhash_bp(&m->bindings, var);
}
#endif

// return module of binding
PYJU_DLLEXPORT PyjuModule_t *jl_get_module_of_binding(PyjuModule_t *m, PyjuSym_t *var)
{
    PyjuBinding_t *b = pyju_get_binding(m, var);
    if (b == NULL)
        return NULL;
    return b->owner;
}


// get binding for adding a method
// like jl_get_binding_wr, but has different error paths
PYJU_DLLEXPORT PyjuBinding_t *pyju_get_binding_for_method_def(PyjuModule_t *m, PyjuSym_t *var)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t **bp = _pyju_get_module_binding_bp(m, var);
    PyjuBinding_t *b = *bp;

    if (b != HT_NOTFOUND) {
        if (b->owner != m) {
            if (b->owner == NULL) {
                b->owner = m;
            }
            else {
                PYJU_UNLOCK(&m->lock);
                PyjuBinding_t *b2 = pyju_get_binding(b->owner, b->name);
                if (b2 == NULL || b2->value == NULL)
                    pyju_errorf("invalid method definition: imported function %s.%s does not exist",
                              pyju_symbol_name(b->owner->name), pyju_symbol_name(b->name));
                // TODO: we might want to require explicitly importing types to add constructors
                if (!b->imported && !pyju_is_type(b2->value)) {
                    pyju_errorf("error in method definition: function %s.%s must be explicitly imported to be extended",
                              pyju_symbol_name(b->owner->name), pyju_symbol_name(b->name));
                }
                return b2;
            }
        }
    }
    else {
        b = new_binding(var);
        b->owner = m;
        *bp = b;
        pyju_gc_wb_buf(m, b, sizeof(PyjuBinding_t));
    }

    PYJU_UNLOCK(&m->lock);
    return b;
}

static void module_import_(PyjuModule_t *to, PyjuModule_t *from, PyjuSym_t *s, PyjuSym_t *asname,
                           int explici);

typedef struct _modstack_t {
    PyjuModule_t *m;
    PyjuSym_t *var;
    struct _modstack_t *prev;
} modstack_t;

static PyjuBinding_t *pyju_get_binding_(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var, modstack_t *st);

static inline PyjuModule_t *module_usings_getidx(PyjuModule_t *m PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT;

#ifndef __clang_gcanalyzer__
// The analyzer doesn't like looking through the arraylist, so just model the
// access for it using this function
static inline PyjuModule_t *module_usings_getidx(PyjuModule_t *m PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT {
    return (PyjuModule_t*)m->usings.items[i];
}
#endif


// find a binding from a module's `usings` list
// called while holding m->lock
static PyjuBinding_t *using_resolve_binding(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var, modstack_t *st, int warn)
{
    PyjuBinding_t *b = NULL;
    PyjuModule_t *owner = NULL;
    for(int i=(int)m->usings.len-1; i >= 0; --i) {
        PyjuModule_t *imp = module_usings_getidx(m, i);
        // TODO: make sure this can't deadlock
        PYJU_LOCK(&imp->lock);
        PyjuBinding_t *tempb = _pyju_get_module_binding(imp, var);
        PYJU_UNLOCK(&imp->lock);
        if (tempb != HT_NOTFOUND && tempb->exportp) {
            tempb = pyju_get_binding_(imp, var, st);
            if (tempb == NULL || tempb->owner == NULL)
                // couldn't resolve; try next using (see issue #6105)
                continue;
            if (owner != NULL && tempb->owner != b->owner &&
                !tempb->deprecated && !b->deprecated &&
                !(tempb->constp && tempb->value && b->constp && b->value == tempb->value)) {
                if (warn) {
                    PYJU_UNLOCK(&m->lock);
                    pyju_printf(PYJU_STDERR,
                              "WARNING: both %s and %s export \"%s\"; uses of it in module %s must be qualified\n",
                              pyju_symbol_name(owner->name),
                              pyju_symbol_name(imp->name), pyju_symbol_name(var),
                              pyju_symbol_name(m->name));
                    // mark this binding resolved, to avoid repeating the warning
                    (void)pyju_get_binding_wr(m, var, 0);
                    PYJU_LOCK(&m->lock);
                }
                return NULL;
            }
            if (owner == NULL || !tempb->deprecated) {
                owner = imp;
                b = tempb;
            }
        }
    }
    return b;
}

// get binding for reading. might return NULL for unbound.
static PyjuBinding_t *pyju_get_binding_(PyjuModule_t *m, PyjuSym_t *var, modstack_t *st)
{
    modstack_t top = { m, var, st };
    modstack_t *tmp = st;
    while (tmp != NULL) {
        if (tmp->m == m && tmp->var == var) {
            // 是否存在循环引用
            // import cycle without finding actual location
            return NULL;
        }
        tmp = tmp->prev;
    }
    PYJU_LOCK(&m->lock);
    PyjuBinding_t *b = _pyju_get_module_binding(m, var);
    if (b == HT_NOTFOUND || b->owner == NULL) {
        b = using_resolve_binding(m, var, &top, 1);
        PYJU_UNLOCK(&m->lock);
        if (b != NULL) {
            // do a full import to prevent the result of this lookup
            // from changing, for example if this var is assigned to
            // later.
            module_import_(m, b->owner, var, var, 0);
            return b;
        }
        return NULL;
    }
    PYJU_UNLOCK(&m->lock);
    if (b->owner != m || b->name != var)
        return pyju_get_binding_(b->owner, b->name, &top);
    return b;
}

PYJU_DLLEXPORT PyjuBinding_t *pyju_get_binding(PyjuModule_t *m, PyjuSym_t *var)
{
    return pyju_get_binding_(m, var, NULL);
}

static int eq_bindings(PyjuBinding_t *a, PyjuBinding_t *b)
{
    if (a==b) return 1;
    if (a->name == b->name && a->owner == b->owner) return 1;
    // todo: 会不会name不同，而value相同？？
    if (a->constp && a->value && b->constp && b->value == a->value) return 1;
    return 0;
}

// does module m explicitly import s?
PYJU_DLLEXPORT int pyju_is_imported(PyjuModule_t *m, PyjuSym_t *s)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t *b = (PyjuBinding_t*)ptrhash_get(&m->bindings, s);
    PYJU_UNLOCK(&m->lock);
    return (b != HT_NOTFOUND && b->imported);
}

// NOTE: we use explici since explicit is a C++ keyword
static void module_import_(PyjuModule_t *to, PyjuModule_t *from, PyjuSym_t *s, PyjuSym_t *asname, int explici)
{
    PyjuBinding_t *b = pyju_get_binding(from, s);
    if (b == NULL) {
        pyju_printf(PYJU_STDERR,
                  "WARNING: could not import %s.%s into %s\n",
                  pyju_symbol_name(from->name), pyju_symbol_name(s),
                  pyju_symbol_name(to->name));
    }
    else {
        if (b->deprecated) {
            if (b->value == pyju_nothing) {
                return;
            }
            else if (to != pyju_main_module && to != pyju_base_module &&
                     pyju_options.depwarn != PYJU_OPTIONS_DEPWARN_OFF) {
                /* with #22763, external packages wanting to replace
                   deprecated Base bindings should simply export the new
                   binding */
                pyju_printf(PYJU_STDERR,
                          "WARNING: importing deprecated binding %s.%s into %s.\n",
                          pyju_symbol_name(from->name), pyju_symbol_name(s),
                          pyju_symbol_name(to->name));
            }
        }

        PYJU_LOCK(&to->lock);
        PyjuBinding_t **bp = (PyjuBinding_t**)ptrhash_bp(&to->bindings, asname);
        PyjuBinding_t *bto = *bp;
        if (bto != HT_NOTFOUND) {
            if (bto == b) {
                // importing a binding on top of itself. harmless.
            }
            else if (bto->name != s) {
                PYJU_UNLOCK(&to->lock);
                pyju_printf(PYJU_STDERR,
                          "WARNING: ignoring conflicting import of %s.%s into %s\n",
                          pyju_symbol_name(from->name), pyju_symbol_name(s),
                          pyju_symbol_name(to->name));
                return;
            }
            else if (bto->owner == b->owner) {
                // already imported
                bto->imported = (explici!=0);
            }
            else if (bto->owner != to && bto->owner != NULL) {
                // already imported from somewhere else
                // 从其他的模块导入了asname，而不是从from Module导入的
                PyjuBinding_t *bval = pyju_get_binding(to, asname);
                if (bval->constp && bval->value && b->constp && b->value == bval->value) {
                    // 从from导入的s的值,和从其他模块导入的asname值相同
                    // equivalent binding
                    bto->imported = (explici!=0);
                    PYJU_UNLOCK(&to->lock);
                }
                else {
                    PYJU_UNLOCK(&to->lock);
                    pyju_printf(PYJU_STDERR,
                              "WARNING: ignoring conflicting import of %s.%s into %s\n",
                              pyju_symbol_name(from->name), pyju_symbol_name(s),
                              pyju_symbol_name(to->name));
                }
                return;
            }
            else if (bto->constp || bto->value) {
                // asname 就属于to Module，并且asname的值已经设置了
                // conflict with name owned by destination module
                assert(bto->owner == to);
                if (bto->constp && bto->value && b->constp && b->value == bto->value) {
                    // equivalent binding
                    // from模块中的s变量的值，和to模块中的asname值相同，就相当于已经导入了，不报错
                    PYJU_UNLOCK(&to->lock);
                }
                else {
                    PYJU_UNLOCK(&to->lock);
                    pyju_printf(PYJU_STDERR,
                              "WARNING: import of %s.%s into %s conflicts with an existing identifier; ignored.\n",
                              pyju_symbol_name(from->name), pyju_symbol_name(s),
                              pyju_symbol_name(to->name));
                }
                return;
            }
            else {
                // asname就属于to Module，并且asname的值还没有设置，此时使用from模块中的值
                bto->owner = b->owner;
                bto->imported = (explici!=0);
            }
        }
        else {
            PyjuBinding_t *nb = new_binding(b->name);
            nb->owner = b->owner;
            nb->imported = (explici!=0);
            nb->deprecated = b->deprecated;
            *bp = nb;
            pyju_gc_wb_buf(to, nb, sizeof(PyjuBinding_t));
        }
        PYJU_UNLOCK(&to->lock);
    }
}

PYJU_DLLEXPORT void pyju_module_import(PyjuModule_t *to, PyjuModule_t *from, PyjuSym_t *s)
{
    module_import_(to, from, s, s, 1);
}

PYJU_DLLEXPORT void pyju_module_import_as(PyjuModule_t *to, PyjuModule_t *from, PyjuSym_t *s, PyjuSym_t *asname)
{
    module_import_(to, from, s, asname, 1);
}

PYJU_DLLEXPORT void pyju_module_use(PyjuModule_t *to, PyjuModule_t *from, PyjuSym_t *s)
{
    module_import_(to, from, s, s, 0);
}

PYJU_DLLEXPORT void pyju_module_use_as(PyjuModule_t *to, PyjuModule_t *from, PyjuSym_t *s, PyjuSym_t *asname)
{
    module_import_(to, from, s, asname, 0);
}

PYJU_DLLEXPORT void pyju_module_using(PyjuModule_t *to, PyjuModule_t *from)
{
    if (to == from)
        return;
    PYJU_LOCK(&to->lock);
    for(size_t i=0; i < to->usings.len; i++) {
        if (from == to->usings.items[i]) {
            PYJU_UNLOCK(&to->lock);
            return;
        }
    }
    // TODO: make sure this can't deadlock
    PYJU_LOCK(&from->lock);
    // print a warning if something visible via this "using" conflicts with
    // an existing identifier. note that an identifier added later may still
    // silently override a "using" name. see issue #2054.
    void **table = from->bindings.table;
    for(size_t i=1; i < from->bindings.size; i+=2) {
        if (table[i] != HT_NOTFOUND) {
            PyjuBinding_t *b = (PyjuBinding_t*)table[i];
            if (b->exportp && (b->owner==from || b->imported)) {
                PyjuSym_t *var = (PyjuSym_t*)table[i-1];
                PyjuBinding_t **tobp = (PyjuBinding_t**)ptrhash_bp(&to->bindings, var);
                if (*tobp != HT_NOTFOUND && (*tobp)->owner != NULL &&
                    // don't warn for conflicts with the module name itself.
                    // see issue #4715
                    var != to->name &&
                    !eq_bindings(pyju_get_binding(to, var), b)) {
                    // TODO: not ideal to print this while holding module locks
                    pyju_printf(PYJU_STDERR,
                              "WARNING: using %s.%s in module %s conflicts with an existing identifier.\n",
                              pyju_symbol_name(from->name), pyju_symbol_name(var),
                              pyju_symbol_name(to->name));
                }
            }
        }
    }
    PYJU_UNLOCK(&from->lock);

    arraylist_push(&to->usings, from);
    pyju_gc_wb(to, from);
    PYJU_UNLOCK(&to->lock);
}

PYJU_DLLEXPORT void pyju_module_export(PyjuModule_t *from, PyjuSym_t *s)
{
    PYJU_LOCK(&from->lock);
    PyjuBinding_t **bp = (PyjuBinding_t**)ptrhash_bp(&from->bindings, s);
    if (*bp == HT_NOTFOUND) {
        PyjuBinding_t *b = new_binding(s);
        // don't yet know who the owner is
        // todo: 在from模块的bindings哈希表创建的，为什么不属于该模块？？
        b->owner = NULL;
        *bp = b;
        pyju_gc_wb_buf(from, b, sizeof(PyjuBinding_t));
    }
    assert(*bp != HT_NOTFOUND);
    (*bp)->exportp = 1;
    PYJU_UNLOCK(&from->lock);
}

PYJU_DLLEXPORT int pyju_boundp(PyjuModule_t *m, PyjuSym_t *var)
{
    PyjuBinding_t *b = pyju_get_binding(m, var);
    return b && (b->value != NULL);
}

PYJU_DLLEXPORT int pyju_defines_or_exports_p(PyjuModule_t *m, PyjuSym_t *var)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t *b = (PyjuBinding_t*)ptrhash_get(&m->bindings, var);
    PYJU_UNLOCK(&m->lock);
    return b != HT_NOTFOUND && (b->exportp || b->owner==m);
}

PYJU_DLLEXPORT int pyju_module_exports_p(PyjuModule_t *m, PyjuSym_t *var)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t *b = _pyju_get_module_binding(m, var);
    PYJU_UNLOCK(&m->lock);
    return b != HT_NOTFOUND && b->exportp;
}

PYJU_DLLEXPORT int pyju_binding_resolved_p(PyjuModule_t *m, PyjuSym_t *var)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t *b = _pyju_get_module_binding(m, var);
    PYJU_UNLOCK(&m->lock);
    return b != HT_NOTFOUND && b->owner != NULL;
}

PYJU_DLLEXPORT PyjuBinding_t *pyju_get_module_binding(PyjuModule_t *m PYJU_PROPAGATES_ROOT, PyjuSym_t *var)
{
    PYJU_LOCK(&m->lock);
    PyjuBinding_t *b = _pyju_get_module_binding(m, var);
    PYJU_UNLOCK(&m->lock);
    return b == HT_NOTFOUND ? NULL : b;
}

static PyjuBinding_t *pyju_get_dep_message_binding(PyjuModule_t *m, PyjuBinding_t *deprecated_binding);

PYJU_DLLEXPORT PyjuValue_t *pyju_get_global(PyjuModule_t *m, PyjuSym_t *var)
{
    PyjuBinding_t *b = pyju_get_binding(m, var);
    if (b == NULL) return NULL;
    if (b->deprecated) pyju_binding_deprecation_warning(m, b);
    return b->value;
}

PYJU_DLLEXPORT void pyju_set_global(PyjuModule_t *m PYJU_ROOTING_ARGUMENT, PyjuSym_t *var, PyjuValue_t *val PYJU_ROOTED_ARGUMENT)
{
    PYJU_TYPECHK(pyju_set_global, module, (PyjuValue_t*)m);
    PYJU_TYPECHK(pyju_set_global, symbol, (PyjuValue_t*)var);
    PyjuBinding_t *bp = pyju_get_binding_wr(m, var, 1);
    pyju_checked_assignment(bp, val);
}


extern const char *pyju_filename;
extern int pyju_lineno;

static char const dep_message_prefix[] = "_dep_message_";

static PyjuBinding_t *pyju_get_dep_message_binding(PyjuModule_t *m, PyjuBinding_t *deprecated_binding)
{
    size_t prefix_len = strlen(dep_message_prefix);
    size_t name_len = strlen(pyju_symbol_name(deprecated_binding->name));
    char *dep_binding_name = (char*)alloca(prefix_len+name_len+1);
    memcpy(dep_binding_name, dep_message_prefix, prefix_len);
    memcpy(dep_binding_name + prefix_len, pyju_symbol_name(deprecated_binding->name), name_len);
    dep_binding_name[prefix_len+name_len] = '\0';
    return pyju_get_binding(m, pyju_symbol(dep_binding_name));
}

void pyju_binding_deprecation_warning(PyjuModule_t *m, PyjuBinding_t *b)
{
    // Only print a warning for deprecated == 1 (renamed).
    // For deprecated == 2 (moved to a package) the binding is to a function
    // that throws an error, so we don't want to print a warning too.
    if (b->deprecated == 1 && pyju_options.depwarn) {
        if (pyju_options.depwarn != PYJU_OPTIONS_DEPWARN_ERROR)
            pyju_printf(PYJU_STDERR, "WARNING: ");
        PyjuBinding_t *dep_message_binding = NULL;
        if (b->owner) {
            pyju_printf(PYJU_STDERR, "%s.%s is deprecated",
                      pyju_symbol_name(b->owner->name), pyju_symbol_name(b->name));
            dep_message_binding = pyju_get_dep_message_binding(b->owner, b);
        }
        else {
            pyju_printf(PYJU_STDERR, "%s is deprecated", pyju_symbol_name(b->name));
        }

        if (dep_message_binding && dep_message_binding->value) {
            if (pyju_isa(dep_message_binding->value, (PyjuValue_t*)pyju_string_type)) {
                pyju_uv_puts(PYJU_STDERR, pyju_string_data(dep_message_binding->value),
                    pyju_string_len(dep_message_binding->value));
            }
            else {
                pyju_static_show(PYJU_STDERR, dep_message_binding->value);
            }
        }
        else {
            PyjuValue_t *v = b->value;
            if (v) {
                if (pyju_is_type(v) || pyju_is_module(v)) {
                    pyju_printf(PYJU_STDERR, ", use ");
                    pyju_static_show(PYJU_STDERR, v);
                    pyju_printf(PYJU_STDERR, " instead.");
                }
                else {
                    // TODO: not impl
                    pyju_printf(PYJU_STDERR, "not impl pyju_gf_mtable\n");
                    // PyjuMethTable_t *mt = pyju_gf_mtable(v);
                    // if (mt != NULL && (mt->defs != jl_nothing ||
                    //                    jl_isa(v, (jl_value_t*)jl_builtin_type))) {
                    //     jl_printf(JL_STDERR, ", use ");
                    //     if (mt->module != jl_core_module) {
                    //         jl_static_show(JL_STDERR, (jl_value_t*)mt->module);
                    //         jl_printf(JL_STDERR, ".");
                    //     }
                    //     jl_printf(JL_STDERR, "%s", jl_symbol_name(mt->name));
                    //     jl_printf(JL_STDERR, " instead.");
                    // }
                }
            }
        }
        pyju_printf(PYJU_STDERR, "\n");

        if (pyju_options.depwarn != PYJU_OPTIONS_DEPWARN_ERROR) {
            if (pyju_lineno == 0) {
                pyju_printf(PYJU_STDERR, " in module %s\n", pyju_symbol_name(m->name));
            }
            else {
                pyju_printf(PYJU_STDERR, "  likely near %s:%d\n", pyju_filename, pyju_lineno);
            }
        }

        if (pyju_options.depwarn == PYJU_OPTIONS_DEPWARN_ERROR) {
            if (b->owner)
                pyju_errorf("deprecated binding: %s.%s",
                          pyju_symbol_name(b->owner->name),
                          pyju_symbol_name(b->name));
            else
                pyju_errorf("deprecated binding: %s", pyju_symbol_name(b->name));
        }
    }
}

PYJU_DLLEXPORT void pyju_checked_assignment(PyjuBinding_t *b, PyjuValue_t *rhs)
{
    PyjuValue_t *old_ty = NULL;
    if (!pyju_atomic_cmpswap_relaxed(&b->ty, &old_ty, (PyjuValue_t*)pyju_any_type) && !pyju_isa(rhs, old_ty)) {
        pyju_errorf("cannot assign an incompatible value to the global %s.",
                  pyju_symbol_name(b->name));
    }
    if (b->constp) {
        PyjuValue_t *old = NULL;
        if (pyju_atomic_cmpswap(&b->value, &old, rhs)) {
            pyju_gc_wb_binding(b, rhs);
            return;
        }
        if (pyju_egal(rhs, old))
            return;
        if (pyju_typeof(rhs) != pyju_typeof(old) || pyju_is_type(rhs) || pyju_is_module(rhs)) {
#ifndef __clang_gcanalyzer__
            pyju_errorf("invalid redefinition of constant %s",
                      pyju_symbol_name(b->name));
#endif
        }
        pyju_safe_printf("WARNING: redefinition of constant %s. This may fail, cause incorrect answers, or produce other errors.\n",
                       pyju_symbol_name(b->name));
    }
    pyju_atomic_store_relaxed(&b->value, rhs);
    pyju_gc_wb_binding(b, rhs);
}

#ifdef __cplusplus
}
#endif
