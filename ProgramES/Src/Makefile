CFLAGS=-Wall
01=moves
11=strategy
12=model

dep=$(01).o $(11).o $(12).o

all: $(dep)
	gcc $(dep) main.c $(LIBS) -o main

$(01).o: $(01).c $(01).h
	gcc -c $(01).c -o $(01).o

$(11).o: $(11).c
	gcc -c $(11).c -o $(11).o

$(12).o: $(12).c $(12).h
	gcc -c $(12).c -o $(12).o

default: main

run:
	main $(ARGS)

clean:
	rm *.o $(dep)