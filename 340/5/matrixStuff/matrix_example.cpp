#include "matrix.h"
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));

	Matrix m1;
	Matrix m2(3, 4);
	Matrix m3(3, 4);
	Matrix m4(4, 3);

	m2.set(0, 0, 3);
	m2.set(0, 1, 4);
	m2.set(0, 2, 5);

	cout << m2 << endl;
	cout << "-----" << endl;

	m2.set(2, 2, -6);
	m3 = m2;

	m2.set(2, 3, -7);

	cout << m3 << endl;
	cout << m2 << endl;

	Matrix mSum = m2 + m3;

	cout << "-- Sum --" << endl;

	cout << mSum << endl;

	Matrix m5 = -m2;

	cout << "-- Negative --" << endl;
	cout << m5 << endl;

	cout << m2.get(0, 0) << endl;

	return 0;
}

