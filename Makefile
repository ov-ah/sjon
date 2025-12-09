CC = gcc
CFLAGS = -Wall -Wextra `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

all: sjon

sjon: sjon.o
	$(CC) sjon.o -o bin/sjon $(LDFLAGS)

sjon.o: sjon.c
	$(CC) $(CFLAGS) -c sjon.c

install: sjon
	cp bin/sjon /usr/local/bin/

clean: sjon
	rm -f *.o

.PHONY: install clean
