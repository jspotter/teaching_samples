#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int findKthBiggest(const vector<int>& numbers, int k) {
	// Pick a random element of the vector to be a pivot
	int pivot = numbers[rand() % numbers.size()];

	// Split numbers into left and right. Left has
	// everything less than the pivot, right has
	// everything greater than or equal to the
	// pivot.
	vector<int> left;
	vector<int> right;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] < pivot)
			left.push_back(numbers[i]);
		else
			right.push_back(numbers[i]);
	}

	// Return pivot if it is the kth biggest,
	// otherwise search in left or right if the
	// pivot is too big or too small, respectively.
	if (right.size() == k)
		return pivot;
	else if (right.size() > k - 1)
		return findKthBiggest(right, k);
	else
		return findKthBiggest(left, k - right.size());
}

int main()
{
	srand(time(NULL));

	vector<int> numbers;
	numbers.push_back(6);
	numbers.push_back(4);
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(1);
	numbers.push_back(8);
	numbers.push_back(5);
	numbers.push_back(3);

	cout << findKthBiggest(numbers, 3) << endl;

	return 0;
}

