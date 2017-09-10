#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN
#include <string.h>

const int LIGHT_NUM = 1000;

int light[LIGHT_NUM+1];

int main(int argc, char * argv[])
{
    memset(light, 0, sizeof(light));

    int k = 0;
    scanf("%d", &k);

    for (int i=1; i <=k; ++i)
    {
        for(int j=1; j<=LIGHT_NUM; ++j)
        {
            if(0 == j%i)
            {
                light[j] = !light[j];
            }
        }
    }

    for(int j=1; j<=LIGHT_NUM; ++j)
    {
        if (light[j])
        {
            printf("%d ", j);
        }
    }


    return 0;
}
