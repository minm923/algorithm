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

typedef set<int> Set;
// set --> ID
map<Set, int> IDcache;
// ID --> set
vector<Set> SetCache;


int ID(const Set& x)
{
    if (IDcache.count(x))
    {
        return IDcache[x];
    }
    else
    {
        SetCache.push_back(x);
        return IDcache[x] = SetCache.size() - 1;        
    }
}

void empty_stack(stack<int>& s)
{
    while (!s.empty())
    {
        s.pop();
    }
}

int process(const int count);

#define ALL(x) x.begin(),x.end()
//#define INS(x) inserter(x,x.begin())
#define INS(x) insert_iterator<set<int> >(x,x.begin())

stack<int> s;

int main(int argc, char * argv[])
{
    int n = 0;
    cin >> n;

    for (int i=0; i<n; ++i)
    {
        int count = 0;
        cin >> count;        
        process(count);
    }

    return 0;
}


int process(const int count)
{
    empty_stack(s);
    for(int i=0; i<count; ++i)
    {
        string op;
        cin >> op;        

        if ('P' == op[0])
        {
            s.push(ID(Set()));            
        }
        else if('D' == op[0])
        {
            s.push(s.top());
        }
        else
        {
            Set x1 = SetCache[s.top()]; s.pop();
            Set x2 = SetCache[s.top()]; s.pop();
            Set x;
            if ('U' == op[0])
            {
                set_union(ALL(x1), ALL(x2), INS(x));
            }
            else if ('I' == op[0])
            {
                set_intersection(ALL(x1), ALL(x2), INS(x));
            }
            else if ('A' == op[0])
            {
                x = x2;
                x.insert(ID(x1));
            }

            s.push(ID(x));
        }

        cout << SetCache[s.top()].size() << endl;
    }
}
