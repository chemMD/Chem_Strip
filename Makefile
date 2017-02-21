
CC = g++

CFLAGS = -Wall

all: strip

strip: strip.o
	${CC} ${CFLAGS} strip.o -o strip

strip.o: strip.cpp
	${CC} ${CFLAGS} -c strip.cpp

clean:
	rm -rf strip.o
