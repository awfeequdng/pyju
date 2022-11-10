
#include <stdlib.h>
#include <string.h>


#include "pyju.h"
#include "pyju_internal.h"
#include "pyju_assert.h"

#ifdef __cplusplus
extern "C" {
#endif


// stack of bits to keep track of which combination of Union components we are
// looking at (0 for Union.a, 1 for Union.b). forall_exists_subtype and
// exists_subtype loop over all combinations by updating a binary count in
// this structure.
// Union type decision points are discovered while the algorithm works.
// If a new Union decision is encountered, the `more` flag is set to tell
// the forall/exists loop to grow the stack.
// TODO: the stack probably needs to be artificially large because of some
// deeper problem (see #21191) and could be shrunk once that is fixed
typedef struct {
    int16_t depth;
    int16_t more;
    int16_t used;
    uint32_t stack[100];  // stack of bits represented as a bit vector
} pyju_unionstate_t;

typedef struct {
    int16_t depth;
    int16_t more;
    int16_t used;
    void *stack;
} pyju_saved_unionstate_t;

// Linked list storing the type variable environment. A new jl_varbinding_t
// is pushed for each UnionAll type we encounter. `lb` and `ub` are updated
// during the computation.
// Most of the complexity is due to the "diagonal rule", requiring us to
// identify which type vars range over only concrete types.
typedef struct pyju_varbinding_t {
    PyjuTVar_t *var;
    PyjuValue_t *lb;
    PyjuValue_t *ub;
    int8_t right;       // whether this variable came from the right side of `A <: B`
    int8_t occurs_inv;  // occurs in invariant position
    int8_t occurs_cov;  // # of occurrences in covariant position
    int8_t concrete;    // 1 if another variable has a constraint forcing this one to be concrete
    // constraintkind: in covariant position, we try three different ways to compute var ∩ type:
    // let ub = var.ub ∩ type
    // 0 - var.ub <: type ? var : ub
    // 1 - var.ub = ub; return var
    // 2 - either (var.ub = ub; return var), or return ub
    int8_t constraintkind;
    int8_t intvalued;      // must be integer-valued; i.e. occurs as N in Vararg{_,N}
    int8_t limited;
    int16_t depth0;         // # of invariant constructors nested around the UnionAll type for this var
    // when this variable's integer value is compared to that of another,
    // it equals `other + offset`. used by vararg length parameters.
    int16_t offset;
    // array of typevars that our bounds depend on, whose UnionAlls need to be
    // moved outside ours.
    PyjuArray_t *innervars;
    struct pyju_varbinding_t *prev;
} pyju_varbinding_t;

// subtype algorithm state
typedef struct pyju_stenv_t {
    // N.B.: varbindings are created on the stack and rooted there
    pyju_varbinding_t *vars;    // type variable environment
    pyju_unionstate_t Lunions;  // union state for unions on the left of A <: B
    pyju_unionstate_t Runions;  // union state for unions on the right
    // N.B.: envout is gc-rooted
    PyjuValue_t **envout;      // for passing caller the computed bounds of right-side variables
    int envsz;                // length of envout
    int envidx;               // current index in envout
    int invdepth;             // # of invariant constructors we're nested in on the left
    int Rinvdepth;            // # of invariant constructors we're nested in on the right
    int ignore_free;          // treat free vars as black boxes; used during intersection
    int intersection;         // true iff subtype is being called from intersection
    int emptiness_only;       // true iff intersection only needs to test for emptiness
    int triangular;           // when intersecting Ref{X} with Ref{<:Y}
} pyju_stenv_t;


// `env` is NULL if no typevar information is requested, or otherwise
// points to a rooted array of length `jl_subtype_env_size(y)`.
// This will be populated with the values of variables from unionall
// types at the outer level of `y`.
PYJU_DLLEXPORT int pyju_subtype_env(PyjuValue_t *x, PyjuValue_t *y, PyjuValue_t **env, int envsz)
{
    pyju_stenv_t e;
    if (y == (PyjuValue_t*)pyju_any_type || x == pyju_bottom_type)
        return 1;
    printf("not impl yet: %s\n", __FUNCTION__);
    return 0;
//     if (x == y ||
//         (pyju_typeof(x) == pyju_typeof(y) &&
//          (pyju_is_unionall(y) || pyju_is_uniontype(y)) &&
//          pyju_types_egal(x, y))) {
//         if (envsz != 0) { // quickly copy env from x
//             PyjuUnionAll_t *ua = (PyjuUnionAll_t*)x;
//             int i;
//             for (i = 0; i < envsz; i++) {
//                 assert(pyju_is_unionall(ua));
//                 env[i] = (PyjuValue_t*)ua->var;
//                 ua = (PyjuUnionAll_t*)ua->body;
//             }
//         }
//         return 1;
//     }
//     int obvious_subtype = 2;
//     if (pyju_obvious_subtype(x, y, &obvious_subtype)) {
// #ifdef NDEBUG
//         if (obvious_subtype == 0)
//             return obvious_subtype;
//         else if (envsz == 0)
//             return obvious_subtype;
// #endif
//     }
//     else {
//         obvious_subtype = 3;
//     }
//     init_stenv(&e, env, envsz);
//     int subtype = forall_exists_subtype(x, y, &e, 0);
//     assert(obvious_subtype == 3 || obvious_subtype == subtype || pyju_has_free_typevars(x) || pyju_has_free_typevars(y));
// #ifndef NDEBUG
//     if (obvious_subtype == 0 || (obvious_subtype == 1 && envsz == 0))
//         subtype = obvious_subtype; // this ensures that running in a debugger doesn't change the result
// #endif
//     return subtype;
}

static int subtype_in_env_(PyjuValue_t *x, PyjuValue_t *y, pyju_stenv_t *e, int invdepth, int Rinvdepth)
{
    printf("not impl yet: %s\n", __FUNCTION__);
    return 0;
    // pyju_stenv_t e2;
    // init_stenv(&e2, NULL, 0);
    // e2.vars = e->vars;
    // e2.intersection = e->intersection;
    // e2.ignore_free = e->ignore_free;
    // e2.invdepth = invdepth;
    // e2.Rinvdepth = Rinvdepth;
    // e2.envsz = e->envsz;
    // e2.envout = e->envout;
    // e2.envidx = e->envidx;
    // return forall_exists_subtype(x, y, &e2, 0);
}

static int subtype_in_env(PyjuValue_t *x, PyjuValue_t *y, pyju_stenv_t *e)
{
    return subtype_in_env_(x, y, e, e->invdepth, e->Rinvdepth);
}

static int subtype_bounds_in_env(PyjuValue_t *x, PyjuValue_t *y, pyju_stenv_t *e, int R, int d)
{
    return subtype_in_env_(x, y, e, R ? e->invdepth : d, R ? d : e->Rinvdepth);
}

PYJU_DLLEXPORT int pyju_subtype(PyjuValue_t *x, PyjuValue_t *y)
{
    return pyju_subtype_env(x, y, NULL, 0);
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
