#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wformat="

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "vector.h"

// Initialize the vector types we will use.
void test_vector_string() {
    printf("================== TESTING STRINGS (pointers)...\n\n");

    typedef vector_t_init(char*) vector_string_t;

    // initialize the vector object.
    vector_string_t names;
    vector_init(&names);

    // Push 3 strings to the vector.
    vector_push(&names, "Jim");
    vector_push(&names, "Sally");
    vector_push(&names, "Jason");
    vector_push(&names, "Jenny");
    vector_push(&names, "James");

    // Print the vector out
    char printval[vector_sprint_len(&names, "%s")];
    vector_sprint(printval, &names, "%s");
    printf("printing vector...\n");
    printf("    %s\n", printval);
    printf("\n");

    // pop vector
    printf("popping value...\n");
    char* popped = vector_pop(&names);
    printf("    popped: %s\n", popped);

    printf("shifting value...\n");
    char* shifted = vector_shift(&names);
    printf("    shifted: %s\n", shifted);

    printf("setting value at index 1 to phil\n");
    vector_set(&names, 1, "phil");
    printf("    new value at index 1: %s\n", vector_get(&names, 1));
    printf("setting value at index 10 to jack\n");
    vector_set(&names, 10, "jack");
    printf("    new value at index 10: %s\n", vector_get(&names, 10));

    printf("unshifting value tod onto beginning of vector\n");
    vector_unshift(&names, "tod");
    printf("    new value at index 0: %s\n", vector_get(&names, 0));
    printf("\n");

    char printval_e[vector_sprint_len(&names, "%s")];
    vector_sprint(printval_e, &names, "%s");
    printf("printing vector...\n");
    printf("    %s\n", printval_e);
    printf("\n");

    // Free resources
    vector_finish(&names);
}

void test_vector_int() {
    printf("================== TESTING INTS (primitive)...\n\n");
    typedef vector_t_init(int) vector_int_t;

    vector_int_t ints;
    vector_init(&ints);

    vector_push(&ints, 1);
    vector_push(&ints, 2);
    vector_push(&ints, 3);
    vector_push(&ints, 4);
    vector_push(&ints, 5);
    vector_push(&ints, 6);
    vector_push(&ints, 7);

    char printval[vector_sprint_len(&ints, "%d")];
    vector_sprint(printval, &ints, "%d");
    printf("printing vector...\n");
    printf("    %s\n", printval);
    printf("\n");

    printf("popping value... ");
    char popped = (char)vector_pop(&ints);
    printf("popped: %d\n", popped);

    printf("shifting value... ");
    int shifted = vector_shift(&ints);
    printf("shifted: %i\n", shifted);

    printf("setting value at index 1 to 5\n");
    vector_set(&ints, 1, 5);
    printf("setting value at index 10 to 8\n");
    vector_set(&ints, 10, 8);

    printf("unshifting value 11 onto beginning of vector\n");
    vector_unshift(&ints, 11);

    printf("padding left side of vector to %d length with element 0\n", ints.count + 3);
    vector_pad(&ints, -(ints.count + 3), 0);
    printf("padding right side of vector to %d length with element 1\n", ints.count + 3);
    vector_pad(&ints, ints.count + 3, 1);
    printf("\n");

    char printval_e[vector_sprint_len(&ints, "%d")];
    vector_sprint(printval_e, &ints, "%d");
    printf("printing vector...\n");
    printf("    %s\n", printval_e);
    printf("\n");

    vector_finish(&ints);
}

void test_vector_char() {
    printf("================== TESTING CHARS (primitive)...\n\n");

    typedef vector_t_init(char) vector_char_t;

    vector_char_t chars;
    vector_init(&chars);

    vector_push(&chars, 'a');
    vector_push(&chars, 'b');
    vector_push(&chars, 'c');
    vector_push(&chars, 'd');
    vector_push(&chars, 'e');
    vector_push(&chars, 'f');
    vector_push(&chars, 'g');

    char printval[vector_sprint_len(&chars, "%c")];
    vector_sprint(printval, &chars, "%c");
    printf("printing vector...\n");
    printf("    %s\n", printval);
    printf("\n");

    printf("popping value...\n");
    char popped = (char)vector_pop(&chars);
    printf("    popped: %c\n", popped);

    printf("shifting value...\n");
    char shifted = (char)vector_shift(&chars);
    printf("    shifted: %c\n", shifted);

    printf("setting value at index 1 to S\n");
    vector_set(&chars, 1, 'S');
    printf("    new value at index 1: %c\n", (char)vector_get(&chars, 1));
    printf("setting value at index 10 to J\n");
    vector_set(&chars, 10, 'J');
    printf("    new value at index 10: %c\n", (char)vector_get(&chars, 10));

    printf("unshifting value T onto beginning of vector\n");
    vector_unshift(&chars, 'T');
    printf("    new value at index 0: %c\n", (char)vector_get(&chars, 0));
    printf("\n");

    char printval_e[vector_sprint_len(&chars, "%c")];
    vector_sprint(printval_e, &chars, "%c");
    printf("printing vector...\n");
    printf("    %s\n", printval_e);
    printf("\n");

    vector_finish(&chars);
}

int main(void) {
    
    test_vector_string();
    test_vector_int();
    test_vector_char();
}
