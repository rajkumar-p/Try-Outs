# Complier
CC=g++
# Compilier options
CFLAGS=-c -Wall
all: main

main: main.o karatsuba.o
	$(CC) main.o karatsuba.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

karatsuba.o: karatsuba.cpp
	$(CC) $(CFLAGS) karatsuba.cpp

clean:
	rm -f *.o main