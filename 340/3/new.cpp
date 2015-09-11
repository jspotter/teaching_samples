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
		
		// Statically allocating a struct is fast!
		MyStruct s;

		// Dynamically allocating a struct is slow!
		// MyStruct* s = new MyStruct();
	
		// If you chose static allocation, your struct
		// will go away once you get to the bottom of
		// this for-loop. If you chose dynamic allocation,
		// your struct will still be around.
	}

	return 0;
}

