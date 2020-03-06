/*
 * Queue.c
 *
 *  Created on: Jun 11, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node{
	int value;
	struct queue_node *next;
}queue_node;

typedef struct queue{
	queue_node *head;
	int size;
	queue_node *tail;
}queue;

queue* create_queue(){
	queue *Q = (queue *) malloc(sizeof(queue));
	(*Q).head = NULL;
	(*Q).tail = NULL;
	(*Q).size = 0;
	return Q;
}

int is_empty_queue(queue *Q){
	return (*Q).size == 0;
}

void push_queue(queue *Q, int value){
	queue_node *QN = (queue_node *) malloc(sizeof(queue_node));
	QN->next = NULL;
	QN->value = value;
	if(is_empty_queue(Q)){
		Q->tail = QN;
		Q->head = QN;
	}
	else{
		Q->tail->next = QN;
		Q->tail = QN;
	}
	Q->size++;
}

int pop_queue(queue *Q){
	if(is_empty_queue(Q)){
		printf("Queue is empty");
		fflush(stdout);
		return 0;
	}
	else{
		int value = Q->head->value;
		queue_node *QN = (queue_node *) malloc(sizeof(queue_node));
		QN = Q->head;
		Q->head = Q->head->next;
		free(QN);
		Q->size--;
		return value;
	}
}

int main(){
	queue *Q = create_queue();
	push_queue(Q, 1);
	push_queue(Q, 12);
	push_queue(Q, 1994);
	while(!is_empty_queue(Q)){
		printf("%d\t", pop_queue(Q));
		fflush(stdout);
	}
	return 0;
}
