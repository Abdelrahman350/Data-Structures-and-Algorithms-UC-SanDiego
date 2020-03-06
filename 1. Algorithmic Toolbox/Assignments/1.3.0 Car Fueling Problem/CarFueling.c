/*
 * CarFueling.c
 *
 *  Created on: Mar 15, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>

unsigned int minRefills(unsigned int x[], unsigned int n, unsigned int L);

int main(){
	unsigned int L = 400;
	unsigned int numRefills = 0;
	unsigned int x[] = {100, 150, 200, 250, 300, 350, 500, 730, 1000, 1100, 1200, 1300, 1400, 1450};
	unsigned int n = sizeof(x)/sizeof(unsigned int)-2;

	numRefills = minRefills(x, n, L);

	printf("Number of Refills = %u",numRefills);
	fflush(stdout);

	return 0;
}

unsigned int minRefills(unsigned int x[], unsigned int n, unsigned int L){
	unsigned int numRefills = 0;
	unsigned int currentRefill = 0;
	unsigned int lastRefill = 0;

	while(currentRefill <= n){
		lastRefill = currentRefill;
		while((currentRefill <= n) && (x[currentRefill+1] - x[lastRefill] <= L)){
			currentRefill++;
		}
		if(currentRefill == lastRefill){
			printf("Impossible\n");
			fflush(stdout);
			return 0;
		}
		if(currentRefill <= n){
			numRefills++;
		}
	}

	return numRefills;
}
