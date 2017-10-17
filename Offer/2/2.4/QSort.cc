#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int Partition(int* arr, int low, int high)
{
    int iPovit = arr[low];

    while (low < high)
    {
        while (low < high && arr[high] > iPovit && --high);
        arr[low] = arr[high];

        while (low < high && arr[low]  < iPovit && ++low);
        arr[high] = arr[low];
    }

    arr[high] = iPovit;

    return high;        
}

void QSort(int* arr, int low, int high)
{
    int iPivotPos = Partition(arr, low, high);
    cout << "PivotPos :" << iPivotPos << endl;

    if (iPivotPos-1 > low)
    {
        QSort(arr, low, iPivotPos-1);    
    }

    if (iPivotPos+1 < high)
    {
        QSort(arr, iPivotPos+1, high);
    }
}

void QuickSort(int* arr, int low, int high)
{
    if (!arr || low <0 || high <0 || high<low)
    {
        return ;        
    }

    QSort(arr, low, high);
}

int main(int argc, char * argv[])
{
    int arr[] = {9, 8, 7, 5, 4, 3, 2, 1, 0};

    QuickSort(arr, 0, sizeof(arr)/sizeof(arr[0]) );
    copy(arr, arr+sizeof(arr)/sizeof(arr[0]), ostream_iterator<int>(cout, "\n"));
    

    return 0;
}

