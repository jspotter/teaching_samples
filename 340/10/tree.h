#ifndef _TREE_H
#define _TREE_H

#include <cstdlib>   // necessary in order to use NULL

class TreeNode
{
public:
	TreeNode() : left(NULL), right(NULL) {}

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
	Tree& operator=(const Tree& other);

	void push(int value);
	TreeNode* find(int value) const;
	void print() const;

private:
	TreeNode* start;

	void copyOther(const Tree& other);
	void clear();
	void pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush);
	TreeNode* findFrom(TreeNode* startingPoint, int value) const;
	void printFrom(TreeNode* startintPoint, int numSpaces) const;
	void copyFrom(TreeNode* startintPoint);
	void clearFrom(TreeNode* startingPoint);
};

#endif

