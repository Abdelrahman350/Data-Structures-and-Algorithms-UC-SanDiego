/*
 * changeMoney.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>

unsigned int changeMoney(unsigned int  money);
unsigned int changeMoney2(unsigned int  money);
unsigned int changeMoney3(unsigned int  money);

int main(){
	unsigned int money = 0;
	unsigned int changes = 0;

	fflush(stdin);
	scanf("%u", &money);


	changes = changeMoney3(money);

	printf("%u", changes);
	fflush(stdout);

	return 0;
}

unsigned int changeMoney(unsigned int  money){

	unsigned int changes = 0;
	unsigned int reserve = money;


	while(reserve > 0){
		while (reserve / 10 > 0){
			reserve -= 10;
			changes++;
		}
		while (reserve / 5 > 0){
			reserve -= 5;
			changes++;
		}
		while (reserve > 0){
			reserve -= 1;
			changes++;
		}

	}

	return changes;
}

unsigned int changeMoney2(unsigned int  money){

	unsigned int changes = 0;
	unsigned int reserve = money;


	if(reserve > 0){
		if (reserve >= 10){
		    changes += reserve / 10;
			reserve %= 10;
		}
		if (reserve >= 5){
		    changes += reserve / 5;
			reserve %= 5;
		}
		if (reserve >= 1){
		    changes += reserve / 1;
			reserve %= 1;
		}

	}

	return changes;
}

unsigned int changeMoney3(unsigned int  money){

	return ((money / 10) + ((money % 10) / 5) + (money % 5));
}
