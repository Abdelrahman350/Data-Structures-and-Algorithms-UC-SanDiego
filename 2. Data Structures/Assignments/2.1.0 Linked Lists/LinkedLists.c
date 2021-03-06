/*
 * LinkedLists.c
 *
 *  Created on: May 25, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
	int value;
	struct list_node *next;
}list_node;

typedef struct list{
	list_node *head; //Pointer to node (first node)
	int size;
}list;

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

int main(){
	list* L = create_list();
	push_front_list(L,5);
	push_front_list(L,50);
	push_front_list(L,500);
	push_back_list(L,3);
	push_back_list(L,30);
	push_back_list(L,300);
	while(!is_empty_list(L)){
		printf("%d ", pop_front_list(L));
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	push_front_list(L,5);
	push_front_list(L,50);
	push_front_list(L,500);
	push_back_list(L,3);
	push_back_list(L,30);
	push_back_list(L,300);
	while(!is_empty_list(L)){
		printf("%d ", pop_back_list(L));
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	push_front_list(L,5);
	push_front_list(L,50);
	push_front_list(L,500);
	push_back_list(L,3);
	push_back_list(L,30);
	push_back_list(L,300);
	insert_position_list(L, 0, 120);
	insert_position_list(L, 2, 250);
	while(!is_empty_list(L)){
		printf("%d ", pop_front_list(L));
		fflush(stdout);
	}
	return 0;
}
