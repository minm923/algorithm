#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

// stringstream
using namespace std;

int main(int argc, char* argv[]) 
{
    string s = "1 23 # 4";
    stringstream ss;
    ss<<s;
    int val1 = 0;
    int val2 = 0;

    ss >> val1;
    ss >> val2;

    cout << val1;
    cout << val2;
    

    return 0;
    
    while(ss>>s)
    {
        cout<<s<<endl;
        //int val = convert<int>(s);
        //cout<<val<<endl;
    }

    return 0;
}
