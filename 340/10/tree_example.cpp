#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
	Tree t;

	t.push(4);
	t.push(2);
	t.push(1);
	t.push(3);
	t.push(6);
	t.push(5);

	t.print();

	Tree t3(t);
	t3.push(7);

	t.print();
	t3.print();

	Tree t2;
	t2.push(2);
	t2.push(1);
	t2.push(3);

	t2 = t;

	t2.push(8);

	t2.print();
	t.print();
	
	TreeNode *node = t.find(5);
	cout << "found: " << node->value << endl;

	node = t.find(100000);
	cout << "t.find(100000): " << node << endl;
}

