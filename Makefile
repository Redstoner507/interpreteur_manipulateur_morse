#Variables
CC = gcc
CFLAGS = -O3 -Wall -Wextra
LDLIBS = -lgpiod

SRC = morse.c
OBJ = $(SRC:.c=.o)

all: morse

morse: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f morse
