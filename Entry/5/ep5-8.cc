#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <stdint.h>
#include <cstdio>

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


    BigInteger operator = (const string& str)
    {
        s.clear();
        int x = 0;
        int len = (str.length() - 1) / WIDTH + 1;

        for (int i=0; i<len; ++i)
        {
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);

            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
    }


};


int main(int argc, char * argv[])
{
    string s = "0123456";        

    cout << s.substr(1, 3) << endl;

    return 0;    
}

