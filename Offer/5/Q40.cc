#include <iostream>
#include <stdio.h>
#include <stdlib.h>

unsigned int FindFirstBitIs1(int num)
{
    unsigned int ret = 0X80000000;
    while (0 == (ret&num))
    //while (0 == ret&num)// 优先级问题
    {
        ret >>= 1;
    }

    return ret;
}

int arrxor(int* arr, int len)
{
    int ret = 0;
    for (int i=0; i<len; ++i)
    {
        ret ^= arr[i];
    }

    return ret;    
}

int solution(int* arr, int len, int& res1, int& res2)
{
    if (!arr || len<=0)
        return 1;

    int ret =  arrxor(arr, len);

    unsigned int flg = FindFirstBitIs1(ret);

    res1 = 0;
    res2 = 0;
    for (int i=0; i<len; ++i)
    {
        if (arr[i]&flg)
        {
            res1 ^= arr[i];
        }
        else
        {
            res2 ^= arr[i];
        }
    }

    return 0;
}

int main(int argc, char * argv[])
{
    int arr[] = {3, 4, -1, 4, 3, 2};

    int res1;
    int res2;

    solution(arr, 6, res1, res2);

    std::cout << res1 <<std::endl;
    std::cout << res2 <<std::endl;

    
    return 0;
}
