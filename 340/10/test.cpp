#include "oak.h"
#include <iostream>
using namespace std;

int main()
{
	Oak o;

	o.push(4);
	o.push(30);
	o.push(-3);
	o.push(5);
	o.push(10);

	for (int i = 0; i < 5; i++) {
		cout << o.top() << endl;
		o.pop();
	}

	return 0;
}
