#define __STDC_LIMIT_MACROS
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN

int main(int argc, char * argv[])
{
    double i;

    // 注 : 浮点数是近似值
    for (i=0; i != 10; i+=0.1)
        printf("%.1f\n", i);


    return 0;
}
