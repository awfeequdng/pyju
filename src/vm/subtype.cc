
#include <stdlib.h>
#include <string.h>


#include "pyju_object.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT int pyju_subtype(PyjuValue_t *x, PyjuValue_t *y)
{
    printf("not impl: pyju_subtype\n");
    return 0;
}

PYJU_DLLEXPORT int pyju_types_equal(PyjuValue_t *a, PyjuValue_t *b)
{
    printf("not impl: pyju_types_equal\n");
    return 0;
}

// returns true if the intersection of `t` and `Type` is non-empty and not a kind
// this is sufficient to determine if `isa(x, T)` can instead simply check for `typeof(x) <: T`
int pyju_has_intersect_type_not_kind(PyjuValue_t *t)
{
    t = pyju_unwrap_unionall(t);
    if (t == (PyjuValue_t*)pyju_any_type)
        return 1;
    if (pyju_is_uniontype(t)) {
        return pyju_has_intersect_type_not_kind(((PyjuUnionType_t*)t)->a) ||
               pyju_has_intersect_type_not_kind(((PyjuUnionType_t*)t)->b);
    }
    if (pyju_is_typevar(t)) {
        return pyju_has_intersect_type_not_kind(((PyjuTVar_t*)t)->ub);
    }
    if (pyju_is_datatype(t)) {
        if (((PyjuDataType_t*)t)->name == pyju_type_typename)
            return 1;
    }
    return 0;
}

PYJU_DLLEXPORT int pyju_isa(PyjuValue_t *x, PyjuValue_t *t)
{
    if (pyju_typeis(x,t) || t == (PyjuValue_t*)pyju_any_type)
        return 1;
    if (pyju_is_type(x)) {
        if (t == (PyjuValue_t*)pyju_type_type)
            return 1;
        if (!pyju_has_free_typevars(x)) {
            if (pyju_is_concrete_type(t))
                return 0;
            if (pyju_is_type_type(t))
                return pyju_types_equal(x, pyju_tparam0(t));
            PyjuValue_t *t2 = pyju_unwrap_unionall(t);
            if (pyju_is_datatype(t2)) {
                if (((PyjuDataType_t*)t2)->name == pyju_type_typename) {
                    PyjuValue_t *tp = pyju_tparam0(t2);
                    if (pyju_is_typevar(tp)) {
                        if (((PyjuTVar_t*)tp)->lb == pyju_bottom_type) {
                            while (pyju_is_typevar(tp))
                                tp = ((PyjuTVar_t*)tp)->ub;
                            if (!pyju_has_free_typevars(tp))
                                return pyju_subtype(x, tp);
                        }
                        else if (((PyjuTVar_t*)tp)->ub == (PyjuValue_t*)pyju_any_type) {
                            while (pyju_is_typevar(tp))
                                tp = ((PyjuTVar_t*)tp)->lb;
                            if (!pyju_has_free_typevars(tp))
                                return pyju_subtype(tp, x);
                        }
                    }
                }
                else {
                    return 0;
                }
            }
            if (pyju_subtype(pyju_typeof(x), t))
                return 1;
            if (pyju_has_intersect_type_not_kind(t2)) {
                PYJU_GC_PUSH1(&x);
                x = (PyjuValue_t*)pyju_wrap_Type(x);  // TODO jb/subtype avoid pyju_wrap_Type
                int ans = pyju_subtype(x, t);
                PYJU_GC_POP();
                return ans;
            }
            return 0;
        }
    }
    if (pyju_is_concrete_type(t) && pyju_type_equality_is_identity(pyju_typeof(x), t))
        return 0;
    return pyju_subtype(pyju_typeof(x), t);
}

#ifdef __cplusplus
}
#endif
