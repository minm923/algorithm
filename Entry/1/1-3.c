#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    // 输入3位数反转
    int i = 0;
    scanf("%d", &i);

    printf("%d%d%d\n", i%10, i%100/10, i/100);

    int m = 0;
    m = i%10*100 + i%100/10*10 + i/100;
    printf("%d\n", m);
    printf("%03d\n", m);

    // 交换变量
    // 1. 3元交换
    // 2. 2元交换
    printf("\n");
    
    int a = 10;
    int b = 11;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d, %d\n", a, b);


    return 0;    
}
