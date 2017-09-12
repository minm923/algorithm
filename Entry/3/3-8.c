#include <stdio.h>
#include <string.h>

#define MAX_ARR_SIZE 80

char buff[MAX_ARR_SIZE];

int main(int argc, char* argv[]) 
{
    memset(buff, 0, sizeof buff);
    scanf("%s", buff);
    const int iLen = strlen(buff);

    int iOValue = 1;
    int iXValue = 0;
    int iSum    = 0;

    for (int i=0; i<iLen; ++i)
    {
        if ('O' == buff[i])
        {
            iSum += iOValue;
            ++iOValue;
        }

        if ('X' == buff[i])
        {
            iOValue = 1;
        }
    }

    printf("sum = %d\n", iSum);


    return 0;
}
