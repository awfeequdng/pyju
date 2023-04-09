

add_executable(superscalar
    superscalar.cc
)

target_link_libraries(superscalar
    ch_contrib::gbenchmark_all
)
