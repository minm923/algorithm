#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[])
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif    



    int s   = 0;
    int min = 0;
    int max = 0;
    int n   = 0;
    int x   = 0;
    int flg = 1;

    while (1 == scanf("%d", &n))
    {
        if (flg)
        {
            min = n;
            max = n;
            flg = 0;
        }
        else
        {
            if (n > max)
            {
                max = n;
            }
            if (n < min)
            {
                min = n;
            }
        }            

        s += n;
        ++x;
    }

    printf("max = %d, min = %d, sum = %.2f\n", max, min, (double)s/x);


    return 0;
}
