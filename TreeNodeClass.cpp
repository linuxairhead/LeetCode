#include "TreeNodeClass.h"
#include <iostream>

void TreeNodeClass::insertTree(TreeNode*& node, int num) {

	if (node == NULL) {
		//std::cout << "insert Tree " << num << " \n";
		node = new TreeNode(num);
	}
	else {
		if (node->left == NULL)
			this->insertTree(node->left, num);	
		else 
			this->insertTree(node->right, num);

	}
}

void TreeNodeClass::printTree(TreeNode*& node) {
	if (node == NULL)
		return;

	else{		
		std::cout << node->data << " ";
		this->printTree(node->left);		
		this->printTree(node->right);
	}
}