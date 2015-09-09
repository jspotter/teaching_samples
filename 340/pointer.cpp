#include <cstdlib>
#include <iostream>
using namespace std;

struct MyStruct
{
	int x;
	int y;
};

void my_function(MyStruct *s)
{
	(*s).x += 10;
	(*s).y += 10;

	cout << "(" << s->x << ", " << s->y << ")" << endl;
}

int main()
{
	MyStruct* s = new MyStruct();

	s->x = 5;
	s->y = 15;

	my_function(s);

	cout << "(" << s->x << ", " << s->y << ")" << endl;

	return 0;
}

