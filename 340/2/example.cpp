#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	string s;
	cout << "Enter a string: ";
	// cin >> s;
	getline(cin, s);
	cout << "You typed " << s << endl;

	for (int i = s.size() - 1; i >= 0; i--) {
		char c = s[i];
		if (ispunct(c)) {
			s.erase(i, 1);
			cout << "s is now: " << s << endl;
		}
	}

	cout << s << endl;

	return 0;
}

