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
		myVector.push_back(i * 3);
	}

	int myArray[] = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27 };

	int count = count_if(myArray, myArray + 5, IsOdd);
	cout << count << " odd numbers" << endl;

	return 0;
}

