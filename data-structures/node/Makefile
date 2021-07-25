# make is a utility that automates compilation
# it is invoked with "make" at the os prompt

OBJS = node-test.o node.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o node-test

node-test.o: node-test.cc node.h
	$(CC) $(CFLAGS) node-test.cc

node.o : node.cc node.h
	$(CC) $(CFLAGS) node.cc

clean:
	\rm *.o node-test