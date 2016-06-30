#compiler
CC=gcc
#linker
LD=gcc
#include file directory
CFLAGS=-I.

#linker rule
testSort: main.o insertionSort.o BubbleSort.o SelectionSort.o
#	gcc -o testSort main.o insertionSort.o BubbleSort.o SelectionSort.o
	$(LD) -o testSort main.o insertionSort.o BubbleSort.o SelectionSort.o
	
#compiler rules
main.o: main.c
#gcc -c -I. main.c
	$(CC) -c $(CFLAGS) main.c	
	 
insertionSort.o: insertionSort.c
#gcc -c -I. insertionSort.c
	$(CC) -c $(CFLAGS) insertionSort.c
BubbleSort.o: BubbleSort.c
#gcc -c -I. BubbleSort.c
	$(CC) -c $(CFLAGS) BubbleSort.c	
SelectionSort.o: SelectionSort.c
#gcc -c -I. SelectionSort.c
	$(CC) -c $(CFLAGS) SelectionSort.c	

#clean up procedure		
clean:
	rm *.o
	rm testSort

