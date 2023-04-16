#!/bin/bash -eu

pushd $1

# Build
bin_dir=./bin
mkdir -p ${bin_dir}
g++ -std=c++11 *.cpp -g -I. -o ${bin_dir}/test

popd
