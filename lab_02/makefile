CC=gcc
CFLAGS=-Wall
DEPS = winograd.h functions.h
OBJ = winograd.o functions.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

win.out: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
		rm $(OBJ)

clean:
	rm $(OBJ) *.out
