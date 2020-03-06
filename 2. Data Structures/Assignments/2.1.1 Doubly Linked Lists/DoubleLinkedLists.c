/*
 * DoubleLinkedLists.c
 *
 *  Created on: Jun 1, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
	struct list_node *previous;
	int value;
	struct list_node *next;
}list_node;

typedef struct list{
	list_node *head; //Pointer to node (first node)
	int size;
	list_node *tail;
}list;

list* create_list(){
	list* L = (list*) malloc(sizeof(list));
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
	return L;
}

int is_empty_list(list* L){
	return L->size == 0;
}

void push_front_list(list *L, int value){
	list_node *LN = (list_node *) malloc(sizeof(list_node));
	LN->value = value;
	LN->previous = NULL;
	LN->next = NULL;
	if((*L).size == 0){
		L->head = LN;
		L->tail = LN;
	}
	else{
		(*LN).next = (*L).head;
		(*((*L).head)).previous = LN;
		(*L).head = LN;
	}
	L->size++;
}

void push_back_list(list *L, int value){
	list_node *LN = (list_node *) malloc(sizeof(list_node));
	LN->value = value;
	LN->next = NULL;
	LN->previous = NULL;

	if(is_empty_list(L)){
		(*L).head = LN;
		(*L).tail = LN;
	}
	else{
		LN->previous = L->tail;
		(*((*L).tail)).next = LN;
		L->tail = LN;
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
	if((*L).size == 1){
		(*L).head = NULL;
		(*L).tail = NULL;
	}
	else{
		(*L).head = (*((*L).head)).next;
		(*((*L).head)).previous = NULL;
	}

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
	int value = (*((*L).tail)).value;
	if(L->head->next == NULL){//One Node
		free(L->tail);
		(*L).head = NULL;
		(*L).tail = NULL;
	}
	else{
		list_node *LN = (*L).tail;
		(*L).tail = (*((*L).tail)).previous;
		(*((*L).tail)).next = NULL;
		free(LN);
	}
	L->size--;
	return value;
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
				(*LN).next = *current;
				(*LN).previous = (**current).previous;
				(**current).previous = LN;
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
	insert_position_list(L, 6, 250);
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
	insert_position_list(L, 0, 120);
	insert_position_list(L, 6, 250);
	while(!is_empty_list(L)){
		printf("%d ", pop_back_list(L));
		fflush(stdout);
	}
	return 0;
}
