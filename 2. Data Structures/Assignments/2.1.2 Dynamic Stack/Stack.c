/*
 * Stack.c
 *
 *  Created on: Jun 9, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node{
	int value;
	struct stack_node *next;
}stack_node;

typedef struct stack{
	stack_node *top;
	int size;
}stack;

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

int main(){
	stack *S = create_stack();
	push_stack(S, 5);
	push_stack(S, 9);
	push_stack(S, 3);

	while(!is_empty_stack(S)){
		printf("%d ", pop_stack(S));
		fflush(stdout);
	}
	return 0;
}
