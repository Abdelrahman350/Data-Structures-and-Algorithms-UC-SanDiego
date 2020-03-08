/*
 * PartitioningSouvenirs.c
 *
 *  Created on: May 25, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
uint equalPartitions(uint *ptr, uint n);

int main(){
	uint n;
	uint result = 0;

	fflush(stdin);
	scanf("%u", &n);

	uint *ptr = (uint *) malloc(n * sizeof(uint));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%u", (ptr + i));
	}

	result = equalPartitions(ptr, n);

	printf("%u", result);
	fflush(stdout);
}

uint equalPartitions(uint *ptr, uint n){
	uint result = 0;
	uint sum = 0;
	for(uint i = 0; i < n; i++){
		sum += *(ptr + i);
	}

	if(sum % 3 != 0){
		return result;
	}
	else{
		return result;
	}
}
