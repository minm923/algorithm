#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LEN 100

char s1[LEN] = {0};
char s2[LEN] = {0};

bool isCombine(const char * s1, const char * s2)
{
    const int iLen1 = strlen(s1);
    const int iLen2 = strlen(s2);
    const int iLen = iLen1 > iLen2 ? iLen2 : iLen1;

    for (int i=0; i<iLen; ++i)
    {
        if ((s1[i]+s2[i]-'0'-'0') > 3)
        {
            return false;            
        }
    }


    return true;
}

int main(int argc, char* argv[]) 
{
    scanf("%s", s1);
    scanf("%s", s2);
    const int iLen1 = strlen(s1);        
    const int iLen2 = strlen(s2);        

    int res1 = 0;
    for (int i=0; i<iLen1; ++i)
    {
        if (isCombine(s1+i, s2))
        {
            res1 = (i+iLen2) > iLen1 ? (i+iLen2) : iLen1;
            printf("i = %d, len : %d\n", i, res1);
            break;
        }
    }

    int res2 = 0;
    for (int i=0; i<iLen2; ++i)
    {
        if (isCombine(s2+i, s1))
        {
            res2 = (i+iLen1) > iLen2 ? (i+iLen1) : iLen2;
            printf("i = %d, len : %d\n", i, res2);
            break;
        }
    }

    printf("fin Len = %d...\n", (res1 > res2) ? res2 : res1);

    return 0;
}
