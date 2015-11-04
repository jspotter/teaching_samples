#include "tree.h"
#include <assert.h>
using namespace std;

int main()
{
	Tree t1, t2;
	
	t1.push(6);
	t1.push(5);
	t1.push(7);

	t2 = t1;
	t2.push(26);

	Tree t3(t2);
	t3.push(0);

	Node* n;
	n = t1.find(5);
	assert(n != NULL);
	n = t2.find(5);
	assert(n != NULL);
	n = t3.find(5);
	assert(n != NULL);

	n = t1.find(26);
	assert(n == NULL);
	n = t2.find(26);
	assert(n != NULL);
	n = t3.find(26);
	assert(n != NULL);

	n = t1.find(0);
	assert(n == NULL);
	n = t2.find(0);
	assert(n == NULL);
	n = t3.find(0);
	assert(n != NULL);

	t1.print();
	t2.print();
	t3.print();

	Tree *t4 = new Tree();
	t4->push(10);
	t4->push(8);
	t4->push(9);

	delete t4;

	return 0;
}
