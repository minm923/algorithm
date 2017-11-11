#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

// ugly number 最优解法
int main(int argc, char* argv[])
{
    const int coeff[3] = {2, 3, 5};
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    set<long long> s;

    pq.push(1);
    s.insert(1);

    for (int i=1; ; ++i)
    {
        long long x = pq.top();
        pq.pop();

        if (1500 == i)
        {
            cout << "1500's ugly number : " << x << endl;
            break;
        }

        for (int j=0; j<3; ++j)
        {
            long long newx = x*coeff[j];
            if (!s.count(newx))
            {
                s.insert(newx);
                pq.push(newx);
            }
        }
    }

    return 0;
}
