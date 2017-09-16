#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char arr[6][7];

int main(int argc, char* argv[]) 
{
    memset(arr,  0, sizeof arr);

    arr[0][3] = '*';
    arr[1][0] = '*';
    arr[1][3] = '*';
    arr[2][4] = '*';
    arr[3][2] = '*';
    arr[4][0] = '*';
    arr[4][3] = '*';
    arr[4][6] = '*';
    arr[5][3] = '*';

    int n = 1;

    for (int i=0; i<6; ++i)
    {
        for (int j=0; j<7; ++j)
        {
            if ('*' != arr[i][j])
            {
                if ((i-1)<0 || (j-1)<0 || '*'==arr[i][j-1] || '*' == arr[i-1][j] ) 
                {
                    arr[i][j] = n++;
                }
            }
        }
    }

    for (int i=0; i<6; ++i)
    {
        for (int j=0; j<7; ++j)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    printf("..............\n");
    for (int i=0; i<6; ++i)
    {
        for (int j=0; j<7; ++j)
        {
            if ('*' == arr[i][j])
            {
                printf("\n");
            }
            else
            {
                printf("%d", arr[i][j]);
            }
        }

        printf("\n");
    }

    printf("..............\n");

    for (int j=0; j<7; ++j)
    {
        for (int i=0; i<6; ++i)
        {
            if ('*' == arr[i][j])
            {
                printf("\n");
            }
            else
            {
                printf("%d", arr[i][j]);
            }
        }

        printf("\n");
    }


    return 0;
}
