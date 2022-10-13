CMAKE_MINIMUM_REQUIRED(VERSION 3.15.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_language( C CXX ASM )

set(CMAKE_BUILD_TYPE Release)

message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")
message("Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" ON)

file(GLOB_RECURSE
        PYJU_SUPPORT_SRC
        CONFIGURE_DEPENDS  # Ask CMake to regenerate the build system if these files change.
        ./*.cc
        ./*.h
        )

message(STATUS "PYJU_SUPPORT_SRC " ${PYJU_SUPPORT_SRC})

add_library(pyju_support SHARED
    ${PYJU_SUPPORT_SRC}
)

target_link_libraries(pyju_support
    PUBLIC
    ch_contrib::utf8proc
)


