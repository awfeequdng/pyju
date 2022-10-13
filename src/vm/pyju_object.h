#pragma once
#include <bits/types/sig_atomic_t.h>
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include "support/dtypes.h"
#include "support/htable.h"
#include "support/arraylist.h"
#include "pyju_atomics.h"
#include "pyju_threads.h"
#include "pyju_assert.h"



// Define the largest size (bytes) of a properly aligned object that the
// processor family and compiler typically supports without a lock
// (assumed to be at least a pointer size). Since C is bad at handling 16-byte
// types, we currently use 8 here as the default.
#define MAX_ATOMIC_SIZE 8
#define MAX_POINTERATOMIC_SIZE 8

#ifdef _P64
#define NWORDS(sz) (((sz)+7)>>3)
#else
#define NWORDS(sz) (((sz)+3)>>2)
#endif

#if defined(__GNUC__)
#  define PYJU_NORETURN __attribute__ ((noreturn))
#  define PYJU_CONST_FUNC __attribute__((const))
#  define PYJU_USED_FUNC __attribute__((used))
#else
#  define PYJU_NORETURN
#  define PYJU_CONST_FUNC
#  define PYJU_USED_FUNC
#endif

#define container_of(ptr, type, member) \
    ((type *) ((char *)(ptr) - offsetof(type, member)))


