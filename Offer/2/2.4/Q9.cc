#include <stdio.h>

int Fibonacci(int n)
{
    int res = 0;
    int n0 = 0;
    int n1 = 1;

    if (0 == n )
    {
        res = n0;        
    }
    else if (1 == n)
    {
        res = n1;
    }
    else
    {
        for (int i=0; i<n-1; ++i)
        {
            res = n0 + n1;
            n0 = n1;
            n1 = res;
        }
    }

    return res;    
}

int Fibonacci2(int n)
{
    if (0 == n)
    {
        return 0;                
    }
    else if (1 == n)
    {
        return 1;        
    }
    else
    {
        return Fibonacci2(n-1) + Fibonacci2(n-2);
    }
}

int Fibonacci3(int n)
{
    int arr[2] =  {0, 1};
    
    if (n<2)
    {
        return arr[n];        
    }
    else
    {
        int res = 0;
        for (int i=0; i<n-1; ++i)
        {
            res = arr[0] + arr[1];            
            arr[0] = arr[1];
            arr[1] = res;
        }
        return res;
    }

    
}

int main(int argc, char * argv[])
{
    printf("%d\n", Fibonacci(10));
    printf("%d\n", Fibonacci2(10));
    printf("%d\n", Fibonacci3(10));
    return 0;
}
