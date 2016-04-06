#include "linked_list.h"
using namespace std;

LinkedList::LinkedList() {
	start = NULL;
	end = NULL;
}

LinkedList::~LinkedList() {
	LinkedListNode* current = start;
	while (current != NULL) {
		LinkedListNode *temp = current;
		current = current->next;
		delete temp;
	}
}

void LinkedList::insertAtEnd(int val) {
	LinkedListNode* newNode = new LinkedListNode();
	newNode->value = val;
	newNode->next = NULL;
	newNode->prev = end;

	if (end != NULL) {
		end->next = newNode;
	} else {
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
		end = newNode;
	}

	start = newNode;
}

int LinkedList::valueAtEnd() {
	if (end != NULL) {
		return end->value;
	}

	throw LinkedListEmptyException();
}

void LinkedList::removeAtEnd() {
	if (end == NULL) {
		return;
	}

	if (end->prev != NULL) {
		end->prev->next = NULL;
	} else {
		start = NULL;
	}

	LinkedListNode* temp = end;
	end = end->prev;
	delete temp;
}

