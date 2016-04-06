#include "matrix.h"
#include <sstream>
using namespace std;

Matrix::Matrix() : nRows(0), nCols(0) {}

Matrix::Matrix(int rows, int cols) : nRows(rows), nCols(cols) {

	// Initialize all elements to 0
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			matrix[pair<int, int>(row, col)] = 0;
		}
	}
}

int Matrix::numRows() const
{
	return nRows;
}

int Matrix::numCols() const
{
	return nCols;
}

int Matrix::get(int row, int col) const
{
	return matrix.at(pair<int, int>(row, col));
}

void Matrix::set(int row, int col, int val)
{
	matrix[pair<int, int>(row, col)] = val;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	if (other.numRows() != nRows || other.numCols() != nCols) {
		throw MatrixAdditionException();
	}

	Matrix result(nRows, nCols);
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			result.set(row, col, get(row, col) + other.get(row, col));
		}
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	if (other.numRows() != nCols) {
		throw MatrixMultiplicationException();
	}

	Matrix result(nRows, other.numCols());
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < other.numCols(); col++) {
			result.set(row, col, rowTimesColumn(other, row, col));
		}
	}

	return result;
}

Matrix Matrix::operator-() const
{
	Matrix result(nRows, nCols);
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			result.set(row, col, -get(row, col));
		}
	}

	return result;
}

ostream& operator<< (ostream& o, const Matrix& m)
{
	o << m.toString();
	return o;
}

void Matrix::print() const
{
	cout << toString();
}

string Matrix::toString() const
{
	stringstream ss;
	ss << "[" << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			ss << matrix.at(pair<int, int>(row, col)) << "   ";
		}
		ss << endl;
	}
	ss << "]" << endl;

	return ss.str();
}

int Matrix::rowTimesColumn(const Matrix& other, int row, int col) const
{
	int sum = 0;
	for (int i = 0; i < nCols; i++) {
		sum += get(row, i) * other.get(i, col);
	}
	return sum;
}

