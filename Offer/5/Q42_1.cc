#include <stdio.h>
#include <string.h>

void MySwap(char *c1, char *c2)
{
    char c;
    c    = *c1;
    *c1  = *c2;
    *c2  = c;
}

void reverse_str(char* s, int len)
{
    for (int i=0; i<len/2; ++i)
    {
        MySwap(s+i, s+len-1-i);
    }
}

void solution(char* s, int len)
{
    reverse_str(s, len);

    int start = 0;
    int end   = 0;

    for (int i=0; i<len; ++i)
    {
        if (*(s+i) == ' ')
        {
            end = i;
            reverse_str(s+start, end-start);
            start = i+1;
        }
    }
}

int main(int argc, char* argv[])
{
    char arr[] = "I am a student.";
    char arr2[] = "C++ is the most perfect language in this world";
    solution(arr, strlen(arr));
    printf("%s\n", arr);
    solution(arr2, strlen(arr2));
    printf("%s\n", arr2);

    return 0;
}
