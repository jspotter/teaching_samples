#include <iostream>
using namespace std;

int main()
{
	int n = 5;

	int result = 1;
	for (int i = n; i >= 1; i--) {
		result *= i;
	}

	cout << n << " factorial == " << result << endl;

	return 0;
}

