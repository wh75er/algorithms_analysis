CC=gcc
CFLAGS=-Wall -O0
DEPS = winograd.h functions.h
OBJ = winograd.o functions.o
OBJ_ENHANCE = winograd_enhanced.o functions.o
OBJ_TEST = test_time.o functions.o

all: win.out win_enhanced.out test_time.out cleanOBJ

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

win.out: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

win_enhanced.out: $(OBJ_ENHANCE)
		$(CC) -o $@ $^ $(CFLAGS)

test_time.out: $(OBJ_TEST)
		$(CC) -o $@ $^ $(CFLAGS)

cleanOBJ:
	rm *.o

clean:
	rm *.o *.out 2> /dev/null
