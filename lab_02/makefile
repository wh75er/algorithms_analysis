CC=gcc
CFLAGS=-Wall -g
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
	rm $(OBJ) $(OBJ_ENHANCE)

clean:
	rm $(OBJ) $(OBJ_ENHANCE) *.out 2> /dev/null
