#include "oak.h"
using namespace std;

int Oak::top() const
{
	if (start == NULL)
		throw OakEmptyException();

	Node* current = start;
	while (true)
	{
		if (current->right == NULL) {
			return current->value;
		}

		current = current->right;
	}
}

void Oak::pop()
{
	if (start == NULL)
		return;

	Node* current = start;
	Node* parent = NULL;
	while (true)
	{
		if (current->right == NULL) {
			if (parent == NULL) {
				start = start->left;
				delete start;
			} else {
				parent->right = current->left;
				delete current;
			}

			return;
		}

		parent = current;
		current = current->right;
	}
}

