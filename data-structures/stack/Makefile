OBJS = stack-test.o stack.o node.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o stack-test

stack-test.o: stack-test.cc
	$(CC) $(CFLAGS) stack-test.cc

stack.o: stack.cc stack.h
	$(CC) $(CFLAGS) stack.cc

node.o: ../node/node.cc ../node/node.h
	$(CC) $(CFLAGS) ../node/node.cc

clean: 
	\rm *.o stack-test