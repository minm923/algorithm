#include <iostream>

void myswap(char* p1, char* p2)
{
    char t = 0;
    t   = *p1;
    *p1 = *p2;
    *p2 = t;
}

void solution(char * arr, int iLen)
{
    if (!arr || iLen <=0)
        return ;            

    char* pFirst = arr;
    char* pEnd   = arr+iLen-1;

    // 数组可能有奇数 有偶数 不能用!= 
    while (pFirst < pEnd)
    {
        myswap(pFirst++, pEnd--);
    }
}



int main(int argc, char* argv[])
{
    //char ca[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char ca[] = {'a', 'b', 'c', 'd', 'e'};
    const int N = sizeof(ca) / sizeof(ca[0]);
    solution(ca, N);

    for (int i=0; i<N; ++i)
    {
        std::cout << ca[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

