/*
 * LCM.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>

unsigned long int GCD_Euclidean(unsigned long int a, unsigned long int b);
unsigned long int LCM(unsigned long int a, unsigned long int b);

int main(){

	unsigned long int a,b,result;

	fflush(stdin);
	scanf("%lu   %lu",&a,&b);
	result = LCM( a, b);

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

unsigned long int LCM(unsigned long int a, unsigned long int b){

	unsigned long int GCD;
	GCD = GCD_Euclidean( a, b);
	return ((a / GCD) * b);
}
