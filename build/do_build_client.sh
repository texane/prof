#!/usr/bin/env sh


# build dr client
# from http://dynamorio.org/docs:
# if a client is not using CMake, the appropriate compiler and linker flags
# can be gleaned from DynamoRIOConfig.cmake

DYNAMORIO_HOME=$HOME/install

gcc \
-fPIC -shared -nostartfiles -nodefaultlibs -lgcc \
-DLINUX -DX86_32 \
-o fubar.so \
-I$DYNAMORIO_HOME/include/dr fubar.c

# build sample application
gcc \
-I$DYNAMORIO_HOME/include/dr \
-DLINUX -DX86_32 \
main.c \
-L$DYNAMORIO_HOME/lib/dr/release \
-ldynamorio