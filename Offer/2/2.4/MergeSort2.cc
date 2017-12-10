#include <iostream>
#include <iterator>
#include <string.h>

int getMinNum(int* input, int& start1, int end1, int& start2, int end2)
{
    int res = 0;
    if (start1>end1 && start2>end2)
    {
        std::cout << "error" << std::endl;
    }
    else if (start1>end1)
    {
        res = input[start2++];
    }
    else if (start2>end2)
    {
        res = input[start1++];
    }
    else
    {
        res = (input[start1] > input[start2]) ? input[start2++] :res = input[start1++];
    }

    return res;
}

void merge(int* input, int* output, int start1, int end1, int start2, int end2)
{
    int index1=start1;
    int index2=start2;

    for (int i=start1; i<= end2; ++i)
    {
        output[i] = getMinNum(input, index1, end1, index2, end2);
    }

    for(int j=start1;j<=end2; ++j)
    {
        input[j] = output[j];
    }
}

void msort(int* input, int* output, int start, int end)
{
    if (start < end)
    {
        int mid = (end - start) / 2 + start;
        msort(input, output, start, mid);
        msort(input, output, mid+1, end);
        merge(input, output, start, mid, mid+1, end);
    }
}

void mergesort(int* input, int* output, int len)
{
    if (!input || !output || len <=0)
        return ;
    
    msort(input, output, 0, len-1);
}

int main(int argc, char * argv[])
{
    int arr1[] = {3, 1, 2};
    int arr2[3];
    memset(arr2, 0, sizeof arr2);
    mergesort(arr1, arr2, sizeof(arr2)/sizeof(arr2[0]));

    for (int i=0; i<3; ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}
