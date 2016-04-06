#include <cstdlib>
#include <iostream>
using namespace std;

class A
{
public:
	A(int value) {
		a = value;
	}

	int a;
};

class B : public A
{
public:
	B(int value) : A(value) {
		b = value;
	}

	int b;
};

int main()
{
	A a(20);
	B b(10);

	cout << a.a << endl;
	cout << b.a << endl;
	cout << b.b << endl;

	a = b;

	cout << a.a << endl;

	return 0;
}

