#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Path
{
public:
	vector<char> nodes;
	int cost;
};

class PathCompare
{
public:
	bool operator() (const Path& first, const Path& second)
	{
		return first.cost > second.cost;
	}
};

int main()
{
	priority_queue<Path, vector<Path>, PathCompare> pq;

	Path first;
	first.cost = 10;

	Path second;
	second.cost = 5;

	Path third;
	third.cost = 7;

	pq.push(first);
	pq.push(second);
	pq.push(third);

	while (!pq.empty()) {
		Path p = pq.top();
		cout << p.cost << endl;
		pq.pop();
	}

	return 0;
}

