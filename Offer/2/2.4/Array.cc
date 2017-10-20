#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

char* mycopy(char* const src, char* const dest, int n)
{
    if (!src || !dest || n<=0)
    {
        return NULL;
    }

    for (int i=0; i<n; ++i)
    {
        src[i] = dest[i];
    }

    return src;
}

int main(int argc, char * argv[])
{
    char arr[256] = {0};
    char arr2[256] = {1, 0, 1, 0, 1, 0};

    int * pInt = (int *) arr;
    *pInt = 256;


    mycopy(arr+sizeof(int), arr2, 5);

    for (int i=0; i<15; ++i)
    {
        printf("%d\n", arr[i]);        
    }

    int * pInt2 = (int *)arr;
    cout << "len = " << *pInt2 << endl;

    cout << "ending.." << endl;

    std::string ss("123");
    cout << ss.size() << endl;
    cout << ss[0] << endl;
    cout << ss[1] << endl;
    cout << ss[2] << endl;

    return 0;
}
