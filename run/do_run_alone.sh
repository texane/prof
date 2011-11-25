#!/usr/bin/env bash

export DYNAMORIO_HOME=$HOME/install
export LD_LIBRARY_PATH=$DYNAMORIO_HOME/lib/dr/release:.
export DYNAMORIO_OPTIONS='-code_api'
./a.out
