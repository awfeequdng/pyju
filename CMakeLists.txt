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

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/contrib)

file(GLOB_RECURSE
        JUPY_SRC
        CONFIGURE_DEPENDS  # Ask CMake to regenerate the build system if these files change.
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/src/*.h
        ${PROJECT_SOURCE_DIR}/base/*.cpp
        ${PROJECT_SOURCE_DIR}/base/*.h
        )

message(STATUS "JUPY_SRC " ${JUPY_SRC})

add_library(pyju_lib SHARED
    ${JUPY_SRC}
)
target_link_libraries(pyju_lib
    PUBLIC
    ch_contrib::jemalloc
)

add_executable(pyju
    programs/main.cpp
)

target_link_libraries(pyju
    PUBLIC
    pyju_lib
)

include (configure_config.cmake)


configure_file (src/Common/config.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Common/config.h")
configure_file (src/Common/config_version.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Common/config_version.h")
configure_file (src/Core/config_core.h.in "${CMAKE_CURRENT_BINARY_DIR}/src/Core/config_core.h")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
