#!/usr/bin/env bash

if [[ -d build ]]
then
    echo "Directory exists"
else
    mkdir build
fi

if [[ -d "results/bin" ]] 
then
    echo "Directory exists"
else
    mkdir -p results/bin
fi

if [[ -d "results/lib" ]]
then
    echo "Directory exists"
else
    mkdir -p results/lib
fi

c++ -c -I include/ src/subtract.cpp -o build/subtract.o 
c++ -c -I include/ src/sum.cpp -o build/sum.o
ar rcs results/lib/libipb_arithmetic.a build/sum.o build/subtract.o
c++ -std=c++17 -c -I include/  src/main.cpp -o build/main.o
c++ -std=c++17 build/main.o -L results/lib/ -lipb_arithmetic -o results/bin/test_ipb_arithmetic