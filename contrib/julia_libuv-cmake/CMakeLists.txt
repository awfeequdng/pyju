# cmake_minimum_required(VERSION 3.4)
# project(libuv LANGUAGES C)

# cmake_policy(SET CMP0057 NEW) # Enable IN_LIST operator
# cmake_policy(SET CMP0064 NEW) # Support if (TEST) operator

set(LIBRARY_DIR "${PROJECT_SOURCE_DIR}/contrib/julia_libuv")

# include(CMakePackageConfigHelpers)
# include(CMakeDependentOption)
# include(CheckCCompilerFlag)
# include(GNUInstallDirs)
# include(CTest)

# set(CMAKE_C_VISIBILITY_PRESET hidden)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_C_EXTENSIONS ON)
# set(CMAKE_C_STANDARD 90)


# check_c_compiler_flag(/W4 UV_LINT_W4)
# check_c_compiler_flag(/wd4100 UV_LINT_NO_UNUSED_PARAMETER_MSVC)
# check_c_compiler_flag(/wd4127 UV_LINT_NO_CONDITIONAL_CONSTANT_MSVC)
# check_c_compiler_flag(/wd4201 UV_LINT_NO_NONSTANDARD_MSVC)
# check_c_compiler_flag(/wd4206 UV_LINT_NO_NONSTANDARD_EMPTY_TU_MSVC)
# check_c_compiler_flag(/wd4210 UV_LINT_NO_NONSTANDARD_FILE_SCOPE_MSVC)
# check_c_compiler_flag(/wd4232 UV_LINT_NO_NONSTANDARD_NONSTATIC_DLIMPORT_MSVC)
# check_c_compiler_flag(/wd4456 UV_LINT_NO_HIDES_LOCAL)
# check_c_compiler_flag(/wd4457 UV_LINT_NO_HIDES_PARAM)
# check_c_compiler_flag(/wd4459 UV_LINT_NO_HIDES_GLOBAL)
# check_c_compiler_flag(/wd4706 UV_LINT_NO_CONDITIONAL_ASSIGNMENT_MSVC)
# check_c_compiler_flag(/wd4996 UV_LINT_NO_UNSAFE_MSVC)

# check_c_compiler_flag(-Wall UV_LINT_WALL) # DO NOT use this under MSVC

# # TODO: Place these into its own function
# check_c_compiler_flag(-Wno-unused-parameter UV_LINT_NO_UNUSED_PARAMETER)
# check_c_compiler_flag(-Wstrict-prototypes UV_LINT_STRICT_PROTOTYPES)
# check_c_compiler_flag(-Wextra UV_LINT_EXTRA)

# check_c_compiler_flag(/utf-8 UV_LINT_UTF8_MSVC)

# set(lint-no-unused-parameter $<$<BOOL:${UV_LINT_NO_UNUSED_PARAMETER}>:-Wno-unused-parameter>)
# set(lint-strict-prototypes $<$<BOOL:${UV_LINT_STRICT_PROTOTYPES}>:-Wstrict-prototypes>)
# set(lint-extra $<$<BOOL:${UV_LINT_EXTRA}>:-Wextra>)
# set(lint-w4 $<$<BOOL:${UV_LINT_W4}>:/W4>)
# set(lint-no-unused-parameter-msvc $<$<BOOL:${UV_LINT_NO_UNUSED_PARAMETER_MSVC}>:/wd4100>)
# set(lint-no-conditional-constant-msvc $<$<BOOL:${UV_LINT_NO_CONDITIONAL_CONSTANT_MSVC}>:/wd4127>)
# set(lint-no-nonstandard-msvc $<$<BOOL:${UV_LINT_NO_NONSTANDARD_MSVC}>:/wd4201>)
# set(lint-no-nonstandard-empty-tu-msvc $<$<BOOL:${UV_LINT_NO_NONSTANDARD_EMPTY_TU_MSVC}>:/wd4206>)
# set(lint-no-nonstandard-file-scope-msvc $<$<BOOL:${UV_LINT_NO_NONSTANDARD_FILE_SCOPE_MSVC}>:/wd4210>)
# set(lint-no-nonstandard-nonstatic-dlimport-msvc $<$<BOOL:${UV_LINT_NO_NONSTANDARD_NONSTATIC_DLIMPORT_MSVC}>:/wd4232>)
# set(lint-no-hides-local-msvc $<$<BOOL:${UV_LINT_NO_HIDES_LOCAL}>:/wd4456>)
# set(lint-no-hides-param-msvc $<$<BOOL:${UV_LINT_NO_HIDES_PARAM}>:/wd4457>)
# set(lint-no-hides-global-msvc $<$<BOOL:${UV_LINT_NO_HIDES_GLOBAL}>:/wd4459>)
# set(lint-no-conditional-assignment-msvc $<$<BOOL:${UV_LINT_NO_CONDITIONAL_ASSIGNMENT_MSVC}>:/wd4706>)
# set(lint-no-unsafe-msvc $<$<BOOL:${UV_LINT_NO_UNSAFE_MSVC}>:/wd4996>)
# # Unfortunately, this one is complicated because MSVC and clang-cl support -Wall
# # but using it is like calling -Weverything
# string(CONCAT lint-default $<
#   $<AND:$<BOOL:${UV_LINT_WALL}>,$<NOT:${is-msvc}>>:-Wall
# >)
# set(lint-utf8-msvc $<$<BOOL:${UV_LINT_UTF8_MSVC}>:/utf-8>)

