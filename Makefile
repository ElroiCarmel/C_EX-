CC = gcc
CFLAGS = -Wall -g
DEPS = StrList.h
OBJ = StrList.o Main.o

StrList : $(OBJ)
	$(CC) -o $@ $^

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o StrList

PHONY: clean