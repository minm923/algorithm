#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN
#include <string.h>

int main(int argc, char * argv[])
{
    const int BUFF_SIZE = 100;
    char buff[BUFF_SIZE];// 放计算结果
    char buff2[BUFF_SIZE];// 放余数
    memset(buff, 0, sizeof buff);
    memset(buff2, 0, sizeof buff2);
    int i=0;// buff下标
    int j=0;// buff2下标
    int l=0;

    int a = 0;
    int b = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    int zs = a / b;
    int ys = a % b;
    printf("%d.", zs);

    // 用循环模拟除法
    while (ys !=0 && NULL == strchr(buff2, ys))
    {
        buff2[j++] = ys;    

        zs = ys*10/b;
        ys = ys*10%b;

        buff[i++] = zs;
        
        if (ys != 0)
        {
            l = i;
        }
        else
        {
            l = 0;
        }

    }

    for (int k=0; k<i; ++k)
    {
        printf("%d", buff[k]);
    }
    printf("\n");
    printf("%d\n", l);

    return 0;
}
