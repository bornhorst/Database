HEADERS	= repl.h
VPATH	= REPL/

default: all

compile: main.c REPL/repl.c
	gcc -o db main.c REPL/repl.c -w

run: 
	./db

clean:
	rm db
