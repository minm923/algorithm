#include <stdio.h>

int main(int argc, char * argv[])
{
    // while 循环
    //int n = 0;
    long long n = 0;
    
    //scanf("%d", &n);    
    scanf("%lld", &n);    

    int i = 0;

    while(n != 1)
    {
        if (1 == n%2)        
        {
            n = 3*n+1;
        }
        else
        {
            n = n / 2;
        }
        ++i;
    }

    printf("%d\n", i);    

    return 0;    
}
