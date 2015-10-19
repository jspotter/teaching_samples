#include <cstdlib>
#include <iostream>
#include <vector>
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

bool spaceshipsAreEqual(const Spaceship& s1, const Spaceship& s2)
{
	return s1 == s2;
}

int main()
{
	vector<Spaceship> myVector;

	for (char i = 0; i < 10; i++) {
		stringstream ss;
		ss << "C";
		myVector.push_back(Spaceship(ss.str(), i));

		cout << myVector[i].name << endl;
		cout << myVector[i].numLights << endl;
		cout << "---" << endl;
	}

	Spaceship s1("C", 2);
	Spaceship s2("C", 3);

	Spaceship sArray[] = { s1, s2 };

	vector<Spaceship>::iterator iter = search(myVector.begin(), myVector.end(), sArray, sArray + 2, spaceshipsAreEqual);

	if (iter == myVector.end()) {
		cout << "didn't find anything" << endl;
		return 0;
	}

	Spaceship foundSpaceship = *iter;
	cout << "First spaceship found: spaceship " << foundSpaceship.name << " (" << foundSpaceship.numLights << " lights)"
			 << endl;

	return 0;
}

