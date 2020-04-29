/*
 * stack.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Abdelrahman
 */

#ifndef STACK_H_
#define STACK_H_

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

stack* create_stack();
int is_empty_stack(stack *S);
void push_stack(stack *S, int value);
int pop_stack(stack *S);


#endif /* STACK_H_ */
