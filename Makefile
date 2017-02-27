
CC = g++

CFLAGS = -Wall

all: myprogram

myprogram: strip.o main.o
	${CC} ${CFLAGS} -o myprogram strip.o main.o

strip.o: strip.cpp
	${CC} ${CFLAGS} -c strip.cpp

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp
clean:
	rm myprogram *.o
