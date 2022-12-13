CMAKE_MINIMUM_REQUIRED(VERSION 3.15.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_language( C CXX ASM )

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

project(pyju)

# 该选项解决clang不支持operator delete(void*, size_t)的问题
# if (COMPILER_GCC OR COMPILER_CLANG)
#     # Enable C++14 sized global deallocation functions. It should be enabled by setting -std=c++14 but I'm not sure.
# endif ()
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsized-deallocation")

message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")
message("Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

# use clang libabixx
# if (CMAKE_CXX_COMPILER_ID STREQUAL Clang)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I~/opt/llvm/include")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I~/opt/llvm/include/c++/v1")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isysroot ~/opt/llvm/include/c++/v1")
#     MESSAGE(STATUS "--------------------- CMAKE CXX FLAGS : ${CMAKE_CXX_FLAGS}")
# endif ()

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)

# Turns on all external libs like nuraft, ODBC, ...
option(ENABLE_LIBRARIES "Enable all external libraries by default" ON)

message(STATUS "Enable all external libraries:" ${ENABLE_LIBRARIES})

# 解决zstd.h中deprecated报错的问题
add_definitions(-DZSTD_DISABLE_DEPRECATE_WARNINGS)

# include(cmake/cpu_features.cmake)
include (cmake/add_warning.cmake)
include (cmake/warnings.cmake)
include (cmake/version.cmake)
include (cmake/arch.cmake)
include (cmake/target.cmake)
include (cmake/embed_binary.cmake)

# Ignore export() since we don't use it,
# but it gets broken with a global targets via link_libraries()
# 由于global-group为全局的链接库，为了避免这个库被llvm使用（在编译llvm时报找不到global-grou）,我们使用如下的宏来断开link_libraries链接的库
# 如果不添加如下两行配置，LLVM编译报错
macro (export)
endmacro ()

# Global libraries
# See:
# - default_libs.cmake
add_library(global-libs INTERFACE)

add_library(global-group INTERFACE)
if (OS_LINUX OR OS_ANDROID)
    include(cmake/linux/default_libs.cmake)
elseif (OS_DARWIN)
    include(cmake/darwin/default_libs.cmake)
elseif (OS_FREEBSD)
    include(cmake/freebsd/default_libs.cmake)
endif ()
link_libraries(global-group)

if (WERROR)
    # Don't pollute CMAKE_CXX_FLAGS with -Werror as it will break some CMake checks.
    # Instead, adopt modern cmake usage requirement.
    target_compile_options(global-group INTERFACE "-Werror")
endif ()

# Make this extra-checks for correct library dependencies.
if (OS_LINUX AND NOT SANITIZE)
    target_link_options(global-group INTERFACE "-Wl,--no-undefined")
endif ()

if (TARGET global-group)
    install (EXPORT global DESTINATION cmake)
endif ()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/contrib)
if (NOT ENABLE_JEMALLOC)
    message (WARNING "jemalloc allocator is disabled. This is not recommended for production builds.")
endif ()

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/base
    ${PROJECT_SOURCE_DIR}/base/loggers
)
file(GLOB_RECURSE
        PYJU_SRC
        CONFIGURE_DEPENDS  # Ask CMake to regenerate the build system if these files change.
        ${PROJECT_SOURCE_DIR}/src/ast/*.cpp
        ${PROJECT_SOURCE_DIR}/src/ast/*.h
        ${PROJECT_SOURCE_DIR}/src/Client/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Client/*.h
        ${PROJECT_SOURCE_DIR}/src/Common/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Common/*.h
        ${PROJECT_SOURCE_DIR}/src/Compression/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Compression/*.h
        ${PROJECT_SOURCE_DIR}/src/Core/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Core/*.h
        ${PROJECT_SOURCE_DIR}/src/Disks/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Disks/*.h
        ${PROJECT_SOURCE_DIR}/src/Formats/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Formats/*.h
        ${PROJECT_SOURCE_DIR}/src/interpreter/*.cpp
        ${PROJECT_SOURCE_DIR}/src/interpreter/*.h
        ${PROJECT_SOURCE_DIR}/src/IO/*.cpp
        ${PROJECT_SOURCE_DIR}/src/IO/*.h
        ${PROJECT_SOURCE_DIR}/src/Parser/*.cpp
        ${PROJECT_SOURCE_DIR}/src/Parser/*.h
        ${PROJECT_SOURCE_DIR}/base/loggers/*.cpp
        ${PROJECT_SOURCE_DIR}/base/loggers/*.h
        )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/base)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/vm)

message(STATUS "PYJU_SRC " ${PYJU_SRC})

add_library(pyju_core SHARED
    ${PYJU_SRC}
)
target_link_libraries(pyju_core
    PUBLIC
    Poco::Net
    Poco::Foundation
    Poco::Util
    Poco::Net::SSL
    boost::headers_only
    boost::program_options
    ch_contrib::magic_enum
    ch_contrib::replxx
    ch_contrib::cityhash
    ch_contrib::cctz
    base
    # loggers
    pcg_random
    readpassphrase
    widechar_width
    ch_contrib::re2_st
    ch_contrib::re2
    ch_contrib::yaml_cpp
    ch_contrib::double_conversion
    ch_contrib::miniselect
    ch_contrib::dragonbox_to_chars
    ch_contrib::fast_float
    ch_contrib::lz4
    ch_contrib::zstd
    ch_contrib::xz
    ch_contrib::brotli
    ch_contrib::bzip2
    ch_contrib::zlib
    ch_contrib::fmt
    OpenSSL::SSL
    OpenSSL::Crypto
    ch_contrib::cpuid
    ch_contrib::llvm
    ch_contrib::utf8proc
)

if (OS_LINUX)
    target_link_libraries(pyju_core
        PUBLIC
        ${CMAKE_DL_LIBS}
        ch_contrib::jemalloc
    )
endif ()

add_executable(pyju
    programs/pyju.cpp
    programs/TestTags.cpp
    programs/Client.cpp
    programs/pyju_main.cpp
)

target_link_libraries(pyju
    PUBLIC
    pyju_core
    pyju_vm
)

# test
add_subdirectory(test/llvm/HowToUseJIT)
add_subdirectory(test/llvm/HowToUseLLJIT)
add_subdirectory(test/llvm/OrcV2Example)

include (configure_config.cmake)


configure_file (src/Common/config.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Common/config.h")
configure_file (src/Common/config_version.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Common/config_version.h")
configure_file (src/Core/config_core.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Core/config_core.h")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src/Core)

