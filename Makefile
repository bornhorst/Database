HEADERS	= repl.h
VPATH	= REPL/

default: all

all: main.c REPL/repl.c
	gcc -o db main.c REPL/repl.c -w
