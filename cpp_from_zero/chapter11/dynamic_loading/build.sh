#!/bin/bash -eu

bin_dir=./bin
mkdir -p ${bin_dir}

# Compile
g++ -std=c++11 -c add.cpp
g++ -std=c++11 -c sub.cpp

# Make a shared library "libfoo.so"
lib="${bin_dir}/libfoo.so"
g++ -std=c++11 -shared -o ${lib} add.o sub.o

# Display symbol names in the library
nm ${lib} > symbols.txt

# Display demangled symbol names
nm ${lib} | c++filt

# Compile main and specify dynamic loading
out="${bin_dir}/foo"
g++ -std=c++11 -c main.cpp
g++ -std=c++11 main.o -I. -ldl -o ${out}

# Display dependencies of the library
echo "ldd ${lib}"
ldd ${lib}

# Specify directories which store shared libraries
export LD_LIBRARY_PATH=${bin_dir}

# Display dependencies of an output binary
echo "ldd ${out}"
ldd ${out}

rm *.o
