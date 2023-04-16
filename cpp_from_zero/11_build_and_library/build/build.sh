#!/bin/bash -eu

# Preprocess
g++ -std=c++11 -E main.cpp > main.cpp.preprocess

bin_dir=./bin
mkdir -p ${bin_dir}

# Compile
g++ -std=c++11 -c main.cpp
g++ -std=c++11 -c util.cpp

# Link
g++ -std=c++11 main.o util.o -I. -o ${bin_dir}/hello

rm *.o
