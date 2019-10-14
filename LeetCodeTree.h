#include <vector>
#include <iostream>
#include <unordered_set>
#include <stack>
#include "BinarySearchTree.h"

using namespace std;

class LeetCodeTree {

private:
	/* LeetCode #173 */
	std::stack<TreeNode*> s;
	/* LeetCode #173 End */

	/* LeetCode #1110 */
	void delNodesHelper(TreeNode*, unordered_set<int>&, vector<TreeNode*>&, bool);
	/* LeetCode #1110 End */
public:
	LeetCodeTree();

	/* LeetCode #173 */
	LeetCodeTree(TreeNode*);
	int nextBST();
	bool hasNextBST();
	/* LeetCode #173 End */

	/* LeetCode #1110. Delete Node And Return Forest */
	vector<TreeNode*> delNodes(TreeNode*, vector<int>&);	
	/* LeetCode #1110 End */

}; 
