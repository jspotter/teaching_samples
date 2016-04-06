#include "matrix.h"
#include <sstream>
using namespace std;

const char* MatrixDimensionException::what() const throw() {
	return "Dimensions inappropriate for given operation.";
}

const char* MatrixIndicesOutOfBoundsException::what() const throw() {
	return "Indices out of bounds for matrix.";
}

Matrix::Matrix() : nRows(0), nCols(0) { /* empty constructor */ }

Matrix::Matrix(int rows, int cols) : nRows(rows), nCols(cols) {
	for (int row = 0; row < rows; row++) {
		matrix.push_back(vector<int>(cols));
	}
}

void Matrix::checkIndices(int row, int col) const {
	if (row < 0 || col < 0 || row >= nRows || col >= nCols) {
		throw MatrixIndicesOutOfBoundsException();
	}
}

int Matrix::get(int row, int col) const {
	checkIndices(row, col);
	return matrix[row][col];
}

void Matrix::set(int row, int col, int val) {
	checkIndices(row, col);
	matrix[row][col] = val;
}

void Matrix::print() const {
	cout << toString();
}

string Matrix::toString() const {
	stringstream ss;
	ss << "[" << endl;
	for (int row = 0; row < nRows; row++) {
		for (int col = 0; col < nCols; col++) {
			ss << matrix[row][col] << "  ";
		}
		ss << endl;
	}
	ss << "]" << endl;

	return ss.str();
}

Matrix Matrix::operator+(const Matrix& other) const {
	if (nRows != other.nRows || nCols != other.nCols) {
		throw MatrixDimensionException();
	}

	Matrix result(nRows, nCols);
	for (int row = 0; row < nRows; ++row) {
		for (int col = 0; col < nCols; ++col) {
			result.matrix[row][col] = matrix[row][col] + other.matrix[row][col];
		}
	}

	return result;
}

Matrix Matrix::operator-() const {
	Matrix result(nRows, nCols);
	for (int row = 0; row < nRows; ++row) {
		for (int col = 0; col < nCols; ++col) {
			result.matrix[row][col] = -matrix[row][col];
		}
	}

	return result;
}

ostream& operator<<(ostream& o, const Matrix& m) {
	o << m.toString();
	return o;
}
