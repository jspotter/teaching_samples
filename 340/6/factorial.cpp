#include <cstdlib>
#include <iostream>
using namespace std;

static const int NUMBER = 5;

int main()
{
	int result = 1;

	for (int i = NUMBER; i >= 1; i--) {
		result *= i;
	}

	cout << result << endl;

	return 0;
}

