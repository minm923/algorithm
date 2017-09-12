#include<stdio.h>
#include<string.h>

#define MAX_ARR_SIZE 100001

int buff[MAX_ARR_SIZE];

int main(int argc, char* argv[]) 
{
    memset(buff, 0, sizeof buff);

    for (int i=1; i<MAX_ARR_SIZE; ++i)
    {
        int n = i;
        int sum = i;
        while (n%10)
        {
            sum += n % 10;
            n = n / 10;
        }

        //printf("i = %d, sum = %d\n", i , sum);

        if (sum <MAX_ARR_SIZE)
        {
            if (0 == buff[sum])
            {
                buff[sum] = i;
            }
            else
            {
                if (buff[sum] > i)
                {
                    buff[sum] = i;
                }
            }
        }
    }

    printf(".....\n");

    int n = 0;
    scanf("%d", &n);
    printf("n = %d \n", n);

    printf("%d \n", buff[n]);


    return 0;
}
