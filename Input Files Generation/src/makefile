# Complier
CC=g++
# Compilier options
CFLAGS=-c -Wall
# Location of the boost include libraries
BOOST=-I/opt/local/include/
all: main

main: main.o input_files_generation.o
	$(CC) main.o input_files_generation.o -o main

main.o: main.cpp
	$(CC) $(BOOST) $(CFLAGS) main.cpp

input_files_generation.o: input_files_generation.cpp
	$(CC) $(BOOST) $(CFLAGS) input_files_generation.cpp

clean:
	rm -f *.o main