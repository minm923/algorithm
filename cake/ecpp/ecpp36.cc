#include <iostream>

class B
{
public:
    virtual void mf()
    {
        std::cout << "B mf" << std::endl;
    }
};

class C : public B
{
public:
    virtual void mf()
    {
        std::cout << "C mf" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    C* pC = new C;
    B* pB = pC;

    pC->mf();
    pB->mf();

    return 0;
}

