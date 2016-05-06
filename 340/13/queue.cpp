#include <cstdlib>
#include <iostream>
#include <queue>
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

	queue<vector<Node<int>*> > myQueue;
	vector<Node<int>*> initial;
	initial.push_back(v[0]);
	Node<int>* endpoint = v[5];
	myQueue.push(initial);

	// Assume that every node can access the nodes
	// whose values are numerically adjacent (i.e.
	// node 1 can access node 2, node 5 can access
	// nodes 4 and 6, etc.)
	while (!myQueue.empty()) {
		vector<Node<int>*> nextPath = myQueue.front();
		Node<int>* lastNode = nextPath.back();
		myQueue.pop();

		if (lastNode == endpoint) {
			printVector(nextPath);
			return 0;
		}

		vector<Node<int>*> pathToInsert(nextPath);
		if (lastNode->value < v.size()) {
			Node<int>* nextNode = v[lastNode->value];
			pathToInsert.push_back(nextNode);
			myQueue.push(pathToInsert);
		}
	}

	cout << "No path from 1 to 6 found!" << endl;

	return 0;
}

