#include <iostream>
#include <vector>
#include <stdexcept>

int solution(int n, int m)
{
    if (1 == n)
    {
        return 0;
    }
    else
    {
        return (solution(n-1, m) + m) % n;
    }
}

int solution2(int n, m)
{

}

int main(int argc, char* argv[])
{
    std::cout << solution(5, 3) << std::endl;

    return 0;
}

