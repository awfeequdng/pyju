include("${PROJECT_SOURCE_DIR}/cmake/pyju_glob_sources.cmake")
add_headers_and_sources(loggers .)
add_library(loggers ${loggers_sources} ${loggers_headers})
target_link_libraries(loggers PRIVATE pyju_core)
target_include_directories(loggers PUBLIC ..)
