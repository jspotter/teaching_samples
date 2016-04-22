#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	string s = "hi", s2 = "CS 340", s3 = "Jonathan";

	// The square brackets hold what's called the "capture" -
	// they indicate what things in the current scope should
	// be available to this lambda function. Putting an equals
	// sign in square brackets means "capture everything by
	// value". Putting an ampersand in square brackets means
	// "capture everything by reference".
	auto func = [=] (string sArg) -> void {
		cout << s << endl;
		cout << sArg << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << "-----" << endl;
	};

	s = "HIIIII";
	s2 = "SFSU";
	s3 = "San Francisco, CA";

	func(s);

	return 0;
}

