/*
 * MajorityElement.c
 *
 *  Created on: Apr 11, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
void mergeSort(long int *ptr, uint start, uint end);
void merge(long int *ptr, uint start, uint middle, uint end);
int majorityElement(long int *ptr, uint n);

int main(){
	uint n = 0;
	int flag = 0;
	long int *ptr = NULL;

	fflush(stdin);
	scanf("%u",&n);

	ptr = (long int *) malloc(n * sizeof(long int));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%ld", (ptr + i));
	}

	flag = majorityElement(ptr, n);

	printf("%d", flag);
	fflush(stdout);

	return 0;
}

void mergeSort(long int *ptr, uint start, uint end){
	if(start < end){
		uint middle = start + (end - start)/2;

		mergeSort(ptr, start, middle);
		mergeSort(ptr, middle+1, end);

		merge(ptr, start, middle, end);
	}
}

void merge(long int *ptr, uint start, uint middle, uint end){
	uint i, j, k;
	long int *ptrLeft = 0;
	long int *ptrRight = 0;
	uint leftSize = middle - start + 1;
	uint rightSize = end - middle;

	/*Create Temporary Arrays*/
	ptrLeft = (long int *) malloc(leftSize * sizeof(long int));
	ptrRight = (long int *) malloc(rightSize * sizeof(long int));

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
		if(*(ptrLeft+i) < *(ptrRight+j)){
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

int majorityElement(long int *ptr, uint n){
	int flag = 0;
	uint count = 1;
	long int currentElement;
	mergeSort(ptr, 0, n-1);
	currentElement = *(ptr + 0);

	for(uint i = 1; i < n; i++){
		if(currentElement == *(ptr+i)){
			count++;
			if(count > n/2){
				flag = 1;
				return flag;
			}
		}
		else{
			currentElement = *(ptr + i);
			count = 1;
		}
	}
	return flag;
}
