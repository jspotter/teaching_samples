#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void readIntegers(vector<int>& numbers)
{
	string line;
	stringstream stream;

	cout << "Enter numbers: ";
	getline(cin, line);
	stream << line;

	while (true) {
		int nextInt;
		stream >> nextInt;
		if (stream.fail()) break;
		numbers.push_back(nextInt);
	}
}

vector<int> sortIntegers(const vector<int>& numbers)
{
	vector<int> sorted = vector<int>();


}

void printNumbers(const vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> numbers = vector<int>();
	
	readIntegers(numbers);
	numbers = sortIntegers(numbers);
	printIntegers(numbers);

	return 0;
}

