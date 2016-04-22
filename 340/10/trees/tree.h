#ifndef _TREE_H
#define _TREE_H

#include <cstdlib>

class TreeNode
{
public:
	TreeNode() : left(NULL), right(NULL) { }

	TreeNode* left;
	TreeNode* right;
	int value;
};

class Tree
{
public:
	Tree();
	Tree(const Tree& other);
	~Tree();

	void push(int value);
	TreeNode* find(int value) const;
	void print() const;
	Tree& operator=(const Tree& other);

protected:
	TreeNode* start;

	void pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush);
	void printFrom(TreeNode* startingPoint, int numSpaces) const;
	TreeNode* findFrom(TreeNode* startingPoint, int value) const;
	void clearFrom(TreeNode* startingPoint);
	void copyFrom(TreeNode* startingPoint);
};

#endif

