#include "linked_list.h"
using namespace std;

/*
 * Constructor, destructor, copy constructor, and
 * assignment operator.
 */
LinkedList::LinkedList() : start(NULL), end(NULL) {}

LinkedList::~LinkedList()
{
	clear();
}

LinkedList::LinkedList(const LinkedList& other) : start(NULL),
	end(NULL)
{
	copyOther(other);
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	// Make sure we aren't trying to copy the same
	// thing into itself, like:
	//
	// myList = myList;
	if (this != &other) {
		// Remove whatever data we have first, and
		// then copy the data from the other list.
		clear();
		copyOther(other);
	}

	// The "this" variable is a pointer to the current
	// list, so we return what it points to.
	return *this;
}

/* Helper method to copy from another linked list. Used
 * in the copy constructor and the assignment operator. */
void LinkedList::copyOther(const LinkedList& other)
{
	LinkedListNode* current = other.start;
	while (current != NULL) {
		insertAtEnd(current->value);
		current = current->next;
	}
}

/* Helper method to remove everything from the current
 * list. Used in the destructor and the assignment
 * operator. */
void LinkedList::clear() {
	LinkedListNode* current = start;
	while (current != NULL) {
		LinkedListNode *temp = current;
		current = current->next;
		delete temp;
	}

	// Set these to NULL, so we don't have
	// dangling pointers!
	start = NULL;
	end = NULL;
}

/* Insertion methods. */
void LinkedList::insertAtEnd(int val) {
	LinkedListNode* newNode = new LinkedListNode();
	newNode->value = val;
	newNode->next = NULL;
	newNode->prev = end;

	if (end != NULL) {
		end->next = newNode;
	} else {
		// First node!
		start = newNode;
	}

	end = newNode;
}

void LinkedList::insertAtBeginning(int val) {
	LinkedListNode* newNode = new LinkedListNode();
	newNode->value = val;
	newNode->next = start;
	newNode->prev = NULL;

	if (start != NULL) {
		start->prev = newNode;
	} else {
		// First node!
		end = newNode;
	}

	start = newNode;
}

/* Retrieval */
int LinkedList::valueAtEnd() {
	if (end != NULL) {
		return end->value;
	}

	// This line is only reached if we didn't
	// return.
	throw LinkedListEmptyException();
}

/* Removal */
void LinkedList::removeAtEnd() {
	// Do nothing if the list is empty. */
	if (end == NULL) {
		return;
	}

	// Bookkeeping
	if (end->prev != NULL) {
		end->prev->next = NULL;
	} else {
		start = NULL;
	}

	LinkedListNode* temp = end;
	end = end->prev;

	// Deletion
	delete temp;
}

