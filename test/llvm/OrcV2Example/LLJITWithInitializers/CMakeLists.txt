
add_executable(LLJITWithInitializers
LLJITWithInitializers.cc
)

target_link_libraries(LLJITWithInitializers
    ch_contrib::llvm
)