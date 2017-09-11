#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN
#include <string.h>

int arr[8][8];

int main(int argc, char * argv[])
{
    int n = 0;
    scanf("%d", &n);
    n = n % 8;
    memset(arr, 0, sizeof arr);

    int sum = n * n;
    int x = 0;
    int y = n-1;

    int i = 1;
    arr[x][y] = i;

    while(i < sum) // 注意 < 号, <=会死循环 因为i == 16
    {
        // 注意 x + 1 <n 的用法
        while(x+1 < n   && !arr[x+1][y]) arr[++x][y] = ++i;
        while(y-1 > -1  && !arr[x][y-1]) arr[x][--y] = ++i;
        while(x-1 > -1  && !arr[x-1][y]) arr[--x][y] = ++i;
        while(y+1 < n   && !arr[x][y+1]) arr[x][++y] = ++i;
    }

    for (int i = 0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
