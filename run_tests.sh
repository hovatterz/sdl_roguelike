#!/bin/sh
cmake --build build --config Debug --target all
(cd build && ctest -C Debug --output-on-failure)
