// This file is a part of Julia. License is MIT: https://julialang.org/license

#ifndef PYJU_ARRAYLIST_H
#define PYJU_ARRAYLIST_H

#define AL_N_INLINE 29

#define SMALL_AL_N_INLINE 6

#ifdef __cplusplus
extern "C" {
#endif

#include "analyzer_annotations.h"

typedef struct {
    size_t len;
    size_t max;
    void **items;
    void *_space[AL_N_INLINE];
} arraylist_t;

arraylist_t *arraylist_new(arraylist_t *a, size_t size) PYJU_NOTSAFEPOINT;
void arraylist_free(arraylist_t *a) PYJU_NOTSAFEPOINT;

void arraylist_push(arraylist_t *a, void *elt) PYJU_NOTSAFEPOINT;
void *arraylist_pop(arraylist_t *a) PYJU_NOTSAFEPOINT;
void arraylist_grow(arraylist_t *a, size_t n) PYJU_NOTSAFEPOINT;

typedef struct {
    uint32_t len;
    uint32_t max;
    void **items;
    void *_space[SMALL_AL_N_INLINE];
} small_arraylist_t;

small_arraylist_t *small_arraylist_new(small_arraylist_t *a, uint32_t size) PYJU_NOTSAFEPOINT;
void small_arraylist_free(small_arraylist_t *a) PYJU_NOTSAFEPOINT;

void small_arraylist_push(small_arraylist_t *a, void *elt) PYJU_NOTSAFEPOINT;
void *small_arraylist_pop(small_arraylist_t *a) PYJU_NOTSAFEPOINT;
PYJU_DLLEXPORT void small_arraylist_grow(small_arraylist_t *a, uint32_t n) PYJU_NOTSAFEPOINT;

#ifdef __cplusplus
}
#endif

#endif
