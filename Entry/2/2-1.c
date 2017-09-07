#include <stdio.h>

int main(int argc, char * argv[])
{
    // for 循环
    // 循环
    int n = 1;
    //scanf("%d", &n);

    for(int i=1; i<=n; ++i)
    {
        printf("%d\n", i);
    }

    // 完全平方数
    for (int i=1000; i<10000; ++i)
    {
        if ((i/1000 == i%1000/100) && (i%100/10 == i%100%10%10))
        {
            printf("%d\n", i);
        }
    }

    return 0;    
}
