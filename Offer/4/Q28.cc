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

void perm(char* pStr, char* pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }
    else
    {
        for (char* pCh=pBegin; *pCh != '\0'; ++pCh)
        {
                Swap(pBegin, pCh);
                perm(pStr, pBegin+1);
                Swap(pBegin, pCh);
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
