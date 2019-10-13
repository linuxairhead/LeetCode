#include "LeetCodeTree.h"

/* LeetCode #111. Delete Node And Return Forest
   Given the root of a binary tree, each node in the tree has a distinct value.
   After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
   Return the roots of the trees in the remaining forest.
   You may return the result in any order.

   Given Condition
		A binary tree
		Each node has a distinct value

   Observed
		

   */
void LeetCodeTree::delNodesHelper(TreeNode* root, unordered_set<int>& uset, vector<TreeNode*> &v, bool pd) {

	if (!root)
		return;

	bool deleted = uset.count(root->data);

	if (!deleted && pd) {
		cout << " push " << root->data;
		v.emplace_back(root);
	}

	this->delNodesHelper(root->left, uset, v, deleted);

	if (!root->left || uset.count(root->left->data))
		root->left = nullptr;

	this->delNodesHelper(root->right, uset, v, deleted);

	if (!root->right || uset.count(root->right->data))
		root->right = nullptr;
}

vector<TreeNode*> LeetCodeTree::delNodes(TreeNode* root, vector<int>& to_delete) {

	vector<TreeNode*> retVector;
	unordered_set<int> um;

	for (auto i : to_delete)
		um.emplace(i);

	this->delNodesHelper(root, um, retVector, true);

	return retVector;
}

void LeetCodeTree::delNodesTester() {
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> dv = { 3,5 };
	BinarySearchTree bst;
	TreeNode* root = NULL;

	bst.insertVectorListTreeNode(root, v);

	cout << endl;

	auto rv = this->delNodes(root, dv);
	cout << endl;
	for(auto i : rv)
		bst.printTree(i);
	cout << endl;
}
