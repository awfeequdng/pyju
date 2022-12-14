file(GLOB_RECURSE
        BASE_SRCS
        CONFIGURE_DEPENDS  # Ask CMake to regenerate the build system if these files change.
        ./*.cpp
        )

# set (SRCS
#     argsToConfig.cpp
#     coverage.cpp
#     demangle.cpp
#     getFQDNOrHostName.cpp
#     getMemoryAmount.cpp
#     getPageSize.cpp
#     getThreadId.cpp
#     JSON.cpp
#     LineReader.cpp
#     mremap.cpp
#     phdr_cache.cpp
#     preciseExp10.cpp
#     setTerminalEcho.cpp
#     shift10.cpp
#     sleep.cpp
#     terminalColors.cpp
#     errnoToString.cpp
#     StringRef.cpp
#     hex_formatter.cpp
#     colorizer.cpp
#     string_helpers.cpp
# )

# if (ENABLE_REPLXX)
#     list (APPEND BASE_SRC ReplxxLineReader.cpp)
# endif ()

if (USE_DEBUG_HELPERS)
    get_target_property(MAGIC_ENUM_INCLUDE_DIR ch_contrib::magic_enum INTERFACE_INCLUDE_DIRECTORIES)
    # CMake generator expression will do insane quoting when it encounters special character like quotes, spaces, etc.
    # Prefixing "SHELL:" will force it to use the original text.
    set (INCLUDE_DEBUG_HELPERS "SHELL:-I\"${MAGIC_ENUM_INCLUDE_DIR}\" -include \"${PROJECT_SOURCE_DIR}/base/base/iostream_debug_helpers.h\"")
    # Use generator expression as we don't want to pollute CMAKE_CXX_FLAGS, which will interfere with CMake check system.
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:${INCLUDE_DEBUG_HELPERS}>)
endif ()

add_library (base ${BASE_SRCS})

if (WITH_COVERAGE)
    target_compile_definitions(base PUBLIC WITH_COVERAGE=1)
else ()
    target_compile_definitions(base PUBLIC WITH_COVERAGE=0)
endif ()

target_include_directories(base PUBLIC .. "${CMAKE_CURRENT_BINARY_DIR}/..")

if (OS_DARWIN AND NOT USE_STATIC_LIBRARIES)
    target_link_libraries(base PUBLIC -Wl,-U,_inside_main)
endif()

target_link_libraries (base
    PUBLIC
        ch_contrib::cityhash
        boost::headers_only
        boost::system
        Poco::Net
        Poco::Net::SSL
        Poco::Util
        Poco::Foundation
        ch_contrib::replxx
        ch_contrib::cctz
        ch_contrib::fmt
        ch_contrib::magic_enum
        ch_contrib::pdqsort
        ch_contrib::llvm
        ch_contrib::utf8proc
)

if (ENABLE_TESTS)
    add_subdirectory (tests)
endif ()
