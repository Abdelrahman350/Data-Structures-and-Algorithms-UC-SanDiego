/*
 * GCD.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>

unsigned long int GCD_Euclidean(unsigned long int a, unsigned long int b);

int main(){

	unsigned long int a,b,result;

	fflush(stdin);
	scanf("%lu   %lu",&a,&b);
	result = GCD_Euclidean( a, b);

	printf("%lu", result);
	fflush(stdout);
}

unsigned long int GCD_Euclidean(unsigned long int a, unsigned long int b){

	if(b == 0){
		return a;
	}
	else{
		a = a - b * (a/b);
	    return GCD_Euclidean(b,a);
	}
}
