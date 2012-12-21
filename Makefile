CFLAGS := -Wall -std=c99 -D_POSIX_SOURCE

main: input.o util.o algorithm.o constants.h main.c
	gcc -o main main.c input.o util.o algorithm.o -lX11 -lXtst $(CFLAGS)

input.o: input.c input.h
	gcc -o input.o -c input.c $(CFLAGS)
	
util.o: util.c util.h
	gcc -o util.o -c util.c $(CFLAGS)

algorithm.o: algorithm.c algorithm.h
	gcc -o algorithm.o -c algorithm.c $(CFLAGS)

mrproper: clean
	rm main

clean:
	rm *.o
	rm *~
	
doc:
	doxygen doc/doxyConfig
