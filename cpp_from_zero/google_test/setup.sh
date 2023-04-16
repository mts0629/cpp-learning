#!/bin/bash -eu

# Download googletest archive (v1.8.1)
mkdir -p tmp && cd tmp
wget "https://github.com/google/googletest/archive/release-1.8.1.tar.gz"
tar zxvf release-1.8.1.tar.gz

# Build and install
cd googletest-release-1.8.1
mkdir -p build && cd build
cmake .. && make && sudo make install
