#include <cstdlib>
#include <iostream>
using namespace std;

struct A
{
	int x;
	int y;
	int z;
};

A *array = new A[100];

int main()
{
	A a;
	a.x = 12;
	a.y = 13;
	a.z = 14;

	array[0] = a;
	cout << array[0].x << endl;

	delete array;

	return 0;
}

