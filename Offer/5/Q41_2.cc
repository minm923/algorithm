#include <iostream>

class Solution {
public:
    int countSum(int begin, int end)
    {
        long sum = begin + end;

        int s = sum * (end - begin + 1) / 2;

        return s;
    }
    
    void print(int begin, int end, vector<vector<int> >& endv)
    {
        vector<int> arr;

        while (begin <= end)
        {
            arr.push_back(begin++);
        }

        endv.push_back(arr);
    }
    
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > endv;

        for (int i=1; i<sum; ++i)
        {   
            int begin = i;
            int end   = sum - 1;

            while (begin < end)
            {   
                int s = countSum(begin, end);
                if (s == sum)
                {   
                    print(begin, end, endv);
                    break;
                }   
                else if (s > sum)
                {   
                    --end;
                }   
                else
                {   
                    break;
                }   
            }   
        }

        return endv;
    }
};

int main(int argc, char * argv[])
{
    
    return 0;
}

