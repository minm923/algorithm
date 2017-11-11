#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 20
#define MAX_NUM 100;

bool IsFirstEleForwardSecondEle(int a, int b)
{
    static char arr1[N] = {0};
    static char arr2[N] = {0};

    sprintf(arr1, "%d%d", a, b);
    sprintf(arr2, "%d%d", b, a);
    
    bool res = true;
    if (strcmp(arr1, arr2) > 0)
        res = false;

    return res;
}

void Swap(int* e1, int *e2)
{
    int tmp = *e1;
    *e1     = *e2;
    *e2     = tmp;
}

void solution(int* arr, int iLen)
{
    for (int i=0; i<iLen-1; ++i)
    {
        for (int j=i+1; j<iLen; ++j)
        {
            if (!IsFirstEleForwardSecondEle(arr[i], arr[j]))
                Swap(arr+i, arr+j);
        }
    }

    for (int i=0; i<iLen; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

// 使用qsort版本
void solution2(int* arr, int iLen)
{
    if (!arr || iLen <=0)
        return ;

    sort(arr, arr+iLen, IsFirstEleForwardSecondEle);

    for (int i=0; i<iLen; ++i)
        printf("%d", arr[i]);

    printf("\n");

}

int main(int argc, char* argv[])
{
    int arr[]  = {3, 32, 321};
    int arr2[]  = {25, 76, 86, 23, 45};
    int arr3[]  = {9, 2, 3, 56, 3};

    cout << "solution1"  << endl;

    solution(arr, 3);
    solution(arr2, 5);
    solution(arr3, 5);

    cout << "solution2" << endl;

    int arr4[]  = {3, 32, 321};
    int arr5[]  = {25, 76, 86, 23, 45};
    int arr6[]  = {9, 2, 3, 56, 3};


    solution2(arr4, 3);
    solution2(arr5, 5);
    solution2(arr6, 5);

    return 0;    
}
