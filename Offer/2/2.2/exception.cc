#include <iostream>
#include <stdexcept>
//#include <exception>

using namespace std;

int main(int argc, char * argv[])
{
    int a = 1;
    int b = 2;

    try
    {
        if (a != b)
        {
            //runtime_error ex("not the same");
            exception ex;
            throw ex;
        }
    }
    catch (runtime_error err)
    {
        cout << "in catch" << endl;
        cout << err.what() << endl;
    }
    catch (exception err)        
    {
        cout << "in second catch" << endl;
        cout << err.what() << endl;
    }

    cout << "end..." << endl;

    return 0;
}
