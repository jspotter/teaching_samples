#include <cstdlib>
#include <iostream>
using namespace std;

class Person
{
public:
	string getName() {
		return "JOnathan";
	}
private:
	string name;
	string ssn;
};

class Student : public virtual Person
{
public:
	int getHours() {
		return 10;
	}
private:
	int hours;
};

class Employee : public virtual Person
{
public:
	Employee() : hours(20) {}
	int getHours() {
		return hours;
	}
private:
	int hours;
};

class EmployeeHelper : public Employee
{
public:
	int employeeGetHours() {
		return getHours();
	}
};

class StudentHelper : public Student
{
public:
	int studentGetHours() {
		return getHours();
	}
};

class StudentEmployee : public Student, public Employee // public StudentHelper, public EmployeeHelper
{

};

int main()
{
	StudentEmployee se;
	cout << se.getHours() << endl;
	// cout << se.getName() << endl;
	// cout << se.studentGetHours() << endl;
	// cout << se.employeeGetHours() << endl;

	return 0;
}

