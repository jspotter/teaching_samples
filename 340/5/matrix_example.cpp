#include "matrix.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));

	Matrix m1, m2(3, 4), m3(3, 4), m4(4, 3);

	m1.print();
	m2.print();
	m3.print();

	m2.set(2, 2, -6);
	m3 = m2;

	m2.set(2, 3, -7);

	m2.print();
	m3.print();

	cout << m2.get(2, 2) << endl;

	Matrix mSum = m2 + m3;
	mSum.print();

	cout << "-----" << endl;

	for (int row = 0; row < m3.numRows(); row++) {
		for (int col = 0; col < m3.numCols(); col++) {
			m3.set(row, col, rand() % 10);
		}
	}

	for (int row = 0; row < m4.numRows(); row++) {
		for (int col = 0; col < m4.numCols(); col++) {
			m4.set(row, col, rand() % 10);
		}
	}

	m3.print();
	m4.print();

	Matrix mProd = m3 * m4;
	mProd.print();

	return 0;
}

