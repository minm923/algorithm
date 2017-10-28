#include <iostream>

using namespace std;

bool solution(int* arr1, int* arr2, int n)
{
    if (!arr1 || !arr2 || n <=0)
        return false;

    int FirstElm = arr2[0];
    int flg1 = -1;

    for (int i=0; i<n; ++i)
    {
        if (arr1[i] == FirstElm)
        {
            flg1 = i;
            break;
        }
    }

    if (-1 == flg1)
        return false;        

    int flg2 = flg1 - 1;
    int flg3 = flg1 + 1;

    for (int i=1; i<n; ++i)
    {
        if (flg2>=0 && arr1[flg2] == arr2[i])
        {
            --flg2;
        }
        else if (flg3<n && arr1[flg3] == arr2[i])
        {
            ++flg3;
        }
        else
        {
            return false;
        }

    }

    return true;
}

int main(int argc, char* argv[])
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {4, 3, 5, 1, 2};
    int arr3[5] = {4, 5, 3, 2, 1};

    cout << solution(arr1, arr2, 5) << endl;
    cout << solution(arr1, arr3, 5) << endl;

    return 0;
}
