CCOMPILER := g++
CFLAGS := -Wall -Wextra -pedantic
# CFLAGS+="Werror"
LIB_PATH := ./ctlibrary-windows-v1.6.5/Win64/libcaretaker_static.lib
SYSTEM_LIBS := -lsetupapi

all: main.exe main2.exe

main.exe:
	${CCOMPILER} ${CFLAGS} ${LIB_PATH} ${SYSTEM_LIBS} -o ./build/main.exe ./src/main.cpp

main2.exe:
	${CCOMPILER} ${CFLAGS} -o ./build/main2.exe ./src/main.c

