#!/bin/bash -e

rm -rf build
mkdir build
pushd src/jni
./header.sh
popd > /dev/null
pushd build > /dev/null
cmake ..
make
popd > /dev/null
cp build/src/jni/libaotlex_jni.so .. || true
cp build/src/jni/libaotlex_jni.dylib .. || true

