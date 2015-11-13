#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
void mySwap(T& first, T& second)
{
	T temp = first;
	first = second;
	second = temp;
}

template <typename FromType, typename ToType>
ToType convert(const FromType& value)
{
	return static_cast<ToType>(value);
}

int main()
{
	int x = 10, y = 20;
	cout << "x: " << x << ", y: " << y << endl;
	mySwap(x, y);
	cout << "x: " << x << ", y: " << y << endl;

	string s1 = "first string", s2 = "second string";
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	mySwap(s1, s2);
	cout << "s1: " << s1 << ", s2: " << s2 << endl;

	double d = 6.3;
	cout << convert<double, int>(d) << endl;

	return 0;
}

