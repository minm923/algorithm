#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int a = 29;

    printf("%.4f, %.4f\n", sin(a), cos(a));

    int year = 0;
    
    scanf("%d", &year);        

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        printf("yes\n");        
    }
    else
    {
        printf("no\n");
    }


    return 0;        
}
