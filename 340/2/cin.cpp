#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	string str1, str2;

	cout << "Enter two words: ";
	cin >> str1 >> str2;

	cout << "The second word was " << str2
		 << " and the first word was " << str1 << "." << endl;

	return 0;
}

