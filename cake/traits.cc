#include <iostream>

template <typename T>
struct TraitsHelper
{
    static const bool isPointer = false;
};

template <typename T>
struct TraitsHelper<T*>
{
    static const bool isPointer = true;
};

template <typename T>
void test()
{
    if (TraitsHelper<T>::isPointer)
    {
        std::cout << "isPointer" << std::endl;
    }
    else
    {
        std::cout << "notPointer" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    test<int*>();
    test<int>();

    return 0;
}

