#!/bin/bash -eu

bin_dir=./bin
mkdir -p ${bin_dir}

# Build
g++ -std=c++11 sample.cpp sample_test.cpp -o ${bin_dir}/test -L/usr/local/lib -lgtest -lgtest_main -lpthread

# Run
${bin_dir}/test
