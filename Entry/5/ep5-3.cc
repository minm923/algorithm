#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>

using namespace std;

int main(int argc, char * argv[])
{
    set<string> myset;
    string s;
    while(cin >> s)
    {
        // 非字母都替换成空格
        for (int i=0; i<s.size(); ++i)                 
        {
            if (!isalpha(s[i]))
            {
                s[i] = ' ';
            }
            else
            {
                s[i] = tolower(s[i]);
            }
        }

        stringstream ss(s);        
        string word;

        while(ss >> word)
        {
            if (myset.find(word) == myset.end())
            {
                myset.insert(word);
            }
        }
    }

    for(set<string>::iterator it = myset.begin(); it != myset.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;    
}
