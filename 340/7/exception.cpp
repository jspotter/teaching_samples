#include <cstdlib>
#include <iostream>
using namespace std;

// Practice throwing and catching exceptions.
// Levels 2 and 3 do not get to finish - level 3 because
// it throws an exception, and level 2 because it does not
// handle it. Level 1 handles the exception and gets to
// continue as normal. main() does not even see the
// exception, so it also gets to continue as normal.

void level3()
{
	throw 20;

	cout << "Level 3 exiting with no problems." << endl;
}

void level2()
{
	level3();
	cout << "Level 2 exiting with no problems." << endl;
}

void level1()
{
	try {
		level2();
	} catch (int e) {
		cout << "Level 1 caught exception: " << e << endl;
	}
	cout << "Level 1 exiting with no problems." << endl;
}

int main()
{
	try {
		level1();
	} catch (int e) {
		cout << "main() caught exception: " << e << endl;
	}

	cout << "Everything went smoothly." << endl;
	return 0;
}

