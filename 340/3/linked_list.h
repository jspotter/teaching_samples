#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <cstdlib>
using namespace std;

struct LinkedListNode
{
	LinkedListNode *prev;
	LinkedListNode *next;
	int value;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	
	void push(int val);
	bool insert_at(int val, int idx);

	int peek();
	int pop();
	int retrieve_at(int idx);
	bool remove_at(int idx);

	LinkedListNode *find(int val);

private:
	LinkedListNode *start;
	LinkedListNode *end;

	void remove(LinkedListNode *node);
};

#endif

