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

For Ubuntu:

```
sudo add-apt-repository -y "deb http://archive.ubuntu.com/ubuntu `lsb_release -sc` main universe restricted multiverse"
sudo apt-get update -y -qq
sudo apt-get install build-essential cmake cppcheck clang-format libsdl2-dev libsdl2-image-dev
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
