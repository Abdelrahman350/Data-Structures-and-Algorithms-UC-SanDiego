/*
 * KnapsackDP_noRepetition.c
 *
 *  Created on: May 23, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct weightUnits{
	uint weight;
	uint value;
}weights;

uint knapsackDP_noRep(weights *ptrWeights, uint n, uint W);
uint max(uint a, uint b);

int main(){
	uint W, n, maxWeight;

	fflush(stdin);
	scanf("%u", &W);

	fflush(stdin);
	scanf("%u", &n);

	weights *ptrWeights = (weights *) malloc(n * sizeof(weights));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%u", &(*(ptrWeights+i)).weight);
		(ptrWeights+i)->value = (*(ptrWeights+i)).weight;
	}

	maxWeight = knapsackDP_noRep(ptrWeights, n, W);

	printf("%u", maxWeight);
	fflush(stdout);
}

uint knapsackDP_noRep(weights *ptrWeights, uint n, uint W){
	n++;
	W++;
	uint *ptrValue = (uint *) malloc(n*W * sizeof(uint));
	uint rows = n;
	uint cols = W;
	for(uint i = 0; i < rows; i++){
		for(uint w = 0; w < cols; w++){
			if(i == 0 || w == 0){
				*(ptrValue + i*cols + w) = 0;
			}
			else if((*(ptrWeights + i - 1)).weight <= w){
				*(ptrValue + i*cols + w) = max(*(ptrValue + (i-1)*cols + w), *(ptrValue + (i-1)*cols + w-(*(ptrWeights + i - 1)).weight) + (ptrWeights + i - 1)->value);

			}
			else{
				*(ptrValue + i*cols + w) = *(ptrValue + (i-1)*cols + w);
			}
		}
	}

	return *(ptrValue + (rows-1)*cols + (cols-1));
}

uint max(uint a, uint b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
