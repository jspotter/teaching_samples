#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    void move() { 
        cout << "This animal moves in some way" << endl; 
    }
    virtual void eat() = 0;
};

// The class "Animal" may possess a definition for eat() if desired.
class Llama : public Animal {
public:
	void move() {
		cout << "Dance like a llama!" << endl;
	}

    // The non virtual function move() is inherited but cannot be overridden
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
	vector<Animal> v;

	Llama l;
	Wolf w;

	Animal a = l;

	v.push_back(l);
	v.push_back(w);











	/*
	Llama l;
	l.move();

	vector<Animal*> v(10);
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			v[i] = new Llama();
		} else {
			v[i] = new Wolf();
		}
	}

	for (int i = 0; i < 10; i++) {
		v[i]->eat();
		v[i]->move();
		cout << "-----" << endl;
	}
	*/
	/*
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

	vector<Animal> v;
	v.push_back(animal);
	v.push_back(llama);
	v.push_back(wolf);

	for (int i = 0; i < v.size(); i++) {
		v[i].move();
		v[i].eat();
	}

	*/
	/*
	vector<Animal*> v2;
	// v2.push_back(new Animal());
	v2.push_back(new Llama());
	v2.push_back(new Wolf());

	for (int i = 0; i < v2.size(); i++) {
		v2[i]->move();
		v2[i]->eat();
	}
	*/
	return 0;
}

