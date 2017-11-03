#include <iostream>
#include <string.h>
#include <stdio.h>

#define STRLEN 100

void Swap(char* p1, char* p2)
{
        char tmp = *p1;
        *p1      = *p2;
        *p2      = tmp;
}

bool isSwap(char* pBegin, char* pEnd)
{
    for (char* pCh=pBegin; pCh < pEnd; ++pCh)
    {
        if (*pCh == *pEnd)
            return false;
    }
    
    return true;
}

void perm(char* pStr, char* pBegin)
{
    //printf("begin %c\n", *pBegin);
    //if (isAllSame(pBegin) || *pBegin == '\0')
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for (char* pCh=pBegin; *pCh != '\0'; ++pCh)
        {
            if (isSwap(pBegin, pCh))// attention  确定的位置和待交换的位置 之间有和待交换位置的元素相等的元素
            {
                Swap(pBegin, pCh);
                perm(pStr, pBegin+1);
                Swap(pBegin, pCh);
            }
        }
    }
}

void solution(char* const str, const int n)
{
    if (!str|| n <= 0)
        return ;

    perm(str, str);
}

int main(int argc, char* argv[])
{
    char str[100];
    memset(str, 0, sizeof str);

    scanf("%s", str);    
    int iLen = strlen(str);
    printf("str : %s, len : %d\n", str, iLen);

    solution(str, iLen);

    return 0;
}

