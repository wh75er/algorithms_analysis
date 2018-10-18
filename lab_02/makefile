CC=gcc
CFLAGS=-Wall
DEPS = winograd.h functions.h
OBJ = winograd.o functions.o
OBJ_ENHANCE = winograd_enhanced.o functions.o

all: win.out win_enhanced.out cleanOBJ

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

win.out: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

win_enhanced.out: $(OBJ_ENHANCE)
		$(CC) -o $@ $^ $(CFLAGS)

cleanOBJ:
	rm $(OBJ)

clean:
	rm $(OBJ) *.out 2> /dev/null
