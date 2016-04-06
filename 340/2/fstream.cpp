<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string formatForFile(int nextNumber)
{
	if (nextNumber >= 10) {
		return to_string(nextNumber);
	} else {
		return "0" + to_string(nextNumber);
	}
}

int main()
{
	fstream fileOfNumbers("file.txt");
	int x;
	vector<int> vectorOfNumbers;

	while (true) {
		fileOfNumbers >> x;
		if (fileOfNumbers.fail()) {
			break;
		}

		vectorOfNumbers.push_back(x);
	}

	fileOfNumbers.clear();
	fileOfNumbers.seekp(0);
	
	for (int next : vectorOfNumbers) {
		cout << "next num in vector: " << next << endl;
		cout << "write cursor: " << fileOfNumbers.tellp() << endl;
		string nextString = formatForFile(next + 1);
		fileOfNumbers << nextString << endl;
	}

	fileOfNumbers.close();
=======
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
>>>>>>> 47ce6e1bfd1dd7f5642f7fa6fd9aaf3921a10844

	return 0;
}

