#include <iostream>

using namespace std;

bool solution(int* arr, int iLen)
{
    if (!arr || iLen <=0)
    {
        return false;
    }

    int root  = arr[iLen-1];

    int i = 0;
    for (; i<iLen-1; ++i)
    {
        if (arr[i]>root)
        {
            break;
        }
    }

    for (int j=i+1; j<iLen-1; ++j)
    {
        if (arr[j] < root)
        {
            return false;
        }
    }

    bool lres = true;
    bool rres = true;

    if (i>0)
    {
        lres = solution(arr, i);
    }
    
    if (i<iLen-1)
    {
        rres = solution(arr+i, iLen-i-1);// attention 把最后的去除
    }

    return  lres && rres;
}

int main(int argc, char* argv[])
{
    int arr1[] = {5, 7, 6, 9, 11, 10, 8};
    int arr2[] = {7, 4, 6, 5};

    cout << solution(arr1, 7) << endl;
    cout << solution(arr2, 4) << endl;

    return 0;    
}
