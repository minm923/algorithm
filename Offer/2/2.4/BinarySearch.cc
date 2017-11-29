#include <iostream>

int BinarySearch(int* arr, int low, int high, int value)
{
    if (arr != NULL && low>=0 && high>=0 && high >=low)
    {
        int mid  = 0;
        long sum = 0;
        while (low <= high)         
        {
            sum = low + high;                
            mid = sum / 2;

            if (arr[mid] > value)
            {
                high = mid -1;                                
            }
            else if (arr[mid] < value)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
    }

    return -1;
}

int main(int argc, char * argv[])
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << BinarySearch(arr, 0, 9, 8) << std::endl;

    return 0;
}
