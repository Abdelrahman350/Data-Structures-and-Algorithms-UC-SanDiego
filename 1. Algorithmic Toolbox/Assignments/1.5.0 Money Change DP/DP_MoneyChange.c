/*
 * DP_MoneyChange.c
 *
 *  Created on: May 13, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned int uint;
uint DP_MoneyChange(uint money, uint coins[], uint n);

int main(){
	uint money = 0;
	uint numCoins = 0;
	uint coins[] = {1, 3, 4};
	uint n = sizeof(coins) / sizeof(coins[0]);

	fflush(stdin);
	scanf("%u", &money);

	numCoins = DP_MoneyChange(money, coins, n);

	printf("%u", numCoins);
	fflush(stdout);

}

uint DP_MoneyChange(uint money, uint coins[], uint n){
	uint i = 0;
	uint *ptrMinCoins = NULL;
	ptrMinCoins = (uint *) malloc((money + 1) * sizeof(uint));
	*(ptrMinCoins + 0) = 0;

	for(i = 1; i < (money + 1); i++){
		*(ptrMinCoins + i) = UINT_MAX;
		for(uint j = 0; j < n; j++){
			if(i >= coins[j]){
				uint NumCoins = *(ptrMinCoins + (i - coins[j])) + 1;
				if(NumCoins < *(ptrMinCoins + i)){
					*(ptrMinCoins + i) = NumCoins;
				}
			}
		}
	}
	return *(ptrMinCoins + i-1);
}
