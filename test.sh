#!/bin/bash

set -e

echo "# gcc vector.c -o vector.o -c"
gcc -I./src ./src/vector.c -o ./build/vector.o -c
echo "# gcc vector.c -o vector.o -c - DONE"
echo ""

echo "# gcc test.c -o test.o -c"
gcc -I./src ./tests/test.c -o ./build/test.o -c
echo "# gcc test.c -o test.o -c - DONE"
echo ""

echo "# gcc -o test test.o vector.o"
gcc -o ./build/test ./build/test.o ./build/vector.o
echo "# gcc -o test test.o vector.o - DONE"
echo ""

echo "# ./test"
./build/test
echo "# ./test - DONE"

echo "# rm ./build/test.o"
rm ./build/test.o
echo "# rm ./build/vector.o"
rm ./build/vector.o
echo "# rm ./build/test"
rm ./build/test
