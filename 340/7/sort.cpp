#include <cstdlib>
#include <iostream>
#include <time.h>     // for seeding our random number generator
using namespace std;

static const int LIST_SIZE = 20;
static const int LIST_MAX = 100;

void merge(int list[], int lh, int pivot, int rh)
{
	int temp[rh - lh + 1];
	int leftIndex = lh, rightIndex = pivot + 1, outputIndex = 0;

	while (leftIndex <= pivot && rightIndex <= rh) {

		// Append the smaller of the two numbers at the front of
		// each of our two sublists
		if (list[leftIndex] < list[rightIndex]) {
			temp[outputIndex] = list[leftIndex];
			leftIndex++;
		} else {
			temp[outputIndex] = list[rightIndex];
			rightIndex++;
		}

		// Increment the output index regardless of which
		// list we drew from
		outputIndex++;
	}

	// Figure out which list still has numbers, and write
	// them to the output array
	if (leftIndex > pivot) {
		for (int i = rightIndex; i <= rh; i++) {
			temp[outputIndex] = list[i];
			outputIndex++;
		}
	} else if (rightIndex > rh) {
		for (int i = leftIndex; i <= pivot; i++) {
			temp[outputIndex] = list[i];
			outputIndex++;
		}
	}

	// Put merged values back into original list
	for (int i = 0; i < rh - lh + 1; i++) {
		list[lh + i] = temp[i];
	}
}

void mergeSort(int list[], int lh, int rh)
{
	if (lh >= rh) {
		return;
	}

	int pivot = (lh + rh) / 2;
	mergeSort(list, lh, pivot);
	mergeSort(list, pivot + 1, rh);
	merge(list, lh, pivot, rh);
}

int main()
{
	int list[LIST_SIZE];

	// Seed our random number generator (to make sure it
	// outputs different numbers every time)
	srand(time(NULL));

	// Generate random numbers for our list
	for (int i = 0; i < LIST_SIZE; i++) {
		list[i] = rand() % LIST_MAX;
		cout << list[i] << endl;
	}
	cout << "-----" << endl;

	mergeSort(list, 0, LIST_SIZE - 1);

	for (int i = 0; i < LIST_SIZE; i++) {
		cout << list[i] << endl;
	}

	return 0;
}

