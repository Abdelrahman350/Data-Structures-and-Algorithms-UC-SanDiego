/*
 * LinkedList.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

list* create_list(){
	list* L = (list*) malloc(sizeof(list));
	L->head = NULL;
	L->size = 0;
	return L;
}

int is_empty_list(list* L){
	return L->size == 0;
}

void push_front_list(list *L, int value){
	list_node *LN = (list_node *) malloc(sizeof(list_node));
	LN->value = value;
	LN->next = L->head;//If this is the first node (L->head = NULL)
	L->head = LN;
	L->size++;
}

void push_back_list(list *L, int value){
	list_node *LN = (list_node *) malloc(sizeof(list_node));
	LN->value = value;
	LN->next = NULL;
	list_node *p = L->head;


	if(p == NULL){// if the list is empty
		(*L).head = LN;
	}
	else{
		while(p->next != NULL){
			p = p->next;
		}
		(*p).next = LN;  //p->next = LN; Make the last node points to the new backPushed node instead of NULL
	}
	L->size++;
}

int pop_front_list(list *L){
	if(is_empty_list(L)){
		printf("List is Empty");
		fflush(stdout);
		return 0;
	}
	int value = L->head->value;
	list_node *LN = L->head;
	L->head = L->head->next;
	free(LN);
	L->size--;
	return value;
}

int pop_back_list(list *L){
	if(is_empty_list(L)){
		printf("List is Empty");
		fflush(stdout);
		return 0;
	}
	else if(L->head->next == NULL){//One Node
		int value = (*((*L).head)).value;
		free(L->head);
		(*L).head = NULL;
		L->size--;
		return value;
	}
	else{
		list_node *LN = (*L).head;
		while((*LN).next->next != NULL){
			LN = (*LN).next;//Referencing the node before the end
		}
		int value = (*((*LN).next)).value;
		free(LN->next);
		LN->next = NULL;
		L->size--;
		return value;
	}
}

void insert_position_list(list *L, int position, int value){
	position++;
	if(position < 1 || position > L->size){
		printf("Invalid Position\n");
		fflush(stdout);
	}
	else{
		list_node **current = &(*L).head;
		while(position--){
			if(position == 0){
				list_node *LN = (list_node *) malloc(sizeof(list_node));
				(*LN).value = value;
				(*LN).next = NULL;
				(*LN).next = *current;
				*current = LN;
			}
			else{
				current = &(**current).next; //Get the address of the next pointer (next of the first node)
			}
		}
		(*L).size++;
	}
}

int has_cycle(list *L){
	list_node *head = (*L).head;

	if(head == NULL){
		return 0;
	}
	else{
		list_node *fast = (*head).next;
		list_node *slow = head;

		while(fast != NULL && slow != NULL && fast->next != NULL){
			if(fast == slow){
				return 1;
			}
			else{
				slow = slow->next;
				fast = fast->next->next;
			}
		}
		return 0;
	}
}

int Detect_and_RemoveLoop(list *L){
	list_node *head = (*L).head;

	if(head == NULL){
		return 0;
	}
	else{
		list_node *fast = (*head).next;
		list_node *slow = head;

		while(fast != NULL && slow != NULL && fast->next != NULL){
			if(fast == slow){
				removeLoop(fast, L);
				return 1;
			}
			else{
				slow = slow->next;
				fast = fast->next->next;
			}
		}
		return 0;
	}
}

void removeLoop(list_node *N, list *L){
	list_node *head = L->head;
	list_node *ptr1 = N;
	list_node *ptr2 = N;

	//Count the number of the nodes in the loop
	unsigned int k = 1;
	while(ptr1->next != ptr2){
		ptr1 = ptr1->next;
		k++;
	}

	/*Make one pointer points to head and the
	 * other to k nodes after head.
	 */
	ptr1 = head;
	ptr2 = head;
	for(unsigned int i = 0; i < k; i++){
		ptr2 = ptr2->next;
	}

	/*Move both pointers with the same pace until
	 * they meet at the start of the loop
	 */
	while(ptr2 != ptr1){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	//Move the 2nd pointer to to last node in the loop
	while(ptr2->next != ptr1){
		ptr2 = ptr2->next;
	}

	//Remove the loop
	ptr2->next = NULL;
}
