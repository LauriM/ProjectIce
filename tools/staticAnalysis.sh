#!/bin/sh

#Run inside the root of the project

make clean && scan-build -v -analyzer-check-objc-missing-dealloc --experimental-checks --use-c++=clang++ make
