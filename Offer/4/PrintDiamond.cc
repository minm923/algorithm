#include <stdio.h>
#include <stdlib.h>


void PrintDiamond(int n)
{
    if ((n&1) != 1)
        return ;

    int flg1 = n / 2;
    int flg2 = n / 2;

    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            if (flg1 == j || flg2 == j)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        if (i<n/2)
        {
            ++flg1;
            --flg2;
        }
        else
        {
            --flg1;
            ++flg2;
        }
    }
}

int main(int argc, char * argv[])
{
    if (argc <= 1)
        return 1;
    int n = atoi(argv[1]);
    PrintDiamond(n);

    return 0;
}
