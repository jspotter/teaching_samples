#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<char> s;

	cout << "Enter some text: ";
	string text;
	getline(cin, text);

	for (int i = 0; i < text.length(); i++) {
		char c = text.at(i);
		s.insert(c);
	}

	unordered_set<char>::iterator found = s.find('z');
	if (found == s.end()) {
		cout << "Not found" << endl;
	} else {
		cout << "Yayaaayy" << endl;
	}

	unordered_set<char>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << endl;
	}
}






