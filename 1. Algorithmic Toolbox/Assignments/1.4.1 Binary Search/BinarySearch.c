/*
 * BinarySearch.c
 *
 *  Created on: Apr 2, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int uint;
typedef long int l_int;

l_int binarySearch(l_int *ptrInput, l_int low, l_int high, l_int key);
void printArray(l_int n, l_int *ptr);

int main(){
	uint n, m;
	l_int input = 0;
	l_int key = 0;
	l_int index = 0;
	l_int *ptrInput = &input;
	l_int *ptrKey = &key;
	l_int *ptrIndex = &index;

	fflush(stdin);
	scanf("%lu", &n);

	ptrInput = (l_int *) malloc(n * sizeof(l_int));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%ld", (ptrInput+i));
	}

	fflush(stdin);
	scanf("%lu", &m);

	ptrKey = (l_int *) malloc(m * sizeof(l_int));
	ptrIndex = (l_int *) malloc(m * sizeof(l_int));

	for(uint i = 0; i < m; i++){
		fflush(stdin);
		scanf("%ld", (ptrKey+i));
	}

	for(uint i = 0; i < m; i++){
		*(ptrIndex+i) = binarySearch(ptrInput, 0, (n-1), *(ptrKey+i));
		printf("%ld ", *(ptrIndex+i));
		fflush(stdout);
	}

	return 0;
}

l_int binarySearch(l_int *ptrInput, l_int low, l_int high, l_int key){
	if(high < low){
		return (- 1);
	}
	else{
		l_int mid;
		mid = low + (high - low)/2;

		if(key == *(ptrInput + mid)){
			return mid;
		}
		else if(key < *(ptrInput + mid)){
			return binarySearch(ptrInput, low, (mid - 1), key);
		}
		else{
			return binarySearch(ptrInput, (mid + 1), high, key);
		}
	}
}

void printArray(l_int n, l_int *ptr){
	printf("{");
	for(int i = 0; i < n; i++){
		printf("%lu ", *(ptr+i));
		fflush(stdout);
	}
	printf("}\n");
	fflush(stdout);
}
