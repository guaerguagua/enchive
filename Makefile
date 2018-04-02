.POSIX:
.SUFFIXES:
CC     = cc
CFLAGS = -ansi -pedantic -Wall -Wextra -O3 -g3
PREFIX = /usr/local

sources = src/main_test.c src/sha256.c
objects = $(sources:.c=.o)
headers = config.h src/sha256.h

enchive: $(objects)
	$(CC) $(LDFLAGS) -o $@ $(objects) $(LDLIBS)

src/sha256.o: src/sha256.c config.h





.PHONY:clean
clean:
	rm -f encrypt $(objects)

install: enchive
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f encrypt $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/encrypt

.SUFFIXES: .c .o
.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<
