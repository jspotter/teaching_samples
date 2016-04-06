#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> myMap;
	myMap["Jonathan"] = 5;
	myMap["CS 340"] = 100;

	cout << myMap["Jonathan"] << endl;

	myMap["Jonathan"]++;

	cout << myMap["Jonathan"] << endl;

	cout << myMap["Shwe"] << endl;

	/*
	map<char, int> mapOfCharacterCounts;

	for (int i = 0; i < text.length(); i++) {
		char next = text[i];
		mapOfCharacterCounts[next]++;
	}
	*/
}
