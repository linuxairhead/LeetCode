struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinarySearchTree{
private:
	
	void printTreeTester(TreeNode*);

	void getTreeSizeTester(TreeNode*);

	void getTreeMaxDepthTester(TreeNode*);

public:

	void tester();

	void insertTreeNode(TreeNode*&, int);

	void insertVectorListTreeNode(TreeNode*&, std::vector<int>);

	bool lookupTreeNode(TreeNode*, int);

	void printTree(TreeNode*);

	int sizeTree(TreeNode*);

	int maxDepth(TreeNode*);
};
