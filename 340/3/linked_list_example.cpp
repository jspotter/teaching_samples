#include <cstdlib>
#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	LinkedList list;
	list.push(5);

	cout << list.peek() << endl;
	cout << list.pop() << endl;
	cout << list.pop() << endl;

	return 0;
}

