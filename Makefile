CC=gcc
FLAGS= -Wall -g

all:mybankd maind mains mybanks

mybanks:libMybank.a

mybankd:libMybank.so

libMybank.a:Mybank.o Mybank.h
	 ar rcs libMybank.a Mybank.o Mybank.h

libMybank.so:Mybank.o	Mybank.h
	$(CC) -shared -o libMybank.so  Mybank.o

Mybank.o: Mybank.c Mybank.h 
	$(CC) -fPIC -c Mybank.c

mains:main.o libMybank.a
	$(CC) $(FLAGS) -o  mains main.o libMybank.a 

maind:main.o libMybank.so
	$(CC) $(FLAGS) -o maind main.o ./libMybank.so 

main.o:main.c Mybank.h
	$(CC) -c main.c

.PHONY:clean 

clean:
	rm -f *.o *.a *.so mains maind


