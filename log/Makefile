CC=gcc
CFLAGS=-Wall -Wextra -O3

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf *.o
