#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN

int main(int argc, char * argv[])
{
    FILE* fin  = NULL;
    FILE* fout = NULL;

    fin  = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    if (!fin || !fout)
    {
        printf("file open fails...");
        return -1;
    }

    int n = 0;
    int m = 0;
    int l = 0;
    int flg = 0; 

    while(3 == fscanf(fin, "%d %d %d", &n, &m, &l))
    {
        flg = 0;
        for (int i = 10; i < 100; ++i)
        {
            if (i%3 == n && i%5 == m && i%7 == l)
            {
                fprintf(fout, "%d\n", i);
                flg = 1;
            }
        }

        if (!flg)
        {
            fprintf(fout, "No answer\n");
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
