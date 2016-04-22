#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// We can pass isOdd as the last argument
// to count_if, or we can pass an anonymous
// lambda function.
bool isOdd(int i)
{
	return i % 2 == 1;
}

int main()
{
	vector<int> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i * 3);
	}

	int count = count_if(
	    myVector.begin(), 
		myVector.end(), 
		[] (int i) -> bool {
		cout << "whoa i'm inside an anonymous function" 
			<< endl;
		return i % 2 == 1; 
	});
	cout << count << " odd numbers" << endl;

	return 0;
}

