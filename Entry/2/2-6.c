#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN

int main(int argc, char * argv[])
{
    FILE* fin  = NULL;
    FILE* fout = NULL;

    fin = stdin;
    fout = stdout;
    //fin  = fopen("data.in", "rb");
    //fout = fopen("data.out", "wb");
    if (!fin || !fout)
    {
        printf("file open fails...");
        return -1;
    }

    int s   = 0;
    int min = INT_MAX;
    int max = INT_MIN;
    int n   = 0;
    int x   = 0;

    while(1 == fscanf(fin, "%d", &n))
    {
       if (n > max)
       {
            max = n;
       }

       if (n < min)
       {
            min = n;
       }

        s += n;
        ++x;
    }

    fprintf(fout, "max = %d, min = %d, average = %.2f\n", max, min, (double)s/x);

    //fclose(fin);
    //fclose(fout);

    return 0;
}
