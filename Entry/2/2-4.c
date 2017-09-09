#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[])
{
    const int MOD = 1000000;
    int n = 0;
    int S = 0;

    scanf("%d", &n);

    for (int i=1; i <=n; ++i)
    {
        int factorial = 1;
        for (int j = 1; j <=i; ++j)
        {
            factorial *= j;
        }

        S += factorial;
        S %= MOD;
    }

    printf("S = %d, Time used = %.2f\n", S, (double)clock() / CLOCKS_PER_SEC);


    return 0;    
}
