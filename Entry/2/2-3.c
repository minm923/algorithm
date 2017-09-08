#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    double sum = 0;
    int   term = 1;
    int      S = -1;// 设置一个系数

    do
    {
        sum += -1 * S * 1.0 / term;
        S *= -1;
        term += 2;
    }
    while(1.0/term >= 1e-6);

    printf("%f\n", sum);


    return 0;    
}
