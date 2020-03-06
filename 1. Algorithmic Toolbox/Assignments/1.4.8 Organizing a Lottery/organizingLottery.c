/*
 * organizingLottery.c
 *
 *  Created on: Apr 16, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum type{Start, Point, End};
typedef unsigned int uint;
typedef struct Segments{
	long int coordinate;
	int type;
	long int order;
}Segment;

void mergeSort(Segment *ptr, uint coordinate, uint end);
void merge(Segment *ptr, uint coordinate, uint middle, uint end);
long int* pointsCovers(Segment *ptrSegments, uint n, uint m, Segment *ptrPoints);

int main(){
	uint n = 0;
	uint m = 0;
	Segment *ptrSegments = NULL;
	Segment *ptrPoints = NULL;
	long int *ptrResult = NULL;

	fflush(stdin);
	scanf("%u",&n);

	n *= 2;

	fflush(stdin);
	scanf("%u",&m);

	ptrSegments = (Segment *) malloc(n * sizeof(Segment));
	ptrPoints = (Segment *) malloc(m * sizeof(Segment));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%ld", &(ptrSegments + i)->coordinate);
		if(i%2 == 0){
			(ptrSegments + i)->type = Start;
		}
		else{
			(ptrSegments + i)->type = End;
		}
	}

	for(uint i = 0; i < m; i++){
		fflush(stdin);
		scanf("%ld", &(ptrPoints + i)->coordinate);
		(ptrPoints + i)->type = Point;
		(ptrPoints + i)->order = i;
	}

	ptrResult = pointsCovers(ptrSegments, n, m, ptrPoints);

	for(uint i = 0; i < m; i++){
		printf("%ld ",*(ptrResult+i));
		fflush(stdout);
	}

	return 0;
}

void mergeSort(Segment *ptr, uint coordinate, uint end){
	if(coordinate < end){
		uint middle = coordinate + (end - coordinate)/2;

		mergeSort(ptr, coordinate, middle);
		mergeSort(ptr, middle+1, end);

		merge(ptr, coordinate, middle, end);
	}
}

void merge(Segment *ptr, uint coordinate, uint middle, uint end){
	uint i, j, k;
	Segment *ptrLeft = 0;
	Segment *ptrRight = 0;
	uint leftSize = middle - coordinate + 1;
	uint rightSize = end - middle;

	/*Create Temporary Arrays*/
	ptrLeft = (Segment *) malloc(leftSize * sizeof(Segment));
	ptrRight = (Segment *) malloc(rightSize * sizeof(Segment));

	/*Copy Data to Temporary Arrays*/
	for(i = 0; i < leftSize; i++){
		*(ptrLeft+i) = *(ptr+coordinate+i);
	}
	for(j = 0; j < rightSize; j++){
		*(ptrRight+j) = *(ptr+middle+j+1);
	}

	/*Merge the temporary arrays*/
	i = 0; j = 0; k = coordinate;
	while((i < leftSize) && (j < rightSize)){
		if((ptrLeft+i)->coordinate <= (ptrRight+j)->coordinate){
			if((ptrLeft+i)->coordinate == (ptrRight+j)->coordinate){
				if((ptrLeft+i)->type <= (ptrRight+j)->type){
					*(ptr+k) = *(ptrLeft+i); /*Pick the left element if it's smaller*/
					i++; /*Move the pointer to the next element in the left array*/
				}
				else{
					*(ptr+k) = *(ptrRight+j); /*Pick the right element if it's smaller*/
					j++; /*Move the pointer to the next element in the right array*/
				}
			}
			else{
				*(ptr+k) = *(ptrLeft+i); /*Pick the left element if it's smaller*/
				i++; /*Move the pointer to the next element in the left array*/
			}
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

long int* pointsCovers(Segment *ptrSegments, uint n, uint m, Segment *ptrPoints){
	int count = 0;
	long int *ptrResult = (long int *) malloc(m * sizeof(long int));
	Segment *ptrPairs = (Segment *) malloc((m+n) * sizeof(Segment));

	for(uint i = 0; i < n; i++){
		*(ptrPairs+i) = *(ptrSegments+i);
	}
	for(uint i = 0, j = n; i < m; i++, j++){
		*(ptrPairs+j) = *(ptrPoints+i);
	}

	mergeSort(ptrPairs, 0, (m + n)-1);

	for(uint i = 0; i < (m+n); i++){
		if((*(ptrPairs+i)).type == Start){
			count++;
		}
		else if((*(ptrPairs+i)).type == End){
			count--;
		}
		else if((*(ptrPairs+i)).type == Point){
			*(ptrResult+(*(ptrPairs+i)).order) = count;
		}
	}



	return ptrResult;
}
