#include <cstdlib>
#include <iostream>
using namespace std;

class Dummy
{
	public:
		Dummy() : value(0) {}
		Dummy(int val) : value(val) {}

		Dummy operator-() {
			Dummy d;
			d.value = -value;
			return d;
		}

		void print()
		{
			cout << value << endl;
		}
	private:
		int value;
};

int main()
{
	Dummy d1(6);
	Dummy d2 = -d1;

	d1.print();
	d2.print();

	return 0;
}

