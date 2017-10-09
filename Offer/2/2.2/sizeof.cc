#include <iostream>

using namespace std;

class c_empty
{

};

class c_con_decon
{
public:    
    c_con_decon() { }
    ~c_con_decon() { }
};

class c_v
{
public:
    virtual void func() { }
};

int main(int argc, char * argv[])
{
    c_empty ce;
    cout << sizeof(ce) << endl;

    c_con_decon ccd;
    cout << sizeof(ccd) << endl;

    c_v cv;
    cout << sizeof(cv) << endl;

    return 0;
}
