#!/bin/sh

make clean
git pull origin master
./premake4 gmake
make
sh tools/updateTags.sh
./test
