#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

string reverseString(const string &start)
{
	if (start.size() == 0) {
		return start;
	}

	return reverseString(start.substr(1)) +
		start.at(0);
}

int main()
{
	string start = "Jonathan";
	cout << start << endl;
	cout << reverseString(start) << endl;

	return 0;
}

