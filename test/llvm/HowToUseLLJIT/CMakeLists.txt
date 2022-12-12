
add_executable(HowToUseLLJIT
    HowToUseLLJIT.cc
)

target_link_libraries(HowToUseLLJIT
    ch_contrib::llvm
)