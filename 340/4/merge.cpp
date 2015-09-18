#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef int

void merge(vector<int> & first, vector<int> & second, vector<int> & result)
{
	// TODO: fill this in
}

void printVector(const vector<int> & v)
{
	// TODO: fill this in
}

int main()
{
	vector<int> firstVector = vector<int>({ 100, 150, 175, 180, 300 });
	vector<int> secondVector = vector<int>({ 130, 155, 178, 190, 200 });
	vector<int> mergedVector = vector<int>();

	merge(firstVector, secondVector, mergedVector);
	printVector(mergedVector);

	return 0;
}

