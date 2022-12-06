#include "support/platform.h"

#include <iostream>

#if defined(_OS_LINUX_)
#  include <link.h>
#endif

// #include <llvm/DebugInfo/DWARF/DWARFContext.h>

#include "llvm/Object/ObjectFile.h"
#include <llvm/Object/SymbolSize.h>

#include "llvm/IR/Mangler.h"

#include "jitlayers.h"

using namespace llvm;

static JITDebugInfoRegistry &getJITDebugRegistry() PYJU_NOTSAFEPOINT {
    return pyju_ExecutionEngine->getDebugInfoRegistry();
}


struct debug_link_info {
    StringRef filename;
    uint32_t crc32;
};


extern "C" PYJU_DLLEXPORT void pyju_lock_profile_impl(void) PYJU_NOTSAFEPOINT;
extern "C" PYJU_DLLEXPORT void pyju_unlock_profile_impl(void) PYJU_NOTSAFEPOINT;

template <typename T>
static void pyju_profile_atomic(T f);


#if (defined(_OS_LINUX_) || defined(_OS_FREEBSD_) || (defined(_OS_DARWIN_) && defined(LLVM_SHLIB)))
extern "C" void __register_frame(void*);
extern "C" void __deregister_frame(void*);

template <typename callback>
static void processFDEs(const char *EHFrameAddr, size_t EHFrameSize, callback f)
{
    const char *P = EHFrameAddr;
    const char *End = P + EHFrameSize;
    do {
        const char *Entry = P;
        P += 4;
        assert(P <= End);
        uint32_t Length = *(const uint32_t*)Entry;
        // Length == 0: Terminator
        if (Length == 0)
            break;
        assert(P + Length <= End);
        uint32_t Offset = *(const uint32_t*)P;
        // Offset == 0: CIE
        if (Offset != 0)
            f(Entry);
        P += Length;
    } while (P != End);
}
#endif

std::string JITDebugInfoRegistry::mangle(StringRef Name, const DataLayout &DL) PYJU_NOTSAFEPOINT
{
    std::string MangledName;
    {
        raw_string_ostream MangledNameStream(MangledName);
        Mangler::getNameWithPrefix(MangledNameStream, Name, DL);
    }
    return MangledName;
}

void JITDebugInfoRegistry::add_code_in_flight(StringRef name, PyjuCodeInstance_t *codeinst, const DataLayout &DL) PYJU_NOTSAFEPOINT {
    (**codeinst_in_flight)[mangle(name, DL)] = codeinst;
}


PyjuMethodInstance_t *JITDebugInfoRegistry::lookupLinfo(size_t pointer) PYJU_NOTSAFEPOINT
{
    pyju_lock_profile_impl();
    auto region = linfomap.lower_bound(pointer);
    PyjuMethodInstance_t *linfo = NULL;
    if (region != linfomap.end() && pointer < region->first + region->second.first)
        linfo = region->second.second;
    pyju_unlock_profile_impl();
    return linfo;
}

//Protected by debuginfo_asyncsafe
JITDebugInfoRegistry::objectmap_t &
JITDebugInfoRegistry::getObjectMap() PYJU_NOTSAFEPOINT
{
    return objectmap;
}

void JITDebugInfoRegistry::set_sysimg_info(sysimg_info_t info) PYJU_NOTSAFEPOINT {
    (**this->sysimg_info) = info;
}

JITDebugInfoRegistry::Locked<JITDebugInfoRegistry::sysimg_info_t>::ConstLockT
JITDebugInfoRegistry::get_sysimg_info() const PYJU_NOTSAFEPOINT {
    return *this->sysimg_info;
}

JITDebugInfoRegistry::Locked<JITDebugInfoRegistry::objfilemap_t>::LockT
JITDebugInfoRegistry::get_objfile_map() PYJU_NOTSAFEPOINT {
    return *this->objfilemap;
}

JITDebugInfoRegistry::JITDebugInfoRegistry() PYJU_NOTSAFEPOINT {
    uv_rwlock_init(&debuginfo_asyncsafe);
    debuginfo_asyncsafe_held.init();
}

struct unw_table_entry
{
    int32_t start_ip_offset;
    int32_t fde_offset;
};

