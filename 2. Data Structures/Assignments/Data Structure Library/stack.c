/*
 * stack.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Abdelrahman
 */


#include "stack.h"

stack* create_stack(){
	stack *S = (stack *) malloc(sizeof(stack));
	(*S).top = NULL;
	(*S).size = 0;
	return S;
}

int is_empty_stack(stack *S){
	return (*S).size == 0;
}

void push_stack(stack *S, int value){
	stack_node *SN = (stack_node *) malloc(sizeof(stack_node));
	SN->value = value;
	SN->next = S->top;
	S->top = SN;
	S->size++;
}

int pop_stack(stack *S){
	int value = (*((*S).top)).value;
	stack_node *SN =  (stack_node *) malloc(sizeof(stack_node));
	SN = S->top;
	S->top = S->top->next;
	free(SN);
	S->size--;
	return value;
}
