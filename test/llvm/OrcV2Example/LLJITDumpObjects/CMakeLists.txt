
add_executable(LLJITDumpObjects
    LLJITDumpObjects.cc
)

target_link_libraries(LLJITDumpObjects
    ch_contrib::llvm
)

# LLJITDumpObjects will dump a add.o file, then we can link the add.o adn test_add.cc to test add function
# add_executable(test_add
#     test_add.cc
#     add.o
# )