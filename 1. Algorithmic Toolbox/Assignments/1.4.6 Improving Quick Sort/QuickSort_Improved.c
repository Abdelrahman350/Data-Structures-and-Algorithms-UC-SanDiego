/*
 * QuickSort_Improved.c
 *
 *  Created on: Apr 14, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint;
void quickSort(int *ptr, int start, int end);
void partitionThree(int *ptr, int start, int end, int *m1, int *m2);
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
		int m1, m2;
		partitionThree(ptr, start, end, &m1, &m2);
		quickSort(ptr, start, m1-1);
		quickSort(ptr, m2+1, end);
	}
}

void partitionThree(int *ptr, int start, int end, int *m1, int *m2){
	srand(time(0));
	int random = start + (rand() % (end - start + 1));
	swap((ptr+random),(ptr+start));

	int pivot = *(ptr+start);
	int j = start;
	for(uint i = start+1; i < end+1; i++){
		if(*(ptr+i) <= pivot){
			j++;
			swap((ptr+j),(ptr+i));
		}
	}

	swap((ptr+j),(ptr+start));
	*m1 = j;

	for(uint i = start; (i < j) && (*m1 > i);){
		if(*(ptr+i) == *(ptr+j)){
			(*m1)--;
			swap((ptr+*m1),(ptr+i));
		}
		else{
			i++;
		}
	}
	*m2 = j;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
