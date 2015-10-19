#include <cstdlib>
#include <iostream>
using namespace std;

void myFunction(int x)
{
	cout << x << endl;
}

bool bothAreEven(int first, int second)
{
	return first % 2 == 0 && second % 2 == 0;
}

void callMyFunction(function<bool(int, int)> f)
{
	cout << (f(10, 20) ? "true!" : "false!") << endl;
}

int main()
{
	callMyFunction(bothAreEven);

	return 0;
}

