CC = g++
FLAGS = -std=c++11 
SOURCES = main.o TList.o Octahedron.o
EXECUTABLE = start
all: build

build: main.o TList.o Octahedron.o
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp Octahedron.h
	$(CC) $(FLAGS) -c main.cpp

TList.o: TList.cpp TList.h Figure.h
	$(CC) $(FLAGS) -c TList.cpp

Octahedron.o: Octahedron.cpp Octahedron.h Figure.h
	$(CC) $(FLAGS) -c Octahedron.cpp

clean:
	rm -f $(SOURCES) $(EXECUTABLE)