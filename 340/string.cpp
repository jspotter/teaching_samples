#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{

	string one;
	cin >> one;
	if (one == "abc") {
		cout << "equal!" << endl;
	} else {
		cout << "not equal!" << endl;
	}

	for (char c : one) {
		cout << c << endl;
	}


	return 0;
}

