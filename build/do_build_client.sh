#!/usr/bin/env sh


# build dr client
# from http://dynamorio.org/docs:
# if a client is not using CMake, the appropriate compiler and linker flags
# can be gleaned from DynamoRIOConfig.cmake

DYNAMORIO_HOME=$HOME/install
PROF_HOME=`pwd`

gcc \
-fPIC -shared -nostartfiles -nodefaultlibs -lgcc \
-DLINUX -DX86_32 \
-o $PROF_HOME/build/fubar.so \
-I$DYNAMORIO_HOME/include/dr \
$PROF_HOME/src/fubar.c

# build sample application
gcc \
-I$DYNAMORIO_HOME/include/dr \
-DLINUX -DX86_32 \
-o $PROF_HOME/build/a.out \
$PROF_HOME/src/main.c \
-L$DYNAMORIO_HOME/lib/dr/release \
-ldynamorio