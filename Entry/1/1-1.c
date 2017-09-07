#include <stdio.h>

int main(int argc, char * argv[])
{
    printf("%d\n", 1+2);
    printf("%d\n", 3-4);
    printf("%d\n", 5*6);
    printf("%d\n", 8/4);    // 求整
    printf("%d\n", 8/5);    // 求整
    printf("%.1f\n", 8.0/5);// 求商 保留小数点后1位
    printf("%.2f\n", 8.0/5);// 求商 保留小数点后2位
    printf("\n");

    // 以下为非规范用法
    // printf("%.1f\n", 8/5);  // 求整 保留小数点后2位
    // printf("%d\n", 8.0/5.0);// 求整 保留小数点后2位


    return 0;    
}
