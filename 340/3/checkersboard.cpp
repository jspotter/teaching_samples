#include <cstdlib>
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class GridIndexException : public exception {
public:
	virtual const char* what() const throw() {
		return "Row or column index out of bounds for grid.";
	}
};

class Grid
{

public:
	Grid() {
		numColumns = 0;
	}

	void addRow() {
		myGrid.push_back(vector<int>(numColumns));
	}

	void addCol() {
		++numColumns;
		for (int row = 0; row < myGrid.size(); ++row) {
			myGrid[row].push_back(0);
		}
	}

	void set(int row, int col, int value) {
		checkIndices(row, col);
		myGrid[row][col] = value;
	}

	int get(int row, int col) {
		checkIndices(row, col);
		return myGrid[row][col];
	}

	void swap(int row1, int col1, int row2, int col2) {
		checkIndices(row1, col1);
		checkIndices(row2, col2);
	
		int temp = myGrid[row1][col1];
		myGrid[row1][col1] = myGrid[row2][col2];
		myGrid[row2][col2] = temp;
	}

	void print() {
		for (int row = 0; row < myGrid.size(); row++) {
			for (int col = 0; col < numColumns; col++) {
				cout << myGrid[row][col] << " ";
			}
			cout << endl;
		}
	}

protected:
	vector<vector<int> > myGrid;
	int numColumns;

	void checkIndices(int row, int col) {
		if (col >= numColumns || row >= myGrid.size() ||
		    col < 0 || row < 0) {
			throw GridIndexException();
		}
	}
};

class CheckersBoard : public Grid
{
public:
	CheckersBoard() {
		for (int i = 0; i < 8; i++) {
			addRow();
			addCol();
		}

		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if (row > 4 && row % 2 != col % 2) {
					myGrid[row][col] = 1;
				}
			}
		}
	}
};

int main()
{
	CheckersBoard g;
	g.print();

	cout << "-----" << endl;

	/*
	g.addCol();
	g.addRow();
	g.addCol();
	g.addRow();
	g.addCol();
	g.addRow();
	g.addCol();

	try {
		g.set(1, 2, 10);
		g.set(100, 200, 10);
		g.set(0, 2, 11);
	} catch(GridIndexException e) {
		cout << "Tried to set something at a bad index" << endl;
	}

	g.swap(1, 2, 0, 2);

	g.print();
	*/
	return 0;
}

