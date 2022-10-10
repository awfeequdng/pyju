
if (POLICY CMP0048)
  cmake_policy (SET CMP0048 NEW)
endif ()
# project (utf8proc VERSION 2.7.0 LANGUAGES C)

# This is the ABI version number, which may differ from the
# API version number (defined in utf8proc.h and above).
# Be sure to also update these in Makefile and MANIFEST!
set(SO_MAJOR 2)
set(SO_MINOR 5)
set(SO_PATCH 0)

set (LIBRARY_DIR "${PROJECT_SOURCE_DIR}/contrib/utf8proc")

set(SRCS
    "${LIBRARY_DIR}/utf8proc.c"
    "${LIBRARY_DIR}/utf8proc.h"
)


add_library (_utf8proc ${SRCS})
target_include_directories(_utf8proc SYSTEM PUBLIC "${LIBRARY_DIR}")

if (NOT MSVC)
  set_target_properties(
    _utf8proc PROPERTIES
    COMPILE_FLAGS "-O2 -std=c99 -pedantic -Wall"
  )
endif ()

if (BUILD_SHARED_LIBS)
  # Building shared library
else()
  # Building static library
  target_compile_definitions(_utf8proc PUBLIC "UTF8PROC_STATIC")
  if (MSVC)
    set_target_properties(_utf8proc PROPERTIES OUTPUT_NAME "utf8proc_static")
  endif()
endif()

set_target_properties (_utf8proc PROPERTIES
  POSITION_INDEPENDENT_CODE ON
  VERSION "${SO_MAJOR}.${SO_MINOR}.${SO_PATCH}"
  SOVERSION ${SO_MAJOR}
)

add_library(ch_contrib::utf8proc ALIAS _utf8proc)
