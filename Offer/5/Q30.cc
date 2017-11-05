#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

const int K = 4;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

int solution(vector<int>& Nums, intSet& kSet)
{
    for (vector<int>::iterator it=Nums.begin(); it!=Nums.end(); ++it)
    {
        if (kSet.size() < K)
        {
            kSet.insert(*it);
        }
        else
        {
            setIterator sit = kSet.begin();
            if (*it < *sit)
            {
                kSet.erase(sit);
                kSet.insert(*it);
            }
        }
    }
}


int main(int argc, char* argv[])
{
    int arr[] =  {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> Nums(arr, arr+8);
    intSet kSet;

    solution(Nums, kSet);

    copy(kSet.begin(), kSet.end(), ostream_iterator<int>(cout, " "));// trick copy cout

    return 0;
}
