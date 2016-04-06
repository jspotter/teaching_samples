#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int getSum(const vector<int>& intsToSum) {
	int sum = 0;
	for (int next : intsToSum) {
		sum += next;
	}
	return sum;
}

int main()
{
	string line;
	stringstream ss;
	vector<int> listOfNumbers;
	
	cout << "Give me some numbers: ";
	getline(cin, line);

	ss << line;
	while (true) {
		int next;
		ss >> next;
		if (ss.fail()) {
			break;
		}

		listOfNumbers.push_back(next);
	}

	cout << "The sum is: " << getSum(listOfNumbers) << endl;
	cout << "The original line was " << line << endl;

	return 0;
}

