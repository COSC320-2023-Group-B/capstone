CCOMPILER := g++
CFLAGS := -Wall -Wextra -pedantic
# CFLAGS+="Werror"

all: main.exe main2.exe

main.exe:
	${CCOMPILER} ${CFLAGS} -o ./build/main.exe ./src/main.cpp

main2.exe:
	${CCOMPILER} ${CFLAGS} -o ./build/main2.exe ./src/main.c

