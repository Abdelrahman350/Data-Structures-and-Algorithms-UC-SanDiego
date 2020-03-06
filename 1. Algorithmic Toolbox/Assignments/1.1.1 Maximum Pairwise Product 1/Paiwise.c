/*
 * Paiwise.c
 *
 *  Created on: Feb 25, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void max(uint64_t *a, uint64_t *b);
void maxPairwiseProduct(uint64_t *ptr, int *n, uint64_t *product);

int main(){
	int n = 0;
	uint64_t *ptr = 0;
	uint64_t product = 0llu;

	fflush(stdin);
	scanf("%d",&n);

	ptr = (uint64_t *) malloc(n * sizeof(uint64_t));
	for(int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%"PRId64"", (ptr+i));
	}

	maxPairwiseProduct(ptr, &n, &product);
	printf("%"PRId64"", product);
	fflush(stdout);

	return 0;
}

void max(uint64_t *a, uint64_t *b){
	if(*a > *b){
	}
	else{
		*a = *b;
	}
}

void maxPairwiseProduct(uint64_t *ptr, int *n, uint64_t *product){
	int i = 0;
	int j = 0;
	uint64_t m = 0;

	for(i = 0; i < *n; i++){
		for(j = i + 1; j < *n; j++){
			m = (*(ptr+i) * *(ptr+j));
			max(product, &m);
		}
	}
}
