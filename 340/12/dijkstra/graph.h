#ifndef _GRAPH_H
#define _GRAPH_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stdexcept>

/*
 * Exception for trying to find
 * a path between two nodes if
 * at least one of the nodes
 * doesn't exist.
 */
class NonExistentNodeException : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "At least one of those nodes doesn't exist!";
	}
};

/*
 * Exception for trying to find
 * a path between two nodes when
 * no path exists.
 */
class NoPathException : public std::exception
{
public:
	virtual const char* what() const throw() {
		return "No path exists between those two nodes!";
	}
};

/*
 * Node
 * -----
 * Represents a node in a graph. T is
 * the type of value held in the node.
 */
template <typename T>
class Node
{
public:
	Node(const T& value) : value(value) {}

	/*
	 * Why wouldn't this do what we want?
	 *
	 * Hint: what is the new node connected to?
	 */
	/*

	Node<T>* copy(const Node& other) {
		return new Node<T>(value);
	}

	*/
	
	/*
	 * Why not a vector for the list of adjacent
	 * nodes?
	 */
	std::unordered_set<Node<T>*> adjacents;
	T value;
	bool marked;
};

/*
 * Graph
 * -----
 * Represents a bi-directional (undirected)
 * graph. Nodes can have any value. The
 * graph does not have to be connected. Values
 * must be unique.
 */
template <typename T>
class Graph
{
public:
	Graph() {}
	
	/*
	 * Since we dynamically allocate each node,
	 * we need the big 3!
	 * 
	 * - destructor
	 * - copy constructor
	 * - assignment operator
	 */
	~Graph() {
		clear();
	}

	Graph(const Graph<T>& other) {
		copyOther(other);
	}

	Graph<T>& operator=(const Graph<T>& other) {
		if (this != &other) {
			clear();
			copyOther(other);
		}
		return *this;
	}

	/*
	 * Common graph operations.
	 */
	Node<T>* insert(const T& value) {
		if (values.find(value) != values.end()) {
			return NULL;
		}

		Node<T>* newNode = new Node<T>(value);
		values[value] = newNode;
		nodes.push_back(newNode);
		return newNode;
	}

	void connect(Node<T>* first, Node<T>* second) {
		first->adjacents.insert(second);
		second->adjacents.insert(first);
	}

	void unmarkAll() {
		for (int i = 0; i < nodes.size(); i++) {
			nodes[i]->marked = false;
		}
	}

	void print() {
		for (int i = 0; i < nodes.size(); i++) {
			std::cout << nodes[i]->value << ": ";
			for (auto iter = nodes[i]->adjacents.begin();
			          iter != nodes[i]->adjacents.end();
								++iter) {

				std::cout << (*iter)->value << " ";
			}
			std::cout << std::endl;
		}
	}

	std::vector<Node<T>*> shortestPath(const T& start, const T& end) {
		if (values.find(start) == values.end() ||
		    values.find(end) == values.end()) {
			throw NonExistentNodeException();
		}

		std::deque<std::vector<Node<T>*> > paths;
		unmarkAll();

		Node<T>* startNode = values[start];
		Node<T>* endNode = values[end];

		startNode->marked = true;
		std::vector<Node<T>*> startPath;
		startPath.push_back(startNode);

		paths.push_back(startPath);

		while (!paths.empty()) {
			std::vector<Node<T>*> currentPath = paths[0];
			paths.pop_front();

			Node<T>* lastNode = currentPath[currentPath.size() - 1];
			for (auto iter = lastNode->adjacents.begin();
			          iter != lastNode->adjacents.end();
								++iter) {
				Node<T>* nextNode = *iter;

				if (!nextNode->marked) {
					nextNode->marked = true;
					std::vector<Node<T>*> nextPath(currentPath);
					nextPath.push_back(nextNode);

					if (nextNode->value == end) {
						return nextPath;
					}

					paths.push_back(nextPath);
				}
			}
		}

		throw NoPathException();
	}

private:
	std::vector<Node<T>*> nodes;
	std::unordered_map<T, Node<T>*> values;  // for uniqueness and lookup

	void copyOther(const Graph<T>& other) {
		for (int i = 0; i < other.nodes.size(); i++) {
			insert(other.nodes[i]->value);
		}

		for (int i = 0; i < other.nodes.size(); i++) {
			auto adjacents = other.nodes[i]->adjacents;
			for (auto iter = adjacents.begin(); iter != adjacents.end(); ++iter) {
				values[other.nodes[i]->value]->adjacents.insert(values[(*iter)->value]);
			}
		}
	}

	void clear() {
		for (int i = 0; i < nodes.size(); ++i) {
			delete nodes[i];
		}

		nodes.clear();
	}
};

#endif

