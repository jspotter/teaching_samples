#include <cstdlib>
#include <iostream>
using namespace std;

struct MyStruct
{
	int x;
	int y;
};

int main()
{
	for (int i = 0; i < 1000000000; i++) {
		MyStruct s;
	}

	return 0;
}

