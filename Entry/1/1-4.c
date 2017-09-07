#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);

    int x = (4*n -m) / 2;
    int y = n - x;

    if ((m%2 == 1) || x <0 || y < 0)
    {
        printf("No answer\n");
    }
    else
    {
        printf("%d, %d\n", x, y);
    }
    

    return 0;    
}
