#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Printable
{
public:
	virtual void print() const = 0;
};

class Monkey : public Printable
{
public:
	void print() const {
		cout << "I'm a monkey!" << endl;
	}
};

class FaxMachine : public Printable
{
public:
	void print() const {
		cout << "Fax machine meep moop" << endl;
	}
};

int main()
{
	srand(time(NULL));

	vector<Printable*> printables;
	for (int i = 0; i < 10; i++) {
		if (rand() % 2 == 0)
			printables.push_back(new Monkey());
		else
			printables.push_back(new FaxMachine());
	}

	for (int i = 0; i < printables.size(); i++) {
		printables[i]->print();
		delete printables[i];   // don't ever use this pointer again!
	}

	return 0;
}

