#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <exception>
#include <iostream>

class MatrixDimensionException : public std::exception
{
public:
	virtual const char* what() const throw();
};

class MatrixIndicesOutOfBoundsException : public std::exception
{
public:
	virtual const char* what() const throw();
};

/*
 * This class represents a matrix of integers.
 * It can have arbitrary dimensions.
 */
class Matrix {
public:
	// The default constructor creates a 0x0 matrix.
	Matrix();

	// The 2-arg constructor creates a matrix with
	// numRows rows and numCols columns.
	Matrix(int numRows, int numCols);

	// get returns the value at a particular row and
	// column.
	//
	// set changes the value at a particular row
	// and column.
	int get(int row, int col) const;
	void set(int row, int col, int val);

	// MATH!
	Matrix operator+(const Matrix& other) const;
	Matrix operator-() const;

	// Output
	friend std::ostream& operator<<(std::ostream& o, const Matrix& m);

	// prints a matrix
	void print() const;
private:
	int nRows, nCols;
	std::vector<std::vector<int> > matrix;

	void checkIndices(int row, int col) const;
	std::string toString() const;
};

#endif
