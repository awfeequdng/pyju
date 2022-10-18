
/*
  Symbol table
*/

#include <cstdint>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#include "support/hashing.h"

#ifdef __cplusplus
extern "C" {
#endif

static _Atomic(PyjuSym_t*) symtab = NULL;

#define MAX_SYM_LEN ((size_t)INTPTR_MAX - sizeof(PyjuTaggedValue_t) - sizeof(PyjuSym_t) - 1)

static uintptr_t hash_symbol(const char *str, size_t len) PYJU_NOTSAFEPOINT {
    uintptr_t oid = memhash(str, len) ^ ~(uintptr_t)0/3*2;
    // compute the same hash value as v1.6 and earlier, which used `hash_uint(3h - objectid(sym))`
    return inthash(-oid);
}

static size_t symbol_nbytes(size_t len) PYJU_NOTSAFEPOINT
{
    return (sizeof(PyjuSym_t) + len + 1 + 7) & -8;
}

static PyjuSym_t *mk_symbol(const char *str, size_t len)
{
    PyjuSym_t *sym;
    size_t nb = symbol_nbytes(len);
    assert(pyju_symbol_type && "not initialized");

    PyjuTaggedValue_t *tag = (PyjuTaggedValue_t*)pyju_gc_perm_alloc_nolock(nb, 0, sizeof(void*), 0);
    sym = (PyjuSym_t*)(pyju_valueof(tag));
    // set to old marked so that we won't look at it in the GC or write barrier.
    tag->header = ((uintptr_t)pyju_symbol_type) | GC_OLD_MARKED;
    pyju_atomic_store_relaxed(&sym->left, nullptr);
    pyju_atomic_store_relaxed(&sym->right, nullptr);
    sym->hash = hash_symbol(str, len);
    memcpy(pyju_symbol_name(sym), str, len);
    pyju_symbol_name(sym)[len] = 0;
    return sym;
}


static PyjuSym_t *symtab_lookup(_Atomic(PyjuSym_t*) *ptree, const char *str, size_t len, _Atomic(PyjuSym_t*) **slot) PYJU_NOTSAFEPOINT
{
    PyjuSym_t *node = pyju_atomic_load_relaxed(ptree); // consume
    uintptr_t h = hash_symbol(str, len);

    // Tree nodes sorted by major key of (int(hash)) and minor key of (str).
    while (node != NULL) {
        intptr_t x = (intptr_t)(h - node->hash);
        if (x == 0) {
            x = strncmp(str, pyju_symbol_name(node), len);
            if (x == 0 && pyju_symbol_name(node)[len] == 0) {
                if (slot != NULL)
                    *slot = ptree;
                return node;
            }
        }
        if (x < 0)
            ptree = &node->left;
        else
            ptree = &node->right;
        node = pyju_atomic_load_relaxed(ptree); // consume
    }
    if (slot != NULL)
        *slot = ptree;
    return node;
}


PyjuSym_t *_pyju_symbol(const char *str, size_t len) PYJU_NOTSAFEPOINT // (or throw)
{
#ifndef __clang_gcanalyzer__
    // Hide the error throwing from the analyser since there isn't a way to express
    // "safepoint only when throwing error" currently.
    if (len > MAX_SYM_LEN)
        // pyju_exceptionf(pyju_argumenterror_type, "Symbol name too long");
        abort();
#endif
    assert(!memchr(str, 0, len));
    _Atomic(PyjuSym_t*) *slot;
    PyjuSym_t *node = symtab_lookup(&symtab, str, len, &slot);
    if (node == NULL) {
        uv_mutex_lock(&gc_perm_lock);
        // Someone might have updated it, check and look up again
        if (pyju_atomic_load_relaxed(slot) != NULL && (node = symtab_lookup(slot, str, len, &slot))) {
            uv_mutex_unlock(&gc_perm_lock);
            return node;
        }
        node = mk_symbol(str, len);
        pyju_atomic_store_release(slot, node);
        uv_mutex_unlock(&gc_perm_lock);
    }
    return node;
}

PYJU_DLLEXPORT PyjuSym_t *pyju_symbol(const char *str) PYJU_NOTSAFEPOINT // (or throw)
{
    return _pyju_symbol(str, strlen(str));
}

PYJU_DLLEXPORT PyjuSym_t *pyju_symbol_lookup(const char *str) PYJU_NOTSAFEPOINT
{
    return symtab_lookup(&symtab, str, strlen(str), NULL);
}

PYJU_DLLEXPORT PyjuSym_t *pyju_symbol_n(const char *str, size_t len)
{
    if (memchr(str, 0, len))
        // pyju_exceptionf(pyju_argumenterror_type, "Symbol name may not contain \\0");
        assert(0 && "Symbol name may not contain \\0");
    return _pyju_symbol(str, len);
}

PYJU_DLLEXPORT PyjuSym_t *pyju_get_root_symbol(void)
{
    return pyju_atomic_load_relaxed(&symtab);
}

static _Atomic(uint32_t) gs_ctr = 0;  // TODO: per-module?
uint32_t pyju_get_gs_ctr(void) { return pyju_atomic_load_relaxed(&gs_ctr); }
void pyju_set_gs_ctr(uint32_t ctr) { pyju_atomic_store_relaxed(&gs_ctr, ctr); }


PYJU_DLLEXPORT PyjuSym_t *pyju_gensym(void)
{
    char name[16];
    char *n;
    uint32_t ctr = pyju_atomic_fetch_add(&gs_ctr, 1);
    n = uint2str(&name[2], sizeof(name)-2, ctr, 10);
    *(--n) = '#'; *(--n) = '#';
    return pyju_symbol(n);
}

PYJU_DLLEXPORT PyjuSym_t *pyju_tagged_gensym(const char *str, size_t len)
{
    if (len == (size_t)-1) {
        len = strlen(str);
    }
    else if (memchr(str, 0, len)) {
        // pyju_exceptionf(pyju_argumenterror_type, "Symbol name may not contain \\0");
        assert(0 && "Symbol name may not contain \\0");
    }
    char gs_name[14];
    size_t alloc_len = sizeof(gs_name) + len + 3;
    if (len > MAX_SYM_LEN || alloc_len > MAX_SYM_LEN)
        // pyju_exceptionf(pyju_argumenterror_type, "Symbol name too long");
        assert(0 && "Symbol name too long");
    char *name = (char*)(len >= 256 ? malloc_s(alloc_len) : alloca(alloc_len));
    char *n;
    name[0] = '#';
    name[1] = '#';
    name[2 + len] = '#';
    memcpy(name + 2, str, len);
    uint32_t ctr = pyju_atomic_fetch_add(&gs_ctr, 1);
    n = uint2str(gs_name, sizeof(gs_name), ctr, 10);
    memcpy(name + 3 + len, n, sizeof(gs_name) - (n - gs_name));
    PyjuSym_t *sym = _pyju_symbol(name, alloc_len - (n - gs_name)- 1);
    if (len >= 256)
        free(name);
    return sym;
}

#ifdef __cplusplus
}
#endif
