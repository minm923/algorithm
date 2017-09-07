#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int t = 0;

    scanf("%d%d%d", &a, &b, &c);

    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }

    if (b > c)
    {
        t = c;
        c = b;
        b = t;
    }

    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }

  

    printf("%d,%d,%d\n", a, b, c);

    return 0;    
}
