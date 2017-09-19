#include <iostream>
#include <algorithm>
#include <stdint.h>

using namespace std;

int main(int argc, char * argv[])
{
    uint64_t a = 0;
    uint64_t b = 0;

    while(cin >> a >> b)
    {
        cout << min(a, b) << endl;
    }


    return 0;    
}
