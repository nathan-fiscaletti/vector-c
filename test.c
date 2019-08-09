#include "stdio.h"
#include "vector.h"

int main(void) {
    // initialize the vector object.
    struct vector* v = vector_init();

    // Push 3 strings to the vector.
    char* c = "test";
    char* c2 = "test2";
    char* c3 = "test3";
    vector_push(v, c);
    vector_push(v, c2);
    vector_push(v, c3);

    // Push three integers to the vector.
    int i = 3;
    int i2 = 4;
    int i3 = 5;
    vector_push(v, &i);
    vector_push(v, &i2);
    vector_push(v, &i3);

    // Pop the last element off of the vector.
    printf("popping...\n");
    int popped = *(int*)vector_pop(v);
    printf("popped: %d\n\n", popped);

    // Unshift an element on to the beginning of the vector.
    printf("unshifting...\n");
    char* shiftme = "shift me";
    vector_unshift(v, shiftme);

    // shift an element off of the beginning of the vector.
    printf("shifting...\n");
    printf("shifted: %s\n\n", (char*)vector_shift(v));

    int i9 = 9;
    printf("pading to index 9 with value %d...\n\n", i9);
    vector_pad(v, 10, &i9);

    // loop through the vector printing each value.
    printf("printing...\n");
    for (int i = 0; i < v->count; i++) {
        if (i < 3) {
            printf("index %d: %s\n", i, (char*)vector_get(v, i));
        } else {
            printf("index %d: %d\n", i, *((int*)vector_get(v, i)));
        }
    }
    printf("\n");

    // Retrieve the index of the last element.
    printf("getting index of %d...\n", i2);
    printf("index of %d: %d\n", i2, vector_index_of(v, &i2));

    // free the vector object.
    vector_free(v);
}
