#include <iostream>

template<typename ClassType>
class Singleton
{
public:    
    static ClassType* Instance()
    {
        static ClassType obj;
        return &obj;
    }
}

// 多线程单例实现参考  muduo Singleton.h

int main(int argc, char * argv[])
{

    return 0;
}