# list(APPEND uv_cflags ${lint-strict-prototypes} ${lint-extra} ${lint-default} ${lint-w4})
# list(APPEND uv_cflags ${lint-no-unused-parameter})
# list(APPEND uv_cflags ${lint-no-unused-parameter-msvc})
# list(APPEND uv_cflags ${lint-no-conditional-constant-msvc})
# list(APPEND uv_cflags ${lint-no-nonstandard-msvc})
# list(APPEND uv_cflags ${lint-no-nonstandard-empty-tu-msvc})
# list(APPEND uv_cflags ${lint-no-nonstandard-file-scope-msvc})
# list(APPEND uv_cflags ${lint-no-nonstandard-nonstatic-dlimport-msvc})
# list(APPEND uv_cflags ${lint-no-hides-local-msvc})
# list(APPEND uv_cflags ${lint-no-hides-param-msvc})
# list(APPEND uv_cflags ${lint-no-hides-global-msvc})
# list(APPEND uv_cflags ${lint-no-conditional-assignment-msvc})
# list(APPEND uv_cflags ${lint-no-unsafe-msvc})
# list(APPEND uv_cflags ${lint-utf8-msvc} )

# check_c_compiler_flag(-fno-strict-aliasing UV_F_STRICT_ALIASING)
# list(APPEND uv_cflags $<$<BOOL:${UV_F_STRICT_ALIASING}>:-fno-strict-aliasing>)

set(uv_sources
    ${LIBRARY_DIR}/src/fs-poll.c
    ${LIBRARY_DIR}/src/idna.c
    ${LIBRARY_DIR}/src/inet.c
    ${LIBRARY_DIR}/src/loop-watcher.c
    ${LIBRARY_DIR}/src/random.c
    ${LIBRARY_DIR}/src/strscpy.c
    ${LIBRARY_DIR}/src/strtok.c
    ${LIBRARY_DIR}/src/threadpool.c
    ${LIBRARY_DIR}/src/timer.c
    ${LIBRARY_DIR}/src/uv-common.c
    ${LIBRARY_DIR}/src/uv-data-getter-setters.c
    ${LIBRARY_DIR}/src/version.c)

    list(APPEND uv_defines _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE)
if(NOT CMAKE_SYSTEM_NAME MATCHES "Android|OS390|QNX")
  # TODO: This should be replaced with find_package(Threads) if possible
  # Android has pthread as part of its c library, not as a separate
  # libpthread.so.
  list(APPEND uv_libraries pthread)
