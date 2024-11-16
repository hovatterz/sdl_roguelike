# Overview

This is for my personal refresh on C99.

Requirements:

- C compiler
- CMake version 3.31+
- cppcheck
- clang-format
- SDL2
- SDL2_image

For a Mac with Homebrew installed these dependencies can be installed with:

```
brew install gcc sdl2 sdl2_image cmake cppcheck clang-format
```

## Building

Debug

```
./build.sh
```

Release

```
BUILD_TYPE=Release ./build.sh
```

## Linting

```
./lint.sh
```

## Testing

```
./run_tests.sh
```

## Running

```
bin/roguelike
```
