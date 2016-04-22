#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(30);
	v.push_back(40);
	v.push_back(17);

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}
}
