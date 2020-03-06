/*
 * computeTreeHeight.cpp
 *
 *  Created on: Aug 6, 2019
 *      Author: Abdelrahman
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**************************************************************************/
typedef struct tree_node{
	struct tree_node *left_child;
	unsigned long int value;
	struct tree_node *right_child;
}tree_node;

typedef struct tree{
	tree_node *root;
	unsigned int size;
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

void insert_tree(tree *T, unsigned long int value){
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
		cout << root->value <<"\t";
		print_tree(root->left_child);
		print_tree(root->right_child);
	}
}
/**************************************************************************/

typedef struct node{
	long int parents;
	unsigned long int nodes;
}node;

unsigned int treeHeight(vector<node> nodes);

int main(){
	unsigned long int n;
	unsigned int height = 0;

	cin >> n;

	vector <node> nodes(n);

	for(unsigned long int i = 0; i < n; i++){
		cin >> nodes[i].parents;
		nodes[i].nodes = i;
	}
	height = treeHeight(nodes);
	cout << height;
	return 0;
}

bool compare(node A, node B){
	return (A.parents < B.parents);
}

unsigned int treeHeight(vector<node> nodes){
	unsigned int height = 0;
	sort(begin(nodes), end(nodes), compare);
	tree *T = create_tree();
	for(unsigned int i = 0; i < nodes.size(); i++){
		cout << nodes[i].nodes <<"\t" << nodes[i].parents << "\n";
		insert_tree(T, nodes[i].nodes);
	}
	cout<<"\n";
	print_tree(T->root);cout<<"\n";
	return height;
}
