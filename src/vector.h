#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

/**
 * @brief Initializes a new vector type.
 * @param T The type that the Vector contains.
 */
#define vector_t_init(T) struct { int count; T* elements; }

/**
 * @brief base vector types.
 */
typedef vector_t_init(void*) vector_t_void;

/**
 * @brief Initialize a new Vector. Make sure you free this vector later using vector_free().
 * @param T the type of object that this vector wraps.
 * @see vector_free()
 */
void vector_init(void* v);

/**
 * @brief Release any resources bound by the vector.
 * @param v The vector to free.
 */
void vector_finish(void* v);

/**
 * @breif Retrieve an element from a Vector at the specified index.
 * @param v   The Vector.
 * @param idx The index.
 */
void* vector_get(void* v, int idx);

/**
 * @brief Set the value for an element within the vector at the specified index.
 * @param v     The Vector.
 * @param idx   The Index.
 * @param value The Value.
 */
void vector_set(void* v, int idx, void* value);

/**
 * @brief Pops and returns the value of the last element of the vector, shortening the vector by one element.
 * @param v The Vector.
 * @return The value of the last element of the vector. If the vector is empty, NULL will be returned.
 */
void* vector_pop(void* v);

/**
 * @brief Push a new element onto the end of a vector.
 * @param v    The Vector.
 * @param elem The element.
 */
void vector_push(void* v, void* elem);

/**
 * @brief Prepend an element to the beginning of a Vector.
 * @param v    The Vector.
 * @param elem The element.
 */
void vector_unshift(void* v, void* elem);

/**
 * @brief Shifts the first value of the vector off and returns it, shortening the vector by one element and moving everything down.
 * @param v The Vector.
 * @return The shifted value, or NULL if the vector is empty.
 */
void* vector_shift(void* v);

/**
 * @brief Removes the element at the specified index from the vector and updates the indices for the remaining elements if necessary. 
 * @param v   The Vector.
 * @param idx The Index.
 */
void vector_delete(void* v, int idx);

/**
 * @brief Pad a vector to the specified length with an element. If count is positive then the vector is padded on the right, if it is negative then on the left. If the absolute value of count is less than or equal to the length of the vector then no padding takes place.
 * @param v      The Vector.
 * @param length The new Length.
 * @param elem   The Element.
 */
void vector_pad(void* v, int length, void* elem);

/**
 * @brief Retrieve the first index of the specified element in the specified vector.
 * @param v    The Vector.
 * @param elem The Element.
 * @return The first index of the specified element.
 */
int vector_index_of(void* v, void* elem);

/**
 * @brief Determine if the vector is empty.
 * @param v The Vector.
 * @return non-zero if the vector is empty, 0 otherwise.
 */
int vector_is_empty(void* v);

/**
 * @brief Clear out all elements from a vector and resize it to 0.
 * @param v The Vector.
 */
void vector_clear(void* v);

/**
 * @brief Determine the length of a printed version of a vector using a format for each element.
 * @param v           The Vector.
 * @param element_fmt The format for each element.
 */
size_t vector_sprint_len(void* v, char* element_fmt);

/**
 * @brief Print the vector out to a buffer.
 * @param buf         The buffer to print to.
 * @param v           The Vector.
 * @param element_fmt The format for each element.
 */
void vector_sprint(char* buf, void* v, char* element_fmt);

/**
 * @brief Print a vector out using the specified format for each element.
 * @param v           The Vector.
 * @param element_fmt The format for each element.
 */
void vector_print(void* v, char* element_fmt);

#endif //VECTOR_H
