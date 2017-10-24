#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int solution(int A[], int N)
{
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i=1; i<N; ++i)
    {
        if (A[i] > max)
        {
            max = A[i];
        }

        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return abs(max-min);
}

int main(int argc, char * argv[])
{
    int A[] = {4, 3, 2, 5, 1, 1};
    int res = solution(A, 6);

    printf("%d\n", res);

    return 0;
}
