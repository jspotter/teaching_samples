#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Student
{
public:
	string firstName;
	string lastName;
	int age;
	string favoriteAuthor;
};

int main()
{
	ifstream inputFile("data.csv");
	vector<Student> listOfStudents;

	while(true) {
		string firstName, lastName, age, favoriteAuthor;
		int ageAsInteger;

		getline(inputFile, firstName, ',');
		if (inputFile.fail()) {
			break;
		}

		getline(inputFile, lastName, ',');
		getline(inputFile, age, ',');
		getline(inputFile, favoriteAuthor);

		stringstream ss;
		ss << age;
		ss >> ageAsInteger;
		
		Student s;
		s.firstName = firstName;
		s.lastName = lastName;
		s.age = ageAsInteger;
		s.favoriteAuthor = favoriteAuthor;

		listOfStudents.push_back(s);
	}

	for (Student s : listOfStudents) {
		cout << s.firstName << endl;
		cout << s.lastName << endl;
		cout << s.age << endl;
		cout << s.favoriteAuthor << endl;
		cout << "-----" << endl;
	}

	return 0;
}

