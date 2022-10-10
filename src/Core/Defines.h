#pragma once

#include <base/defines.h>

/// The size of the I/O buffer by default.
#define PYJU_DEFAULT_BUFFER_SIZE 1048576ULL

/// The boundary on which the blocks for asynchronous file operations should be aligned.
#define DEFAULT_AIO_FILE_BLOCK_SIZE 4096

#define SHOW_CHARS_ON_SYNTAX_ERROR ptrdiff_t(160)
