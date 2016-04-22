#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s = "HI THERE";
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << s << endl;
}
