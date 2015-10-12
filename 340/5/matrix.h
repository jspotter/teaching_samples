#ifndef _MATRIX_H
#define _MATRIX_H

#include <map>
#include <utility>
#include <exception>
#include <iostream>

/*
 * In .h files, we do NOT say
 *
 * using namespace std;
 *
 * You'll notice that whenever we refer to exception, map,
 * or pair, we have to say std::exception, std::map, or
 * std::pair. This is because we don't want to force people
 * who use our class to use the std namespace.
 */

class MatrixAdditionException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "You can only add matrices with identical dimensions.";
	}
};

class MatrixMultiplicationException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "You can only multiply matrices when the first matrix's \
		        number of columns matches the second matrix's number \
						of rows.";
	}
};

// This class represents a matrix of integers of
// an arbitrary size.
class Matrix
{
	public:
		// The default constructor creates a 0x0 matrix.
		Matrix();

		// Constructor that creates a rows x cols matrix.
		Matrix(int rows, int cols);

		// For this particular class, we can let C++ create
		// a default destructor, copy constructor, and
		// assignment operator. If we wanted to explicitly
		// define them, we could do so like this:
		//
		// Destructor:
		//
		// ~Matrix();
		//
		// Copy constructor:
		//
		// Matrix(const Matrix& other);
		//
		// Assignment operator:
		//
		// Matrix& operator=(const Matrix& other);
		
		// Get the dimensions of this matrix (permanent once set)
		int numRows() const;
		int numCols() const;

		// Getter and setter. Specify a row, column, and
		// value for the cell at that row and column.
		//
		// Note that get inserts a default value if one was
		// not there already. As a result, it cannot be const.
		int get(int row, int col) const;
		void set(int row, int col, int val);

		// Matrix operations
		const Matrix operator+(const Matrix& other) const throw (MatrixAdditionException);
		const Matrix operator*(const Matrix& other) const throw (MatrixMultiplicationException);
		const Matrix operator-() const;
		friend std::ostream& operator<< (std::ostream& o, const Matrix &m);

		// Print this matrix to the console
		void print() const;
	private:
		int nRows, nCols;
		std::map<std::pair<int, int>, int> matrix;

		int rowTimesColumn(const Matrix& other, int row, int col) const;
		std::string toString() const;
};

#endif

