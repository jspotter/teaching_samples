#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	vector< vector<int> > matrix;
	ofstream ofs;
	ifstream ifs;

	for (int row = 0; row < 10; row++) {
		matrix.push_back(vector<int>());
		
		for (int col = 0; col < 10; col++) {
			matrix[row].push_back(row * col);
		}
	}

	ofs.open("my_matrix.txt");
	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[0].size(); col++) {
			ofs << matrix[row][col] << " ";
		}

		ofs << endl;
	}

	ofs.close();

	// Do some useful work...

	vector< vector<int> > another_matrix;

	ifs.open("my_matrix.txt");
	string line;
	while (true) {
		getline(ifs, line);

		if (ifs.fail()) break;

		another_matrix.push_back(vector<int>());

		stringstream ss;
		ss << line;

		while (true) {
			int next;
			ss >> next;

			if (ss.fail()) break;

			another_matrix[another_matrix.size() - 1].push_back(next);
		}
	}

	cout << "another_matrix[2][3] = " << another_matrix[2][3] << endl;

	return 0;
}

















