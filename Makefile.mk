
CC = g++

CFLAGS = -Wall

all: strip_all

strip_all: strip.o
	${CC} ${CFLAGS} strip.o -o strip

strip.o: strip.cpp
	${CC} ${CFLAGS} -c strip.cpp

clean:
	rm strip_all *.o
