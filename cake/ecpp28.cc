#include <iostream>
#include <string>

using namespace std;

string  GetName()
{
    return string("gaomin");
}

string  GetName2()
{
    return string("xuyue");
}

int main(int argc, char* argv[])
{
    const char& t = GetName()[1];
    const char * pc = &(GetName()[1]);// pc is a dangling handles

    GetName2();

    cout << *pc << endl;// cout u not a
    cout << t << endl;// cout u not a

    return 0;    
}

