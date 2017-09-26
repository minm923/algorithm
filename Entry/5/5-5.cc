#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>

// 集合练习
using namespace std;



int main(int argc, char * argv[])
{
    vector<int> iv;
    iv.push_back(1);
    iv.push_back(2);
    iv.push_back(3);
    iv.push_back(11);

    set<int> iv2;
    iv2.insert(5);
    iv2.insert(9);
    set<int>::iterator tti = iv2.begin();
    ++tti;

    copy(iv.begin(), iv.end(), insert_iterator<set<int> >(iv2, tti));


    for (set<int>::iterator it=iv2.begin(); it!=iv2.end(); ++it)
    {
        cout << *it  << endl;
    }


    return 0;
}


