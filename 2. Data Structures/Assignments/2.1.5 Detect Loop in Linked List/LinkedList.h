/*
 * LinkedList.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Abdelrahman
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

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

list* create_list();
int is_empty_list(list* L);
void push_front_list(list *L, int value);
void push_back_list(list *L, int value);
int pop_front_list(list *L);
int pop_back_list(list *L);
void insert_position_list(list *L, int position, int value);
int has_cycle(list *L);
int Detect_and_RemoveLoop(list *L);
void removeLoop(list_node *N, list *L);

#endif /* LINKEDLIST_H_ */