#ifdef __cplusplus
extern "C" {
#endif

struct PyjuValue_t;

// the following macro is
// used to indicate which types below are subtypes of PyjuValue_t
#define PYJU_DATA_TYPE PyjuValue_t __pyju_value_;

struct PyjuTlsStates_t;
typedef PyjuTlsStates_t * PyjuPtls_t;

struct PyjuTaggedValueBits_t {
    uintptr_t gc:2;
};

struct PyjuTaggedValue_t {
    union {
        uintptr_t header;
        PyjuTaggedValue_t *next;
        PyjuValue_t *type; // 16-byte aligned
        PyjuTaggedValueBits_t bits;
    };
};

struct PyjuValue_t {
    PyjuTaggedValue_t tag;
};

#define pyju_astaggedvalue(v)                                             \
    ((PyjuTaggedValue_t*)v)

#define pyju_valueof(v)                                                 \
    ((PyjuValue_t*)v)

#define pyju_typeof(v)                                                    \
    ((PyjuValue_t*)(pyju_astaggedvalue(v)->header & ~(uintptr_t)15))

static inline void pyju_set_typeof(void *v, void *t)
{
    // Do not call this on a value that is already initialized.
    PyjuTaggedValue_t *tag = pyju_astaggedvalue(v);
    pyju_atomic_store_relaxed((_Atomic(PyjuValue_t*)*)&tag->type, (PyjuValue_t*)t);
}
#define pyju_typeis(v, t) (pyju_typeof(v) == (PyjuValue*)(t))

// Symbols are interned strings (hash-consed) stored as an invasive binary tree.
// The string data is nul-terminated and hangs off the end of the struct.
struct PyjuSym_t {
    PYJU_DATA_TYPE
    _Atomic(struct PyjuSym_t*) left;
    _Atomic(struct PyjuSym_t*) right;
    uintptr_t hash;    // precomputed hash value
    // PYJU_ATTRIBUTE_ALIGN_PTRSIZE(char name[]);
};

// A numbered SSA value, for optimized code analysis and generation
// the `id` is a unique, small number
struct PyjuSsaValue_t {
    PYJU_DATA_TYPE
    ssize_t id;
};

// A SimpleVector is an immutable pointer array
// Data is stored at the end of this variable-length struct.
struct PyjuSvec_t {
    PYJU_DATA_TYPE
    size_t length;
    // pointer size aligned
    // PyjuValue_t *data[];
} ;

struct PujuArrayFlags_t {
    /*
      how - allocation style
      0 = data is inlined, or a foreign pointer we don't manage
      1 = julia-allocated buffer that needs to be marked
      2 = malloc-allocated pointer this array object manages
      3 = has a pointer to the object that owns the data
    */
    uint16_t how:2;
    uint16_t ndims:9;
    uint16_t pooled:1;
    uint16_t ptrarray:1; // representation is pointer array
    uint16_t hasptr:1; // representation has embedded pointers
    uint16_t isshared:1; // data is shared by multiple Arrays
    uint16_t isaligned:1; // data allocated with memalign
};

PYJU_EXTENSION struct PyjuArray_t {
    PYJU_DATA_TYPE
    void *data;
    size_t length;
    PujuArrayFlags_t flags;
    uint16_t elsize;  // element size including alignment (dim 1 memory stride)
    uint32_t offset;  // for 1-d only. does not need to get big.
    size_t nrows;
    union {
        // 1d
        size_t maxsize;
        // Nd
        size_t ncols;
    };
    // other dim sizes go here for ndims > 2

    // followed by alignment padding and inline data, or owner pointer
};

STATIC_INLINE int pyju_arrary_ndimwords(uint32_t ndims) {
    return (ndims < 3 ? 0 : ndims - 2);
}

struct PyjuDatatype_t;
typedef struct PyjuDatatype_t PyjuTupleType_t;

// TypeMap is an implicitly defined type
// that can consist of any of the following nodes:
//   typedef TypeMap Union{TypeMapLevel, TypeMapEntry, Nothing}
// it forms a roughly tree-shaped structure, consisting of nodes of TypeMapLevels
// which split the tree when possible, for example based on the key into the tuple type at `offs`
// when key is a leaftype, (but only when the tree has enough entries for this to be
// more efficient than storing them sorted linearly)
// otherwise the leaf entries are stored sorted, linearly
typedef PyjuValue_t PyjuTypeMap_t;

struct PyjuCodeInstance_t;

typedef PyjuValue_t *(PyjuCall_t)(PyjuValue_t*, PyjuValue_t**, uint32_t, PyjuCodeInstance_t*);
typedef PyjuCall_t *PyjuCallPtr_t;

typedef PyjuValue_t *(*PyjuFptrArgs_t)(PyjuValue_t*, PyjuValue_t**, uint32_t);

typedef PyjuValue_t *(*PyjuFptrSparam_t)(PyjuValue_t*, PyjuValue_t**, PyjuSvec_t*);

struct PyjuModule_t;

struct PyjuLineInfoNode_t {
    PyjuModule_t *module;
    PyjuValue_t *method;
    PyjuSym_t *file;
    int32_t line;
    int32_t inlined_at;
};

struct PyjuMethodInstance_t;

// the following mirrors `struct EffectsOverride` in `base/compiler/effects.jl`
union PyjuPurityOverrides_t {
    struct {
        uint8_t ipo_consistent          : 1;
        uint8_t ipo_effect_free         : 1;
        uint8_t ipo_nothrow             : 1;
        uint8_t ipo_terminates_globally : 1;
        // Weaker form of `terminates` that asserts
        // that any control flow syntactically in the method
        // is guaranteed to terminate, but does not make
        // assertions about any called functions.
        uint8_t ipo_terminates_locally  : 1;
        uint8_t ipo_notaskstate         : 1;
        uint8_t ipo_inaccessiblememonly : 1;
    } overrides;
    uint8_t bits;
};

struct PyjuCodeInfo_t {
    // ssavalue-indexed arrays of properties:
    PyjuArray_t *code;      // Any array of statements
    PyjuValue_t *codelocs;  // Int32 array of indices into the line table
    PyjuValue_t *ssavaluetypes; // types of ssa values (or count of them)
    PyjuArray_t *ssaflags; // flags associated with each statement:
        // 0 = inbounds
        // 1 = inline
        // 2 = noinline
        // 3 = <reserved> strict-ieee (strictfp)
        // 4 = effect-free (may be deleted if unused)
        // 5-6 = <unused>
        // 7 = has out-of-band info
    // miscellaneous data:
    PyjuValue_t *method_for_inference_limit_heuristics; // optional method used during inference
    PyjuValue_t *linetable; // Table of locations [TODO: make this volatile like slotnames]
    PyjuArray_t *slotnames; // names of local variables
    PyjuArray_t *slotflags; // local var bit flags
    PyjuValue_t *slottypes; // inferred types of slots
    PyjuValue_t *rettype;
    PyjuMethodInstance_t *parent; // context (optionally, if available, otherwise nothing)
    PyjuValue_t *edges; // forward edges to method instances that must be invalidated
    size_t min_world;
    size_t max_world;
    // various boolean properties:
    uint8_t inferred;
    uint16_t inlining_cost;
    uint8_t propagate_inbounds;
    uint8_t pure;
    // uint8 settings
    uint8_t constprop; // 0 = use heuristic; 1 = aggressive; 2 = none
    PyjuPurityOverrides_t purity;
};

struct PyjuMethod_t {
    PYJU_DATA_TYPE
    PyjuSym_t *name;    // for error report
    PyjuModule_t *module;
    PyjuSym_t *file;
    int32_t line;
    size_t primary_world;
    size_t deleted_world;

    // method's type signature. redundant with TypeMapEntry->specTypes
    PyjuValue_t *sig;

    // table of all pyju_method_instance_t specializations we have
    _Atomic(PyjuSvec_t*) specializations; // allocated as [hashable, ..., NULL, linear, ....]
    _Atomic(PyjuArray_t*) speckeyset; // index lookup by hash into specializations

    PyjuValue_t *slot_syms; // compacted list of slot names (String)
    PyjuValue_t *external_mt; // reference to the method table this method is part of, null if part of the internal table
    PyjuValue_t *source;  // original code template (pyju_code_info_t, but may be compressed), null for builtins
    _Atomic(PyjuMethodInstance_t *) unspecialized;  // unspecialized executable method instance, or null
    PyjuValue_t *generator;  // executable code-generating function if available
    PyjuArray_t *roots;  // pointers in generated code (shared to reduce memory), or null
    // Identify roots by module-of-origin. We only track the module for roots added during incremental compilation.
    // May be NULL if no external roots have been added, otherwise it's a Vector{UInt64}
    PyjuArray_t *root_blocks;   // RLE (build_id, offset) pairs (even/odd indexing)
    int32_t nroots_sysimg;     // # of roots stored in the system image
    PyjuSvec_t *ccallable; // svec(rettype, sig) if a ccallable entry point is requested for this

    // cache of specializations of this method for invoke(), i.e.
    // cases where this method was called even though it was not necessarily
    // the most specific for the argument types.
    _Atomic(PyjuTypeMap_t*) invokes;

    // A function that compares two specializations of this method, returning
    // `true` if the first signature is to be considered "smaller" than the
    // second for purposes of recursion analysis. Set to NULL to use
    // the default recusion relation.
    PyjuValue_t *recursion_relation;

    uint32_t nargs;
    uint32_t called;        // bit flags: whether each of the first 8 arguments is called
    uint32_t nospecialize;  // bit flags: which arguments should not be specialized
    uint32_t nkw;           // # of leading arguments that are actually keyword arguments
                            // of another method.
    uint8_t isva;
    uint8_t pure;
    uint8_t is_for_opaque_closure;
    // uint8 settings
    uint8_t constprop;     // 0x00 = use heuristic; 0x01 = aggressive; 0x02 = none

    // Override the conclusions of inter-procedural effect analysis,
    // forcing the conclusion to always true.
    PyjuPurityOverrides_t purity;

    // hidden fields:
    // lock for modifications to the method
    PyjuMutex_t writelock;
};

struct PyjuMethodInstance_t {
    PYJU_DATA_TYPE
    union {
        PyjuValue_t *value;     // generic accessor
        PyjuModule_t *module;   // this is a toplevel thunk
        PyjuMethod_t *method;   // method this is specialized from
    } def;
    PyjuValue_t *specTypes;     // argument types this was specialized for
    PyjuSvec_t *sparam_vals;    // static parameter values, indexed by def.method->sparam_syms
    PyjuValue_t *uninferred;    // cached uncompressed code, for generated functions, top-level thunks, or the interpreter
    PyjuArray_t *backedges;     // list of method-instances which contain a call into this method-instance
    PyjuArray_t *callbacks;     // list of callback functions to inform external caches about invalidations
    _Atomic(PyjuCodeInstance_t *) cache;
    uint8_t inInference;        // flags to tell if inference is running on this object
    uint8_t precompiled;        // true if this instance was generated by an explicit `precompile(...)` call
};

// OpaqueClosure
struct PyjuOpaqueClosure {
    PYJU_DATA_TYPE
    PyjuValue_t *captures;
    size_t world;
    PyjuMethod_t *source;
    PyjuFptrArgs_t invoke;
    void *specptr;
};

struct PyjuCodeInstance_t {
    PYJU_DATA_TYPE
    PyjuMethodInstance_t *def; // method this is specialized from
    _Atomic(PyjuCodeInstance_t *) next; // pointer to the next cache entry

    // world range for which this object is valid to use
    size_t min_world;
    size_t max_world;

        // inference state cache
    PyjuValue_t *rettype; // return type for fptr
    PyjuValue_t *rettype_const; // inferred constant return value, or null
    _Atomic(PyjuValue_t *) inferred; // inferred pyju_code_info_t, or pyju_nothing, or null

    // purity results
#ifdef PYJU_USE_ANON_UNIONS_FOR_PURITY_FLAGS
    // see also encode_effects() and decode_effects() in `base/compiler/effects.jl`,
    union {
        uint32_t ipo_purity_bits;
        struct {
            uint8_t ipo_consistent          : 2;
            uint8_t ipo_effect_free         : 2;
            uint8_t ipo_nothrow             : 2;
            uint8_t ipo_terminates          : 2;
            uint8_t ipo_nonoverlayed        : 1;
            uint8_t ipo_notaskstate         : 2;
            uint8_t ipo_inaccessiblememonly : 2;
        } ipo_purity_flags;
    };
    union {
        uint32_t purity_bits;
        struct {
            uint8_t consistent          : 2;
            uint8_t effect_free         : 2;
            uint8_t nothrow             : 2;
            uint8_t terminates          : 2;
            uint8_t nonoverlayed        : 1;
            uint8_t notaskstate         : 2;
            uint8_t inaccessiblememonly : 2;
        } purity_flags;
    };
#else
    uint32_t ipo_purity_bits;
    _Atomic(uint32_t) purity_bits;
#endif

    PyjuValue_t *argescapes; // escape information of call arguments

    // compilation state cache
    uint8_t isspecsig; // if specptr is a specialized function signature for specTypes->rettype
    _Atomic(uint8_t) precompile;  // if set, this will be added to the output system image
    _Atomic(PyjuCallPtr_t) invoke; // jlcall entry point
    union PyjuGenericSpecPtr_t {
        _Atomic(void*) fptr;
        _Atomic(PyjuFptrArgs_t) fptr1;
        // 2 constant
        _Atomic(PyjuFptrSparam_t) fptr3;
        // 4 interpreter
    } specptr; // private data for `jlcall entry point
    uint8_t relocatability;  // nonzero if all roots are built into sysimg or tagged by module key
};

typedef PyjuValue_t PyjuFunction_t;

struct PyjuTVar_t {
    PYJU_DATA_TYPE
    PyjuSym_t *name;
    PyjuValue_t *lb;    // lower bound
    PyjuValue_t *ub;    // upper bound
};

// UnionAll type (iterated union over all values of a variable in certain bounds)
// written `body where lb<:var<:ub`
struct PyjuUnionAll_t {
    PYJU_DATA_TYPE
    PyjuTVar_t *var;
    PyjuValue_t *body;
};

struct PyjuMethTable_t;
// represents the "name" part of a DataType, describing the syntactic structure
// of a type and storing all data common to different instantiations of the type,
// including a cache for hash-consed allocation of DataType objects.
struct PyjuTypeName_t {
    PYJU_DATA_TYPE
    PyjuSym_t *name;
    PyjuModule_t *module;
    PyjuSvec_t *names;  // field names
    const uint32_t *atomicfileds;   // if any fields are atomic, we record them here
    const uint32_t *constfields;    // if any fields are const, we record them here
    // `wrapper` is either the only instantiation of the type (if no parameters)
    // or a UnionAll accepting parameters to make an instantiation.
    PyjuValue_t *wrapper;
    _Atomic(PyjuValue_t*) Typeofwrapper;  // cache for Type{wrapper}
    _Atomic(PyjuSvec_t*) cache;        // sorted array
    _Atomic(PyjuSvec_t*) linearcache;  // unsorted array
    PyjuMethTable_t *mt;
    PyjuArray_t *partial;               // incomplete instantiations of this type
    intptr_t hash;
    int32_t n_uninitialized;
    // type properties
    uint8_t abstract:1;
    uint8_t mutabl:1;
    uint8_t mayinlinealloc:1;
    uint8_t max_methods; // override for inference's max_methods setting (0 = no additional limit or relaxation)
};

struct PyjuUnionType_t {
    PYJU_DATA_TYPE
    PyjuValue_t *a;
    PyjuValue_t *b;
};

// in little-endian, isptr is always the first bit, avoiding the need for a branch in computing isptr
struct PyjuFieldDesc8_t {
    uint8_t isptr:1;
    uint8_t size:7;
    uint8_t offset;   // offset relative to data start, excluding type tag
};

struct PyjuFieldDesc16_t {
    uint16_t isptr:1;
    uint16_t size:15;
    uint16_t offset;   // offset relative to data start, excluding type tag
};

struct PyjuFieldDesc32_t {
    uint32_t isptr:1;
    uint32_t size:31;
    uint32_t offset;   // offset relative to data start, excluding type tag
};

struct PyjuDataTypeLayout_t {
    uint32_t nfields;
    uint32_t npointers; // number of pointers embedded inside
    int32_t first_ptr; // index of the first pointer (or -1)
    uint16_t alignment; // strictest alignment over all fields
    uint16_t haspadding : 1; // has internal undefined bytes
    uint16_t fielddesc_type : 2; // 0 -> 8, 1 -> 16, 2 -> 32, 3 -> foreign type
    // union {
    //     PyjuFieldDesc8_t field8[nfields];
    //     PyjuFieldDesc16_t field16[nfields];
    //     PyjuFieldDesc32_t field32[nfields];
    // };
    // union { // offsets relative to data start in words
    //     uint8_t ptr8[npointers];
    //     uint16_t ptr16[npointers];
    //     uint32_t ptr32[npointers];
    // };
};

struct PyjuDataType_t {
    PYJU_DATA_TYPE
    PyjuTypeName_t *name;
    PyjuDataType_t *super;
    PyjuSvec_t *parameters;
    PyjuSvec_t *types;
    PyjuValue_t *instance;  // for singletons
    const PyjuDataTypeLayout_t *layout;
    int32_t size; // TODO: move to _PyjuDataTypeLayout_t
    // memoized properties
    uint32_t hash;
    uint8_t hasfreetypevars:1; // majority part of isconcrete computation
    uint8_t isconcretetype:1; // whether this type can have instances
    uint8_t isdispatchtuple:1; // aka isleaftupletype
    uint8_t isbitstype:1; // relevant query for C-api and type-parameters
    uint8_t zeroinit:1; // if one or more fields requires zero-initialization
    uint8_t has_concrete_subtype:1; // If clear, no value will have this datatype
    uint8_t cached_by_hash:1; // stored in hash-based set cache (instead of linear cache)
};

struct PyjuVararg_t {
    PYJU_DATA_TYPE
    PyjuValue_t *T;
    PyjuValue_t *N;
} ;

struct PyjuWeakRef_t {
    PYJU_DATA_TYPE
    PyjuValue_t *value;
};


struct PyjuBindind_t {
    // not first-class
    PyjuSym_t *name;
    _Atomic(PyjuValue_t*) value;
    _Atomic(PyjuValue_t*) globalref;  // cached GlobalRef for this binding
    PyjuModule_t* owner;  // for individual imported bindings -- TODO: make _Atomic
    _Atomic(PyjuValue_t*) ty;  // binding type
    uint8_t constp:1;
    uint8_t exportp:1;
    uint8_t imported:1;
    uint8_t deprecated:2; // 0=not deprecated, 1=renamed, 2=moved to another package
};

struct PyjuUuid_t {
    uint64_t hi;
    uint64_t lo;
};

struct PyjuModule_t {
    PYJU_DATA_TYPE
    PyjuSym_t *name;
    PyjuModule_t *parent;
    // hidden fields:
    htable_t bindings;
    arraylist_t usings; //
    uint64_t build_id;
    PyjuUuid_t uuid;
    size_t primary_world;
    _Atomic(uint32_t) counter;
    int32_t nospecialize;   // global bit flags; initialization for new methods
    int8_t optlevel;
    int8_t compile;
    int8_t infer;
    uint8_t istopmod;
    int8_t max_methods;
    PyjuMutex_t lock;
};

// one Type-to-Value entry
struct PyjuTypeMapEntry_t {
    PYJU_DATA_TYPE
    _Atomic(PyjuTypeMapEntry_t*) next; // invasive linked list
    PyjuTupleType_t *sig; // the type signature for this entry
    PyjuTupleType_t *simplesig; // a simple signature for fast rejection
    PyjuSvec_t *guardsigs;
    size_t min_world;
    size_t max_world;
    union {
        PyjuValue_t *value; // generic accessor
        PyjuMethodInstance_t *linfo; // [nullable] for guard entries
        PyjuMethod_t *method;
    } func;
    // memoized properties of sig:
    int8_t isleafsig; // isleaftype(sig) & !any(isType, sig) : unsorted and very fast
    int8_t issimplesig; // all(isleaftype | isAny | isType | isVararg, sig) : sorted and fast
    int8_t va; // isVararg(sig)
};

// one level in a TypeMap tree (each level splits on a type at a given offset)
struct PyjuTypeMapLevel_t {
    PYJU_DATA_TYPE
    // these vectors contains vectors of more levels in their intended visit order
    // with an index that gives the functionality of a sorted dict.
    // next split may be on Type{T} as LeafTypes then TypeName's parents up to Any
    // next split may be on LeafType
    // next split may be on TypeName
    _Atomic(PyjuArray_t*) arg1; // contains LeafType
    _Atomic(PyjuArray_t*) targ; // contains Type{LeafType}
    _Atomic(PyjuArray_t*) name1; // contains non-abstract TypeName, for parents up to (excluding) Any
    _Atomic(PyjuArray_t*) tname; // contains a dict of Type{TypeName}, for parents up to Any
    // next a linear list of things too complicated at this level for analysis (no more levels)
    _Atomic(PyjuTypeMapEntry_t*) linear;
    // finally, start a new level if the type at offs is Any
    _Atomic(PyjuTypeMap_t*) any;
};

struct PyjuMethTable_t {
    PYJU_DATA_TYPE
    PyjuSym_t *name;    // sometimes a hack used by serialization to handle kwsorter
    _Atomic(PyjuTypeMap_t*) defs;
    _Atomic(PyjuArray_t*) leafcache;
    _Atomic(PyjuTypeMap_t*) cache;
    intptr_t max_args;      // max # of no-vararg arguments in a signature
    PyjuValue_t *kwsorter;  // keyword argument sorter function
    PyjuModule_t *module; // used for incremental serialization to locate original binding
    PyjuArray_t *backedges;
    PyjuMutex_t writelock;
    uint8_t offs; // 0, or 1 to skip splitting typemap of first (function) argument
    uint8_t frozen; // whether this accepts adding new methods
};

struct PyjuExpr_t {
    PYJU_DATA_TYPE
    PyjuSym_t *head;
    PyjuArray_t *args;
};


struct PyjuMethodMatch_t {
    PYJU_DATA_TYPE
    PyjuTupleType_t *spec_types;
    PyjuSvec_t *sparams;
    PyjuMethod_t *method;
    // A bool on the julia side, but can be temporarily 0x2 as a sentinel
    // during construction.
    uint8_t fully_covers;
};

// gc -------------------------------------------------------------------------
struct PyjuGcFrame_t {
    size_t nroots;
    PyjuGcFrame_t *prev;
    // actual roots go here
};

// NOTE: it is the caller's responsibility to make sure arguments are
// rooted such that the gc can see them on the stack.
// `foo(f(), g())` is not safe,
// since the result of `f()` is not rooted during the call to `g()`,
// and the arguments to foo are not gc-protected during the call to foo.
// foo can't do anything about it, so the caller must do:
// PyjuValue_t *x=NULL, *y=NULL; PYJU_GC_PUSH2(&x, &y);
// x = f(); y = g(); foo(x, y)

#define pyju_pgcstack (pyju_current_task->gcstack)

#define PYJU_GC_ENCODE_PUSHARGS(n)   (((size_t)(n))<<2)
#define PYJU_GC_ENCODE_PUSH(n)       ((((size_t)(n))<<2)|1)


#define PYJU_GC_PUSH1(arg1)                                                                               \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(1), pyju_pgcstack, arg1};                                 \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSH2(arg1, arg2)                                                                         \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(2), pyju_pgcstack, arg1, arg2};                           \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSH3(arg1, arg2, arg3)                                                                   \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(3), pyju_pgcstack, arg1, arg2, arg3};                     \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSH4(arg1, arg2, arg3, arg4)                                                             \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(4), pyju_pgcstack, arg1, arg2, arg3, arg4};               \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSH5(arg1, arg2, arg3, arg4, arg5)                                                       \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(5), pyju_pgcstack, arg1, arg2, arg3, arg4, arg5};         \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSH6(arg1, arg2, arg3, arg4, arg5, arg6)                                                 \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(6), pyju_pgcstack, arg1, arg2, arg3, arg4, arg5, arg6};   \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSH7(arg1, arg2, arg3, arg4, arg5, arg6, arg7)                                           \
  void *__gc_stkf[] = {(void*)PYJU_GC_ENCODE_PUSH(7), pyju_pgcstack, arg1, arg2, arg3, arg4, arg5, arg6, arg7}; \
  pyju_pgcstack = (PyjuGcFrame_t*)__gc_stkf;

#define PYJU_GC_PUSHARGS(rts_var,n)                                                                       \
  rts_var = ((PyjuValue_t**)alloca(((n)+2)*sizeof(PyjuValue_t*)))+2;                                      \
  ((void**)rts_var)[-2] = (void*)PYJU_GC_ENCODE_PUSHARGS(n);                                              \
  ((void**)rts_var)[-1] = pyju_pgcstack;                                                                  \
  memset((void*)rts_var, 0, (n)*sizeof(PyjuValue_t*));                                                   \
  pyju_pgcstack = (PyjuGcFrame_t*)&(((void**)rts_var)[-2])

#define PYJU_GC_POP() (pyju_pgcstack = pyju_pgcstack->prev)

PYJU_DLLEXPORT int pyju_gc_enable(int on);
PYJU_DLLEXPORT int pyju_gc_is_enabled(void);

enum PyjuGcCollection_t {
    PYJU_GC_AUTO = 0,         // use heuristics to determine the collection type
    PYJU_GC_FULL = 1,         // force a full collection
    PYJU_GC_INCREMENTAL = 2,  // force an incremental collection
};

// PYJU_DLLEXPORT void pyju_gc_collect(PyjuGcCollection_t);

// PYJU_DLLEXPORT void pyju_gc_add_finalizer(PyjuValue_t *v, PyjuFunction_t *f) PYJU_NOTSAFEPOINT;
// PYJU_DLLEXPORT void pyju_gc_add_ptr_finalizer(PyjuPtls_t ptls, PyjuValue_t *v, void *f) PYJU_NOTSAFEPOINT;
// PYJU_DLLEXPORT void pyju_finalize(PyjuValue_t *o);
// PYJU_DLLEXPORT PyjuWeakRef_t *pyju_gc_new_weakref(PyjuValue_t *value);
// PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_0w(void);
// PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_1w(void);
// PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_2w(void);
// PYJU_DLLEXPORT PyjuValue_t *pyju_gc_alloc_3w(void);
// PYJU_DLLEXPORT PyjuValue_t *pyju_gc_allocobj(size_t sz);
// PYJU_DLLEXPORT void *pyju_malloc_stack(size_t *bufsz, struct _PyjuTask_t *owner) PYJU_NOTSAFEPOINT;
// PYJU_DLLEXPORT void pyju_free_stack(void *stkbuf, size_t bufsz);
// PYJU_DLLEXPORT void pyju_gc_use(PyjuValue_t *a);

// PYJU_DLLEXPORT void pyju_clear_malloc_data(void);

// // GC write barriers
// PYJU_DLLEXPORT void pyju_gc_queue_root(const PyjuValue_t *root) PYJU_NOTSAFEPOINT;
// PYJU_DLLEXPORT void pyju_gc_queue_multiroot(const PyjuValue_t *root, const PyjuValue_t *stored) PYJU_NOTSAFEPOINT;

// STATIC_INLINE void pyju_gc_wb(const void *parent, const void *ptr) PYJU_NOTSAFEPOINT
// {
//     // parent and ptr isa PyjuValue_t*
//     if (__unlikely(pyju_astaggedvalue(parent)->bits.gc == 3 && // parent is old and not in remset
//                    (pyju_astaggedvalue(ptr)->bits.gc & 1) == 0)) // ptr is young
//         pyju_gc_queue_root((PyjuValue_t*)parent);
// }

// STATIC_INLINE void pyju_gc_wb_back(const void *ptr) PYJU_NOTSAFEPOINT // ptr isa PyjuValue_t*
// {
//     // if ptr is old
//     if (__unlikely(pyju_astaggedvalue(ptr)->bits.gc == 3)) {
//         pyju_gc_queue_root((PyjuValue_t*)ptr);
//     }
// }

// STATIC_INLINE void pyju_gc_multi_wb(const void *parent, const PyjuValue_t *ptr) PYJU_NOTSAFEPOINT
// {
//     // ptr is an immutable object
//     if (__likely(pyju_astaggedvalue(parent)->bits.gc != 3))
//         return; // parent is young or in remset
//     if (__likely(pyju_astaggedvalue(ptr)->bits.gc == 3))
//         return; // ptr is old and not in remset (thus it does not point to young)
//     PyjuDataType_t *dt = (PyjuDataType_t*)pyju_typeof(ptr);
//     const PyjuDataTypeLayout_t *ly = dt->layout;
//     if (ly->npointers)
//         pyju_gc_queue_multiroot((PyjuValue_t*)parent, ptr);
// }

// PYJU_DLLEXPORT void *pyju_gc_managed_malloc(size_t sz);
// PYJU_DLLEXPORT void *pyju_gc_managed_realloc(void *d, size_t sz, size_t oldsz,
//                                          int isaligned, PyjuValue_t *owner);
// PYJU_DLLEXPORT void pyju_gc_safepoint(void);

// constants and type objects -------------------------------------------------

// kinds
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_datatype_type PYJU_GLOBALLY_ROOTED;


// object accessors -----------------------------------------------------------

#define pyju_svec_len(t)    (((PyjuSvec_t*)t)->length)
#define pyju_svec_set_len_unsafe(t, n)  (((PyjuSvec_t*)t)->length = (n))
#define pyju_svec_data(t)   ((PyjuValue_t**)((char*)(t) + sizeof(PyjuSvec_t)))

// STATIC_INLINE PyjuValue_t *pyju_svecref(void *t PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT
// {
//     assert(pyju_typeis(t, pyju_simplevector_type));
//     assert(i < pyju_svec_len(t));
//     // while svec is supposedly immutable, in practice we sometimes publish it first
//     // and set the values lazily
//     return pyju_atomic_load_relaxed((_Atomic(PyjuValue_t*)*)pyju_svec_data(t) + i);
// }
// STATIC_INLINE PyjuValue_t *pyju_svecset(
//     void *t PYJU_ROOTING_ARGUMENT PYJU_PROPAGATES_ROOT,
//     size_t i, void *x PYJU_ROOTED_ARGUMENT) PYJU_NOTSAFEPOINT
// {
//     assert(pyju_typeis(t, pyju_simplevector_type));
//     assert(i < pyju_svec_len(t));
//     // TODO: while svec is supposedly immutable, in practice we sometimes publish it first
//     // and set the values lazily. Those users should be using pyju_atomic_store_release here.
//     pyju_svec_data(t)[i] = (PyjuValue_t*)x;
//     pyju_gc_wb(t, x);
//     return (PyjuValue_t*)x;
// }


#define pyju_array_len(a)   (((PyjuArray_t*)(a))->length)
#define pyju_array_data(a)  ((void*)((PyjuArray_t*)(a))->data)
#define pyju_array_dim(a,i) ((&((PyjuArray_t*)(a))->nrows)[i])
#define pyju_array_dim0(a)  (((PyjuArray_t*)(a))->nrows)
#define pyju_array_nrows(a) (((PyjuArray_t*)(a))->nrows)
#define pyju_array_ndims(a) ((int32_t)(((PyjuArray_t*)a)->flags.ndims))
#define pyju_array_data_owner_offset(ndims) (offsetof(PyjuArray_t,ncols) + sizeof(size_t)*(1+pyju_array_ndimwords(ndims))) // in bytes
#define pyju_array_data_owner(a) (*((PyjuValue_t**)((char*)a + pyju_array_data_owner_offset(pyju_array_ndims(a)))))




// tasks and exceptions -------------------------------------------------------

struct PyjuTimingBlock_t;
struct PyjuExcStack_t;

// info describing an exception handler
struct PyjuHandler_t {
    pyju_jmp_buf eh_ctx;
    PyjuGcFrame_t *gcstack;
    struct PyjuHandler_t *prev;
    int8_t gc_state;
    size_t locks_len;
    sig_atomic_t defer_signal;
    PyjuTimingBlock_t *timing_stack;
    size_t world_age;
};

struct PyjuTask_t {
    PYJU_DATA_TYPE
    PyjuValue_t *next;  // invasive linked list for scheduler
    PyjuValue_t *queue; // invasive linked list for scheduler
    PyjuValue_t *tls;
    PyjuValue_t *donenotify;
    PyjuValue_t *result;
    PyjuValue_t *logstate;
    PyjuFunction_t *start;
    uint64_t rngState[4];
    _Atomic(uint8_t) _state;
    uint8_t sticky; // record whether this Task can be migrated to a new thread
    _Atomic(uint8_t) _isexception; // set if `result` is an exception to throw or that we exited with
    // multiqueue priority
    uint16_t priority;

// hidden state:
    // id of owning thread - does not need to be defined until the task runs
    _Atomic(int16_t) tid;
    // threadpool id
    int8_t threadpoolid;
    // saved gc stack top for context switches
    PyjuGcFrame_t *gcstack;
    size_t world_age;
    // quick lookup for current ptls
    PyjuPtls_t ptls; // == pyju_all_tls_states[tid]
    // saved exception stack
    PyjuExcStack_t *excstack;
    // current exception handler
    PyjuHandler_t *eh;
    // saved thread state
    PyjuUContext_t ctx;
    void *stkbuf; // malloc'd memory (either copybuf or stack)
    size_t bufsz; // actual sizeof stkbuf
    unsigned int copy_stack:31; // sizeof stack for copybuf
    unsigned int started:1;
};

#define PYJU_TASK_STATE_RUNNABLE 0
#define PYJU_TASK_STATE_DONE     1
#define PYJU_TASK_STATE_FAILED   2

PYJU_DLLEXPORT PyjuTask_t *pyju_new_task(PyjuFunction_t*, PyjuValue_t*, size_t);
PYJU_DLLEXPORT void pyju_switchto(PyjuTask_t **pt);
PYJU_DLLEXPORT int pyju_set_task_tid(PyjuTask_t *task, int16_t tid) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_set_task_threadpoolid(PyjuTask_t *task, int8_t tpid) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void PYJU_NORETURN pyju_throw(PyjuValue_t *e PYJU_MAYBE_UNROOTED);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_rethrow(void);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_sig_throw(void);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_rethrow_other(PyjuValue_t *e PYJU_MAYBE_UNROOTED);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_no_exc_handler(PyjuValue_t *e);
PYJU_DLLEXPORT PYJU_CONST_FUNC PyjuGcFrame_t **(pyju_get_pgcstack)(void) PYJU_GLOBALLY_ROOTED PYJU_NOTSAFEPOINT;
#define pyju_current_task (container_of(pyju_get_pgcstack(), PyjuTask_t, gcstack))


#ifdef __cplusplus
}
#endif
