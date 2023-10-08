CC = g++
CFLAGS = -Wall -g
 
main: main.o Board.o
	$(CC) $(CFLAGS) -o main main.o Board.o

main.o: main.cpp Board.h
	$(CC) $(CFLAGS) -c main.cpp

Board.o: Board.h
