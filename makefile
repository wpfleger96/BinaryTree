CC = g++
DEBUG = -g
CFLAGS = -std=gnu++11
FLAGS = -Wall -g $(DEBUG)

all: main

main: 
	$(CC) $(CFLAGS) -o main Main.cpp BinaryTree.cpp ItemType.cpp 

clean:
	rm -rf main