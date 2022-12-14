
add_executable(LLJITWithObjectLinkingLayerPlugin
LLJITWithObjectLinkingLayerPlugin.cc
)

target_link_libraries(LLJITWithObjectLinkingLayerPlugin
    ch_contrib::llvm
)