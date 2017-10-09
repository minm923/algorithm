#include <iostream>

using namespace std;

class Base
{
public:
    virtual void f() { cout << "Base::f()" << endl; }
    virtual void g() { cout << "Base::g()" << endl; }
    virtual void h() { cout << "Base::h()" << endl; }
    virtual void i(int a) { cout << "Base::i() " << a << endl; }// ??

};

class Derive : public Base
{
public:
    virtual void f() { cout << "Derive::f()" << endl; }
    virtual void g1() { cout << "Derive::g()" << endl; }
    virtual void h1() { cout << "Derive::h()" << endl; }


};


class Base2
{
public:
    virtual void f() { cout << "Base::f()" << endl; }
    virtual void g() { cout << "Base::g()" << endl; }
    virtual void h() { cout << "Base::h()" << endl; }
    virtual void i(int a) { cout << "Base::i() " << a << endl; }// ??

};

class Base3
{
public:
    virtual void f() { cout << "Base::f()" << endl; }
    virtual void g() { cout << "Base::g()" << endl; }
    virtual void h() { cout << "Base::h()" << endl; }
    virtual void i(int a) { cout << "Base::i() " << a << endl; }// ??

};

class Derive2 : public Base, public Base2, public Base3
{
public:
    virtual void f() { cout << "Derive::f()" << endl; }
    virtual void g1() { cout << "Derive::g()" << endl; }
    virtual void h1() { cout << "Derive::h()" << endl; }

};

typedef void (*Fun) (void);
typedef void (*Fun2) (int a);

int main(int argc, char * argv[])
{

    Base b;

    Fun pFun = NULL;

    cout << "V-Table : " << (void *)(&b) << endl;
    cout << "V-Table first function address : " << (void *)*(long*)(&b) << endl;

    pFun  = (Fun)*((long*)*(long*)(&b)+0);
    pFun();

    pFun  = (Fun)*((long *)*(long*)(&b)+1);
    pFun();

    pFun  = (Fun)*((long*)*(long*)(&b)+2);
    pFun();

    Fun2 pFun2 = NULL;
    pFun2 = (Fun2)*((long*)*(long*)(&b)+3);
    int a = 923;
    pFun2(a);

    //Derive d;

    Derive2 d2;

    return 0;    
}
