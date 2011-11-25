#!/usr/bin/env bash

export PROF_HOME=`pwd`

export DYNAMORIO_HOME=$HOME/install
export LD_LIBRARY_PATH=$DYNAMORIO_HOME/lib/dr/release:$PROF_HOME/build
export DYNAMORIO_OPTIONS='-code_api'

$PROF_HOME/build/a.out
