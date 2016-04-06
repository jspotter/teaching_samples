#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int myGrid[3][4];

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			myGrid[row][col] = 0;
		}
	}

	myGrid[1][2] = 10;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			cout << myGrid[row][col] << "  ";
		}
		cout << endl;
	}

	return 0;
}

