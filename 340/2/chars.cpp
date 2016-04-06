#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int charCounts[128];
	for (int i = 0; i < 128; i++) {
		charCounts[i] = 0;
	}

	string s;
	cout << "Enter a string: ";
	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++) {
		char nextChar = s[i];
		charCounts[nextChar]++;
	}

	char nextChar = 0;
	while (true) {
		if (charCounts[nextChar] > 0) {
			cout << "You have " << charCounts[nextChar] << " of the letter " << nextChar << endl;
		}

		if (nextChar == 127) {
			break;
		}
		nextChar++;
	}

	return 0;
}

