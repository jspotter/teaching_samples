#include <cstdlib>
#include <iostream>
#include "linked_list.h"
using namespace std;

int main()
{
	/* Test basic functionality. */
	LinkedList list;
	list.insertAtEnd(5);
	list.insertAtBeginning(1);

	cout << list.valueAtEnd() << endl;
	list.removeAtEnd();
	cout << list.valueAtEnd() << endl;

	cout << "-----" << endl;

	/* Test copy constructor */
	LinkedList list2(list);
	
	list2.insertAtEnd(6);

	cout << list.valueAtEnd() << endl;
	cout << list2.valueAtEnd() << endl;

	cout << "-----" << endl;

	/* Test assignment operator */
	LinkedList list3;
	list3.insertAtEnd(-1);
	list3.insertAtEnd(-2);
	list3.insertAtEnd(-3);

	list3 = list2;

	list3.insertAtEnd(30);

	cout << list.valueAtEnd() << endl;
	cout << list2.valueAtEnd() << endl;
	cout << list3.valueAtEnd() << endl;

	return 0;
}

