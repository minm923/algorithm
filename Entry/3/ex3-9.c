#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>// define INT_MAX INT_MIN
#include <string.h>

int main(int argc, char * argv[])
{
    char str1[10];
    memset(str1, 0, sizeof str1);
    char str2[10];
    memset(str2, 0, sizeof str2);

    scanf("%s", str1);
    scanf("%s", str2);

    const int i = strlen(str1);
    const int j = strlen(str2);
    char * ptmp = str2;
    char * pres = NULL;
    int k = 0;

    for (k=0; k<i && ptmp <(str2+j); ++k, ++ptmp)
    {
        ptmp = strchr(ptmp, str1[k]);
        if (!ptmp)
        {
            printf("false\n");

            return -1;
        }
    }

    if (i == k)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
