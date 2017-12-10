#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void solution(int* arr, int len)
{
    vector<int> iv(len, 1);

    if (!arr || len <=0)
        return ;

    int i = 0;            
    int j = len -1;

    for (int k=0; k<len; ++k)
    {
        if (0 == arr[k])
            iv[i++] = 0;
        else if (2 == arr[k])
            iv[j--] = 2;
    }

    copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, "\n"));
}

void solution2(int* arr, int len)
{
    if (!arr || len <=0)
        return ;

    int i = -1;
    int j = -1;
    int k = -1;

    copy(arr, arr+len, ostream_iterator<int>(cout, " "));
    cout << endl;
    for (int l=0; l<len; ++l)    
    {
        if (0 == arr[l])
        {
            arr[++k] = 2;
            arr[++j] = 1;
            arr[++i] = 0;
        }
        else if (1 == arr[l])
        {
            arr[++k] = 2;
            arr[++j] = 1;
        }
        else
        {
            arr[++k] = 2;
        }
    copy(arr, arr+len, ostream_iterator<int>(cout, " "));
    cout << endl;
    }

    copy(arr, arr+len, ostream_iterator<int>(cout, " "));
    cout << endl;
}

void extersion(int* arr, int len)
{
    if (!arr || len <=0)
        return ;

    int i1 = -1;
    int j2 = -1;
    int k3 = -1;
    int l4 = -1;
    int m5 = -1;

    for (int i=0; i<len; ++i)
    {
        if (1 == arr[i])
        {
            arr[++m5] = 5;
            arr[++l4] = 4;
            arr[++k3] = 3;
            arr[++j2] = 2;
            arr[++i1] = 1;
        }
        else if (2 == arr[i])
        {
            arr[++m5] = 5;
            arr[++l4] = 4;
            arr[++k3] = 3;
            arr[++j2] = 2;
        }
        else if (3 == arr[i])
        {
            arr[++m5] = 5;
            arr[++l4] = 4;
            arr[++k3] = 3;
        }
        else if (4 == arr[i])
        {
            arr[++m5] = 5;
            arr[++l4] = 4;
        }
        else
        {
            arr[++m5] = 5;
        }
    }
    copy(arr, arr+len, ostream_iterator<int>(cout, " "));
    cout << endl;

}

int main(int argc, char* argv[])
{
    int arr[] = {0,1,2,0,1,2};
    int arr2[] = {1,2,0,0,2};
    int arr3[] = {1,1,0,0,2};
    solution2(arr, sizeof(arr)/sizeof(arr[0]));   
    cout << endl;
    solution2(arr2, sizeof(arr2)/sizeof(arr2[0]));   
    cout << endl;
    solution2(arr3, sizeof(arr3)/sizeof(arr3[0]));   
    cout << endl;

    int arr4[] = {5,4,4,2,3,1};
    extersion(arr4, sizeof(arr4)/sizeof(arr4[0]));   
    cout << endl;


    return 0;
}
