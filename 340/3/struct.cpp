#include <cstdlib>
#include <iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	string year_in_school;
};

int main()
{
	Student me;
	me.name = "Jonathan";
	me.age = 100;
	me.year_in_school = "what is school?";

	cout << "name: " << me.name << ", age: " << me.age
		 << ", year in school: " << me.year_in_school << endl;

	return 0;
}

