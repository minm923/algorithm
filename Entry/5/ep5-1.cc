#include <algorithm>
#include <iostream>

using namespace std;

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

    sort(arr, arr+Len);// 升序排列

    int value = 0;
    cin >> value;

    int * pi = upper_bound(arr, arr+Len, value);

    cout << (pi-arr) << endl;
    cout << *pi << endl;


    return 0;    
}
