#!/bin/bash

CFLAGS="-Wall -Wextra -pedantic"
# CFLAGS+="Werror"

g++ $CFLAGS -o ./build/main.exe ./src/main.cpp
g++ $CFLAGS -o ./build/main2.exe ./src/main.c

# Stray Symbol: 