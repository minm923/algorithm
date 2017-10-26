#include <stdio.h>
#include <stdlib.h>

void printarr(int* arr,int n)
{
    for(int i=0; i<n; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void Swap(int* p1, int* p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int solution(int* arr, int n, bool func(int e))
{
    if (!arr || n <=0)
        return 1;

    int start = 0;
    int end   = n-1;

    while (start < end)
    {
        while (func(arr[start]))
            ++start;

        while (!func(arr[end]))
            --end;

        if (start < end) // attention 注意判断 start end
            Swap(arr+start, arr+end);
    }
    
    return 0;
}

bool IsOdd(int e)
{
    return (e & 1);
}

int main(int argc, char* argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    solution(arr, 9, IsOdd);
    printf("final...\n");
    printarr(arr, 9);

    return 0;
}
