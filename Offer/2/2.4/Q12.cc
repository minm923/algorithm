#include <stdio.h>
#include <stdlib.h>

void InitNumber(char* number, int n)
{
    for (int i=0; i<n; ++i)
    {
        number[i] = '0';
    }
}

int IsMaxNumber(char* number, int n)
{
    int flg = 1;
    for (int i=0; i<n; ++i)    
    {
        if(number[i] != '9')
        {  
            flg = 0;
            break;
        }
    }

    return flg;
}

int IncreaseNumber(char* number, int n)
{
    int overflow = 0;
    int flg = 1;
    for (int i=n-1; i>=0; --i)        
    {
        number[i] += flg;
        if (number[i] > '9')
        {
            if (0 == i)
            {
                overflow = 1;
            }
            else
            {
                number[i] = '0';
                flg = 1;
            }
        }
        else
        {
            break;
        }
    }

    return overflow;
}

void PrintNumber(char* number, int n)
{
    int flg = 0;
    int startPosition = -1;
    for (int i=0; i<n; ++i)
    {
        if ('0' != number[i])
        {
            startPosition = i;
            break;
        }
    }

    if (startPosition >= 0)
    {
        for (int i=startPosition; i<n; ++i)
        {
            printf("%c", number[i]);
        }
        printf("\n");
    }
}

int PrintNBitNumber(int n)
{
    if (n <= 0)
        return 1;

    char * number = new char[n];
    if (!number)
        return 1;

    InitNumber(number, n);

    while (!IncreaseNumber(number, n))
    {
        PrintNumber(number, n);
    }

}

int main(int argc, char* argv[])
{
    if (argc <=1)
        return 1;
    int n = atoi(argv[1]);
    PrintNBitNumber(n);

    return 0;
}
