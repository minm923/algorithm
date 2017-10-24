#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int getNumBits(int n)
{
    int count = 1;
    while(n = n/10)    
        ++count;
    return count;    
}

void printEdge(int ven, int count)
{
    for (int i=0; i<count; ++i)
    {
        printf("+");
        for (int j=0; j<ven; ++j)
        {
            printf("-");
        }
    }
    printf("+\n");
}

void printNum(int A[], int index, int ven, int count)
{
    for (int i=0; i<count; ++i, ++index)
    {
        printf("|");
        int num    = A[index];
        int numbits = getNumBits(num);
        int spacenum = ven - numbits;
        for (int j=0; j<spacenum; ++j)
        {
            printf(" ");
        }
        printf("%d", num);
    }
    printf("|\n");
}

int ArrayMax(int A[], int N)
{
    int max = INT_MIN;
    for(int i=0; i<N; ++i)
    {
        max = (A[i] > max) ? A[i] : max;
    }

    return max;    
}


void solution(int A[], int N, int K)
{
    int max = ArrayMax(A, N);
    int ven = getNumBits(max);
    int index = 0;
    int rows = 0;
    int last = 0;

    if (K < N)
    {
        rows = N / K;
        last = N % K;
    }
    else
    {
        K = N;
        rows = 1;
    }

   for (int i=0; i<rows; ++i, index+=K)
    {
        printEdge(ven, K);
        printNum(A, index, ven, K);
    }

    printEdge(ven, K);
    if (last > 0)
    {
        printNum(A, index, ven, last);    
        printEdge(ven, last);
    }
}

int main(int argc, char * argv[])
{
    int A[] = {4, 35, 80, 123, 12345, 44, 8, 5};

    solution(A, 8, 10);

    return 0;
}
