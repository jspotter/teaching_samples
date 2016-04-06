#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    void move(void) { 
        cout << "This animal moves in some way" << endl; 
    }
    virtual void eat(void) = 0;
};

// The class "Animal" may possess a definition for eat() if desired.
class Llama : public Animal {
public:
	void move(void) {
		cout << "Dance like a llama!" << endl;
	}

    // The non virtual function move() is inherited but cannot be overridden
    void eat(void) { 
        cout << "Llamas eat grass!" << endl; 
    }
};

class Wolf : public Animal {
public:
	void eat(void) {
		cout << "Wolves eat people!" << endl;
	}
};

int main()
{
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

	/* vector<Animal> v;
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

