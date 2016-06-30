#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <insertionSort.h>
#include <BubbleSort.h>
#include <SelectionSort.h>
//add new header files for sort1 and sort2<-----

#define VECTORSIZE 100000

int compareVectors(int *vector1,int *vector2, int size);

int main(){
	int r,i,originalVector[VECTORSIZE],sortedVector[VECTORSIZE],testVector[VECTORSIZE];
	/*seed random number*/
	srand(1234);
	clock_t start, diff;
	
 /*initialize random number*/
	for (i=0;i<VECTORSIZE;i++)originalVector[i]=rand()%10000;

	/*copy vector to sorted vector*/
	memmove(sortedVector,originalVector,sizeof(originalVector));

 /*insertion sort*/
 start=clock(); /*start timer*/
	insertion_sort(sortedVector,VECTORSIZE); 
 printf ("Insertion sort took %d ms\n",(clock()-start)*1000/CLOCKS_PER_SEC);
 
 /*Bubble Sort is the simplest sorting algorithm that works by 
  *repeatedly swapping the adjacent elements if they are in wrong order.*/
 /*copy vector to test vector*/
	memmove(testVector,originalVector,sizeof(originalVector));
	start=clock(); /*start timer*/
	bubble_sort(testVector,VECTORSIZE);
	printf ("Bubble sort took %d ms\n",(clock()-start)*1000/CLOCKS_PER_SEC);
 /*check that it is sorted*/
 if(!compareVectors(sortedVector,testVector,VECTORSIZE)){
		printf("Bubble sort failed\n");
		return 0;
	}	

 /*The selection sort algorithm sorts an array by repeatedly finding the minimum element 
  *(considering ascending order) from unsorted part and putting it at the beginning*/
 /*copy vector to test vector*/
	memmove(testVector,originalVector,sizeof(originalVector));
	start=clock(); /*start timer*/
	selection_sort(testVector,VECTORSIZE);
	printf ("Selection sort took %d ms\n",(clock()-start)*1000/CLOCKS_PER_SEC);
 /*check that it is sorted*/
 if(!compareVectors(sortedVector,testVector,VECTORSIZE)){
		printf("Selection sort failed\n");
		return 0 ;
	}
	return 1;
}

int compareVectors(int *vector1,int *vector2, int size){
	int i;
	for(i=0;i<size;i++){
	 if(vector1[i] != vector2[i])return(0);
	} 
	return(1);
}	 
