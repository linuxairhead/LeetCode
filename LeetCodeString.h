#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class LeetCodeString {

	void stringMessage(string, string);

public:
	/*Using For Loop*/
	vector<char> stringToVector(string, bool);

	string vectorToString(vector<char>, bool);

	/*Using Range Constructor*/
	vector<char> stringToVectorOne(string, bool);

	string vectorToStringOne(vector<char>, bool);
	
	void StringTester();
};
