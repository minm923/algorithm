#include <stdio.h>

int count =0;

/*
 * A : | 
 * B : /
 * C : \
 */

void BQ(unsigned char A, unsigned char B, unsigned C)
{
    if (0XFF == A )
    {
        ++count;        
    }
    else
    {
        unsigned char D =  ~(A|B|C);
        while(D)            
        {
            unsigned char bit = D & (-D);
            D = D - bit;
            BQ((A|bit), (B|bit)<<1, (C|bit)>>1);
        }
    }
}

int main(int argc, char* argv[])
{
    BQ(0, 0, 0);
    printf("%d\n", count);
    return 0;
}
