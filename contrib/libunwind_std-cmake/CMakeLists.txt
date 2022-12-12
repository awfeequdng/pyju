CMAKE_MINIMUM_REQUIRED(VERSION 3.15.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_language( C CXX ASM )

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

project(pyju)

include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

set(LIBUNWIND_SOURCE_DIR "${PROJECT_SOURCE_DIR}/../libunwind_std")


set(PKG_MAJOR "1")
set(PKG_MINOR "6")
set(PKG_EXTRA "-rc1")
set(PACKAGE_STRING "libunwind")
set(PACKAGE_BUGREPORT "")

set(TARGET_AMD64 1)
set(arch x86_64)
add_definitions(-D__x86_64__)
add_definitions(-D__amd64__)
add_definitions(-D__linux__)


# Windows builds will only support remote unwind
# add_definitions(-DUNW_REMOTE_ONLY)

# Disable security warnings
# add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Our posix abstraction layer will provide these headers
# set(HAVE_ELF_H 1)
# set(HAVE_ENDIAN_H 1)

configure_file(${LIBUNWIND_SOURCE_DIR}/include/config.h.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)
configure_file(${LIBUNWIND_SOURCE_DIR}/include/libunwind-common.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/libunwind-common.h)
configure_file(${LIBUNWIND_SOURCE_DIR}/include/libunwind.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/libunwind.h)
configure_file(${LIBUNWIND_SOURCE_DIR}/include/tdep/libunwind_i.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/tdep/libunwind_i.h)

SET(libunwind_ptrace_la_SOURCES
${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_elf.c
    ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_accessors.c ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_access_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_access_mem.c ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_access_reg.c
    ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_create.c ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_destroy.c
    ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_find_proc_info.c ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_get_dyn_info_list_addr.c
    ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_put_unwind_info.c ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_get_proc_name.c
    ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_reg_offset.c ${LIBUNWIND_SOURCE_DIR}/src/ptrace/_UPT_resume.c
)

SET(libunwind_coredump_la_SOURCES
${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_accessors.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_create.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_destroy.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_access_mem.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_elf_map_image.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_find_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_get_proc_name.c

    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UPT_elf.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UPT_access_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UPT_get_dyn_info_list_addr.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UPT_put_unwind_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UPT_resume.c
)

# List of arch-independent files needed by generic library (libunwind-$ARCH):
SET(libunwind_la_SOURCES_generic
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gdyn-extract.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gdyn-remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gfind_dynamic_proc_info.c
    # The Gget_accessors.c implements the same function as Lget_accessors.c, so
    # the source is excluded here to prevent name clash
    #mi/Gget_accessors.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gget_proc_info_by_ip.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gget_proc_name.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gput_dynamic_unwind_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gdestroy_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gget_reg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gset_reg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gget_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gset_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gset_caching_policy.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gset_cache_size.c
)

SET(libunwind_la_SOURCES_os_linux
    ${LIBUNWIND_SOURCE_DIR}/src/os-linux.c
)

SET(libunwind_la_SOURCES_os_linux_local
# Nothing when we don't want to support CXX exceptions
)

SET(libunwind_la_SOURCES_os                 ${libunwind_la_SOURCES_os_linux})
SET(libunwind_la_SOURCES_os_local           ${libunwind_la_SOURCES_os_linux_local})
SET(libunwind_la_SOURCES_x86_os             ${LIBUNWIND_SOURCE_DIR}/src/x86/Gos-linux.c)
SET(libunwind_x86_la_SOURCES_os             ${LIBUNWIND_SOURCE_DIR}/src/x86/getcontext-linux.S)
SET(libunwind_la_SOURCES_x86_os_local       ${LIBUNWIND_SOURCE_DIR}/src/x86/Los-linux.c)
SET(libunwind_la_SOURCES_x86_64_os          ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gos-linux.c)
SET(libunwind_la_SOURCES_x86_64_os_local    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Los-linux.c)
SET(libunwind_la_SOURCES_arm_os             ${LIBUNWIND_SOURCE_DIR}/src/arm/Gos-linux.c)
SET(libunwind_la_SOURCES_arm_os_local       ${LIBUNWIND_SOURCE_DIR}/src/arm/Los-linux.c)
list(APPEND libunwind_coredump_la_SOURCES   ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_access_reg_linux.c
                                            ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_get_threadinfo_prstatus.c
                                            ${LIBUNWIND_SOURCE_DIR}/src/coredump/_UCD_get_mapinfo_linux.c)

# List of arch-independent files needed by both local-only and generic
# libraries:
SET(libunwind_la_SOURCES_common
    ${libunwind_la_SOURCES_os}
    ${LIBUNWIND_SOURCE_DIR}/src/mi/init.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/flush_cache.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/mempool.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/strerror.c
)

SET(libunwind_la_SOURCES_local_unwind
# Nothing when we don't want to support CXX exceptions
)

# List of arch-independent files needed by local-only library (libunwind):
SET(libunwind_la_SOURCES_local_nounwind
    ${libunwind_la_SOURCES_os_local}
    ${LIBUNWIND_SOURCE_DIR}/src/mi/backtrace.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/dyn-cancel.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/dyn-info-list.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/dyn-register.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Ldyn-extract.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lfind_dynamic_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lget_accessors.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lget_proc_info_by_ip.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lget_proc_name.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lput_dynamic_unwind_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Ldestroy_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lget_reg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lset_reg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lget_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lset_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lset_caching_policy.c
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Lset_cache_size.c
)

SET(libunwind_la_SOURCES_local
    ${libunwind_la_SOURCES_local_nounwind}
    ${libunwind_la_SOURCES_local_unwind}
)

SET(libunwind_dwarf_common_la_SOURCES
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/global.c
)

SET(libunwind_dwarf_local_la_SOURCES
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Lexpr.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Lfde.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Lparser.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Lpe.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Lfind_proc_info-lsb.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Lfind_unwind_table.c
)

SET(libunwind_dwarf_generic_la_SOURCES
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Gexpr.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Gfde.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Gparser.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Gpe.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Gfind_proc_info-lsb.c
    ${LIBUNWIND_SOURCE_DIR}/src/dwarf/Gfind_unwind_table.c
)

SET(libunwind_elf32_la_SOURCES
    ${LIBUNWIND_SOURCE_DIR}/src/elf32.c
)

SET(libunwind_elf64_la_SOURCES
    ${LIBUNWIND_SOURCE_DIR}/src/elf64.c
)
SET(libunwind_elfxx_la_SOURCES
    ${LIBUNWIND_SOURCE_DIR}/src/elfxx.c
)


# The list of files that go into libunwind and libunwind-aarch64:
SET(libunwind_la_SOURCES_aarch64_common
    ${libunwind_la_SOURCES_common}
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/is_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/regname.c
)

# The list of files that go into libunwind:
SET(libunwind_la_SOURCES_aarch64
    ${libunwind_la_SOURCES_aarch64_common}
    ${libunwind_la_SOURCES_local}
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lapply_reg_state.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lreg_states_iterate.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lcreate_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lget_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lget_save_loc.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lglobal.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Linit.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Linit_local.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Linit_remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lis_signal_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lregs.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lresume.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lstash_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Lstep.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Ltrace.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/getcontext.S
)

SET(libunwind_aarch64_la_SOURCES_aarch64
    ${libunwind_la_SOURCES_aarch64_common}
    ${libunwind_la_SOURCES_generic}
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gapply_reg_state.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Greg_states_iterate.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gcreate_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gget_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gget_save_loc.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gglobal.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Ginit.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Ginit_local.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Ginit_remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gis_signal_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gregs.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gresume.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gstash_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gstep.c
    ${LIBUNWIND_SOURCE_DIR}/src/aarch64/Gtrace.c
)

# The list of files that go into libunwind and libunwind-arm:
SET(libunwind_la_SOURCES_arm_common
    ${libunwind_la_SOURCES_common}
    ${LIBUNWIND_SOURCE_DIR}/src/arm/is_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/regname.c
)

# The list of files that go into libunwind:
SET(libunwind_la_SOURCES_arm
    ${libunwind_la_SOURCES_arm_common}
    ${libunwind_la_SOURCES_arm_os_local}
    ${libunwind_la_SOURCES_local}
    ${LIBUNWIND_SOURCE_DIR}/src/arm/getcontext.S
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lapply_reg_state.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lreg_states_iterate.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lcreate_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lget_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lget_save_loc.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lglobal.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Linit.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Linit_local.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Linit_remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lregs.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lresume.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lstep.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lex_tables.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Lstash_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Ltrace.c
)

# The list of files that go into libunwind-arm:
SET(libunwind_arm_la_SOURCES_arm
    ${libunwind_la_SOURCES_arm_common}
    ${libunwind_la_SOURCES_arm_os}
    ${libunwind_la_SOURCES_generic}
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gapply_reg_state.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Greg_states_iterate.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gcreate_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gget_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gget_save_loc.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gglobal.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Ginit.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Ginit_local.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Ginit_remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gregs.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gresume.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gstep.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gex_tables.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gstash_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/arm/Gtrace.c
)

# The list of files that go both into libunwind and libunwind-x86_64:
SET(libunwind_la_SOURCES_x86_64_common
    ${libunwind_la_SOURCES_common}
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/is_fpreg.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/regname.c
)

# The list of files that go into libunwind:
SET(libunwind_la_SOURCES_x86_64
    ${libunwind_la_SOURCES_x86_64_common}
    ${libunwind_la_SOURCES_x86_64_os_local}
    ${libunwind_la_SOURCES_local}
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/setcontext.S
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lapply_reg_state.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lreg_states_iterate.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lcreate_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lget_save_loc.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lglobal.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Linit.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Linit_local.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Linit_remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lget_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lregs.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lresume.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lstash_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Lstep.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Ltrace.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/getcontext.S
)

# The list of files that go into libunwind-x86_64:
SET(libunwind_x86_64_la_SOURCES_x86_64
    ${libunwind_la_SOURCES_x86_64_common}
    ${libunwind_la_SOURCES_x86_64_os}
    ${libunwind_la_SOURCES_generic}
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gapply_reg_state.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Greg_states_iterate.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gcreate_addr_space.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gget_save_loc.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gglobal.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Ginit.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Ginit_local.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Ginit_remote.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gget_proc_info.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gregs.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gresume.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gstash_frame.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gstep.c
    ${LIBUNWIND_SOURCE_DIR}/src/x86_64/Gtrace.c
)

SET(libunwind_la_SOURCES                    ${libunwind_la_SOURCES_x86_64})
SET(libunwind_remote_la_SOURCES             ${libunwind_x86_64_la_SOURCES_x86_64})
SET(libunwind_elf_la_SOURCES                ${libunwind_elf64_la_SOURCES})
list(APPEND libunwind_setjmp_la_SOURCES     ${LIBUNWIND_SOURCE_DIR}/src/x86_64/longjmp.S ${LIBUNWIND_SOURCE_DIR}/src/x86_64/siglongjmp.SA)


set_source_files_properties(${libunwind_remote_la_SOURCES} PROPERTIES COMPILE_FLAGS "-std=c11")
set_source_files_properties(${LIBUNWIND_SOURCE_DIR}/src/win/pal-single-threaded.c/src/mi/Gget_accessors.c PROPERTIES COMPILE_FLAGS "-std=c11")
set_source_files_properties(${LIBUNWIND_SOURCE_DIR}/src/mi/Gget_accessors.c PROPERTIES COMPILE_FLAGS "-std=c11")
set_source_files_properties(${libunwind_dwarf_common_la_SOURCES} PROPERTIES COMPILE_FLAGS "-std=c11")
set_source_files_properties(${libunwind_dwarf_generic_la_SOURCES} PROPERTIES COMPILE_FLAGS "-std=c11")
set_source_files_properties(${libunwind_elf_la_SOURCES} PROPERTIES COMPILE_FLAGS "-std=c11")

add_library(unwind
  OBJECT
  ${LIBUNWIND_SOURCE_DIR}/src/win/pal-single-threaded.c
  # ${libunwind_la_SOURCES}  Local...
  ${libunwind_remote_la_SOURCES}
    # Commented out above for LOCAL + REMOTE runtime build
    ${LIBUNWIND_SOURCE_DIR}/src/mi/Gget_accessors.c
  # ${libunwind_dwarf_local_la_SOURCES}
  ${libunwind_dwarf_common_la_SOURCES}
  ${libunwind_dwarf_generic_la_SOURCES}
  ${libunwind_elf_la_SOURCES}
)

set_target_properties(unwind PROPERTIES FOLDER "contrib/libunwind_std-cmake")


target_include_directories(unwind PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
target_include_directories(unwind PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include/tdep)
# files for cross os compilation
target_include_directories(unwind PUBLIC ${LIBUNWIND_SOURCE_DIR}/include/win)
target_include_directories(unwind PUBLIC ${LIBUNWIND_SOURCE_DIR}/include)
target_include_directories(unwind PUBLIC ${LIBUNWIND_SOURCE_DIR}/src)
target_include_directories(unwind PUBLIC ${LIBUNWIND_SOURCE_DIR}/include/tdep)



# target_include_directories(unwind SYSTEM BEFORE PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>)
# target_include_directories(unwind SYSTEM BEFORE PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/tdep>)
# # files for cross os compilation
# target_include_directories(unwind SYSTEM BEFORE PUBLIC $<BUILD_INTERFACE:${LIBUNWIND_SOURCE_DIR}/include/win>)
# target_include_directories(unwind SYSTEM BEFORE PUBLIC $<BUILD_INTERFACE:${LIBUNWIND_SOURCE_DIR}/include>)
# target_include_directories(unwind SYSTEM BEFORE PUBLIC $<BUILD_INTERFACE:${LIBUNWIND_SOURCE_DIR}/src>)
# target_include_directories(unwind SYSTEM BEFORE PUBLIC $<BUILD_INTERFACE:${LIBUNWIND_SOURCE_DIR}/include/tdep>)
# target_compile_definitions(unwind PRIVATE -D_LIBUNWIND_NO_HEAP=1 -D_DEBUG -D_LIBUNWIND_IS_NATIVE_ONLY)
# target_compile_options(unwind PRIVATE -fno-exceptions -funwind-tables -fno-sanitize=all $<$<COMPILE_LANGUAGE:CXX>:-nostdinc++ -fno-rtti>)


install(
    TARGETS unwind
    EXPORT global
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
