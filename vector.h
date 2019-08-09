#ifndef VECTOR_H
#define VECTOR_H

#include "stddef.h"
#include "stdlib.h"

struct vector {
    int count;
    void** elements;
};

struct vector* vector_init();
void vector_free(struct vector* v);
void* vector_get(struct vector *v, int idx);
void vector_set(struct vector *v, int idx, void* value);
void vector_push(struct vector *v, void* elem);
void* vector_pop(struct vector *v);
void vector_unshift(struct vector* v, void* elem);
void* vector_shift(struct vector* v);
void vector_pad(struct vector *v, int count, void* elem);
int vector_index_of(struct vector *v, void* elem);
int vector_is_empty(struct vector *v);

#endif //VECTOR_H
