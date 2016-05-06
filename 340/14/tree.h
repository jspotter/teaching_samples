#ifndef _TREE_H
#define _TREE_H

#include <cstdlib>

struct Node
{
	// Structs can have constructors too!
	Node() : left(NULL), right(NULL) {}

	Node* left;
	Node* right;
	int value;
};

class Tree
{
public:
	Tree();
	Tree(const Tree& other);
	~Tree();
	Tree& operator=(const Tree& other);

	void push(int value);
	Node* find(int value) const;
	void print() const;

	void printBFS();

protected:
	Node* start;

	void copyOther(const Tree& other);
	void clear();
	Node* findFrom(int value, Node* start) const;
	void printFrom(Node* start, int numSpaces) const;
	void copyFrom(Node* start);
	void clearFrom(Node* start);
};

#endif

