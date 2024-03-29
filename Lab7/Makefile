# Makefile for linsrch
# Minas Spetsakis, Mar. 2024

SRC = main.c linsrch.c
HDR = linsrch.h
OBJ = main.o linsrch.o

TRG = lindb

# SRC is the list of all source (.c) files. Not really needed here.
# OBJ is the list of all object (.o) files. Object files are the compiled
#     versions of the corresponding source files.
# HDR is the list of all the (.h) header files. Header files contain
#     global variable declarations, type definitions and #defines of macros
# TRG is the target file. This is the executable file where all the .o
#     files will be assembled into.
#     See is the \ works...

${TRG}:${OBJ}
	gcc ${OBJ} -o ${TRG}

main.o: main.c ${HDR}
	gcc -c main.c -o main.o

linsrch.o: linsrch.c ${HDR}
	gcc -c linsrch.c -o linsrch.o

clean:
	rm -f ${OBJ} ${TRG}

