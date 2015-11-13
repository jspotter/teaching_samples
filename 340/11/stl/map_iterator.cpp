#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <time.h>
using namespace std;

void printMap(const unordered_map<string, int>& myMap)
{
	for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
		cout << iter->first << ": " << iter->second << endl;
	}
	cout << "-----" << endl;
}

int main()
{
	srand(time(NULL));

	unordered_map<string, int> myMap;
	myMap.insert(pair<string, int>("Jonathan", 1));
	myMap.insert(pair<string, int>("Jerry", 2));
	myMap.insert(pair<string, int>("Tien", 3));

	printMap(myMap);
/*
	for (auto iter = myMap.end() - 1; iter >= myMap.begin(); iter--) {
		if (iter->first.at(0) == 'J')
			myMap.erase(iter);
	}

	printMap(myMap);
*/
	return 0;
}

