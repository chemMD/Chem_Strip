
CC = g++

CFLAGS = -Wall

all: stl_collection

stl_collection: car.o car_db.o stl_collection.o
	${CC} ${CFLAGS} car.o car_db.o stl_collection.o -o stl_collection

car.o: car.cpp
	${CC} ${CFLAGS} -c car.cpp

car_db.o: car_db.cpp
	${CC} ${CFLAGS} -c car_db.cpp
	
stl_collection.o: stl_collection.cpp
	${CC} ${CFLAGS} -c stl_collection.cpp

clean:
	rm stl_collection *.o
