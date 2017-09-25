#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <set>
#include <queue>
#include <map>

using namespace std;

struct cmp
{
    // 个位数较小的在前
    bool operator() (const int a, const int b) const 
    {
        return a%10 > b%10;        
    }
};

priority_queue<int, vector<int>, cmp> pq;

typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL> > pq2;

int main(int argc, char * argv[])
{
    pq.push(11);    
    pq.push(9);    
    pq.push(8);    
    pq.push(2);    
    pq.push(5);    

    while(!pq.empty())
    {
        const int i = pq.top();        
        cout << i << endl;
        pq.pop();
    }

    return 0;    
}

