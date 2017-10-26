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
    if (IsMaxNumber(number, n))
        return 0;

    int flg = 1;
    if (flg)
    {
        for (int i=n-1; i>=0; --i)        
        {
            number[i] += flg;
            flg = 0;
            if (number[i] > '9')
            {
                number[i] = '0';
                flg = 1;
            }
        }
    }



    return 1;
}

void PrintNumber(char* number, int n)
{
    for (int i=0; i<n; ++i)
    {
        printf("%c", number[i]);
    }
    printf("\n");
}

int PrintNBitNumber(int n)
{
    if (n <= 0)
        return 1;

    char * number = new char[n];
    if (!number)
        return 1;

    InitNumber(number, n);

    while (IncreaseNumber(number, n))
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
