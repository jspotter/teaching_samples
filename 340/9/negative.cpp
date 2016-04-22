#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i * 3);
	}

	for (int i = 0; i < 10; i++) {
		cout << v[i] << endl;
	}

	cout << "-----" << endl;

	transform(v.begin(), v.begin() + 5, v.begin() + 9, [] (int i) -> int {
		return -i;
	});

	for (int i = 0; i < 10; i++) {
		cout << v[i] << endl;
	}

	cout << "-----" << endl;

	return 0;
}

