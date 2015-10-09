#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

static const int LIST_SIZE = 20;
static const int MAX_VALUE = 50;

// Recursively find the maximum int in an array
//
// list: the array of numbers
// size: the number of things in the list
// start: the index in the list that we should start at
//        (we ignore everything before start)
int find_max(int list[], int size, int start)
{
	// If we are only responsible for finding the max
	// of a list of size 1, return the only number
	// the list contains
	if (size == 1) {
		return list[start];
	}

	// Compare the first number in the list to the biggest
	// number in the rest of the list
	int first = list[start];
	int max_of_rest = find_max(list, size - 1, start + 1);

	return first > max_of_rest ? first : max_of_rest;
}

int main()
{
	// Create a list with some random numbers in it
	srand(time(NULL));

	int my_list[LIST_SIZE];
	for (int i = 0; i < LIST_SIZE; i++) {
		my_list[i] = rand() % MAX_VALUE;
		cout << my_list[i] << endl;
	}
	cout << "-----" << endl;

	int max = find_max(my_list, LIST_SIZE, 0);

	cout << "Max: " << max << endl;

	return 0;
}

