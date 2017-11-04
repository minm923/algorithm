#include <iostream>

using namespace std;

void solution(int* arr, int iLen)
{
    if (!arr || iLen <=0)
        return ;

    int iCount = 0;
    int Num    = 0;

    for (int i=0; i<iLen; ++i)
    {
        if (0 == iCount)
        {
            Num = arr[i];
            ++iCount;                
        }
        else
        {
            if (Num == arr[i])
                ++iCount;
            else
                --iCount;
        }
    }

    cout << Num << endl;
}


int main(int argc, char* argv[])
{
    int arr1[] = {1,2,3,2,2,2,5,4,2};
    int arr2[] = {1,2,3,2,6,6,6,6,6};
    int arr3[] = {4,5,6,4,6,4,4,3,4};

    solution(arr1, 9);
    solution(arr2, 9);
    solution(arr3, 9);

    return 0;    
}