extern "C" PYJU_DLLEXPORT void pyju_lock_profile_impl(void) PYJU_NOTSAFEPOINT
{
    uintptr_t held = getJITDebugRegistry().debuginfo_asyncsafe_held;
    if (held++ == 0)
        uv_rwlock_rdlock(&getJITDebugRegistry().debuginfo_asyncsafe);
    getJITDebugRegistry().debuginfo_asyncsafe_held = held;
}

extern "C" PYJU_DLLEXPORT void pyju_unlock_profile_impl(void) PYJU_NOTSAFEPOINT
{
    uintptr_t held = getJITDebugRegistry().debuginfo_asyncsafe_held;
    assert(held);
    if (--held == 0)
        uv_rwlock_rdunlock(&getJITDebugRegistry().debuginfo_asyncsafe);
    getJITDebugRegistry().debuginfo_asyncsafe_held = held;
}

// some actions aren't signal (especially profiler) safe so we acquire a lock
// around them to establish a mutual exclusion with unwinding from a signal
template <typename T>
static void pyju_profile_atomic(T f)
{
    assert(0 == getJITDebugRegistry().debuginfo_asyncsafe_held);
    uv_rwlock_wrlock(&getJITDebugRegistry().debuginfo_asyncsafe);
#ifndef _OS_WINDOWS_
    sigset_t sset;
    sigset_t oset;
    sigfillset(&sset);
    pthread_sigmask(SIG_BLOCK, &sset, &oset);
#endif
    f();
#ifndef _OS_WINDOWS_
    pthread_sigmask(SIG_SETMASK, &oset, NULL);
#endif
    uv_rwlock_wrunlock(&getJITDebugRegistry().debuginfo_asyncsafe);
}

// --- storing and accessing source location metadata ---
void pyju_add_code_in_flight(StringRef name, PyjuCodeInstance_t *codeinst, const DataLayout &DL)
{
    getJITDebugRegistry().add_code_in_flight(name, codeinst, DL);
}


void JITDebugInfoRegistry::registerJITObject(const object::ObjectFile &Object,
                        std::function<uint64_t(const StringRef &)> getLoadAddress,
                        std::function<void*(void*)> lookupWriteAddress)
{
    PyjuPtls_t ptls = pyju_current_task->ptls;
    // This function modify codeinst->fptr in GC safe region.
    // This should be fine since the GC won't scan this field.
    int8_t gc_state = pyju_gc_safe_enter(ptls);

    object::section_iterator EndSection = Object.section_end();


    auto symbols = object::computeSymbolSizes(Object);
    bool first = true;
    for (const auto &sym_size : symbols) {
        const object::SymbolRef &sym_iter = sym_size.first;
        object::SymbolRef::Type SymbolType = cantFail(sym_iter.getType());
        if (SymbolType != object::SymbolRef::ST_Function) continue;
        uint64_t Addr = cantFail(sym_iter.getAddress());
        auto Section = cantFail(sym_iter.getSection());
        if (Section == EndSection) continue;
        if (!Section->isText()) continue;
        uint64_t SectionAddr = Section->getAddress();
        StringRef secName = cantFail(Section->getName());
        uint64_t SectionLoadAddr = getLoadAddress(secName);
        Addr -= SectionAddr - SectionLoadAddr;
        StringRef sName = cantFail(sym_iter.getName());
        uint64_t SectionSize = Section->getSize();
        size_t Size = sym_size.second;

        PyjuCodeInstance_t *codeinst = NULL;
        {
            auto lock = *this->codeinst_in_flight;
            auto &codeinst_in_flight = *lock;
            StringMap<PyjuCodeInstance_t*>::iterator codeinst_it = codeinst_in_flight.find(sName);
            if (codeinst_it != codeinst_in_flight.end()) {
                codeinst = codeinst_it->second;
                codeinst_in_flight.erase(codeinst_it);
            }
        }
        pyju_profile_atomic([&]() {
            if (codeinst)
                linfomap[Addr] = std::make_pair(Size, codeinst->def);
            if (first) {
                objectmap[SectionLoadAddr] = {&Object,
                    (size_t)SectionSize,
                    (ptrdiff_t)(SectionAddr - SectionLoadAddr),
                    *Section,
                    nullptr,
                    };
                first = false;
            }
        });
    }
    pyju_gc_safe_leave(ptls, gc_state);
}

void pyju_register_jit_object(const object::ObjectFile &Object,
                            std::function<uint64_t(const StringRef &)> getLoadAddress,
                            std::function<void *(void *)> lookupWriteAddress)
{
    getJITDebugRegistry().registerJITObject(Object, getLoadAddress, lookupWriteAddress);
}

