#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    double sum = 0;
    int   term = 1;

    do
    {
        sum += 1.0 / term;
        // todo...
    }
    while(abs(1.0/term) > 1e-6);

    printf("%f\n", sum);


    return 0;    
}
