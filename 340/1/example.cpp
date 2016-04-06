#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int x = 10;

	if (x > 5) {
		cout << "greater than 5" << endl;
	} else if (x == 0) {
		cout << "x is 0" << endl;
	} else {
		cout << "not greater than 5" << endl;
	}

	do {
		x--;
	} while (x > 0);

	int myArray[5];
	for (int i = 0; i < 5; i++) {
		myArray[i] = i * 2;
		cout << myArray[i] << endl;
	}

	return 0;
}

