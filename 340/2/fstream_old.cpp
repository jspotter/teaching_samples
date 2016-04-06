#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	fstream fs("file.txt");
	vector<int> v;

	fs.seekg(10);
	while (true) {
		int next;
		fs >> next;
		if (fs.fail()) break;
		v.push_back(next);
	}

	fs.clear();
	fs.seekp(10);
	for (int i = 16; i <= 20; i++) {
		fs << i << endl;
	}

	for (int i = 0; i < v.size(); i++) {
		fs << v[i] << endl;
	}

	return 0;
}

