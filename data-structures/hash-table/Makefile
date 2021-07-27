OBJS = hash-table-test.o hash-table.o singly-linked-list.o node.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hash-table-test

hash-table-test.o: hash-table-test.cc
	$(CC) $(CFLAGS) hash-table-test.cc

hash-table.o: hash-table.cc hash-table.h
	$(CC) $(CFLAGS) hash-table.cc

singly-linked-list.o: ../singly-linked-list/singly-linked-list.cc ../singly-linked-list/singly-linked-list.h
	$(CC) $(CFLAGS) ../singly-linked-list/singly-linked-list.cc

node.o: ../node/node.cc ../node/node.h
	$(CC) $(CFLAGS) ../node/node.cc

clean:
	\rm *.o hash-table-test