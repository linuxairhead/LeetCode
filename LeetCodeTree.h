#include <vector>
#include <iostream>
#include <unordered_set>
#include "BinarySearchTree.h"

using namespace std;

class LeetCodeTree {

private:	
	void delNodesHelper(TreeNode*, unordered_set<int>&, vector<TreeNode*>&, bool);
	
public:
	// LeetCode #1110. Delete Node And Return Forest
	vector<TreeNode*> delNodes(TreeNode*, vector<int>&);

	void delNodesTester();
}; 
