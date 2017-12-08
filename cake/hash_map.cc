//g++ -o 1 hm.cc -Wno-deprecated
#include <string>
#include <iostream>
#include <ext/hash_map>

typedef __gnu_cxx::hash_map<int, std::string> playerpool;

//typedef std::hash_map<int, std::string> playerpool;

int main(int argc, char* argv[])
{
    playerpool pool;
    pool[1] = "gaomin";
    pool[2] = "xuyue";

    std::cout <<  pool[1] << std::endl;
    std::cout <<  pool[2] << std::endl;

    return 0;
}
