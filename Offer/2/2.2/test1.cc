#include <iostream>

using namespace std;

class Base
{
public:
    virtual void f() { cout << "Base::f()" << endl; }
};

class Derive : public Base
{
public:    
    virtual void f() { cout << "Derive::f2()" << endl; }
};

int main(int argc, char * argv[])
{
    Base * pbase = new Derive();
    pbase->f2();

    return 0;    
}
