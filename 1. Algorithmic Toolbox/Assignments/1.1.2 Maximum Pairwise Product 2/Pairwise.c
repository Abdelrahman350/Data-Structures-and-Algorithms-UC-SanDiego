/*
 * Pairwise.c
 *
 *  Created on: Feb 26, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void swap(uint64_t *a, uint64_t *b);
void bubbleSort(uint64_t *ptr, int *n);
void maxPairwiseProduct(uint64_t *ptr, int *n, uint64_t *product);
void printArray(int n, uint64_t *ptr);

int main(){
	int n = 0;
	uint64_t *ptr =0;
	uint64_t product = 0llu;

	fflush(stdin);
	scanf("%d",&n);

	ptr = (uint64_t *) malloc(n * sizeof(uint64_t));
	for(int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%"PRId64"", (ptr+i));
	}

	bubbleSort(ptr, &n);

	//printArray(n, ptr);

	maxPairwiseProduct(ptr, &n, &product);
	printf("%"PRId64"", product);
	fflush(stdout);

	return 0;
}

void swap(uint64_t *a, uint64_t *b){
	uint64_t temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void maxPairwiseProduct(uint64_t *ptr, int *n, uint64_t *product){
	bubbleSort(ptr, n);
	*product = *(ptr+(*n - 1)) * *(ptr+(*n - 2));
}

void bubbleSort(uint64_t *ptr, int *n){

	for(int i = 0; i < (*n-1); i++){
		int swaps = 0;

		for(int j = (i+1); j < (*n); j++){
			if(*(ptr+i) > *(ptr+j)){
				swap((ptr+i),(ptr+j));
				swaps = 1;
			}
		}

		for(int j = (*n-1); j > (i+1); j--){
			/*printf("At i = %d , j = %d , *(ptr+j) = %"PRId64" , *(ptr+j-1) = %"PRId64"\n",i,j,*(ptr+j),*(ptr+j-1));
			fflush(stdout);*/
			if(*(ptr+j-1) > *(ptr+j)){
				swap((ptr+j),(ptr+j-1));
				swaps = 1;
			}
			//printArray(*n, ptr);
		}
		/*printf("\n");
		fflush(stdout);*/

		if(swaps == 0){
			break;
		}
	}

}
void printArray(int n, uint64_t *ptr){
	printf("{");
	for(int i = 0; i < n; i++){
		printf("%"PRId64"\t", *(ptr+i));
		fflush(stdout);
	}
	printf("}\n");
	fflush(stdout);
}