// TODO: convert the safe names from aotcomile.cpp:makeSafeName back into symbols
static std::pair<char *, bool> pyju_demangle(const char *name) PYJU_NOTSAFEPOINT
{
    // This function is not allowed to reference any TLS variables since
    // it can be called from an unmanaged thread on OSX.
    const char *start = name + 6;
    const char *end = name + strlen(name);
    char *ret;
    if (end <= start)
        goto done;
    if (strncmp(name, "japi1_", 6) &&
        strncmp(name, "japi3_", 6) &&
        strncmp(name, "julia_", 6) &&
        strncmp(name, "jsys1_", 6) &&
        strncmp(name, "jlsys_", 6))
        goto done;
    if (*start == '\0')
        goto done;
    while (*(--end) != '_') {
        char c = *end;
        if (c < '0' || c > '9')
            goto done;
    }
    if (end <= start)
        goto done;
    ret = (char*)malloc_s(end - start + 1);
    memcpy(ret, start, end - start);
    ret[end - start] = '\0';
    return std::make_pair(ret, true);
done:
    return std::make_pair(strdup(name), false);
}

// int pyju_DI_for_fptr(uint64_t fptr, uint64_t *symsize, int64_t *slide,
//         object::SectionRef *Section, llvm::DIContext **context) PYJU_NOTSAFEPOINT
// {
//     int found = 0;
//     assert(0 == getJITDebugRegistry().debuginfo_asyncsafe_held);
//     uv_rwlock_wrlock(&getJITDebugRegistry().debuginfo_asyncsafe);
//     if (symsize)
//         *symsize = 0;

//     auto &objmap = getJITDebugRegistry().getObjectMap();
//     auto fit = objmap.lower_bound(fptr);
//     if (fit != objmap.end() && fptr < fit->first + fit->second.SectionSize) {
//         *slide = fit->second.slide;
//         *Section = fit->second.Section;
//         if (context) {
//             if (fit->second.context == nullptr)
//                 fit->second.context = DWARFContext::create(*fit->second.object).release();
//             *context = fit->second.context;
//         }
//         found = 1;
//     }
//     uv_rwlock_wrunlock(&getJITDebugRegistry().debuginfo_asyncsafe);
//     return found;
// }

// // Set *name and *filename to either NULL or malloc'd string
// extern "C" PYJU_DLLEXPORT int pyju_getFunctionInfo_impl(pyju_frame_t **frames_out, size_t pointer, int skipC, int noInline) PYJU_NOTSAFEPOINT
// {
//     // This function is not allowed to reference any TLS variables if noInline
//     // since it can be called from an unmanaged thread on OSX.

//     pyju_frame_t *frames = (pyju_frame_t*)calloc(sizeof(pyju_frame_t), 1);
//     frames[0].line = -1;
//     *frames_out = frames;

//     llvm::DIContext *context;
//     object::SectionRef Section;
//     int64_t slide;
//     uint64_t symsize;
//     if (pyju_DI_for_fptr(pointer, &symsize, &slide, &Section, &context)) {
//         frames[0].linfo = getJITDebugRegistry().lookupLinfo(pointer);
//         int nf = lookup_pointer(Section, context, frames_out, pointer, slide, true, noInline);
//         return nf;
//     }
//     return pyju_getDylibFunctionInfo(frames_out, pointer, skipC, noInline);
// }

extern "C" PyjuMethodInstance_t *pyju_gdblookuplinfo(void *p) PYJU_NOTSAFEPOINT
{
    return getJITDebugRegistry().lookupLinfo((size_t)p);
}

#include <type_traits>

// Skip over an arbitrary long LEB128 encoding.
// Return the pointer to the first unprocessed byte.
static const uint8_t *consume_leb128(const uint8_t *Addr, const uint8_t *End)
{
    const uint8_t *P = Addr;
    while ((*P >> 7) != 0 && P < End)
        ++P;
    return P + 1;
}

