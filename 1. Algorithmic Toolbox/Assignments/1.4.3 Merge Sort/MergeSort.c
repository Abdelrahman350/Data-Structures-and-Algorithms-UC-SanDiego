/*
 * MergeSort.c
 *
 *  Created on: Apr 8, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
void mergeSort(int *ptr, uint start, uint end);
void merge(int *ptr, uint start, uint middle, uint end);

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

	mergeSort(ptr, 0, n-1);

	for(uint i = 0; i < n; i++){
		printf("%d ", *(ptr + i));
		fflush(stdout);
	}

	return 0;
}

void mergeSort(int *ptr, uint start, uint end){
	if(start < end){
		uint middle = start + (end - start)/2;

		mergeSort(ptr, start, middle);
		mergeSort(ptr, middle+1, end);

		merge(ptr, start, middle, end);
	}
}

void merge(int *ptr, uint start, uint middle, uint end){
	uint i, j, k;
	int *ptrLeft = 0;
	int *ptrRight = 0;
	uint leftSize = middle - start + 1;
	uint rightSize = end - middle;

	/*Create Temporary Arrays*/
	ptrLeft = (int *) malloc(leftSize * sizeof(int));
	ptrRight = (int *) malloc(rightSize * sizeof(int));

	/*Copy Data to Temporary Arrays*/
	for(i = 0; i < leftSize; i++){
		*(ptrLeft+i) = *(ptr+start+i);
	}
	for(j = 0; j < rightSize; j++){
		*(ptrRight+j) = *(ptr+middle+j+1);
	}

	/*Merge the temporary arrays*/
	i = 0; j = 0; k = start;
	while((i < leftSize) && (j < rightSize)){
		if(*(ptrLeft+i) <= *(ptrRight+j)){
			*(ptr+k) = *(ptrLeft+i); /*Pick the left element if it's smaller*/
			i++; /*Move the pointer to the next element in the left array*/
		}
		else{
			*(ptr+k) = *(ptrRight+j); /*Pick the right element if it's smaller*/
			j++; /*Move the pointer to the next element in the right array*/
		}
		k++; /*Move the pointer to the next element in the merged array*/
	}

	/*Copy the remaining elements*/
	while(i < leftSize){
		*(ptr+k) = *(ptrLeft+i);
		i++;
		k++;
	}
	while(j < rightSize){
		*(ptr+k) = *(ptrRight+j);
		j++;
		k++;
	}
}
