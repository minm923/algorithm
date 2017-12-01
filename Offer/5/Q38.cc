#include <iostream>
#include <stdio.h>

int* valueposition(int* start, int len, int value)
{
    int* left  = start;    
    int* right = start + len - 1;
    int* mid   = NULL;
    int* pos   = NULL;

    while (left <= right)
    {
        mid = (right - left) / 2 + left;        

        if (*mid > value)
        {
            right = mid - 1;
        }
        else if (*mid < value)
        {
            left = mid + 1;
        }
        else
        {
            pos = mid;
            break;
        }
    }

    return pos;
}

int solution(int* start, int len, int value)
{
    if (!start || len <=0)
        return 0;

    int count = 0;
    int * pos = valueposition(start, len, value);
    if (pos)
    {
        ++count;
        int* up  = pos + 1;
        int* low = pos - 1;
        while (up < (start+len) && *up == value)
        {
            ++count;
            ++up;
        }

        while (low >= start && *low == value)
        {
            ++count;
            --low;
        }
    }

    return count;
}

int main(int argc, char * argv[])
{
    int arr[] = {1,2,3,3,3,3,5};

    printf("%d \n",solution(arr, 7, 3));
    printf("%d \n",solution(arr, 7, 1));
    printf("%d \n",solution(arr, 7, 2));
    printf("%d \n",solution(arr, 7, 5));
    printf("%d \n",solution(arr, 7, 4));
    printf("%d \n",solution(arr, 7, 0));


    return 0;
}
