# Complier
CC=g++
# Compilier options
CFLAGS=-c -Wall
all: main

main: main.o word_ladder.o
	$(CC) main.o word_ladder.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

word_ladder.o: word_ladder.cpp
	$(CC) $(CFLAGS) word_ladder.cpp

clean:
	rm -f *.o main