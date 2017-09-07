#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    //A1
    printf("A1\n");
    printf("%d\n", 11111*11111);
    printf("%d\n", 111111*111111);
    printf("%d\n", 111111111*111111111);

    //A2
    printf("A2\n");
    printf("%f\n", 11111.0*11111);
    printf("%f\n", 111111.0*111111);
    printf("%f\n", 111111111.0*111111111);

    //A3
    printf("A3\n");
    printf("%d\n", sqrt(-1));

    //A4
    printf("A4\n");            
    printf("%f\n", 1.0/0.0);// 浮点数表示有精度差异
    printf("%f\n", 0.0/0.0);

    //A5
    printf("A5\n");
    printf("%d\n", 1/0);//Floating point exception

    return 0;        
}
