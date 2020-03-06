/*
 * SelectionSort.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
void selectionSort(uint n, int *ptr);
void swap(int *ptr1, int *ptr2);

int main(){
	uint n = 0;
	int m = 0;
	int *ptr = &m;

	fflush(stdin);
	scanf("%u",&n);

	ptr = (int *) malloc(n * sizeof(int));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%d", (ptr + i));
	}

	selectionSort(n, ptr);

	for(uint i = 0; i < n; i++){
		printf("%d ", *(ptr + i));
		fflush(stdout);
	}

	return 0;
}

void selectionSort(uint n, int *ptr){
	uint minIndex;

	for(uint i = 0; i < n-1; i++){
		minIndex = i;
		for(uint j = i+1; j < n; j++){
			if(*(ptr + j) < *(ptr + minIndex)){
				minIndex = j;
			}
		}
		swap((ptr+minIndex), (ptr+i));
	}
}

void swap(int *ptr1, int *ptr2){
	int temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
