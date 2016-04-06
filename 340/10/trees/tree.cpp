#include "tree.h"
#include <iostream>
using namespace std;

Tree::Tree() : start(NULL) {}

void Tree::push(int value)
{
	TreeNode* newNode = new TreeNode();
	newNode->value = value;
	if (start == NULL) {
		start = newNode;
		return;
	}

	pushFrom(start, newNode);
}

void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush)
{
	if (startingPoint->value < nodeToPush->value) {
		if (startingPoint->right == NULL) {
			startingPoint->right = nodeToPush;
		} else {
			pushFrom(startingPoint->right, nodeToPush);
		}
	}
}


