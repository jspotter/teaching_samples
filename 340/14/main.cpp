#include <iostream>
#include <cstdlib>
#include "tree.h"
using namespace std;

int main()
{
	Tree t;
	t.push(5);
	t.push(3);
	t.push(7);
	t.push(1);
	t.push(4);
	t.push(6);
	t.push(8);

	t.printBFS();

	return 0;
}

