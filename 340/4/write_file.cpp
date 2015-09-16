#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream ofs;
	string str;

	ofs.open("my_important_info.txt", ios_base::app);
	for (int i = 0; i < 10; i++) {
		ofs << i << " ";
	}

	ofs.close();

	return 0;
}

