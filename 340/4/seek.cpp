#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("file1.txt");

	int next;
	ifs.seekg(20);
	ifs >> next;
	cout << next << endl;

	return 0;
}

