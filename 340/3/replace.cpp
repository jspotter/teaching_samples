#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s = "I ate cereal, for breakfast!";
	
	cout << s << endl;

	replace(s.begin(), s.end(), ',', ' ');
	replace(s.begin(), s.end(), '!', ' ');

	cout << s << endl;

	return 0;
}

