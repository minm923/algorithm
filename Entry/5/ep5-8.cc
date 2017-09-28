#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <cstdint>

using namespace std;

struct BigInteger
{
    static const int BASE  = 100000000;        
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger (int64_t num = 0) { *this = num; }

    BigInteger operator = (int64_t num)
    {
        s.clear();
        do
        {
            s.push_back(num % BASE);
            num /= BASE;
        }
        while(num > 0);
    }


};


int main(int argc, char * argv[])
{

    return 0;    
}

