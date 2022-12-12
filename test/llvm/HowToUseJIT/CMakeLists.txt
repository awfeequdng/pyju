

add_executable(HowToUseJIT
    HowToUseJIT.cc
)

target_link_libraries(HowToUseJIT
    ch_contrib::llvm
)
