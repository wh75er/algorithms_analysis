CC=gcc
CFLAGS=-Wall -O0
DEPS = sort.h functions.h
OBJ_BUBBLE = bubbleSort.o functions.o
OBJ_INSERT = insertSort.o functions.o
OBJ_MERGE = mergeSort.o functions.o
OBJ_TEST = test_time.o functions.o

all: bubble.out insert.out merge.out test_time.out cleanOBJ

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

bubble.out: $(OBJ_BUBBLE)
		$(CC) -o $@ $^ $(CFLAGS)

insert.out: $(OBJ_INSERT)
		$(CC) -o $@ $^ $(CFLAGS)

merge.out: $(OBJ_MERGE)
		$(CC) -o $@ $^ $(CFLAGS)

test_time.out: $(OBJ_TEST)
		$(CC) -o $@ $^ $(CFLAGS)

cleanOBJ:
	rm *.o

clean:
	rm *.o *.out 2> /dev/null
