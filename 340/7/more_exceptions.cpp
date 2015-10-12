#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

// More practice throwing and catching exceptions.

class MyException : public exception
{
	public:
		const char *what() const throw()
		{
			return "This is MyException";
		}
};

class MyOtherException : public exception
{
	public:
		const char *what() const throw()
		{
			return "I'm the other one";
		}
};

void level3()
{
	// Half the time, throw an instance of MyException.
	// The rest of the time, throw an instance of
	// MyOtherException.
	if (rand() % 2 == 0)
		throw MyException();
	else
		throw MyOtherException();

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
	} catch (MyException& e) {
		cout << "MyException: " << e.what() << endl;
	} catch (MyOtherException& e) {
		cout << "MyOtherException: " << e.what() << endl;
	} catch (...) {
		cout << "Unrecognized exception" << endl;
	}
	cout << "Level 1 exiting with no problems." << endl;
}

int main()
{
	srand(time(NULL));
	
	try {
		level1();
	} catch (...) {
		// This should not happen!
		cout << "main() caught exception" << endl;
	}

	cout << "Everything went smoothly." << endl;
	return 0;
}

