#!/usr/bin/env bash

export PROF_HOME=`pwd`

export DYNAMORIO_HOME=$HOME/install
export LD_LIBRARY_PATH=$DYNAMORIO_HOME/lib/dr/release:.
export LD_PRELOAD="libdrpreload.so libdynamorio.so"

$DYNAMORIO_HOME/bin/dr/drrun -client $PROF_HOME/build/fubar.so 0 "" \
$PROF_HOME/build/a.out
