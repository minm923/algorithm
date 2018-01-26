#include <iostream>
#include <stdio.h>

int myntol(int n)
{
    int r   = 0;
    int flg = 0xFF;
    
    r |= ((n >> 24) & flg);
    r |= ((n >> 16) & flg) << 8;
    r |= ((n >> 8)  & flg) << 16;
    r |= ( n        & flg) << 24;

    return r;
}

int main(int argc, char* argv[])
{
    std::cout << "int size" << sizeof(int)  << std::endl;

    int size  = sizeof(int);
    int n     = 0X12345678;
    char * p2 = (char *)&n;

    std::cout << "before myntol" << std::endl;
    for (int i=0; i<size; ++i)
    {
        printf("%x\n", *(p2++));
    }

    int r     = myntol(n);
    char * p  = (char *)&r;

    std::cout << "after myntol" << std::endl;
    for (int i=0; i<size; ++i)    
    {
        printf("%x\n", *(p++));        
    }

    return 0;
}

