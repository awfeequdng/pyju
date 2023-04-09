set (SRC_DIR "${PROJECT_SOURCE_DIR}/contrib/google-benchmark/src")

set (SRCS
  "${SRC_DIR}/benchmark.cc"
  "${SRC_DIR}/benchmark_api_internal.cc"
  "${SRC_DIR}/benchmark_name.cc"
  "${SRC_DIR}/benchmark_register.cc"
  "${SRC_DIR}/benchmark_runner.cc"
  "${SRC_DIR}/check.cc"
  "${SRC_DIR}/colorprint.cc"
  "${SRC_DIR}/commandlineflags.cc"
  "${SRC_DIR}/complexity.cc"
  "${SRC_DIR}/console_reporter.cc"
  "${SRC_DIR}/counter.cc"
  "${SRC_DIR}/csv_reporter.cc"
  "${SRC_DIR}/json_reporter.cc"
  "${SRC_DIR}/perf_counters.cc"
  "${SRC_DIR}/reporter.cc"
  "${SRC_DIR}/sleep.cc"
  "${SRC_DIR}/statistics.cc"
  "${SRC_DIR}/string_util.cc"
  "${SRC_DIR}/sysinfo.cc"
  "${SRC_DIR}/timers.cc")

add_library(gbenchmark "${SRCS}")
target_include_directories(gbenchmark SYSTEM PUBLIC "${SRC_DIR}/../include")

add_library(gbenchmark_main "${SRC_DIR}/benchmark_main.cc")
target_link_libraries(gbenchmark_main PUBLIC gbenchmark)

add_library(google_benchmark_all INTERFACE)
target_link_libraries(google_benchmark_all INTERFACE gbenchmark gbenchmark_main)

add_library(ch_contrib::gbenchmark_all ALIAS google_benchmark_all)
