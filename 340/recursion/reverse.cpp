#include <iostream>
using namespace std;

string reverseString(const string& start) {
	string result;

	for (int i = start.size() - 1; i >= 0; i--) {
		result += start[i];
	}

	return result;
}

int main()
{
	string start = "Jonathan";
	cout << start << endl;
	cout << reverseString(start) << endl;
	return 0;
}

