#include "SelectionSort.h"

void selection_sort(int *a, int n) {
	int i, j temp;
	for(i = 0; i < n; i++) {
		int min = i;
		for (j = i + 1; j < n; j++ ) {
			if (a[j] < a[min]) min = j;
		}
	temp = a[i];
	a[i] = a[min];
	a[min] = temp;	
	}
}
