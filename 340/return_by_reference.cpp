#include <iostream>
using namespace std;

class Thing {
public:
	Thing() : x(10) {}

	int& getInt() { return x; }
	void printInt() { cout << x << endl; }
private:
	int x;
};

int main()
{
	Thing t;
	int& myInt = t.getInt();
	t.getInt() = 12;
	cout << myInt << endl;
	t.printInt();
}
