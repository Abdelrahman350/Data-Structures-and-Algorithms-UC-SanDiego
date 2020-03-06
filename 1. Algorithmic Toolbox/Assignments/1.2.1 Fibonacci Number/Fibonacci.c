/*
 * Fibonacci.c
 *
 *  Created on: Feb 28, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <inttypes.h>

unsigned long long int fibonacciList(unsigned long long int n);

int main(){
	unsigned long long int n = 0;
	unsigned long long int result = 0;

	fflush(stdin);
	scanf("%I64u", &n);

	result = fibonacciList(n);

	printf("%I64u", result);
	fflush(stdout);

	return 0;
}

unsigned long long int fibonacciList(unsigned long long int n){

	unsigned long long int f[n];
	f[0] = 0;
	f[1] = 1;

	for(int i = 2; i <= n; i++){
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}
