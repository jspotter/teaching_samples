#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

string reverseString(const string &start)
{
	stringstream ss;
	for (int i = start.size() - 1; i >= 0; i--) {
		ss << start.at(i);
	}

	return ss.str();
}

int main()
{
	string start = "Jonathan";
	cout << start << endl;
	cout << reverseString(start) << endl;

	return 0;
}

