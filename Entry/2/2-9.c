#include <stdio.h>

void printTriangle(int n);

int main(int argc, char * argv[])
{

    int n = 0;
    scanf("%d", &n);

    printTriangle(n);

    return 0;
}

void printTriangle(int n)
{
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<i; ++j)
        {
            printf(" ");
        }

        for (int k=0; k<(1+(n-1-i)*2); ++k)
        {
            printf("*");
        }

        printf("\n");
    }
}
