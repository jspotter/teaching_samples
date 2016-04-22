#include "tree.h"
#include <iostream>
using namespace std;

Tree::Tree() : start(NULL) {}

Tree::Tree(const Tree& other)
{
	copyFrom(other.start);
}

Tree& Tree::operator=(const Tree& other)
{
	if (this != &other) {
		clearFrom(start);
		start = NULL;
		copyFrom(other.start);
	}
	return *this;
}

void Tree::copyFrom(TreeNode* startingPoint)
{
	if (startingPoint == NULL) {
		return;
	}

	push(startingPoint->value);
	copyFrom(startingPoint->left);
	copyFrom(startingPoint->right);
}

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
	} else {
		if (startingPoint->left == NULL) {
			startingPoint->left = nodeToPush;
		} else {
			pushFrom(startingPoint->left, nodeToPush);
		}
	}
}

void Tree::print() const
{
	printFrom(start, 0);
}

void Tree::printFrom(TreeNode* startingPoint, int numSpaces) const
{
	if (startingPoint == NULL) {
		return;
	}

	for (int i = 0; i < numSpaces; i++) {
		cout << " ";
	}

	cout << startingPoint->value <<endl;
	printFrom(startingPoint->left, numSpaces + 2);
	printFrom(startingPoint->right, numSpaces + 2);
}

TreeNode* Tree::find(int value) const
{
	return findFrom(start, value);
}

TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const
{
	if (startingPoint == NULL || startingPoint->value == value) {
		return startingPoint;
	}

	if (startingPoint->value < value) {
		return findFrom(startingPoint->right, value);
	} else {
		return findFrom(startingPoint->left, value);
	}
}

Tree::~Tree()
{
	clearFrom(start);
}

void Tree::clearFrom(TreeNode* startingPoint)
{
	if (startingPoint == NULL) {
		return;
	}

	clearFrom(startingPoint->left);
	clearFrom(startingPoint->right);
	delete startingPoint;
}










