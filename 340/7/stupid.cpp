#include <iostream>
using namespace std;

void stupid(int n)
{
	if (n <= 1) {
		cout << n << endl;
		return;
	}

	stupid(n - 1);
	stupid(n - 2);
}

int main()
{
	stupid(3);
}

