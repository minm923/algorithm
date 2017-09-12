#include <stdio.h>
#include <string.h>

#define MAX_ARR_SIZE 100

char buff[MAX_ARR_SIZE];

int littleone(int ans, int t, int iStrLen)
{
    int j = ans;
    int k = t;
    for (int i=1; i<=iStrLen; ++i)
    {
        if (buff[ans] == buff[t])
        {
            ans = (ans +1) % iStrLen;
            t   = (t + 1) % iStrLen;
        }
        else if (buff[ans] < buff[t])
        {
            return j;
        }
        else
        {
            return k;
        }
    }

    return j;    
}

int main(int argc, char* argv[]) 
{
    memset(buff, 0, sizeof buff);
    scanf("%s", buff);
    const int iStrLen = strlen(buff);
    printf("strlen %d\n", iStrLen);

    int ans = 0;
    for(int t=1; t<iStrLen; ++t)
    {
        ans = littleone(ans, t, iStrLen);
    }

    printf("start %d\n", ans);

    for (int i=1; i<=iStrLen; ++i)
    {
        printf("%c", buff[ans]);
        ans = (ans + 1) % iStrLen;
    }

    printf("\n");

    return 0;
}
