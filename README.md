# A library for managing Vectors in C

> See [test.sh](./test.sh) & [tests/test.c](./tests/test.c) for example usage.

## Creating a Vector

To create a vector you first need to initialize a type for it. You can do this using the `vector_init_t` macro.

```c
typedef vector_init_t(char) vector_char_t;
```

> There is one default type already built in
> ```c
> typedef vector_t_init(void*) vector_t_void;
>  ```

After your Vector type is defined, you will need to create an instance of it and initialize the instance using `vector_init()`. Once you are done using this vector, don't forget to release it using `vector_finish()`.

```c
typedef vector_t_init(char) vector_char_t;

int main() {
    vector_char_t v_char;
    vector_init(&v_char);

    // ... do something with the vector

    vector_finish(&v_char);
}
```

## Printing a Vector

You can print out a Vector to console fairly easily, just pass it a formatting string for each element in the vector.

* Print a Vector Directly
   ```c
   vector_print(&v_char, "%c");
   printf("\n");
   ```
* Print a Vector to a `char[]` buffer
   ```c
   // determine buffer length
   size_t len = vector_sprint_len(&v_char, "%c");
   // create the buffer
   char buf[len];
   // print to the buffer
   vector_sprint(buf, &v_char, "%c");
   ```

## Using a Vector

There are several built in functions for using a vector.

* `vector_get(&v_char, 3);`

   Retrieves the value from the vector at the specifid index. If the index is outside the bounds of the vector, `NULL` will be returned instead.

* `vector_set(&v_char, 3, 'a');`

   Sets the value at the specified index to `'a'`. If the specified index is less than `0`, the function will do simply return and do nothing. If the index is outside the upper bound of the vector, the vector will be padded out to the index using `NULL` values before the value is set.

* `vector_pop(&v_char);`

   Pops and returns the value of the last element of the vector, shortening the vector by one element. If the vector is empty, `NULL` will be returned.

* `vector_push(&v_char, 'b');`

   Pushes a new element onto the end of the Vector.

* `vector_unshift(&v_char, 'c');`

   Prepend an element to the beginning of a Vector.

* `vector_shift(&v_char);`

    Shifts the first value of the vector off and returns it, shortening the vector by one element and moving everything down. if the vector is empty, `NULL` will be returned.

* `vector_delete(&v_char, 3);`

   Removes the element at the specified index from the vector and updates the indices for the remaining elements if necessary. 

* `vector_pad(&v_char, 4, 'd');`

   Pad a vector to the specified length with an element. If length is positive then the vector is padded on the right, if it is negative then on the left. If the absolute value of length is less than or equal to the length of the vector then no padding takes place.

* `vector_index_of(&v_char, 'a');`

   Retrieve the first index of the specified element in the specified vector.

* `vector_is_empty(&v_char);`

   Determine if the vector is empty.

* `vector_clear(&v_char);`

   Clear out all elements from a vector and resize it to 0.




