#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <queue>
#include <map>
#include <stdint.h>
#include <cstdio>
#include <algorithm>

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
            num = num / BASE;
        }
        while(num > 0);

        return *this;
    }

    BigInteger operator = (string & str)
    {
        int x;
        s.clear();
        const int len = str.length();
        const int blocks = (len -1) / WIDTH + 1;// trick 1

        for (int i=0; i<blocks; ++i)
        {
            int end   = len -WIDTH * i;            
            int start = max(0, end-WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }

        return *this;
    }

    // 调试用
    void biprint()
    {
        for (int i=0; i<s.size(); ++i)
        {
            cout << s[i] << endl;
        }
    }


};

ostream& operator << (ostream& out, const BigInteger& x)
{
    out << x.s.back();

    for (int i = x.s.size()-2; i>=0; i--)
    {
        char buf[20] = {0};
        sprintf(buf, "%08d", x.s[i]);
        out << buf ;
    }

    return out;
}

istream& operator >> (istream& cin, BigInteger& x)
{
    string str;
    if (!(cin >> str)) return cin;
    x = str;    

    return cin;
}

BigInteger operator + (BigInteger& a, BigInteger& b)
{
    const int iLena = a.s.size();
    const int iLenb = b.s.size();
    BigInteger res;
    res.s.clear();

    int64_t i = 0;
    int flg = 0;
    while (i<iLena || i<iLenb)
    {
        int s = 0;
        if (i<iLena)
        {
            s += a.s[i];
        }

        if (i<iLenb)
        {
            s += b.s[i];
        }

        printf("s : %lld\n", s);
        res.s.push_back((s%100000000 + flg));                

        if (s/100000000)
        {
            flg = 1;            
        }
        else
        {
            flg = 0;
        }
        
        ++i;
    }

    return res;                            
}

BigInteger operator - (BigInteger& a, BigInteger& b)
{
    const int iLena = a.s.size();
    const int iLenb = b.s.size();
    BigInteger res;
    res.s.clear();

    int64_t i = 0;
    int flg = 0;
    while (i<iLena || i<iLenb)
    {

    } 
}

int main(int argc, char * argv[])
{
    BigInteger a;
    BigInteger b;
    BigInteger c;

    cin >> a;
    cin >> b;

    cout << "aaaaaaaaaaa" << endl;
    a.biprint();
    cout << "bbbbbbbbbbb" << endl;
    b.biprint();

    c = a + b;
    cout << "ccccccccccc" << endl;
    c.biprint();

    cout << c ;

    return 0;    
}

