add_executable(LLJITWithCustomObjectLinkerLayer
    LLJITWithCustomObjectLinkerLayer.cc
)

target_link_libraries(LLJITWithCustomObjectLinkerLayer
    ch_contrib::llvm
)