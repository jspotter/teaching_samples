#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> q;

	for (int i = 0; i < 10; i++) {
		// can call push_front or push_back
		q.push_back(i);
	}

	while (!q.empty()) {
		// can call front or back, and pop_front
		// or pop_back
		cout << q.back() << endl;
		q.pop_back();
	}
}
