CMAKE_MINIMUM_REQUIRED(VERSION 3.15.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_language( C CXX ASM )

set(CMAKE_BUILD_TYPE Release)

project(pyju)

# 该选项解决clang不支持operator delete(void*, size_t)的问题
# if (COMPILER_GCC OR COMPILER_CLANG)
#     # Enable C++14 sized global deallocation functions. It should be enabled by setting -std=c++14 but I'm not sure.
# endif ()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsized-deallocation")

message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")
message("Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

# use clang libabixx
if (CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I~/opt/llvm/include")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I~/opt/llvm/include/c++/v1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isysroot ~/opt/llvm/include/c++/v1")
    MESSAGE(STATUS "--------------------- CMAKE CXX FLAGS : ${CMAKE_CXX_FLAGS}")
endif ()

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)

# Turns on all external libs like nuraft, ODBC, ...
option(ENABLE_LIBRARIES "Enable all external libraries by default" ON)

message(STATUS "Enable all external libraries:" ${ENABLE_LIBRARIES})

# 解决zstd.h中deprecated报错的问题
add_definitions(-DZSTD_DISABLE_DEPRECATE_WARNINGS)

include (cmake/add_warning.cmake)
include (cmake/warnings.cmake)
include (cmake/version.cmake)
include (cmake/arch.cmake)
include (cmake/target.cmake)
include (cmake/embed_binary.cmake)

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
        JUPY_SRC
        CONFIGURE_DEPENDS  # Ask CMake to regenerate the build system if these files change.
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.h
        ${PROJECT_SOURCE_DIR}/base/loggers/*.cpp
        ${PROJECT_SOURCE_DIR}/base/loggers/*.h
        )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/base)

message(STATUS "JUPY_SRC " ${JUPY_SRC})

add_library(pyju_core SHARED
    ${JUPY_SRC}
)
target_link_libraries(pyju_core
    PUBLIC
    Poco::Net
    Poco::Foundation
    Poco::Util
    boost::headers_only
    boost::program_options
    ch_contrib::magic_enum
    ch_contrib::replxx
    ch_contrib::cityhash
    ch_contrib::fmt
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
    OpenSSL::SSL
    OpenSSL::Crypto
)


if (OS_LINUX)
    target_link_libraries(pyju_core
        PUBLIC
        ${CMAKE_DL_LIBS}
        ch_contrib::jemalloc
    )
endif ()

add_executable(pyju
    programs/main.cpp
)

target_link_libraries(pyju
    PUBLIC
    pyju_core
)

include (configure_config.cmake)


configure_file (src/Common/config.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Common/config.h")
configure_file (src/Common/config_version.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Common/config_version.h")
configure_file (src/Core/config_core.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Core/config_core.h")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src/Core)
