#include <iostream>
#include <stdio.h>
#include <string.h>

void Merge(int* arr, int* tmp, int start, int mid, int end)
{
    int arr1Start = start;   
    int arr2Start = mid + 1;
    int tmpStart  = start;

    while (arr1Start <= mid && arr2Start <= end)
    {
        if (arr[arr1Start] < arr[arr2Start])
        {
            tmp[tmpStart++] = arr[arr1Start++];
        }
        else
        {
            tmp[tmpStart++] = arr[arr2Start++];
        }
    }

    while (arr1Start <= mid)
    {
        tmp[tmpStart++] = arr[arr1Start++];
    }

    while (arr2Start <= end)
    {
        tmp[tmpStart++] = arr[arr2Start++];
    }

    for (int i=start;i<=end;++i)
    {
        arr[i] = tmp[i];
    }
}

void MSort(int* input, int* output, int start, int end)
{
    if (start < end)
    {
        int mid   = start + (end - start) / 2;

        MSort(input, output, start, mid);
        MSort(input, output, mid+1, end);
        Merge(input, output, start, mid, end);
    }
}

void MergeSort(int* input, int* output, int iLen)
{
    if (!input || !output || iLen<=0)
    {
        return ;
    }

    MSort(input, output, 0, iLen-1);
}

int main(int argc, char* argv[])
{
    int arr1[] = {3, 5, 7, 2, 6, 9, 28, 0, 4};
    int arr2[9];

    memset(arr2, 0, sizeof arr2);

    MergeSort(arr1, arr2, 9);

    for (int i=0; i<9; ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}
