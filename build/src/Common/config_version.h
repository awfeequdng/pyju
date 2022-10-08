#pragma once

// .h autogenerated by cmake!

// NOTE: has nothing common with DBMS_TCP_PROTOCOL_VERSION,
// only DBMS_TCP_PROTOCOL_VERSION should be incremented on protocol changes.
#define VERSION_REVISION 1
#define VERSION_NAME "pyju"
#define DBMS_NAME VERSION_NAME
/* #undef VERSION_MAJOR */
#define VERSION_MINOR 1
/* #undef VERSION_PATCH */
#define VERSION_STRING "0.1.0"
#define VERSION_STRING_SHORT "0.1"
/* #undef VERSION_OFFICIAL */
#define VERSION_FULL "pyju 0.1.0"
#define VERSION_DESCRIBE "v0.1.0"
/* #undef VERSION_GITHASH */
#define VERSION_INTEGER 1000
/* #undef VERSION_DATE */

#if defined(VERSION_MAJOR)
#define DBMS_VERSION_MAJOR VERSION_MAJOR
#else
#define DBMS_VERSION_MAJOR 0
#endif

#if defined(VERSION_MINOR)
#define DBMS_VERSION_MINOR VERSION_MINOR
#else
#define DBMS_VERSION_MINOR 0
#endif

#if defined(VERSION_PATCH)
#define DBMS_VERSION_PATCH VERSION_PATCH
#else
#define DBMS_VERSION_PATCH 0
#endif

#if !defined(VERSION_OFFICIAL)
#   define VERSION_OFFICIAL ""
#endif