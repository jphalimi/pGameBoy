CC=gcc
CFLAGS=-Wall -Wextra -O3
EXE=gbl

LOGFOLDER=log

SOURCES=$(wildcard *.c) $(wildcard $(LOGFOLDER)/*.c)
OBJ=$(SOURCES:.c=.o)

all:$(EXE)

obj/%.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

$(EXE): $(OBJ)
	make -C $(LOGFOLDER)/ log.o -s
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	make -C $(LOGFOLDER)/ clean -s
	rm -rf *.o $(EXE)
