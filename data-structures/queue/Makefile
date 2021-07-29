OBJS = queue-test.o queue.o node.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o queue-test

queue-test.o: queue-test.cc
	$(CC) $(CFLAGS) queue-test.cc

queue.o: queue.cc queue.h
	$(CC) $(CFLAGS) queue.cc

node.o: ../node/node.cc ../node/node.h
	$(CC) $(CFLAGS) ../node/node.cc

clean:
	\rm *.o queue-test