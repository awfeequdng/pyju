// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_BITVECTOR_H
#define PYJU_BITVECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

PYJU_DLLEXPORT uint32_t *bitvector_new(uint64_t n, int initzero);
PYJU_DLLEXPORT
uint32_t *bitvector_resize(uint32_t *b, uint64_t oldsz, uint64_t newsz,
                           int initzero);
size_t bitvector_nwords(uint64_t nbits);
PYJU_DLLEXPORT void bitvector_set(uint32_t *b, uint64_t n, uint32_t c);
PYJU_DLLEXPORT uint32_t bitvector_get(uint32_t *b, uint64_t n);

#ifdef __cplusplus
}
#endif

#endif
