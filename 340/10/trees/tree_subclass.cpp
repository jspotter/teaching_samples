#include "tree.h"
#include <iostream>
using namespace std;

class DoubleNode : public TreeNode
{
public:
	int secondValue;
};

class DoubleTree : public Tree
{
public:
	void push(int value)
	{
		DoubleNode *node = new DoubleNode();
		node->value = value;
		node->secondValue = value + 1;
		if (start == NULL) {
			start = node;
			return;
		}
		pushFrom(start, node);
	}

	int getSecondValue(int value)
	{
		// WARNING: This code isn't great, since it doesn't account
		// for the possibility that we don't find the value.
		DoubleNode* node = (DoubleNode*) find(value);
		return node->secondValue;
	}
};

int main()
{
	DoubleTree t;
	t.push(10);
	t.push(11);

	cout << t.getSecondValue(11) << endl;
}

