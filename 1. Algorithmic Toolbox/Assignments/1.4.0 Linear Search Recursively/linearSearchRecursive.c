/*
 * linearSearchRecursive.c
 *
 *  Created on: Mar 31, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef uint type;
int recursiveLinearSearch(type *ptr, uint low, uint high, type key);

int main(){

	uint n = 0;
	uint m = 0;
	uint result = 0;
	uint *ptr = &m;
	uint key = 0;

	printf("Size = ");
	fflush(stdout);
	fflush(stdin);
	scanf("%u",&n);
	printf("\n");
	fflush(stdout);

	ptr = (uint *) malloc(n * sizeof(uint));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%u", (ptr+i));
	}
	printf("\n");
	fflush(stdout);

	printf("Key = ");
	fflush(stdout);

	fflush(stdin);
	scanf("%u", &key);
	printf("\n");
	fflush(stdout);

	result = recursiveLinearSearch(ptr, 0, n-1, key);

	printf("%d",result);
	fflush(stdout);

	return 0;
}


int recursiveLinearSearch(type *ptr, uint low, uint high, type key){

	if( high < low){
		return (-1);
	}
	if(key == *(ptr + low)){
		return low;
	}

	return recursiveLinearSearch(ptr, low+1, high, key);
}
