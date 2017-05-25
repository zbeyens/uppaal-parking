CFLAGS=-Wall
01=compilor

dep=$(01).o

all: $(dep)
	g++ $(dep) main.cpp $(LIBS) -o main -std=c++11

$(01).o: $(01).cpp
	g++ -c $(01).cpp -o $(01).o

default: main

run:
	main $(ARGS)

clean:
	rm *.o $(dep)