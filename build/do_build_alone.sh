#!/usr/bin/env sh


# build dr client
# from http://dynamorio.org/docs:
# if a client is not using CMake, the appropriate compiler and linker flags
# can be gleaned from DynamoRIOConfig.cmake

DYNAMORIO_HOME=$HOME/install


# build sample application
gcc \
-I$DYNAMORIO_HOME/include/dr \
-DLINUX -DX86_32 \
-DUSE_DYNAMO=1 \
main.c fubar.c \
-L$DYNAMORIO_HOME/lib/dr/release \
-ldynamorio -ldrpreload \
-ldl
