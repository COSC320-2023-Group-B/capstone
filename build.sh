#!/bin/bash

# CFLAGS=""
CFLAGS="-Wall -Wextra -pedantic"
# CFLAGS+="Werror"

g++ $CFLAGS -o ./build/main.exe ./src/main.cpp

exit 0
