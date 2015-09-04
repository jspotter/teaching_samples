#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string line;
	stringstream ss;
	int x, y, z;
	
	cout << "Give me some numbers: ";
	getline(cin, line);

	ss << line;
	ss >> x >> y >> z;

	cout << "The sum is " << (x + y + z) << endl;

	return 0;
}

