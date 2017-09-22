#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[])
{

    map<string, int> mymap;
    set<string> myset;
    string s;
    while(cin >> s)
    {
        string ts = s;        

        for (int i=0; i<ts.size(); ++i)
        {
            ts[i] = tolower(ts[i]);            
        }

        sort(ts.begin(), ts.end());        

        if (!mymap.count(ts))
        {
            mymap[ts] = 1;
            myset.insert(s);
        }
    }

    for(set<string>::iterator it = myset.begin(); it != myset.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;    
}
