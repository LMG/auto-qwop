CFLAGS := -Wall -std=c99 -D_POSIX_SOURCE

main: input.o util.o constants.h main.c
	gcc -o main main.c input.o util.o -lX11 -lXtst $(CFLAGS)

input.o: input.c input.h
	gcc -o input.o -c input.c $(CFLAGS)
	
util.o: util.c util.h
	gcc -o util.o -c util.c $(CFLAGS)
	
clean:
	rm *.o main
	
doc:
	doxygen doc/doxyConfig
