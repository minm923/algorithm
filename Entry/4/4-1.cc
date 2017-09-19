#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

// 字符串和数字转换函数
// sscanf sprintf

int main(int argc, char* argv[]) 
{
    // sprintf
    char str[256] = {0};
    int data = 1024;

    sprintf(str, "%d", data);
    printf("%s\n", str);
    memset(str, 0, sizeof str);

    sprintf(str, "0x%X", data);
    printf("%s\n", str);
    memset(str, 0, sizeof str);

    sprintf(str, "0%o", data);
    printf("%s\n", str);
    memset(str, 0, sizeof str);

    const char * p1 = "Hello";
    const char * p2 = "World";

    // 拼接字符串
    sprintf(str, "%s %s", p1, p2);
    printf("%s\n", str);
    memset(str, 0, sizeof str);

    // sscanf
    char s[15] = "123.432,432";
    int n;
    double f1;
    int f2;
    // n : 读取的字符长度
    sscanf(s, "%lf,%d%n", &f1, &f2, &n);    
    std::cout<<f1<<" "<<f2<<" "<<n;

    return 0;
}
