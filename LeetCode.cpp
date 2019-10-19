// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include "LeetCode.h"
#include "LeetCodeTree.h"
#include "LeetCodeArray.h"
#include "BinarySearchTree.h"

using namespace std;

void LeetCode::BSTtester() {

	vector<int> list = { 1, 2, 3, 4, 5 };
	TreeNode* root = NULL;
	BinarySearchTree bst;
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
			bst.insertVectorListTreeNode(root, list);
			break;
		case 2:
			bst.printTreeTester(root);
			break;
		case 3:
			bst.getTreeSizeTester(root);
			break;
		case 4:
			bst.getTreeMaxDepthTester(root);
			break;
		case 5:
			cout << " Enter the node number -->";
			cin >> choice;
			string s = bst.lookupTreeNode(root, choice) ? "has " : "don't have ";
			cout << "the tree " << s << " node " << choice;
		}
		cout << endl;
	}
}

void LeetCode::searchInsertTester() {
	LeetCodeArray lca;
	vector<int> inputV = { 1, 3, 5, 6 };
	int inputNum = 5;
	cout << " the num " << inputNum << " will be insert at location " << lca.searchInsert(inputV, inputNum) << endl;
}

void LeetCode::UniqueBSTTester() {
	LeetCodeTree lct;
	for (int i : {1, 2, 3, 4, 5, 6, 7, 8}) 
		cout << "Unique BST for " << i << " node are " << lct.numUniqueBST(i) << endl;
	
}

void LeetCode::nextBSTTester() {
	vector<int> v = { 7, 15, 3, 9, 20 };
	BinarySearchTree bst;
	TreeNode* root = NULL;

	bst.insertVectorListBSTNode(root, v);
	LeetCodeTree lct(root);
	bool bResult;
	string sResult;

	while ( bResult = lct.hasNextBST()) {
		sResult = bResult ? "is" : "isn't";
		cout << "There " << sResult << " next node." << endl;
		cout << "The next node is " << lct.nextBST() << endl;
	}
	sResult = bResult ? "is" : "isn't";
	cout << "There " << sResult << " next node." << endl<<endl;
}

void LeetCode::delNodesTester() {
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> dv = { 3,5 };
	BinarySearchTree bst;
	TreeNode* root = NULL;
	LeetCodeTree lct;

	bst.insertVectorListTreeNode(root, v);

	cout << endl;

	auto rv = lct.delNodes(root, dv);
	cout << endl;
	for (auto i : rv)
		bst.printTree(i);
	cout << endl;
}

int main()
{
	int choice;

    cout << "LeetCode C++ Tester!" << endl;
	while (1) {
		cout << "LeetCode   35. Search Insert Position" << endl;
		cout << "LeetCode   96. Unique BST" << endl;
		cout << "LeetCode  173. Binary Search Tree Iterator" << endl;
		cout << "LeetCode 1110. Delete Node And Return Forest" << endl;
		cout << "Please select which LeetCode would you like to test --> ";
		cin >> choice;
		LeetCode lc;

		switch (choice) {
		case 0:
			lc.BSTtester();
			break;

		case 35:
			lc.searchInsertTester();
			break;

		case  96:
			lc.UniqueBSTTester();
			break;

		case  173:
			lc.nextBSTTester();
			break;

		case 1110:
			lc.delNodesTester();
			break;		
		}
	}
}