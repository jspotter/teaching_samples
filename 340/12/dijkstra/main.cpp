#include "graph.h"
using namespace std;

int main()
{
	Graph<string> g;
	Node<string>* a = g.insert("a");
	Node<string>* b = g.insert("b");
	Node<string>* c = g.insert("c");
	Node<string>* d = g.insert("d");
	Node<string>* e = g.insert("e");
	g.connect(a, b);
	g.connect(c, d);
	g.connect(b, e);
	g.connect(c, e);
	g.print();
	cout << "-----" << endl;

	vector<Node<string>*> path = g.shortestPath("a", "e");
	cout << "Path from a to e: ";
	for (int i = 0; i < path.size(); i++) {
		cout << path[i]->value << " ";
	}
	cout << endl;
	cout << "----" << endl;

	return 0;
}

