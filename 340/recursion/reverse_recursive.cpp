#include <iostream>
using namespace std;

string reverseString(const string& start)
{
	if (start.size() == 0) {
		return start;
	}

	return reverseString(start.substr(1)) + start[0];
}
