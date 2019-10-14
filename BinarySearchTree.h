#ifndef TreeNode_HEADER
#define TreeNode_HEADER

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};
#endif

#ifndef BinarySearchTree_HEADER
#define BinarySearchTree_HEADER

class BinarySearchTree{
public:
	void printTreeTester(TreeNode*);

	void getTreeSizeTester(TreeNode*);

	void getTreeMaxDepthTester(TreeNode*);

	void insertBSTNode(TreeNode*&, int);

	void insertVectorListBSTNode(TreeNode*&, std::vector<int>);

	void insertTreeNode(TreeNode*&, int);

	void insertVectorListTreeNode(TreeNode*&, std::vector<int>);

	bool lookupTreeNode(TreeNode*, int);

	void printTree(TreeNode*);

	int sizeTree(TreeNode*);

	int maxDepth(TreeNode*);
};
#endif