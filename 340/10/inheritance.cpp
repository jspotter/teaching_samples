#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

class Animal
{
public:
	Animal() : name("Animal")
	{
	}

	void printName()
	{
		cout << name << endl;
	}

protected:
	string name;
};

class Cheetah : public Animal
{
public:
	Cheetah()
	{
		name = "Cheetah";
	}

	void run()
	{
		cout << "75 mpg omgggg" << endl;
	}
};

int main()
{
	srand(time(NULL));

	vector<Animal> v;

	for (int i = 0; i < 20; i++) {
		if (rand() % 2 == 0) {
			v.push_back(Cheetah());
		} else {
			v.push_back(Animal());
		}
	}

	for (int i = 0; i < v.size(); i++) {
		v[i].printName();
	}

	return 0;
}

