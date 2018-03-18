#include <iostream>


int solution(int n, int m)
{
    if (n<=0 || m <=0)
        return -1;

    int ret = 0;        

    for (int i=2; i<=n; ++i)
    {
        ret = (ret + m) % i;
    }

    return ret;
}

int main (int argc, char * argv[])
{

    std::cout << solution(1, 2) << std::endl;
    std::cout << solution(3, 2) << std::endl;

    return 0;
}
