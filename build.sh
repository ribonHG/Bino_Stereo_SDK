#!/bin/sh 

echo "start build ..."

mkdir build
mkdir bin

cd build

cmake ..

make -j3

cd ..

echo "OK"