endif()
list(APPEND uv_sources
  ${LIBRARY_DIR}/src/unix/async.c
  ${LIBRARY_DIR}/src/unix/core.c
  ${LIBRARY_DIR}/src/unix/dl.c
  ${LIBRARY_DIR}/src/unix/fs.c
  ${LIBRARY_DIR}/src/unix/getaddrinfo.c
  ${LIBRARY_DIR}/src/unix/getnameinfo.c
  # ${LIBRARY_DIR}/src/unix/loop-watcher.c
  ${LIBRARY_DIR}/src/unix/loop.c
  ${LIBRARY_DIR}/src/unix/pipe.c
  ${LIBRARY_DIR}/src/unix/poll.c
  ${LIBRARY_DIR}/src/unix/process.c
  ${LIBRARY_DIR}/src/unix/random-devurandom.c
  ${LIBRARY_DIR}/src/unix/signal.c
  ${LIBRARY_DIR}/src/unix/stream.c
  ${LIBRARY_DIR}/src/unix/tcp.c
  ${LIBRARY_DIR}/src/unix/thread.c
  ${LIBRARY_DIR}/src/unix/tty.c
  ${LIBRARY_DIR}/src/unix/udp.c
)

if(CMAKE_SYSTEM_NAME STREQUAL "AIX")
  list(APPEND uv_defines
       _ALL_SOURCE
       _LINUX_SOURCE_COMPAT
       _THREAD_SAFE
       _XOPEN_SOURCE=500
       HAVE_SYS_AHAFS_EVPRODS_H)
  list(APPEND uv_libraries perfstat)
  list(APPEND uv_sources
    ${LIBRARY_DIR}/src/unix/aix.c
    ${LIBRARY_DIR}/src/unix/aix-common.c)
endif()

if(APPLE OR CMAKE_SYSTEM_NAME MATCHES "Android|Linux")
  list(APPEND uv_sources ${LIBRARY_DIR}/src/unix/proctitle.c)
endif()

if(APPLE)
  list(APPEND uv_defines _DARWIN_UNLIMITED_SELECT=1 _DARWIN_USE_64_BIT_INODE=1)
  list(APPEND uv_sources
    ${LIBRARY_DIR}/src/unix/darwin-proctitle.c
    ${LIBRARY_DIR}/src/unix/darwin.c
    ${LIBRARY_DIR}/src/unix/fsevents.c)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "GNU")
  list(APPEND uv_libraries dl)
  list(APPEND uv_sources
  ${LIBRARY_DIR}/src/unix/bsd-ifaddrs.c
  ${LIBRARY_DIR}/src/unix/no-fsevents.c
  ${LIBRARY_DIR}/src/unix/no-proctitle.c
  ${LIBRARY_DIR}/src/unix/posix-hrtime.c
  ${LIBRARY_DIR}/src/unix/posix-poll.c
  ${LIBRARY_DIR}/src/unix/hurd.c)
endif()


if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  list(APPEND uv_defines _GNU_SOURCE _POSIX_C_SOURCE=200112)
  list(APPEND uv_libraries dl rt)
  list(APPEND uv_sources
    ${LIBRARY_DIR}/src/unix/linux-core.c
    ${LIBRARY_DIR}/src/unix/linux-inotify.c
    ${LIBRARY_DIR}/src/unix/linux-syscalls.c
    ${LIBRARY_DIR}/src/unix/procfs-exepath.c
    ${LIBRARY_DIR}/src/unix/random-getrandom.c
    ${LIBRARY_DIR}/src/unix/random-sysctl-linux.c
    ${LIBRARY_DIR}/src/unix/epoll.c
  )
endif()


add_library(_uv SHARED ${uv_sources})
target_link_libraries(_uv ${uv_libraries})

add_library(ch_contrib::uv ALIAS _uv)

target_compile_definitions(_uv
  INTERFACE
    USING_UV_SHARED=1
  PRIVATE
    BUILDING_UV_SHARED=1
    ${uv_defines})

target_include_directories(_uv
  PUBLIC
  "${LIBRARY_DIR}/include"
  "${LIBRARY_DIR}/src"
  )

message(STATUS "summary of build options:
    Install prefix:  ${CMAKE_INSTALL_PREFIX}
    Target system:   ${CMAKE_SYSTEM_NAME}
    Compiler:
      C compiler:    ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_ID})
      CFLAGS:        ${CMAKE_C_FLAGS_${_build_type}} ${CMAKE_C_FLAGS}
")
