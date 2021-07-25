OBJS = singly-linked-list-test.o singly-linked-list.o node.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o singly-linked-list-test

singly-linked-list-test.o: singly-linked-list-test.cc
	$(CC) $(CFLAGS) singly-linked-list-test.cc

singly-linked-list.o: singly-linked-list.cc singly-linked-list.h
	$(CC) $(CFLAGS) singly-linked-list.cc

node.o: ../node/node.cc ../node/node.h
	$(CC) $(CFLAGS) ../node/node.cc

clean:
	\rm *.o singly-linked-list-test