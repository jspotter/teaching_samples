#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void printVector(const vector<string>& v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	cout << "-----" << endl;
}

int main()
{
	srand(time(NULL));

	vector<string> v;
	
	for (int i = 0; i < 10; i++) {
		if (i % 3 == 0)
			v.push_back("a");
		else
			v.push_back("b");
	}

	printVector(v);

	/* for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == "b") {
			v.erase(iter);
		}
	}

	printVector(v); */

	for (vector<string>::iterator iter = v.end() - 1; iter >= v.begin(); iter--) {
		if (*iter == "b")
			v.erase(iter);
	}

	printVector(v);

	return 0;
}

