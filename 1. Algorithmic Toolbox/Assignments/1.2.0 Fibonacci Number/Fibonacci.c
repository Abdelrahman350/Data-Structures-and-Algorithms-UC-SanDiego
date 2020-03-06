/*
 * Fibonacci.c
 *
 *  Created on: Feb 28, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>

unsigned long int fibonacciRecursive(unsigned long int n);

int main(){
	unsigned long int n = 0;
	unsigned long int result = 0;

	fflush(stdin);
	scanf("%lu", &n);

	result = fibonacciRecursive(n);

	printf("%lu", result);
	fflush(stdout);

	return 0;
}

unsigned long int fibonacciRecursive(unsigned long int n){

	if(n <= 1){
		return n;
	}
	else{
		return (fibonacciRecursive(n-1)+fibonacciRecursive(n-2));
	}
}
