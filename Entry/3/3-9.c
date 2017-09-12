#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 80

char buff[MAX_ARR_SIZE];

int main(int argc, char* argv[]) 
{
    memset(buff, 0, sizeof buff);
    scanf("%s", buff);
    const int iLen = strlen(buff);

    double arr[MAX_ARR_SIZE];
    memset(arr, 0, sizeof arr);

    arr['C'] = 12.01;
    arr['H'] = 1.008;
    arr['O'] = 16.00;    
    arr['N'] = 14.01;

    double Sum     = 0;
    char preChar = 0;

    for (int i=0; i<iLen; ++i)
    {
        if (isalpha(buff[i]))
        {
            Sum += arr[buff[i]];            
            preChar = buff[i];
        }

        if (isdigit(buff[i]))
        {
            Sum += arr[preChar] * (buff[i]-'0'-1);
            preChar = buff[i];
        }
    }

    printf("sum = %.3f\n", Sum);

    return 0;
}
