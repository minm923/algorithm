#include <iostream>

/*
class Base
{
private:
    int x;

public:    
    virtual void mf1() = 0;
    virtual void mf2();
    void mf3();
};


class Derived : public Base
{
public:
    virtual void mf1();
    void mf4();
};

void Derived::mf4()
{
    mf2();
}
*/

class Base
{
private:
    int x;
public:    
    virtual void mf1() = 0;

    virtual void mf1(int)
    {
        std::cout << "Base mf1 int " << std::endl;
    }

    virtual void mf2()
    {
        std::cout << "Base mf2 " << std::endl;
    }

    void mf3()
    {
        std::cout << "Base mf3 " << std::endl;
    }

    void mf3(double)
    {
        std::cout << "Base mf3 double " << std::endl;
    }
};

void Base::mf1()
{
    std::cout << "base pure virtual mf1" << std::endl;
}

class Derived : public Base
{
public:
    using Base::mf1;
    using Base::mf3;

    virtual void mf1()
    {
        std::cout << "Derived virtual mf1" << std::endl;
    }

    void mf3()
    {
        std::cout << "Derived mf3" << std::endl;
    }

    void mf4()
    {
        std::cout << "Derived mf4" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Derived d;
    int x;

    d.mf1();
    d.mf1(x);// hide unless using Base::mf1
    d.mf2();
    d.mf3();
    d.mf3(x);//  hide unless using Base::mf2

    return 0;
}

