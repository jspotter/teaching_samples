#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	auto func = [] {
		cout << "hi" << endl;
	};

	func();

	return 0;
}

