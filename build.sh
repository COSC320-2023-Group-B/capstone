#!/bin/bash

# CFLAGS=""
CFLAGS="-Wall -Wextra -pedantic"
# CFLAGS+="Werror"

g++ $CFLAGS -o ./build/main.exe ./src/main.cpp -Lctlibrary-windows-v1.6.5/Win64 -lcaretaker_static

# Stray Symbol: 