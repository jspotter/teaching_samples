#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <exception>

/*
 * LinkedListEmptyException
 * -----
 * Gets thrown whenever you try to 
 * retrieve a value from an empty
 * linked list.
 */
class LinkedListEmptyException : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "Cannot get value from empty linked list.";
	}
};

/*
 * LinkedListNode
 * -----
 * Represents a node in the linked
 * list. Has a pointer to the previous
 * and next elements. Also has a value.
 */
class LinkedListNode
{
public:
	LinkedListNode *prev;
	LinkedListNode *next;
	int value;
};

/*
 * LinkedList
 * -----
 * The actual linked list. Has a pointer
 * to the start and end of the list. Both
 * will be NULL if the list is empty.
 */
class LinkedList
{
public:
	/*
	 * Constructor - initialize an empty linked
	 * list.
	 */
	LinkedList();

	/*
	 * Destructor - clean up dynamically allocated
	 * nodes.
	 */
	~LinkedList();

	/*
	 * Copy constructor - initialize a linked list
	 * based on the contents of another linked
	 * list.
	 */
	LinkedList(const LinkedList& other);

	/*
	 * Assignment operator - overwrite the contents
	 * of the current linked list with the contents
	 * of another linked list. Return a LinkedList
	 * by reference in order to support assignment
	 * chaining, like:
	 * 
	 * l3 = l2 = l1;
	 */
	LinkedList& operator=(const LinkedList& other);

	/*
	 * insertAtEnd - Inserts a new node with the
	 * given value (val) as the last node in the
	 * list.
	 */
	void insertAtEnd(int val);

	/*
	 * insertAtBeginning - Same as previous, except
	 * the node is inserted at the beginning.
	 */
	void insertAtBeginning(int val);

	/*
	 * valueAtEnd - Retrieves the last value in the
	 * linked list. Throws an exception if the list
	 * is empty.
	 */
	int valueAtEnd();

	/*
	 * removeAtEnd - Removes the last element in the
	 * list. Takes no action if the list is empty.
	 */
	void removeAtEnd();

private:
	/*
	 * Start and end pointers.
	 */
	LinkedListNode *start;
	LinkedListNode *end;

	/*
	 * Private helper methods.
	 */
	void copyOther(const LinkedList& other);
	void clear();
};

#endif

