CFLAGS=-Wall
00=globalVariable
01=moves
11=strategy
12=model

dep=$(01).o $(11).o $(12).o

all:
	gcc model.c -o model

clean:
	rm *.o $(dep)
