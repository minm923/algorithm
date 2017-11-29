#include <vector>
#include <stdio.h>

using namespace std;

int mymin2(int* rotateArray, int begin, int end)
{
    int imin = rotateArray[begin];
    for (int i=begin; i<=end; ++i)
    {
        if (rotateArray[i] < imin)
            imin = rotateArray[i];
    }

    printf("res %d\n", imin);
    return imin;
}

int mymin(int* rotateArray, int i)
{
    if (i<=0)
        return 0;
    
    int begin = 0;
    int end   = i - 1;
    
    if (rotateArray[begin] < rotateArray[end])
    {
        printf("res %d\n", rotateArray[begin]);
        return rotateArray[begin];
    }
    else
    {
        while (begin+1 < end)
        {
            int mid = (end - begin) / 2 + begin;
            if (rotateArray[mid] > rotateArray[begin])
            {
                begin = mid;
            }
            else if (rotateArray[mid] < rotateArray[begin]) 
            {
                end = mid;
            }
            else
            {
                return mymin2(rotateArray, begin, end);
            }
        }

        int first  = rotateArray[begin];
        int second = rotateArray[end];
        int res = first > second ? second : first;
        printf("res %d\n", res);
        return res;
    }
}

int main(int argc, char * argv[])
{
    int arr[] = {4, 5, 6, 1, 2, 3};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int arr3[] = {1, 1, 1, 0, 1, 1};
    int arr4[] = {1, 0, 1, 1, 1, 1};
    int arr5[] = {1, 1, 1, 1, 1, 0};

    mymin(arr, 6);
    mymin(arr2, 6);
    mymin(arr3, 6);
    mymin(arr4, 6);
    mymin(arr5, 6);

    return 0;
}
