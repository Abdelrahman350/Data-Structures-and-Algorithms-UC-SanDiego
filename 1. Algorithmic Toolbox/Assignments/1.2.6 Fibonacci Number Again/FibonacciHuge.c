/*
 * FibonacciHuge.c
 *
 *  Created on: Mar 1, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <inttypes.h>

unsigned long long int fibonacciHuge(unsigned long long int n, unsigned long long int m);
unsigned long long int fibonacciList(unsigned long long int n, unsigned long long int m);

int main(){
	unsigned long long int n = 0;
	unsigned long long int m = 0;
	unsigned long long int result = 0;

	fflush(stdin);
	scanf("%I64u   %I64u", &n, &m);
	result = fibonacciHuge(n, m);

	printf("%I64u", result);
	fflush(stdout);

	return 0;
}

unsigned long long int fibonacciHuge(unsigned long long int n, unsigned long long int m){

	unsigned long long int a, b, c;
	unsigned long long int length = 0;
	unsigned long long int i = 2;

	if((n < 2)){
		return n;
	}

	a = 0;
	b = 1;

	while(1){

		c = (a + b) % m;
		a = b;
		b = c;

		if((b == 1) && (a == 0)){
			length = i - 1;
			break;
		}

		i++;
	}
	n = n - length * (n / length);

	return fibonacciList(n, m);
}

unsigned long long int fibonacciList(unsigned long long int n, unsigned long long int m){

	unsigned long long int a , b, c;
	a = 0;
	b = 1;

	if(n < 2)
	{
		return n;
	}

	for(unsigned long long int i = 2; i <= n; i++){
		c = (a + b) % m;
		a = b;
		b = c;
	}
	return c % m;
}
