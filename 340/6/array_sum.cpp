#include <iostream>
using namespace std;

int sumArray(int numbers[], int size)
{
	if (size == 0) {
		return 0;
	}

	return numbers[0] + sumArray(numbers + 1, size - 1);
}

int main()
{
	int myArray[] = {10, 20, 30, 40, 50};

	cout << sumArray(myArray, 5) << endl;

	return 0;
}

