#include <iostream>
#include <algorithm>
#include <iterator>
#include <time.h>

using namespace std;

void movepovit(int* arr, int low,int high)
{
    int base = high-low+1;
    int index = low + random()%base;
    int tmp = arr[index];
    arr[index] = arr[low];
    arr[low] = tmp;
}

int Partition(int* arr, int low, int high)
{
    movepovit(arr, low, high);

    int ipovit = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= ipovit && --high);// >=
        if (low >= high)
            break;
        else
            arr[low] = arr[high];

        while(low < high && arr[low] < ipovit && ++low);
        if (low >= high)
            break;
        else
            arr[high] = arr[low];
    }

    arr[high] = ipovit;

    return high;
}

void QSort(int* arr, int low, int high)
{
    int iPivotPos = Partition(arr, low, high);

    if (iPivotPos-1 > low)
    {
        QSort(arr, low, iPivotPos-1);    
    }

    if (iPivotPos+1 < high)
    {
        QSort(arr, iPivotPos+1, high);
    }
}

void QuickSort(int* arr, int len)
{
    if (!arr || len <=0)
    {
        return ;        
    }

    QSort(arr, 0, len-1);
}

int main(int argc, char * argv[])
{
    srand(time(NULL));
    int arr[] = {9, 8, 7, 5, 4, 3, 2, 1, 0};
    int arr2[] = {1,2,1,0,2,0};
    int arr3[] = {1,1,1,1,1,0};
    int arr4[] = {0,0,0,0,0,0};

    QuickSort(arr, sizeof(arr)/sizeof(arr[0]));
    copy(arr, arr+sizeof(arr)/sizeof(arr[0]), ostream_iterator<int>(cout, "\n"));

    cout<< "next" << endl;
    QuickSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    copy(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]), ostream_iterator<int>(cout, "\n"));
    cout<< "next" << endl;
    QuickSort(arr3, sizeof(arr3)/sizeof(arr3[0]));
    copy(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]), ostream_iterator<int>(cout, "\n"));
    cout<< "next" << endl;
    QuickSort(arr4, sizeof(arr4)/sizeof(arr4[0]));
    copy(arr4, arr4+sizeof(arr4)/sizeof(arr4[0]), ostream_iterator<int>(cout, "\n"));

    return 0;
}
