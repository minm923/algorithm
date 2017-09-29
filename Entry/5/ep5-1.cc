#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int cmp(int a, int b)
{
    return a < b;
}

int main(int argc, char* argv[])
{
    int n = 0;
    const int N = 100;
    int arr[N] = {0};
    int i = 0;

    cin >> n;
    const int Len = n;

    while (n--)
    {
        cin >> arr[i++]; 
    }

    // [arr, arr+Len)
    sort(arr, arr+Len, less<int>());// 升序排列
    cout << "after sort" << endl;

    for (int i=0; i<Len ; ++i)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;

    int value = 0;
    cin >> value;

    int * pi = upper_bound(arr, arr+Len, value);

    cout << (pi-arr) << endl;
    cout << *pi << endl;


    return 0;    
}
