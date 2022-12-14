#include "pyju.h"
#include "pyju_internal.h"

#include <llvm/ADT/StringMap.h>
#include <llvm/DebugInfo/DIContext.h>
#include <llvm/IR/DataLayout.h>

#include <mutex>
#include <map>
#include <type_traits>

typedef struct {
    const llvm::object::ObjectFile *obj;
    llvm::DIContext *ctx;
    int64_t slide;
} objfileentry_t;

// Central registry for resolving function addresses to `jl_method_instance_t`s and
// originating `ObjectFile`s (for the DWARF debug info).
//
// A global singleton instance is notified by the JIT whenever a new object is emitted,
// and later queried by the various function info APIs. We also use the chance to handle
// some platform-specific unwind info registration (which is unrelated to the query
// functionality).
class JITDebugInfoRegistry
{
public:
    template<typename ResourceT>
    struct Locked {

        template<typename CResourceT>
        struct Lock {
            std::unique_lock<std::mutex> lock;
            CResourceT &resource;

            Lock(std::mutex &mutex, CResourceT &resource) PYJU_NOTSAFEPOINT : lock(mutex), resource(resource) {}
            Lock(Lock &&) PYJU_NOTSAFEPOINT = default;
            Lock &operator=(Lock &&) PYJU_NOTSAFEPOINT = default;

            CResourceT &operator*() PYJU_NOTSAFEPOINT {
                return resource;
            }

            const CResourceT &operator*() const PYJU_NOTSAFEPOINT {
                return resource;
            }

            CResourceT *operator->() PYJU_NOTSAFEPOINT {
                return &**this;
            }

            const CResourceT *operator->() const PYJU_NOTSAFEPOINT {
                return &**this;
            }

            operator const CResourceT &() const PYJU_NOTSAFEPOINT {
                return resource;
            }

            ~Lock() PYJU_NOTSAFEPOINT = default;
        };
    private:

        mutable std::mutex mutex;
        ResourceT resource;
    public:
        typedef Lock<ResourceT> LockT;
        typedef Lock<const ResourceT> ConstLockT;

        Locked(ResourceT resource = ResourceT()) PYJU_NOTSAFEPOINT : mutex(), resource(std::move(resource)) {}

        LockT operator*() PYJU_NOTSAFEPOINT {
            return LockT(mutex, resource);
        }

        ConstLockT operator*() const PYJU_NOTSAFEPOINT {
            return ConstLockT(mutex, resource);
        }

        ~Locked() PYJU_NOTSAFEPOINT = default;
    };

    template<typename datatype>
    struct pyju_pthread_key_t {
        static_assert(std::is_trivially_default_constructible<datatype>::value, "Invalid datatype for pthread key!");
        static_assert(std::is_trivially_destructible<datatype>::value, "Expected datatype to be trivially destructible!");
        static_assert(sizeof(datatype) == sizeof(void*), "Expected datatype to be like a void*!");
        pthread_key_t key;

        void init() PYJU_NOTSAFEPOINT {
            if (pthread_key_create(&key, NULL))
                pyju_error("fatal: pthread_key_create failed");
        }

        operator datatype() PYJU_NOTSAFEPOINT {
            return reinterpret_cast<datatype>(pthread_getspecific(key));
        }

        pyju_pthread_key_t &operator=(datatype val) PYJU_NOTSAFEPOINT {
            pthread_setspecific(key, reinterpret_cast<void*>(val));
            return *this;
        }

        void destroy() PYJU_NOTSAFEPOINT {
            pthread_key_delete(key);
        }
    };

    struct sysimg_info_t {
        uint64_t jl_sysimage_base;
        // pyju_sysimg_fptrs_t sysimg_fptrs;
        PyjuMethodInstance_t **sysimg_fvars_linfo;
        size_t sysimg_fvars_n;
    };

    struct libc_frames_t {
#if defined(_OS_DARWIN_) && defined(LLVM_SHLIB)
        std::atomic<void(*)(void*)> libc_register_frame_{nullptr};
        std::atomic<void(*)(void*)> libc_deregister_frame_{nullptr};

        void libc_register_frame(const char *Entry) JL_NOTSAFEPOINT;

        void libc_deregister_frame(const char *Entry) JL_NOTSAFEPOINT;
#endif
    };
private:

    struct ObjectInfo {
        const llvm::object::ObjectFile *object = nullptr;
        size_t SectionSize = 0;
        ptrdiff_t slide = 0;
        llvm::object::SectionRef Section{};
        llvm::DIContext *context = nullptr;
    };

    template<typename KeyT, typename ValT>
    using rev_map = std::map<KeyT, ValT, std::greater<KeyT>>;

    typedef rev_map<size_t, ObjectInfo> objectmap_t;
    typedef rev_map<uint64_t, objfileentry_t> objfilemap_t;

    objectmap_t objectmap{};
    rev_map<size_t, std::pair<size_t, PyjuMethodInstance_t *>> linfomap{};

    // Maintain a mapping of unrealized function names -> linfo objects
    // so that when we see it get emitted, we can add a link back to the linfo
    // that it came from (providing name, type signature, file info, etc.)
    Locked<llvm::StringMap<PyjuCodeInstance_t*>> codeinst_in_flight{};

    Locked<sysimg_info_t> sysimg_info{};

    Locked<objfilemap_t> objfilemap{};

    static std::string mangle(llvm::StringRef Name, const llvm::DataLayout &DL) PYJU_NOTSAFEPOINT;

public:

    JITDebugInfoRegistry() PYJU_NOTSAFEPOINT;
    ~JITDebugInfoRegistry() PYJU_NOTSAFEPOINT = default;

    // Any function that acquires this lock must be either a unmanaged thread
    // or in the GC safe region and must NOT allocate anything through the GC
    // while holding this lock.
    // Certain functions in this file might be called from an unmanaged thread
    // and cannot have any interaction with the julia runtime
    // They also may be re-entrant, and operating while threads are paused, so we
    // separately manage the re-entrant count behavior for safety across platforms
    // Note that we cannot safely upgrade read->write
    uv_rwlock_t debuginfo_asyncsafe{};
    pyju_pthread_key_t<uintptr_t> debuginfo_asyncsafe_held{};
    libc_frames_t libc_frames{};

    void add_code_in_flight(llvm::StringRef name, PyjuCodeInstance_t *codeinst, const llvm::DataLayout &DL) PYJU_NOTSAFEPOINT;
    PyjuMethodInstance_t *lookupLinfo(size_t pointer) PYJU_NOTSAFEPOINT;
    void registerJITObject(const llvm::object::ObjectFile &Object,
                        std::function<uint64_t(const llvm::StringRef &)> getLoadAddress,
                        std::function<void*(void*)> lookupWriteAddress) PYJU_NOTSAFEPOINT;
    objectmap_t& getObjectMap() PYJU_NOTSAFEPOINT;
    void set_sysimg_info(sysimg_info_t info) PYJU_NOTSAFEPOINT;
    Locked<sysimg_info_t>::ConstLockT get_sysimg_info() const PYJU_NOTSAFEPOINT;
    Locked<objfilemap_t>::LockT get_objfile_map() PYJU_NOTSAFEPOINT;
};