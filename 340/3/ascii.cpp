#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string line;
	stringstream ss;
	
	getline(cin, line);

	ss << line;

	while (true) {
		char next;
		ss >> next;
		if (ss.fail()) break;

		if (next >= 'A' && next <= 'Z') {
			cout << "Capital letter: " << next << " would have index: " << (next - 'A') << endl;
		} else if (next >= 'a' && next <= 'z') {
			cout << "Lower case letter: " << next << " would have index: " << (next - 'a') << endl;
		}
	}

	return 0;
}

