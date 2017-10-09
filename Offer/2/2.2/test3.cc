#include <iostream>

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

int main()
{
    A a;
    Base * pBase = &a;

    //a.func();// 隐藏
    a.func(1);
    (*pBase).func();
    pBase->func();

    return 0;
}
