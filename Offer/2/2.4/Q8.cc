#include <stdio.h>

int* Min(int* number, int len)
{
    if (!number || len <=0)
    {
        return NULL;
    }

    int front = 0;
    int end   = len - 1;
    int mid   = (end - front) / 2 + front;

    if (number[front] < number[end])
    {
        printf("min %d\n", number[front]);        
        return number;
    }
    else
    {
        while (front+1 != end)
        {
            int mid_value = number[mid];
            if (mid_value > number[front])
            {
                front = mid;
            }
            else if (mid_value < number[front])
            {
                end = mid;
            }
            else
            {
                front += 1;
            }
            
            mid = (end - front) / 2 + front;
        }
    }

    printf("min %d\n", number[end]);

    return number+end;
}

int main(int argc, char *argv[])
{
    int arr[] = {4, 5, 6, 1, 2, 3};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int arr3[] = {1, 1, 1, 0, 1, 1};
    int arr4[] = {1, 0, 1, 1, 1, 1};
    int arr5[] = {1, 1, 1, 1, 1, 0};

    Min(arr, 6);
    Min(arr2, 6);
    Min(arr3, 6);
    Min(arr4, 6);
    Min(arr5, 6);

    return 0;
}
