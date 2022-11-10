

file(GLOB_RECURSE
        PYJU_VM_SRC
        CONFIGURE_DEPENDS  # Ask CMake to regenerate the build system if these files change.
        ./*.cc
        ./*.h
        )

# message(STATUS "PYJU_VM_SRC " ${PYJU_VM_SRC})

add_subdirectory(support)

add_library(pyju_vm SHARED
    ${PYJU_VM_SRC}
)

target_link_libraries(pyju_vm
    PUBLIC
    pyju_support
    ch_contrib::uv
    ch_contrib::llvm
)


