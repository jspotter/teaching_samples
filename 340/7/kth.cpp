#include <iostream>
#include <time.h>
using namespace std;

int findKthBiggest(int nums[], int k, int lh, int rh)
{
	if (k > rh - lh) {
		return INT_MIN;
	}

	int pivot = 


}

int main()
{
	srand(time(NULL));

	int numbers[] = {1, 6, 4, 7, 8, 10, 5, 3, 2, 9};

	cout << findKthBiggest(numbers, 3, 0, 9) << endl;
	cout << findKthBiggest(numbers, 6, 0, 9) << endl;

	return 0;
}
