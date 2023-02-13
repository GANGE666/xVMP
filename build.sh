#!/bin/bash
cd "$(dirname "$0")"

if [ ! -d "build" ]; then
    mkdir build
    cd build
#    cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -GNinja -DCMAKE_BUILD_TYPE="Release" ../src
    cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DCMAKE_BUILD_TYPE="Release" ../src
else
    cd build
fi


cmake --build .

