#include <iostream>

template<typename T>
inline T Large(T& a, T& b)
{
    return (a > b) ? a : b;
}

// 宏定义 仅做字符替换 没有类型安全检查
#define LARGE(a, b) (((a) > (b)) ? (a) : (b))

int main(int argc, char* argv[])
{
    int a = 1;
    int b = 2;

    std::cout << Large(++a, b) << std::endl;
    std::cout << LARGE(++a, b) << std::endl;

    return 0;
}

