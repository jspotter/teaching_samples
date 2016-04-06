#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	string filename = "file1.txt";
	filename += "";
	ofstream ofs(filename);
	ifstream ifs(filename);
	// ofs.open(filename);

	ofs << "hi\n";
	
	ofs.close();


	return 0;
}