// Parse a LEB128 encoding to a type T. Truncate the result if there's more
// bytes than what there are more bytes than what the type can store.
// Adjust the pointer to the first unprocessed byte.
template<typename T> static T parse_leb128(const uint8_t *&Addr,
                                           const uint8_t *End)
{
    typedef typename std::make_unsigned<T>::type uT;
    uT v = 0;
    for (unsigned i = 0;i < ((sizeof(T) * 8 - 1) / 7 + 1);i++) {
        uint8_t a = *Addr;
        Addr++;
        v |= uT(a & 0x7f) << (i * 7);
        if ((a & 0x80) == 0 || Addr >= End) {
            if (a & 0x40 && std::is_signed<T>::value) {
                int valid_bits = (i + 1) * 7;
                if (valid_bits < 64) {
                    v |= -(uT(1) << valid_bits);
                }
            }
            return T(v);
        }
    }
    Addr = consume_leb128(Addr, End);
    return T(v);
}

template <typename U, typename T>
static U safe_trunc(T t)
{
    assert((t >= static_cast<T>(std::numeric_limits<U>::min()))
           && (t <= static_cast<T>(std::numeric_limits<U>::max())));
    return static_cast<U>(t);
}


// How the address and size in the FDE are encoded.
enum DW_EH_PE : uint8_t {
    DW_EH_PE_absptr = 0x00, /* An absolute pointer. The size is determined by
                             * whether this is a 32-bit or 64-bit address space,
                             * and will be 32 or 64 bits */
    DW_EH_PE_omit = 0xff, // The value is omitted
    DW_EH_PE_uleb128 = 0x01, // The value is an unsigned LEB128
    DW_EH_PE_udata2 = 0x02,
    DW_EH_PE_udata4 = 0x03,
    DW_EH_PE_udata8 = 0x04, /* The value is stored as unsigned data with the
                             * specified number of bytes. */
    DW_EH_PE_signed = 0x08, /* A signed number. The size is determined by
                             * whether this is a 32-bit or 64-bit address space */
    DW_EH_PE_sleb128 = 0x09, /* A signed LEB128. */
    DW_EH_PE_sdata2 = 0x0a,
    DW_EH_PE_sdata4 = 0x0b,
    DW_EH_PE_sdata8 = 0x0c, /* The value is stored as signed data with the
                             * specified number of bytes. */

    // In addition the above basic encodings, there are modifiers.

    DW_EH_PE_pcrel = 0x10, // Value is PC relative.

    // We currently don't support the following once.
    DW_EH_PE_textrel = 0x20, // Value is text relative.
    DW_EH_PE_datarel = 0x30, // Value is data relative.
    DW_EH_PE_funcrel = 0x40, // Value is relative to start of function.
    DW_EH_PE_aligned = 0x50, /* Value is aligned: padding bytes are inserted as
                              * required to make value be naturally aligned. */
    DW_EH_PE_indirect = 0x80 /* This is actually the address of the real value. */
};


// Parse the CIE and return the type of encoding used by FDE
static DW_EH_PE parseCIE(const uint8_t *Addr, const uint8_t *End)
{
    // http://www.airs.com/blog/archives/460
    // Length (4 bytes)
    uint32_t cie_size = *(const uint32_t*)Addr;
    const uint8_t *cie_addr = Addr + 4;
    const uint8_t *p = cie_addr;
    const uint8_t *cie_end = cie_addr + cie_size;
    assert(cie_end <= End);
    // Check this is an CIE record (CIE ID: 4 bytes)
    assert(*(const uint32_t*)cie_addr == 0);
    p += 4;
    // Check CIE version (1 byte)
    uint8_t cie_version = *p;
    assert(cie_version == 1 || cie_version == 3);
    p++;
    // Augmentation String (NUL terminate)
    const char *augmentation = (const char*)p;
    size_t augmentation_len = strlen(augmentation);
    // Assume there's no EH Data field, which exist when the augmentation
    // string has "eh" in it.
    p += augmentation_len + 1;
    // Code Alignment Factor (1 byte)
    // should always be 1 on x86, 4 on PPC, etc.
    // (used for DW_CFA_advance_loc / not used here)
    //assert(*p == 1);
    p++;
    // Data Alignment Factor (LEB128)
    assert(cie_end >= p);
    p = consume_leb128(p, cie_end);
    // return address register
    if (cie_version == 1) {
        p++;
    }
    else {
        p = consume_leb128(p, cie_end);
    }
    // Now it's the augmentation data. which may have the information we
    // are interested in...
    for (const char *augp = augmentation;;augp++) {
        switch (*augp) {
        case 'z':
            // Augmentation Length
            p = consume_leb128(p, cie_end);
            break;
        case 'L':
            // LSDA encoding
            p++;
            break;
        case 'R':
            // .... the only one we care about ....
            return static_cast<DW_EH_PE>(*p);
        case 'P': {
            // Personality data
            // Encoding
            auto encoding = static_cast<DW_EH_PE>(*p);
            p++;
            // Personality function
            switch (encoding & 0xf) {
            case DW_EH_PE_uleb128:
            case DW_EH_PE_sleb128:
                p = consume_leb128(p, cie_end);
                break;
            case DW_EH_PE_udata2:
            case DW_EH_PE_sdata2:
                p += 2;
                break;
            case DW_EH_PE_udata4:
            case DW_EH_PE_sdata4:
                p += 4;
                break;
            case DW_EH_PE_udata8:
            case DW_EH_PE_sdata8:
                p += 8;
                break;
            case DW_EH_PE_signed:
                p += sizeof(void*);
                break;
            default:
                if (encoding == DW_EH_PE_absptr || encoding == DW_EH_PE_omit) {
                    p += sizeof(void*);
                }
                else {
                    assert(0 && "Invalid personality encoding.");
                }
                break;
            }
        }
            break;
        default:
            continue;
        }
        assert(cie_end >= p);
    }
    return DW_EH_PE_absptr;
}

