CFLAG=-lrt
sources = src/main_test.c src/sha256.c
objects = $(sources:.c=.o)
headers = src/sha256.h

encrypt: $(objects)
	cc $(CFLAG) -o $@ $(objects)

src/sha256.o: src/sha256.c

clean:
	rm -f encrypt $(objects)

.SUFFIXES: .c .o
.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<