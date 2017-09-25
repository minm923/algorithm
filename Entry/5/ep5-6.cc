#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <queue>
#include <deque>

using namespace std;

int main(int argc, char * argv[])
{
    deque<int> qi;
    
    for (int i=0; i<10; ++i)
    {
        qi.push_back(i);
    }

    cout << qi.front() << endl;
    cout << qi.back()  << endl;
    cout << qi.size()  << endl;
    qi.pop_front();
    cout << qi.front() << endl;
    cout << qi.size()  << endl;

    cout << "-------" << endl;

    for (deque<int>::iterator it=qi.begin(); it!=qi.end(); ++it)
    {
        cout << *it << endl;
    }



    return 0;    
}
