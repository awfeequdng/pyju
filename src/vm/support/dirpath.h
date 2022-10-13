// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_DIRPATH_H
#define PYJU_DIRPATH_H

#define PATHSEPSTRING "/"
#define PATHLISTSEPSTRING ":"
#if defined(PATH_MAX)
#define PYJU_PATH_MAX PATH_MAX
#else // many platforms don't have a max path, we define one anyways
#define PYJU_PATH_MAX 1024
#endif

#endif
