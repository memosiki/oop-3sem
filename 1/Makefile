CC = g++
FLAGS = -std=c++11
SOURCES = main.o Foursquare.o Triangle.o Octahedron.o
EXECUTABLE = start
all: build

build: main.o Foursquare.o Triangle.o Octahedron.o
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp Foursquare.h Triangle.h Octahedron.h
	$(CC) $(FLAGS) -c main.cpp

Foursquare.o: Foursquare.cpp Foursquare.h Figure.h
	$(CC) $(FLAGS) -c Foursquare.cpp

Triangle.o: Triangle.cpp Triangle.h Figure.h
	$(CC) $(FLAGS) -c Triangle.cpp

Octahedron.o: Octahedron.cpp Octahedron.h Figure.h
	$(CC) $(FLAGS) -c Octahedron.cpp

clean:
	rm -f $(SOURCES) $(EXECUTABLE)