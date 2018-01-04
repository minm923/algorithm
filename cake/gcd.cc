#include <stdio.h>
#include <iostream>
#include <stdint.h>

int gcd(int a, int b)
{
    int x = 0;
    int y = 0;

    if (a > b)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }

    int z = x % y;
    while (0 != z)
    {
        x = y;
        y = z;
        z = x % y;
    }

    return y;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main(int argc, char* argv[])
{
    int a = 100;
    int b = 25;
    int c = -25;
    
    std::cout << b%a << std::endl;
    std::cout << c%a << std::endl;

    return 0;
}

