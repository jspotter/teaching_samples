#include "tree.h"
#include <iostream>
using namespace std;

Tree::Tree() : start(NULL) {}

Tree::Tree(const Tree& other) : start(NULL)
{
	copyOther(other);
}

Tree::~Tree()
{
	clear();
}

Tree& Tree::operator=(const Tree& other)
{
	if (this != &other) {
		clear();
		copyOther(other);
	}

	return *this;
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

TreeNode* Tree::find(int value) const
{
	return findFrom(start, value);
}

void Tree::print() const
{
	printFrom(start, 0);
}

void Tree::copyOther(const Tree& other)
{
	copyFrom(other.start);
}

void Tree::clear()
{
	clearFrom(start);
	start = NULL;
}

// pushFrom
//
// Recursively push a single element into a tree.
void Tree::pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush)
{
	if (startingPoint->value < nodeToPush->value) {
		if (startingPoint->right == NULL) {
			
			// base case #1
			startingPoint->right = nodeToPush;
		} else {

			// recursive call #1
			pushFrom(startingPoint->right, nodeToPush);
		}

	// If we insert the same value twice, the second copy
	// will to to the left of the first copy.
	} else {
		if (startingPoint->left == NULL) {

			// base case #2
			startingPoint->left = nodeToPush;
		} else {

			// recursive call #2
			pushFrom(startingPoint->left, nodeToPush);
		}
	}
}

// findFrom
//
// Recursively find a single element in a tree.
// Note that we don't have to look at every element
// in the tree! At any point, we have to choose either
// right or left depending on whether the value we
// are looking for is bigger or smaller than the
// node we are looking at.
TreeNode* Tree::findFrom(TreeNode* startingPoint, int value) const
{
	if (startingPoint == NULL) {
		return NULL;
	}

	if (startingPoint->value == value) {
		return startingPoint;
	} else if (value < startingPoint->value) {
		return findFrom(startingPoint->left, value);
	} else {
		return findFrom(startingPoint->right, value);
	}
}

// printFrom
//
// Recursively print the values in a tree. Use
// pre-order traversal.
//
// If a tree looks like this:
//
//           6
//          / \
//         /   \
//        5     10
//       /      / \
//      /      /   \
//     0      8    12
//
// then it will be printed like this:
//
// 6
//   5
//     0
//   10
//     8
//     12
// 
void Tree::printFrom(TreeNode* startingPoint, int numSpaces) const
{
	if (startingPoint == NULL) {
		return;
	}

	for (int i = 0; i < numSpaces; i++) {
		cout << " ";
	}

	cout << startingPoint->value << endl;

	printFrom(startingPoint->left, numSpaces + 2);
	printFrom(startingPoint->right, numSpaces + 2);
}

// copyFrom
//
// Recursively copy another tree's nodes. Use
// pre-order traversal.
void Tree::copyFrom(TreeNode* startingPoint)
{
	if (startingPoint == NULL) {
		return;
	}

	push(startingPoint->value);
	copyFrom(startingPoint->left);
	copyFrom(startingPoint->right);
}

// clearFrom
//
// Recursively delete nodes. Use post-order traversal.
void Tree::clearFrom(TreeNode* startingPoint)
{
	if (startingPoint == NULL) {
		return;
	}

	clearFrom(startingPoint->left);
	clearFrom(startingPoint->right);
	delete startingPoint;
}

