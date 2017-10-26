#include <stdio.h>

int NumberOf1(int n)
{
    int count = 0;
    int flg   = 1;

    while (flg)
    {
        if (n & flg)
            ++count;

        flg = flg << 1;
    }

    printf("count = %d\n", count);
    return count;    
}

int NumberOf1_2(int n)
{
    int count = 0;

    while (n)
    {
        ++count;
        n = (n-1) & n;// -1 trick
    }
    printf("count = %d\n", count);
    return count;    
}


int main(int argc, char * argv[])
{
    NumberOf1(100);
    NumberOf1(-100);

    NumberOf1_2(100);
    NumberOf1_2(-100);

    return 0;    
}
