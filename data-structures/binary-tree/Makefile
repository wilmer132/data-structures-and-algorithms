OBJS = binary-tree-test.o binary-tree.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o binary-tree-test

binary-tree-test-.o: binary-tree-test.cc binary-tree.h
	$(CC) $(CFLAGS) binary-tree-test-.cc

binary-tree.o: binary-tree.cc binary-tree.h
	$(CC) $(CFLAGS) binary-tree.cc

clean:
	\rm *.o binary-tree-test