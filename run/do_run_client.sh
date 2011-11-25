#!/usr/bin/env bash

export DYNAMORIO_HOME=$HOME/install
export LD_LIBRARY_PATH=$DYNAMORIO_HOME/lib/dr/release:.
export LD_PRELOAD="libdrpreload.so libdynamorio.so"

$HOME/install/bin/dr/drrun -client $PWD/fubar.so 0 "" \
./a.out
