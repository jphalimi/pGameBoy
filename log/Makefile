CC=gcc
CFLAGS=-Wall -Wextra -O3

%.o: %.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -rf *.o
