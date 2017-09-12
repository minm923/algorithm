#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 10

int buff[MAX_ARR_SIZE];

int main(int argc, char* argv[]) 
{
    memset(buff, 0, sizeof buff);

    int s = 0;
    scanf("%d", &s);
    for (int i=1; i<=s; ++i)
    {
        int n = i;
        // 特别考虑0的情况
        while (n/10 || n%10)
        {
            ++buff[n%10];
            n = n / 10;
        }
    }

    for (int i=0; i<MAX_ARR_SIZE; ++i)
    {
        printf("%d : %d\n", i, buff[i]);
    }

    return 0;
}
