#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<char, int> m;

	cout << "Enter some text: ";
	string text;
	getline(cin, text);

	for (int i = 0; i < text.length(); i++) {
		char c = text.at(i);
		m[c]++;
	}

	unordered_map<char, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << "Letter: " << iter->first << endl;
		cout << "Value: " << iter->second << endl;
	}
}




