CFLAGS=-Wall -g -DNDENUG

all : ex22_main

ex22_main: ex22.o

clean:
	rm -f ex1 *.o *.exe
	rm -rf *.dSYM

	