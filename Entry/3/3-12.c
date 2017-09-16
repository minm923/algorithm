#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 80

char buff[MAX_ARR_SIZE];
char buff2[MAX_ARR_SIZE];

int main(int argc, char* argv[]) 
{
    memset(buff,  0, sizeof buff);
    memset(buff2, 0, sizeof buff2);

    scanf("%s", buff);
    const int iLen = (int)strlen(buff);
    printf("iLen %d\n", iLen);

    for (int i=1; i<=iLen; ++i)
    {
        memcpy(buff2, buff, i);        
        int iRepeatTime = iLen / i -1;
        
        for (int j=1; j<=iRepeatTime; ++j)
        {
            memcpy(buff2+i*j, buff2, i);
        }

        if (0 == (memcmp(buff, buff2, iLen)))
        {
            printf("buff2 : %s\n", buff2);
            printf("%d\n", i);            
            break;
        }
        
        memset(buff2, 0, sizeof buff2);
    }


    return 0;
}
