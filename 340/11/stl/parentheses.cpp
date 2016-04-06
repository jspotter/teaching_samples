#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> openParens;
	string line;
	getline(cin, line);

	for (int i = 0; i < line.length(); i++) {
		if (line.at(i) == '(') {
			openParens.push(i);
		} else if (line.at(i) == ')') {
			if (openParens.empty()) {
				cout << "Unmatched ) at index " << i << endl;
				return 0;
			}

			openParens.pop();
		}
	}

	if (!openParens.empty()) {
		cout << "Unmatched ( at index " << openParens.top() << endl;
	} else {
		cout << "Looks good!" << endl;
	}

	return 0;
}

