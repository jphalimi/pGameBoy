CC=gcc
CFLAGS=-Wall -Wextra -O3
EXE=gbl

all:$(EXE)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXE): log/log.o main.o
	make -C log/ log.o
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	make -C log/ clean
	rm -rf *.o $(EXE)
