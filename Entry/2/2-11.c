#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN

void compute(int n, int * s, int * d);

int main(int argc, char * argv[])
{
    const int HE = 45;
    const int JI = 362880;

    for (int i=123; i<=329; ++i)
    {
        int j = i * 2;
        int k = i * 3;

        int s = 0;
        int d = 1;

        compute(i, &s, &d);
        compute(j, &s, &d);
        compute(k, &s, &d);

        if (s == HE && d == JI)
        {
            printf ("%d, %d, %d\n", i, j, k);
        }

    }


    return 0;
}

void compute(int n, int * s, int * d)
{
    int bai = n / 100;
    int shi = n % 100 / 10;
    int ge =  n % 10;

    *s += bai + shi + ge;
    *d *= bai * shi * ge;

}
