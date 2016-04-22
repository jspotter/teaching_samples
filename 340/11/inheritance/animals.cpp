#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Animal is an "abstract class" because it has a
// pure virtual function. This means it cannot be
// instantiated.
class Animal {
public:
    void move() { 
        cout << "This animal moves in some way" << endl; 
    }

	// Pure virtual function
	//
	// This means we cannot instantiate an Animal.
    virtual void eat() = 0;
};

class Llama : public Animal {
public:
	void move() {
		cout << "Dance like a llama!" << endl;
	}

    void eat() { 
        cout << "Llamas eat grass!" << endl; 
    }
};

class Wolf : public Animal {
public:
	void eat() {
		cout << "Wolves eat people!" << endl;
	}
};

int main()
{
	// Lines that have been commented out would
	// not compile because they require instantiating
	// an abstract class.

	// Animal animal;
	Llama llama;
	Wolf wolf;

	// animal.move();
	// animal.eat();
	
	llama.move();
	llama.eat();

	wolf.move();
	wolf.eat();

	cout << "-----" << endl;

	/*
	
	vector<Animal> v;
	v.push_back(animal);
	v.push_back(llama);
	v.push_back(wolf);

	for (int i = 0; i < v.size(); i++) {
		v[i].move();
		v[i].eat();
	}

	*/

	vector<Animal*> v2;
	// v2.push_back(new Animal());
	v2.push_back(new Llama());
	v2.push_back(new Wolf());

	for (int i = 0; i < v2.size(); i++) {
		v2[i]->move();
		v2[i]->eat();
	}

	return 0;
}

