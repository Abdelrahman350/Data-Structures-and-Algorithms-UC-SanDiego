/*
 * DetectLoop.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){
	list* L = create_list();
	push_back_list(L,50);
	push_back_list(L,20);
	push_back_list(L,15);
	push_back_list(L,4);
	push_back_list(L,10);

	//create loop
	L->head->next->next->next->next->next = L->head->next->next;

	int x = Detect_and_RemoveLoop(L);

	if(x){
		printf("Yes, there was a loop.\n");
		fflush(stdout);
	}
	else{
		printf("No, no loops found\n");
		fflush(stdout);
	}

	while(!is_empty_list(L)){
		printf("%d ", pop_front_list(L));
		fflush(stdout);
	}
	return 0;
}
