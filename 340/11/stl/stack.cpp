#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> ints;
	
	for (int i = 0; i < 10; i++) {
		ints.push(i);
	}

	while (!ints.empty()) {
		cout << ints.top() << endl;
		ints.pop();
	}

	return 0;
}

