#include <vector>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::insertVectorListTreeNode(TreeNode*& tn, vector<int> list) {

	cout << "inserted list of node to tree" << endl;
	for (auto i : list) {
		this->insertTreeNode(tn, i);
	}
}

void BinarySearchTree::printTreeTester(TreeNode* tn) {
	cout << "print all the node from Tree";
	this->printTree(tn);
	cout << endl;
}

void BinarySearchTree::getTreeSizeTester(TreeNode* tn) {
	int s = this->sizeTree(tn);
	cout << "the total number of Node of tree is " << s << endl;
}

void BinarySearchTree::getTreeMaxDepthTester(TreeNode* tn) {
	int s = this->maxDepth(tn);
	cout << "Max depth of tree is " << s << endl;
}

void BinarySearchTree::tester() {
	   
	vector<int> list = { 1, 2, 3, 4, 5 };
	TreeNode* root = NULL;
	int choice;

	while (1) {
		cout << "This is Binary Search Tree Tester\n";
		cout << "1.    insert\n";
		cout << "2.    print Tree\n";
		cout << "3.    print Number of Node\n";
		cout << "4.    print Max Depth of Tree\n";
		cout << "5.    Check for Node in Tree\n";
		cout << " Please chose your choise----------->";
		cin >> choice;

		switch (choice) {
		case 1:
			this->insertVectorListTreeNode(root, list);
			break;
		case 2:
			this->printTreeTester(root);
			break;
		case 3:
			this->getTreeSizeTester(root);
			break;
		case 4:
			this->getTreeMaxDepthTester(root);
			break;
		case 5:
			cout << " Enter the node number -->";
			cin >> choice;
			string s = this->lookupTreeNode(root, choice) ? "has " : "don't have ";
			cout << "the tree " << s  << " node " << choice;
		}
		cout << endl;
	}
}

void BinarySearchTree::insertTreeNode(TreeNode*& node, int num) {

	if (node == NULL) {
		//std::cout << "insert Tree " << num << " \n";
		node = new TreeNode(num);
	}
	else {
		if (node->left == NULL)
			this->insertTreeNode(node->left, num);	
		else 
			this->insertTreeNode(node->right, num);
	}
}

bool BinarySearchTree::lookupTreeNode(TreeNode* node, int num) {
	if (node == NULL)
		return false;
	else {
		if (node->data == num)
			return true;
		else {
			if (node->left == NULL)
				return this->lookupTreeNode(node->left, num);
			else
				return this->lookupTreeNode(node->right, num);
		}
	}
}

void BinarySearchTree::printTree(TreeNode* node) {
	if (node == NULL)
		return;
	else{		
		std::cout << node->data << " ";
		this->printTree(node->left);		
		this->printTree(node->right);
	}
}

int BinarySearchTree::sizeTree(TreeNode* node) {
	if (node == NULL)
		return 0;
	else
		return (this->sizeTree(node->left)+1+this->sizeTree(node->right));
}

int BinarySearchTree::maxDepth(TreeNode* node) {
	if (node == NULL)
		return 0;
	else {
		int left = 1 + this->maxDepth(node->left);
		int right = 1 + this->maxDepth(node->right);

		return (left > right ? left : right);
	}
}