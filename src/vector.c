#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define internal(v) ((v_internal_t*)v)

struct v_internal {
    int count;
    void** elements;
} typedef v_internal_t;

void vector_init(void* v) {
    memset(v, 0, sizeof(*v));
    internal(v)->count = 0;
    void** elems = malloc(sizeof(void*) * internal(v)->count);
    memset(elems, 0, sizeof(void*) * internal(v)->count);
    internal(v)->elements = elems;
}

void vector_finish(void* v) {
    free(internal(v)->elements);
}

void vector_resize(void* v, int add) {
    internal(v)->count += add;
    internal(v)->elements = realloc(internal(v)->elements, sizeof(void*) * internal(v)->count);
}

void vector_set(void* v, int idx, void* value) {
    if (idx < 0) {
        return;
    }

    while (internal(v)->count <= idx) {
        vector_push(v, NULL);
    }

    internal(v)->elements[idx] = value;
}

void* vector_get(void* v, int idx) {
    if (idx >= internal(v)->count || idx < 0) {
        return NULL;
    }

    return internal(v)->elements[idx];
}

void vector_push(void* v, void* elem) {
    vector_resize(v, 1);
    internal(v)->elements[internal(v)->count - 1] = elem;
}

void* vector_pop(void* v) {
    if (internal(v)->count < 1) {
        return NULL;
    }
    void* result = internal(v)->elements[internal(v)->count - 1];
    vector_resize(v, -1);
    return result;
}

void vector_unshift(void* v, void* elem) {
    // append an empty element onto the end of the vector
    vector_resize(v, 1); 

    // Move everything to the right
    for (int i = internal(v)->count - 2; i > -1; i--) {
        internal(v)->elements[i + 1] = internal(v)->elements[i];
    }

    // Add the new element to the beginning of the vector.
    internal(v)->elements[0] = elem;
}

void* vector_shift(void* v) {
    void* result = internal(v)->elements[0];
    for (int i = 1; i < internal(v)->count; i++) {
        internal(v)->elements[i -1] = internal(v)->elements[i];
    }
    vector_resize(v, -1);
    return result;
}

void vector_delete(void* v, int idx) {
    for (int i = 0; i<internal(v)->count; i++) {
        if (i == idx) {
            internal(v)->elements[i] = NULL;
        } else if (i > idx) {
            internal(v)->elements[i-1] = internal(v)->elements[i];
        }
    }

    vector_resize(v, -1);
}

int vector_index_of(void* v, void* elem) {
    for (int i = 0; i < internal(v)->count; i++) {
        if (internal(v)->elements[i] == elem) {
            return i;
        }
    }

    return -1;
}

void vector_pad(void* v, int length, void* elem) {
    if (abs(length) <= internal(v)->count) {
        return;
    }

    int new_items = abs(length) - internal(v)->count;

    // pad left
    if (length < 0) {
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

int vector_is_empty(void *v) {
    return internal(v)->count < 1;
}

void vector_clear(void *v) {
    vector_resize(v, -(internal(v)->count));
}

size_t vector_sprint_len(void* v, char* element_fmt) {
    // get a larger buffer size just to be sure.
    return strlen(element_fmt) * (internal(v)->count^2);
}

void vector_sprint(char* buf, void* v, char* element_fmt) {
    memset(buf, 0, vector_sprint_len(v, element_fmt));
    strcpy(buf, "[");
    for (int i = 0; i<(internal(v)->count); i++) {
        void* val = internal(v)->elements[i];
        const char* fmt_val = (val == NULL) ? "%s" : element_fmt;
        val = (val == NULL) ? "NULL" : val;

        int len = snprintf(NULL, 0, fmt_val, val);
        char buffer[len + 1];
        int extra = snprintf(buffer, len + 1, fmt_val, val);
        strcat(buf, buffer);
        if (i < (internal(v)->count - 1)) {
            strcat(buf, ", ");
        }
    }
    strcat(buf, "]");
}

void vector_print(void* v, char* element_fmt) {
    char printval[vector_sprint_len(v, element_fmt)];
    vector_sprint(printval, v, element_fmt);
    printf("%s", printval);
}
