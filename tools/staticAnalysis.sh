#!/bin/sh

#Run inside the root of the project

make clean && scan-build -v --use-c++=clang++ make
