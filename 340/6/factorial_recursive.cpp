#include <cstdlib>
#include <iostream>
using namespace std;

static const int NUMBER = 5;

int factorial(int x)
{
	if (x < 0) {
		return -1;
	}

	if (x == 0) {
		return 1;
	}

	return x * factorial(x - 1);
}

int main()
{
	cout << factorial(NUMBER) << endl;

	return 0;
}

