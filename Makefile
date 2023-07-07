# Activity 6

CC=gcc -std=c99

all: overfl

overfl: check_overflow.c
	${CC} -o overfl check_overflow.c

clean:
	rm -f overfl