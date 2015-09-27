#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	string filename = "file1.txt";
	ofstream is;
	is.open(filename);

	is << "hi\n";
	
	is.close();


	return 0;
}
