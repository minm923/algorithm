#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN
#include <string.h>

int main(int argc, char * argv[])
{
    char all[100] = {0};
    char input[20] = {0};

    scanf("%s", input);
    printf("%s\n", input);

    for (int i=100; i<=999; ++i)
    {
        for (int j=10; j<=99; ++j)        
        {
            int t0 = i * (j%10);
            int t1 = i * (j/10);
            int sum = i * j;
            sprintf(all, "%d%d%d%d%d", i, j, t0, t1, sum);

            int flg = 1;
            for (int k=0; k<(int)strlen(all); ++k)
            {
                if (NULL == strchr(input, all[k]))
                {
                    flg = 0;
                }
            }

            if (flg)
            {
                printf("i=%d j=%d\n", i, j);
            }
        }
    }
   
    return 0;
}
