#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifs;
	string str;

	ifs.open("garbage.cpp");
	if (ifs.fail()) cout << "failllll" << endl;
	while (true) {
		getline(ifs, str);
		if (ifs.fail()) break;

		cout << str << endl;
	}

	return 0;
}

