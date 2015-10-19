#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool IsOdd(int i)
{
	return i % 2 == 1;
}

int main()
{
	vector<int> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i * 10);
	}

	vector<int>::iterator iter = find_if(myVector.begin(), myVector.end(), IsOdd);
	if (iter != myVector.end())
		cout << "The first odd value is: " << *iter << endl;
	else
		cout << "oohhhh noooo" << endl;

	return 0;
}

