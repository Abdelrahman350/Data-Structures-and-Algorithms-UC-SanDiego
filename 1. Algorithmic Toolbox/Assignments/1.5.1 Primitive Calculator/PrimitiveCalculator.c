/*
 * PrimitiveCalculator.c
 *
 *  Created on: May 13, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
uint* DP_primitiveCalculator(uint n, uint *ptrSequenceSize);
uint min(uint a, uint b);

int main(){
	uint n;
	uint m = 0;
	uint *ptrSequenceSize = &m;
	uint *ptrSequence = NULL;

	scanf("%u", &n);

	ptrSequence = DP_primitiveCalculator(n, ptrSequenceSize);

	printf("%u\n", (*ptrSequenceSize)-1);
	fflush(stdout);

	for(uint i = (*ptrSequenceSize); i > 0; i--){
		printf("%u ", *(ptrSequence + i - 1));
		fflush(stdout);
	}

	return 0;
}

uint* DP_primitiveCalculator(uint n, uint *ptrSequenceSize){
	uint *ptrN = (uint *) malloc((n+1) * sizeof(uint));
	uint *ptrSequence = (uint *) malloc((n) * sizeof(uint));
	*(ptrN + 0) = 0;
	// Get the minimum number of Operations
	for(uint i = 1; i < (n+1); i++){
		*(ptrN + i) = *(ptrN + i - 1) + 1;

		if(i % 2 == 0){
			*(ptrN + i) = min(*(ptrN + i/2) + 1, *(ptrN + i));
		}
		if(i % 3 == 0){
			*(ptrN + i) = min(*(ptrN + i/3) + 1, *(ptrN + i));
		}
	}

	//Get the sequence
	uint i = n;
	while(i > 1){
		*(ptrSequence + *ptrSequenceSize) = i;
		(*ptrSequenceSize)++;

		if(*(ptrN + i) == *(ptrN + i - 1) + 1){
			i--;
		}
		else if((i%2==0) && (*(ptrN + i/2) + 1 == *(ptrN + i))){
			i /= 2;
		}
		else if((i%3==0) && (*(ptrN + i/3) + 1 == *(ptrN + i))){
			i /= 3;
		}
	}
	*(ptrSequence + (*ptrSequenceSize)) = 1;
	(*ptrSequenceSize)++;
	return ptrSequence;
}

uint min(uint a, uint b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}
