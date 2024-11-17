CC = gcc
CFLAGS = -Wall -Wextra -g -O2

all: main

main: main.c btree.o repl.o database.o
    $(CC) $(CFLAGS) main.c btree.o repl.o database.o -o main

btree.o: btree.c btree.h
    $(CC) $(CFLAGS) -c btree.c

repl.o: repl.c repl.h
    $(CC) $(CFLAGS) -c repl.c

database.o: database.c database.h
    $(CC) $(CFLAGS) -c database.c

clean:
    rm -f *.o main
    
gcc -Wall -Wextra -g main.c database.c btree.c -o main
