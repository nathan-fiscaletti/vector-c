#include "vector.h"

struct vector* vector_init() {
    struct vector *result = (struct vector*)malloc(sizeof(struct vector));
    result->count = 0;
    result->elements = malloc(sizeof(void*) * result->count);
    return result;
}

void vector_free(struct vector* v) {
    free(v->elements);
    free(v);
}

void vector_resize(struct vector* v, int add) {
    v->count += add;
    v->elements = realloc(v->elements, sizeof(void*) * v->count);
}

void vector_set(struct vector* v, int idx, void* value) {
    while (v->count >= idx) {
        vector_push(v, NULL);
    }

    v->elements[idx] = value;
}

void* vector_get(struct vector* v, int idx) {
    if (idx > v->count || idx < 0) {
        return NULL;
    }

    return v->elements[idx];
}

void vector_push(struct vector* v, void* elem) {
    vector_resize(v, 1);
    v->elements[v->count - 1] = elem;
}

void* vector_pop(struct vector* v) {
    void* result = v->elements[v->count - 1];
    vector_resize(v, -1);
    return result;
}

void vector_unshift(struct vector* v, void* elem) {
    vector_resize(v, 1);
    for (int i = v->count - 2; i > -1; i--) {
        v->elements[i + 1] = v->elements[i];
    }
    v->elements[0] = elem;
}

void* vector_shift(struct vector* v) {
    void* result = v->elements[0];
    for (int i = 1; i < v->count; i++) {
        v->elements[i -1] = v->elements[i];
    }
    vector_resize(v, -1);
    return result;
}

void vector_delete(struct vector* v, int idx) {
    // TODO
}

int vector_index_of(struct vector *v, void* elem) {
    for (int i = 0; i < v->count; i++) {
        if (v->elements[i] == elem) {
            return i;
        }
    }

    return -1;
}

void vector_pad(struct vector *v, int count, void* elem) {
    if (abs(count) <= v->count) {
        return;
    }

    int new_items = abs(count) - v->count;

    // pad left
    if (count < 0) {
        while (new_items) {
            vector_unshift(v, elem);
            new_items--;
        }
    } 
    
    // pad right
    else {
        while (new_items) {
            vector_push(v, elem);
            new_items--;
        }
    }
}

int vector_is_empty(struct vector *v) {
    return v->count < 1;
}
