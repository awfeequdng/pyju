#pragma once
#include <bits/types/sig_atomic_t.h>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <stdint.h>
#include "support/dtypes.h"
#include "support/htable.h"
#include "support/arraylist.h"
#include "pyju_atomics.h"
#include "pyju_threads.h"
#include "pyju_assert.h"
#include "support/libsupport.h"


#define DEBUG_FUNC \
    printf("func: %s, line: %d ---------------------------------------------\n",\
            __FUNCTION__, __LINE__);

#define DEBUG_FUNC_STR(str) \
    printf("func: %s, line: %d, %s -----------------------------------------\n",\
           __FUNCTION__, __LINE__, str);

#define DEBUG_FUNC_INT(i) \
    printf("func: %s, line: %d, %d -----------------------------------------\n",\
            __FUNCTION__, __LINE__, i);

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

#define PYJU_TV_SIZE  sizeof(PyjuTaggedValue_t)

struct PyjuValue_t {
    PyjuTaggedValue_t tag;
    char __data_ptr[];
};

#define pyju_astaggedvalue(v)                                             \
    ((PyjuTaggedValue_t*)v)

#define pyju_valueof(v)                                                 \
    ((PyjuValue_t*)v)

#define pyju_typeof(v)                                                    \
    ((PyjuValue_t*)(pyju_astaggedvalue(v)->header & ~(uintptr_t)7))

static inline void pyju_set_typeof(void *v, void *t)
{
    // Do not call this on a value that is already initialized.
    PyjuTaggedValue_t *tag = pyju_astaggedvalue(v);
    pyju_atomic_store_relaxed((_Atomic(PyjuValue_t*)*)&tag->type, (PyjuValue_t*)t);
}
#define pyju_typeis(v, t) (pyju_typeof(v) == (PyjuValue_t *)(t))

