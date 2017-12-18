CC = g++
FLAGS = -std=c++11 
SOURCES = main.o TList.o TListItem.o Foursquare.o Triangle.o Octahedron.o
EXECUTABLE = start
all: build

build: $(SOURCES)
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp TList.h TListItem.h 
	$(CC) $(FLAGS) -c main.cpp

TList.o: TList.cpp TList.h Figure.h Foursquare.h Octahedron.h Triangle.h
	$(CC) $(FLAGS) -c TList.cpp

TListItem.o: TListItem.cpp TListItem.h Figure.h Foursquare.h Octahedron.h  Triangle.h
	$(CC) $(FLAGS) -c TListItem.cpp

Foursquare.o: Foursquare.cpp Foursquare.h Figure.h
	$(CC) $(FLAGS) -c Foursquare.cpp

Triangle.o: Triangle.cpp Triangle.h Figure.h
	$(CC) $(FLAGS) -c Triangle.cpp

Octahedron.o: Octahedron.cpp Octahedron.h Figure.h
	$(CC) $(FLAGS) -c Octahedron.cpp

clean:
	rm -f $(SOURCES) $(EXECUTABLE)