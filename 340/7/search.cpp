#include <iostream>
using namespace std;

int binarySearch(int nums[], int toFind, int lh, int rh)
{
	if (lh == rh) {
		return nums[lh] == toFind ? lh : -1;
	}

	int pivot = (lh + rh) / 2;
	if (nums[pivot] == toFind) {
		return pivot;
	}

	if (nums[pivot] > toFind) {
		rh = pivot - 1;
		return binarySearch(nums, toFind, lh, rh);
	} else {
		lh = pivot + 1;
		return binarySearch(nums, toFind, lh, rh);
	}
}

int main()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };

	cout << binarySearch(numbers, 3, 0, 6) << endl;

	return 0;
}

