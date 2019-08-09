#!/bin/bash

gcc test.c -o test.o -c
gcc vector.c -o vector.o -c
gcc -o test test.o vector.o
./test
