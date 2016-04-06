#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <exception>

class LinkedListEmptyException : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Cannot get value from empty linked list.";
	}
};

class LinkedListNode
{
public:
	LinkedListNode *prev;
	LinkedListNode *next;
	int value;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	
	void insertAtEnd(int val);
	void insertAtBeginning(int val);

	int valueAtEnd();
	void removeAtEnd();

private:
	LinkedListNode *start;
	LinkedListNode *end;
};

#endif

