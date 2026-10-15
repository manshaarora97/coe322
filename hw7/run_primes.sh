#!/bin/bash
# Build with CMake and run the primes program with 10 primes.
set -e
cmake -S . -B build -DCMAKE_CXX_COMPILER=icpx
cmake --build build
echo 10 | ./build/primes
