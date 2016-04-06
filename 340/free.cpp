#include <iostream>
using namespace std;

class Node
{
	Node *next;
	int value;
};

int main()
{
	Node* n = new Node();
	free(n);
}
