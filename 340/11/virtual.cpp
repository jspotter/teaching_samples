#include <cstdlib>
#include <iostream>
using namespace std;

class Parent {
  public:
    void doA() { cout << "doA in Parent" << endl; }
    virtual void doB() { cout << "doB in Parent" << endl; }
};

class Child : public Parent {
  public:
    void doA() { cout << "doA in Child" << endl; }
    void doB() { cout << "doB in Child" << endl; }
};

Parent* p1 = new Parent();
Parent* p2 = new Child();
Child* cp = new Child();

void testStuff() {
  p1->doA();
  p2->doA();
  cp->doA();

  p1->doB();
  p2->doB();
  cp->doB();
}

int main()
{
  testStuff();
  return 0;
}

