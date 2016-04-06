#include <cstdlib>
#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	LinkedList list;
	list.insertAtEnd(5);
	list.insertAtBeginning(1);

	cout << list.valueAtEnd() << endl;
	list.removeAtEnd();
	cout << list.valueAtEnd() << endl;

	return 0;
}

