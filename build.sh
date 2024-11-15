#!/bin/sh
cmake -B build -DCMAKE_BUILD_TYPE=${BUILD_TYPE}
(cd build && make)
