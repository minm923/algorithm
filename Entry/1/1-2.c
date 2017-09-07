#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    const double pi = acos(-1);    
    double i = 0.0;
    double j = 0.0;
    
    scanf("%lf%lf", &i, &j);

    double s0 = 2 * pi * i * i;
    double s1 = pi * i * j;
    double s3 = s0 + s1;

    printf("Area = %lf\n", s3);
    printf("Area = %f\n", s3);

    return 0;    
}
