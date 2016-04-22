#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public:
	Animal() : name("Animal")
	{
	}

	virtual void printName()
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
		speed = "75";
	}

	void run()
	{
		cout << speed << "mpg omgggg" << endl;
	}

	void printName() {
		cout << "Rawaawawwr" << endl;
	}

	string speed;
};

int main()
{
	vector<Animal*> v;
	v.push_back(new Animal());
	v.push_back(new Cheetah());
	v.push_back(new Animal());

	for (int i = 0; i < v.size(); i++) {
		v[i]->printName();
	}

	// This won't compile!
	// cout << v[1]->speed << endl;
}
