#!/bin/sh

#Change to source root
cd src/

#Remove old proto stuff
rm proto/*.cc
rm proto/*.h

#recompile protos
protoc --cpp_out=. proto/*.proto

cd ..

echo "done"
