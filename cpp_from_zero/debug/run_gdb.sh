#!/bin/bash -eu

pushd $1

# Run gdb
gdb ./bin/test -x ./command.gdb

popd
