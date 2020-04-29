/*
 * differentSummands.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

uint* summands(uint n, uint *ptr, uint *counter);

int main(){
	uint n = 0;
	uint *ptr = 0;
	uint m = 0;
	uint *counter;
	counter = &m;

	fflush(stdin);
	scanf("%u", &n);

	ptr = summands(n, ptr, counter);

	printf("%u\n", *counter);
	fflush(stdout);


	for(uint i = 0; i < *counter; i++){
		printf("%u ",ptr[i]);
		fflush(stdout);
	}

	return 0;
}

uint* summands(uint n, uint *ptr, uint *counter){

	uint *summands;
	summands = (uint *)malloc(n * sizeof(uint));

	for(uint i = 1; i <= n; i++){
		n -= i;
		if(n <= i){
			summands[(*counter)++] = n + i;
		}
		else{
			summands[(*counter)++] = i;
		}
	}

	ptr = (uint *)malloc(*counter * sizeof(uint));

	for(uint i = 0; i < *counter; i++){
		ptr[i] = summands[i];
	}
	return ptr;
}
