/*
 * CheckBrackets.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Abdelrahman
 */


#include <string.h>
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

long int checkBrackets(char *str);

int main(){
	char str[100000];
	scanf("%s", str);
	fflush(stdin);

	int result = checkBrackets(str);

	if(result == -1){
		printf("Success");
		fflush(stdout);
	}
	else{
		printf("%d", result);
		fflush(stdout);
	}
	return 0;
}

long int checkBrackets(char *str){
	int size = strlen(str);
	stack *S = create_stack();
	unsigned long int i, index;
	for(i = 0; i < size; i++){
		if(is_empty_stack(S)){
			index = i;
		}
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			push_stack(S, str[i]);
		}
		else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
			if(is_empty_stack(S)){
				return i+1;
			}
			else if(str[i] != ')' && S->top->value == '('){
				break;
			}
			else if(str[i] != ']' && S->top->value == '['){
				break;
			}
			else if(str[i] != '}' && S->top->value == '{'){
				break;
			}
			else{
				pop_stack(S);
			}
		}
	}
	if(is_empty_stack(S)){
		return -1;
	}
	else{
		if(i >= size){
			return index+1;
		}
		else{
			return i+1;
		}
	}
}
