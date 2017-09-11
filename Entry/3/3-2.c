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
    
    int x = n -1;
    int y = 0;
    
    int i = 1;

    while(i <= sum)
    {
        while(y+1 < n  && !arr[x][y+1]) arr[x][y++] = i++;
        while(x-1 > -1 && !arr[x-1][y]) arr[x--][y] = i++;
        while(y-1 > -1 && !arr[x][y-1]) arr[x][y--] = i++;
        while(x+1 < n  && !arr[x+1][y]) arr[x++][y] = i++;
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
