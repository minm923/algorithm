#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN

int main(int argc, char * argv[])
{
    for (int i=100; i<=999; ++i)        
    {
        int h = i / 100;
        int s = i % 100 /10;
        int g = i % 10;

        int sum = h*h*h + s*s*s + g*g*g;
        if (i == sum)
        {
            printf("%d\n",sum);
        }
    }

    return 0;
}
