/*
 * computeTreeHeight.cpp
 *
 *  Created on: Aug 6, 2019
 *      Author: Abdelrahman
 */


#include <iostream>
#include <vector>
#include <algorithm>

class Tree{
	int size;
	std::vector<std::vector<int>> nodes;

public:
	int root;

	void initialize(){
		std::cin>> size;
		nodes.resize(size);

		for(int i = 0; i < size; ++i){
			int parent = 0;
			std::cin >> parent;
			if(parent == -1){
				root = i;
			}
			else{
				nodes[parent].push_back(i);
			}
		}
	}

	int height(int root){
		int max = 0;
		for(unsigned int i = 0; i < nodes[root].size(); ++i){
			max = std::max(max, height(nodes[root][i]));
		}
		return (max + 1);
	}

};

int main(){
	Tree tree;
	tree.initialize();
	std::cout << tree.height(tree.root) << std::endl;
	return 0;
}
