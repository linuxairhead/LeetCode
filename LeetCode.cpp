// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include "LeetCodeTree.h"
#include "BinarySearchTree.h"

using namespace std;

class LeetCode{

};

int main()
{
	int choice;

    std::cout << "LeetCode C++ Tester!" << std::endl;
	while (1) {
		std::cout << "LeetCode 1110. Delete Node And Return Forest" << std::endl;
		std::cout << "Please select which LeetCode would you like to test --> ";
		std::cin >> choice;

		switch (choice) {
		case 0:
			BinarySearchTree bst;
			bst.tester();
			break;
		case 1110:
			LeetCodeTree lct;
			lct.delNodesTester();
			break;
		
		}
	}
}