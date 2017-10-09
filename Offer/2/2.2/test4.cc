#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
public:
    virtual void func() { cout << "Base::func()" << endl; }
};

class A: public Base
{
public:    
    void func(int a) { cout << "A::func()" << endl; }
};

class B : public A
{
public:
    void func(int a) { cout << "B::func()" << endl; }
};

int main()
{
    Base * pBase  = new A();
    Base * pBase2 = new A();
    Base * pBase3 = new B();

    const type_info& ty  = typeid(*pBase);
    const type_info& ty2 = typeid(*pBase2);
    const type_info& ty3 = typeid(*pBase3);

    cout << ty.name() << endl;
    cout << ty2.name() << endl;
    cout << ty3.name() << endl;

    return 0;
}
