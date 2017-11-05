#include <iostream>
#include <limits.h>
#include <string.h>

using namespace std;

// trick 动态规划
void solution2(int* arr, int* res, int iLen)
{
    if (!arr || !res || iLen <=0)
        return ;

    for (int i=0; i<iLen; ++i)
    {
        if (0 == i)
        {
            res[i] = arr[i];
        }
        else
        {
            if (res[i-1] <=0)
                res[i] = arr[i];                    
            else
                res[i] = res[i-1] + arr[i];
        }
    }

    int max = INT_MIN;

    for (int i=0; i<iLen; ++i)
    {
        if (res[i] > max)
            max = res[i];
    }

    cout << max << endl;
}

void solution(int* arr, int iLen)
{
    if (!arr || iLen <=0)
        return ;
    
    int greatestSum = INT_MIN;
    int curSum      = 0;
    
    for (int i=0; i<iLen; ++i)
    {
        if (curSum <= 0)
            curSum  = arr[i];
        else
            curSum += arr[i];

        if (curSum > greatestSum)
            greatestSum = curSum;
    }

    cout << greatestSum << endl;
}

int main(int argc, char* argv[])
{
    int arr1[] = {1,2,3,2,2,2,5,4,2};
    int arr2[] = {1,2,3,2,6,6,6,6,6};
    int arr3[] = {4,5,6,4,6,4,4,3,4};
    int arr4[] = {1,-2,3,10,-4,7,2,-5};

    int res[sizeof(arr4)/sizeof(arr4[0])];
    memset(res, 0, sizeof res);

    solution(arr1, 9);
    solution(arr2, 9);
    solution(arr3, 9);
    solution(arr4, 8);

    cout << "cha" << endl;
    solution2(arr4, res, 8);


    return 0;    
}

