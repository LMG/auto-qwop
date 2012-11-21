main: input.o main.c
	gcc -o main main.c input.o -lX11 -lXtst -Wall -std=c99 -D_POSIX_SOURCE

input.o: input.c input.h
	gcc -o input.o -c input.c -Wall
