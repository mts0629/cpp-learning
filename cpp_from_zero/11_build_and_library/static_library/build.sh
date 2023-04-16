#!/bin/bash -eu

bin_dir=./bin
mkdir -p ${bin_dir}

# Compile
g++ -std=c++11 -c add.cpp
g++ -std=c++11 -c sub.cpp

# Make a static library "libfoo.a"
lib="${bin_dir}/libfoo.a"
ar rc ${lib} add.o sub.o

# Display a list of included object files
echo "ar t ${lib}"
ar t ${lib}

# Compile main and link statically
g++ -std=c++11 -c main.cpp
g++ -std=c++11 main.o -I. ${lib} -o ${bin_dir}/foo
# Or
# g++ -std=c++11 main.o -I. -L${bin_dir} -lfoo -o ${bin_dir}/foo

rm *.o
