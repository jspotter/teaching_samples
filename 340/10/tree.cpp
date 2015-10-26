#include "tree.h"
#include <iostream>
using namespace std;

Tree::Tree() : start(NULL) {}

Tree::Tree(const Tree& other)
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
	Node* pushed = new Node();
	pushed->value = value;

	if (start == NULL) {
		start = pushed;
	} else {
		Node* current = start;
		while (true)
		{
			if (value < current->value) {
				if (current->left == NULL) {
					current->left = pushed;
					break;
				} else {
					current = current->left;
				}
			} else {
				if (current->right == NULL) {
					current->right = pushed;
					break;
				} else {
					current = current->right;
				}
			}
		}
	}
}

Node* Tree::find(int value) const
{
	return findFrom(value, start);
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
}

// findFrom
//
// Recursively find a single element in a tree.
// Note that we don't have to look at every element
// in the tree! At any point, we have to choose either
// right or left depending on whether the value we
// are looking for is bigger or smaller than the
// node we are looking at.
Node* Tree::findFrom(int value, Node* start) const
{
	if (start == NULL) {
		return NULL;
	}

	if (start->value == value) {
		return start;
	} else if (value < start->value) {
		return findFrom(value, start->left);
	} else {
		return findFrom(value, start->right);
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
void Tree::printFrom(Node* start, int numSpaces) const
{
	if (start == NULL) {
		return;
	}

	for (int i = 0; i < numSpaces; i++) {
		cout << " ";
	}

	cout << start->value << endl;

	printFrom(start->left, numSpaces + 2);
	printFrom(start->right, numSpaces + 2);
}

// copyFrom
//
// Recursively copy another tree's nodes. Use
// pre-order traversal.
void Tree::copyFrom(Node* start)
{
	if (start == NULL) {
		return;
	}

	push(start->value);
	copyFrom(start->left);
	copyFrom(start->right);
}

// clearFrom
//
// Recursively delete nodes. Use post-order traversal.
void Tree::clearFrom(Node* start)
{
	if (start == NULL) {
		return;
	}

	clearFrom(start->left);
	clearFrom(start->right);
	delete start;
}

