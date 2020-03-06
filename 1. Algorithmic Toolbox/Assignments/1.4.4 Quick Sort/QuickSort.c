/*
 * QuickSort.c
 *
 *  Created on: Apr 10, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
void quickSort(int *ptr, int start, int end);
int partition(int *ptr, int start, int end);
void swap(int *a, int *b);

int main(){
	uint n = 0;
	int *ptr = NULL;

	fflush(stdin);
	scanf("%u",&n);

	ptr = (int *) malloc(n * sizeof(int));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%d", (ptr + i));
	}

	quickSort(ptr, 0, n-1);

	for(uint i = 0; i < n; i++){
		printf("%d ", *(ptr + i));
		fflush(stdout);
	}

	return 0;
}


void quickSort(int *ptr, int start, int end){
	if(start < end){
		int middle = partition(ptr, start, end);
		quickSort(ptr, start, middle-1);
		quickSort(ptr, middle+1, end);
	}
}

int partition(int *ptr, int start, int end){
	int pivot = *(ptr+start);
	int j = start;
	for(uint i = start+1; i < end+1; i++){
		if(*(ptr+i) <= pivot){
			j++;
			swap((ptr+j),(ptr+i));
		}
	}
	swap((ptr+j),(ptr+start));
	return j;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
