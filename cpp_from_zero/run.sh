#!/bin/bash -eu

OPTIONS="-std=c++14"

BIN_DIR=./bin

build_and_run() {
    src=$1

    target="${BIN_DIR}/$(basename ${src/.cpp/})"

    mkdir -p ${BIN_DIR}

    g++ ${OPTIONS} ${src} -o ${target}

    ./${target}
}

build_and_run $@
