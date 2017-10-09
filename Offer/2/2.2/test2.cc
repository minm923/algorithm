#include <iostream>

using namespace std;

class Base
{
    public:
        virtual void func()
        {
            cout << "Base :" << endl;
        }
        virtual void func(int arg1)
        {
            cout << "Base :" << arg1 << endl;
        }
        void func(int arg1,int arg2)
        {
            cout << "Base :" << arg1 <<": "<< arg2 << endl;
        }
};

class A: public Base
{
    public:
        void func()
        {
            cout << "A :" << endl;
        }
        virtual void func1(){}
};

int main()
{
    Base base;
    A a;
    Base *test =&a;
    test->func();// 重载
    //a.func(1);// 隐藏，编译错误
    //a.func(1,2);//编译错误
    test->func(1); // Base::func(int); 

    return 0;
}
