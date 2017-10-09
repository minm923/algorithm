#include <iostream>

using namespace std;

class A
{
public:    
    A(int i) : a(i) { }

    //A(A& ra) { a = ra.a; }

    //void operator = (int i) { a = i; }
    
    void print() 
    {
        cout << a << endl;
    }

private:        
    int a;        
};

int main(int argc, char * argv[])
{
    A ta = 10;    
    ta.print();
    //A ta(10);
    //A b = ta;

    return 0;
}
