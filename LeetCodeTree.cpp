#include "LeetCodeTree.h"

// default constructure
LeetCodeTree::LeetCodeTree() {
	
}

/* LeetCode #96 
   Given n, how many structurally unique BST's (binary search trees)
   that store values 1 ... n?

   idea - dynamic programming
   n = 1 then  1
   n = 2 then 1-2 or 2-1 so 2
   n = 3 then (1)-2r-3r, (1)-3r-2l,  1l-(2)-3r, (3)-1l-2l, (3)-2l-1r
		() root number,
		r  right of root
		l  left of root

   G(3) =   F(1,3)   +   F(2,3)   +   F(3,3) --> F(root, given n)
        = G(0) * G(2) + G(1) * G(1) + G(2) * G(0)

   Cartesian Product	
   F(i, n) = G(i-1) * G(n-i)

   Time Complexity O(n^2)
   Space Complexity O(n)

*/
int LeetCodeTree::numUniqueBST(int num) {

	vector<int> unique(num + 1, 1);
	unique[0] = unique[1] = 1;

	for (int i = 2; i <=num; i++) 
		for (int j = 0 ; j < i; j++)
			unique[i] += unique[j] * unique[i-j-1];
	
	return unique[num];
}
/* LeetCode #96 End */

/* LeetCode #173 
   Implement an iterator over a binary search tree (BST).
   Your iterator will be initialized with the root node of a BST
   Calling next() will return the next smallest number in the BST.
*/
LeetCodeTree::LeetCodeTree(TreeNode* root) {
	/*
	 * keep track of all the left leaf of the tree
	 *                        root(p1)
	 *             left(p2)                  right
	 *        left(p3)      right        left      right
	 *  left(p4)  right  left   right left right left right   
	*/
	while (root) {
		s.push(root);
		root = root->left;
	}
}

int LeetCodeTree::nextBST() {
	/*
	 * get the top of stack which is the next smallest of the tree */
	TreeNode* n = s.top();
	s.pop();

	/*
	 * if right isn't null, push the right to top of stack
	 * And continue push all the left of tree to top of stack
	 * The last node will be the next of next smallest of the tree */
	TreeNode* r = n->right;
	while (r) {
		s.push(r);
		r = r->left;
	}
	return n->data;
}

bool LeetCodeTree::hasNextBST() {
	/*
	 * if there is node in the stack, there is next node.
	 */
	return !s.empty();
}

/* LeetCode #173 End */

/* LeetCode #1110. Delete Node And Return Forest
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

/* LeetCode #1110 End */
