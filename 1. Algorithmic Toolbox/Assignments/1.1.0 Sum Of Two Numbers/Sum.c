/*
 * Sum.c
 *
 *  Created on: Feb 25, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>

int sumTwoInts(int a, int b);

int main(){

	int a = 0;
	int b = 0;
	int sum = 0;

	fflush(stdin);
	scanf("%d %d",&a,&b);
	sum = sumTwoInts(a, b);
	printf("%d",sum);
	fflush(stdout);
	return 0;
}

int sumTwoInts(int a, int b){
	return (a + b);
}
