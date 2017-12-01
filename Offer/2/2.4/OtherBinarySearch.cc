#include <vector>
#include <stdio.h>

using namespace std;

int* fmin(int* arr, int count)
{
    int* pmin = arr;
    for (int i=0; i<count; ++i)
    {
        if (arr[i]<*pmin)
            pmin = arr+i;
    }

    printf("min = %d\n", *pmin);

    return pmin;    
}

int* findmin(int*start, int end)
{
    if (!start || end <=0)
        NULL;                        

    int* left  = start;    
    int* right = start + end -1;
    int* mid   = NULL;

    while (left+1 < right)
    {
        mid = (right - left) / 2 + left;
        if (*mid > *right)
        {
            left = mid;
        }
        else if (*mid < *right)
        {
            right = mid;
        }
        else
        {
            return fmin(left, right-left+1);
        }
    }

    int * res = (*left > *right) ? right : left;
    printf("min = %d\n", *res);

    return res;
}

int main(int argc, char * argv[])
{
    int arr[]  = {4, 5, 6, 1, 2, 3};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int arr3[] = {1, 1, 1, 0, 1, 1};
    int arr4[] = {1, 0, 1, 1, 1, 1};
    int arr5[] = {1, 1, 1, 1, 1, 0};
    int arr6[] = {3, 4, 5, 6, 1, 2};

    findmin(arr, 6);
    findmin(arr2, 6);
    findmin(arr3, 6);
    findmin(arr4, 6);
    findmin(arr5, 6);
    findmin(arr6, 6);

    return 0;
}

