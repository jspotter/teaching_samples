#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Spaceship
{
	public:
		string name;
		int numLights;

		Spaceship() : name(""), numLights(0)
		{
			// nada
		}

		Spaceship(string n, int nl) : name(n), numLights(nl)
		{
			// nothing here
		}
		
		bool operator==(const Spaceship& other) const
		{
			return name == other.name && numLights == other.numLights;
		}
};

int main()
{
	vector<Spaceship> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(Spaceship("I'm a spaceship", i));
	}

	Spaceship s("I'm a spaceship", 3);
	vector<Spaceship>::iterator iter = find(myVector.begin(), myVector.end(), s);

	cout << iter->name << endl;
	cout << iter->numLights << endl;
	
	return 0;
}

