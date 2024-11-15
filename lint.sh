#!/bin/sh

cppcheck --std=c99 src/* test/*
clang-format -i --style=LLVM src/* test/*
