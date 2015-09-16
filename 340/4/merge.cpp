#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef int

void merge(vector<int>

int main()
{
	vector<int> firstVector = vector<int>({ 100, 150, 175, 180, 300 });
	vector<int> secondVector = vector<int>({ 130, 155, 178, 190, 200 });
	vector<int> mergedVector = vector<int>();

	merge(
	printVector(mergedVector);

	return 0;
}

