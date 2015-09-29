#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void merge(const vector<int> & first, const vector<int> & second,
					 vector<int> & result)
{
	int lh = 0, rh = 0;

	while (true) {
		if (lh >= first.size()) {
			for (int i = rh; i < second.size(); i++) {
				result.push_back(second[i]);
				break;
			}
		}

		if (rh >= second.size()) {
			for (int i = lh; i < first.size(); i++) {
				result.push_back(first[i]);
				break;
			}
		}

		int lh;
		int rh;


		////....


		ifs1 >> lh;
		ifs2 >> rh;

		if (ifs1.fail())



		if (ifs2.fail())

		if (lh > rh) {
			// push back lh
			// ifs1 >> lh

		} else {
			// push back rh
			// ifs2 >> rh
		}






		if (first[lh] > second[rh]) {
			result.push_back(second[rh]);
			rh++;
		} else {
			result.push_back(first[lh]);
			lh++;
		}
	}

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

