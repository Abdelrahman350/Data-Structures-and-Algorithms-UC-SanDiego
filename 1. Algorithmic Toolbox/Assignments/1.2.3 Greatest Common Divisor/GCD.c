/*
 * GCD.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>

unsigned long int GCD(unsigned long int a, unsigned long int b);

int main(){

	unsigned long int a,b,result;

	fflush(stdin);
	scanf("%lu   %lu",&a,&b);
	result = GCD( a, b);

	printf("%lu", result);
	fflush(stdout);
}

unsigned long int GCD(unsigned long int a, unsigned long int b){
	unsigned long int best = 0;

	for(unsigned long d = 1; d < (a + b); d++){
		if(!(a%d) && !(b%d)){
			best = d;
		}
	}
	return best;
}