// Symbols are interned strings (hash-consed) stored as an invasive binary tree.
// The string data is nul-terminated and hangs off the end of the struct.
struct PyjuSym_t {
    PYJU_DATA_TYPE
    _Atomic(PyjuSym_t*) left;
    _Atomic(PyjuSym_t*) right;
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

STATIC_INLINE int pyju_array_ndimwords(uint32_t ndims) {
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
    const uint32_t *atomicfields;   // if any fields are atomic, we record them here
    const uint32_t *constfields;    // if any fields are const, we record them here
    // `wrapper` is either the only instantiation of the type (if no parameters)
    // or a UnionAll accepting parameters to make an instantiation.
    PyjuValue_t *wrapper;
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


struct PyjuBinding_t {
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

// GC write barriers
PYJU_DLLEXPORT void pyju_gc_queue_root(const PyjuValue_t *root) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_gc_queue_multiroot(const PyjuValue_t *root, const PyjuValue_t *stored) PYJU_NOTSAFEPOINT;

STATIC_INLINE void pyju_gc_wb(const void *parent, const void *ptr) PYJU_NOTSAFEPOINT
{
    // parent and ptr isa PyjuValue_t*
    if (__unlikely(pyju_astaggedvalue(parent)->bits.gc == 3 && // parent is old and not in remset
                   (pyju_astaggedvalue(ptr)->bits.gc & 1) == 0)) // ptr is young
        pyju_gc_queue_root((PyjuValue_t*)parent);
}

STATIC_INLINE void pyju_gc_wb_back(const void *ptr) PYJU_NOTSAFEPOINT // ptr isa PyjuValue_t*
{
    // if ptr is old
    if (__unlikely(pyju_astaggedvalue(ptr)->bits.gc == 3)) {
        pyju_gc_queue_root((PyjuValue_t*)ptr);
    }
}

STATIC_INLINE void pyju_gc_multi_wb(const void *parent, const PyjuValue_t *ptr) PYJU_NOTSAFEPOINT
{
    // ptr is an immutable object
    if (__likely(pyju_astaggedvalue(parent)->bits.gc != 3))
        return; // parent is young or in remset
    if (__likely(pyju_astaggedvalue(ptr)->bits.gc == 3))
        return; // ptr is old and not in remset (thus it does not point to young)
    PyjuDataType_t *dt = (PyjuDataType_t*)pyju_typeof(ptr);
    const PyjuDataTypeLayout_t *ly = dt->layout;
    if (ly->npointers)
        pyju_gc_queue_multiroot((PyjuValue_t*)parent, ptr);
}

PYJU_DLLEXPORT void *pyju_gc_managed_malloc(size_t sz);
PYJU_DLLEXPORT void *pyju_gc_managed_realloc(void *d, size_t sz, size_t oldsz,
                                         int isaligned, PyjuValue_t *owner);
PYJU_DLLEXPORT void pyju_gc_safepoint(void);

#define pyju_nparams(t)  pyju_svec_len(((PyjuDataType_t*)(t))->parameters)
#define pyju_tparam0(t)  pyju_svecref(((PyjuDataType_t*)(t))->parameters, 0)
#define pyju_tparam1(t)  pyju_svecref(((PyjuDataType_t*)(t))->parameters, 1)
#define pyju_tparam(t,i) pyju_svecref(((PyjuDataType_t*)(t))->parameters, i)


// get a pointer to the data in a datatype
#define pyju_data_ptr(v)  ((PyjuValue_t**)((char*)v + PYJU_TV_SIZE))

#define pyju_string_data(s) ((char*)s + PYJU_TV_SIZE + sizeof(void*))
#define pyju_string_len(s)  (*(size_t*)((char*)s + PYJU_TV_SIZE))
// constants and type objects -------------------------------------------------

// kinds
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_typeofbottom_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_datatype_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_uniontype_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_unionall_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_tvar_type PYJU_GLOBALLY_ROOTED;

extern PYJU_DLLIMPORT PyjuDataType_t *pyju_any_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_type_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_typename_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_type_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_symbol_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_ssavalue_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_abstractslot_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_slotnumber_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_typedslot_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_argument_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_const_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_partial_struct_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_partial_opaque_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_interconditional_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_method_match_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_simplevector_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_tuple_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_vecelement_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_anytuple_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_emptytuple_type PYJU_GLOBALLY_ROOTED;
#define pyju_tuple_type pyju_anytuple_type
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_anytuple_type_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_vararg_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_function_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_builtin_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_opaque_closure_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_opaque_closure_typename PYJU_GLOBALLY_ROOTED;

extern PYJU_DLLIMPORT PyjuValue_t *pyju_bottom_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_method_instance_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_code_instance_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_code_info_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_method_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_module_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_abstractarray_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_densearray_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_array_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_array_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_weakref_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_abstractstring_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_string_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_errorexception_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_argumenterror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_loaderror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_initerror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_typeerror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_methoderror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_undefvarerror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_atomicerror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_lineinfonode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_stackovf_exception PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_memory_exception PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_readonlymemory_exception PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_diverror_exception PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_undefref_exception PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_interrupt_exception PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_boundserror_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_an_empty_vec_any PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_an_empty_string PYJU_GLOBALLY_ROOTED;

extern PYJU_DLLIMPORT PyjuDataType_t *pyju_bool_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_char_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_int8_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_uint8_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_int16_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_uint16_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_int32_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_uint32_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_int64_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_uint64_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_float16_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_float32_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_float64_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_floatingpoint_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_number_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_void_type PYJU_GLOBALLY_ROOTED;  // deprecated
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_nothing_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_signed_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_voidpointer_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_uint8pointer_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_pointer_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_llvmpointer_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_ref_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_pointer_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_llvmpointer_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuTypeName_t *pyju_namedtuple_typename PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuUnionAll_t *pyju_namedtuple_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_task_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_pair_type PYJU_GLOBALLY_ROOTED;

extern PYJU_DLLIMPORT PyjuValue_t *pyju_array_uint8_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_array_any_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_array_symbol_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_array_int32_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_array_uint64_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_expr_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_globalref_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_linenumbernode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_gotonode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_gotoifnot_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_returnnode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_phinode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_pinode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_phicnode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_upsilonnode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_quotenode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_newvarnode_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_intrinsic_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_methtable_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_typemap_level_type PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuDataType_t *pyju_typemap_entry_type PYJU_GLOBALLY_ROOTED;

extern PYJU_DLLIMPORT PyjuSvec_t *pyju_emptysvec PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_emptytuple PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_true PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_false PYJU_GLOBALLY_ROOTED;
extern PYJU_DLLIMPORT PyjuValue_t *pyju_nothing PYJU_GLOBALLY_ROOTED;

// object accessors -----------------------------------------------------------

#define pyju_svec_len(t)    (((PyjuSvec_t*)t)->length)
#define pyju_svec_set_len_unsafe(t, n)  (((PyjuSvec_t*)t)->length = (n))
#define pyju_svec_data(t)   ((PyjuValue_t**)((char*)(t) + sizeof(PyjuSvec_t)))

STATIC_INLINE PyjuValue_t *pyju_svecref(void *t PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT
{
    assert(pyju_typeis(t, pyju_simplevector_type));
    assert(i < pyju_svec_len(t));
    // while svec is supposedly immutable, in practice we sometimes publish it first
    // and set the values lazily
    return pyju_atomic_load_relaxed((_Atomic(PyjuValue_t*)*)pyju_svec_data(t) + i);
}
STATIC_INLINE PyjuValue_t *pyju_svecset(
    void *t PYJU_ROOTING_ARGUMENT PYJU_PROPAGATES_ROOT,
    size_t i, void *x PYJU_ROOTED_ARGUMENT) PYJU_NOTSAFEPOINT
{
    assert(pyju_typeis(t, pyju_simplevector_type));
    assert(i < pyju_svec_len(t));
    // TODO: while svec is supposedly immutable, in practice we sometimes publish it first
    // and set the values lazily. Those users should be using pyju_atomic_store_release here.
    pyju_svec_data(t)[i] = (PyjuValue_t*)x;
    pyju_gc_wb(t, x);
    return (PyjuValue_t*)x;
}


#define pyju_array_len(a)   (((PyjuArray_t*)(a))->length)
#define pyju_array_data(a)  ((void*)((PyjuArray_t*)(a))->data)
#define pyju_array_dim(a,i) ((&((PyjuArray_t*)(a))->nrows)[i])
#define pyju_array_dim0(a)  (((PyjuArray_t*)(a))->nrows)
#define pyju_array_nrows(a) (((PyjuArray_t*)(a))->nrows)
#define pyju_array_ndims(a) ((int32_t)(((PyjuArray_t*)a)->flags.ndims))
#define pyju_array_data_owner_offset(ndims) (offsetof(PyjuArray_t,ncols) + sizeof(size_t)*(1+pyju_array_ndimwords(ndims))) // in bytes
#define pyju_array_data_owner(a) (*((PyjuValue_t**)((char*)a + pyju_array_data_owner_offset(pyju_array_ndims(a)))))


PYJU_DLLEXPORT char *pyju_array_typetagdata(PyjuArray_t *a) PYJU_NOTSAFEPOINT;

#ifdef __clang_gcanalyzer__
PyjuValue_t **pyju_array_ptr_data(PyjuArray_t *a PYJU_PROPAGATES_ROOT) PYJU_NOTSAFEPOINT;
STATIC_INLINE PyjuValue_t *pyju_array_ptr_ref(void *a PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT;
STATIC_INLINE PyjuValue_t *pyju_array_ptr_set(
    void *a PYJU_ROOTING_ARGUMENT, size_t i,
    void *x PYJU_ROOTED_ARGUMENT) PYJU_NOTSAFEPOINT;
#else
#define pyju_array_ptr_data(a)  ((PyjuValue_t**)((PyjuArray_t*)(a))->data)
STATIC_INLINE PyjuValue_t *pyju_array_ptr_ref(void *a PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT
{
    assert(((PyjuArray_t*)a)->flags.ptrarray);
    assert(i < pyju_array_len(a));
    return pyju_atomic_load_relaxed(((_Atomic(PyjuValue_t*)*)(pyju_array_data(a))) + i);
}
STATIC_INLINE PyjuValue_t *pyju_array_ptr_set(
    void *a PYJU_ROOTING_ARGUMENT, size_t i,
    void *x PYJU_ROOTED_ARGUMENT) PYJU_NOTSAFEPOINT
{
    assert(((PyjuArray_t*)a)->flags.ptrarray);
    assert(i < pyju_array_len(a));
    pyju_atomic_store_relaxed(((_Atomic(PyjuValue_t*)*)(pyju_array_data(a))) + i, (PyjuValue_t*)x);
    if (x) {
        if (((PyjuArray_t*)a)->flags.how == 3) {
            a = pyju_array_data_owner(a);
        }
        pyju_gc_wb(a, x);
    }
    return (PyjuValue_t*)x;
}
#endif

STATIC_INLINE uint8_t pyju_array_uint8_ref(void *a, size_t i) PYJU_NOTSAFEPOINT
{
    assert(i < pyju_array_len(a));
    assert(pyju_typeis(a, pyju_array_uint8_type));
    return ((uint8_t*)(pyju_array_data(a)))[i];
}
STATIC_INLINE void pyju_array_uint8_set(void *a, size_t i, uint8_t x) PYJU_NOTSAFEPOINT
{
    assert(i < pyju_array_len(a));
    assert(pyju_typeis(a, pyju_array_uint8_type));
    ((uint8_t*)(pyju_array_data(a)))[i] = x;
}

#define pyju_exprarg(e,n) pyju_array_ptr_ref(((pyju_expr_t*)(e))->args, n)
#define pyju_exprargset(e, n, v) pyju_array_ptr_set(((pyju_expr_t*)(e))->args, n, v)
#define pyju_expr_nargs(e) pyju_array_len(((pyju_expr_t*)(e))->args)

#define pyju_fieldref(s,i) pyju_get_nth_field(((PyjuValue_t*)(s)),i)
#define pyju_fieldref_noalloc(s,i) pyju_get_nth_field_noalloc(((PyjuValue_t*)(s)),i)
#define pyju_nfields(v)    pyju_datatype_nfields(pyju_typeof(v))

// arrays
PYJU_DLLEXPORT PyjuArray_t *pyju_new_array(PyjuValue_t *atype, PyjuValue_t *dims);
PYJU_DLLEXPORT PyjuArray_t *pyju_reshape_array(PyjuValue_t *atype, PyjuArray_t *data,
                                          PyjuValue_t *dims);
PYJU_DLLEXPORT PyjuArray_t *pyju_ptr_to_array_1d(PyjuValue_t *atype, void *data,
                                            size_t nel, int own_buffer);
PYJU_DLLEXPORT PyjuArray_t *pyju_ptr_to_array(PyjuValue_t *atype, void *data,
                                         PyjuValue_t *dims, int own_buffer);

PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_array_1d(PyjuValue_t *atype, size_t nr);
PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_array_2d(PyjuValue_t *atype, size_t nr,
                                           size_t nc);
PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_array_3d(PyjuValue_t *atype, size_t nr,
                                           size_t nc, size_t z);
PYJU_DLLEXPORT PyjuArray_t *pyju_pchar_to_array(const char *str, size_t len);
PYJU_DLLEXPORT PyjuValue_t *pyju_pchar_to_string(const char *str, size_t len);
PYJU_DLLEXPORT PyjuValue_t *pyju_cstr_to_string(const char *str);
PYJU_DLLEXPORT PyjuValue_t *pyju_alloc_string(size_t len);
PYJU_DLLEXPORT PyjuValue_t *PyjuArray_to_string(PyjuArray_t *a);
PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_vec_any(size_t n);
PYJU_DLLEXPORT PyjuValue_t *pyju_arrayref(PyjuArray_t *a, size_t i);  // 0-indexed
PYJU_DLLEXPORT PyjuValue_t *pyju_ptrarrayref(PyjuArray_t *a PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT;  // 0-indexed
PYJU_DLLEXPORT void pyju_arrayset(PyjuArray_t *a PYJU_ROOTING_ARGUMENT, PyjuValue_t *v PYJU_ROOTED_ARGUMENT PYJU_MAYBE_UNROOTED, size_t i);  // 0-indexed
PYJU_DLLEXPORT void pyju_arrayunset(PyjuArray_t *a, size_t i);  // 0-indexed
PYJU_DLLEXPORT int pyju_array_isassigned(PyjuArray_t *a, size_t i);  // 0-indexed
PYJU_DLLEXPORT void pyju_array_grow_end(PyjuArray_t *a, size_t inc);
PYJU_DLLEXPORT void pyju_array_del_end(PyjuArray_t *a, size_t dec);
PYJU_DLLEXPORT void pyju_array_grow_beg(PyjuArray_t *a, size_t inc);
PYJU_DLLEXPORT void pyju_array_del_beg(PyjuArray_t *a, size_t dec);
PYJU_DLLEXPORT void pyju_array_sizehint(PyjuArray_t *a, size_t sz);
PYJU_DLLEXPORT void pyju_array_ptr_1d_push(PyjuArray_t *a, PyjuValue_t *item);
PYJU_DLLEXPORT void pyju_array_ptr_1d_append(PyjuArray_t *a, PyjuArray_t *a2);
PYJU_DLLEXPORT PyjuValue_t *pyju_apply_array_type(PyjuValue_t *type, size_t dim);
PYJU_DLLEXPORT int pyju_array_validate_dims(size_t *nel, size_t *tot, uint32_t ndims, size_t *dims, size_t elsz);
// property access
PYJU_DLLEXPORT void *pyju_array_ptr(PyjuArray_t *a);
PYJU_DLLEXPORT void *pyju_array_eltype(PyjuValue_t *a);
PYJU_DLLEXPORT int pyju_array_rank(PyjuValue_t *a);
PYJU_DLLEXPORT size_t pyju_array_size(PyjuValue_t *a, int d);

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



// determine actual entry point name
#if defined(sigsetjmp)
#define pyju_setjmp_f    __sigsetjmp
#define pyju_setjmp_name "__sigsetjmp"
#else
#define pyju_setjmp_f    sigsetjmp
#define pyju_setjmp_name "sigsetjmp"
#endif
#define pyju_setjmp(a,b)    sigsetjmp(a,b)
#define pyju_longjmp(a,b)   siglongjmp(a,b)


#ifdef __clang_gcanalyzer__
// This is hard. Ideally we'd teach the static analyzer about the extra control
// flow edges. But for now, just hide this as best we can
extern int had_exception;
#define PYJU_TRY if (1)
#define PYJU_CATCH if (had_exception)

#else

#define PYJU_TRY if (1)
#define PYJU_CATCH if (0)

// #define PYJU_TRY                                                    \
//     int i__tr, i__ca; pyju_handler_t __eh;                          \
//     size_t __excstack_state = pyju_excstack_state();                \
//     pyju_enter_handler(&__eh);                                      \
//     if (!pyju_setjmp(__eh.eh_ctx,0))                                \
//         for (i__tr=1; i__tr; i__tr=0, pyju_eh_restore_state(&__eh))

// #define PYJU_CATCH                                                \
//     else                                                        \
//         for (i__ca=1, pyju_eh_restore_state(&__eh); i__ca; i__ca=0, pyju_restore_excstack(__excstack_state))

#endif


// system information
PYJU_DLLEXPORT int pyju_errno(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_set_errno(int e) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int32_t pyju_stat(const char *path, char *statbuf) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_cpu_threads(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_effective_threads(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT long pyju_getpagesize(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT long pyju_getallocationgranularity(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_is_debugbuild(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuSym_t *pyju_get_UNAME(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuSym_t *pyju_get_ARCH(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_get_libllvm(void) PYJU_NOTSAFEPOINT;
extern PYJU_DLLIMPORT int pyju_n_threads;

// I/O system -----------------------------------------------------------------

struct uv_loop_s;
struct uv_handle_s;
struct uv_stream_s;
#ifdef _OS_WINDOWS_
typedef HANDLE pyju_uv_os_fd_t;
#else
typedef int pyju_uv_os_fd_t;
#endif
#define PYJU_STREAM struct uv_stream_s
#define PYJU_STDOUT pyju_uv_stdout
#define PYJU_STDERR pyju_uv_stderr
#define PYJU_STDIN  pyju_uv_stdin

PYJU_DLLEXPORT int pyju_process_events(void);

PYJU_DLLEXPORT struct uv_loop_s *pyju_global_event_loop(void);

PYJU_DLLEXPORT void pyju_close_uv(struct uv_handle_s *handle);

PYJU_DLLEXPORT PyjuArray_t *pyju_take_buffer(ios_t *s);

typedef struct {
    void *data;
    struct uv_loop_s *loop;
    int type; // enum uv_handle_type
    pyju_uv_os_fd_t file;
} pyju_uv_file_t;

#ifdef __GNUC__
#define _PYJU_FORMAT_ATTR(type, str, arg) \
    __attribute__((format(type, str, arg)))
#else
#define _PYJU_FORMAT_ATTR(type, str, arg)
#endif

PYJU_DLLEXPORT void pyju_uv_puts(struct uv_stream_s *stream, const char *str, size_t n);
PYJU_DLLEXPORT int pyju_printf(struct uv_stream_s *s, const char *format, ...)
    _PYJU_FORMAT_ATTR(printf, 2, 3);
PYJU_DLLEXPORT int pyju_vprintf(struct uv_stream_s *s, const char *format, va_list args)
    _PYJU_FORMAT_ATTR(printf, 2, 0);
PYJU_DLLEXPORT void pyju_safe_printf(const char *str, ...) PYJU_NOTSAFEPOINT
    _PYJU_FORMAT_ATTR(printf, 1, 2);

extern PYJU_DLLEXPORT PYJU_STREAM *PYJU_STDIN;
extern PYJU_DLLEXPORT PYJU_STREAM *PYJU_STDOUT;
extern PYJU_DLLEXPORT PYJU_STREAM *PYJU_STDERR;

PYJU_DLLEXPORT PYJU_STREAM *pyju_stdout_stream(void);
PYJU_DLLEXPORT PYJU_STREAM *pyju_stdin_stream(void);
PYJU_DLLEXPORT PYJU_STREAM *pyju_stderr_stream(void);
PYJU_DLLEXPORT int pyju_termios_size(void);

// showing and std streams
PYJU_DLLEXPORT void pyju_flush_cstdio(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_stdout_obj(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_stderr_obj(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT size_t pyju_static_show(PYJU_STREAM *out, PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT size_t pyju_static_show_func_sig(PYJU_STREAM *s, PyjuValue_t *type) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_print_backtrace(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void jlbacktrace(void) PYJU_NOTSAFEPOINT; // deprecated
// Mainly for debugging, use `void*` so that no type cast is needed in C++.
PYJU_DLLEXPORT void pyju_(void *pyju_value) PYJU_NOTSAFEPOINT;


PYJU_DLLEXPORT void pyju_init();



// showing and std streams
PYJU_DLLEXPORT void pyju_flush_cstdio(void) PYJU_NOTSAFEPOINT;

// julia options -----------------------------------------------------------

#include "pyju_options.h"

extern PYJU_DLLIMPORT pyju_options_t pyju_options;

PYJU_DLLEXPORT ssize_t pyju_sizeof_pyju_options(void);


// throwing common exceptions
PYJU_DLLEXPORT void PYJU_NORETURN pyju_error(const char *str);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_errorf(const char *fmt, ...);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_exceptionf(PyjuDataType_t *ty,
                                            const char *fmt, ...);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_eof_error(void);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_type_error(const char *fname,
                                            PyjuValue_t *expected PYJU_MAYBE_UNROOTED,
                                            PyjuValue_t *got PYJU_MAYBE_UNROOTED);
PYJU_DLLEXPORT void PYJU_NORETURN pyju_type_error_rt(const char *fname, const char *context,
                                               PyjuValue_t *expected PYJU_MAYBE_UNROOTED,
                                               PyjuValue_t *got PYJU_MAYBE_UNROOTED);

// Parse an argc/argv pair to extract general julia options, passing back out
// any arguments that should be passed on to the script.
PYJU_DLLEXPORT void pyju_parse_opts(int *argcp, char ***argvp);

// Settings for code_coverage and malloc_log
// NOTE: if these numbers change, test/cmdlineargs.jl will have to be updated
#define PYJU_LOG_NONE 0
#define PYJU_LOG_USER 1
#define PYJU_LOG_ALL  2
#define PYJU_LOG_PATH 3

#define PYJU_OPTIONS_CHECK_BOUNDS_DEFAULT 0
#define PYJU_OPTIONS_CHECK_BOUNDS_ON 1
#define PYJU_OPTIONS_CHECK_BOUNDS_OFF 2

#define PYJU_OPTIONS_COMPILE_DEFAULT 1
#define PYJU_OPTIONS_COMPILE_OFF 0
#define PYJU_OPTIONS_COMPILE_ON  1
#define PYJU_OPTIONS_COMPILE_ALL 2
#define PYJU_OPTIONS_COMPILE_MIN 3

#define PYJU_OPTIONS_COLOR_AUTO 0
#define PYJU_OPTIONS_COLOR_ON 1
#define PYJU_OPTIONS_COLOR_OFF 2

#define PYJU_OPTIONS_HISTORYFILE_ON 1
#define PYJU_OPTIONS_HISTORYFILE_OFF 0

#define PYJU_OPTIONS_STARTUPFILE_ON 1
#define PYJU_OPTIONS_STARTUPFILE_OFF 2

#define PYJU_LOGLEVEL_BELOWMIN -1000001
#define PYJU_LOGLEVEL_DEBUG    -1000
#define PYJU_LOGLEVEL_INFO      0
#define PYJU_LOGLEVEL_WARN      1000
#define PYJU_LOGLEVEL_ERROR     2000
#define PYJU_LOGLEVEL_ABOVEMAX  1000001

#define PYJU_OPTIONS_DEPWARN_OFF 0
#define PYJU_OPTIONS_DEPWARN_ON 1
#define PYJU_OPTIONS_DEPWARN_ERROR 2

#define PYJU_OPTIONS_WARN_OVERWRITE_OFF 0
#define PYJU_OPTIONS_WARN_OVERWRITE_ON 1

#define PYJU_OPTIONS_WARN_SCOPE_OFF 0
#define PYJU_OPTIONS_WARN_SCOPE_ON 1

#define PYJU_OPTIONS_POLLY_ON 1
#define PYJU_OPTIONS_POLLY_OFF 0

#define PYJU_OPTIONS_FAST_MATH_ON 1
#define PYJU_OPTIONS_FAST_MATH_OFF 2
#define PYJU_OPTIONS_FAST_MATH_DEFAULT 0

#define PYJU_OPTIONS_HANDLE_SIGNALS_ON 1
#define PYJU_OPTIONS_HANDLE_SIGNALS_OFF 0

#define PYJU_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_YES 1
#define PYJU_OPTIONS_USE_SYSIMAGE_NATIVE_CODE_NO 0

#define PYJU_OPTIONS_USE_COMPILED_MODULES_YES 1
#define PYJU_OPTIONS_USE_COMPILED_MODULES_NO 0


// TODO: we need to pin the task while using this (set pure bit)
PYJU_DLLEXPORT pyju_jmp_buf *pyju_get_safe_restore(void) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void pyju_set_safe_restore(pyju_jmp_buf *) PYJU_NOTSAFEPOINT;

PYJU_DLLEXPORT PyjuTask_t *pyju_get_current_task(void) PYJU_NOTSAFEPOINT;

// struct type info
PYJU_DLLEXPORT PyjuSvec_t *pyju_compute_fieldtypes(PyjuDataType_t *st PYJU_PROPAGATES_ROOT, void *stack);
#define pyju_get_fieldtypes(st) ((st)->types ? (st)->types : pyju_compute_fieldtypes((st), NULL))
STATIC_INLINE PyjuSvec_t *pyju_field_names(PyjuDataType_t *st) PYJU_NOTSAFEPOINT
{
    return st->name->names;
}
STATIC_INLINE PyjuValue_t *pyju_field_type(PyjuDataType_t *st PYJU_PROPAGATES_ROOT, size_t i)
{
    return pyju_svecref(pyju_get_fieldtypes(st), i);
}
STATIC_INLINE PyjuValue_t *pyju_field_type_concrete(PyjuDataType_t *st PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT
{
    assert(st->types);
    return pyju_svecref(st->types, i);
}


#define pyju_datatype_size(t)       (((PyjuDataType_t*)t)->size)
#define pyju_datatype_align(t)      (((PyjuDataType_t*)t)->layout->alignment)
#define pyju_datatype_nbits(t)      ((((PyjuDataType_t*)t)->size) * 8)
#define pyju_datatype_nfields(t)    (((PyjuDataType_t*)t)->layout->nfields)

// basic predicates -----------------------------------------------------------
#define pyju_is_nothing(v)     (((PyjuValue_t*)(v)) == ((PyjuValue_t*)pyju_nothing))
#define pyju_is_tuple(v)       (((PyjuDataType_t*)pyju_typeof(v))->name == pyju_tuple_typename)
#define pyju_is_namedtuple(v)  (((PyjuDataType_t*)pyju_typeof(v))->name == pyju_namedtuple_typename)
#define pyju_is_svec(v)        pyju_typeis(v,pyju_simplevector_type)
#define pyju_is_simplevector(v) pyju_is_svec(v)
#define pyju_is_typename(v)    pyju_typeis(v, pyju_typename_type)
#define pyju_is_datatype(v)    pyju_typeis(v, pyju_datatype_type)
#define pyju_is_mutable_datatype(t) (pyju_is_datatype(t) && (((PyjuDataType_t*)t)->name->mutabl))
#define pyju_is_immutable(t)   (!((PyjuDataType_t*)t)->name->mutabl)
#define pyju_is_immutable_datatype(t) (pyju_is_datatype(t) && (!((PyjuDataType_t*)t)->name->mutabl))
#define pyju_is_uniontype(v)   pyju_typeis(v, pyju_uniontype_type)

#define pyju_is_typevar(v)     pyju_typeis(v, pyju_tvar_type)
#define pyju_is_unionall(v)    pyju_typeis(v, pyju_unionall_type)
#define pyju_is_int8(v)        pyju_typeis(v, pyju_int8_type)
#define pyju_is_int16(v)       pyju_typeis(v, pyju_int16_type)
#define pyju_is_int32(v)       pyju_typeis(v, pyju_int32_type)
#define pyju_is_int64(v)       pyju_typeis(v, pyju_int64_type)
#define pyju_is_uint8(v)       pyju_typeis(v, pyju_uint8_type)
#define pyju_is_uint16(v)      pyju_typeis(v, pyju_uint16_type)
#define pyju_is_uint32(v)      pyju_typeis(v, pyju_uint32_type)
#define pyju_is_uint64(v)      pyju_typeis(v, pyju_uint64_type)
#define pyju_is_bool(v)        pyju_typeis(v, pyju_bool_type)
#define pyju_is_symbol(v)      pyju_typeis(v, pyju_symbol_type)
#define pyju_is_ssavalue(v)    pyju_typeis(v, pyju_ssavalue_type)

#define pyju_is_string(v)      pyju_typeis(v, pyju_string_type)
#define pyju_array_isbitsunion(a) (!(((PyjuArray_t*)(a))->flags.ptrarray) && pyju_is_uniontype(pyju_tparam0(pyju_typeof(a))))


PYJU_DLLEXPORT int pyju_subtype(PyjuValue_t *a, PyjuValue_t *b);

STATIC_INLINE int pyju_is_kind(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return (v==(PyjuValue_t*)pyju_uniontype_type || v==(PyjuValue_t*)pyju_datatype_type ||
            v==(PyjuValue_t*)pyju_unionall_type || v==(PyjuValue_t*)pyju_typeofbottom_type);
}

STATIC_INLINE int pyju_is_type(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return pyju_is_kind(pyju_typeof(v));
}

STATIC_INLINE int pyju_is_primitivetype(void *v) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(v) && pyju_is_immutable(v) &&
            ((PyjuDataType_t*)(v))->layout &&
            pyju_datatype_nfields(v) == 0 &&
            pyju_datatype_size(v) > 0);
}

STATIC_INLINE int pyju_is_structtype(void *v) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(v) &&
            !((PyjuDataType_t*)(v))->name->abstract &&
            !pyju_is_primitivetype(v));
}

STATIC_INLINE int pyju_isbits(void *t) PYJU_NOTSAFEPOINT // corresponding to isbitstype() in julia
{
    return (pyju_is_datatype(t) && ((PyjuDataType_t*)t)->isbitstype);
}

STATIC_INLINE int pyju_is_datatype_singleton(PyjuDataType_t *d) PYJU_NOTSAFEPOINT
{
    return (d->instance != NULL);
}

STATIC_INLINE int pyju_is_abstracttype(void *v) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(v) && ((PyjuDataType_t*)(v))->name->abstract);
}

STATIC_INLINE int pyju_is_array_type(void *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == pyju_array_typename);
}

STATIC_INLINE int pyju_is_array(void *v) PYJU_NOTSAFEPOINT
{
    PyjuValue_t *t = pyju_typeof(v);
    return pyju_is_array_type(t);
}

STATIC_INLINE int pyju_is_opaque_closure_type(void *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == pyju_opaque_closure_typename);
}

STATIC_INLINE int pyju_is_opaque_closure(void *v) PYJU_NOTSAFEPOINT
{
    PyjuValue_t *t = pyju_typeof(v);
    return pyju_is_opaque_closure_type(t);
}

STATIC_INLINE int pyju_is_cpointer_type(PyjuValue_t *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == ((PyjuDataType_t*)pyju_pointer_type->body)->name);
}

STATIC_INLINE int pyju_is_llvmpointer_type(PyjuValue_t *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == pyju_llvmpointer_typename);
}

STATIC_INLINE int pyju_is_abstract_ref_type(PyjuValue_t *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == ((PyjuDataType_t*)pyju_ref_type->body)->name);
}

STATIC_INLINE int pyju_is_tuple_type(void *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == pyju_tuple_typename);
}

STATIC_INLINE int pyju_is_namedtuple_type(void *t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == pyju_namedtuple_typename);
}

STATIC_INLINE int pyju_is_vecelement_type(PyjuValue_t* t) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(t) &&
            ((PyjuDataType_t*)(t))->name == pyju_vecelement_typename);
}

STATIC_INLINE int pyju_is_type_type(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return (pyju_is_datatype(v) &&
            ((PyjuDataType_t*)(v))->name == ((PyjuDataType_t*)pyju_type_type->body)->name);
}

STATIC_INLINE int pyju_is_array_zeroinit(PyjuArray_t *a) PYJU_NOTSAFEPOINT
{
    if (a->flags.ptrarray || a->flags.hasptr)
        return 1;
    PyjuValue_t *elty = pyju_tparam0(pyju_typeof(a));
    return pyju_is_datatype(elty) && ((PyjuDataType_t*)elty)->zeroinit;
}

PYJU_DLLEXPORT PyjuSym_t *pyju_symbol(const char *str) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuSym_t *pyju_symbol_lookup(const char *str) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuSym_t *pyju_symbol_n(const char *str, size_t len) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuSym_t *pyju_gensym(void);
PYJU_DLLEXPORT PyjuSym_t *pyju_tagged_gensym(const char *str, size_t len);
PYJU_DLLEXPORT PyjuSym_t *pyju_get_root_symbol(void);

PYJU_DLLEXPORT void *pyju_symbol_name(PyjuSym_t *s);
// inline version with strong type check to detect typos in a `->name` chain
STATIC_INLINE char *pyju_symbol_name_(PyjuSym_t* s) PYJU_NOTSAFEPOINT
{
    return (char*)s + LLT_ALIGN(sizeof(PyjuSym_t), sizeof(void*));
}
#define pyju_symbol_name(s) pyju_symbol_name_(s)

static inline uint32_t pyju_fielddesc_size(int8_t fielddesc_type) PYJU_NOTSAFEPOINT
{
    assert(fielddesc_type >= 0 && fielddesc_type <= 2);
    return 2 << fielddesc_type;
    //if (fielddesc_type == 0) {
    //    return sizeof(PyjuFieldDesc8_t);
    //}
    //else if (fielddesc_type == 1) {
    //    return sizeof(PyjuFieldDesc16_t);
    //}
    //else {
    //    return sizeof(PyjuFieldDesc32_t);
    //}
}

#define pyju_dt_layout_fields(d) ((const char*)(d) + sizeof(PyjuDataTypeLayout_t))
static inline const char *pyju_dt_layout_ptrs(const PyjuDataTypeLayout_t *ly) PYJU_NOTSAFEPOINT
{
    return pyju_dt_layout_fields(ly) + pyju_fielddesc_size(ly->fielddesc_type) * ly->nfields;
}

#define DEFINE_FIELD_ACCESSORS(f)                                             \
    static inline uint32_t pyju_field_##f(PyjuDataType_t *st,                    \
                                        int i) PYJU_NOTSAFEPOINT                \
    {                                                                         \
        const PyjuDataTypeLayout_t *ly = st->layout;                          \
        assert(i >= 0 && (size_t)i < ly->nfields);                            \
        if (ly->fielddesc_type == 0) {                                        \
            return ((const PyjuFieldDesc8_t*)pyju_dt_layout_fields(ly))[i].f;    \
        }                                                                     \
        else if (ly->fielddesc_type == 1) {                                   \
            return ((const PyjuFieldDesc16_t*)pyju_dt_layout_fields(ly))[i].f;   \
        }                                                                     \
        else {                                                                \
            assert(ly->fielddesc_type == 2);                                  \
            return ((const PyjuFieldDesc32_t*)pyju_dt_layout_fields(ly))[i].f;   \
        }                                                                     \
    }                                                                         \

DEFINE_FIELD_ACCESSORS(offset)
DEFINE_FIELD_ACCESSORS(size)
#undef DEFINE_FIELD_ACCESSORS

static inline int pyju_field_isptr(PyjuDataType_t *st, int i) PYJU_NOTSAFEPOINT
{
    const PyjuDataTypeLayout_t *ly = st->layout;
    assert(i >= 0 && (size_t)i < ly->nfields);
    // TODO: 小端时没有这样转换，in little-endian, isptr is always the first bit,
    // 但是在大端环境下isptr就不是第一个bit了，这个不会有问题吗？
    return ((const PyjuFieldDesc8_t*)(pyju_dt_layout_fields(ly) + pyju_fielddesc_size(ly->fielddesc_type) * i))->isptr;
}

static inline uint32_t pyju_ptr_offset(PyjuDataType_t *st, int i) PYJU_NOTSAFEPOINT
{
    const PyjuDataTypeLayout_t *ly = st->layout;
    assert(i >= 0 && (size_t)i < ly->nfields);
    const void *ptrs = pyju_dt_layout_ptrs(ly);
    if (ly->fielddesc_type == 0) {
        return ((const uint8_t*)ptrs)[i];
    }
    else if (ly->fielddesc_type == 1) {
        return ((const uint16_t*)ptrs)[i];
    }
    else {
        assert(ly->fielddesc_type == 2);
        return ((const uint32_t*)ptrs)[i];
    }
}

static inline int pyju_field_isatomic(PyjuDataType_t *st, int i) PYJU_NOTSAFEPOINT
{
    const uint32_t *atomicfields = st->name->atomicfields;
    if (atomicfields != NULL) {
        if (atomicfields[i/32] & (1 << (i %32)))
            return 1;
    }
    return 0;
}

static inline int pyju_field_isconst(PyjuDataType_t *st, int i) PYJU_NOTSAFEPOINT
{
    PyjuTypeName_t *tn = st->name;
    if (!tn->mutabl)
        return 1;
    const uint32_t *constfields = tn->constfields;
    if (constfields != NULL) {
        if (constfields[i / 32] & (1 << (i % 32)))
            return 1;
    }
    return 0;
}

static inline int pyju_is_layout_opaque(const PyjuDataTypeLayout_t *l) PYJU_NOTSAFEPOINT
{
    return l->nfields == 0 && l->npointers > 0;
}

PYJU_DLLEXPORT PyjuValue_t *pyju_box_bool(int8_t x) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_box_int8(int8_t x) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_box_uint8(uint8_t x) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_box_int16(int16_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_uint16(uint16_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_int32(int32_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_uint32(uint32_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_char(uint32_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_int64(int64_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_uint64(uint64_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_float32(float x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_float64(double x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_voidpointer(void *x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_uint8pointer(uint8_t *x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_ssavalue(size_t x);
PYJU_DLLEXPORT PyjuValue_t *pyju_box_slotnumber(size_t x);
PYJU_DLLEXPORT int8_t pyju_unbox_bool(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int8_t pyju_unbox_int8(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT uint8_t pyju_unbox_uint8(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int16_t pyju_unbox_int16(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT uint16_t pyju_unbox_uint16(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int32_t pyju_unbox_int32(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT uint32_t pyju_unbox_uint32(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int64_t pyju_unbox_int64(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT uint64_t pyju_unbox_uint64(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT float pyju_unbox_float32(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT double pyju_unbox_float64(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void *pyju_unbox_voidpointer(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT uint8_t *pyju_unbox_uint8pointer(PyjuValue_t *v) PYJU_NOTSAFEPOINT;

PYJU_DLLEXPORT int pyju_get_size(PyjuValue_t *val, size_t *pnt);

#ifdef _P64
#define pyju_box_long(x)   pyju_box_int64(x)
#define pyju_box_ulong(x)  pyju_box_uint64(x)
#define pyju_unbox_long(x) pyju_unbox_int64(x)
#define pyju_unbox_ulong(x) pyju_unbox_uint64(x)
#define pyju_is_long(x)    pyju_is_int64(x)
#define pyju_is_ulong(x)   pyju_is_uint64(x)
#define pyju_long_type     pyju_int64_type
#define pyju_ulong_type    pyju_uint64_type
#else
#define pyju_box_long(x)   pyju_box_int32(x)
#define pyju_box_ulong(x)  pyju_box_uint32(x)
#define pyju_unbox_long(x) pyju_unbox_int32(x)
#define pyju_unbox_ulong(x) pyju_unbox_uint32(x)
#define pyju_is_long(x)    pyju_is_int32(x)
#define pyju_is_ulong(x)   pyju_is_uint32(x)
#define pyju_long_type     pyju_int32_type
#define pyju_ulong_type    pyju_uint32_type
#endif

// structs
PYJU_DLLEXPORT int         pyju_field_index(PyjuDataType_t *t, PyjuSym_t *fld, int err);
PYJU_DLLEXPORT PyjuValue_t *pyju_get_nth_field(PyjuValue_t *v, size_t i);
// Like pyju_get_nth_field above, but asserts if it needs to allocate
PYJU_DLLEXPORT PyjuValue_t *pyju_get_nth_field_noalloc(PyjuValue_t *v PYJU_PROPAGATES_ROOT, size_t i) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_get_nth_field_checked(PyjuValue_t *v, size_t i);
PYJU_DLLEXPORT void        pyju_set_nth_field(PyjuValue_t *v, size_t i, PyjuValue_t *rhs) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int         pyju_field_isdefined(PyjuValue_t *v, size_t i) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT PyjuValue_t *pyju_get_field(PyjuValue_t *o, const char *fld);
PYJU_DLLEXPORT PyjuValue_t *pyju_value_ptr(PyjuValue_t *a);
int pyju_uniontype_size(PyjuValue_t *ty, size_t *sz);
PYJU_DLLEXPORT int pyju_islayout_inline(PyjuValue_t *eltype, size_t *fsz, size_t *al);


#define PYJU_TYPECHK(fname, type, v)                                 \
    if (!pyju_is_##type(v)) {                                        \
        pyju_type_error(#fname, (PyjuValue_t*)pyju_##type##_type, (v)); \
    }
#define PYJU_TYPECHKS(fname, type, v)                                     \
    if (!pyju_is_##type(v)) {                                             \
        pyju_type_error(fname, (PyjuValue_t*)pyju_##type##_type, (v));       \
    }

// constructors
PYJU_DLLEXPORT PyjuValue_t *pyju_new_bits(PyjuValue_t *bt, const void *src);
PYJU_DLLEXPORT PyjuValue_t *pyju_atomic_new_bits(PyjuValue_t *dt, const char *src);
PYJU_DLLEXPORT void pyju_atomic_store_bits(char *dst, const PyjuValue_t *src, int nb);
PYJU_DLLEXPORT PyjuValue_t *pyju_atomic_swap_bits(PyjuValue_t *dt, char *dst, const PyjuValue_t *src, int nb);
PYJU_DLLEXPORT int pyju_atomic_bool_cmpswap_bits(char *dst, const PyjuValue_t *expected, const PyjuValue_t *src, int nb);
PYJU_DLLEXPORT PyjuValue_t *pyju_atomic_cmpswap_bits(PyjuDataType_t *dt, PyjuDataType_t *rettype, char *dst, const PyjuValue_t *expected, const PyjuValue_t *src, int nb);
PYJU_DLLEXPORT PyjuValue_t *pyju_new_struct(PyjuDataType_t *type, ...);
PYJU_DLLEXPORT PyjuValue_t *pyju_new_structv(PyjuDataType_t *type, PyjuValue_t **args, uint32_t na);
PYJU_DLLEXPORT PyjuValue_t *pyju_new_structt(PyjuDataType_t *type, PyjuValue_t *tup);
PYJU_DLLEXPORT PyjuValue_t *pyju_new_struct_uninit(PyjuDataType_t *type);
PYJU_DLLEXPORT PyjuSvec_t *pyju_svec(size_t n, ...) PYJU_MAYBE_UNROOTED;
PYJU_DLLEXPORT PyjuSvec_t *pyju_svec1(void *a);
PYJU_DLLEXPORT PyjuSvec_t *pyju_svec2(void *a, void *b);
PYJU_DLLEXPORT PyjuSvec_t *pyju_alloc_svec(size_t n);
PYJU_DLLEXPORT PyjuSvec_t *pyju_alloc_svec_uninit(size_t n);
PYJU_DLLEXPORT PyjuSvec_t *pyju_svec_copy(PyjuSvec_t *a);
PYJU_DLLEXPORT PyjuSvec_t *pyju_svec_fill(size_t n, PyjuValue_t *x);

// type constructors
PYJU_DLLEXPORT PyjuTypeName_t *pyju_new_typename_in(PyjuSym_t *name, PyjuModule_t *inmodule, int abstract, int mutabl);
PYJU_DLLEXPORT PyjuValue_t *pyju_apply_type(PyjuValue_t *tc, PyjuValue_t **params, size_t n);
PYJU_DLLEXPORT PyjuValue_t *pyju_apply_type1(PyjuValue_t *tc, PyjuValue_t *p1);
PYJU_DLLEXPORT PyjuValue_t *pyju_apply_type2(PyjuValue_t *tc, PyjuValue_t *p1, PyjuValue_t *p2);
PYJU_DLLEXPORT PyjuDataType_t *pyju_apply_modify_type(PyjuValue_t *dt);
PYJU_DLLEXPORT PyjuDataType_t *pyju_new_datatype(PyjuSym_t *name,
                                            PyjuModule_t *module,
                                            PyjuDataType_t *super,
                                            PyjuSvec_t *parameters,
                                            PyjuSvec_t *fnames,
                                            PyjuSvec_t *ftypes,
                                            PyjuSvec_t *fattrs,
                                            int abstract, int mutabl,
                                            int ninitialized);
PYJU_DLLEXPORT PyjuTVar_t *pyju_new_typevar(PyjuSym_t *name, PyjuValue_t *lb, PyjuValue_t *ub);
PYJU_DLLEXPORT const char *pyju_typename_str(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT const char *pyju_typeof_str(PyjuValue_t *v) PYJU_NOTSAFEPOINT;

STATIC_INLINE int pyju_is_concrete_type(PyjuValue_t *v) PYJU_NOTSAFEPOINT
{
    return pyju_is_datatype(v) && ((PyjuDataType_t*)v)->isconcretetype;
}
PYJU_DLLEXPORT PyjuTupleType_t *pyju_apply_tuple_type(PyjuSvec_t *params);
PYJU_DLLEXPORT PyjuValue_t *pyju_tupletype_fill(size_t n, PyjuValue_t *v);

// object identity
PYJU_DLLEXPORT int pyju_egal(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_egal__bits(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_egal__special(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT int pyju_egal__unboxed(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT uintptr_t pyju_object_id(PyjuValue_t *v) PYJU_NOTSAFEPOINT;

STATIC_INLINE int pyju_egal__unboxed_(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED, PyjuDataType_t *dt) PYJU_NOTSAFEPOINT
{
    if (dt->name->mutabl) {
        if (dt == pyju_simplevector_type || dt == pyju_string_type || dt == pyju_datatype_type)
            return pyju_egal__special(a, b, dt);
        return 0;
    }
    return pyju_egal__bits(a, b, dt);
}

STATIC_INLINE int pyju_egal_(const PyjuValue_t *a PYJU_MAYBE_UNROOTED, const PyjuValue_t *b PYJU_MAYBE_UNROOTED) PYJU_NOTSAFEPOINT
{
    if (a == b)
        return 1;
    PyjuDataType_t *dt = (PyjuDataType_t*)pyju_typeof(a);
    if (dt != (PyjuDataType_t*)pyju_typeof(b))
        return 0;
    return pyju_egal__unboxed_(a, b, dt);
}
#define pyju_egal(a, b) pyju_egal_((a), (b))

// type predicates and basic operations
PYJU_DLLEXPORT int pyju_types_equal(PyjuValue_t *a, PyjuValue_t *b);
PYJU_DLLEXPORT int pyju_isa(PyjuValue_t *x, PyjuValue_t *t);
PYJU_DLLEXPORT int pyju_type_equality_is_identity(PyjuValue_t *t1, PyjuValue_t *t2);


#define pyju_fieldref(s,i) pyju_get_nth_field(((PyjuValue_t*)(s)),i)
#define pyju_fieldref_noalloc(s,i) pyju_get_nth_field_noalloc(((PyjuValue_t*)(s)),i)
#define pyju_nfields(v)    pyju_datatype_nfields(pyju_typeof(v))


PYJU_DLLEXPORT void PYJU_NORETURN pyju_bounds_error_int(PyjuValue_t *v PYJU_MAYBE_UNROOTED,
                                                  size_t i);

PYJU_DLLEXPORT PyjuArray_t *pyju_alloc_vec_any(size_t n);


PYJU_DLLEXPORT int pyju_has_free_typevars(PyjuValue_t *v) PYJU_NOTSAFEPOINT;
PyjuDataType_t *pyju_wrap_Type(PyjuValue_t *t);

#ifdef __cplusplus
}
#endif
