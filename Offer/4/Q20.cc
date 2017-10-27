#include <stdio.h>

#define N 4
#define M 5

// trick 复杂问题 先分解出简单的步骤 
void PrintCirCle(int** number, int startN, int endN, int startM, int endM)
{
    if (!number || startN<0 || endN<0 || startM<0 || endM<0)
        return ;        

    for (int i=startM; i<endM; ++i)
        printf("%d ", number[startN][i]);

    for (int i=startN+1; i<endN; ++i)
        printf("%d ", number[i][endM-1]);

    for (int i=endM-2; i>=startM; --i)
        printf("%d ", number[endN-1][i]);

    for (int i=endN-2; i>startN; --i)
        printf("%d ", number[i][startM]);
}

void Solution(int** number, int n, int m)
{
    if (!number || n<=0 || m<=0)
        return ;

    int startN = 0;
    int endN   = n;
    int startM = 0;
    int endM   = m;

    while((startN != endN) && (startM != endM))
    {
        PrintCirCle(number, startN++, endN--, startM++, endM--);
    }
}

int main(int argc, char* argv[])
{
    int arr1[M] = {1, 2, 3, 4, 5};
    int arr2[M] = {14, 15, 16, 17, 6};
    int arr3[M] = {13, 20, 19, 18, 7};
    int arr4[M] = {12, 11, 10, 9, 8};

    int* arr5[N] = {arr1, arr2, arr3, arr4};

    Solution(arr5, N, M);

    return 0;        
}
