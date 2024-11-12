# Overview

This is for my personal refresh on C99.

Requirements:

- C compiler
- CMake version 3.31+
- cppcheck
- clang-format

## Building

```
mkdir -p cmake
cd cmake
cmake ..
make
../bin/c_refresh
```

## Linting

```
cppcheck --std=c99 src/
clang-format -i src/*
```
