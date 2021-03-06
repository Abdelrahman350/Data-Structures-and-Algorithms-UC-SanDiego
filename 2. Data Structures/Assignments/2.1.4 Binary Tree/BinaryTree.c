/*
 * BinaryTree.c
 *
 *  Created on: Jun 13, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node{
	struct tree_node *left_child;
	int value;
	struct tree_node *right_child;
}tree_node;

typedef struct tree{
	tree_node *root;
	int size;
}tree;

tree* create_tree(){
	tree *T = (tree *) malloc(sizeof(tree));
	(*T).root = NULL;
	(*T).size = 0;
	return T;
}

int is_empty_tree(tree *T){
	return T->size == 0;
}

void insert_tree(tree *T, int value){
	tree_node *TN = (tree_node *) malloc(sizeof(tree_node));
	TN->left_child = NULL;
	TN->right_child = NULL;
	TN->value = value;
	if(is_empty_tree(T)){
		T->root = TN;
		T->size++;
	}
	else{
		tree_node *root = T->root;
		while(1){
			if(value < root->value){
				if(root->left_child == NULL){
					root->left_child = TN;
					T->size++;
				}
				else{
					root = root->left_child;
				}
			}
			else if(value > root->value){
				if(root->right_child == NULL){
					root->right_child = TN;
					T->size++;
				}
				else{
					root = root->right_child;
				}
			}
			else{
				break;
			}
		}
	}
}

void print_tree(tree_node *root){
	if(root == NULL){
		return;
	}
	else{
		print_tree(root->left_child);
		printf("%d\t", root->value);
		fflush(stdout);
		print_tree(root->right_child);
	}
}

int main(){
	tree *T = create_tree();
	insert_tree(T,5);
	insert_tree(T,7);
	insert_tree(T,3);
	insert_tree(T,4);
	insert_tree(T,7);
	print_tree(T->root);
	return 0;
}
