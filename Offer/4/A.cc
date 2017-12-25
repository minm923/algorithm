#include <stdio.h>
#include <string.h>

void MySwap(char * p1, char *p2)
{
    char t = 0;
    t  = *p1;
    *p1 = *p2;
    *p2 = t;
}

bool IsSwap(char* pos1, char* pos2)
{
    char t = *pos2;

    for (char* p=pos1; p<pos2; ++p)
    {
        if (*p == t)
            return false;
    }

    return true;
}


void solution(char * str, char* begin, int len)
{
    if (!str || !begin || len < 0)
    {
        return ;
    }

    if (0 == len)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i=0; i<len; ++i)    
        {
            if (IsSwap(begin, begin+i))
            {
                MySwap(begin, begin+i);
                solution(str, begin+1, len-1);
                MySwap(begin+i, begin);
            }
        }
    }
}


int main(int argc, char* argv[])
{
    char arr[] = "122";

    printf("len %d\n", strlen(arr));

    solution(arr, arr, strlen(arr));


    return 0;
}
