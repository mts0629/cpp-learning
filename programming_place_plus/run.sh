#!/bin/bash -eu

OPTIONS="-std=c++14"

BIN_DIR=./bin

build_and_run() {
    src_list=""

    if [ -d $1 ]; then
        src_dir=$1
        for f in $(find ${src_dir} -type f -name *.cpp); do
            src_list="${src_list} $f"
        done

        OPTIONS="${OPTIONS} -I${src_dir}"
        target="${BIN_DIR}/$(basename ${src_dir})"
    else
        src_list=$1

        target="${BIN_DIR}/$(basename ${src_list/.cpp/})"
    fi

    mkdir -p ${BIN_DIR}

    g++ ${OPTIONS} ${src_list} -o ${target}

    ./${target}
}

usage() {
    echo "Build and run sample programs"
    echo "Usage:"
    echo "  run.sh source_file.cpp"
    echo "  run.sh directory_to_source_files"
    echo "Notes:"
    echo "  - './bin' directory is created for build outputs"
}

if [ $# -lt 1 ]; then
    usage
    exit 1
fi

build_and_run $@
