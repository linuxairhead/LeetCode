#pragma once
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class TreeNodeClass{
private:
	TreeNode* root;

public:
	void insertTree(TreeNode*&, int);

	void printTree(TreeNode*&);
};
