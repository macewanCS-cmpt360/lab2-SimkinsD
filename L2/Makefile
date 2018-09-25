C = gcc
CFLAGS = -g -Wall -std=gnu99

.PHONY : all

all : q1 q2 q3 q7 shell

q% : q%.c
	$(CC) $(CFLAGS) -o $@ $^

shell : shell.c
	$(CC) $(CFLAGS) -o $@ $^
