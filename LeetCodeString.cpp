#include "LeetCodeString.h"

void LeetCodeString::stringMessage(string s1, string s2) {
	cout << "************** This is the algorithm **************" << endl;
	cout << "* " << s1 << endl;
	cout << "* " << s2 << endl;
	cout << "***************************************************" << endl;
}
/*
Using For loop for vector to string and string to vector conversion
*/

vector<char> LeetCodeString::stringToVector(string s, bool message = false) {
	vector<char> retVector;

	if (message)
		this->stringMessage("Using For Loop for string to vector conversion",
			"for(inti=0; i < s.size(); i++) retVector.push_back(s[i]);");	

	for (int i = 0; i < s.size(); i++)
		retVector.push_back(s[i]);

	return retVector;
}

string LeetCodeString::vectorToString(vector<char> v, bool message = false) {
	string retString;

	if (message)
		this->stringMessage("Using For Loop for vector to string conversion",
			"for (char i : v) retString.push_back(i); ");

	for (char i : v)
		retString.push_back(i);

	return retString;
}
/*
Using Range Constructor for vector to sting and string to vector conversion
*/

vector<char> LeetCodeString::stringToVectorOne(string s, bool message = false) {
	if (message)
		this->stringMessage("Using Range Constructor for string to vector conversion",
			"vector<char> retVector(s.begin(), s.end());");

	vector<char> retVector(s.begin(), s.end());
	return retVector;
}

string LeetCodeString::vectorToStringOne(vector<char> v, bool message = false) {
	if (message)
		this->stringMessage("Using Range Constructor for vector to string conversion",
			"string s(v.begin(), v.end());");

	string retString(v.begin(), v.end());
	return retString;
}

void LeetCodeString::StringTester() {
	int choice = 0, choice2 = 0;
	vector<char> result, vString;
	string sResult;

	cout << endl << endl << " Leet Code String Tester " << endl;
	while(1) {
		cout << "1. string to vector" << endl;
		cout << "2. vector to string" << endl;
		cout << "3. break loop" << endl;
		cout << "What is your choice --------------------> ";
		cin >> choice;
		if (choice == 3)
			return;
		
		cout << endl;
		cout << "type 1 : Using For loop" << endl;
		cout << "type 2 : Using Range Constructor " << endl;
		cout << "What is your choice -------------------> ";
		cin >> choice2;
		cout << endl;
		
		switch (choice) {
		case 1:
			switch (choice2) {
			case 1: result = this->stringToVector("This is the string to convert from string to vector", true);
				break;
			case 2: result = this->stringToVectorOne("This is the string after convert from string to vector", true);
				break;
			}
			cout << "Printing result from vector ..... ....." << endl;
			for (char i : result)
				cout << i;
			cout << endl;
			break;
		case 2:			
			vString = this->stringToVector( "This is the string after convert from string to vector");
			switch (choice2) {				
			case 1:sResult = this->vectorToString(vString, true);
				break;
			case 2:sResult = this->vectorToStringOne(vString, true);
				break;
			}
			cout << "Printing result from vector ..... ..... " << endl;
			cout << sResult << endl;
			break;
		}
		cout << endl << " ------ Continue with String Test " << endl;
	}
}