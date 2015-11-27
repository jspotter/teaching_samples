#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

template <typename T>
class Node
{
public:
	Node(const T& value) : value(value) {}

	T value;
};

void printVector(const vector<Node<int>*>& v)
{
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << (*iter)->value << endl;
	}
}

int main()
{
	vector<Node<int>*> v;
	for (int i = 0; i < 6; i++) {
		v.push_back(new Node<int>(i + 1));
	}

	deque<vector<Node<int>*> > myDeque;
	vector<Node<int>*> initial;
	initial.push_back(v[0]);
	Node<int>* endpoint = v[5];
	myDeque.push_back(initial);

	// Assume that every node can access the nodes
	// whose values are numerically adjacent (i.e.
	// node 1 can access node 2, node 5 can access
	// nodes 4 and 6, etc.)
	while (!myDeque.empty()) {
		vector<Node<int>*> nextPath = myDeque.front();
		Node<int>* lastNode = nextPath.back();
		myDeque.pop_front();

		vector<Node<int>*> pathToInsert(nextPath);
		if (lastNode->value < v.size()) {
			Node<int>* nextNode = v[lastNode->value];
			pathToInsert.push_back(nextNode);
			if (nextNode == endpoint) {
				printVector(pathToInsert);
				return 0;
			}
			myDeque.push_back(pathToInsert);
		}
	}

	cout << "No path from 1 to 6 found!" << endl;

	return 0;
}

