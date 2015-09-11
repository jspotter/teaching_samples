#include "linked_list.h"

LinkedList::LinkedList() {
	this->start = NULL;
	this->end = NULL;
}

LinkedList::~LinkedList() {
	LinkedListNode *current = this->start;
	while (current != NULL) {
		LinkedListNode *temp = current;
		current = current->next;
		delete temp;
	}
}

void LinkedList::push(int val) {
	LinkedListNode *new_node = new LinkedListNode();
	new_node->value = val;
	new_node->next = NULL;
	new_node->prev = this->end;

	if (this->end != NULL) {
		this->end->next = new_node;
	} else {
		this->start = new_node;
	}

	this->end = new_node;
}

int LinkedList::peek() {
	if (this->end != NULL) {
		return this->end->value;
	}

	return -1;
}

int LinkedList::pop() {
	if (this->end != NULL) {
		int val = this->end->value;
		remove(this->end);
		return val;
	}

	return -1;
}

void LinkedList::remove(LinkedListNode *node, int *return_value) {
	if (this->start == node) {
		this->start = node->next;
	} else if (node->prev != NULL) {
		node->prev->next = node->next;
	}

	if (this->end == node) {
		this->end = node->prev;
	} else if (node->next != NULL) {
		node->next->prev = node->prev;
	}

	delete node;
}