void register_eh_frames(uint8_t *Addr, size_t Size)
{
    printf("not impl: register_eh_frames\n");
    // // System unwinder
    // pyju_profile_atomic([&]() {
    //     __register_frame(Addr);
    // });

    // // Now first count the number of FDEs
    // size_t nentries = 0;
    // processFDEs((char*)Addr, Size, [&](const char*){ nentries++; });
    // if (nentries == 0)
    //     return;

    // // Our unwinder
    // unw_dyn_info_t *di = new unw_dyn_info_t;
    // // In a shared library, this is set to the address of the PLT.
    // // For us, just put 0 to emulate a static library. This field does
    // // not seem to be used on our supported architectures.
    // di->gp = 0;
    // // I'm not a great fan of the naming of this constant, but it means the
    // // right thing, which is a table of FDEs and IPs.
    // di->format = UNW_INFO_FORMAT_IP_OFFSET;
    // di->u.rti.name_ptr = 0;
    // di->u.rti.segbase = (unw_word_t)Addr;

    // uintptr_t start_ip = (uintptr_t)-1;
    // uintptr_t end_ip = 0;

    // // Then allocate a table and fill in the information
    // // While we're at it, also record the start_ip and size,
    // // which we fill in the table
    // unw_table_entry *table = new unw_table_entry[nentries];
    // std::vector<uintptr_t> start_ips(nentries);
    // size_t cur_entry = 0;
    // // Cache the previously parsed CIE entry so that we can support multiple
    // // CIE's (may not happen) without parsing it every time.
    // const uint8_t *cur_cie = nullptr;
    // DW_EH_PE encoding = DW_EH_PE_omit;
    // processFDEs((char*)Addr, Size, [&](const char *Entry) {
    //         // Skip Length (4bytes) and CIE offset (4bytes)
    //         uint32_t fde_size = *(const uint32_t*)Entry;
    //         uint32_t cie_id = ((const uint32_t*)Entry)[1];
    //         const uint8_t *cie_addr = (const uint8_t*)(Entry + 4 - cie_id);
    //         if (cie_addr != cur_cie)
    //             encoding = parseCIE(cie_addr, Addr + Size);
    //         const uint8_t *fde_end = (const uint8_t*)(Entry + 4 + fde_size);
    //         const uint8_t *EntryPtr = (const uint8_t*)(Entry + 8);
    //         uintptr_t start = 0;
    //         uintptr_t size = 0;
    //         // The next two fields are address and size of the PC range
    //         // covered by this FDE.
    //         if (encoding == DW_EH_PE_absptr || encoding == DW_EH_PE_omit) {
    //             assert(fde_size >= 2 * sizeof(void*) + 4);
    //             start = *(const uintptr_t*)EntryPtr;
    //             size = *(const uintptr_t*)(EntryPtr + sizeof(void*));
    //         }
    //         else {
    //             uintptr_t baseptr = (uintptr_t)EntryPtr;
    //             // Only support pcrel for now...
    //             assert((encoding & 0xf0) == 0x10 &&
    //                    "Only pcrel mode is supported");
    //             switch (encoding & 0xf) {
    //             case DW_EH_PE_uleb128:
    //                 start = baseptr + parse_leb128<uintptr_t>(EntryPtr, fde_end);
    //                 size = parse_leb128<uintptr_t>(EntryPtr, fde_end);
    //                 break;
    //             case DW_EH_PE_udata2:
    //                 assert(fde_size >= 2 * 2 + 4);
    //                 start = baseptr + ((const uint16_t*)EntryPtr)[0];
    //                 size = ((const uint16_t*)EntryPtr)[1];
    //                 break;
    //             case DW_EH_PE_udata4:
    //                 assert(fde_size >= 2 * 4 + 4);
    //                 start = baseptr + ((const uint32_t*)EntryPtr)[0];
    //                 size = ((const uint32_t*)EntryPtr)[1];
    //                 break;
    //             case DW_EH_PE_udata8:
    //                 assert(fde_size >= 2 * 8 + 4);
    //                 start = uintptr_t(baseptr + ((const uint64_t*)EntryPtr)[0]);
    //                 size = uintptr_t(((const uint64_t*)EntryPtr)[1]);
    //                 break;
    //             case DW_EH_PE_signed:
    //                 assert(fde_size >= 2 * sizeof(void*) + 4);
    //                 start = baseptr + ((const intptr_t*)EntryPtr)[0];
    //                 size = ((const intptr_t*)EntryPtr)[1];
    //                 break;
    //             case DW_EH_PE_sleb128:
    //                 start = baseptr + parse_leb128<intptr_t>(EntryPtr, fde_end);
    //                 size = parse_leb128<intptr_t>(EntryPtr, fde_end);
    //                 break;
    //             case DW_EH_PE_sdata2:
    //                 assert(fde_size >= 2 * 2 + 4);
    //                 start = baseptr + ((const int16_t*)EntryPtr)[0];
    //                 size = ((const int16_t*)EntryPtr)[1];
    //                 break;
    //             case DW_EH_PE_sdata4:
    //                 assert(fde_size >= 2 * 4 + 4);
    //                 start = baseptr + ((const int32_t*)EntryPtr)[0];
    //                 size = ((const int32_t*)EntryPtr)[1];
    //                 break;
    //             case DW_EH_PE_sdata8:
    //                 assert(fde_size >= 2 * 8 + 4);
    //                 start = uintptr_t(baseptr + ((const int64_t*)EntryPtr)[0]);
    //                 size = uintptr_t(((const int64_t*)EntryPtr)[1]);
    //                 break;
    //             default:
    //                 assert(0 && "Invalid FDE encoding.");
    //                 break;
    //             }
    //         }

    //         if (start < start_ip)
    //             start_ip = start;
    //         if (end_ip < (start + size))
    //             end_ip = start + size;
    //         table[cur_entry].fde_offset =
    //             safe_trunc<int32_t>((intptr_t)Entry - (intptr_t)Addr);
    //         start_ips[cur_entry] = start;
    //         cur_entry++;
    //     });
    // for (size_t i = 0; i < nentries; i++) {
    //     table[i].start_ip_offset =
    //         safe_trunc<int32_t>((intptr_t)start_ips[i] - (intptr_t)start_ip);
    // }
    // assert(end_ip != 0);

    // di->u.rti.table_len = nentries * sizeof(*table) / sizeof(unw_word_t);
    // di->u.rti.table_data = (unw_word_t)table;
    // di->start_ip = start_ip;
    // di->end_ip = end_ip;

    // pyju_profile_atomic([&]() {
    //     _U_dyn_register(di);
    // });
}

void deregister_eh_frames(uint8_t *Addr, size_t Size)
{
    printf("not impl: deregister_eh_frames\n");
    // pyju_profile_atomic([&]() {
    //     __deregister_frame(Addr);
    // });

    // Deregistering with our unwinder (_U_dyn_cancel) requires a lookup table
    // to find the allocated entry above (or looking into libunwind's internal
    // data structures).
}


extern "C" PYJU_DLLEXPORT
uint64_t pyju_getUnwindInfo_impl(uint64_t dwAddr)
{
    // Might be called from unmanaged thread
    pyju_lock_profile_impl();
    auto &objmap = getJITDebugRegistry().getObjectMap();
    auto it = objmap.lower_bound(dwAddr);
    uint64_t ipstart = 0; // ip of the start of the section (if found)
    if (it != objmap.end() && dwAddr < it->first + it->second.SectionSize) {
        ipstart = (uint64_t)(uintptr_t)(*it).first;
    }
    pyju_unlock_profile_impl();
    return ipstart;
}