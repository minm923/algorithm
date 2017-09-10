#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN

int main(int argc, char * argv[])
{
    const int MAX_VALUE = 1000000;
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

    while(2 == fscanf(fin, "%d %d", &n, &m))
    {
        n = n % MAX_VALUE;
        m = m % MAX_VALUE;

        if (0 == n && 0 == m)
        {
            fprintf(fout, "n = %d, m = %d end...\n", n, m);
            break;
        }

        if (0 == n || 0 == m)
        {
            
            fprintf(fout, "n = %d, m = %d data error...\n", n, m);
            continue;
        }


        if (n > m)
        {
            fprintf(fout, "n = %d, m = %d data error...\n", n, m);
            continue;
        }

        double sum = 0.0;
        for (int i = n; i <=m ; ++i)
        {
            sum += 1.0 / (i * i);
        }
                


        fprintf(fout, "answer : %.5f\n", sum);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
