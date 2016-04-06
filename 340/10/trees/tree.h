#ifndef _TREE_H
#define _TREE_H

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
	~Tree();

	void push(int value);
	TreeNode* find(int value) const;
	void print() const;

private:
	TreeNode* start;

	void pushFrom(TreeNode* startingPoint, TreeNode* nodeToPush);
};

#endif

