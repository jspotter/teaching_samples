#include <cstdlib>
#include <iostream>
using namespace std;

struct Student
{
	string name;
	int age;
	string year_in_school;
};

void some_function(const Student &s)
{
	// s.name = "George Clooney";
	// s.age = 0;
	cout << "name: " << s.name << ", age: " << s.age
		 << ", year in school: " << s.year_in_school << endl;
}

int main()
{
	Student me;
	me.name = "Jonathan";
	me.age = 100;
	me.year_in_school = "what is school?";

	cout << "name: " << me.name << ", age: " << me.age
		 << ", year in school: " << me.year_in_school << endl;
	
	some_function(me);

	cout << "name: " << me.name << ", age: " << me.age
		 << ", year in school: " << me.year_in_school << endl;

	return 0;
}

